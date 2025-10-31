/*
 * Dark Mode Implementation
 * 
 * This module implements dark mode support by:
 * - Detecting Windows dark mode preference from registry
 * - Providing custom color handling for dialogs and controls
 * - Custom drawing for ListView controls
 */

#include <windows.h>
#include <commctrl.h>
#include <uxtheme.h>
#include <dwmapi.h>
#include "darkmode.h"

// Global brushes for dark mode
static HBRUSH g_hBrushDialogBg = NULL;
static HBRUSH g_hBrushControlBg = NULL;
static HBRUSH g_hBrushDark = NULL;
static BOOL g_bDarkModeEnabled = FALSE;

// Forward declarations for Windows 10+ dark mode APIs
typedef BOOL (WINAPI *fnShouldAppsUseDarkMode)();
typedef BOOL (WINAPI *fnAllowDarkModeForWindow)(HWND hwnd, BOOL allow);
typedef BOOL (WINAPI *fnSetPreferredAppMode)(INT mode);

static fnAllowDarkModeForWindow AllowDarkModeForWindow = NULL;

/*
 * IsDarkModeEnabled - Check if Windows is in dark mode
 * 
 * Reads the Windows registry to determine if dark mode is enabled.
 * This checks the PersonalizationSettings for the AppsUseLightTheme value.
 */
BOOL IsDarkModeEnabled(void)
{
    HKEY hKey;
    DWORD dwValue = 1; // Default to light mode
    DWORD dwSize = sizeof(DWORD);
    
    // Try to read the dark mode setting from registry
    // 0 = Dark Mode, 1 = Light Mode
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                      0,
                      KEY_READ,
                      &hKey) == ERROR_SUCCESS)
    {
        RegQueryValueExW(hKey, L"AppsUseLightTheme", NULL, NULL, (LPBYTE)&dwValue, &dwSize);
        RegCloseKey(hKey);
    }
    
    // Return TRUE if dark mode (value is 0)
    return (dwValue == 0);
}

/*
 * InitDarkMode - Initialize dark mode support
 * 
 * Creates brushes needed for dark mode and attempts to load
 * Windows 10+ dark mode APIs if available.
 */
void InitDarkMode(void)
{
    g_bDarkModeEnabled = IsDarkModeEnabled();
    
    if (!g_bDarkModeEnabled)
        return;
    
    // Create brushes for dark mode backgrounds
    g_hBrushDialogBg = CreateSolidBrush(DARK_DIALOG_BG);
    g_hBrushControlBg = CreateSolidBrush(DARK_CONTROL_BG);
    g_hBrushDark = CreateSolidBrush(DARK_BG_COLOR);
    
    // Try to load Windows 10 build 1809+ dark mode APIs
    HMODULE hUxtheme = LoadLibraryW(L"uxtheme.dll");
    if (hUxtheme)
    {
        // Ordinal 135 is AllowDarkModeForWindow on Windows 10 1809+
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wcast-function-type"
        AllowDarkModeForWindow = (fnAllowDarkModeForWindow)GetProcAddress(hUxtheme, MAKEINTRESOURCEA(135));
        #pragma GCC diagnostic pop
    }
}

/*
 * ApplyDarkModeToWindow - Enable dark mode for a window's title bar
 */
static void ApplyDarkModeToWindow(HWND hwnd)
{
    if (!g_bDarkModeEnabled)
        return;
    
    // Windows 10 build 1809+ dark mode API
    if (AllowDarkModeForWindow)
    {
        AllowDarkModeForWindow(hwnd, TRUE);
    }
    
    // Windows 10 build 1903+ uses DWMWA_USE_IMMERSIVE_DARK_MODE (attribute 20)
    // Windows 11 uses attribute 20 as well
    BOOL darkMode = TRUE;
    DwmSetWindowAttribute(hwnd, 20, &darkMode, sizeof(darkMode));
}

/*
 * ApplyDarkModeToDialog - Apply dark mode styling to a dialog
 * 
 * This should be called during WM_INITDIALOG.
 */
void ApplyDarkModeToDialog(HWND hwnd)
{
    if (!g_bDarkModeEnabled)
        return;
    
    ApplyDarkModeToWindow(hwnd);
}

/*
 * ApplyDarkModeToListView - Apply dark mode to a ListView control
 * 
 * Sets colors for the ListView to match dark theme.
 */
void ApplyDarkModeToListView(HWND hListView)
{
    if (!g_bDarkModeEnabled)
        return;
    
    // Set ListView colors
    ListView_SetTextColor(hListView, DARK_TEXT_COLOR);
    ListView_SetTextBkColor(hListView, DARK_CONTROL_BG);
    ListView_SetBkColor(hListView, DARK_CONTROL_BG);
    
    // Try to apply dark mode to the header
    HWND hHeader = ListView_GetHeader(hListView);
    if (hHeader)
    {
        SetWindowTheme(hHeader, L"ItemsView", NULL); // Use dark theme
    }
}

/*
 * HandleDarkModeMessages - Process WM_CTLCOLOR* messages for dark mode
 * 
 * Call this from your dialog procedure's message handler.
 * Returns non-zero if the message was handled.
 */
INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    (void)hwnd; // Unused parameter
    
    if (!g_bDarkModeEnabled)
        return 0;
    
    HDC hdc = (HDC)wParam;
    HWND hControl = (HWND)lParam;
    
    switch (msg)
    {
        case WM_CTLCOLORDLG:
            // Dialog background
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLORSTATIC:
        {
            // Static text and labels
            SetTextColor(hdc, DARK_TEXT_COLOR);
            SetBkColor(hdc, DARK_DIALOG_BG);
            return (INT_PTR)g_hBrushDialogBg;
        }
        
        case WM_CTLCOLOREDIT:
        {
            // Edit controls (text boxes)
            // Check if the control is read-only
            LONG style = GetWindowLong(hControl, GWL_STYLE);
            if (style & ES_READONLY)
            {
                SetTextColor(hdc, DARK_TEXT_DISABLED);
            }
            else
            {
                SetTextColor(hdc, DARK_TEXT_COLOR);
            }
            SetBkColor(hdc, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
        }
        
        case WM_CTLCOLORBTN:
            // Buttons - use dialog background
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLORLISTBOX:
            // Listbox controls
            SetTextColor(hdc, DARK_TEXT_COLOR);
            SetBkColor(hdc, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
    }
    
    return 0;
}

