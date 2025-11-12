# WinRDP

> **🤖 AI-Generated Project:** This entire application and its 30-chapter educational book were written by AI with direction from Swatto. The project demonstrates that AI can help us return to efficient, framework-free software development. Real coding experience was essential for providing effective guidance to the AI.

A simple RDP connection manager written in **pure C** using the **Windows API**. Built to solve the problem of managing too many servers and passwords, while serving as a comprehensive learning resource for Windows programming.

**Directed by Swatto • Built with AI**

---

## 📑 Table of Contents
- [Quick Start](#-quick-start)
- [What You'll Learn](#-what-youll-learn)
- [Features](#-what-it-does)
- [Building It Yourself](#-building-it-yourself)
- [Documentation](#-documentation)
- [Windows API Examples](#-windows-api-examples)
- [Security](#-security-stuff)
- [Extending It](#-ideas-for-extending-it)

---

## 🚀 Quick Start

### For Users
1. Download [WinRDP-Setup-1.5.0.exe](https://github.com/Swatto86/WinRDP/releases/latest)
2. Run the installer
3. Launch from Start Menu or system tray
4. Set your credentials and add servers

### For Developers
```bash
git clone https://github.com/Swatto86/WinRDP.git
cd WinRDP
.\build.bat
.\build\WinRDP.exe
```

See [BUILD.md](BUILD.md) for detailed build instructions.

---

## 🎯 What You'll Learn

If you dig into the code, you'll see examples of:

**C Language Stuff:**
- **Pointers & Memory Management** - malloc, realloc, free, pointer-to-pointer
- **Structures** - typedef struct, nested structures
- **Function Pointers** - Callbacks and Windows message handlers
- **Wide Character Strings** - Unicode support with wchar_t

**Windows API Stuff:**
- **Window Management** - Creating windows, dialog boxes, message handling
- **System Tray** - Putting icons in the notification area
- **Global Hotkeys** - Ctrl+Shift+R to show/hide from anywhere
- **Credential Manager** - Storing passwords securely with Windows
- **Registry Operations** - Reading and writing registry keys
- **File I/O** - CSV files with Unicode
- **Launching Programs** - Starting RDP sessions with ShellExecuteW
- **ListView Controls** - Those nice sortable lists
- **Network APIs** - Scanning for computers on the network

## 📋 What It Does

### Main Features
- **Manage RDP Connections** - Keep all your servers in one list
- **Persistent RDP Files** - Saves connection files so you don't get security warnings
  - No more "do you trust this publisher?" every time
  - Files stored in %APPDATA%\Roaming\WinRDP\Connections
  - Each server gets its own reusable RDP file
- **Global Credentials** - Set your username/password once, use everywhere
  - Edit them anytime with the button on the main window
  - Switch accounts without restarting
  - Smart timer that hides the window if you don't need it
- **Per-Host Credentials** - Override for specific servers that need different logins
  - Optional per-server username/password
  - Falls back to your global credentials if not set
- **Secure Storage** - Uses Windows Credential Manager for passwords
  - Windows encrypts everything
  - Host list file encrypted with DPAPI (v1.4.0+)
- **Quick Connect** - Double-click to connect
- **Search** - Type to filter your server list
- **System Tray** - Lives in your notification area
- **Autostart** - Can launch with Windows if you want
- **Dark Mode** - Follows your Windows theme
  - Looks good whether you're in light or dark mode

### Extra Stuff
- **Toggle Hotkey (Ctrl+Shift+R)** - Show/hide from anywhere
  - Works even when you're in other apps
  - Press once to show, press again to hide
- **Network Scanning** - Find computers on your network
  - Scan your domain or workgroup
  - Filter by type: Workstations, Servers, Domain Controllers
  - Automatically adds them with their descriptions
  - Uses the NetServerEnum API
- **Bulk Delete (Ctrl+Shift+Alt+D)** - Nuke everything
  - Secret hotkey to wipe all hosts and credentials
  - Asks twice to make sure you mean it
  - Only works in the Host Management dialog
- **Dark Mode** - Looks good in dark theme
  - Automatically follows your Windows theme
  - Dark title bars and controls

### Technical Bits
- Pure C, no dependencies except Windows SDK
- Comes with an NSIS installer
- 64-bit
- Memory-safe (I tried, anyway)

## 🔧 Building It Yourself

You'll need a C compiler. Pick one:

### Option 1: MinGW-w64 (GCC for Windows)
```bash
# Install via MSYS2
pacman -S mingw-w64-x86_64-gcc
```

### Option 2: Visual Studio
- Visual Studio 2019 or newer with C++ stuff
- Windows SDK

## 📚 Documentation

**Essential Docs:**
- **README.md** (this file) - Overview, features, and usage
- **BUILD.md** - Build instructions and installation
- **CHANGELOG.md** - Version history and planned features

**Learning:**
- **C_PROGRAMMING_BOOK.md** - Complete 30-chapter C programming guide
- **Source code** - Extensively commented for educational purposes

## 🏗️ How to Build

### Easy way (use the script)
```bash
cd WinRDP

# Build it (detects GCC or MSVC automatically)
.\build.bat

# Run it
.\build\WinRDP.exe
```

The build script figures out which compiler you have and uses it.

### Making the Installer
```bash
# Build everything and create installer
.\build-installer.bat
```

This spits out `WinRDP-Setup-1.5.0.exe` that you can share.

See [BUILD.md](BUILD.md) for more details.

## 📁 How It's Organized

```
WinRDP/
├── src/
│   ├── main.c          - Entry point, window procedures, UI logic
│   ├── credentials.c   - Windows Credential Manager integration
│   ├── hosts.c         - Host list management (CSV file I/O)
│   ├── rdp.c          - RDP file generation and launching
│   ├── registry.c      - Windows Registry operations
│   ├── darkmode.c      - Dark mode detection and theming
│   ├── adscan.c        - Active Directory/network computer discovery
│   ├── utils.c         - Utility functions (centering windows, etc.)
│   ├── resources.rc    - Dialog definitions, menus, strings
│   ├── resource.h      - Resource identifiers
│   ├── config.h        - Application configuration
│   └── *.h            - Header files
├── build/             - Compiled output (created by build.bat)
├── build.bat          - Windows build script
├── build-installer.bat - Build application + installer
├── installer.nsi      - NSIS installer script
├── hosts.csv          - Sample host list
└── README.md          - This file
```

## 🎓 Windows API Examples

### 1. Creating Windows and the Message Loop
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

### 2. Dialog Boxes
```c
// Create a modal dialog
INT_PTR result = DialogBox(
    hInstance,
    MAKEINTRESOURCE(IDD_LOGIN),
    hwndParent,
    LoginDialogProc);
```

**Files**: `main.c` (dialog procedures), `resources.rc` (dialog definitions)

### 3. System Tray Icons
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

### 4. Credential Manager
```c
// Save credentials securely (global or per-host)
CREDENTIALW cred = {0};
cred.Type = CRED_TYPE_GENERIC;
cred.TargetName = L"MyApp:Credential";  // Or L"MyApp:TERMSRV/hostname" for per-host
cred.UserName = L"username";
cred.CredentialBlob = (LPBYTE)password;
cred.CredentialBlobSize = wcslen(password) * sizeof(wchar_t);
CredWriteW(&cred, 0);

// Read credentials (checks per-host first, falls back to global)
// Per-host: LoadRDPCredentials(hostname, username, password)
// Global: LoadCredentials(NULL, username, password)
PCREDENTIALW pcred;
CredReadW(L"MyApp:Credential", CRED_TYPE_GENERIC, 0, &pcred);
// Use pcred->UserName and pcred->CredentialBlob
CredFree(pcred);
```

**Files**: `credentials.c`, `rdp.c`

**Credential Strategy**:
- Global credentials: Stored once at application launch, used for all hosts by default
- Per-host credentials: Optional individual credentials for specific hosts
- When connecting: Per-host credentials are checked first, then fall back to global

### 5. Registry Operations
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

### 6. Network Computer Discovery
```c
// Scan network for computers using NetServerEnum
NET_API_STATUS status = NetServerEnum(
    NULL,                    // Local computer
    101,                     // Information level
    (LPBYTE*)&pBuf,         // Buffer for results
    MAX_PREFERRED_LENGTH,    // Maximum data
    &entriesRead,           // Entries read
    &totalEntries,          // Total entries
    SV_TYPE_ALL,            // Server types
    NULL,                   // Domain (NULL = current)
    NULL);                  // Resume handle

// Access computer information
for (i = 0; i < entriesRead; i++) {
    wchar_t* name = pBuf[i].sv101_name;
    wchar_t* comment = pBuf[i].sv101_comment;
    DWORD type = pBuf[i].sv101_type;
    // Filter by type: workstation, server, domain controller
}
NetApiBufferFree(pBuf);
```

**Files**: `adscan.c`, `adscan.h`

### 7. Launching Applications
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

### 8. ListView Controls
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

### 9. Dark Mode Support
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

## 🔐 Security Stuff

- **Passwords** are stored in Windows Credential Manager (encrypted by Windows)
- **Your host list** (hosts.csv) is encrypted with DPAPI (v1.4.0+)
  - Machine-level encryption - works for autostart
  - Can't be decrypted on a different computer
  - Encrypts/decrypts automatically
  - Works with old unencrypted files too
- **RDP files** live in %APPDATA%\Roaming\WinRDP\Connections
  - Stops those annoying security warnings
  - Each Windows user has their own
  - You can delete them manually if you want
- I use the secure versions of file functions (_s versions)

## 🐛 If Something Breaks

1. **Use DebugView** (from Sysinternals):
   I put `OutputDebugString()` calls in the code:
   ```c
   OutputDebugStringW(L"Debug message here\n");
   ```

2. **Check Event Viewer**:
   Some errors show up in the Windows Event Log.

3. **Use a debugger**:
   Visual Studio or windbg if you want to go deep.

## 📖 Useful Links

- [Windows API Docs](https://docs.microsoft.com/en-us/windows/win32/api/) - Official reference
- [Charles Petzold's "Programming Windows"](https://www.charlespetzold.com/pw5/) - The classic book
- [theForger's Win32 Tutorial](http://www.winprog.org/tutorial/) - Good for beginners
- [RDP File Format](https://docs.microsoft.com/en-us/windows-server/remote/remote-desktop-services/clients/rdp-files) - If you want to customize

## 📝 License

MIT License. Use it however you want.

## 📦 Installing

There's an installer:
- Download `WinRDP-Setup-1.5.0.exe`
- Double-click it
- Find it in your system tray or Start Menu
- Check "About" in the tray menu if you want to know who made it

See [BUILD.md](BUILD.md) for how to build your own.

## 🎯 Ideas for Extending It

Want to add more stuff? Here are some ideas:

1. **Import/Export** - Save/load hosts as JSON or XML
2. **Folders** - Group your hosts
3. **History Log** - Track when you connected to what
4. **Custom RDP Options** - Per-host resolution, color depth, etc.
5. **LDAP** - Deeper Active Directory integration
6. ✅ **Dark Mode** - Done!
7. ✅ **Global Hotkey** - Done!
8. ✅ **Network Scanning** - Done!
9. ✅ **Per-Host Credentials** - Done!
10. **Multi-monitor** - Pick which screen for RDP
11. **Port Scanner** - Check if 3389 is open before connecting
12. ✅ **Encryption** - Done!
13. **Ping Status** - Show which hosts are online

## 🙏 About This Project

WinRDP was created with AI assistance to demonstrate that modern software can be built without framework bloat. This project serves as both a practical tool and an extensive learning resource. All the code is commented and explained so you can see how everything works.

## 🤝 Contributing

Found a bug? Want to add a feature? Contributions are welcome!

1. Check the [planned features](CHANGELOG.md#upcoming-features-planned) in CHANGELOG.md
2. Fork the repository
3. Create a feature branch
4. Make your changes with clear commit messages
5. Test thoroughly on Windows 7+
6. Submit a pull request

For major changes, open an issue first to discuss what you'd like to change.

---

**Directed by Swatto • Built with AI**

Hope you find it useful! 🚀

