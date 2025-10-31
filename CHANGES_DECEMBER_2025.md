# WinRDP - December 2025 Update Summary

## New Features Added

### 1. Global Hotkey (Ctrl+Shift+R)
**Purpose**: Instantly open WinRDP from anywhere in Windows to connect to servers

**Functionality**:
- Registered globally using `RegisterHotKey()` API
- Works regardless of which application has focus
- Intelligently shows appropriate dialog:
  - If global credentials exist → Opens Connect to Server dialog
  - If no credentials → Opens Enter Credentials dialog
- Prevents duplicate dialogs by bringing existing to front

**Technical Details**:
- Registered in `WM_CREATE` of main window
- Unregistered in `WM_DESTROY` on exit
- Handled via `WM_HOTKEY` message
- Silent failure if hotkey in use (app still functional)

---

### 2. Bulk Delete Hotkey (Ctrl+Shift+Alt+D)
**Purpose**: Secret hotkey to quickly delete all hosts and credentials

**Functionality**:
- Accessible only from Host Management dialog
- Hard to press accidentally (4 modifier keys)
- Double confirmation for safety:
  - First warning with details of what will be deleted
  - Final warning with "last chance" message
- Deletes:
  - All RDP hosts from CSV file
  - All WinRDP credentials from Windows Credential Manager
  - Both global and per-host credentials

**Technical Details**:
- Registered in Host Management `WM_INITDIALOG`
- Unregistered in `WM_CLOSE` and `WM_DESTROY`
- Uses `CredEnumerateW` to find all WinRDP credentials
- Filters by "WinRDP:" prefix
- Properly frees all allocated memory
- Handled via `WM_HOTKEY` message

**Safety Features**:
- Two-step confirmation process
- Default button is "No" on both confirmations
- Clear warnings with bullet points
- Success/error feedback after deletion

---

## Technical Implementation

### New Functions

#### In `hosts.c`:
```c
BOOL DeleteAllHosts(void)
```
- Creates empty CSV with just header
- Preserves file format and encoding
- Returns TRUE on success

#### In `credentials.c`:
```c
BOOL DeleteAllWinRDPCredentials(void)
```
- Enumerates all credentials using `CredEnumerateW`
- Filters for "WinRDP:" prefix
- Deletes each matching credential
- Properly frees memory with `CredFree`
- Returns TRUE even if no credentials found

#### In `main.c`:
- `WM_HOTKEY` handler in `WndProc()` for global hotkey
- `WM_HOTKEY` handler in `HostDialogProc()` for bulk delete
- Registration/unregistration in appropriate lifecycle events

---

## Files Modified

### Source Code:
- `src/main.c` - Hotkey registration, WM_HOTKEY handlers, enhanced comments
- `src/hosts.c` - DeleteAllHosts() function
- `src/hosts.h` - DeleteAllHosts() declaration
- `src/credentials.c` - DeleteAllWinRDPCredentials() function with CredEnumerateW
- `src/credentials.h` - DeleteAllWinRDPCredentials() declaration
- `src/resource.h` - Added IDM_GLOBAL_HOTKEY and IDM_DELETE_ALL constants

### Documentation:
- `README.md` - Added hotkey features to feature list
- `00_START_HERE.md` - Added global hotkeys to learning objectives
- `PROJECT_SUMMARY.md` - Updated features and Windows API concepts
- `CODE_COMMENTARY.md` - Added Global Hotkeys section with code examples
- `RECENT_UPDATES.md` - Detailed documentation of new features

### New Documentation:
- `GLOBAL_HOTKEY_FEATURE.md` - Complete guide to global hotkey feature
- `DELETE_ALL_FEATURE.md` - Complete guide to bulk delete feature
- `CHANGES_DECEMBER_2025.md` - This summary document

---

## Windows API Concepts Demonstrated

### Global Hotkeys
- `RegisterHotKey()` - System-wide hotkey registration
- `UnregisterHotKey()` - Release hotkeys on cleanup
- `WM_HOTKEY` message - Handling hotkey presses
- Modifier keys: `MOD_CONTROL`, `MOD_SHIFT`, `MOD_ALT`
- Virtual key codes (e.g., 0x44 for 'D')

### Credential Management
- `CredEnumerateW()` - List all credentials
- `CredFree()` - Free memory from enumeration
- Filtering and bulk deletion patterns

---

## Build & Testing

**Build Status**: ✅ Successful with no warnings or errors

**Testing Checklist**:
- ✅ Global hotkey opens appropriate dialog
- ✅ Global hotkey brings dialog to front if already open
- ✅ Bulk delete hotkey shows confirmations
- ✅ Bulk delete removes all hosts from CSV
- ✅ Bulk delete removes all credentials
- ✅ Hotkeys unregister properly on exit
- ✅ No memory leaks
- ✅ Clean build with GCC

---

## Usage Instructions

### Global Open Hotkey
1. Launch WinRDP (runs in system tray)
2. Press **Ctrl+Shift+R** from anywhere
3. Appropriate dialog appears based on credentials

### Bulk Delete Hotkey
1. Open WinRDP
2. Click "Manage" to open Host Management
3. Press **Ctrl+Shift+Alt+D**
4. Read first warning and confirm
5. Read final warning and confirm
6. All data deleted

---

## Code Quality

- ✅ Comprehensive comments
- ✅ Educational value in comments
- ✅ Proper error handling
- ✅ Memory management
- ✅ Safe string operations
- ✅ Clean build
- ✅ No compiler warnings
- ✅ Follows existing code style

---

## Educational Value

These features teach:
- Global hotkey registration and cleanup
- System-wide message handling
- Credential enumeration API
- Bulk operations with filtering
- User safety patterns (confirmations)
- Fail-safe error handling
- Dialog management

---

## Ready for GitHub

All documentation updated, code commented, build successful, features tested.

**Commit message suggestion**:
```
Add global hotkey support and bulk delete feature

Features:
- Ctrl+Shift+R: Global hotkey to open WinRDP from anywhere
- Ctrl+Shift+Alt+D: Secret hotkey to delete all hosts and credentials
- Intelligent dialog display based on saved credentials
- Comprehensive documentation and in-code comments

Technical:
- RegisterHotKey/UnregisterHotKey/WM_HOTKEY implementation
- CredEnumerateW for credential enumeration
- Double confirmation for safety
- Proper memory management
```

---

**Status**: Production ready! 🎉

