/*
 * RDP Launch Header
 */

#ifndef RDP_H
#define RDP_H

#include <windows.h>

BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   wchar_t* outputPath, size_t outputLen);

BOOL LaunchRDP(const wchar_t* hostname, const wchar_t* username, 
               const wchar_t* password);

BOOL LaunchRDPWithDefaults(const wchar_t* hostname);

#endif // RDP_H

