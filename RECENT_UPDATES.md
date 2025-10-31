# Recent Updates to WinRDP

## Latest Changes (October 31, 2025)

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

**Lines of Code Added**: ~220 (dark mode implementation)
**Files Modified**: 15+
**Files Added**: 5 (darkmode.c, darkmode.h, 3 documentation files)
**Files Deleted**: 1 (Makefile)
**Bugs Fixed**: 2 (RDP hostname, ListView columns)

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

