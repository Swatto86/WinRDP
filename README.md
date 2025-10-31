# WinRDP - Educational Windows API Project

A lightweight Remote Desktop (RDP) connection manager written in **pure C** using the **Windows API**. This project is designed as a learning resource for understanding Windows programming concepts.

## 🎯 Learning Objectives

This project demonstrates:

- **Window Management** - Creating windows, dialog boxes, and message handling
- **System Tray Programming** - Adding icons to the notification area
- **Credential Manager API** - Secure password storage using Windows Credential Manager
- **Registry Operations** - Reading and writing to the Windows Registry
- **File I/O** - CSV file handling with Unicode support
- **Process Launching** - Starting applications with ShellExecuteW
- **ListView Controls** - Working with common controls

## 📋 Features

- Store and manage RDP server connections
- Secure credential storage using Windows Credential Manager
- Quick connect to saved servers
- Search functionality for hosts
- **Network Computer Scanning** - Automatically discover computers on your network
- System tray icon for quick access
- Autostart with Windows (optional)
- **Dark Mode Support** - Automatically follows Windows theme
- Pure C with no external dependencies (except Windows SDK)

## 🔧 Prerequisites

To build this project, you need:

### Option 1: MinGW-w64 (GCC for Windows)
```bash
# Install via MSYS2 (recommended)
pacman -S mingw-w64-x86_64-gcc
```

### Option 2: Microsoft Visual Studio
- Visual Studio 2019 or later with C++ Desktop Development workload
- Windows SDK

## 🏗️ Building the Project

### Using the Build Script (Recommended)
```bash
# Navigate to project directory
cd WinRDP

# Build (automatically detects GCC or MSVC)
.\build.bat

# Run
.\build\WinRDP.exe
```

The `build.bat` script will automatically detect whether you have GCC (MinGW) or MSVC installed and use the appropriate compiler.

## 📚 Code Structure

```
WinRDP/
├── src/
│   ├── main.c          - Entry point, window procedures, UI logic
│   ├── credentials.c   - Windows Credential Manager integration
│   ├── hosts.c         - Host list management (CSV file I/O)
│   ├── rdp.c          - RDP file generation and launching
│   ├── registry.c      - Windows Registry operations
│   ├── darkmode.c      - Dark mode detection and theming
│   ├── utils.c         - Utility functions (centering windows, etc.)
│   ├── resources.rc    - Dialog definitions, menus, strings
│   ├── resource.h      - Resource identifiers
│   ├── config.h        - Application configuration
│   └── *.h            - Header files
├── build/             - Compiled output (created by build.bat)
├── build.bat          - Windows build script
└── README.md          - This file
```

## 🎓 WinAPI Concepts Demonstrated

### 1. **Window Creation and Message Loop**
```c
// Creating a window
HWND hwnd = CreateWindowExW(
    0, L"ClassName", L"Title",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    640, 480,
    NULL, NULL, hInstance, NULL);

// Message loop
MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

**Files**: `main.c` (WinMain, WndProc)

### 2. **Dialog Boxes**
```c
// Create a modal dialog
INT_PTR result = DialogBox(
    hInstance,
    MAKEINTRESOURCE(IDD_LOGIN),
    hwndParent,
    LoginDialogProc);
```

**Files**: `main.c` (dialog procedures), `resources.rc` (dialog definitions)

### 3. **System Tray Icons**
```c
// Add icon to system tray
NOTIFYICONDATA nid = {0};
nid.cbSize = sizeof(NOTIFYICONDATA);
nid.hWnd = hwnd;
nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
nid.uCallbackMessage = WM_TRAYICON;
Shell_NotifyIcon(NIM_ADD, &nid);
```

**Files**: `main.c` (InitSystemTray)

### 4. **Credential Manager**
```c
// Save credentials securely
CREDENTIALW cred = {0};
cred.Type = CRED_TYPE_GENERIC;
cred.TargetName = L"MyApp:Credential";
cred.UserName = L"username";
cred.CredentialBlob = (LPBYTE)password;
cred.CredentialBlobSize = wcslen(password) * sizeof(wchar_t);
CredWriteW(&cred, 0);

// Read credentials
PCREDENTIALW pcred;
CredReadW(L"MyApp:Credential", CRED_TYPE_GENERIC, 0, &pcred);
// Use pcred->UserName and pcred->CredentialBlob
CredFree(pcred);
```

**Files**: `credentials.c`

### 5. **Registry Operations**
```c
// Open registry key
HKEY hKey;
RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\MyApp", 0, KEY_READ, &hKey);

// Read value
DWORD value;
DWORD size = sizeof(DWORD);
RegQueryValueExW(hKey, L"Setting", NULL, NULL, (LPBYTE)&value, &size);

// Write value
RegSetValueExW(hKey, L"Setting", 0, REG_DWORD, (LPBYTE)&value, sizeof(DWORD));

RegCloseKey(hKey);
```

**Files**: `registry.c`

### 6. **Launching Applications**
```c
// Launch an application
ShellExecuteW(
    NULL,
    L"open",
    L"notepad.exe",
    L"file.txt",
    NULL,
    SW_SHOWNORMAL);
```

**Files**: `rdp.c` (LaunchRDP)

### 7. **ListView Controls**
```c
// Create columns
LVCOLUMN col = {0};
col.mask = LVCF_TEXT | LVCF_WIDTH;
col.pszText = L"Column Name";
col.cx = 150;
ListView_InsertColumn(hListView, 0, &col);

// Add items
LVITEM item = {0};
item.mask = LVIF_TEXT;
item.iItem = 0;
item.pszText = L"Item Text";
ListView_InsertItem(hListView, &item);
```

**Files**: `main.c` (MainDialogProc, HostDialogProc)

### 8. **Dark Mode Support**
```c
// Detect Windows dark mode
BOOL IsDarkModeEnabled(void);

// Apply dark mode to dialogs
void ApplyDarkModeToDialog(HWND hwnd);

// Handle control color messages
INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Dark title bar (Windows 10 1903+)
BOOL darkMode = TRUE;
DwmSetWindowAttribute(hwnd, 20, &darkMode, sizeof(darkMode));
```

**Files**: `darkmode.c`, `darkmode.h`

## 🔐 Security Notes

- Credentials are stored using Windows Credential Manager (encrypted)
- RDP files are created in the temp directory and deleted after use
- File I/O uses secure functions (_s versions)

## 🐛 Debugging Tips

1. **Use DebugView** (Sysinternals):
   Add `OutputDebugString()` calls to see debug output:
   ```c
   OutputDebugStringW(L"Debug message here\n");
   ```

2. **Check Windows Event Viewer**:
   Some errors are logged to Windows Event Log.

3. **Visual Studio Debugger**:
   Open the built executable in Visual Studio or use `windbg` for advanced debugging.

## 📖 Additional Resources

- [Windows API Documentation](https://docs.microsoft.com/en-us/windows/win32/api/)
- [Charles Petzold's "Programming Windows"](https://www.charlespetzold.com/pw5/) - Classic book
- [theForger's Win32 API Tutorial](http://www.winprog.org/tutorial/) - Great for beginners
- [RDP File Format](https://docs.microsoft.com/en-us/windows-server/remote/remote-desktop-services/clients/rdp-files)

## 📝 License

This is a learning project released into the public domain. Feel free to use, modify, and distribute as you wish.

## 🎯 Future Exercise Ideas

Want to extend your learning? Try adding:

1. **Import/Export** - Save hosts to JSON or XML
2. **Grouping** - Organize hosts into groups/folders
3. **Connection History** - Log successful connections
4. **Custom RDP Settings** - Per-host resolution, color depth, etc.
5. **LDAP Integration** - Scan Active Directory for servers
6. ✅ **Dark Mode** - Support Windows dark theme (IMPLEMENTED!)
7. **Hotkeys** - Global hotkeys to show/hide window
8. **Multi-monitor Support** - Choose which monitor for RDP
9. **Port Scanning** - Check if port 3389 is open
10. **Encryption** - Additional encryption layer for CSV file

## 🙏 Acknowledgments

This project was created as an educational resource for learning Windows API programming in C. It's inspired by the need for a simple, transparent RDP manager that demonstrates core Windows programming concepts.

Happy coding! 🚀

