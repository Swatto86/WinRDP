/*
 * WinRDP - Educational Windows RDP Manager in Pure C
 * 
 * This is a learning project demonstrating Windows API programming concepts:
 * - Window creation and message handling
 * - System tray icons
 * - Dialog boxes
 * - ListView controls
 * - Credential Manager API
 * - Global hotkeys (RegisterHotKey, WM_HOTKEY)
 * - Registry operations
 * - Process launching
 * 
 * Author: Swatto
 * License: Public Domain
 */

#include <windows.h>
#include <commctrl.h>
#include <shellapi.h>
#include <wincred.h>
#include <stdio.h>
#include <strsafe.h>

// Include our header files
#include "resource.h"
#include "config.h"
#include "credentials.h"
#include "hosts.h"
#include "rdp.h"
#include "registry.h"
#include "darkmode.h"
#include "adscan.h"

// Forward declarations of our functions
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK HostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK AddHostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ScanDomainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK ScanResultsDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK AboutDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL InitSystemTray(HWND hwnd);
BOOL ShowSystemTrayIcon(HWND hwnd);
BOOL HideSystemTrayIcon(HWND hwnd);
void ShowContextMenu(HWND hwnd);

// Global variables
HINSTANCE g_hInstance = NULL;
NOTIFYICONDATA g_nid = {0};
HWND g_hwndMain = NULL;

// Dialog instance tracking
static HWND g_hwndLoginDialog = NULL;
static HWND g_hwndMainDialog = NULL;
static HWND g_hwndHostDialog = NULL;
static HWND g_hwndAddHostDialog = NULL;

// Scan results tracking
static int g_scanComputerCount = 0;

// Timer ID for auto-close countdown
#define TIMER_AUTO_CLOSE_LOGIN 1

// Scan domain parameters
typedef struct {
    wchar_t domain[256];
    BOOL includeWorkstations;
    BOOL includeServers;
    BOOL includeDomainControllers;
} ScanParams;

// Edit host data (for pre-filling edit dialog)
typedef struct {
    wchar_t originalHostname[MAX_HOSTNAME_LEN];  // Original hostname (for deletion if renamed)
    wchar_t hostname[MAX_HOSTNAME_LEN];
    wchar_t description[MAX_DESCRIPTION_LEN];
    BOOL isEdit;  // TRUE if editing, FALSE if adding new
} EditHostData;

// ListView sorting state
typedef struct {
    int sortColumn;      // Column being sorted (1=Hostname, 2=Description)
    BOOL sortAscending;  // TRUE for ascending, FALSE for descending
    Host* hosts;         // Pointer to host array for sorting
    int hostCount;       // Number of hosts
} SortParams;

// Search text tracking for highlighting
typedef struct {
    wchar_t searchText[256];
    BOOL hasSearchText;
} SearchContext;

// Forward declaration for sort comparison function
int CALLBACK CompareListViewItems(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

/*
 * WinMain - Entry point for Windows GUI applications
 * 
 * Parameters:
 *   hInstance     - Handle to the current instance of the application
 *   hPrevInstance - Always NULL (legacy from 16-bit Windows)
 *   lpCmdLine     - Command line arguments as a string
 *   nCmdShow      - How the window should be shown (minimized, maximized, etc.)
 * 
 * Returns:
 *   Exit code (0 for success)
 */
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPWSTR lpCmdLine, int nCmdShow)
{
    // Suppress unused parameter warnings
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    // Check for single instance using a named mutex
    HANDLE hMutex = CreateMutexW(NULL, TRUE, L"WinRDP_SingleInstance_Mutex");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        // Another instance is already running
        MessageBoxW(NULL, 
                   L"WinRDP is already running.\n\nPlease check the system tray for the running instance.",
                   L"WinRDP - Already Running",
                   MB_OK | MB_ICONINFORMATION);
        
        if (hMutex)
            CloseHandle(hMutex);
        
        return 0;
    }

    // Store instance handle globally for later use
    g_hInstance = hInstance;

    // Initialize common controls (ListView, TreeView, etc.)
    // This must be called before using any common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_LISTVIEW_CLASSES | ICC_STANDARD_CLASSES;
    InitCommonControlsEx(&icex);
    
    // Initialize dark mode support
    InitDarkMode();

    // Register the main window class
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = APP_CLASS_NAME;
    wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));

    if (!RegisterClassExW(&wc))
    {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error", 
                    MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }

    // Create the main window (hidden, used for message processing)
    // The actual UI will be shown in dialogs
    g_hwndMain = CreateWindowExW(
        0,                          // Extended window style
        APP_CLASS_NAME,             // Window class name
        APP_WINDOW_TITLE,           // Window title
        WS_OVERLAPPEDWINDOW,        // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, // Position (x, y)
        CW_USEDEFAULT, CW_USEDEFAULT, // Size (width, height)
        NULL,                       // Parent window
        NULL,                       // Menu
        hInstance,                  // Instance handle
        NULL                        // Additional application data
    );

    if (g_hwndMain == NULL)
    {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error",
                    MB_ICONEXCLAMATION | MB_OK);
        return 1;
    }

    // Initialize system tray icon
    InitSystemTray(g_hwndMain);

    // Don't show the main window, just keep it for message processing
    // ShowWindow(g_hwndMain, SW_HIDE);
    // UpdateWindow(g_hwndMain);

    // Show the login dialog at startup (pass 0 for normal behavior with countdown)
    INT_PTR loginResult = DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_LOGIN), g_hwndMain, LoginDialogProc, 0);
    
    // If credentials were saved, show the main server list dialog
    if (loginResult == IDOK)
    {
        DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), g_hwndMain, MainDialogProc);
    }

    /*
     * The Message Loop
     * 
     * This is the heart of a Windows application. It continuously:
     * 1. Gets messages from the message queue (GetMessage)
     * 2. Translates keyboard input (TranslateMessage)
     * 3. Dispatches messages to the window procedure (DispatchMessage)
     * 
     * GetMessage returns 0 when WM_QUIT is received, ending the loop
     */
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Clean up system tray icon before exiting
    HideSystemTrayIcon(g_hwndMain);

    // Release the mutex
    if (hMutex)
        CloseHandle(hMutex);

    return (int)msg.wParam;
}

/*
 * WndProc - Main Window Procedure (Message Handler)
 * 
 * This function processes all messages sent to the window.
 * Windows uses a message-passing architecture where the OS sends
 * messages to windows to notify them of events.
 * 
 * Common messages:
 *   WM_CREATE  - Window is being created
 *   WM_DESTROY - Window is being destroyed
 *   WM_PAINT   - Window needs to be redrawn
 *   WM_COMMAND - User clicked a menu/button
 *   etc.
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
            // Register global hotkey (Ctrl+Shift+R) to open connect dialog
            if (!RegisterHotKey(hwnd, IDM_GLOBAL_HOTKEY, MOD_CONTROL | MOD_SHIFT, 'R'))
            {
                // Hotkey registration failed - could be in use by another app
                // Silently fail - the app will still work without the hotkey
            }
            return 0;

        case WM_TRAYICON:
            // Custom message for system tray icon events
            switch (LOWORD(lParam))
            {
                case WM_LBUTTONUP:
                    // Left click - show main dialog
                    if (g_hwndMainDialog == NULL)
                    {
                        DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                                 hwnd, MainDialogProc);
                    }
                    else
                    {
                        // Bring existing dialog to front
                        SetForegroundWindow(g_hwndMainDialog);
                    }
                    break;

                case WM_RBUTTONUP:
                    // Right click - show context menu
                    ShowContextMenu(hwnd);
                    break;
            }
            return 0;

        case WM_COMMAND:
            // Menu or button command
            switch (LOWORD(wParam))
            {
                case IDM_OPEN:
                    // Show main dialog
                    if (g_hwndMainDialog == NULL)
                    {
                        DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                                 hwnd, MainDialogProc);
                    }
                    else
                    {
                        // Bring existing dialog to front
                        SetForegroundWindow(g_hwndMainDialog);
                    }
                    break;

                case IDM_ABOUT_DIALOG:
                    // Show About dialog
                    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ABOUT), 
                             hwnd, AboutDialogProc);
                    break;

                case IDM_ABOUT:
                    // Toggle autostart
                    ToggleAutostart();
                    break;

                case IDM_EXIT:
                    PostQuitMessage(0);
                    break;
                
                default:
                    // Handle recent connections menu items
                    // These are in the range IDM_RECENT_START to IDM_RECENT_END
                    if (LOWORD(wParam) >= IDM_RECENT_START && LOWORD(wParam) <= IDM_RECENT_END)
                    {
                        // Calculate which recent host was clicked
                        int recentIndex = LOWORD(wParam) - IDM_RECENT_START;
                        
                        // Get the recent hosts again to retrieve the selected hostname
                        Host* recentHosts = NULL;
                        int recentCount = 0;
                        
                        if (GetRecentHosts(&recentHosts, &recentCount, 5))
                        {
                            // Verify the index is valid
                            if (recentIndex >= 0 && recentIndex < recentCount)
                            {
                                // Launch RDP connection to the selected host
                                LaunchRDPWithDefaults(recentHosts[recentIndex].hostname);
                            }
                            
                            // Free the hosts array
                            FreeHosts(recentHosts, recentCount);
                        }
                    }
                    break;
            }
            return 0;

        case WM_HOTKEY:
            // Handle global hotkey for toggling connect dialog
            if (wParam == IDM_GLOBAL_HOTKEY)
            {
                // Check if we have global credentials saved
                wchar_t username[MAX_USERNAME_LEN];
                wchar_t password[MAX_PASSWORD_LEN];
                
                if (LoadCredentials(NULL, username, password))
                {
                    // We have global credentials - toggle main dialog
                    if (g_hwndMainDialog == NULL)
                    {
                        // Dialog not shown - show it
                        DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                                 hwnd, MainDialogProc);
                    }
                    else
                    {
                        // Dialog is shown - check if it's visible or minimized
                        if (IsWindowVisible(g_hwndMainDialog) && !IsIconic(g_hwndMainDialog))
                        {
                            // Window is visible and not minimized - close it
                            PostMessage(g_hwndMainDialog, WM_CLOSE, 0, 0);
                        }
                        else
                        {
                            // Window exists but is hidden or minimized - bring it to front
                            ShowWindow(g_hwndMainDialog, SW_RESTORE);
                            SetForegroundWindow(g_hwndMainDialog);
                        }
                    }
                }
                else
                {
                    // No global credentials - toggle login dialog
                    if (g_hwndLoginDialog == NULL)
                    {
                        // Dialog not shown - show it
                        // Pass 0 to allow normal startup behavior with countdown
                        DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), 
                                      hwnd, LoginDialogProc, 0);
                    }
                    else
                    {
                        // Dialog is shown - check if it's visible or minimized
                        if (IsWindowVisible(g_hwndLoginDialog) && !IsIconic(g_hwndLoginDialog))
                        {
                            // Window is visible and not minimized - close it
                            PostMessage(g_hwndLoginDialog, WM_CLOSE, 0, 0);
                        }
                        else
                        {
                            // Window exists but is hidden or minimized - bring it to front
                            ShowWindow(g_hwndLoginDialog, SW_RESTORE);
                            SetForegroundWindow(g_hwndLoginDialog);
                        }
                    }
                }
            }
            return 0;

        case WM_DESTROY:
            // Unregister global hotkey
            UnregisterHotKey(hwnd, IDM_GLOBAL_HOTKEY);
            // Window is being destroyed - quit the application
            PostQuitMessage(0);
            return 0;
    }

    // Let Windows handle any messages we don't process
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

/*
 * InitSystemTray - Initialize the system tray icon
 * 
 * The system tray (notification area) allows applications to run
 * in the background with just a small icon visible.
 */
BOOL InitSystemTray(HWND hwnd)
{
    g_nid.cbSize = sizeof(NOTIFYICONDATA);
    g_nid.hWnd = hwnd;
    g_nid.uID = ID_TRAYICON;
    g_nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    g_nid.uCallbackMessage = WM_TRAYICON;
    g_nid.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    StringCchCopyW(g_nid.szTip, ARRAYSIZE(g_nid.szTip), L"WinRDP Manager");

    return Shell_NotifyIcon(NIM_ADD, &g_nid);
}

BOOL ShowSystemTrayIcon(HWND hwnd)
{
    UNREFERENCED_PARAMETER(hwnd);
    return Shell_NotifyIcon(NIM_ADD, &g_nid);
}

BOOL HideSystemTrayIcon(HWND hwnd)
{
    UNREFERENCED_PARAMETER(hwnd);
    return Shell_NotifyIcon(NIM_DELETE, &g_nid);
}

/*
 * ShowContextMenu - Display right-click menu for tray icon
 * 
 * Enhanced with Recent Connections feature:
 * - Displays the 5 most recently connected servers
 * - Allows one-click connection without opening main window
 * - Shows only servers that have been connected to before
 * - Most convenient access for frequently used servers
 */
void ShowContextMenu(HWND hwnd)
{
    POINT pt;
    GetCursorPos(&pt);

    // Create popup menu
    HMENU hMenu = CreatePopupMenu();
    if (hMenu)
    {
        // Add recent connections section at the top
        Host* recentHosts = NULL;
        int recentCount = 0;
        
        // Get up to 5 most recently connected hosts
        if (GetRecentHosts(&recentHosts, &recentCount, 5) && recentCount > 0)
        {
            // Add a header for the recent connections section
            AppendMenuW(hMenu, MF_STRING | MF_GRAYED, 0, L"Recent Connections:");
            
            // Add each recent host to the menu
            for (int i = 0; i < recentCount && i < 5; i++)
            {
                // Format: "hostname (description)" or just "hostname" if no description
                wchar_t menuText[MAX_HOSTNAME_LEN + MAX_DESCRIPTION_LEN + 10];
                if (wcslen(recentHosts[i].description) > 0)
                {
                    swprintf_s(menuText, sizeof(menuText)/sizeof(wchar_t), 
                              L"  %s  (%s)", 
                              recentHosts[i].hostname, 
                              recentHosts[i].description);
                }
                else
                {
                    swprintf_s(menuText, sizeof(menuText)/sizeof(wchar_t), 
                              L"  %s", 
                              recentHosts[i].hostname);
                }
                
                // Add menu item with ID in the range IDM_RECENT_START to IDM_RECENT_END
                // We'll use the index to map back to the hostname
                AppendMenuW(hMenu, MF_STRING, IDM_RECENT_START + i, menuText);
            }
            
            // Free the hosts array
            FreeHosts(recentHosts, recentCount);
            
            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
        }
        
        AppendMenuW(hMenu, MF_STRING, IDM_OPEN, L"Open");
        AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
        
        // Add autostart option with checkmark if enabled
        UINT autostartFlags = MF_STRING;
        if (IsAutostartEnabled())
        {
            autostartFlags |= MF_CHECKED;
        }
        AppendMenuW(hMenu, autostartFlags, IDM_ABOUT, L"Start with Windows");
        
        AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
        AppendMenuW(hMenu, MF_STRING, IDM_ABOUT_DIALOG, L"About");
        AppendMenuW(hMenu, MF_STRING, IDM_EXIT, L"Exit");

        // Required to make menu disappear when clicking outside
        SetForegroundWindow(hwnd);

        TrackPopupMenu(hMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN,
                      pt.x, pt.y, 0, hwnd, NULL);

        DestroyMenu(hMenu);
    }
}

/*
 * LoginDialogProc - Dialog procedure for the login/credentials dialog
 * 
 * Dialog procedures are similar to window procedures but specifically
 * for dialog boxes. They return TRUE if they process a message,
 * FALSE otherwise.
 */
INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Static variable to track countdown seconds (persists across messages)
    static int s_countdownSeconds = 0;
    // Static flag to track if we're in edit mode (no auto-close)
    static BOOL s_isEditMode = FALSE;

    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Track this dialog instance
            g_hwndLoginDialog = hwnd;
            
            // Reset countdown
            s_countdownSeconds = 0;
            
            // Check if we're opening in edit mode (lParam = 1 means editing)
            s_isEditMode = (lParam == 1);
            
            // Dialog is being initialized
            CenterWindow(hwnd);
            
            // Apply dark mode if enabled
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Try to load existing credentials
            wchar_t username[MAX_USERNAME_LEN];
            wchar_t password[MAX_PASSWORD_LEN];
            
            if (LoadCredentials(NULL, username, password))
            {
                // Credentials exist - populate the fields
                SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username);
                SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password);
                
                // Show delete button
                ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_SHOW);
                
                // Only show countdown and start timer if NOT in edit mode
                if (!s_isEditMode)
                {
                    // Show compact status message and start countdown
                    s_countdownSeconds = 5;
                    wchar_t statusMsg[128];
                    swprintf_s(statusMsg, 128, L"✓ Credentials saved - Auto-closing in %d seconds...", s_countdownSeconds);
                    SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
                    
                    // Start timer - fires every 1 second (1000 milliseconds)
                    SetTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN, 1000, NULL);
                }
                else
                {
                    // Edit mode - show simple status without countdown
                    SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"✓ Credentials saved");
                }
            }
            else
            {
                // No credentials - hide the delete button
                ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_HIDE);
                SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"");
            }
            
            return TRUE;
        }
        
        case WM_TIMER:
        {
            // Handle timer events
            if (wParam == TIMER_AUTO_CLOSE_LOGIN)
            {
                // Decrement countdown
                s_countdownSeconds--;
                
                if (s_countdownSeconds > 0)
                {
                    // Update countdown message
                    wchar_t statusMsg[128];
                    swprintf_s(statusMsg, 128, L"✓ Credentials saved - Auto-closing in %d seconds...", s_countdownSeconds);
                    SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
                }
                else
                {
                    // Time's up - kill timer, close login dialog
                    // WinMain will automatically open the main dialog when EndDialog returns IDOK
                    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
                    s_countdownSeconds = 0;
                    
                    // Close the login dialog (returns IDOK to WinMain)
                    EndDialog(hwnd, IDOK);
                }
            }
            return TRUE;
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // Kill timer if it's running (user clicked OK manually)
                    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
                    s_countdownSeconds = 0;
                    
                    // User clicked OK - save credentials
                    wchar_t username[MAX_USERNAME_LEN];
                    wchar_t password[MAX_PASSWORD_LEN];
                    
                    // Get text from edit controls
                    GetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username, MAX_USERNAME_LEN);
                    GetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password, MAX_PASSWORD_LEN);
                    
                    // Validate
                    if (wcslen(username) == 0)
                    {
                        ShowErrorMessage(hwnd, L"Please enter a username.");
                        return TRUE;
                    }
                    
                    if (wcslen(password) == 0)
                    {
                        ShowErrorMessage(hwnd, L"Please enter a password.");
                        return TRUE;
                    }
                    
                    // Save credentials
                    if (SaveCredentials(NULL, username, password))
                    {
                        ShowInfoMessage(hwnd, L"Credentials saved successfully!");
                        EndDialog(hwnd, IDOK);
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Failed to save credentials.");
                    }
                    return TRUE;
                }

                case IDC_BTN_DELETE_CREDS:
                {
                    // Kill timer if running
                    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
                    s_countdownSeconds = 0;
                    
                    // Delete saved credentials
                    if (DeleteCredentials(NULL))
                    {
                        SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, L"");
                        SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, L"");
                        SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"");
                        ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_HIDE);
                        ShowInfoMessage(hwnd, L"Credentials deleted.");
                    }
                    return TRUE;
                }

                case IDCANCEL:
                    // Kill timer if running
                    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
                    s_countdownSeconds = 0;
                    g_hwndLoginDialog = NULL;
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            // Kill timer if running
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            g_hwndLoginDialog = NULL;
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
            
        case WM_DESTROY:
            // Kill timer if running
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            g_hwndLoginDialog = NULL;
            return TRUE;
    }

    // Handle dark mode color messages
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;

    return FALSE;
}

/*
 * CompareListViewItems - Comparison function for ListView sorting
 * 
 * This is a callback function used by ListView_SortItems to compare two items.
 * It compares items based on the current sort column and direction.
 * 
 * Parameters:
 *   lParam1 - lParam of first item (host index in our case)
 *   lParam2 - lParam of second item (host index in our case)
 *   lParamSort - Pointer to SortParams structure
 * 
 * Returns:
 *   Negative if item1 < item2
 *   Zero if item1 == item2
 *   Positive if item1 > item2
 */
int CALLBACK CompareListViewItems(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
    SortParams* params = (SortParams*)lParamSort;
    
    // Get the host indices
    int index1 = (int)lParam1;
    int index2 = (int)lParam2;
    
    // Bounds check
    if (index1 < 0 || index1 >= params->hostCount || 
        index2 < 0 || index2 >= params->hostCount)
    {
        return 0;
    }
    
    // Get the hosts to compare
    Host* host1 = &params->hosts[index1];
    Host* host2 = &params->hosts[index2];
    
    int result = 0;
    
    // Compare based on sort column
    if (params->sortColumn == 1)
    {
        // Sort by hostname
        result = _wcsicmp(host1->hostname, host2->hostname);
    }
    else if (params->sortColumn == 2)
    {
        // Sort by description
        result = _wcsicmp(host1->description, host2->description);
    }
    else if (params->sortColumn == 3)
    {
        // Sort by last connected timestamp
        // "Never" should sort to the end, so treat specially
        BOOL host1Never = (_wcsicmp(host1->lastConnected, L"Never") == 0);
        BOOL host2Never = (_wcsicmp(host2->lastConnected, L"Never") == 0);
        
        if (host1Never && host2Never)
        {
            result = 0;  // Both "Never" - equal
        }
        else if (host1Never)
        {
            result = 1;  // host1 is "Never", host2 has a date - host1 is "greater" (sorts later)
        }
        else if (host2Never)
        {
            result = -1;  // host2 is "Never", host1 has a date - host1 is "less" (sorts earlier)
        }
        else
        {
            // Both have dates - normal string compare works for ISO format
            result = wcscmp(host1->lastConnected, host2->lastConnected);
        }
    }
    
    // Reverse for descending sort
    if (!params->sortAscending)
    {
        result = -result;
    }
    
    return result;
}

/*
 * UpdateHostCountLabel - Update the host count status label
 * 
 * Parameters:
 *   hwndDialog - Handle to the dialog containing the label
 *   labelId - Control ID of the status label
 *   displayedCount - Number of hosts currently displayed
 *   totalCount - Total number of hosts
 * 
 * Updates the label to show "X hosts" or "Showing X of Y hosts" when filtered
 */
void UpdateHostCountLabel(HWND hwndDialog, int labelId, int displayedCount, int totalCount)
{
    wchar_t statusText[128];
    
    if (displayedCount == totalCount)
    {
        // No filtering - show simple count
        swprintf_s(statusText, 128, L"%d host%s", totalCount, (totalCount == 1 ? L"" : L"s"));
    }
    else
    {
        // Filtering active - show "X of Y hosts"
        swprintf_s(statusText, 128, L"Showing %d of %d host%s", 
                  displayedCount, totalCount, (totalCount == 1 ? L"" : L"s"));
    }
    
    SetDlgItemTextW(hwndDialog, labelId, statusText);
}

/*
 * LaunchRDPWithVisualFeedback - Connect with visual feedback
 * 
 * Feature 2: Visual Feedback on Connection
 * Shows wait cursor and brief status message while launching RDP connection.
 * 
 * Parameters:
 *   hwnd - Parent window handle
 *   hostname - The RDP server to connect to
 * 
 * Returns:
 *   TRUE on success, FALSE on failure
 */
BOOL LaunchRDPWithVisualFeedback(HWND hwnd, const wchar_t* hostname)
{
    // Change cursor to wait cursor for visual feedback
    HCURSOR hOldCursor = SetCursor(LoadCursor(NULL, IDC_WAIT));
    
    // Brief message to show we're connecting
    wchar_t statusMsg[512];
    swprintf_s(statusMsg, 512, L"Launching connection to %s...", hostname);
    SetWindowTextW(hwnd, statusMsg);
    
    // Force window update to show the message
    UpdateWindow(hwnd);
    
    // Small delay so user can see the feedback (100ms)
    Sleep(100);
    
    // Actually launch the RDP connection
    BOOL result = LaunchRDPWithDefaults(hostname);
    
    // Restore cursor
    SetCursor(hOldCursor);
    
    // Restore original window title
    SetWindowTextW(hwnd, APP_WINDOW_TITLE);
    
    return result;
}

/*
 * ResizeDescriptionColumn - Resize description column to fill available space
 * 
 * Feature 4: Auto-resize Description Column
 * Dynamically adjusts the description column width when the window is resized.
 * 
 * Parameters:
 *   hList - ListView handle
 */
void ResizeDescriptionColumn(HWND hList)
{
    // Get ListView client area
    RECT rcList;
    GetClientRect(hList, &rcList);
    int listWidth = rcList.right - rcList.left;
    
    // Calculate new description column width
    // Total width minus hostname (170) minus last connected (160) minus dummy (1) minus padding (5)
    int descWidth = listWidth - 170 - 160 - 1 - 5;
    
    // Ensure minimum width
    if (descWidth < 100)
        descWidth = 100;
    
    // Set the new width for description column (column 2)
    ListView_SetColumnWidth(hList, 2, descWidth);
}

/*
 * RefreshHostListView - Refresh the main ListView with optional filtering
 * 
 * Parameters:
 *   hList - Handle to the ListView control
 *   hosts - Array of hosts to display
 *   hostCount - Number of hosts in array
 *   searchText - Filter text (NULL or empty for no filtering)
 * 
 * This function refreshes the ListView with all hosts, optionally filtered
 * by the search text (searches both hostname and description).
 * Returns the number of displayed items.
 */
int RefreshHostListView(HWND hList, Host* hosts, int hostCount, const wchar_t* searchText)
{
    // Clear existing items
    ListView_DeleteAllItems(hList);
    
    if (hosts == NULL || hostCount == 0)
        return 0;
    
    // Check if we have a search filter
    BOOL hasFilter = (searchText != NULL && wcslen(searchText) > 0);
    
    // Convert search text to lowercase for case-insensitive search
    wchar_t searchLower[256] = {0};
    if (hasFilter)
    {
        wcsncpy_s(searchLower, 256, searchText, _TRUNCATE);
        _wcslwr_s(searchLower, 256);
    }
    
    // Add hosts to list, filtering if necessary
    int displayIndex = 0;
    for (int i = 0; i < hostCount; i++)
    {
        // If filtering, check if hostname or description matches
        if (hasFilter)
        {
            wchar_t hostnameLower[256] = {0};
            wchar_t descriptionLower[256] = {0};
            
            wcsncpy_s(hostnameLower, 256, hosts[i].hostname, _TRUNCATE);
            _wcslwr_s(hostnameLower, 256);
            
            wcsncpy_s(descriptionLower, 256, hosts[i].description, _TRUNCATE);
            _wcslwr_s(descriptionLower, 256);
            
            // Skip if neither hostname nor description contains the search text
            if (wcsstr(hostnameLower, searchLower) == NULL && 
                wcsstr(descriptionLower, searchLower) == NULL)
            {
                continue;
            }
        }
        
        // Add this host to the list
        LVITEMW item = {0};
        item.mask = LVIF_TEXT | LVIF_PARAM;
        item.iItem = displayIndex;
        item.iSubItem = 0;
        item.pszText = L"";  // Dummy column 0
        item.lParam = (LPARAM)i;  // Store original index for later reference
        ListView_InsertItem(hList, &item);
        
        ListView_SetItemText(hList, displayIndex, 1, hosts[i].hostname);  // Hostname in column 1
        ListView_SetItemText(hList, displayIndex, 2, hosts[i].description);  // Description in column 2
        ListView_SetItemText(hList, displayIndex, 3, hosts[i].lastConnected);  // Last Connected in column 3
        
        displayIndex++;
    }
    
    return displayIndex;  // Return number of displayed items
}

/*
 * MainDialogProc - Main server list dialog
 */
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    static SortParams sortParams = {1, TRUE, NULL, 0};  // Default: sort by hostname, ascending
    static SearchContext searchContext = {{0}, FALSE};  // Feature 3: Track search text for highlighting
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Track this dialog instance
            g_hwndMainDialog = hwnd;
            
            CenterWindow(hwnd);
            
            // Apply dark mode if enabled
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
            
            // Set extended ListView styles for better appearance
            ListView_SetExtendedListViewStyle(hList, 
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Apply dark mode to ListView
            ApplyDarkModeToListView(hList);
            
            // Get ListView client area to calculate proper column widths
            RECT rcList;
            GetClientRect(hList, &rcList);
            int listWidth = rcList.right - rcList.left;
            
            // Create columns that fill the ListView width exactly
            // Note: Column 0 cannot be centered, so we add a tiny dummy column and use 1 & 2
            LVCOLUMNW col = {0};
            
            // Add invisible dummy column at position 0
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            col.pszText = L"";
            col.cx = 1;  // Almost invisible
            ListView_InsertColumn(hList, 0, &col);
            
            // Now add the real columns which CAN be centered
            col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
            col.fmt = LVCFMT_CENTER;
            
            col.pszText = L"Hostname";
            col.cx = 170;
            ListView_InsertColumn(hList, 1, &col);
            
            col.pszText = L"Description";
            col.cx = listWidth - 170 - 160 - 5;  // Takes most of the remaining space
            ListView_InsertColumn(hList, 2, &col);
            
            col.pszText = L"Last Connected";
            col.cx = 160;  // Fixed width for timestamp
            ListView_InsertColumn(hList, 3, &col);
            
            // Load and display hosts
            if (LoadHosts(&hosts, &hostCount))
            {
                int displayedCount = RefreshHostListView(hList, hosts, hostCount, NULL);
                UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
            }
            
            return TRUE;
        }

        case WM_NOTIFY:
        {
            LPNMHDR pnmhdr = (LPNMHDR)lParam;
            
            if (pnmhdr->idFrom == IDC_LIST_SERVERS)
            {
                if (pnmhdr->code == NM_DBLCLK)
                {
                    // Double-click on a server - connect to it
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0)
                    {
                        // Get the original host index from lParam
                        LVITEMW item = {0};
                        item.mask = LVIF_PARAM;
                        item.iItem = selected;
                        ListView_GetItem(hList, &item);
                        int hostIndex = (int)item.lParam;
                        
                        if (hostIndex >= 0 && hostIndex < hostCount)
                        {
                            // Feature 2: Visual feedback on connection
                            if (LaunchRDPWithVisualFeedback(hwnd, hosts[hostIndex].hostname))
                            {
                                EndDialog(hwnd, IDOK);
                            }
                        }
                    }
                    return TRUE;
                }
                else if (pnmhdr->code == LVN_KEYDOWN)
                {
                    // Handle keyboard shortcuts on listview
                    LPNMLVKEYDOWN pnkd = (LPNMLVKEYDOWN)lParam;
                    
                    if (pnkd->wVKey == VK_RETURN)
                    {
                        // Enter key - connect to selected host
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                        int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                        
                        if (selected >= 0)
                        {
                            // Get the original host index from lParam
                            LVITEMW item = {0};
                            item.mask = LVIF_PARAM;
                            item.iItem = selected;
                            ListView_GetItem(hList, &item);
                            int hostIndex = (int)item.lParam;
                            
                            if (hostIndex >= 0 && hostIndex < hostCount)
                            {
                                // Feature 2: Visual feedback on connection
                                if (LaunchRDPWithVisualFeedback(hwnd, hosts[hostIndex].hostname))
                                {
                                    EndDialog(hwnd, IDOK);
                                }
                            }
                        }
                        return TRUE;
                    }
                    else if (pnkd->wVKey == VK_DELETE)
                    {
                        // Delete key - delete selected host
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                        int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                        
                        if (selected >= 0)
                        {
                            // Get the original host index from lParam
                            LVITEMW item = {0};
                            item.mask = LVIF_PARAM;
                            item.iItem = selected;
                            ListView_GetItem(hList, &item);
                            int hostIndex = (int)item.lParam;
                            
                            if (hostIndex >= 0 && hostIndex < hostCount)
                            {
                                // Confirm deletion
                                wchar_t msg[512];
                                swprintf_s(msg, 512, L"Delete host '%s'?", hosts[hostIndex].hostname);
                                
                                if (MessageBoxW(hwnd, msg, L"Confirm Delete", 
                                               MB_YESNO | MB_ICONQUESTION) == IDYES)
                                {
                                    if (DeleteHost(hosts[hostIndex].hostname))
                                    {
                                        // Reload the list
                                        FreeHosts(hosts, hostCount);
                                        hosts = NULL;
                                        hostCount = 0;
                                        
                                        if (LoadHosts(&hosts, &hostCount))
                                        {
                                            // Get search text if any
                                            HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
                                            wchar_t searchText[256] = {0};
                                            GetWindowTextW(hSearch, searchText, 256);
                                            
                                            int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                            UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
                                        }
                                    }
                                    else
                                    {
                                        ShowErrorMessage(hwnd, L"Failed to delete host.");
                                    }
                                }
                            }
                        }
                        return TRUE;
                    }
                }
                else if (pnmhdr->code == LVN_COLUMNCLICK)
                {
                    // Column header clicked - sort by that column
                    LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)lParam;
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    
                    // Note: Column 0 is dummy, so actual columns are 1, 2, 3
                    int clickedColumn = pnmlv->iSubItem;
                    
                    // Only sort if clicking on actual columns (not dummy column 0)
                    if (clickedColumn == 1 || clickedColumn == 2 || clickedColumn == 3)
                    {
                        // If clicking the same column, toggle sort direction
                        if (sortParams.sortColumn == clickedColumn)
                        {
                            sortParams.sortAscending = !sortParams.sortAscending;
                        }
                        else
                        {
                            // New column - default to ascending
                            sortParams.sortColumn = clickedColumn;
                            sortParams.sortAscending = TRUE;
                        }
                        
                        // Update sort params with current host data
                        sortParams.hosts = hosts;
                        sortParams.hostCount = hostCount;
                        
                        // Perform the sort
                        ListView_SortItems(hList, CompareListViewItems, (LPARAM)&sortParams);
                    }
                    return TRUE;
                }
                else if (pnmhdr->code == NM_RCLICK)
                {
                    // Right-click on ListView - show context menu
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0)
                    {
                        // Get cursor position for menu
                        POINT pt;
                        GetCursorPos(&pt);
                        
                        // Create popup menu
                        HMENU hMenu = CreatePopupMenu();
                        if (hMenu)
                        {
                            AppendMenuW(hMenu, MF_STRING, IDM_CONTEXT_CONNECT, L"Connect");
                            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
                            AppendMenuW(hMenu, MF_STRING, IDM_CONTEXT_DELETE, L"Delete");
                            
                            // Required to make menu disappear when clicking outside
                            SetForegroundWindow(hwnd);
                            
                            // Show menu and get selection
                            int cmd = TrackPopupMenu(hMenu, TPM_RETURNCMD | TPM_LEFTALIGN,
                                                    pt.x, pt.y, 0, hwnd, NULL);
                            
                            DestroyMenu(hMenu);
                            
                            // Handle menu selection
                            if (cmd == IDM_CONTEXT_CONNECT)
                            {
                                // Connect to selected host
                                LVITEMW item = {0};
                                item.mask = LVIF_PARAM;
                                item.iItem = selected;
                                ListView_GetItem(hList, &item);
                                int hostIndex = (int)item.lParam;
                                
                                if (hostIndex >= 0 && hostIndex < hostCount)
                                {
                                    // Feature 2: Visual feedback on connection
                                    if (LaunchRDPWithVisualFeedback(hwnd, hosts[hostIndex].hostname))
                                    {
                                        EndDialog(hwnd, IDOK);
                                    }
                                }
                            }
                            else if (cmd == IDM_CONTEXT_DELETE)
                            {
                                // Delete selected host
                                LVITEMW item = {0};
                                item.mask = LVIF_PARAM;
                                item.iItem = selected;
                                ListView_GetItem(hList, &item);
                                int hostIndex = (int)item.lParam;
                                
                                if (hostIndex >= 0 && hostIndex < hostCount)
                                {
                                    wchar_t msg[512];
                                    swprintf_s(msg, 512, L"Delete host '%s'?", hosts[hostIndex].hostname);
                                    
                                    if (MessageBoxW(hwnd, msg, L"Confirm Delete", 
                                                   MB_YESNO | MB_ICONQUESTION) == IDYES)
                                    {
                                        if (DeleteHost(hosts[hostIndex].hostname))
                                        {
                                            // Reload the list
                                            FreeHosts(hosts, hostCount);
                                            hosts = NULL;
                                            hostCount = 0;
                                            
                                            if (LoadHosts(&hosts, &hostCount))
                                            {
                                                // Get search text if any
                                                HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
                                                wchar_t searchText[256] = {0};
                                                GetWindowTextW(hSearch, searchText, 256);
                                                
                                                int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                                UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    return TRUE;
                }
                else if (pnmhdr->code == NM_CUSTOMDRAW)
                {
                    // Feature 3: Custom draw for search result highlighting
                    LPNMLVCUSTOMDRAW lpcd = (LPNMLVCUSTOMDRAW)lParam;
                    
                    if (!searchContext.hasSearchText)
                    {
                        // No search text - use default drawing
                        return CDRF_DODEFAULT;
                    }
                    
                    switch (lpcd->nmcd.dwDrawStage)
                    {
                        case CDDS_PREPAINT:
                            // Request item-level notifications
                            return CDRF_NOTIFYITEMDRAW;
                            
                        case CDDS_ITEMPREPAINT:
                            // Request subitem-level notifications
                            return CDRF_NOTIFYSUBITEMDRAW;
                            
                        case CDDS_SUBITEM | CDDS_ITEMPREPAINT:
                        {
                            // Get the subitem being drawn
                            int iSubItem = lpcd->iSubItem;
                            int iItem = (int)lpcd->nmcd.dwItemSpec;
                            
                            // Only highlight columns 1 (hostname) and 2 (description)
                            if (iSubItem == 1 || iSubItem == 2)
                            {
                                // Get the text for this subitem
                                wchar_t text[512] = {0};
                                ListView_GetItemText(lpcd->nmcd.hdr.hwndFrom, iItem, iSubItem, text, 512);
                                
                                // Convert both to lowercase for case-insensitive comparison
                                wchar_t textLower[512] = {0};
                                wchar_t searchLower[256] = {0};
                                wcsncpy_s(textLower, 512, text, _TRUNCATE);
                                wcsncpy_s(searchLower, 256, searchContext.searchText, _TRUNCATE);
                                _wcslwr_s(textLower, 512);
                                _wcslwr_s(searchLower, 256);
                                
                                // Check if this text contains the search term
                                if (wcsstr(textLower, searchLower) != NULL)
                                {
                                    // Highlight with yellow background
                                    lpcd->clrTextBk = RGB(255, 255, 150);  // Light yellow
                                    return CDRF_NEWFONT;
                                }
                            }
                            return CDRF_DODEFAULT;
                        }
                    }
                    return CDRF_DODEFAULT;
                }
            }
            break;
        }

        case WM_SIZE:
        {
            // Feature 4: Auto-resize description column when window resizes
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
            if (hList)
            {
                ResizeDescriptionColumn(hList);
            }
            return FALSE;  // Let default processing continue
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_BTN_CONNECT:
                {
                    // Connect to selected server
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0)
                    {
                        // Get the original host index from lParam
                        LVITEMW item = {0};
                        item.mask = LVIF_PARAM;
                        item.iItem = selected;
                        ListView_GetItem(hList, &item);
                        int hostIndex = (int)item.lParam;
                        
                        if (hostIndex >= 0 && hostIndex < hostCount)
                        {
                            // Feature 2: Visual feedback on connection
                            if (LaunchRDPWithVisualFeedback(hwnd, hosts[hostIndex].hostname))
                            {
                                EndDialog(hwnd, IDOK);
                            }
                        }
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Please select a server first.");
                    }
                    return TRUE;
                }

                case IDC_EDIT_SEARCH:
                {
                    // Handle search text changes
                    if (HIWORD(wParam) == EN_CHANGE)
                    {
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
                        
                        // Get search text
                        GetWindowTextW(hSearch, searchContext.searchText, 256);
                        searchContext.hasSearchText = (wcslen(searchContext.searchText) > 0);
                        
                        // Refresh list with filter
                        int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchContext.searchText);
                        UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
                        
                        // Feature 3: Redraw list to show highlighting
                        InvalidateRect(hList, NULL, FALSE);
                    }
                    return TRUE;
                }

                case IDC_BTN_MANAGE:
                {
                    // Show host management dialog (only if not already open)
                    if (g_hwndHostDialog == NULL)
                    {
                        DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_HOSTS),
                                 hwnd, HostDialogProc);
                    }
                    else
                    {
                        // Bring existing dialog to front
                        SetForegroundWindow(g_hwndHostDialog);
                    }
                    
                    // Reload the list after managing hosts
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    
                    if (hosts != NULL)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                        hostCount = 0;
                    }
                    
                    if (LoadHosts(&hosts, &hostCount))
                    {
                        // Get search text if any
                        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
                        wchar_t searchText[256] = {0};
                        GetWindowTextW(hSearch, searchText, 256);
                        
                        int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                        UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
                    }
                    return TRUE;
                }

                case IDC_BTN_EDIT_CREDS:
                {
                    // Hide main window before showing login dialog
                    ShowWindow(hwnd, SW_HIDE);
                    
                    // Show login dialog to edit global credentials
                    // Pass 1 as lParam to indicate edit mode (no auto-close countdown)
                    if (g_hwndLoginDialog == NULL)
                    {
                        DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), 
                                      hwnd, LoginDialogProc, 1);
                    }
                    else
                    {
                        // Bring existing dialog to front
                        SetForegroundWindow(g_hwndLoginDialog);
                    }
                    
                    // Restore main window after login dialog closes
                    ShowWindow(hwnd, SW_SHOW);
                    SetForegroundWindow(hwnd);
                    
                    return TRUE;
                }

                case IDCANCEL:
                    if (hosts != NULL)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                    }
                    g_hwndMainDialog = NULL;
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            if (hosts != NULL)
            {
                FreeHosts(hosts, hostCount);
                hosts = NULL;
            }
            g_hwndMainDialog = NULL;
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
            
        case WM_DESTROY:
            g_hwndMainDialog = NULL;
            return TRUE;
    }

    // Handle dark mode color messages
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;

    UNREFERENCED_PARAMETER(lParam);
    return FALSE;
}

/*
 * HostDialogProc - Host management dialog
 * 
 * This dialog provides full CRUD operations for managing RDP server entries.
 * It also registers a secret hotkey (Ctrl+Shift+Alt+D) for bulk deletion of
 * all hosts and credentials.
 */
INT_PTR CALLBACK HostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    static SortParams sortParams = {1, TRUE, NULL, 0};  // Default: sort by hostname, ascending
    static SearchContext searchContext = {{0}, FALSE};  // Feature 3: Track search text for highlighting
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Track this dialog instance
            g_hwndHostDialog = hwnd;
            
            // Register global hotkey for Ctrl+Shift+Alt+D (bulk delete)
            // This hotkey is intentionally hard to press to prevent accidental use
            RegisterHotKey(hwnd, IDM_DELETE_ALL, MOD_CONTROL | MOD_SHIFT | MOD_ALT, 0x44);
            
            CenterWindow(hwnd);
            
            // Apply dark mode if enabled
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
            
            // Set extended ListView styles
            ListView_SetExtendedListViewStyle(hList,
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Apply dark mode to ListView
            ApplyDarkModeToListView(hList);
            
            // Get ListView client area to calculate proper column widths
            RECT rcList;
            GetClientRect(hList, &rcList);
            int listWidth = rcList.right - rcList.left;
            
            // Create columns that fill the ListView width exactly
            // Note: Column 0 cannot be centered, so we add a tiny dummy column and use 1 & 2
            LVCOLUMNW col = {0};
            
            // Add invisible dummy column at position 0
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            col.pszText = L"";
            col.cx = 1;  // Almost invisible
            ListView_InsertColumn(hList, 0, &col);
            
            // Now add the real columns which CAN be centered
            col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
            col.fmt = LVCFMT_CENTER;
            
            col.pszText = L"Hostname";
            col.cx = 170;
            ListView_InsertColumn(hList, 1, &col);
            
            col.pszText = L"Description";
            col.cx = listWidth - 170 - 160 - 5;  // Takes most of the remaining space
            ListView_InsertColumn(hList, 2, &col);
            
            col.pszText = L"Last Connected";
            col.cx = 160;  // Fixed width for timestamp
            ListView_InsertColumn(hList, 3, &col);
            
            // Load and display hosts
            if (LoadHosts(&hosts, &hostCount))
            {
                int displayedCount = RefreshHostListView(hList, hosts, hostCount, NULL);
                UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
            }
            
            return TRUE;
        }

        case WM_HOTKEY:
        {
            // Handle the registered secret hotkey Ctrl+Shift+Alt+D for bulk deletion
            // This hotkey was registered in WM_INITDIALOG to delete all hosts and credentials
            if (wParam == IDM_DELETE_ALL)
            {
                // Show warning confirmation dialog
                int result = MessageBoxW(hwnd,
                    L"WARNING: This will permanently delete:\n\n"
                    L"• ALL RDP hosts from your list\n"
                    L"• ALL saved credentials (global and per-host)\n\n"
                    L"This action cannot be undone!\n\n"
                    L"Are you absolutely sure?",
                    L"Delete All Data - WinRDP",
                    MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
                
                if (result == IDYES)
                {
                    // Second confirmation
                    int result2 = MessageBoxW(hwnd,
                        L"FINAL WARNING:\n\n"
                        L"You are about to delete ALL hosts and credentials.\n\n"
                        L"This is your last chance to cancel.\n\n"
                        L"Continue?",
                        L"Delete All Data - WinRDP",
                        MB_YESNO | MB_ICONSTOP | MB_DEFBUTTON2);
                    
                    if (result2 == IDYES)
                    {
                        // Perform the deletion
                        BOOL hostsDeleted = DeleteAllHosts();
                        BOOL credsDeleted = DeleteAllWinRDPCredentials();
                        
                        if (hostsDeleted && credsDeleted)
                        {
                            MessageBoxW(hwnd,
                                L"All hosts and credentials have been deleted.",
                                L"Delete Complete - WinRDP",
                                MB_OK | MB_ICONINFORMATION);
                            
                            // Reload the list (should be empty now)
                            HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                            
                            if (hosts != NULL)
                            {
                                FreeHosts(hosts, hostCount);
                                hosts = NULL;
                                hostCount = 0;
                            }
                            
                            if (LoadHosts(&hosts, &hostCount))
                            {
                                int displayedCount = RefreshHostListView(hList, hosts, hostCount, NULL);
                                UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                            }
                        }
                        else
                        {
                            MessageBoxW(hwnd,
                                L"Some data may not have been deleted successfully.\n\n"
                                L"Please check and try again if needed.",
                                L"Delete Warning - WinRDP",
                                MB_OK | MB_ICONWARNING);
                        }
                    }
                }
                
                return TRUE;
            }
            break;
        }

        case WM_NOTIFY:
        {
            LPNMHDR pnmhdr = (LPNMHDR)lParam;
            
            if (pnmhdr->idFrom == IDC_LIST_HOSTS)
            {
                if (pnmhdr->code == LVN_COLUMNCLICK)
                {
                    // Column header clicked - sort by that column
                    LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)lParam;
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                    
                    // Note: Column 0 is dummy, so actual columns are 1, 2, 3
                    int clickedColumn = pnmlv->iSubItem;
                    
                    // Only sort if clicking on actual columns (not dummy column 0)
                    if (clickedColumn == 1 || clickedColumn == 2 || clickedColumn == 3)
                    {
                        // If clicking the same column, toggle sort direction
                        if (sortParams.sortColumn == clickedColumn)
                        {
                            sortParams.sortAscending = !sortParams.sortAscending;
                        }
                        else
                        {
                            // New column - default to ascending
                            sortParams.sortColumn = clickedColumn;
                            sortParams.sortAscending = TRUE;
                        }
                        
                        // Update sort params with current host data
                        sortParams.hosts = hosts;
                        sortParams.hostCount = hostCount;
                        
                        // Perform the sort
                        ListView_SortItems(hList, CompareListViewItems, (LPARAM)&sortParams);
                    }
                    return TRUE;
                }
                else if (pnmhdr->code == LVN_KEYDOWN)
                {
                    // Handle keyboard shortcuts on listview
                    LPNMLVKEYDOWN pnkd = (LPNMLVKEYDOWN)lParam;
                    
                    if (pnkd->wVKey == VK_RETURN)
                    {
                        // Enter key - trigger edit host button
                        PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_BTN_EDIT_HOST, BN_CLICKED), 0);
                        return TRUE;
                    }
                    else if (pnkd->wVKey == VK_DELETE)
                    {
                        // Delete key - delete selected host
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                        int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                        
                        if (selected >= 0)
                        {
                            // Get the original host index from lParam
                            LVITEMW item = {0};
                            item.mask = LVIF_PARAM;
                            item.iItem = selected;
                            ListView_GetItem(hList, &item);
                            int hostIndex = (int)item.lParam;
                            
                            if (hostIndex >= 0 && hostIndex < hostCount)
                            {
                                wchar_t msg[512];
                                swprintf_s(msg, 512, L"Delete host '%s'?", hosts[hostIndex].hostname);
                                
                                if (MessageBoxW(hwnd, msg, L"Confirm Delete", 
                                               MB_YESNO | MB_ICONQUESTION) == IDYES)
                                {
                                    if (DeleteHost(hosts[hostIndex].hostname))
                                    {
                                        // Reload the list
                                        FreeHosts(hosts, hostCount);
                                        hosts = NULL;
                                        hostCount = 0;
                                        
                                        if (LoadHosts(&hosts, &hostCount))
                                        {
                                            // Get search text if any
                                            HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                                            wchar_t searchText[256] = {0};
                                            GetWindowTextW(hSearch, searchText, 256);
                                            
                                            int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                            UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                                        }
                                    }
                                    else
                                    {
                                        ShowErrorMessage(hwnd, L"Failed to delete host.");
                                    }
                                }
                            }
                        }
                        return TRUE;
                    }
                }
                else if (pnmhdr->code == NM_RCLICK)
                {
                    // Right-click on ListView - show context menu
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0)
                    {
                        // Get cursor position for menu
                        POINT pt;
                        GetCursorPos(&pt);
                        
                        // Create popup menu
                        HMENU hMenu = CreatePopupMenu();
                        if (hMenu)
                        {
                            AppendMenuW(hMenu, MF_STRING, IDM_CONTEXT_EDIT, L"Edit");
                            AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
                            AppendMenuW(hMenu, MF_STRING, IDM_CONTEXT_DELETE, L"Delete");
                            
                            // Required to make menu disappear when clicking outside
                            SetForegroundWindow(hwnd);
                            
                            // Show menu and get selection
                            int cmd = TrackPopupMenu(hMenu, TPM_RETURNCMD | TPM_LEFTALIGN,
                                                    pt.x, pt.y, 0, hwnd, NULL);
                            
                            DestroyMenu(hMenu);
                            
                            // Handle menu selection
                            if (cmd == IDM_CONTEXT_EDIT)
                            {
                                // Edit selected host
                                PostMessage(hwnd, WM_COMMAND, MAKEWPARAM(IDC_BTN_EDIT_HOST, BN_CLICKED), 0);
                            }
                            else if (cmd == IDM_CONTEXT_DELETE)
                            {
                                // Delete selected host
                                LVITEMW item = {0};
                                item.mask = LVIF_PARAM;
                                item.iItem = selected;
                                ListView_GetItem(hList, &item);
                                int hostIndex = (int)item.lParam;
                                
                                if (hostIndex >= 0 && hostIndex < hostCount)
                                {
                                    wchar_t msg[512];
                                    swprintf_s(msg, 512, L"Delete host '%s'?", hosts[hostIndex].hostname);
                                    
                                    if (MessageBoxW(hwnd, msg, L"Confirm Delete", 
                                                   MB_YESNO | MB_ICONQUESTION) == IDYES)
                                    {
                                        if (DeleteHost(hosts[hostIndex].hostname))
                                        {
                                            // Reload the list
                                            FreeHosts(hosts, hostCount);
                                            hosts = NULL;
                                            hostCount = 0;
                                            
                                            if (LoadHosts(&hosts, &hostCount))
                                            {
                                                // Get search text if any
                                                HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                                                wchar_t searchText[256] = {0};
                                                GetWindowTextW(hSearch, searchText, 256);
                                                
                                                int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                                UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    return TRUE;
                }
                else if (pnmhdr->code == NM_CUSTOMDRAW)
                {
                    // Feature 3: Custom draw for search result highlighting
                    LPNMLVCUSTOMDRAW lpcd = (LPNMLVCUSTOMDRAW)lParam;
                    
                    if (!searchContext.hasSearchText)
                    {
                        // No search text - use default drawing
                        return CDRF_DODEFAULT;
                    }
                    
                    switch (lpcd->nmcd.dwDrawStage)
                    {
                        case CDDS_PREPAINT:
                            // Request item-level notifications
                            return CDRF_NOTIFYITEMDRAW;
                            
                        case CDDS_ITEMPREPAINT:
                            // Request subitem-level notifications
                            return CDRF_NOTIFYSUBITEMDRAW;
                            
                        case CDDS_SUBITEM | CDDS_ITEMPREPAINT:
                        {
                            // Get the subitem being drawn
                            int iSubItem = lpcd->iSubItem;
                            int iItem = (int)lpcd->nmcd.dwItemSpec;
                            
                            // Only highlight columns 1 (hostname) and 2 (description)
                            if (iSubItem == 1 || iSubItem == 2)
                            {
                                // Get the text for this subitem
                                wchar_t text[512] = {0};
                                ListView_GetItemText(lpcd->nmcd.hdr.hwndFrom, iItem, iSubItem, text, 512);
                                
                                // Convert both to lowercase for case-insensitive comparison
                                wchar_t textLower[512] = {0};
                                wchar_t searchLower[256] = {0};
                                wcsncpy_s(textLower, 512, text, _TRUNCATE);
                                wcsncpy_s(searchLower, 256, searchContext.searchText, _TRUNCATE);
                                _wcslwr_s(textLower, 512);
                                _wcslwr_s(searchLower, 256);
                                
                                // Check if this text contains the search term
                                if (wcsstr(textLower, searchLower) != NULL)
                                {
                                    // Highlight with yellow background
                                    lpcd->clrTextBk = RGB(255, 255, 150);  // Light yellow
                                    return CDRF_NEWFONT;
                                }
                            }
                            return CDRF_DODEFAULT;
                        }
                    }
                    return CDRF_DODEFAULT;
                }
            }
            break;
        }

        case WM_SIZE:
        {
            // Feature 4: Auto-resize description column when window resizes
            HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
            if (hList)
            {
                ResizeDescriptionColumn(hList);
            }
            return FALSE;  // Let default processing continue
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_EDIT_SEARCH_HOSTS:
                {
                    // Handle search text changes
                    if (HIWORD(wParam) == EN_CHANGE)
                    {
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                        
                        // Get search text
                        GetWindowTextW(hSearch, searchContext.searchText, 256);
                        searchContext.hasSearchText = (wcslen(searchContext.searchText) > 0);
                        
                        // Refresh list with filter
                        int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchContext.searchText);
                        UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                        
                        // Feature 3: Redraw list to show highlighting
                        InvalidateRect(hList, NULL, FALSE);
                    }
                    return TRUE;
                }

                case IDC_BTN_ADD_HOST:
                {
                    // Show add host dialog (only if not already open)
                    if (g_hwndAddHostDialog != NULL)
                    {
                        // Bring existing dialog to front
                        SetForegroundWindow(g_hwndAddHostDialog);
                        return TRUE;
                    }
                    
                    if (DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ADD_HOST),
                                 hwnd, AddHostDialogProc) == IDOK)
                    {
                        // Reload the list
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                        
                        if (hosts != NULL)
                        {
                            FreeHosts(hosts, hostCount);
                            hosts = NULL;
                            hostCount = 0;
                        }
                        
                        if (LoadHosts(&hosts, &hostCount))
                        {
                            // Get search text if any
                            HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                            wchar_t searchText[256] = {0};
                            GetWindowTextW(hSearch, searchText, 256);
                            
                            int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                            UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                        }
                    }
                    return TRUE;
                }

                case IDC_BTN_EDIT_HOST:
                {
                    // Edit selected host
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0 && selected < hostCount)
                    {
                        // Pre-fill the Add/Edit dialog with existing data
                        if (g_hwndAddHostDialog != NULL)
                        {
                            SetForegroundWindow(g_hwndAddHostDialog);
                            return TRUE;
                        }
                        
                        // Prepare edit data to pass to dialog
                        EditHostData editData = {0};
                        wcsncpy_s(editData.originalHostname, MAX_HOSTNAME_LEN, hosts[selected].hostname, _TRUNCATE);
                        wcsncpy_s(editData.hostname, MAX_HOSTNAME_LEN, hosts[selected].hostname, _TRUNCATE);
                        wcsncpy_s(editData.description, MAX_DESCRIPTION_LEN, hosts[selected].description, _TRUNCATE);
                        editData.isEdit = TRUE;
                        
                        // Show edit dialog with pre-filled data
                        if (DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_ADD_HOST),
                                          hwnd, AddHostDialogProc, (LPARAM)&editData) == IDOK)
                        {
                            // Reload the list
                            FreeHosts(hosts, hostCount);
                            hosts = NULL;
                            hostCount = 0;
                            
                            if (LoadHosts(&hosts, &hostCount))
                            {
                                // Get search text if any
                                HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                                wchar_t searchText[256] = {0};
                                GetWindowTextW(hSearch, searchText, 256);
                                
                                int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                            }
                        }
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Please select a host to edit.");
                    }
                    return TRUE;
                }

                case IDC_BTN_DELETE_HOST:
                {
                    // Delete selected host
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0 && selected < hostCount)
                    {
                        wchar_t msg[512];
                        swprintf_s(msg, 512, L"Delete host '%s'?", hosts[selected].hostname);
                        
                        if (MessageBoxW(hwnd, msg, L"Confirm Delete", 
                                       MB_YESNO | MB_ICONQUESTION) == IDYES)
                        {
                            if (DeleteHost(hosts[selected].hostname))
                            {
                                // Reload the list
                                FreeHosts(hosts, hostCount);
                                hosts = NULL;
                                hostCount = 0;
                                
                                if (LoadHosts(&hosts, &hostCount))
                                {
                                    // Get search text if any
                                    HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH_HOSTS);
                                    wchar_t searchText[256] = {0};
                                    GetWindowTextW(hSearch, searchText, 256);
                                    
                                    int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
                                    UpdateHostCountLabel(hwnd, IDC_STATIC_HOSTS_COUNT, displayedCount, hostCount);
                                }
                            }
                        }
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Please select a host first.");
                    }
                    return TRUE;
                }

                case IDC_BTN_SCAN_DOMAIN:
                {
                    // Show domain selection dialog
                    ScanParams params = {0};
                    INT_PTR result = DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_SCAN_DOMAIN),
                                                   hwnd, ScanDomainDialogProc, (LPARAM)&params);
                    
                    if (result == IDOK)
                    {
                        // Scan Active Directory/network for computers
                        ComputerInfo* computers = NULL;
                        int computerCount = 0;
                        
                        // Show scanning message
                        SetCursor(LoadCursor(NULL, IDC_WAIT));
                        
                        // Prepare domain parameter
                        const wchar_t* domain = wcslen(params.domain) > 0 ? params.domain : NULL;
                        
                        if (ScanForComputers(domain, 
                                           params.includeWorkstations, params.includeServers, params.includeDomainControllers,
                                           &computers, &computerCount))
                        {
                            SetCursor(LoadCursor(NULL, IDC_ARROW));
                            
                            if (computerCount == 0)
                            {
                                ShowInfoMessage(hwnd, 
                                    L"No computers found on the network.\n\n"
                                    L"This could mean:\n"
                                    L"• You're not connected to a network\n"
                                    L"• Network discovery is disabled\n"
                                    L"• Firewall is blocking discovery\n"
                                    L"• The specified domain/workgroup doesn't exist\n\n"
                                    L"You can still manually add hosts using 'Add Host'.");
                            }
                            else
                            {
                                // Auto-add all discovered computers
                                int addedCount = 0;
                                for (int i = 0; i < computerCount; i++)
                                {
                                    if (AddHost(computers[i].name, computers[i].comment))
                                    {
                                        addedCount++;
                                    }
                                }
                                
                                // Free the computer list
                                FreeComputerList(computers);
                                
                                // Show success message
                                wchar_t msg[512];
                                swprintf_s(msg, 512, 
                                    L"Network scan complete!\n\n"
                                    L"Found: %d computer(s)\n"
                                    L"Added: %d computer(s) to your hosts list\n\n"
                                    L"Computers have been automatically added with their AD descriptions.",
                                    computerCount, addedCount);
                                ShowInfoMessage(hwnd, msg);
                            }
                        }
                        else
                        {
                            SetCursor(LoadCursor(NULL, IDC_ARROW));
                            ShowErrorMessage(hwnd, L"Failed to scan for computers.\n\nPlease check network connectivity and permissions.");
                        }
                    }
                    
                    return TRUE;
                }

                case IDCANCEL:
                    if (hosts != NULL)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                    }
                    g_hwndHostDialog = NULL;
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            // Unregister hotkey when closing
            UnregisterHotKey(hwnd, IDM_DELETE_ALL);
            if (hosts != NULL)
            {
                FreeHosts(hosts, hostCount);
                hosts = NULL;
            }
            g_hwndHostDialog = NULL;
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
            
        case WM_DESTROY:
            // Unregister hotkey when destroying
            UnregisterHotKey(hwnd, IDM_DELETE_ALL);
            g_hwndHostDialog = NULL;
            return TRUE;
    }

    // Handle dark mode color messages
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;

    UNREFERENCED_PARAMETER(lParam);
    return FALSE;
}

/*
 * AddHostDialogProc - Add/Edit host dialog procedure
 * 
 * This dialog allows users to add new hosts or edit existing ones.
 * It supports both global credentials (default) and per-host credentials (optional).
 * 
 * Per-Host Credentials Feature:
 * - Users can optionally set individual credentials for specific hosts
 * - When the "Use custom credentials for this host" checkbox is checked,
 *   username and password fields appear
 * - Per-host credentials take precedence over global credentials when connecting
 * - If checkbox is unchecked, the host will use global credentials
 * 
 * Dialog Behavior:
 * - When adding a new host: Checkbox is unchecked, credential fields hidden
 * - When editing a host: If per-host credentials exist, checkbox is checked and fields shown
 * - Credential fields are dynamically shown/hidden based on checkbox state
 * - Per-host credentials are saved/deleted based on checkbox state when saving
 */
INT_PTR CALLBACK AddHostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static EditHostData* s_editData = NULL;  // Store pointer for later use
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Track this dialog instance
            g_hwndAddHostDialog = hwnd;
            
            CenterWindow(hwnd);
            
            // Apply dark mode if enabled
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Store edit data pointer for use in WM_COMMAND
            s_editData = (EditHostData*)lParam;
            
            // Initially hide credential fields and labels (shown when checkbox is checked)
            // These fields are only visible when user enables per-host credentials
            ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_USERNAME), SW_HIDE);
            ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_PASSWORD), SW_HIDE);
            ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_USERNAME), SW_HIDE);
            ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_PASSWORD), SW_HIDE);
            
            // Check if we're editing an existing host
            if (s_editData != NULL && s_editData->isEdit)
            {
                // Pre-fill the fields with existing host data
                SetDlgItemTextW(hwnd, IDC_EDIT_HOSTNAME, s_editData->hostname);
                SetDlgItemTextW(hwnd, IDC_EDIT_DESCRIPTION, s_editData->description);
                
                // Try to load per-host credentials for this host
                // If they exist, enable the checkbox and show the fields
                wchar_t username[MAX_USERNAME_LEN];
                wchar_t password[MAX_PASSWORD_LEN];
                if (LoadRDPCredentials(s_editData->hostname, username, password))
                {
                    // Per-host credentials exist - enable checkbox and populate fields
                    CheckDlgButton(hwnd, IDC_CHECK_USE_HOST_CREDS, BST_CHECKED);
                    SetDlgItemTextW(hwnd, IDC_EDIT_HOST_USERNAME, username);
                    SetDlgItemTextW(hwnd, IDC_EDIT_HOST_PASSWORD, password);
                    // Show the credential fields now that checkbox is checked
                    ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_USERNAME), SW_SHOW);
                    ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_PASSWORD), SW_SHOW);
                    ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_USERNAME), SW_SHOW);
                    ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_PASSWORD), SW_SHOW);
                }
                // If no per-host credentials exist, checkbox remains unchecked
                // and the host will use global credentials
                
                // Change dialog title to "Edit Host"
                SetWindowTextW(hwnd, L"WinRDP - Edit Host");
            }
            
            return TRUE;
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_CHECK_USE_HOST_CREDS:
                {
                    // Handle checkbox state change for per-host credentials
                    // When checked: Show credential fields
                    // When unchecked: Hide credential fields and clear them
                    BOOL checked = (IsDlgButtonChecked(hwnd, IDC_CHECK_USE_HOST_CREDS) == BST_CHECKED);
                    
                    // Toggle visibility of credential fields and labels based on checkbox state
                    ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_USERNAME), checked ? SW_SHOW : SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, IDC_STATIC_HOST_PASSWORD), checked ? SW_SHOW : SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_USERNAME), checked ? SW_SHOW : SW_HIDE);
                    ShowWindow(GetDlgItem(hwnd, IDC_EDIT_HOST_PASSWORD), checked ? SW_SHOW : SW_HIDE);
                    
                    // If unchecked, clear the fields to ensure clean state
                    // This prevents accidental use of old credential values
                    if (!checked)
                    {
                        SetDlgItemTextW(hwnd, IDC_EDIT_HOST_USERNAME, L"");
                        SetDlgItemTextW(hwnd, IDC_EDIT_HOST_PASSWORD, L"");
                    }
                    return TRUE;
                }
                
                case IDOK:
                {
                    // User clicked Save - validate and save host data
                    wchar_t hostname[MAX_HOSTNAME_LEN];
                    wchar_t description[MAX_DESCRIPTION_LEN];
                    
                    GetDlgItemTextW(hwnd, IDC_EDIT_HOSTNAME, hostname, MAX_HOSTNAME_LEN);
                    GetDlgItemTextW(hwnd, IDC_EDIT_DESCRIPTION, description, MAX_DESCRIPTION_LEN);
                    
                    // Validate hostname (required field)
                    if (wcslen(hostname) == 0)
                    {
                        ShowErrorMessage(hwnd, L"Please enter a hostname.");
                        return TRUE;
                    }
                    
                    // Check if user enabled per-host credentials
                    BOOL useHostCreds = (IsDlgButtonChecked(hwnd, IDC_CHECK_USE_HOST_CREDS) == BST_CHECKED);
                    
                    // If per-host credentials are enabled, validate them
                    if (useHostCreds)
                    {
                        // Get per-host credentials from dialog fields
                        wchar_t username[MAX_USERNAME_LEN];
                        wchar_t password[MAX_PASSWORD_LEN];
                        
                        GetDlgItemTextW(hwnd, IDC_EDIT_HOST_USERNAME, username, MAX_USERNAME_LEN);
                        GetDlgItemTextW(hwnd, IDC_EDIT_HOST_PASSWORD, password, MAX_PASSWORD_LEN);
                        
                        // Validate that both username and password are provided
                        // If checkbox is checked, both fields must be filled
                        if (wcslen(username) == 0 || wcslen(password) == 0)
                        {
                            ShowErrorMessage(hwnd, L"Please enter both username and password for per-host credentials, or uncheck the option to use global credentials.");
                            return TRUE;
                        }
                    }
                    
                    // If editing an existing host, delete the original host first
                    // This handles both rename (hostname change) and update (description change) scenarios
                    wchar_t oldHostname[MAX_HOSTNAME_LEN] = {0};
                    if (s_editData != NULL && s_editData->isEdit)
                    {
                        wcsncpy_s(oldHostname, MAX_HOSTNAME_LEN, s_editData->originalHostname, _TRUNCATE);
                        DeleteHost(s_editData->originalHostname);
                        
                        // If hostname changed, clean up old per-host credentials
                        // This prevents orphaned credentials from old hostname
                        if (_wcsicmp(oldHostname, hostname) != 0)
                        {
                            DeleteRDPCredentials(oldHostname);
                        }
                    }
                    
                    // Add the host (new or updated) to the CSV file
                    if (AddHost(hostname, description))
                    {
                        // Handle per-host credentials based on checkbox state
                        if (useHostCreds)
                        {
                            // User enabled per-host credentials - save them
                            // These will be used instead of global credentials when connecting
                            wchar_t username[MAX_USERNAME_LEN];
                            wchar_t password[MAX_PASSWORD_LEN];
                            
                            GetDlgItemTextW(hwnd, IDC_EDIT_HOST_USERNAME, username, MAX_USERNAME_LEN);
                            GetDlgItemTextW(hwnd, IDC_EDIT_HOST_PASSWORD, password, MAX_PASSWORD_LEN);
                            
                            // Save per-host credentials to Windows Credential Manager
                            // Stored as: WinRDP:TERMSRV/hostname
                            SaveRDPCredentials(hostname, username, password);
                        }
                        else
                        {
                            // User unchecked per-host credentials - delete them if they exist
                            // This ensures the host will use global credentials
                            DeleteRDPCredentials(hostname);
                        }
                        
                        // Clear dialog state and close
                        g_hwndAddHostDialog = NULL;
                        s_editData = NULL;  // Clear edit data
                        EndDialog(hwnd, IDOK);
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Failed to save host.");
                    }
                    return TRUE;
                }

                case IDCANCEL:
                    g_hwndAddHostDialog = NULL;
                    s_editData = NULL;  // Clear edit data
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            g_hwndAddHostDialog = NULL;
            s_editData = NULL;  // Clear edit data
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
            
        case WM_DESTROY:
            g_hwndAddHostDialog = NULL;
            s_editData = NULL;  // Clear edit data
            return TRUE;
    }

    // Handle dark mode color messages
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;

    return FALSE;
}

/*
 * ScanDomainDialogProc - Get domain and computer type filters for scanning
 * 
 * Prompts user for domain name and computer types to scan for.
 * The ScanParams structure is passed via lParam and filled on IDOK.
 */
INT_PTR CALLBACK ScanDomainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static ScanParams* s_params = NULL;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            CenterWindow(hwnd);
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Store pointer to params structure
            s_params = (ScanParams*)lParam;
            
            // Set default state - all computer types checked
            CheckDlgButton(hwnd, IDC_CHECK_WORKSTATIONS, BST_CHECKED);
            CheckDlgButton(hwnd, IDC_CHECK_SERVERS, BST_CHECKED);
            CheckDlgButton(hwnd, IDC_CHECK_DOMAIN_CTRL, BST_CHECKED);
            
            // Focus on domain field
            SetFocus(GetDlgItem(hwnd, IDC_EDIT_DOMAIN));
            
            return FALSE; // We set focus manually
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    if (s_params != NULL)
                    {
                        // Get computer type filters
                        s_params->includeWorkstations = (IsDlgButtonChecked(hwnd, IDC_CHECK_WORKSTATIONS) == BST_CHECKED);
                        s_params->includeServers = (IsDlgButtonChecked(hwnd, IDC_CHECK_SERVERS) == BST_CHECKED);
                        s_params->includeDomainControllers = (IsDlgButtonChecked(hwnd, IDC_CHECK_DOMAIN_CTRL) == BST_CHECKED);
                        
                        // Validate that at least one type is selected
                        if (!s_params->includeWorkstations && !s_params->includeServers && !s_params->includeDomainControllers)
                        {
                            ShowErrorMessage(hwnd, L"Please select at least one computer type to scan for.");
                            return TRUE;
                        }
                        
                        // Get domain name
                        GetDlgItemTextW(hwnd, IDC_EDIT_DOMAIN, s_params->domain, 256);
                    }
                    
                    EndDialog(hwnd, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;
        }
        
        // Handle dark mode messages
        default:
        {
            INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
            if (result != 0)
                return result;
            break;
        }
    }
    
    return FALSE;
}

/*
 * ScanResultsDialogProc - Display network scan results
 * 
 * Shows discovered computers and allows user to select which to add.
 * The computer list is passed via lParam in DialogBoxParam.
 */
INT_PTR CALLBACK ScanResultsDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static ComputerInfo* s_computers = NULL;
    static int s_computerCount = 0;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            CenterWindow(hwnd);
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            // Get computer list - need to extract both pointer and count
            // Since we can only pass one parameter, we'll pass the pointer
            // and the count needs to be embedded or passed differently
            s_computers = (ComputerInfo*)lParam;
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SCAN_RESULTS);
            
            // Set extended styles with checkboxes
            ListView_SetExtendedListViewStyle(hList,
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER | LVS_EX_CHECKBOXES);
            
            ApplyDarkModeToListView(hList);
            
            // Get ListView dimensions
            RECT rcList;
            GetClientRect(hList, &rcList);
            int listWidth = rcList.right - rcList.left;
            
            // Create columns with dummy column for centering
            LVCOLUMNW col = {0};
            
            // Dummy column
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            col.pszText = L"";
            col.cx = 1;
            ListView_InsertColumn(hList, 0, &col);
            
            // Real columns (centered)
            col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
            col.fmt = LVCFMT_CENTER;
            
            col.pszText = L"Computer Name";
            col.cx = 200;
            ListView_InsertColumn(hList, 1, &col);
            
            col.pszText = L"Description";
            col.cx = listWidth - 200 - 5;
            ListView_InsertColumn(hList, 2, &col);
            
            // Get count from global variable
            s_computerCount = g_scanComputerCount;
            
            for (int i = 0; i < s_computerCount && s_computers != NULL; i++)
            {
                LVITEMW item = {0};
                item.mask = LVIF_TEXT;
                item.iItem = i;
                item.iSubItem = 0;
                item.pszText = L"";  // Dummy column
                ListView_InsertItem(hList, &item);
                
                ListView_SetItemText(hList, i, 1, s_computers[i].name);
                ListView_SetItemText(hList, i, 2, s_computers[i].comment);
                
                // Check item by default
                ListView_SetCheckState(hList, i, TRUE);
            }
            
            // Update status
            wchar_t status[256];
            swprintf_s(status, 256, L"Found %d computer(s). Check the ones you want to add:", s_computerCount);
            SetDlgItemTextW(hwnd, IDC_STATIC_SCAN_STATUS, status);
            
            return TRUE;
        }
        
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_BTN_ADD_SELECTED:
                {
                    // Add selected (checked) computers to hosts
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SCAN_RESULTS);
                    int itemCount = ListView_GetItemCount(hList);
                    int addedCount = 0;
                    
                    for (int i = 0; i < itemCount; i++)
                    {
                        // Check if item is checked
                        if (ListView_GetCheckState(hList, i))
                        {
                            wchar_t hostname[256];
                            wchar_t description[256];
                            
                            ListView_GetItemText(hList, i, 1, hostname, 256);
                            ListView_GetItemText(hList, i, 2, description, 256);
                            
                            if (AddHost(hostname, description))
                            {
                                addedCount++;
                            }
                        }
                    }
                    
                    wchar_t msg[256];
                    swprintf_s(msg, 256, L"Added %d computer(s) to your hosts list.", addedCount);
                    ShowInfoMessage(hwnd, msg);
                    
                    // Free computers and close
                    if (s_computers != NULL)
                    {
                        FreeComputerList(s_computers);
                        s_computers = NULL;
                    }
                    
                    EndDialog(hwnd, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                    // Free computers and close
                    if (s_computers != NULL)
                    {
                        FreeComputerList(s_computers);
                        s_computers = NULL;
                    }
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;
        
        case WM_CLOSE:
            // Free computers and close
            if (s_computers != NULL)
            {
                FreeComputerList(s_computers);
                s_computers = NULL;
            }
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }
    
    // Handle dark mode
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;
    
    return FALSE;
}

/*
 * AboutDialogProc - Dialog procedure for the About dialog
 * 
 * Displays application information, version, and author credits.
 */
INT_PTR CALLBACK AboutDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    
    switch (msg)
    {
        case WM_INITDIALOG:
            // Center the dialog on the screen
            CenterWindow(hwnd);
            
            // Apply dark mode if enabled
            ApplyDarkModeToDialog(hwnd);
            
            // Set dialog icon
            HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
            SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
            SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            
            return TRUE;
        
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                case IDCANCEL:
                    EndDialog(hwnd, IDOK);
                    return TRUE;
            }
            break;
        
        case WM_CLOSE:
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }
    
    // Handle dark mode
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;
    
    return FALSE;
}

