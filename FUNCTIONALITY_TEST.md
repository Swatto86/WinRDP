# WinRDP Functionality Test Guide

This document provides a comprehensive test plan for all WinRDP features.

## ✅ Feature Checklist

### 1. **Application Startup**
- [x] Single instance enforcement (mutex)
- [x] System tray icon appears
- [x] Login dialog appears automatically
- [x] Application manifest enables modern UI
- [x] Custom icon displays correctly

### 2. **Credential Management**

#### Global Credentials (Default):

##### Save Global Credentials:
1. Open WinRDP
2. Enter username (e.g., "admin@domain.com")
3. Enter password
4. Click "Save & Continue"
5. **Expected**: Credentials saved to Windows Credential Manager
6. **Expected**: Main dialog appears automatically

##### Load Global Credentials:
1. Close and restart WinRDP
2. **Expected**: Username and password fields pre-filled
3. **Expected**: Status shows "✓ Credentials saved - Auto-closing in X seconds..."
4. **Expected**: "Delete Saved" button visible

##### Delete Global Credentials:
1. With saved credentials loaded
2. Click "Delete Saved"
3. **Expected**: Fields cleared
4. **Expected**: "Delete Saved" button hidden
5. **Expected**: Status text cleared

#### Per-Host Credentials (Optional):

##### Add Host with Per-Host Credentials:
1. Open "Manage Hosts" dialog
2. Click "Add Host"
3. Enter hostname and description
4. Check "Use custom credentials for this host"
5. **Expected**: Username and password fields appear
6. Enter per-host username and password (different from global)
7. Click "Save"
8. **Expected**: Host saved with per-host credentials

##### Connect Using Per-Host Credentials:
1. In main dialog, select host with per-host credentials
2. Click "Connect"
3. **Expected**: Connects using per-host credentials (not global)
4. **Expected**: Connection succeeds with per-host credentials

##### Add Host Without Per-Host Credentials:
1. Open "Manage Hosts" dialog
2. Click "Add Host"
3. Enter hostname and description
4. **Expected**: Checkbox is unchecked, credential fields hidden
5. Click "Save"
6. **Expected**: Host uses global credentials when connecting

##### Edit Host - Enable Per-Host Credentials:
1. Select a host that uses global credentials
2. Click "Edit Host"
3. Check "Use custom credentials for this host"
4. Enter per-host username and password
5. Click "Save"
6. **Expected**: Per-host credentials saved
7. **Expected**: Host now uses per-host credentials

##### Edit Host - Disable Per-Host Credentials:
1. Select a host with per-host credentials
2. Click "Edit Host"
3. **Expected**: Checkbox is checked, credentials are shown
4. Uncheck "Use custom credentials for this host"
5. **Expected**: Credential fields hidden
6. Click "Save"
7. **Expected**: Per-host credentials deleted
8. **Expected**: Host now uses global credentials

##### Edit Host - View Existing Per-Host Credentials:
1. Select a host with per-host credentials
2. Click "Edit Host"
3. **Expected**: Checkbox is checked
4. **Expected**: Username and password fields populated
5. **Expected**: Can modify credentials

##### Rename Host with Per-Host Credentials:
1. Select a host with per-host credentials
2. Click "Edit Host"
3. Change hostname
4. Click "Save"
5. **Expected**: Old hostname per-host credentials deleted
6. **Expected**: New hostname uses global credentials (unless checkbox is checked)

### 3. **Host Management**

#### Add Host:
1. Open main dialog
2. Click "Manage Hosts"
3. Click "Add Host"
4. Enter:
   - Hostname: `server01.domain.com`
   - Description: `Production RDP Server`
5. Click "Save"
6. **Expected**: Host appears in list
7. **Expected**: CSV file created/updated

#### Edit Host:
1. In "Manage Hosts" dialog
2. Select a host from the list
3. Click "Edit Host"
4. Modify description
5. Click "Save"
6. **Expected**: Changes reflected in list
7. **Expected**: CSV file updated

#### Delete Host:
1. In "Manage Hosts" dialog
2. Select a host from the list
3. Click "Delete Host"
4. **Expected**: Confirmation dialog
5. Click "Yes"
6. **Expected**: Host removed from list
7. **Expected**: CSV file updated

#### Multiple Hosts:
1. Add several hosts:
   - `192.168.1.100` - Development Server
   - `rdp.company.com` - Main Server
   - `WIN-PC01` - Test Machine
2. **Expected**: All display correctly with descriptions
3. **Expected**: Full descriptions visible (not truncated)

### 4. **CSV File Handling**

#### UTF-8 Encoding:
1. Add host with special characters in description:
   - Hostname: `test01`
   - Description: `Test: 中文 العربية émojis ñ`
2. Close application
3. Open `build\hosts.csv` in Notepad
4. **Expected**: UTF-8 BOM present
5. **Expected**: Special characters display correctly

#### Commas in Description:
1. Add host with commas:
   - Hostname: `server02`
   - Description: `Server, Main, Production`
2. **Expected**: Saves correctly
3. **Expected**: Loads correctly (not truncated at comma)
4. Open CSV file
5. **Expected**: Description wrapped in quotes

#### Long Descriptions:
1. Add host with long description (200+ characters)
2. **Expected**: Full text saved
3. **Expected**: Full text displayed in list
4. **Expected**: Scrollable in edit field

### 5. **RDP Connection**

#### Connect to Host (Global Credentials):
1. In main dialog, select a host without per-host credentials
2. Double-click OR click "Connect"
3. **Expected**: `mstsc.exe` launches
4. **Expected**: Connects using global credentials
5. **Expected**: Connects to specified hostname

#### Connect to Host (Per-Host Credentials):
1. In main dialog, select a host with per-host credentials
2. Double-click OR click "Connect"
3. **Expected**: `mstsc.exe` launches
4. **Expected**: Connects using per-host credentials (not global)
5. **Expected**: Connection uses correct per-host credentials

#### Credential Priority (Per-Host over Global):
1. Set global credentials (user1/pass1)
2. Add host with per-host credentials (user2/pass2)
3. Connect to host with per-host credentials
4. **Expected**: Uses user2/pass2 (not user1/pass1)
5. Add another host without per-host credentials
6. Connect to that host
7. **Expected**: Uses user1/pass1 (global credentials)

#### Default Credentials:
1. Ensure global credentials saved
2. Connect to a host
3. **Expected**: Username pre-filled in RDP
4. **Expected**: Password pre-filled (if supported)

### 6. **User Interface**

#### Single Instance Dialogs:
1. Open main dialog
2. Try to open again (click tray icon)
3. **Expected**: Existing dialog brought to front
4. Try opening "Manage Hosts" twice
5. **Expected**: Existing dialog brought to front
6. Try opening "Add Host" twice
7. **Expected**: Existing dialog brought to front

#### Dialog Icons:
1. Open each dialog
2. **Expected**: Custom RDP icon in title bar
3. **Expected**: Icon in taskbar
4. **Expected**: Icon in Alt+Tab switcher

#### DPI Scaling:
1. Test on 4K monitor (if available)
2. **Expected**: Crisp rendering
3. **Expected**: No blurry text
4. **Expected**: Proper scaling

#### Dark Mode (Windows 11):
1. Enable Windows dark mode
2. **Expected**: Dialogs use system theme
3. **Expected**: Proper contrast

### 7. **Global Hotkeys**

#### Global Open Hotkey (Ctrl+Shift+R):
1. Launch WinRDP (runs in system tray)
2. From anywhere in Windows, press **Ctrl+Shift+R**
3. **Expected**: Appropriate dialog appears:
   - If global credentials exist: Connect to Server dialog
   - If no credentials: Enter Credentials dialog
4. Press **Ctrl+Shift+R** again while dialog is open
5. **Expected**: Dialog brought to front (not duplicated)

#### Bulk Delete Hotkey (Ctrl+Shift+Alt+D):
1. Open WinRDP Main dialog
2. Click "Manage" to open Host Management
3. Add 3-5 test hosts
4. Save some credentials
5. With Host Management dialog focused, press **Ctrl+Shift+Alt+D**
6. **Expected**: First warning dialog appears with details
7. Click "Yes" to confirm
8. **Expected**: Final warning dialog appears
9. Click "Yes" to confirm
10. **Expected**: All hosts deleted from list
11. **Expected**: All credentials deleted
12. **Expected**: Success message displayed

### 8. **Network Scanning**

#### Scan Domain:
1. Open "Manage Hosts" dialog
2. Click "Scan Domain" button
3. **Expected**: Scan Domain dialog appears
4. Enter domain/workgroup name (or leave empty for current)
5. Choose what to include (workstations, servers, DCs)
6. Click "Scan"
7. **Expected**: Scanning dialog shows progress
8. **Expected**: All discovered computers added to host list automatically
9. **Expected**: AD descriptions preserved
10. **Expected**: Success message shows count of computers added

#### Network Scan Error Handling:
1. Click "Scan Domain" with no network connection
2. **Expected**: Appropriate error message shown
3. Expected**: Host Management dialog remains open

### 9. **System Tray**

#### Left Click:
1. Click tray icon
2. **Expected**: Main dialog opens
3. Close dialog
4. Click again
5. **Expected**: Dialog reopens

#### Right Click Menu:
1. Right-click tray icon
2. **Expected**: Context menu appears with:
   - Open
   - Start with Windows (with checkmark if enabled)
   - Exit
3. Click "Open"
4. **Expected**: Main dialog opens

#### Autostart:
1. Right-click tray icon
2. Click "Start with Windows"
3. **Expected**: Checkmark appears
4. Check registry: `HKCU\Software\Microsoft\Windows\CurrentVersion\Run`
5. **Expected**: WinRDP entry exists
6. Click again to disable
7. **Expected**: Checkmark removed
8. **Expected**: Registry entry deleted

### 10. **Error Handling**

#### Empty Fields:
1. Try adding host with empty hostname
2. **Expected**: Error message "Please enter a hostname"
3. Try saving credentials with empty username
4. **Expected**: Error message "Please enter a username"

#### Invalid Operations:
1. Click "Delete Host" with nothing selected
2. **Expected**: Error "Please select a host first"
3. Click "Edit Host" with nothing selected
4. **Expected**: Error "Please select a host to edit"
5. Click "Connect" with nothing selected
6. **Expected**: Error "Please select a server first"

#### File System:
1. Make `build\hosts.csv` read-only
2. Try adding a host
3. **Expected**: Error message about save failure
4. Remove read-only attribute

### 11. **Data Persistence**

#### Restart Test:
1. Add 5 hosts
2. Save credentials
3. Enable autostart
4. Close application completely
5. Restart application
6. **Expected**: All hosts loaded
7. **Expected**: Credentials loaded
8. **Expected**: Autostart still enabled

#### Clean State:
1. Delete `build\hosts.csv`
2. Delete credentials (if any)
3. Start application
4. **Expected**: Empty host list
5. **Expected**: No credentials loaded
6. **Expected**: No errors

### 12. **Performance**

#### Large List:
1. Add 50+ hosts programmatically (edit CSV)
2. Open "Manage Hosts"
3. **Expected**: Smooth scrolling
4. **Expected**: No lag
5. **Expected**: Fast search/filter (if implemented)

#### Memory:
1. Open Task Manager
2. Run WinRDP
3. **Expected**: < 20MB RAM usage
4. Open all dialogs
5. **Expected**: Reasonable memory usage
6. Close dialogs
7. **Expected**: Memory released

## 🐛 Known Limitations

### Password in RDP:
- **Limitation**: `mstsc.exe` doesn't accept password via command line (security)
- **Behavior**: Username passed, password must be entered
- **Alternative**: Use .RDP files with password (less secure)

### Edit Host:
- **Current**: Opens Add Host dialog (overwrites if same hostname)
- **Future**: Could pre-fill fields with existing data
- **Works**: But not immediately obvious to user

## 📊 Test Results Template

```
Test Date: __________
Tester: __________
Windows Version: __________
Build: __________

Feature                  | Status | Notes
------------------------|--------|-------
Credential Save         | ✓/✗   |
Credential Load         | ✓/✗   |
Credential Delete       | ✓/✗   |
Per-Host Credentials    | ✓/✗   |
Add Host                | ✓/✗   |
Edit Host               | ✓/✗   |
Delete Host             | ✓/✗   |
Connect to RDP          | ✓/✗   |
CSV UTF-8 Encoding      | ✓/✗   |
Single Instance (App)   | ✓/✗   |
Single Instance (Dialogs)| ✓/✗   |
System Tray             | ✓/✗   |
Autostart               | ✓/✗   |
Global Hotkey (Ctrl+Shift+R) | ✓/✗   |
Bulk Delete (Ctrl+Shift+Alt+D) | ✓/✗   |
Network Scanning        | ✓/✗   |
Dark Mode              | ✓/✗   |
Modern UI (Manifest)    | ✓/✗   |
DPI Awareness           | ✓/✗   |
Custom Icon             | ✓/✗   |
```

## 🔍 Debugging Tips

### Credentials Not Saving:
1. Check Windows Credential Manager:
   - Control Panel → Credential Manager → Windows Credentials
   - Look for "WinRDP:DefaultCredentials"
2. Run as Administrator if needed
3. Check return value from `CredWriteW`

### Hosts Not Loading:
1. Check if `build\hosts.csv` exists
2. Open CSV in Notepad - check format
3. Ensure UTF-8 encoding (BOM should be present)
4. Check for syntax errors (unmatched quotes, etc.)

### RDP Not Launching:
1. Verify `mstsc.exe` is in PATH
2. Check command line being generated
3. Test manually: `mstsc.exe /v:hostname`
4. Ensure hostname is valid and reachable

### System Tray Icon Missing:
1. Check if Shell_NotifyIcon succeeded
2. Verify icon resource loads
3. Check Windows tray overflow settings

## 📚 Additional Testing Scenarios

### Edge Cases:
- Very long hostnames (255 characters)
- Special characters in hostnames
- Unicode in all fields
- Empty descriptions (should work)
- Rapid clicking (race conditions)
- Network disconnected (RDP should handle)

### Security:
- Credentials stored encrypted in Windows
- No plain text passwords in CSV
- Registry entries in user hive (not system)
- Mutex name is unique and not guessable

### Accessibility:
- Tab order logical
- Enter key activates default buttons
- Escape key closes dialogs
- Mnemonics/keyboard shortcuts (future)

## 🎓 Educational Value

This test document demonstrates:
- Comprehensive software testing methodology
- User acceptance testing (UAT)
- Edge case identification
- Documentation best practices
- Quality assurance processes

Use this as a template for testing your own Windows applications!

