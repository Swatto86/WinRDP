/*
 * RDP Launch Module
 * 
 * This module creates RDP connection files and launches the Microsoft
 * Remote Desktop client (mstsc.exe).
 * 
 * RDP files are simple text files with key=value pairs that configure
 * the remote desktop connection. Windows reads these files to know
 * how to connect to a server.
 * 
 * Learning points:
 *   - File I/O for creating temporary files
 *   - ShellExecuteW for launching applications
 *   - Working with temporary directories
 */

#include <windows.h>
#include <shellapi.h>
#include <stdio.h>
#include <time.h>
#include "config.h"
#include "credentials.h"
#include "rdp.h"

/*
 * CreateRDPFile - Generate an RDP configuration file
 * 
 * Parameters:
 *   hostname     - The RDP server to connect to
 *   username     - Username for the connection (can be NULL)
 *   outputPath   - Buffer to receive the path to the created file
 *   outputLen    - Size of the outputPath buffer
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 * 
 * The RDP file format is documented at:
 * https://docs.microsoft.com/en-us/windows-server/remote/remote-desktop-services/clients/rdp-files
 */
BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   wchar_t* outputPath, size_t outputLen)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t tempPath[MAX_PATH];
    wchar_t rdpPath[MAX_PATH];
    
    // Get the temporary directory
    // This is typically C:\Users\[Username]\AppData\Local\Temp
    if (GetTempPathW(MAX_PATH, tempPath) == 0)
    {
        return FALSE;
    }
    
    // Create a unique filename using timestamp
    // This prevents conflicts if multiple connections are launched
    time_t now = time(NULL);
    swprintf_s(rdpPath, MAX_PATH, L"%sWinRDP_%lld.rdp", tempPath, (long long)now);
    
    // Open the file for writing
    err = _wfopen_s(&file, rdpPath, L"w, ccs=UTF-8");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    /*
     * Write RDP configuration
     * 
     * Key settings explained:
     *   screen mode id:i:2           - Full screen mode
     *   desktopwidth/height          - Screen resolution
     *   session bpp:i:32             - Color depth (32-bit)
     *   full address:s:[hostname]    - Server to connect to
     *   authentication level:i:0     - Don't require server auth (for older servers)
     *   prompt for credentials:i:0   - Use saved credentials, don't prompt
     *   redirectclipboard:i:1        - Enable clipboard sharing
     *   redirectprinters:i:1         - Enable printer redirection
     */
    fwprintf(file, L"screen mode id:i:2\n");
    fwprintf(file, L"use multimon:i:0\n");
    fwprintf(file, L"desktopwidth:i:1920\n");
    fwprintf(file, L"desktopheight:i:1080\n");
    fwprintf(file, L"session bpp:i:32\n");
    fwprintf(file, L"full address:s:%ls\n", hostname);
    fwprintf(file, L"compression:i:1\n");
    fwprintf(file, L"keyboardhook:i:2\n");
    fwprintf(file, L"audiocapturemode:i:0\n");
    fwprintf(file, L"videoplaybackmode:i:1\n");
    fwprintf(file, L"connection type:i:7\n");
    fwprintf(file, L"networkautodetect:i:1\n");
    fwprintf(file, L"bandwidthautodetect:i:1\n");
    fwprintf(file, L"displayconnectionbar:i:1\n");
    fwprintf(file, L"enableworkspacereconnect:i:1\n");
    fwprintf(file, L"disable wallpaper:i:0\n");
    fwprintf(file, L"allow font smoothing:i:1\n");
    fwprintf(file, L"allow desktop composition:i:1\n");
    fwprintf(file, L"disable full window drag:i:0\n");
    fwprintf(file, L"disable menu anims:i:0\n");
    fwprintf(file, L"disable themes:i:0\n");
    fwprintf(file, L"disable cursor setting:i:0\n");
    fwprintf(file, L"bitmapcachepersistenable:i:1\n");
    fwprintf(file, L"audiomode:i:0\n");
    fwprintf(file, L"redirectprinters:i:1\n");
    fwprintf(file, L"redirectcomports:i:0\n");
    fwprintf(file, L"redirectsmartcards:i:1\n");
    fwprintf(file, L"redirectclipboard:i:1\n");
    fwprintf(file, L"redirectposdevices:i:0\n");
    fwprintf(file, L"autoreconnection enabled:i:1\n");
    fwprintf(file, L"authentication level:i:0\n");
    fwprintf(file, L"prompt for credentials:i:0\n");
    fwprintf(file, L"negotiate security layer:i:1\n");
    fwprintf(file, L"remoteapplicationmode:i:0\n");
    fwprintf(file, L"alternate shell:s:\n");
    fwprintf(file, L"shell working directory:s:\n");
    fwprintf(file, L"gatewayhostname:s:\n");
    fwprintf(file, L"gatewayusagemethod:i:4\n");
    fwprintf(file, L"gatewaycredentialssource:i:4\n");
    fwprintf(file, L"gatewayprofileusagemethod:i:0\n");
    fwprintf(file, L"promptcredentialonce:i:1\n");
    fwprintf(file, L"use redirection server name:i:0\n");
    
    // Add username if provided
    if (username != NULL && wcslen(username) > 0)
    {
        fwprintf(file, L"username:s:%ls\n", username);
    }
    
    fclose(file);
    
    // Return the path to the caller
    wcsncpy_s(outputPath, outputLen, rdpPath, _TRUNCATE);
    
    return TRUE;
}

/*
 * LaunchRDP - Connect to an RDP server
 * 
 * This function:
 *   1. Saves credentials to Windows Credential Manager
 *   2. Creates a temporary RDP file
 *   3. Launches mstsc.exe with the RDP file
 *   4. Cleans up the temporary file
 * 
 * Parameters:
 *   hostname - The RDP server to connect to
 *   username - Username (if NULL, uses default credentials)
 *   password - Password (if NULL, uses default credentials)
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL LaunchRDP(const wchar_t* hostname, const wchar_t* username, 
               const wchar_t* password)
{
    wchar_t rdpPath[MAX_PATH];
    wchar_t actualUsername[MAX_USERNAME_LEN];
    wchar_t actualPassword[MAX_PASSWORD_LEN];
    
    // If credentials not provided, try to load default credentials
    if (username == NULL || password == NULL)
    {
        if (!LoadCredentials(NULL, actualUsername, actualPassword))
        {
            MessageBoxW(NULL, 
                       L"No credentials provided and no default credentials saved.\n"
                       L"Please enter credentials first.",
                       L"Error", MB_OK | MB_ICONERROR);
            return FALSE;
        }
    }
    else
    {
        wcsncpy_s(actualUsername, MAX_USERNAME_LEN, username, _TRUNCATE);
        wcsncpy_s(actualPassword, MAX_PASSWORD_LEN, password, _TRUNCATE);
    }
    
    // Save credentials for this specific RDP session
    // The format TERMSRV/hostname is what Windows RDP client expects
    if (!SaveRDPCredentials(hostname, actualUsername, actualPassword))
    {
        MessageBoxW(NULL, L"Failed to save RDP credentials.", 
                   L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    // Create the RDP file
    if (!CreateRDPFile(hostname, actualUsername, rdpPath, MAX_PATH))
    {
        MessageBoxW(NULL, L"Failed to create RDP file.", 
                   L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    /*
     * Launch mstsc.exe with ShellExecuteW
     * 
     * ShellExecuteW is a powerful function that can:
     *   - Open files with their associated application
     *   - Run executables
     *   - Open URLs in the browser
     *   - etc.
     * 
     * Parameters:
     *   hwnd       - Parent window (NULL = none)
     *   lpVerb     - Action to perform ("open", "edit", "print", etc.)
     *   lpFile     - File or program to execute
     *   lpParams   - Command line parameters
     *   lpDir      - Working directory (NULL = current directory)
     *   nShowCmd   - How to show the window (SW_SHOWNORMAL, SW_HIDE, etc.)
     * 
     * Returns:
     *   A value > 32 on success, <= 32 on error
     */
    HINSTANCE result = ShellExecuteW(
        NULL,                   // No parent window
        L"open",                // Action: open the file
        L"mstsc.exe",           // Program: RDP client
        rdpPath,                // Parameter: path to RDP file
        NULL,                   // Working directory: default
        SW_SHOWNORMAL           // Show window normally
    );
    
    // Check for errors
    if ((INT_PTR)result <= 32)
    {
        wchar_t errorMsg[256];
        swprintf_s(errorMsg, 256, 
                  L"Failed to launch RDP client.\nError code: %d", 
                  (int)(INT_PTR)result);
        MessageBoxW(NULL, errorMsg, L"Error", MB_OK | MB_ICONERROR);
        
        // Clean up the RDP file
        DeleteFileW(rdpPath);
        return FALSE;
    }
    
    // Give mstsc.exe time to read the file before we delete it
    Sleep(1000);
    
    // Clean up the temporary RDP file
    DeleteFileW(rdpPath);
    
    return TRUE;
}

/*
 * LaunchRDPWithDefaults - Connect using default credentials
 * 
 * This is a convenience function that loads the default credentials
 * and launches the RDP connection.
 */
BOOL LaunchRDPWithDefaults(const wchar_t* hostname)
{
    return LaunchRDP(hostname, NULL, NULL);
}

