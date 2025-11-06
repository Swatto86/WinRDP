@echo off
REM Build WinRDP and create NSIS installer

echo ================================================
echo Building WinRDP and Creating Installer
echo ================================================

REM First, build the application
echo.
echo Step 1: Building WinRDP application...
call build.bat
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Application build failed!
    pause
    exit /b 1
)

REM Check if NSIS is available
where makensis >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo.
    echo ERROR: NSIS is not installed or not in PATH!
    echo.
    echo To install NSIS:
    echo   1. Download from: https://nsis.sourceforge.io/Download
    echo   2. Install NSIS
    echo   3. Add NSIS to your PATH, or run this script from NSIS directory
    echo.
    echo Skipping installer creation...
    echo Build complete: build\WinRDP.exe
    pause
    exit /b 0
)

REM Extract version from installer.nsi for dynamic display
for /f "tokens=3 delims= " %%a in ('findstr /C:"!define APP_VERSION" installer.nsi') do set APP_VERSION=%%a
set APP_VERSION=%APP_VERSION:"=%

REM Build the installer
echo.
echo Step 2: Creating NSIS installer...
makensis installer.nsi
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Installer creation failed!
    pause
    exit /b 1
)

echo.
echo ================================================
echo Build and Installer Creation Successful!
echo ================================================
echo.
echo Files created:
echo   - build\WinRDP.exe (application)
echo   - WinRDP-Setup-%APP_VERSION%.exe (installer)
echo.
pause

