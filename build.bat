@echo off
REM WinRDP Build Script for Windows
REM This script compiles the project using GCC (MinGW) or MSVC

echo ================================================
echo Building WinRDP - Educational WinAPI Project
echo ================================================

REM Check if build directory exists
if not exist "build" mkdir build
if not exist "build\obj" mkdir build\obj

REM Try to find GCC first
where gcc >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Using GCC compiler...
    goto :build_gcc
)

REM Try MSVC
where cl >nul 2>nul
if %ERRORLEVEL% EQU 0 (
    echo Using MSVC compiler...
    goto :build_msvc
)

echo ERROR: No compiler found!
echo Please install either:
echo   - MinGW-w64 GCC: https://www.mingw-w64.org/
echo   - Visual Studio with C++ tools
pause
exit /b 1

:build_gcc
echo.
echo Compiling source files...

REM Compile C files
for %%f in (src\*.c) do (
    echo Compiling %%f...
    gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE -c %%f -o build\obj\%%~nf.o
    if %ERRORLEVEL% NEQ 0 (
        echo ERROR: Compilation failed for %%f
        pause
        exit /b 1
    )
)

REM Compile resources
echo Compiling resources...
windres src\resources.rc -o build\obj\resources.o
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Resource compilation failed
    pause
    exit /b 1
)

REM Link
echo.
echo Linking...
gcc -mwindows -municode -o build\WinRDP.exe build\obj\*.o -lcomctl32 -lole32 -lshell32 -ladvapi32 -lcredui -lcomdlg32 -ldwmapi -luxtheme
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Linking failed
    pause
    exit /b 1
)

echo.
echo ================================================
echo Build successful!
echo Executable: build\WinRDP.exe
echo ================================================
pause
exit /b 0

:build_msvc
echo.
echo Compiling with MSVC...
cd src
cl /W4 /D_UNICODE /DUNICODE /D_WIN32_WINNT=0x0601 /c *.c resources.rc
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Compilation failed
    cd ..
    pause
    exit /b 1
)

echo Linking...
link /OUT:..\build\WinRDP.exe /SUBSYSTEM:WINDOWS *.obj resources.res ^
     user32.lib gdi32.lib shell32.lib comctl32.lib advapi32.lib credui.lib comdlg32.lib ole32.lib dwmapi.lib uxtheme.lib

if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Linking failed
    cd ..
    pause
    exit /b 1
)

REM Clean up intermediate files
del *.obj *.res
cd ..

echo.
echo ================================================
echo Build successful!
echo Executable: build\WinRDP.exe
echo ================================================
pause
exit /b 0

