; WinRDP Installer Script for NSIS
; Created for Swatto
; 
; This installer is built for 64-bit Windows applications
; The x64.nsh include ensures correct installation to Program Files
; (not Program Files (x86)) on 64-bit systems

!define APP_NAME "WinRDP"
!define APP_VERSION "1.1.0"
!define COMPANY_NAME "Swatto"
!define APP_PUBLISHER "Swatto"
!define EXE_NAME "WinRDP.exe"
!define INSTALLER_NAME "WinRDP-Setup-1.1.0.exe"

; Compressor settings
SetCompressor /SOLID lzma
SetCompressorDictSize 32

; Platform detection - include early for proper 64-bit detection
!include "x64.nsh"

; Include Modern UI
!include "MUI2.nsh"

; General Settings
Name "${APP_NAME}"
OutFile "${INSTALLER_NAME}"
Unicode True

; Default installation folder - will be set explicitly in .onInit
InstallDir "$PROGRAMFILES\${APP_NAME}"

; Get installation folder from registry if available
InstallDirRegKey HKCU "Software\${APP_NAME}" "InstallPath"

; Request admin privileges for Windows Vista and higher
RequestExecutionLevel admin

; Initialize installer - ensure correct 64-bit path
Function .onInit
    ${If} ${RunningX64}
        ; Force 64-bit Program Files path explicitly (not redirected)
        StrCpy $INSTDIR "C:\Program Files\${APP_NAME}"
    ${Else}
        ; Fallback for 32-bit Windows (rare)
        StrCpy $INSTDIR "C:\Program Files\${APP_NAME}"
    ${EndIf}
FunctionEnd

; Interface Settings
!define MUI_ABORTWARNING
!define MUI_ICON "${NSISDIR}\Contrib\Graphics\Icons\modern-install.ico"
!define MUI_UNICON "${NSISDIR}\Contrib\Graphics\Icons\modern-uninstall.ico"

; Welcome/Finish page settings
!define MUI_WELCOMEPAGE_TITLE "Welcome to ${APP_NAME} Installer"
!define MUI_WELCOMEPAGE_TEXT "This will install ${APP_NAME} ${APP_VERSION} on your computer.$\r$\n$\r$\nCreated by Swatto"

!define MUI_FINISHPAGE_RUN "$INSTDIR\${EXE_NAME}"
!define MUI_FINISHPAGE_RUN_TEXT "Run ${APP_NAME} now"

; License page (optional - uncomment if you have a license file)
; !define MUI_LICENSEPAGE_CHECKBOX
; !insertmacro MUI_PAGE_LICENSE "LICENSE.txt"

; Installer pages
!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

; Uninstaller pages
!insertmacro MUI_UNPAGE_WELCOME
!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES
!insertmacro MUI_UNPAGE_FINISH

; Language files
!insertmacro MUI_LANGUAGE "English"

; Installer
Section "MainSection" SEC01
    SetOutPath "$INSTDIR"
    
    ; Copy the application files
    File "build\${EXE_NAME}"
    
    ; Copy hosts.csv with example entries for first-time users
    File "hosts.csv"
    
    ; Create uninstaller
    WriteUninstaller "$INSTDIR\Uninstall.exe"
    
    ; Registry entries
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayName" "${APP_NAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayIcon" "$INSTDIR\${EXE_NAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "UninstallString" "$INSTDIR\Uninstall.exe"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "Publisher" "${APP_PUBLISHER}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "DisplayVersion" "${APP_VERSION}"
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "NoModify" 1
    WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" "NoRepair" 1
    
    ; Store installation folder
    WriteRegStr HKCU "Software\${APP_NAME}" "InstallPath" "$INSTDIR"
    
    ; Create Start Menu shortcuts
    CreateDirectory "$SMPROGRAMS\${APP_NAME}"
    CreateShortCut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\${EXE_NAME}"
    CreateShortCut "$SMPROGRAMS\${APP_NAME}\Uninstall ${APP_NAME}.lnk" "$INSTDIR\Uninstall.exe"
    
    ; Create Desktop shortcut (optional - comment out if not desired)
    ; CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${EXE_NAME}"
SectionEnd

; Uninstaller
Section "Uninstall"
    ; Remove files
    Delete "$INSTDIR\${EXE_NAME}"
    Delete "$INSTDIR\Uninstall.exe"
    Delete "$INSTDIR\hosts.csv"
    
    ; Remove shortcuts
    Delete "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk"
    Delete "$SMPROGRAMS\${APP_NAME}\Uninstall ${APP_NAME}.lnk"
    ; Delete "$DESKTOP\${APP_NAME}.lnk"
    
    ; Remove Start Menu folder
    RMDir "$SMPROGRAMS\${APP_NAME}"
    
    ; Remove installation directory if empty
    RMDir "$INSTDIR"
    
    ; Remove registry entries
    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}"
    DeleteRegKey HKCU "Software\${APP_NAME}"
SectionEnd

