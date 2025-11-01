# WinRDP Application Flow Diagram

This document visualizes how all components of WinRDP link together, helping you understand the big picture of the application architecture.

## Table of Contents
1. [Application Startup Flow](#application-startup-flow)
2. [Component Architecture](#component-architecture)
3. [Data Flow Diagrams](#data-flow-diagrams)
4. [User Interaction Flows](#user-interaction-flows)
5. [Module Dependencies](#module-dependencies)
6. [Message Flow](#message-flow)

---

## Application Startup Flow

```
Application Starts (wWinMain Entry Point)
    │
    ├─> Check Single Instance (Create Mutex)
    │
    ├─> Initialize Common Controls (ListView)
    │
    ├─> Initialize Dark Mode (darkmode.c)
    │
    ├─> Register Window Class (WndProc)
    │
    ├─> Create Main Window (Hidden, for messages)
    │
    ├─> Initialize System Tray Icon (ShellAPI)
    │
    ├─> Register Global Hotkey (Ctrl+Shift+R)
    │
    ├─> Show Login Dialog (LoginDialogProc)
    │
    └─> Enter Message Loop (GetMessage/Translate)
        └─> Application runs and processes messages
```

---

## Component Architecture

```
WINRDP APPLICATION
│
├── MAIN MODULE (main.c)
│   │
│   ├── Entry Point & Window Management
│   │   • wWinMain() - Application entry point
│   │   • WndProc() - Main window message handler
│   │   • Message loop (GetMessage/DispatchMessage)
│   │
│   └── Dialog Procedures
│       • LoginDialogProc() - Credentials dialog
│       • MainDialogProc() - Server list dialog
│       • HostDialogProc() - Host management dialog
│       • AddHostDialogProc() - Add/edit host dialog
│       • ScanDomainDialogProc() - Network scan options
│       • System tray management
│
├── Core Modules
│   │
│   ├── credentials.c
│   │   • SaveCredentials() - Save global credentials
│   │   • LoadCredentials() - Load global credentials
│   │   • SaveRDPCredentials() - Save per-host credentials
│   │   • LoadRDPCredentials() - Load per-host credentials
│   │   • DeleteCredentials() - Delete credentials
│   │
│   ├── hosts.c
│   │   • LoadHosts() - Read hosts from CSV
│   │   • AddHost() - Add new host
│   │   • DeleteHost() - Remove host
│   │   • FreeHosts() - Free memory
│   │
│   ├── rdp.c
│   │   • CreateRDPFile() - Generate RDP connection file
│   │   • LaunchRDPWithDefaults() - Launch RDP connection
│   │
│   └── registry.c
│       • EnableAutostart() - Add to Windows startup
│       • DisableAutostart() - Remove from startup
│       • IsAutostartEnabled() - Check status
│       • ToggleAutostart() - Toggle state
│
├── Support Modules
│   │
│   ├── darkmode.c
│   │   • InitDarkMode() - Initialize dark mode support
│   │   • ApplyDarkModeToDialog() - Apply to dialog
│   │   • ApplyDarkModeToListView() - Apply to ListView
│   │   • HandleDarkModeMessages() - Handle color messages
│   │
│   ├── adscan.c
│   │   • ScanForComputers() - Discover network computers
│   │   • FreeComputerList() - Free scan results
│   │
│   └── utils.c
│       • CenterWindow() - Center dialog on screen
│       • ShowErrorMessage() - Display error dialog
│       • ShowInfoMessage() - Display info dialog
│
└── External Systems
    │
    ├── Windows Credential Manager
    │   • Global Credentials: "WinRDP:DefaultCredentials"
    │   • Per-Host Credentials: "WinRDP:TERMSRV/hostname"
    │
    ├── File System
    │   • hosts.csv - Host list storage
    │   • %TEMP%\WinRDP_*.rdp - Temporary RDP files
    │
    ├── Windows Registry
    │   • HKCU\Software\Microsoft\Windows\CurrentVersion\Run
    │   • Autostart configuration
    │
    ├── System Tray
    │   • Notification area icon
    │   • Context menu
    │
    └── mstsc.exe
        • Remote Desktop client
        • Launched with generated RDP files
```

---

## Data Flow Diagrams

### 1. Saving Global Credentials Flow

```
User Enters Username/Password
    │
    └─> LoginDialogProc (IDOK button click)
        │
        └─> GetDlgItemTextW() - Get username/password from dialog
            │
            └─> SaveCredentials() (credentials.c)
                │
                └─> CredWriteW() (Windows API)
                    │
                    └─> Windows Credential Manager (Encrypted)
                        Target: "WinRDP:DefaultCredentials"
```

### 2. Loading and Displaying Hosts Flow

```
User Opens Main Dialog
    │
    └─> MainDialogProc (WM_INITDIALOG)
        │
        └─> LoadHosts() (hosts.c)
            │
            └─> _wfopen_s() - Open hosts.csv file
                │
                └─> fgetws() - Read lines from CSV
                    │
                    └─> parse_csv_line() - Parse each line
                        │
                        └─> malloc/realloc() - Allocate memory for Host array
                            │
                            └─> Return Host* array to caller
                                │
                                └─> RefreshHostListView()
                                    └─> ListView_InsertItem() - Display in UI
```

### 3. Connecting to RDP Server Flow

```
User Clicks Connect
    │
    └─> MainDialogProc (IDC_BTN_CONNECT)
        │
        └─> LaunchRDPWithDefaults() (rdp.c)
            │
            ├─> LoadRDPCredentials() - Check for per-host credentials
            │
            └─> If not found: LoadCredentials() - Use global credentials
                │
                └─> Credentials found?
                    │
                    ├─> Yes ──> CreateRDPFile() - Write .rdp file to %TEMP%
                    │          │
                    │          └─> ShellExecuteW() - Launch mstsc.exe
                    │
                    └─> No ──> Show error message
```

### 4. Adding a New Host Flow

```
User Clicks "Add Host"
    │
    └─> HostDialogProc (IDC_BTN_ADD_HOST)
        │
        └─> AddHostDialogProc - Dialog opens
            │
            └─> User Enters:
                • Hostname
                • Description
                • (Optional) Per-Host Credentials
                │
                └─> AddHost() (hosts.c)
                    │
                    ├─> Append to CSV (_wfopen_s, fwprintf)
                    │
                    └─> If per-host credentials enabled:
                        └─> SaveRDPCredentials() (credentials.c)
```

---

## User Interaction Flows

### Flow 1: First Launch (No Saved Credentials)

```
1. App Starts
   └─> Shows System Tray Icon
   └─> Shows Login Dialog
   
2. User Enters Credentials
   └─> Clicks OK
   └─> SaveCredentials() saves to Windows Credential Manager
   └─> Login Dialog Closes (5 sec auto-close if creds exist)
   
3. Main Dialog Opens
   └─> LoadHosts() reads hosts.csv
   └─> Displays host list (empty if first time)
   
4. User Can:
   ├─> Click "Manage" → Host Management Dialog
   ├─> Click "Connect" → Launch RDP (if host selected)
   └─> Close Dialog (stays in system tray)
```

### Flow 2: Subsequent Launch (Credentials Saved)

```
1. App Starts
   └─> Shows System Tray Icon
   └─> Shows Login Dialog
   
2. Login Dialog Detects Saved Credentials
   └─> Auto-fills username/password
   └─> Shows "Delete Credentials" button
   └─> Starts 5-second countdown timer
   └─> Auto-closes after 5 seconds (or user clicks OK)
   
3. Main Dialog Opens
   └─> LoadHosts() reads hosts.csv
   └─> Displays all saved hosts
```

### Flow 3: Connecting to a Server

```
1. User Opens Main Dialog (from tray or hotkey)
   
2. User Selects Host from ListView
   
3. User Clicks "Connect" (or double-clicks)
   
4. LaunchRDPWithDefaults() is called:
   ├─> Check for per-host credentials
   │   └─> LoadRDPCredentials(hostname) 
   │       └─> If found: Use these credentials
   │
   └─> If not found, check global credentials
       └─> LoadCredentials(NULL)
           └─> Use global credentials
   
5. CreateRDPFile() generates .rdp file:
   ├─> Writes hostname
   ├─> Writes username (from credentials)
   └─> Creates file in %TEMP%
   
6. ShellExecuteW() launches mstsc.exe with .rdp file
   
7. Main Dialog Closes (app stays in tray)
```

### Flow 4: Managing Hosts

```
1. User Clicks "Manage" in Main Dialog
   
2. Host Management Dialog Opens
   └─> LoadHosts() reads hosts.csv
   └─> Displays all hosts in ListView
   
3. User Can:
   ├─> "Add Host"
   │   └─> Opens Add Host Dialog
   │   └─> Enter hostname, description
   │   └─> Optionally set per-host credentials
   │   └─> AddHost() appends to CSV
   │
   ├─> "Edit Host"
   │   └─> Pre-fills dialog with host data
   │   └─> If per-host creds exist, shows them
   │   └─> User can modify hostname/description/creds
   │   └─> DeleteHost(old) + AddHost(new)
   │
   ├─> "Delete Host"
   │   └─> Confirms deletion
   │   └─> DeleteHost() removes from CSV
   │   └─> Optionally DeleteRDPCredentials()
   │
   └─> "Scan Domain"
       └─> Opens Scan Domain Dialog
       └─> User enters domain/filters
       └─> ScanForComputers() uses NetServerEnum
       └─> Auto-adds discovered computers
```

### Flow 5: Global Hotkey (Ctrl+Shift+R)

```
1. User Presses Ctrl+Shift+R (anywhere in Windows)
   
2. Windows Sends WM_HOTKEY to Main Window
   
3. WndProc() Handles WM_HOTKEY:
   ├─> Check for global credentials
   │   └─> LoadCredentials(NULL)
   │
   ├─> If global credentials exist:
   │   └─> Show Main Dialog
   │
   └─> If no global credentials:
       └─> Show Login Dialog
   
4. User can then connect as normal
```

---

## Module Dependencies

```
main.c
 ├──> config.h (definitions, constants)
 ├──> credentials.h + credentials.c
 │    └──> Uses: Windows Credential Manager API
 │
 ├──> hosts.h + hosts.c
 │    └──> Uses: File I/O (_wfopen_s, fgetws, fwprintf)
 │
 ├──> rdp.h + rdp.c
 │    ├──> Uses: credentials.c (LoadRDPCredentials, LoadCredentials)
 │    ├──> Uses: File I/O (CreateRDPFile)
 │    └──> Uses: ShellExecuteW (launch mstsc.exe)
 │
 ├──> registry.h + registry.c
 │    └──> Uses: Windows Registry API
 │
 ├──> darkmode.h + darkmode.c
 │    └──> Uses: Windows Dark Mode API (Windows 10+)
 │
 ├──> adscan.h + adscan.c
 │    └──> Uses: NetAPI32 (NetServerEnum)
 │
 ├──> utils.h + utils.c
 │    └──> Helper functions (no external dependencies)
 │
 └──> resources.rc + resource.h
      └──> Dialog definitions, icons, menus
```

---

## Message Flow

### Windows Message Routing

```
Windows OS
    │ (Sends messages to application window)
    │
    └─> Message Queue
        • WM_CREATE
        • WM_COMMAND
        • WM_HOTKEY
        • WM_TRAYICON
        • WM_TIMER
        • WM_NOTIFY
        • etc.
        │
        └─> GetMessage() - Message Loop (main.c, wWinMain)
            │
            └─> TranslateMessage() - Keyboard input translation
                │
                └─> DispatchMessage() - Route to appropriate window procedure
                    │
                    ├─> WndProc() (Main Window)
                    │   Handles: WM_HOTKEY, WM_TRAYICON, WM_COMMAND, WM_DESTROY
                    │
                    └─> Dialog Procedures
                        • LoginDialogProc
                        • MainDialogProc
                        • HostDialogProc
                        • etc.
                        Handle: WM_INITDIALOG, WM_COMMAND, WM_NOTIFY, WM_TIMER
```

### Example: Button Click Message Flow

```
User Clicks "Connect" Button
    │
    └─> Windows Generates WM_COMMAND Message
        │
        └─> GetMessage() Receives Message from Queue
            │
            └─> DispatchMessage() Routes to Dialog Procedure
                │
                └─> MainDialogProc() - WM_COMMAND Handler
                    │
                    └─> Case IDC_BTN_CONNECT:
                        • Get selected item from ListView
                        • Get hostname
                        • Call LaunchRDP()
```

---

## Key Design Patterns

### 1. Dialog Box Pattern
- **Modal Dialogs**: Block parent window until closed
- **Dialog Procedures**: Handle dialog-specific messages
- **Return Values**: IDOK/IDCANCEL indicate user action

### 2. Message-Driven Architecture
- **Event Loop**: Continuous message processing
- **Window Procedures**: Handle window-specific messages
- **Asynchronous**: Non-blocking, responsive UI

### 3. Two-Tier Credential System
- **Global Credentials**: Default for all hosts
- **Per-Host Credentials**: Override for specific hosts
- **Fallback Logic**: Check per-host first, then global

### 4. Resource Management
- **CSV File**: Simple, human-readable host storage
- **Credential Manager**: Secure, OS-managed password storage
- **Temporary Files**: RDP files created/destroyed per connection

### 5. State Management
- **Global Variables**: Track dialog instances (g_hwndMainDialog, etc.)
- **Static Variables**: Dialog-local state (host lists, etc.)
- **File-Based Persistence**: Hosts in CSV, creds in Credential Manager

---

## File and Data Structure Flow

### Hosts CSV File Flow

```
hosts.csv (Plain text, UTF-8, editable)
    hostname,description
    server01.example.com,Production Server
    dc01.domain.local,Domain Controller
    │
    └─> LoadHosts() (hosts.c)
        │
        └─> Host* Array (malloc/realloc) - In memory
            │
            └─> ListView - Display in UI
```

### Credentials Flow

```
Windows Credential Manager (Encrypted by OS)
    │
    ├─> Global Credentials:
    │   Target: "WinRDP:DefaultCredentials"
    │   Username: "domain\user"
    │   Password: [encrypted blob]
    │
    └─> Per-Host Credentials:
        Target: "WinRDP:TERMSRV/server01"
        Username: "admin"
        Password: [encrypted blob]
        │
        └─> CredReadW() (credentials.c)
            │
            └─> Username/Password (In Memory)
                │
                └─> CreateRDPFile() (rdp.c)
                    │
                    └─> %TEMP%\WinRDP_*.rdp (Temporary file)
                        └─> Used by mstsc.exe for connection
```

---

## Summary: How Everything Links Together

1. **Startup**: `wWinMain` initializes everything, creates hidden window, shows login dialog

2. **Credentials**: Login dialog uses `credentials.c` to save/load from Windows Credential Manager

3. **Host List**: Main dialog uses `hosts.c` to read/write `hosts.csv` file

4. **Connection**: When connecting, `rdp.c`:
   - Checks per-host credentials via `credentials.c`
   - Falls back to global credentials
   - Creates temporary .rdp file
   - Launches mstsc.exe

5. **Management**: Host management dialog uses same `hosts.c` and `credentials.c` functions

6. **System Integration**:
   - `registry.c` handles autostart
   - `darkmode.c` applies theme
   - System tray icon receives messages via `WndProc`

7. **Network Scan**: `adscan.c` uses NetAPI32 to discover computers, auto-adds to host list

8. **Message Flow**: Windows OS → Message Queue → Message Loop → Window/Dialog Procedures → Module Functions

The key is that **main.c is the orchestrator** - it handles all UI events and calls functions from other modules. Each module (`credentials.c`, `hosts.c`, etc.) is independent and focused on one task.

