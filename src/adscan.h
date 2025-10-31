/*
 * Active Directory Computer Scanning
 * 
 * This module scans the local network/domain for computers that can
 * be used as RDP hosts. Uses NetAPI32 for computer enumeration.
 */

#ifndef ADSCAN_H
#define ADSCAN_H

#include <windows.h>

// Structure to hold discovered computer information
typedef struct {
    wchar_t name[256];
    wchar_t comment[256];
} ComputerInfo;

// Scan for computers in the domain/workgroup
// Parameters:
//   domain - Domain/workgroup name (NULL for current)
//   username - Optional username (NULL for anonymous)
//   password - Optional password (NULL for anonymous)
//   includeWorkstations - Include workstation computers
//   includeServers - Include server computers
//   includeDomainControllers - Include domain controllers
//   computers - Receives array of ComputerInfo
//   count - Receives number of computers found
// Returns array of ComputerInfo and count
// Caller must free the array with FreeComputerList()
BOOL ScanForComputers(const wchar_t* domain, const wchar_t* username, 
                      const wchar_t* password, BOOL includeWorkstations,
                      BOOL includeServers, BOOL includeDomainControllers,
                      ComputerInfo** computers, int* count);

// Free the computer list returned by ScanForComputers
void FreeComputerList(ComputerInfo* computers);

#endif // ADSCAN_H

