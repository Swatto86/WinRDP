/*
 * WinRDP - Educational Windows RDP Manager in Pure C
 * 
 * This is a learning project demonstrating Windows API programming concepts:
 * - Window creation and message handling
 * - System tray icons
 * - Dialog boxes
 * - ListView controls
 * - Credential Manager API
 * - Registry operations
 * - Process launching
 * 
 * Author: Learning WinAPI
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

// Forward declarations of our functions
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK HostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK AddHostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL InitSystemTray(HWND hwnd);
BOOL ShowSystemTrayIcon(HWND hwnd);
BOOL HideSystemTrayIcon(HWND hwnd);
void ShowContextMenu(HWND hwnd);

// Global variables
HINSTANCE g_hInstance = NULL;
NOTIFYICONDATA g_nid = {0};
HWND g_hwndMain = NULL;

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

    // Store instance handle globally for later use
    g_hInstance = hInstance;

    // Initialize common controls (ListView, TreeView, etc.)
    // This must be called before using any common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_LISTVIEW_CLASSES | ICC_STANDARD_CLASSES;
    InitCommonControlsEx(&icex);

    // Register the main window class
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = APP_CLASS_NAME;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

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

    // Show the login dialog
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_LOGIN), g_hwndMain, LoginDialogProc);

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
            // Window is being created
            return 0;

        case WM_TRAYICON:
            // Custom message for system tray icon events
            switch (LOWORD(lParam))
            {
                case WM_LBUTTONUP:
                    // Left click - show main dialog
                    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                             hwnd, MainDialogProc);
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
                    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                             hwnd, MainDialogProc);
                    break;

                case IDM_ABOUT:
                    // Toggle autostart
                    ToggleAutostart();
                    break;

                case IDM_EXIT:
                    PostQuitMessage(0);
                    break;
            }
            return 0;

        case WM_DESTROY:
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
    g_nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
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
 */
void ShowContextMenu(HWND hwnd)
{
    POINT pt;
    GetCursorPos(&pt);

    // Create popup menu
    HMENU hMenu = CreatePopupMenu();
    if (hMenu)
    {
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
    UNREFERENCED_PARAMETER(lParam);

    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Dialog is being initialized
            CenterWindow(hwnd);
            
            // Try to load existing credentials
            wchar_t username[MAX_USERNAME_LEN];
            wchar_t password[MAX_PASSWORD_LEN];
            
            if (LoadCredentials(NULL, username, password))
            {
                // Credentials exist - populate the fields
                SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username);
                SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password);
                
                // Update the status text
                SetDlgItemTextW(hwnd, IDC_STATIC, L"Credentials are saved");
            }
            
            return TRUE;
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
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
                    // Delete saved credentials
                    if (DeleteCredentials(NULL))
                    {
                        SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, L"");
                        SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, L"");
                        ShowInfoMessage(hwnd, L"Credentials deleted.");
                    }
                    return TRUE;
                }

                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }

    return FALSE;
}

/*
 * MainDialogProc - Main server list dialog
 */
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            CenterWindow(hwnd);
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
            
            // Set extended ListView styles for better appearance
            ListView_SetExtendedListViewStyle(hList, 
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Create columns
            LVCOLUMNW col = {0};
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            
            col.pszText = L"Hostname";
            col.cx = 200;
            ListView_InsertColumn(hList, 0, &col);
            
            col.pszText = L"Description";
            col.cx = 300;
            ListView_InsertColumn(hList, 1, &col);
            
            // Load and display hosts
            if (LoadHosts(&hosts, &hostCount))
            {
                for (int i = 0; i < hostCount; i++)
                {
                    LVITEMW item = {0};
                    item.mask = LVIF_TEXT;
                    item.iItem = i;
                    item.iSubItem = 0;
                    item.pszText = hosts[i].hostname;
                    ListView_InsertItem(hList, &item);
                    
                    ListView_SetItemText(hList, i, 1, hosts[i].description);
                }
            }
            
            return TRUE;
        }

        case WM_NOTIFY:
        {
            LPNMHDR pnmhdr = (LPNMHDR)lParam;
            if (pnmhdr->idFrom == IDC_LIST_SERVERS && pnmhdr->code == NM_DBLCLK)
            {
                // Double-click on a server - connect to it
                HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                
                if (selected >= 0 && selected < hostCount)
                {
                    if (LaunchRDPWithDefaults(hosts[selected].hostname))
                    {
                        EndDialog(hwnd, IDOK);
                    }
                }
                return TRUE;
            }
            break;
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_BTN_CONNECT:
                {
                    // Connect to selected server
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                    
                    if (selected >= 0 && selected < hostCount)
                    {
                        if (LaunchRDPWithDefaults(hosts[selected].hostname))
                        {
                            EndDialog(hwnd, IDOK);
                        }
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Please select a server first.");
                    }
                    return TRUE;
                }

                case IDC_BTN_MANAGE:
                {
                    // Show host management dialog
                    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_HOSTS),
                             hwnd, HostDialogProc);
                    
                    // Reload the list after managing hosts
                    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                    ListView_DeleteAllItems(hList);
                    
                    if (hosts != NULL)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                        hostCount = 0;
                    }
                    
                    if (LoadHosts(&hosts, &hostCount))
                    {
                        for (int i = 0; i < hostCount; i++)
                        {
                            LVITEMW item = {0};
                            item.mask = LVIF_TEXT;
                            item.iItem = i;
                            item.iSubItem = 0;
                            item.pszText = hosts[i].hostname;
                            ListView_InsertItem(hList, &item);
                            
                            ListView_SetItemText(hList, i, 1, hosts[i].description);
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
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }

    UNREFERENCED_PARAMETER(lParam);
    return FALSE;
}

/*
 * HostDialogProc - Host management dialog
 */
INT_PTR CALLBACK HostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            CenterWindow(hwnd);
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
            
            // Set extended ListView styles
            ListView_SetExtendedListViewStyle(hList,
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Create columns
            LVCOLUMNW col = {0};
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            
            col.pszText = L"Hostname";
            col.cx = 250;
            ListView_InsertColumn(hList, 0, &col);
            
            col.pszText = L"Description";
            col.cx = 350;
            ListView_InsertColumn(hList, 1, &col);
            
            // Load and display hosts
            if (LoadHosts(&hosts, &hostCount))
            {
                for (int i = 0; i < hostCount; i++)
                {
                    LVITEMW item = {0};
                    item.mask = LVIF_TEXT;
                    item.iItem = i;
                    item.iSubItem = 0;
                    item.pszText = hosts[i].hostname;
                    ListView_InsertItem(hList, &item);
                    
                    ListView_SetItemText(hList, i, 1, hosts[i].description);
                }
            }
            
            return TRUE;
        }

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDC_BTN_ADD_HOST:
                {
                    // Show add host dialog
                    if (DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_ADD_HOST),
                                 hwnd, AddHostDialogProc) == IDOK)
                    {
                        // Reload the list
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_HOSTS);
                        ListView_DeleteAllItems(hList);
                        
                        if (hosts != NULL)
                        {
                            FreeHosts(hosts, hostCount);
                            hosts = NULL;
                            hostCount = 0;
                        }
                        
                        if (LoadHosts(&hosts, &hostCount))
                        {
                            for (int i = 0; i < hostCount; i++)
                            {
                                LVITEMW item = {0};
                                item.mask = LVIF_TEXT;
                                item.iItem = i;
                                item.iSubItem = 0;
                                item.pszText = hosts[i].hostname;
                                ListView_InsertItem(hList, &item);
                                
                                ListView_SetItemText(hList, i, 1, hosts[i].description);
                            }
                        }
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
                                ListView_DeleteAllItems(hList);
                                
                                FreeHosts(hosts, hostCount);
                                hosts = NULL;
                                hostCount = 0;
                                
                                if (LoadHosts(&hosts, &hostCount))
                                {
                                    for (int i = 0; i < hostCount; i++)
                                    {
                                        LVITEMW item = {0};
                                        item.mask = LVIF_TEXT;
                                        item.iItem = i;
                                        item.iSubItem = 0;
                                        item.pszText = hosts[i].hostname;
                                        ListView_InsertItem(hList, &item);
                                        
                                        ListView_SetItemText(hList, i, 1, hosts[i].description);
                                    }
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

                case IDCANCEL:
                    if (hosts != NULL)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                    }
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
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }

    UNREFERENCED_PARAMETER(lParam);
    return FALSE;
}

/*
 * AddHostDialogProc - Add/Edit host dialog procedure
 */
INT_PTR CALLBACK AddHostDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);

    switch (msg)
    {
        case WM_INITDIALOG:
            CenterWindow(hwnd);
            return TRUE;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    wchar_t hostname[MAX_HOSTNAME_LEN];
                    wchar_t description[MAX_DESCRIPTION_LEN];
                    
                    GetDlgItemTextW(hwnd, IDC_EDIT_HOSTNAME, hostname, MAX_HOSTNAME_LEN);
                    GetDlgItemTextW(hwnd, IDC_EDIT_DESCRIPTION, description, MAX_DESCRIPTION_LEN);
                    
                    if (wcslen(hostname) == 0)
                    {
                        ShowErrorMessage(hwnd, L"Please enter a hostname.");
                        return TRUE;
                    }
                    
                    if (AddHost(hostname, description))
                    {
                        EndDialog(hwnd, IDOK);
                    }
                    else
                    {
                        ShowErrorMessage(hwnd, L"Failed to add host.");
                    }
                    return TRUE;
                }

                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;

        case WM_CLOSE:
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }

    return FALSE;
}

