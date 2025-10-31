# Dark Mode Implementation Guide

## Overview

WinRDP now features **automatic dark mode support** that follows your Windows system theme. When Windows is set to dark mode, the application will automatically use a dark color scheme for all dialogs and controls.

## How It Works

### Detection

The dark mode is detected by reading the Windows registry key:
```
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize
Value: AppsUseLightTheme
```

- **0** = Dark Mode enabled
- **1** = Light Mode enabled (default)

### Implementation Details

The dark mode implementation consists of several components:

#### 1. Registry Detection (`IsDarkModeEnabled`)
Checks the Windows Personalization settings to determine if dark mode is active.

#### 2. Initialization (`InitDarkMode`)
- Creates solid color brushes for dark backgrounds
- Attempts to load Windows 10 build 1809+ dark mode APIs
- Called once during application startup

#### 3. Dialog Application (`ApplyDarkModeToDialog`)
- Enables dark title bar using `DwmSetWindowAttribute`
- Should be called in each dialog's `WM_INITDIALOG` handler

#### 4. Control Color Handling (`HandleDarkModeMessages`)
Processes `WM_CTLCOLOR*` messages to set appropriate colors for:
- Dialog backgrounds
- Static text labels
- Edit controls (text boxes)
- Buttons
- Listboxes

#### 5. ListView Styling (`ApplyDarkModeToListView`)
- Sets text and background colors for ListView controls
- Applies dark theme to ListView headers

## Color Scheme

The dark mode uses the following color palette:

| Element | Color (RGB) | Description |
|---------|-------------|-------------|
| Main Background | `RGB(32, 32, 32)` | Darkest background |
| Dialog Background | `RGB(43, 43, 43)` | Dialog window background |
| Control Background | `RGB(55, 55, 55)` | Edit controls, buttons |
| Primary Text | `RGB(220, 220, 220)` | Main text color |
| Disabled Text | `RGB(130, 130, 130)` | Grayed out text |
| Border Color | `RGB(80, 80, 80)` | Borders and separators |
| Highlight Background | `RGB(0, 120, 215)` | Selected items |
| Highlight Text | `RGB(255, 255, 255)` | Text on selections |

## Code Integration

### Adding Dark Mode to Your Dialog

To add dark mode support to a new dialog:

1. **Include the header:**
```c
#include "darkmode.h"
```

2. **Apply dark mode in WM_INITDIALOG:**
```c
case WM_INITDIALOG:
{
    // ... other initialization code ...
    
    // Apply dark mode if enabled
    ApplyDarkModeToDialog(hwnd);
    
    // For ListView controls:
    HWND hListView = GetDlgItem(hwnd, IDC_YOUR_LISTVIEW);
    ApplyDarkModeToListView(hListView);
    
    return TRUE;
}
```

3. **Handle color messages in your dialog procedure:**
```c
// At the end of your dialog procedure, before returning FALSE:
INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
if (result != 0)
    return result;

return FALSE;
```

## Windows API Used

### Dark Title Bar (Windows 10 1809+)
```c
// Set dark mode for window title bar
BOOL darkMode = TRUE;
DwmSetWindowAttribute(hwnd, 20, &darkMode, sizeof(darkMode));
```

Attribute 20 is:
- `DWMWA_USE_IMMERSIVE_DARK_MODE` on Windows 10 build 1903+
- Works on Windows 11 as well

### ListView Theming
```c
// Set ListView colors
ListView_SetTextColor(hListView, DARK_TEXT_COLOR);
ListView_SetTextBkColor(hListView, DARK_CONTROL_BG);
ListView_SetBkColor(hListView, DARK_CONTROL_BG);

// Apply dark theme to header
HWND hHeader = ListView_GetHeader(hListView);
SetWindowTheme(hHeader, L"ItemsView", NULL);
```

### Control Color Messages

The following messages are handled for dark mode:

- **WM_CTLCOLORDLG** - Dialog background
- **WM_CTLCOLORSTATIC** - Labels and static text
- **WM_CTLCOLOREDIT** - Text boxes
- **WM_CTLCOLORBTN** - Buttons
- **WM_CTLCOLORLISTBOX** - Listbox controls

Each handler sets appropriate text color, background color, and returns a brush for painting.

## Testing

To test dark mode:

1. **Enable Dark Mode in Windows:**
   - Settings → Personalization → Colors
   - Choose "Dark" for "Choose your mode"

2. **Run WinRDP:**
   ```
   build\WinRDP.exe
   ```

3. **Verify:**
   - All dialogs should have dark backgrounds
   - Title bars should be dark
   - Text should be light colored
   - ListView controls should use dark colors

4. **Test Light Mode:**
   - Switch Windows back to Light mode
   - Restart WinRDP
   - Should display with standard light colors

## Compatibility

- **Minimum:** Windows 7 (basic dark mode colors)
- **Recommended:** Windows 10 build 1809+ (full dark title bar support)
- **Best:** Windows 11 (full system integration)

On older Windows versions:
- Dark mode colors will still work for dialogs and controls
- Title bar may remain light (native Windows limitation)

## File Structure

```
src/
├── darkmode.h          # Dark mode API declarations
├── darkmode.c          # Dark mode implementation
└── main.c              # Integrated into all dialog procedures
```

## Educational Value

This implementation demonstrates:

1. **Registry Access** - Reading Windows settings
2. **Dynamic API Loading** - Loading Windows 10+ APIs at runtime
3. **Custom Control Painting** - Handling WM_CTLCOLOR* messages
4. **Windows Theming** - Using modern Windows appearance APIs
5. **Brush Management** - Creating and managing GDI brushes
6. **Conditional Compilation** - Handling different Windows versions

## Notes

- Dark mode is detected once at startup (not dynamically updated)
- To reflect theme changes, restart the application
- All brushes are created during initialization
- No cleanup is currently implemented (brushes are freed by OS on exit)

## Future Enhancements

Potential improvements:

1. **Dynamic Theme Switching** - Detect theme changes while running
2. **Custom Themes** - User-configurable color schemes
3. **High Contrast Support** - Support Windows High Contrast mode
4. **Per-Monitor DPI** - Better scaling on multi-monitor setups
5. **Modern Controls** - Use Windows 11 rounded corners

## License

This dark mode implementation is part of the WinRDP educational project and is released into the public domain.

