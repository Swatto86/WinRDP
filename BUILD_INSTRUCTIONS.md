# Build Instructions for WinRDP

## Prerequisites

You need a C compiler. Choose one of the following:

### Option 1: MinGW-w64 (GCC for Windows) - Recommended

1. **Download MSYS2**: https://www.msys2.org/
2. **Install MSYS2** and follow the instructions
3. **Open MSYS2 MinGW 64-bit terminal** and run:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
4. **Add to PATH**: Add `C:\msys64\mingw64\bin` to your Windows PATH

### Option 2: Visual Studio

1. Download Visual Studio 2019 or later
2. Install with "Desktop development with C++" workload
3. Use "x64 Native Tools Command Prompt for VS"

## Building the Project

### Method 1: Using the Build Script (Recommended)

Simply double-click `build.bat` or run in PowerShell/CMD:
```cmd
.\build.bat
```

The script will:
- Detect your compiler (GCC or MSVC)
- Create build directories
- Compile all source files
- Link the executable
- Report success or errors

### Method 2: Manual Compilation

#### Using GCC (MinGW):
```cmd
REM Create directories
mkdir build build\obj

REM Compile source files
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/main.c -o build/obj/main.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/utils.c -o build/obj/utils.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/credentials.c -o build/obj/credentials.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/hosts.c -o build/obj/hosts.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/rdp.c -o build/obj/rdp.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/registry.c -o build/obj/registry.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/darkmode.c -o build/obj/darkmode.o
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c src/adscan.c -o build/obj/adscan.o

REM Compile resources
windres src/resources.rc -o build/obj/resources.o

REM Link everything
gcc -mwindows -municode -o build/WinRDP.exe build/obj/*.o -lcomctl32 -lole32 -lshell32 -ladvapi32 -lcredui -lcomdlg32 -ldwmapi -luxtheme -lnetapi32
```

#### Using Visual Studio:
```cmd
REM Open "x64 Native Tools Command Prompt for VS"
cd src

REM Compile
cl /W4 /D_UNICODE /DUNICODE /D_WIN32_WINNT=0x0601 /c *.c resources.rc

REM Link
link /OUT:..\build\WinRDP.exe /SUBSYSTEM:WINDOWS *.obj resources.res ^
     user32.lib gdi32.lib shell32.lib comctl32.lib advapi32.lib credui.lib comdlg32.lib ole32.lib dwmapi.lib uxtheme.lib netapi32.lib

REM Clean up
del *.obj *.res
cd ..
```

## Troubleshooting

### "gcc: command not found"
- Make sure MinGW bin directory is in your PATH
- Or use `build.bat` which tries to detect compilers automatically

### "windres: command not found"
- windres comes with MinGW, ensure you installed the full toolchain
- If using MSVC, use `rc.exe` instead

### Linker errors about missing libraries
Make sure you have the Windows SDK installed (comes with Visual Studio or MinGW)

### "Cannot find commctrl.h"
You need the Windows headers. These come with:
- MinGW-w64 (not the old MinGW.org version)
- Windows SDK (with Visual Studio)

## Running the Application

After successful build:
```cmd
.\build\WinRDP.exe
```

Or double-click `build\WinRDP.exe` in File Explorer.

The application will:
1. Show a system tray icon
2. Display a login dialog for entering default RDP credentials
3. Allow you to manage and connect to RDP servers

## Development Tips

### Enable Debug Output
Add this to see debug messages:
```c
OutputDebugStringW(L"Your debug message\n");
```

View with [DebugView](https://docs.microsoft.com/en-us/sysinternals/downloads/debugview) from Sysinternals.

### Hot Reload While Developing
After making changes:
1. Close the running application
2. Run `build.bat` again
3. Test your changes

### Debugging with GDB
```bash
# Run with GDB
gdb build/WinRDP.exe
```

### Debugging with Visual Studio
1. Open Visual Studio
2. File > Open > Project/Solution
3. Select `WinRDP.exe`
4. Set breakpoints and press F5

## Clean Build

To remove all compiled files and start fresh:

```cmd
rmdir /s /q build
```

Then run `build.bat` again to rebuild.

## File Structure After Build

```
WinRDP/
├── build/
│   ├── obj/           <- Object files (.o)
│   └── WinRDP.exe     <- Final executable
├── src/               <- Source code
├── build.bat          <- Build script
└── README.md
```

## Next Steps

After building, see [README.md](README.md) for:
- Usage instructions
- WinAPI concepts explained
- Extension ideas for learning

