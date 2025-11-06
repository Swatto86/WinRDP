# WinRDP Build & Installation Guide

Complete guide for building WinRDP from source and creating the installer.

---

## For End Users: Quick Installation

### Installing WinRDP

1. Download `WinRDP-Setup-1.2.0.exe`
2. Double-click to run the installer
3. Follow the wizard
4. WinRDP installs to `C:\Program Files\WinRDP\`
5. Launch from Start Menu or system tray

### Uninstalling

1. Windows Settings → Apps → WinRDP → Uninstall
2. OR Start Menu → WinRDP → Uninstall WinRDP

---

## For Developers: Building from Source

### Prerequisites

**Choose a compiler:**

**Option 1: MinGW-w64 (GCC) - Recommended**
```bash
# Install via MSYS2
pacman -S mingw-w64-x86_64-gcc

# Add to PATH
# C:\msys64\mingw64\bin
```

**Option 2: Visual Studio**
- Download Visual Studio 2019+
- Install "Desktop development with C++" workload
- Use "x64 Native Tools Command Prompt"

---

## Building the Application

### Quick Build

**Automated (Recommended):**
```cmd
build.bat
```

**Manual (GCC):**
```cmd
mkdir build build\obj
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/*.c -o build/obj/*.o
windres src\resources.rc -o build\obj\resources.o
gcc -mwindows -municode -o build\WinRDP.exe build\obj\*.o -lcomctl32 -lole32 -lshell32 -ladvapi32 -lcredui -lcomdlg32 -ldwmapi -luxtheme -lnetapi32
```

**Manual (MSVC):**
```cmd
cd src
cl /W4 /D_UNICODE /DUNICODE /D_WIN32_WINNT=0x0601 /c *.c resources.rc
link /OUT:..\build\WinRDP.exe /SUBSYSTEM:WINDOWS *.obj resources.res user32.lib gdi32.lib shell32.lib comctl32.lib advapi32.lib credui.lib comdlg32.lib ole32.lib dwmapi.lib uxtheme.lib netapi32.lib
del *.obj *.res
cd ..
```

---

## Creating the Installer

### Prerequisites

Install NSIS:
- Download: https://nsis.sourceforge.io/Download
- Add NSIS to system PATH

### Build Installer

**Automated (Recommended):**
```cmd
build-installer.bat
```

**Manual:**
```cmd
# First build the application
build.bat

# Then create installer
makensis installer.nsi
```

### Output

- `build\WinRDP.exe` - Application executable
- `WinRDP-Setup-1.2.0.exe` - Distribution installer

---

## Installer Features

✅ Modern installation wizard  
✅ 64-bit installation (correct Program Files location)  
✅ Start Menu shortcuts  
✅ Uninstaller integration  
✅ Registry integration (Add/Remove Programs)  
✅ Author attribution (Swatto)  

---

## Troubleshooting

### "gcc not found"
- Install MinGW or use Visual Studio
- Verify PATH includes compiler bin directory

### "windres not found"
- Install MinGW-w64 (not old MinGW.org)
- Ensure PATH includes windres.exe

### "makensis not found"
- Install NSIS
- Add NSIS to system PATH

### "Cannot find commctrl.h"
- Install Windows SDK
- Install MinGW-w64 or Visual Studio

### Build warnings
- Most warnings are informational
- Check build.bat output for actual errors
- Verify all dependencies installed

---

## Technical Details

### Architecture
- **Platform:** Windows 7+ (64-bit)
- **Compiler:** GCC or MSVC
- **Standard:** C11
- **Libraries:** Windows SDK only

### Libraries Used
- `comctl32` - Common controls (ListView)
- `shell32` - Shell functions, system tray
- `advapi32` - Registry, Credential Manager
- `credui` - Credential UI
- `ole32` - COM/OLE support
- `dwmapi` - Desktop window manager
- `uxtheme` - Visual themes
- `netapi32` - Network enumeration

### Flags & Options
- `-mwindows` - GUI application (no console)
- `-municode` - Unicode entry point
- `-DUNICODE -D_UNICODE` - Unicode strings
- `-D_WIN32_WINNT=0x0601` - Windows 7+ APIs

---

**Created by Swatto**  
Professional Windows API Learning Project

