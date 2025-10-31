/*
 * Host Management Module
 * 
 * This module manages the list of RDP servers/hosts.
 * Hosts are stored in a simple CSV file format:
 *   hostname,description
 * 
 * We use standard C file I/O functions for reading and writing.
 * In a real production app, you might use a database or JSON,
 * but CSV is simple and human-readable for learning purposes.
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "hosts.h"

// Internal helper functions
static wchar_t* trim_whitespace(wchar_t* str);
static BOOL parse_csv_line(wchar_t* line, Host* host);

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
    
    // Initialize output parameters
    // Always set output pointers to known state
    *hosts = NULL;
    *count = 0;
    
    // Try to open the hosts file in binary mode
    err = _wfopen_s(&file, HOSTS_FILE_NAME, L"rb");
    if (err != 0 || file == NULL)
    {
        // File doesn't exist yet - that's okay, just return empty list
        return TRUE;
    }
    
    // Skip UTF-8 BOM if present
    unsigned char bom[3];
    fread(bom, 1, 3, file);
    if (!(bom[0] == 0xEF && bom[1] == 0xBB && bom[2] == 0xBF))
    {
        // No BOM, rewind
        fseek(file, 0, SEEK_SET);
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
        fclose(file);  // Don't leak file handle!
        return FALSE;
    }
    
    char line[1024];
    BOOL firstLine = TRUE;
    
    // Read file line by line
    while (fgets(line, 1024, file) != NULL)
    {
        // Skip header line (first line with "hostname,description")
        if (firstLine)
        {
            firstLine = FALSE;
            continue;
        }
        
        // Convert UTF-8 line to wide character
        wchar_t wline[1024];
        MultiByteToWideChar(CP_UTF8, 0, line, -1, wline, 1024);
        
        // Skip empty lines
        if (wcslen(trim_whitespace(wline)) == 0)
            continue;
        
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
         * 
         * Alternative strategies:
         * - Grow by fixed amount (simpler, more allocations)
         * - Grow by 1.5x (less waste, more allocations)
         * - Double (our choice: balance of speed vs memory)
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
                fclose(file);
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
    
    fclose(file);
    return TRUE;
}

/*
 * SaveHosts - Save all hosts to the CSV file
 * 
 * This overwrites the entire file with the new host list.
 */
BOOL SaveHosts(const Host* hosts, int count)
{
    FILE* file = NULL;
    errno_t err;
    
    // Open file for writing (overwrites existing file) in binary mode
    err = _wfopen_s(&file, HOSTS_FILE_NAME, L"wb");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write UTF-8 BOM
    unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
    fwrite(bom, 1, 3, file);
    
    // Write CSV header
    const char* header = "hostname,description\r\n";
    fwrite(header, 1, strlen(header), file);
    
    // Write each host
    for (int i = 0; i < count; i++)
    {
        char utf8_hostname[MAX_HOSTNAME_LEN * 3];
        char utf8_description[MAX_DESCRIPTION_LEN * 3];
        
        // Convert wide strings to UTF-8
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].hostname, -1, utf8_hostname, sizeof(utf8_hostname), NULL, NULL);
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].description, -1, utf8_description, sizeof(utf8_description), NULL, NULL);
        
        // Write hostname
        BOOL hostnameNeedsQuotes = (strchr(utf8_hostname, ',') != NULL);
        if (hostnameNeedsQuotes)
        {
            fwrite("\"", 1, 1, file);
            fwrite(utf8_hostname, 1, strlen(utf8_hostname), file);
            fwrite("\"", 1, 1, file);
        }
        else
        {
            fwrite(utf8_hostname, 1, strlen(utf8_hostname), file);
        }
        
        // Write comma
        fwrite(",", 1, 1, file);
        
        // Write description
        BOOL descNeedsQuotes = (strchr(utf8_description, ',') != NULL);
        if (descNeedsQuotes)
        {
            fwrite("\"", 1, 1, file);
            fwrite(utf8_description, 1, strlen(utf8_description), file);
            fwrite("\"", 1, 1, file);
        }
        else
        {
            fwrite(utf8_description, 1, strlen(utf8_description), file);
        }
        
        // Write newline
        fwrite("\r\n", 1, 2, file);
        
        // Flush after each write
        fflush(file);
    }
    
    fclose(file);
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
 * This function creates an empty CSV file with just the header,
 * effectively deleting all hosts in one operation.
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL DeleteAllHosts(void)
{
    FILE* file = NULL;
    errno_t err;
    
    // Open file for writing (overwrites existing file) in binary mode
    err = _wfopen_s(&file, HOSTS_FILE_NAME, L"wb");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write UTF-8 BOM
    unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
    fwrite(bom, 1, 3, file);
    
    // Write CSV header only (no hosts)
    const char* header = "hostname,description\r\n";
    fwrite(header, 1, strlen(header), file);
    
    fclose(file);
    return TRUE;
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
 * Improved CSV parser that properly handles the description field
 */
static BOOL parse_csv_line(wchar_t* line, Host* host)
{
    // Remove newline
    line[wcscspn(line, L"\r\n")] = L'\0';
    
    // Find the first comma
    wchar_t* comma = wcschr(line, L',');
    
    if (comma == NULL)
    {
        // No comma found - just hostname, no description
        wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, trim_whitespace(line), _TRUNCATE);
        host->description[0] = L'\0';
        return TRUE;
    }
    
    // Split at the first comma
    *comma = L'\0';  // Terminate hostname string at comma
    wchar_t* hostname = trim_whitespace(line);
    wchar_t* description = trim_whitespace(comma + 1);
    
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
    
    return TRUE;
}

