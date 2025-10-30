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
BOOL LoadHosts(Host** hosts, int* count)
{
    FILE* file = NULL;
    errno_t err;
    
    *hosts = NULL;
    *count = 0;
    
    // Try to open the hosts file
    // _wfopen_s is the secure version of _wfopen
    err = _wfopen_s(&file, HOSTS_FILE_NAME, L"r, ccs=UTF-8");
    if (err != 0 || file == NULL)
    {
        // File doesn't exist yet - that's okay, just return empty list
        return TRUE;
    }
    
    int capacity = 10;  // Initial capacity
    *hosts = (Host*)malloc(capacity * sizeof(Host));
    if (*hosts == NULL)
    {
        fclose(file);
        return FALSE;
    }
    
    wchar_t line[1024];
    BOOL firstLine = TRUE;
    
    // Read file line by line
    while (fgetws(line, 1024, file) != NULL)
    {
        // Skip header line (first line with "hostname,description")
        if (firstLine)
        {
            firstLine = FALSE;
            continue;
        }
        
        // Skip empty lines
        if (wcslen(trim_whitespace(line)) == 0)
            continue;
        
        // Expand array if needed
        if (*count >= capacity)
        {
            capacity *= 2;
            Host* newHosts = (Host*)realloc(*hosts, capacity * sizeof(Host));
            if (newHosts == NULL)
            {
                FreeHosts(*hosts, *count);
                fclose(file);
                return FALSE;
            }
            *hosts = newHosts;
        }
        
        // Parse the CSV line and add to array
        if (parse_csv_line(line, &(*hosts)[*count]))
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
    
    // Open file for writing (overwrites existing file)
    err = _wfopen_s(&file, HOSTS_FILE_NAME, L"w, ccs=UTF-8");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write CSV header
    fwprintf(file, L"hostname,description\n");
    
    // Write each host
    for (int i = 0; i < count; i++)
    {
        // Escape commas in fields by wrapping in quotes if needed
        BOOL hostnameNeedsQuotes = (wcschr(hosts[i].hostname, L',') != NULL);
        BOOL descNeedsQuotes = (wcschr(hosts[i].description, L',') != NULL);
        
        if (hostnameNeedsQuotes)
            fwprintf(file, L"\"%s\"", hosts[i].hostname);
        else
            fwprintf(file, L"%s", hosts[i].hostname);
            
        fwprintf(file, L",");
        
        if (descNeedsQuotes)
            fwprintf(file, L"\"%s\"", hosts[i].description);
        else
            fwprintf(file, L"%s", hosts[i].description);
            
        fwprintf(file, L"\n");
    }
    
    fclose(file);
    return TRUE;
}

/*
 * AddHost - Add a new host to the list
 */
BOOL AddHost(const wchar_t* hostname, const wchar_t* description)
{
    Host* hosts = NULL;
    int count = 0;
    
    // Load existing hosts
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Check if host already exists
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            // Host already exists - update description
            wcsncpy_s(hosts[i].description, MAX_DESCRIPTION_LEN, 
                     description, _TRUNCATE);
            BOOL result = SaveHosts(hosts, count);
            FreeHosts(hosts, count);
            return result;
        }
    }
    
    // Add new host
    Host* newHosts = (Host*)realloc(hosts, (count + 1) * sizeof(Host));
    if (newHosts == NULL)
    {
        FreeHosts(hosts, count);
        return FALSE;
    }
    hosts = newHosts;
    
    wcsncpy_s(hosts[count].hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
    wcsncpy_s(hosts[count].description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
    count++;
    
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
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
 */
void FreeHosts(Host* hosts, int count)
{
    UNREFERENCED_PARAMETER(count);
    if (hosts != NULL)
    {
        free(hosts);
    }
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
 * Simple CSV parser that handles quoted fields
 */
static BOOL parse_csv_line(wchar_t* line, Host* host)
{
    wchar_t* context = NULL;
    wchar_t* token;
    int fieldNum = 0;
    
    // Remove newline
    line[wcscspn(line, L"\r\n")] = L'\0';
    
    // Simple CSV parsing (doesn't handle all edge cases, but good enough)
    token = wcstok_s(line, L",", &context);
    while (token != NULL && fieldNum < 2)
    {
        token = trim_whitespace(token);
        
        // Remove quotes if present
        if (token[0] == L'"')
        {
            token++;
            size_t len = wcslen(token);
            if (len > 0 && token[len - 1] == L'"')
                token[len - 1] = L'\0';
        }
        
        if (fieldNum == 0)
        {
            wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, token, _TRUNCATE);
        }
        else if (fieldNum == 1)
        {
            wcsncpy_s(host->description, MAX_DESCRIPTION_LEN, token, _TRUNCATE);
        }
        
        fieldNum++;
        token = wcstok_s(NULL, L",", &context);
    }
    
    return (fieldNum >= 1);  // At least hostname is required
}

