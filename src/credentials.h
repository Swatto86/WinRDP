/*
 * Credential Management Header
 */

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <windows.h>

// Default credential management
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password);
BOOL LoadCredentials(const wchar_t* targetName, wchar_t* username, wchar_t* password);
BOOL DeleteCredentials(const wchar_t* targetName);

// RDP-specific credential management
BOOL SaveRDPCredentials(const wchar_t* hostname, const wchar_t* username, 
                        const wchar_t* password);
BOOL LoadRDPCredentials(const wchar_t* hostname, wchar_t* username, wchar_t* password);
BOOL DeleteRDPCredentials(const wchar_t* hostname);
BOOL DeleteAllWinRDPCredentials(void);

#endif // CREDENTIALS_H

