# WinRDP Dark Mode Support

## Overview

WinRDP features **automatic dark mode support** that follows your Windows system theme. When Windows is set to dark mode, the application automatically uses a dark color scheme for all dialogs and controls.

## Features

### Automatic Detection
- Reads Windows registry to detect dark mode preference
- Applies dark mode automatically when Windows is in dark mode
- No user configuration needed

### Complete Coverage
All dialogs support dark mode:
- ✅ Login Dialog - Credentials entry screen
- ✅ Main Server List Dialog - Server browsing and connection
- ✅ Host Management Dialog - Add/edit/delete servers
- ✅ Add/Edit Host Dialog - Host details entry
- ✅ About Dialog - Application information

### Styled Components
- ✅ Dialog backgrounds - Dark gray backgrounds
- ✅ Text labels - Light colored text
- ✅ Text boxes - Dark input fields with light text
- ✅ Buttons - Properly styled buttons
- ✅ ListView controls - Dark grid with light text
- ✅ Title bars - Dark window chrome (Windows 10 1809+)

## How It Works

### Detection
Dark mode is detected by reading the Windows registry:
```
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize
Value: AppsUseLightTheme
```
- **0** = Dark Mode enabled
- **1** = Light Mode enabled (default)

### Implementation

#### Files
- `src/darkmode.h` - Dark mode API declarations
- `src/darkmode.c` - Dark mode implementation

#### Key Functions
1. **`IsDarkModeEnabled()`** - Detects Windows dark mode setting
2. **`InitDarkMode()`** - Initializes dark mode (called once at startup)
3. **`ApplyDarkModeToDialog()`** - Applies dark mode to a dialog
4. **`HandleDarkModeMessages()`** - Processes dark mode messages

### Message Handling
Dark mode requires special handling of Windows messages:
- `WM_CTLCOLORDLG` - Dark background
- `WM_CTLCOLORSTATIC` - Dark labels
- `WM_CTLCOLOREDIT` - Dark text boxes
- `WM_CTLCOLORLISTBOX` - Dark list boxes

### Registry API
Uses `RegGetValueW` to read Windows theme preference safely.

## Technical Details

### Windows API Functions
- `RegGetValueW` - Read registry safely
- `CreateSolidBrush` - Create dark background brushes
- `SetClassLongPtr` - Set dialog background
- `GetProcAddress` - Load Windows 10+ dark mode APIs
- `DwmSetWindowAttribute` - Dark title bars (Windows 10 1809+)

### Color Scheme
- Background: RGB(32, 32, 32) - Dark gray
- Text: RGB(255, 255, 255) - White
- Input fields: Dark themed by Windows

### Compatibility
- **Windows 7+** - Basic dark mode support
- **Windows 10 1809+** - Full support including dark title bars
- **Windows 11** - Full support with native theming

## Code Example

```c
// In dialog WM_INITDIALOG:
case WM_INITDIALOG:
    // Apply dark mode if enabled
    ApplyDarkModeToDialog(hwnd);
    return TRUE;

// Add after main message processing:
// Handle dark mode
INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
if (result != 0)
    return result;
```

## Testing

To test dark mode:
1. Open Windows Settings → Personalization → Colors
2. Choose "Dark" as your app mode
3. Launch WinRDP
4. Verify all dialogs display in dark mode

---

**WinRDP by Swatto**  
Educational Windows API Programming Project

