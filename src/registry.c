/*
 * Registry Management Module
 * 
 * The Windows Registry is a hierarchical database that stores
 * configuration settings and options for Windows and applications.
 * 
 * This module handles:
 *   - Reading and writing registry values
 *   - Autostart configuration (Run key)
 * 
 * Learning points:
 *   - Registry hives (HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE, etc.)
 *   - Registry keys and values
 *   - Registry data types (REG_SZ, REG_DWORD, etc.)
 * 
 * Key functions:
 *   RegOpenKeyExW   - Open a registry key
 *   RegSetValueExW  - Write a value
 *   RegQueryValueExW - Read a value
 *   RegDeleteValueW - Delete a value
 *   RegCloseKey    - Close the key (always call this!)
 */

#include <windows.h>
#include <stdio.h>
#include "config.h"
#include "registry.h"

/*
 * IsAutostartEnabled - Check if the application is set to autostart
 * 
 * The Run key in the registry contains programs that start automatically
 * when Windows starts. We check if our application is listed there.
 * 
 * Registry path: HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
 */
BOOL IsAutostartEnabled(void)
{
    HKEY hKey;
    LONG result;
    DWORD dataSize = 0;
    
    /*
     * RegOpenKeyExW - Open a registry key
     * 
     * Parameters:
     *   hKey      - Parent key (HKEY_CURRENT_USER, HKEY_LOCAL_MACHINE, etc.)
     *   lpSubKey  - Path to the key to open
     *   ulOptions - Reserved, must be 0
     *   samDesired - Access rights (KEY_READ, KEY_WRITE, etc.)
     *   phkResult - Receives handle to opened key
     * 
     * Returns:
     *   ERROR_SUCCESS on success, error code on failure
     */
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,      // Open in current user's hive
        REG_RUN_KEY,            // Path to Run key
        0,                      // Reserved
        KEY_READ,               // We only need read access
        &hKey                   // Receives the key handle
    );
    
    if (result != ERROR_SUCCESS)
    {
        // Key doesn't exist or can't be opened
        return FALSE;
    }
    
    /*
     * RegQueryValueExW - Query a registry value
     * 
     * We call it first with NULL data buffer to get the size,
     * then we know our value exists if it returns ERROR_SUCCESS
     */
    result = RegQueryValueExW(
        hKey,                   // Key handle
        REG_APP_NAME,           // Value name to query
        NULL,                   // Reserved
        NULL,                   // Don't need the type
        NULL,                   // Don't need the data (yet)
        &dataSize               // Receives size of data
    );
    
    // Always close the key when done!
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS);
}

/*
 * EnableAutostart - Add the application to Windows startup
 * 
 * This creates a registry value in the Run key with the path
 * to our executable, causing Windows to run it at startup.
 */
BOOL EnableAutostart(void)
{
    HKEY hKey;
    LONG result;
    wchar_t exePath[MAX_PATH];
    
    // Get the full path to our executable
    // GetModuleFileNameW returns the path of the current EXE
    if (GetModuleFileNameW(NULL, exePath, MAX_PATH) == 0)
    {
        return FALSE;
    }
    
    // Open the Run key with write access
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        REG_RUN_KEY,
        0,
        KEY_WRITE,              // We need write access
        &hKey
    );
    
    if (result != ERROR_SUCCESS)
    {
        return FALSE;
    }
    
    /*
     * RegSetValueExW - Write a value to the registry
     * 
     * Parameters:
     *   hKey     - Key handle
     *   lpValueName - Name of the value
     *   Reserved - Must be 0
     *   dwType   - Type of data (REG_SZ = string, REG_DWORD = number, etc.)
     *   lpData   - Pointer to the data
     *   cbData   - Size of the data in bytes
     */
    result = RegSetValueExW(
        hKey,
        REG_APP_NAME,
        0,
        REG_SZ,                 // String type
        (const BYTE*)exePath,   // Our executable path
        (DWORD)((wcslen(exePath) + 1) * sizeof(wchar_t))  // Size including null terminator
    );
    
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS);
}

/*
 * DisableAutostart - Remove the application from Windows startup
 */
BOOL DisableAutostart(void)
{
    HKEY hKey;
    LONG result;
    
    // Open the Run key with write access
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        REG_RUN_KEY,
        0,
        KEY_WRITE,
        &hKey
    );
    
    if (result != ERROR_SUCCESS)
    {
        return FALSE;
    }
    
    // Delete our value
    result = RegDeleteValueW(hKey, REG_APP_NAME);
    
    RegCloseKey(hKey);
    
    // It's okay if the value didn't exist
    return (result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);
}

/*
 * ToggleAutostart - Enable if disabled, disable if enabled
 * 
 * Returns the new state (TRUE = enabled, FALSE = disabled)
 */
BOOL ToggleAutostart(void)
{
    if (IsAutostartEnabled())
    {
        DisableAutostart();
        return FALSE;
    }
    else
    {
        EnableAutostart();
        return TRUE;
    }
}

