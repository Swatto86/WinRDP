/*
 * Application Configuration
 * 
 * Constants and settings for the application
 */

#ifndef CONFIG_H
#define CONFIG_H

// Application information
#define APP_NAME                L"WinRDP"
#define APP_VERSION             L"1.0.0"
#define APP_CLASS_NAME          L"WinRDPWindowClass"
#define APP_WINDOW_TITLE        L"WinRDP Manager"

// Credential storage
#define CRED_TARGET_NAME        L"WinRDP:DefaultCredentials"
#define CRED_TARGET_PREFIX      L"WinRDP:TERMSRV/"

// File paths
#define HOSTS_FILE_NAME         L"hosts.csv"

// Registry settings for autostart
#define REG_RUN_KEY             L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define REG_APP_NAME            L"WinRDP"

// Buffer sizes
#define MAX_HOSTNAME_LEN        256
#define MAX_DESCRIPTION_LEN     512
#define MAX_USERNAME_LEN        256
#define MAX_PASSWORD_LEN        256

// Function declarations for utility functions
void CenterWindow(HWND hwnd);
void ShowErrorMessage(HWND hwnd, const wchar_t* message);
void ShowInfoMessage(HWND hwnd, const wchar_t* message);

#endif // CONFIG_H

