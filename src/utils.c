/*
 * Utility Functions
 * 
 * Helper functions used throughout the application
 */

#include <windows.h>
#include "config.h"

/*
 * CenterWindow - Centers a window on the screen
 * 
 * This is a common UI task in Windows programming.
 * We get the screen dimensions and window size, then calculate
 * the position that centers the window.
 */
void CenterWindow(HWND hwnd)
{
    RECT rc, rcDesktop;
    
    // Get window dimensions
    GetWindowRect(hwnd, &rc);
    
    // Get desktop (screen) dimensions
    GetWindowRect(GetDesktopWindow(), &rcDesktop);
    
    // Calculate centered position
    int x = (rcDesktop.right - (rc.right - rc.left)) / 2;
    int y = (rcDesktop.bottom - (rc.bottom - rc.top)) / 2;
    
    // Move window to centered position
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

/*
 * ShowErrorMessage - Display an error message box
 */
void ShowErrorMessage(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, L"Error - " APP_NAME, MB_OK | MB_ICONERROR);
}

/*
 * ShowInfoMessage - Display an information message box
 */
void ShowInfoMessage(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, APP_NAME, MB_OK | MB_ICONINFORMATION);
}

