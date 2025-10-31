/*
 * Credential Management Module
 * 
 * This module handles storing and retrieving credentials using the
 * Windows Credential Manager API (wincred.h).
 * 
 * The Credential Manager is a secure storage system built into Windows
 * that keeps passwords encrypted. It's the same system used by Windows
 * to remember your passwords for network shares, websites, etc.
 * 
 * Key functions:
 *   CredWriteW  - Save a credential
 *   CredReadW   - Retrieve a credential
 *   CredDeleteW - Delete a credential
 *   CredFree    - Free memory allocated by CredReadW
 */

#include <windows.h>
#include <wincred.h>
#include <stdio.h>
#include "config.h"
#include "credentials.h"

/*
 * SaveCredentials - Save username and password to Windows Credential Manager
 * 
 * Parameters:
 *   targetName - The name/identifier for this credential (NULL = use default)
 *   username   - The username to save
 *   password   - The password to save
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 * 
 * Learning notes:
 *   - We use CRED_TYPE_GENERIC for application credentials
 *   - CRED_PERSIST_LOCAL_MACHINE makes it persist across reboots
 *   - The password is stored as a BLOB (Binary Large OBject)
 *   - All strings must be wide (Unicode) strings
 */
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password)
{
    CREDENTIALW cred = {0};
    
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;
    
    // Set up the credential structure
    cred.Type = CRED_TYPE_GENERIC;                    // Generic application credential
    cred.TargetName = (LPWSTR)targetName;             // Identifier for this credential
    cred.CredentialBlobSize = (DWORD)(wcslen(password) * sizeof(wchar_t));  // Password size in bytes
    cred.CredentialBlob = (LPBYTE)password;           // The actual password data
    cred.Persist = CRED_PERSIST_LOCAL_MACHINE;        // Save permanently
    cred.UserName = (LPWSTR)username;                 // The username
    
    // Write the credential to the store
    // CredWriteW returns TRUE on success, FALSE on failure
    if (!CredWriteW(&cred, 0))
    {
        // GetLastError() returns the error code
        // Common errors:
        //   ERROR_BAD_USERNAME - Invalid username format
        //   ERROR_ACCESS_DENIED - No permission to write credentials
        DWORD error = GetLastError();
        wchar_t errorMsg[256];
        swprintf(errorMsg, 256, L"Failed to save credentials. Error code: %lu", error);
        MessageBoxW(NULL, errorMsg, L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    return TRUE;
}

/*
 * LoadCredentials - Retrieve username and password from Credential Manager
 * 
 * Parameters:
 *   targetName - The name/identifier for this credential (NULL = use default)
 *   username   - Buffer to receive username (must be at least MAX_USERNAME_LEN)
 *   password   - Buffer to receive password (must be at least MAX_PASSWORD_LEN)
 * 
 * Returns:
 *   TRUE if credentials were found and loaded, FALSE otherwise
 */
BOOL LoadCredentials(const wchar_t* targetName, wchar_t* username, wchar_t* password)
{
    PCREDENTIALW pcred = NULL;
    
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;
    
    // Try to read the credential
    // CredReadW allocates memory that we must free with CredFree
    if (!CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred))
    {
        // Credential not found or other error
        return FALSE;
    }
    
    // Copy username
    if (pcred->UserName != NULL)
    {
        wcsncpy_s(username, MAX_USERNAME_LEN, pcred->UserName, _TRUNCATE);
    }
    else
    {
        username[0] = L'\0';
    }
    
    // Copy password
    // The password is stored as a binary blob, we need to convert it back to a string
    if (pcred->CredentialBlob != NULL && pcred->CredentialBlobSize > 0)
    {
        size_t passwordLen = pcred->CredentialBlobSize / sizeof(wchar_t);
        if (passwordLen >= MAX_PASSWORD_LEN)
            passwordLen = MAX_PASSWORD_LEN - 1;
            
        wcsncpy_s(password, MAX_PASSWORD_LEN, (wchar_t*)pcred->CredentialBlob, passwordLen);
        password[passwordLen] = L'\0';
    }
    else
    {
        password[0] = L'\0';
    }
    
    // IMPORTANT: Free the memory allocated by CredReadW
    CredFree(pcred);
    
    return TRUE;
}

/*
 * DeleteCredentials - Remove credentials from Credential Manager
 * 
 * Parameters:
 *   targetName - The name/identifier for this credential (NULL = use default)
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL DeleteCredentials(const wchar_t* targetName)
{
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;
    
    if (!CredDeleteW(targetName, CRED_TYPE_GENERIC, 0))
    {
        DWORD error = GetLastError();
        
        // ERROR_NOT_FOUND is okay - credential didn't exist anyway
        if (error == ERROR_NOT_FOUND)
            return TRUE;
            
        return FALSE;
    }
    
    return TRUE;
}

/*
 * SaveRDPCredentials - Save credentials for a specific RDP host
 * 
 * This stores credentials for individual hosts, allowing per-host credential
 * management. The target name format "WinRDP:TERMSRV/hostname" allows the
 * application to distinguish between per-host and global credentials.
 * 
 * Per-host credentials take precedence over global credentials when connecting.
 * 
 * Parameters:
 *   hostname - The RDP server hostname
 *   username - Username for this specific host
 *   password - Password for this specific host
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL SaveRDPCredentials(const wchar_t* hostname, const wchar_t* username, 
                        const wchar_t* password)
{
    wchar_t targetName[512];
    
    // Format: "WinRDP:TERMSRV/hostname"
    // The TERMSRV prefix matches Windows RDP client convention
    // This allows per-host credential storage separate from global credentials
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    
    return SaveCredentials(targetName, username, password);
}

/*
 * LoadRDPCredentials - Load credentials for a specific RDP host
 * 
 * Retrieves per-host credentials if they exist. Returns FALSE if no
 * per-host credentials are stored for the given hostname.
 * 
 * Note: This function only loads per-host credentials. For connection logic
 * that falls back to global credentials, see LaunchRDP() in rdp.c.
 * 
 * Parameters:
 *   hostname - The RDP server hostname
 *   username - Buffer to receive username (must be at least MAX_USERNAME_LEN)
 *   password - Buffer to receive password (must be at least MAX_PASSWORD_LEN)
 * 
 * Returns:
 *   TRUE if per-host credentials were found and loaded, FALSE otherwise
 */
BOOL LoadRDPCredentials(const wchar_t* hostname, wchar_t* username, wchar_t* password)
{
    wchar_t targetName[512];
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    
    return LoadCredentials(targetName, username, password);
}

/*
 * DeleteRDPCredentials - Delete credentials for a specific RDP host
 */
BOOL DeleteRDPCredentials(const wchar_t* hostname)
{
    wchar_t targetName[512];
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    
    return DeleteCredentials(targetName);
}

