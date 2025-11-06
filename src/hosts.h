/*
 * Host Management Header
 */

#ifndef HOSTS_H
#define HOSTS_H

#include <windows.h>
#include "config.h"

// Host structure - represents an RDP server
typedef struct {
    wchar_t hostname[MAX_HOSTNAME_LEN];
    wchar_t description[MAX_DESCRIPTION_LEN];
    wchar_t lastConnected[64];  // ISO 8601 format: YYYY-MM-DD HH:MM:SS or "Never"
} Host;

// Host management functions
BOOL LoadHosts(Host** hosts, int* count);
BOOL SaveHosts(const Host* hosts, int count);
BOOL AddHost(const wchar_t* hostname, const wchar_t* description);
BOOL DeleteHost(const wchar_t* hostname);
BOOL DeleteAllHosts(void);
BOOL UpdateLastConnected(const wchar_t* hostname);
BOOL GetRecentHosts(Host** hosts, int* count, int maxCount);
void FreeHosts(Host* hosts, int count);

#endif // HOSTS_H

