# Global Hotkey Feature

## Overview
Added a global hotkey (`Ctrl+Shift+R`) that allows users to quickly open WinRDP from anywhere in Windows. The hotkey intelligently shows the appropriate dialog based on whether global credentials are saved.

## Implementation

### Keyboard Shortcut
**`Ctrl + Shift + R`**

This global hotkey works from anywhere in Windows, not just when WinRDP has focus.

### Intelligent Dialog Display
The hotkey behavior depends on whether global credentials are saved:

1. **If Global Credentials Exist**: Shows the **"WinRDP - Connect to Server"** dialog
2. **If No Global Credentials**: Shows the **"WinRDP - Enter Credentials"** dialog

This makes it quick to connect to RDP servers without having to navigate through menus.

### Technical Details

#### Global Hotkey Registration
- **Registered in**: `WM_CREATE` of the main window
- **Unregistered in**: `WM_DESTROY` of the main window
- **API**: `RegisterHotKey()` / `UnregisterHotKey()`
- **Hotkey ID**: `IDM_GLOBAL_HOTKEY`

#### Message Handling
- **Message**: `WM_HOTKEY` 
- **Handler**: Checks `wParam == IDM_GLOBAL_HOTKEY` to identify the hotkey
- **Credential Check**: Uses `LoadCredentials(NULL, ...)` to check for global credentials
- **Dialog Management**: Prevents duplicate dialogs by checking for existing instances

#### Code Changes
- `src/resource.h`: Added `IDM_GLOBAL_HOTKEY` constant
- `src/main.c`: Added hotkey registration in `WM_CREATE`
- `src/main.c`: Added `WM_HOTKEY` handler in `WndProc()`
- `src/main.c`: Added hotkey unregistration in `WM_DESTROY`

## Usage

1. Launch WinRDP Manager (it will run in the system tray)
2. From anywhere in Windows, press **Ctrl + Shift + R**
3. The appropriate dialog will appear:
   - If you have global credentials: Connect to Server dialog
   - If no credentials: Enter Credentials dialog
4. Press **Ctrl + Shift + R** again to bring the dialog to the front if already open

## Error Handling

- If hotkey registration fails (e.g., another app is using the same key), the app will continue to work without the hotkey
- The failure is silent - no error messages are shown
- All other functionality remains unchanged

## Educational Value

This feature demonstrates:
- Global hotkey registration (`RegisterHotKey`, `UnregisterHotKey`, `WM_HOTKEY`)
- Dynamic dialog display based on application state
- System tray application patterns
- Fail-safe error handling for system-level operations

## Files Modified
- `src/resource.h`
- `src/main.c`

## Build Status
✅ Successfully compiled with no warnings or errors

