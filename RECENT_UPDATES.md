# Recent Updates to WinRDP

## Latest Changes

### ⌨️ **NEW FEATURES: Global Hotkeys (December 2025)**

#### 1. **Global Open Hotkey (Ctrl+Shift+R)**
- ✅ Instantly open WinRDP from anywhere in Windows
- ✅ Automatically shows appropriate dialog based on saved credentials
- ✅ If global credentials exist: Shows connect dialog
- ✅ If no credentials: Shows credentials entry dialog
- ✅ Prevents duplicate dialogs by bringing existing dialog to front

#### 2. **Bulk Delete Hotkey (Ctrl+Shift+Alt+D)**
- ✅ Hidden secret hotkey in Host Management dialog
- ✅ Deletes all hosts and credentials in one operation
- ✅ Double confirmation for safety (two dialogs with warnings)
- ✅ Deletes all hosts from CSV file
- ✅ Deletes all WinRDP credentials from Windows Credential Manager
- ✅ Hard to press accidentally (4 modifier keys)

#### Technical Implementation
- Uses `RegisterHotKey()` / `UnregisterHotKey()` for global hotkeys
- Handles `WM_HOTKEY` messages in window procedures
- Global hotkey registered in `WM_CREATE`, unregistered in `WM_DESTROY`
- Bulk delete hotkey registered in Host Management `WM_INITDIALOG`
- Credential enumeration using `CredEnumerateW` API

#### Files Modified
- `src/main.c` - Added global hotkey registration and WM_HOTKEY handlers
- `src/resource.h` - Added IDM_GLOBAL_HOTKEY and IDM_DELETE_ALL constants
- `src/hosts.c` - Added `DeleteAllHosts()` function
- `src/hosts.h` - Added DeleteAllHosts() declaration
- `src/credentials.c` - Added `DeleteAllWinRDPCredentials()` function
- `src/credentials.h` - Added DeleteAllWinRDPCredentials() declaration

#### Documentation
- `GLOBAL_HOTKEY_FEATURE.md` - Global hotkey feature documentation
- `DELETE_ALL_FEATURE.md` - Bulk delete feature documentation

### 🎯 **NEW FEATURE: Per-Host Credentials**

#### What It Does
- ✅ Optionally set individual credentials for specific hosts
- ✅ Falls back to global credentials if per-host credentials not set
- ✅ Edit dialog shows existing per-host credentials when editing
- ✅ Checkbox to enable/disable per-host credentials per host
- ✅ Seamless integration with existing credential system

#### How It Works
1. **Global Credentials** (Default):
   - Set once at application launch in Login Dialog
   - Used for all hosts by default
   - Stored in Windows Credential Manager

2. **Per-Host Credentials** (Optional):
   - When adding/editing a host, check "Use custom credentials for this host"
   - Enter username and password for that specific host
   - Credentials are stored per-host in Windows Credential Manager
   - Takes precedence over global credentials when connecting

3. **Connection Priority**:
   - When connecting: Checks per-host credentials first
   - If per-host credentials exist → use them
   - If not → use global credentials
   - If neither exist → show error

#### Files Modified
- `src/rdp.c` - Updated `LaunchRDP()` to check per-host credentials first
- `src/main.c` - Updated `AddHostDialogProc()` to handle per-host credentials
- `src/resources.rc` - Added per-host credential fields to Add/Edit Host dialog
- `src/resource.h` - Added new control IDs for credential fields

#### Technical Details
- Per-host credentials stored as: `WinRDP:TERMSRV/hostname`
- Global credentials stored as: `WinRDP:DefaultCredentials`
- Credential lookup uses existing `LoadRDPCredentials()` function
- Backward compatible: Existing hosts continue using global credentials
- Per-host credentials automatically cleaned up when host is deleted

#### UI Changes
- Add/Edit Host dialog now includes:
  - Checkbox: "Use custom credentials for this host"
  - Username field (shown when checkbox checked)
  - Password field (shown when checkbox checked)
  - Help text: "Leave unchecked to use global credentials"

## Previous Changes (October 31, 2025)

### 🚀 **NEW FEATURE: Active Directory / Network Scanning (Enhanced!)**

#### What It Does
- ✅ Automatically scans your network for computers
- ✅ Works with both domain-joined and workgroup computers  
- ✅ Domain/workgroup selection dialog with optional credentials
- ✅ **AUTO-ADDS discovered computers** with AD descriptions directly to CSV
- ✅ Uses Windows NetAPI32 for computer enumeration

#### How It Works
1. Click "Scan Domain" button in Host Management
2. Dialog appears asking for:
   - Domain/Workgroup name (leave empty for current)
   - Optional credentials (checkbox to enable)
3. Application scans network using `NetServerEnum`
4. **All discovered computers are automatically added** to your hosts CSV
5. Success message shows how many computers were found and added
6. Computer descriptions from Active Directory are preserved!

#### Files Added
- `src/adscan.h` - AD scanning API declarations
- `src/adscan.c` - Network scanning implementation using NetAPI32
- New dialog: `IDD_SCAN_DOMAIN` - Domain selection and credential input
- New dialog: `IDD_SCAN_RESULTS` - Optional results display (currently simplified)

#### Technical Details
- Uses `NetServerEnum` from netapi32.dll
- Domain parameter allows targeting specific domains/workgroups
- Credential fields for optional authentication (checkbox-enabled)
- Enumerates workstations and servers on the network
- **Automatically extracts and saves AD computer descriptions**
- Handles gracefully if not on a network
- Properly frees NetAPI buffers
- Includes computer type detection (Server/Workstation/DC)

### ✨ UI Improvements

#### 1. **Dark Mode Implementation**
- ✅ Automatic detection of Windows dark mode setting
- ✅ Complete dark theme for all dialogs
- ✅ Dark title bars (Windows 10 1809+)
- ✅ Professional color scheme throughout
- Files added: `src/darkmode.h`, `src/darkmode.c`

#### 2. **ListView Column Centering** 
- ✅ Both columns now perfectly centered (headers and content)
- ✅ Solution: Added 1-pixel dummy column at position 0 (Windows limitation workaround)
- ✅ Column layout: Hostname | Description
- ✅ Applied to both Main and Host Management dialogs

#### 3. **Text Box Size Optimization**
- ✅ Reduced text box heights from 22px to 18px
- ✅ More compact and proportional appearance
- ✅ Login dialog: Username and Password fields
- ✅ Main dialog: Search box

#### 4. **ListView Column Width Fix**
- ✅ Dynamic column width calculation based on actual client area
- ✅ No more unwanted wide cell on the right
- ✅ Columns perfectly fill the ListView

#### 5. **Edit Control Borders**
- ✅ Added `WS_EX_CLIENTEDGE` to all text input controls
- ✅ Better visual separation and modern 3D appearance

### 🐛 Bug Fixes

#### 1. **RDP Hostname Bug**
- **Issue**: Only first letter of hostname was being used for RDP connections
- **Cause**: Using `%s` instead of `%ls` in `fwprintf` for wide strings
- **Fixed**: Changed format specifiers in `src/rdp.c`
  - Line 85: `full address:s:%ls`
  - Line 126: `username:s:%ls`

### 🧹 Code Cleanup

#### 1. **Removed Makefile**
- ✅ Deleted `Makefile` (project uses `build.bat`)
- ✅ Updated all documentation to remove Makefile references
- ✅ Updated files:
  - `README.md`
  - `BUILD_INSTRUCTIONS.md`
  - `00_START_HERE.md`
  - `GETTING_STARTED.md`
  - `PROJECT_COMPLETE.txt`
  - `PROJECT_SUMMARY.md`
  - `UPLOAD_CHECKLIST.md`
  - `DARK_MODE_CHANGELOG.md`
  - `DARK_MODE_SUMMARY.md`

#### 2. **Build System Clarification**
- ✅ All documentation now clearly states: Use `build.bat`
- ✅ Build script auto-detects GCC (MinGW) or MSVC
- ✅ Simplified build instructions

### 📊 Statistics

**Lines of Code Added**: ~520 (dark mode + enhanced AD scanning with domain dialog)
**Files Modified**: 17+
**Files Added**: 7 (darkmode.c, darkmode.h, adscan.c, adscan.h, 3 documentation files)
**Files Deleted**: 1 (Makefile)
**Bugs Fixed**: 2 (RDP hostname, ListView columns)
**Major Features Added**: 2 (Dark Mode, Enhanced AD Scanning with auto-add)

### 🎨 Visual Impact

**Before**: 
- Standard light mode only
- Left-aligned ListView columns
- Large text boxes
- First character RDP bug

**After**:
- ✅ Automatic dark mode support
- ✅ Centered columns for symmetry
- ✅ Compact, professional text boxes
- ✅ Full hostname RDP connections
- ✅ Bordered input controls
- ✅ No extra wide cells in ListViews

### 🔧 Technical Details

#### Dark Mode Architecture
```
1. Registry detection (HKEY_CURRENT_USER\...\AppsUseLightTheme)
2. Color brush creation at startup
3. WM_CTLCOLOR* message handling
4. DWM title bar theming (Windows 10+)
5. ListView custom colors
```

#### ListView Centering Solution
```
Column 0: 1px dummy (invisible, left-aligned - Windows limitation)
Column 1: Hostname (centered)
Column 2: Description (centered)
```

### 📚 Documentation

**Complete documentation added**:
1. `DARK_MODE_IMPLEMENTATION.md` - Technical guide
2. `DARK_MODE_SUMMARY.md` - Feature overview
3. `DARK_MODE_CHANGELOG.md` - Detailed changes
4. `RECENT_UPDATES.md` - This file

### 🚀 Build & Run

```bash
# Build
.\build.bat

# Run
.\build\WinRDP.exe
```

**Build Requirements**:
- GCC (MinGW-w64) OR MSVC
- Windows SDK (included with both)
- No additional dependencies

### ✅ Quality Assurance

- ✅ Zero compiler warnings
- ✅ Clean build with GCC
- ✅ All features tested and working
- ✅ Dark mode working on Windows 10/11
- ✅ RDP connections functional
- ✅ UI properly aligned and centered
- ✅ No memory leaks in new code
- ✅ Documentation up to date

### 🎯 Result

WinRDP now features:
- Professional dark mode that follows Windows theme
- Perfectly centered and symmetrical UI
- Compact, modern controls
- Fully functional RDP connections
- Clean, maintainable codebase
- Comprehensive documentation

**Status**: Production ready! 🎉

