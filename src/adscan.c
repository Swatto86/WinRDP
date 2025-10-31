/*
 * Active Directory / Network Computer Scanning
 * 
 * This module uses Windows NetAPI32 to enumerate computers on the network.
 * Works with both domain-joined and workgroup computers.
 * 
 * Educational concepts demonstrated:
 * - NetAPI32 functions (NetServerEnum)
 * - Network enumeration
 * - Buffer management with NetApiBufferFree
 * - Working with Server Info structures
 */

#include <windows.h>
#include <lm.h>  // For NetServerEnum and SERVER_INFO_101
#include <stdio.h>
#include <stdlib.h>
#include "adscan.h"

/*
 * ScanForComputers - Enumerate computers on the network
 * 
 * Uses NetServerEnum to discover computers in the domain/workgroup.
 * This works even if not joined to a domain.
 * 
 * Parameters:
 *   domain    - Domain/workgroup name (NULL or empty for current)
 *   includeWorkstations - Include workstation computers
 *   includeServers - Include server computers (excluding DCs)
 *   includeDomainControllers - Include domain controllers
 *   computers - Pointer to receive allocated array of ComputerInfo
 *   count     - Pointer to receive number of computers found
 * 
 * Note: NetServerEnum uses the caller's security context. 
 * The scan runs with the current logged-in user's permissions.
 * 
 * Returns:
 *   TRUE on success (even if no computers found)
 *   FALSE on failure
 * 
 * The caller MUST call FreeComputerList() when done with the array!
 */
BOOL ScanForComputers(const wchar_t* domain, BOOL includeWorkstations,
                      BOOL includeServers, BOOL includeDomainControllers,
                      ComputerInfo** computers, int* count)
{
    SERVER_INFO_101* buffer = NULL;
    DWORD entriesRead = 0;
    DWORD totalEntries = 0;
    DWORD resumeHandle = 0;
    NET_API_STATUS status;
    
    // Initialize output parameters
    *computers = NULL;
    *count = 0;
    
    // Prepare domain parameter (use NULL if empty string)
    const wchar_t* domainToScan = NULL;
    if (domain != NULL && wcslen(domain) > 0)
    {
        domainToScan = domain;
    }
    
    /*
     * NetServerEnum - Enumerate servers on the network
     * 
     * Parameters:
     *   NULL           - Local computer (NULL = enumerate from local)
     *   101            - Information level (SERVER_INFO_101 has name and comment)
     *   (LPBYTE*)&buffer - Receives pointer to buffer with results
     *   MAX_PREFERRED_LENGTH - Let API allocate optimal buffer size
     *   &entriesRead   - Number of entries actually read
     *   &totalEntries  - Total entries available
     *   SV_TYPE_WORKSTATION | SV_TYPE_SERVER - Type filter (all computers)
     *   domainToScan   - Domain (NULL = current domain/workgroup)
     *   &resumeHandle  - For paging through results
     * 
     * Returns:
     *   NERR_Success (0) on success
     *   Other codes indicate errors
     */
    status = NetServerEnum(
        NULL,                                    // servername
        101,                                     // level (SERVER_INFO_101)
        (LPBYTE*)&buffer,                       // bufptr
        MAX_PREFERRED_LENGTH,                    // prefmaxlen
        &entriesRead,                           // entriesread
        &totalEntries,                          // totalentries
        SV_TYPE_WORKSTATION | SV_TYPE_SERVER,   // servertype (all computers)
        domainToScan,                            // domain (NULL = current, or specified domain)
        &resumeHandle                            // resume_handle
    );
    
    // Check for errors
    if (status != NERR_Success)
    {
        // Not necessarily fatal - might just be no computers found
        // or not on a network
        return TRUE;  // Return success with 0 count
    }
    
    if (entriesRead == 0)
    {
        // No computers found, but not an error
        if (buffer != NULL)
            NetApiBufferFree(buffer);
        return TRUE;
    }
    
    // Allocate array for results (may be larger than needed due to filtering)
    *computers = (ComputerInfo*)malloc(sizeof(ComputerInfo) * entriesRead);
    if (*computers == NULL)
    {
        NetApiBufferFree(buffer);
        return FALSE;
    }
    
    // Copy computer information to our structure, filtering by type
    int addedCount = 0;
    for (DWORD i = 0; i < entriesRead; i++)
    {
        DWORD type = buffer[i].sv101_type;
        
        // Determine computer type and check if we should include it
        BOOL includeThisComputer = FALSE;
        if ((type & SV_TYPE_DOMAIN_CTRL) && includeDomainControllers)
        {
            includeThisComputer = TRUE;
        }
        else if ((type & SV_TYPE_SERVER) && includeServers)
        {
            includeThisComputer = TRUE;
        }
        else if ((type & SV_TYPE_WORKSTATION) && includeWorkstations)
        {
            includeThisComputer = TRUE;
        }
        
        // Skip if this computer type is not included in the filter
        if (!includeThisComputer)
            continue;
        
        // Copy computer name
        wchar_t* name = buffer[i].sv101_name;
        if (name != NULL)
        {
            wcsncpy_s((*computers)[addedCount].name, 256, name, _TRUNCATE);
        }
        else
        {
            (*computers)[addedCount].name[0] = L'\0';
        }
        
        // Copy comment/description
        wchar_t* comment = buffer[i].sv101_comment;
        if (comment != NULL && wcslen(comment) > 0)
        {
            wcsncpy_s((*computers)[addedCount].comment, 256, comment, _TRUNCATE);
        }
        else
        {
            // If no comment, use computer type as description
            if (type & SV_TYPE_DOMAIN_CTRL)
                wcscpy_s((*computers)[addedCount].comment, 256, L"Domain Controller");
            else if (type & SV_TYPE_SERVER)
                wcscpy_s((*computers)[addedCount].comment, 256, L"Server");
            else if (type & SV_TYPE_WORKSTATION)
                wcscpy_s((*computers)[addedCount].comment, 256, L"Workstation");
            else
                wcscpy_s((*computers)[addedCount].comment, 256, L"Computer");
        }
        
        addedCount++;
    }
    
    *count = addedCount;
    
    // Free the buffer allocated by NetServerEnum
    // CRITICAL: Always free NetAPI buffers!
    NetApiBufferFree(buffer);
    
    return TRUE;
}

/*
 * FreeComputerList - Free the computer list
 * 
 * Simple wrapper around free() for consistency.
 */
void FreeComputerList(ComputerInfo* computers)
{
    if (computers != NULL)
    {
        free(computers);
    }
}

