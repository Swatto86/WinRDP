# Delete All Hosts and Credentials Feature

## Overview
Added a hidden keyboard shortcut feature to delete all hosts and credentials in one operation. This feature is intentionally hard to activate to prevent accidental data loss.

## Implementation

### Keyboard Shortcut
**`Ctrl + Shift + Alt + D`**

**Where to use:** This combination must be pressed while the **Host Management dialog** is open. 

To open the Host Management dialog:
1. Launch WinRDP Manager
2. Click the **"Manage"** button on the main dialog
3. This will open the "WinRDP - Manage Hosts" dialog
4. Press **Ctrl + Shift + Alt + D** while this dialog has focus

The deliberate use of four modifier keys makes accidental activation extremely unlikely.

### Safety Features
1. **First Confirmation Dialog**: Warns the user about what will be deleted
   - Shows warning icon
   - Default button is "No" to prevent accidental acceptance
   
2. **Second Confirmation Dialog**: Final chance to cancel
   - Shows stop icon (more severe warning)
   - Default button is again "No"
   
3. **Status Feedback**: Reports success or any issues after deletion

### What Gets Deleted
1. **All RDP Hosts**: The entire `hosts.csv` file is reset to just the header
2. **All Credentials**: Both global and per-host credentials stored in Windows Credential Manager

### Technical Details

#### New Functions
1. **DeleteAllHosts()** in `hosts.c`
   - Creates empty CSV with just the header
   - Returns TRUE on success

2. **DeleteAllWinRDPCredentials()** in `credentials.c`
   - Uses `CredEnumerateW` to list all credentials
   - Filters for credentials starting with "WinRDP:"
   - Deletes each matching credential using `CredDeleteW`
   - Properly frees memory allocated by `CredEnumerateW`

#### Code Changes
- `src/hosts.c`: Added `DeleteAllHosts()` function
- `src/hosts.h`: Added function declaration
- `src/credentials.c`: Added `DeleteAllWinRDPCredentials()` function  
- `src/credentials.h`: Added function declaration
- `src/main.c`: Added `WM_HOTKEY` handler in `HostDialogProc()` and `RegisterHotKey()` in `WM_INITDIALOG` to detect the key combination

**Technical Note:** The keyboard shortcut is implemented using `RegisterHotKey()` API which provides reliable keyboard shortcut handling for modal dialogs. The hotkey is registered when the Host Management dialog opens and unregistered when it closes. This is more reliable than handling `WM_KEYDOWN` messages, which can be consumed by Windows dialog message processing.

## Usage

1. Launch WinRDP Manager from the system tray or run `build\WinRDP.exe`
2. Click the **"Manage"** button on the main dialog
3. The "WinRDP - Manage Hosts" dialog will appear
4. With the Host Management dialog having focus, press **Ctrl + Shift + Alt + D**
5. Read the warning carefully and confirm (or cancel)
6. Confirm again in the second dialog if you're absolutely sure
7. All hosts and credentials will be deleted and the list will refresh empty

## Educational Value

This feature demonstrates:
- Windows API global hotkey registration (`RegisterHotKey`, `UnregisterHotKey`, `WM_HOTKEY`)
- Windows Credential Manager enumeration (`CredEnumerateW`)
- Safe memory management with credential APIs
- Multiple confirmation dialog patterns
- User safety design patterns

## Files Modified
- `src/hosts.c`
- `src/hosts.h`
- `src/credentials.c`
- `src/credentials.h`
- `src/main.c`

## Build Status
✅ Successfully compiled with no warnings or errors

