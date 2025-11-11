/*
 * Host Management Module
 * 
 * This module manages the list of RDP servers/hosts.
 * Hosts are stored in an encrypted CSV file format:
 *   hostname,description,lastConnected
 * 
 * As of version 1.3.0, the CSV data is encrypted using Windows DPAPI
 * (Data Protection API) for security. As of v1.4.0, we use machine-level
 * encryption, meaning any user/process on the same machine can decrypt it.
 * This enables autostart scenarios where the app runs under SYSTEM account.
 * Data remains machine-bound (cannot be decrypted on different computers).
 * 
 * We use standard C file I/O functions for reading and writing,
 * with encryption/decryption handled transparently by the encryption module.
 * In a real production app, you might use a database or JSON,
 * but encrypted CSV provides a good balance of simplicity and security
 * for learning purposes.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hosts.h"
#include "encryption.h"

// Internal helper functions
static wchar_t* trim_whitespace(wchar_t* str);
static BOOL parse_csv_line(wchar_t* line, Host* host);
static BOOL get_hosts_file_path(wchar_t* path, size_t pathLen);

/*
 * LoadHosts - Load all hosts from the CSV file
 * 
 * Parameters:
 *   hosts     - Pointer to array of Host structures (will be allocated)
 *   count     - Pointer to receive the number of hosts loaded
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 *   The caller must call FreeHosts() when done with the array
 * 
 * Learning notes:
 *   - We use _wfopen_s for secure file opening
 *   - We dynamically allocate memory with malloc/realloc
 *   - We use fgetws to read wide-character lines
 */
/*
 * LoadHosts - Load all hosts from the CSV file
 * 
 * Memory Management Concepts Demonstrated:
 * 
 * 1. Dynamic Memory Allocation:
 *    - We don't know how many hosts the file contains
 *    - Stack allocation (Host hosts[10]) would be limiting
 *    - Heap allocation (malloc) allows flexible sizing
 * 
 * 2. Growing Arrays:
 *    - Start with initial capacity (10 items)
 *    - Double capacity when full (efficient growth pattern)
 *    - Use realloc to resize (may move memory!)
 * 
 * 3. Pointer-to-Pointer Pattern:
 *    - Function needs to return both array AND count
 *    - Use Host** to modify caller's pointer
 *    - Caller's pointer will point to allocated memory
 *    - Caller is responsible for calling FreeHosts()
 * 
 * 4. Error Handling:
 *    - Always check if malloc/realloc returns NULL
 *    - Clean up allocated memory before returning FALSE
 *    - Use fclose() to release file handle
 */
BOOL LoadHosts(Host** hosts, int* count)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t hostsFilePath[MAX_PATH];
    BYTE* fileData = NULL;
    BYTE* csvData = NULL;
    DWORD fileSize = 0;
    BOOL isEncrypted = FALSE;
    
    // Initialize output parameters
    // Always set output pointers to known state
    *hosts = NULL;
    *count = 0;
    
    // Get the full path to hosts.csv (critical for autostart scenarios)
    if (!get_hosts_file_path(hostsFilePath, MAX_PATH))
    {
        return FALSE;
    }
    
    // Try to open the hosts file in binary mode
    err = _wfopen_s(&file, hostsFilePath, L"rb");
    if (err != 0 || file == NULL)
    {
        // File doesn't exist yet - that's okay, just return empty list
        return TRUE;
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (fileSize == 0)
    {
        // Empty file
        fclose(file);
        return TRUE;
    }
    
    // Read entire file into memory
    fileData = (BYTE*)malloc(fileSize);
    if (fileData == NULL)
    {
        fclose(file);
        return FALSE;
    }
    
    if (fread(fileData, 1, fileSize, file) != fileSize)
    {
        free(fileData);
        fclose(file);
        return FALSE;
    }
    
    fclose(file);
    
    /*
     * ENCRYPTION: Check if file is encrypted
     * 
     * Encrypted files have the following structure:
     *   [4 bytes] Magic number (ENCRYPTED_FILE_MAGIC = "WRDP")
     *   [4 bytes] Encryption version
     *   [remaining] Encrypted CSV data
     * 
     * If magic number matches, decrypt the data.
     * If not, treat as plain CSV (backward compatibility).
     */
    if (fileSize >= 8)
    {
        DWORD magic = *(DWORD*)fileData;
        if (magic == ENCRYPTED_FILE_MAGIC)
        {
            isEncrypted = TRUE;
            
            // Skip the 8-byte header (magic + version)
            BYTE* encryptedData = fileData + 8;
            DWORD encryptedSize = fileSize - 8;
            
            // Decrypt the data
            DWORD decryptedSize = 0;
            if (!DecryptData(encryptedData, encryptedSize, &csvData, &decryptedSize))
            {
                // Decryption failed - might be corrupted or wrong user
                free(fileData);
                MessageBoxW(NULL, 
                           L"Failed to decrypt hosts file. The file may be corrupted or encrypted by a different user.",
                           L"Decryption Error", MB_OK | MB_ICONERROR);
                return FALSE;
            }
            
            // Free the original file data, we have decrypted data now
            free(fileData);
            fileData = NULL;
            
            // csvData now points to decrypted data (must free with LocalFree)
            fileSize = decryptedSize;
        }
        else
        {
            // Not encrypted, use file data as-is
            csvData = fileData;
        }
    }
    else
    {
        // Too small to be encrypted, use as-is
        csvData = fileData;
    }
    
    /*
     * PARSING: Now parse the CSV data (encrypted or plain)
     * 
     * At this point, csvData contains the plain CSV text.
     * We need to parse it line by line.
     */
    
    // Skip UTF-8 BOM if present
    BYTE* dataPtr = csvData;
    DWORD dataSize = fileSize;
    
    if (dataSize >= 3 && csvData[0] == 0xEF && csvData[1] == 0xBB && csvData[2] == 0xBF)
    {
        dataPtr += 3;
        dataSize -= 3;
    }
    
    /*
     * MEMORY ALLOCATION: Initial capacity
     * 
     * malloc returns void* which we cast to Host*
     * sizeof(Host) ensures correct size on any platform
     * 
     * Why 10? Good starting point - not too wasteful, not too small
     */
    int capacity = 10;  // Initial capacity
    *hosts = (Host*)malloc(capacity * sizeof(Host));
    
    /*
     * CRITICAL: Always check if malloc succeeded!
     * 
     * malloc returns NULL if:
     * - System is out of memory
     * - Requested size too large
     * - Memory fragmentation prevents allocation
     */
    if (*hosts == NULL)
    {
        if (isEncrypted)
            LocalFree(csvData);
        else
            free(csvData);
        return FALSE;
    }
    
    // Parse line by line from memory buffer
    BOOL firstLine = TRUE;
    char* lineStart = (char*)dataPtr;
    char* dataEnd = (char*)(dataPtr + dataSize);
    
    while (lineStart < dataEnd)
    {
        // Find end of line
        char* lineEnd = lineStart;
        while (lineEnd < dataEnd && *lineEnd != '\r' && *lineEnd != '\n')
            lineEnd++;
        
        // Copy line to temporary buffer
        size_t lineLen = lineEnd - lineStart;
        if (lineLen > 0 && lineLen < 1024)
        {
            char line[1024];
            memcpy(line, lineStart, lineLen);
            line[lineLen] = '\0';
            
            // Skip header line (first line with "hostname,description")
            if (!firstLine)
            {
                // Convert UTF-8 line to wide character
                wchar_t wline[1024];
                MultiByteToWideChar(CP_UTF8, 0, line, -1, wline, 1024);
                
                // Skip empty lines
                if (wcslen(trim_whitespace(wline)) > 0)
                {
                    /*
                     * MEMORY REALLOCATION: Growing the array
                     * 
                     * When array is full, we need more space. Strategy:
                     * 1. Double the capacity (efficient: O(log n) reallocations for n items)
                     * 2. Use realloc to resize
                     * 3. CRITICAL: Use temp variable! realloc returns NULL on failure
                     *    but original pointer is still valid
                     * 4. If realloc succeeds, update pointer
                     * 5. If fails, clean up and return error
                     */
                    if (*count >= capacity)
                    {
                        capacity *= 2;  // Double the size
                        
                        // SAFE REALLOC PATTERN: Use temporary variable
                        Host* newHosts = (Host*)realloc(*hosts, capacity * sizeof(Host));
                        
                        if (newHosts == NULL)
                        {
                            // Realloc failed! But *hosts is still valid
                            // Must clean up before returning
                            FreeHosts(*hosts, *count);
                            if (isEncrypted)
                                LocalFree(csvData);
                            else
                                free(csvData);
                            return FALSE;
                        }
                        
                        // Success! Update pointer
                        // realloc may have moved memory to new location
                        *hosts = newHosts;
                    }
                    
                    // Parse the CSV line and add to array
                    if (parse_csv_line(wline, &(*hosts)[*count]))
                    {
                        (*count)++;
                    }
                }
            }
            else
            {
                firstLine = FALSE;
            }
        }
        
        // Move to next line
        lineStart = lineEnd;
        // Skip \r\n or \n
        if (lineStart < dataEnd && *lineStart == '\r')
            lineStart++;
        if (lineStart < dataEnd && *lineStart == '\n')
            lineStart++;
    }
    
    // Clean up
    if (isEncrypted)
        LocalFree(csvData);
    else
        free(csvData);
    
    return TRUE;
}

/*
 * SaveHosts - Save all hosts to the CSV file (with encryption)
 * 
 * This function creates CSV content in memory, encrypts it using DPAPI,
 * and writes the encrypted data to the file.
 * 
 * The file format is:
 *   [4 bytes] Magic number (ENCRYPTED_FILE_MAGIC)
 *   [4 bytes] Encryption version
 *   [remaining] Encrypted CSV data
 */
BOOL SaveHosts(const Host* hosts, int count)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t hostsFilePath[MAX_PATH];
    BYTE* csvBuffer = NULL;
    DWORD csvSize = 0;
    BYTE* encryptedData = NULL;
    DWORD encryptedSize = 0;
    
    // Get the full path to hosts.csv (critical for autostart scenarios)
    if (!get_hosts_file_path(hostsFilePath, MAX_PATH))
    {
        return FALSE;
    }
    
    /*
     * STEP 1: Build CSV content in memory
     * 
     * We build the entire CSV in a memory buffer first, then encrypt it.
     * This is more efficient than encrypting line-by-line.
     */
    
    // Allocate a large buffer for CSV content (128KB should be plenty)
    const DWORD BUFFER_SIZE = 128 * 1024;
    csvBuffer = (BYTE*)malloc(BUFFER_SIZE);
    if (csvBuffer == NULL)
    {
        return FALSE;
    }
    
    char* csvPtr = (char*)csvBuffer;
    DWORD remainingSize = BUFFER_SIZE;
    
    // Write UTF-8 BOM
    unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
    memcpy(csvPtr, bom, 3);
    csvPtr += 3;
    remainingSize -= 3;
    
    // Write CSV header
    const char* header = "hostname,description,lastConnected\r\n";
    size_t headerLen = strlen(header);
    memcpy(csvPtr, header, headerLen);
    csvPtr += headerLen;
    remainingSize -= (DWORD)headerLen;
    
    // Write each host
    for (int i = 0; i < count; i++)
    {
        char utf8_hostname[MAX_HOSTNAME_LEN * 3];
        char utf8_description[MAX_DESCRIPTION_LEN * 3];
        char utf8_lastConnected[200];
        char line[4096];
        
        // Convert wide strings to UTF-8
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].hostname, -1, utf8_hostname, sizeof(utf8_hostname), NULL, NULL);
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].description, -1, utf8_description, sizeof(utf8_description), NULL, NULL);
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].lastConnected, -1, utf8_lastConnected, sizeof(utf8_lastConnected), NULL, NULL);
        
        // Build the CSV line
        int lineLen = 0;
        
        // Add hostname (with quotes if needed)
        BOOL hostnameNeedsQuotes = (strchr(utf8_hostname, ',') != NULL);
        if (hostnameNeedsQuotes)
        {
            lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "\"%s\"", utf8_hostname);
        }
        else
        {
            lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "%s", utf8_hostname);
        }
        
        // Add comma
        lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, ",");
        
        // Add description (with quotes if needed)
        BOOL descNeedsQuotes = (strchr(utf8_description, ',') != NULL);
        if (descNeedsQuotes)
        {
            lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "\"%s\"", utf8_description);
        }
        else
        {
            lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "%s", utf8_description);
        }
        
        // Add comma
        lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, ",");
        
        // Add lastConnected
        lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "%s", utf8_lastConnected);
        
        // Add newline
        lineLen += sprintf_s(line + lineLen, sizeof(line) - lineLen, "\r\n");
        
        // Copy to buffer
        if ((DWORD)lineLen < remainingSize)
        {
            memcpy(csvPtr, line, lineLen);
            csvPtr += lineLen;
            remainingSize -= lineLen;
        }
        else
        {
            // Buffer too small
            free(csvBuffer);
            MessageBoxW(NULL, L"CSV data too large to save.", L"Error", MB_OK | MB_ICONERROR);
            return FALSE;
        }
    }
    
    // Calculate actual CSV size
    csvSize = (DWORD)(csvPtr - (char*)csvBuffer);
    
    /*
     * STEP 2: Encrypt the CSV data
     * 
     * Use Windows DPAPI to encrypt the CSV buffer.
     * The encrypted data can only be decrypted by the same Windows user.
     */
    if (!EncryptData(csvBuffer, csvSize, &encryptedData, &encryptedSize))
    {
        free(csvBuffer);
        MessageBoxW(NULL, L"Failed to encrypt hosts data.", L"Encryption Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    // Free the plaintext CSV buffer (we have encrypted version now)
    free(csvBuffer);
    csvBuffer = NULL;
    
    /*
     * STEP 3: Write encrypted data to file
     * 
     * File format:
     *   [4 bytes] Magic number - identifies this as an encrypted WinRDP file
     *   [4 bytes] Version - allows for future format changes
     *   [remaining] Encrypted data
     */
    
    // Open file for writing (overwrites existing file) in binary mode
    err = _wfopen_s(&file, hostsFilePath, L"wb");
    if (err != 0 || file == NULL)
    {
        LocalFree(encryptedData);
        return FALSE;
    }
    
    // Write magic number
    DWORD magic = ENCRYPTED_FILE_MAGIC;
    if (fwrite(&magic, sizeof(DWORD), 1, file) != 1)
    {
        fclose(file);
        LocalFree(encryptedData);
        return FALSE;
    }
    
    // Write version
    DWORD version = ENCRYPTION_VERSION;
    if (fwrite(&version, sizeof(DWORD), 1, file) != 1)
    {
        fclose(file);
        LocalFree(encryptedData);
        return FALSE;
    }
    
    // Write encrypted data
    if (fwrite(encryptedData, 1, encryptedSize, file) != encryptedSize)
    {
        fclose(file);
        LocalFree(encryptedData);
        return FALSE;
    }
    
    // Success!
    fclose(file);
    LocalFree(encryptedData);
    return TRUE;
}

/*
 * AddHost - Add a new host to the list
 * 
 * Memory Management Educational Notes:
 * 
 * 1. Load-Modify-Save Pattern:
 *    - Load entire list into memory
 *    - Modify in memory
 *    - Save back to file
 *    - Free memory
 * 
 * 2. Memory Ownership:
 *    - We allocate (via LoadHosts)
 *    - We modify
 *    - We free
 *    - Simple ownership model
 * 
 * 3. Realloc for Single Item:
 *    - Could use malloc + memcpy
 *    - realloc is cleaner and may be more efficient
 *    - Grows by one (inefficient for bulk adds, fine for single)
 */
BOOL AddHost(const wchar_t* hostname, const wchar_t* description)
{
    Host* hosts = NULL;
    int count = 0;
    
    /*
     * MEMORY: Load existing hosts
     * LoadHosts allocates memory and sets 'hosts' pointer
     * We become responsible for freeing this memory!
     */
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Check if host already exists (update scenario)
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            // Host already exists - update description (in-place, no new memory)
            wcsncpy_s(hosts[i].description, MAX_DESCRIPTION_LEN, 
                     description, _TRUNCATE);
            
            BOOL result = SaveHosts(hosts, count);
            FreeHosts(hosts, count);  // MUST free before returning!
            return result;
        }
    }
    
    /*
     * MEMORY: Grow array by one slot
     * 
     * realloc(ptr, newsize) attempts to resize memory block
     * May return:
     * - Same pointer (expanded in place)
     * - Different pointer (copied to new location)
     * - NULL (failed, original still valid)
     */
    Host* newHosts = (Host*)realloc(hosts, (count + 1) * sizeof(Host));
    if (newHosts == NULL)
    {
        // Realloc failed - free original and return error
        FreeHosts(hosts, count);
        return FALSE;
    }
    hosts = newHosts;  // Update pointer (may have moved!)
    
    /*
     * MEMORY: Copy strings into new slot
     * 
     * wcsncpy_s is safe - prevents buffer overflow
     * _TRUNCATE: If too long, truncate rather than fail
     * 
     * String storage: Arrays within struct (stack-like)
     * Simpler than malloc for each string
     * Fixed maximum size (MAX_HOSTNAME_LEN, MAX_DESCRIPTION_LEN)
     */
    wcsncpy_s(hosts[count].hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
    wcsncpy_s(hosts[count].description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
    wcscpy_s(hosts[count].lastConnected, 64, L"Never");  // New hosts haven't been connected to
    count++;
    
    // Save and cleanup
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);  // ALWAYS free before function exits!
    return result;
}

/*
 * DeleteHost - Remove a host from the list
 */
BOOL DeleteHost(const wchar_t* hostname)
{
    Host* hosts = NULL;
    int count = 0;
    
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Find and remove the host
    int foundIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1)
    {
        FreeHosts(hosts, count);
        return FALSE;  // Host not found
    }
    
    // Shift remaining hosts down
    for (int i = foundIndex; i < count - 1; i++)
    {
        hosts[i] = hosts[i + 1];
    }
    count--;
    
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
    return result;
}

/*
 * FreeHosts - Free memory allocated for host array
 * 
 * Memory Management Educational Notes:
 * 
 * 1. Simple Ownership Model:
 *    - One call to malloc → one call to free
 *    - No reference counting needed
 *    - No shared ownership complexity
 * 
 * 2. Why Check NULL:
 *    - free(NULL) is safe (does nothing)
 *    - Explicit check makes intent clear
 *    - Prevents confusion in debugger
 * 
 * 3. Why No Count Parameter Needed:
 *    - free() frees entire block
 *    - System tracks allocation size internally
 *    - Count useful if we needed cleanup per-item
 * 
 * 4. What Gets Freed:
 *    - The Host array block
 *    - NOT the strings inside (they're fixed arrays in struct)
 *    - If strings were malloc'd pointers, would need loop
 * 
 * Example with dynamic strings:
 * 
 *   typedef struct {
 *       char* hostname;     // Pointer to malloc'd string
 *       char* description;  // Pointer to malloc'd string
 *   } HostDynamic;
 * 
 *   void FreeHostsDynamic(HostDynamic* hosts, int count) {
 *       if (hosts == NULL) return;
 *       
 *       // Free each string first
 *       for (int i = 0; i < count; i++) {
 *           free(hosts[i].hostname);
 *           free(hosts[i].description);
 *       }
 *       
 *       // Then free array
 *       free(hosts);
 *   }
 * 
 * Our approach (fixed-size arrays) is simpler for this educational project.
 */
void FreeHosts(Host* hosts, int count)
{
    UNREFERENCED_PARAMETER(count);  // Not needed for our simple case
    
    /*
     * MEMORY: Check before freeing
     * 
     * free(NULL) is legal and does nothing, but explicit check
     * makes the code's intent clearer and prevents confusion
     */
    if (hosts != NULL)
    {
        free(hosts);  // Release the entire array back to the system
        
        // NOTE: We don't set hosts = NULL here because 'hosts' is
        // a local copy of the pointer. Caller should set their
        // pointer to NULL after calling FreeHosts().
        // 
        // Better pattern (if we redesigned):
        //   void FreeHosts(Host** hosts, int count) {
        //       free(*hosts);
        //       *hosts = NULL;  // Clear caller's pointer
        //   }
    }
}

/*
 * DeleteAllHosts - Delete all hosts from the CSV file
 * 
 * This function creates an empty encrypted CSV file with just the header,
 * effectively deleting all hosts in one operation.
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL DeleteAllHosts(void)
{
    // Simply save an empty host list using the standard encrypted format
    // This ensures consistency with SaveHosts() and maintains encryption
    return SaveHosts(NULL, 0);
}

/*
 * Helper function: Trim whitespace from string
 */
static wchar_t* trim_whitespace(wchar_t* str)
{
    wchar_t* end;
    
    // Trim leading space
    while (iswspace(*str)) str++;
    
    if (*str == 0)  // All spaces
        return str;
    
    // Trim trailing space
    end = str + wcslen(str) - 1;
    while (end > str && iswspace(*end)) end--;
    
    // Write new null terminator
    *(end + 1) = L'\0';
    
    return str;
}

/*
 * Helper function: Parse a CSV line into a Host structure
 * 
 * Improved CSV parser that properly handles the description and lastConnected fields
 */
static BOOL parse_csv_line(wchar_t* line, Host* host)
{
    // Remove newline
    line[wcscspn(line, L"\r\n")] = L'\0';
    
    // Find the first comma
    wchar_t* comma1 = wcschr(line, L',');
    
    if (comma1 == NULL)
    {
        // No comma found - just hostname, no description or lastConnected
        wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, trim_whitespace(line), _TRUNCATE);
        host->description[0] = L'\0';
        wcscpy_s(host->lastConnected, 64, L"Never");
        return TRUE;
    }
    
    // Split at the first comma
    *comma1 = L'\0';  // Terminate hostname string at comma
    wchar_t* hostname = trim_whitespace(line);
    wchar_t* remainder = comma1 + 1;
    
    // Find the second comma for lastConnected field
    wchar_t* comma2 = wcschr(remainder, L',');
    wchar_t* description;
    wchar_t* lastConnected;
    
    if (comma2 == NULL)
    {
        // No second comma - we have hostname,description (old format)
        description = trim_whitespace(remainder);
        lastConnected = L"Never";
    }
    else
    {
        // We have hostname,description,lastConnected (new format)
        *comma2 = L'\0';
        description = trim_whitespace(remainder);
        lastConnected = trim_whitespace(comma2 + 1);
    }
    
    // Remove quotes from hostname if present
    if (hostname[0] == L'"')
    {
        hostname++;
        size_t len = wcslen(hostname);
        if (len > 0 && hostname[len - 1] == L'"')
            hostname[len - 1] = L'\0';
    }
    
    // Remove quotes from description if present
    if (description[0] == L'"')
    {
        description++;
        size_t len = wcslen(description);
        if (len > 0 && description[len - 1] == L'"')
            description[len - 1] = L'\0';
    }
    
    // Copy to host structure
    wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
    wcsncpy_s(host->description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
    wcsncpy_s(host->lastConnected, 64, lastConnected, _TRUNCATE);
    
    return TRUE;
}

/*
 * get_hosts_file_path - Get the full path to the hosts.csv file
 * 
 * This function constructs an absolute path to hosts.csv based on the
 * executable's location. This is critical for handling autostart scenarios
 * where the working directory may be different from the executable location.
 * 
 * Parameters:
 *   path    - Buffer to receive the full path
 *   pathLen - Size of the buffer in characters
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 * 
 * Bug Fix Note:
 * When applications auto-start with Windows, the working directory is often
 * C:\Windows\System32 rather than the executable's directory. Using relative
 * paths like "hosts.csv" will fail in this scenario. By constructing an
 * absolute path based on GetModuleFileNameW, we ensure the file is always
 * found regardless of the current working directory.
 */
static BOOL get_hosts_file_path(wchar_t* path, size_t pathLen)
{
    wchar_t exePath[MAX_PATH];
    
    // Get the full path to the executable
    if (GetModuleFileNameW(NULL, exePath, MAX_PATH) == 0)
    {
        return FALSE;
    }
    
    // Find the last backslash to get the directory
    wchar_t* lastSlash = wcsrchr(exePath, L'\\');
    if (lastSlash == NULL)
    {
        return FALSE;
    }
    
    // Terminate the string at the last backslash to get directory path
    *(lastSlash + 1) = L'\0';
    
    // Build the full path: executable_directory + hosts.csv
    if (swprintf_s(path, pathLen, L"%s%s", exePath, HOSTS_FILE_NAME) < 0)
    {
        return FALSE;
    }
    
    return TRUE;
}

/*
 * UpdateLastConnected - Update the last connected timestamp for a host
 * 
 * Parameters:
 *   hostname - The hostname to update
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL UpdateLastConnected(const wchar_t* hostname)
{
    Host* hosts = NULL;
    int count = 0;
    
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Find the host
    int foundIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1)
    {
        FreeHosts(hosts, count);
        return FALSE;  // Host not found
    }
    
    // Get current time
    SYSTEMTIME st;
    GetLocalTime(&st);
    
    // Format as ISO 8601-like: YYYY-MM-DD HH:MM:SS
    swprintf_s(hosts[foundIndex].lastConnected, 64, 
               L"%04d-%02d-%02d %02d:%02d:%02d",
               st.wYear, st.wMonth, st.wDay,
               st.wHour, st.wMinute, st.wSecond);
    
    // Save and cleanup
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
    return result;
}

/*
 * GetRecentHosts - Get a list of recently connected hosts
 * 
 * This function retrieves hosts sorted by their last connection time,
 * with the most recently connected hosts first. Hosts that have never
 * been connected to are excluded.
 * 
 * Parameters:
 *   hosts     - Pointer to array of Host structures (will be allocated)
 *   count     - Pointer to receive the number of hosts returned
 *   maxCount  - Maximum number of recent hosts to return (typically 3-5)
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 *   The caller must call FreeHosts() when done with the array
 * 
 * Usage example:
 *   Host* recentHosts = NULL;
 *   int recentCount = 0;
 *   if (GetRecentHosts(&recentHosts, &recentCount, 5)) {
 *       // Use the hosts...
 *       FreeHosts(recentHosts, recentCount);
 *   }
 */
BOOL GetRecentHosts(Host** hosts, int* count, int maxCount)
{
    Host* allHosts = NULL;
    int allCount = 0;
    
    // Initialize output parameters
    *hosts = NULL;
    *count = 0;
    
    // Load all hosts
    if (!LoadHosts(&allHosts, &allCount))
        return FALSE;
    
    if (allCount == 0)
    {
        // No hosts at all
        return TRUE;
    }
    
    // Filter out hosts that have never been connected to
    // and copy to a temporary array for sorting
    Host* connectedHosts = (Host*)malloc(allCount * sizeof(Host));
    if (connectedHosts == NULL)
    {
        FreeHosts(allHosts, allCount);
        return FALSE;
    }
    
    int connectedCount = 0;
    for (int i = 0; i < allCount; i++)
    {
        // Skip hosts that have never been connected to
        if (_wcsicmp(allHosts[i].lastConnected, L"Never") != 0)
        {
            connectedHosts[connectedCount] = allHosts[i];
            connectedCount++;
        }
    }
    
    // Free the original list
    FreeHosts(allHosts, allCount);
    
    if (connectedCount == 0)
    {
        // No connected hosts
        free(connectedHosts);
        return TRUE;
    }
    
    // Sort by lastConnected timestamp (descending - most recent first)
    // Simple bubble sort is fine for small lists (typically < 10 items)
    for (int i = 0; i < connectedCount - 1; i++)
    {
        for (int j = 0; j < connectedCount - i - 1; j++)
        {
            // Compare timestamps (ISO 8601 format sorts correctly with string compare)
            if (wcscmp(connectedHosts[j].lastConnected, connectedHosts[j + 1].lastConnected) < 0)
            {
                // Swap
                Host temp = connectedHosts[j];
                connectedHosts[j] = connectedHosts[j + 1];
                connectedHosts[j + 1] = temp;
            }
        }
    }
    
    // Return only the requested number of most recent hosts
    int resultCount = (connectedCount < maxCount) ? connectedCount : maxCount;
    
    Host* result = (Host*)malloc(resultCount * sizeof(Host));
    if (result == NULL)
    {
        free(connectedHosts);
        return FALSE;
    }
    
    // Copy the most recent hosts to result array
    for (int i = 0; i < resultCount; i++)
    {
        result[i] = connectedHosts[i];
    }
    
    free(connectedHosts);
    
    // Set output parameters
    *hosts = result;
    *count = resultCount;
    
    return TRUE;
}


