/*
 * Dark Mode Support
 * 
 * This module provides dark mode functionality for the application.
 * It detects Windows dark mode settings and applies appropriate colors
 * to all UI elements including dialogs, controls, and listviews.
 */

#ifndef DARKMODE_H
#define DARKMODE_H

#include <windows.h>

// Dark mode colors
#define DARK_BG_COLOR           RGB(32, 32, 32)       // Main background
#define DARK_DIALOG_BG          RGB(43, 43, 43)       // Dialog background
#define DARK_CONTROL_BG         RGB(55, 55, 55)       // Edit controls, buttons
#define DARK_TEXT_COLOR         RGB(220, 220, 220)    // Primary text
#define DARK_TEXT_DISABLED      RGB(130, 130, 130)    // Disabled text
#define DARK_BORDER_COLOR       RGB(80, 80, 80)       // Borders and lines
#define DARK_HIGHLIGHT_BG       RGB(0, 120, 215)      // Selected items
#define DARK_HIGHLIGHT_TEXT     RGB(255, 255, 255)    // Text on highlight

// Function declarations
BOOL IsDarkModeEnabled(void);
void InitDarkMode(void);
void ApplyDarkModeToDialog(HWND hwnd);
void ApplyDarkModeToListView(HWND hListView);
INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // DARKMODE_H

