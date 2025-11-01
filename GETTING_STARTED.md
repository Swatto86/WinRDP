# Getting Started with WinRDP - A Learning Journey

Welcome to WinRDP! This project is designed to teach you **Windows API programming in pure C**. 

## 🎯 What You'll Learn

By studying and building this project, you'll understand:

1. **Windows Programming Fundamentals**
   - Message-driven architecture
   - Window and dialog creation
   - Event handling and callbacks

2. **System Integration**
   - Windows Credential Manager for secure password storage
   - Registry operations for autostart functionality
   - System tray programming

3. **User Interface**
   - Dialog-based interfaces
   - ListView controls for data display
   - Resource files (.rc) for UI definition

4. **Process Management**
   - Launching external applications (RDP client)
   - File I/O for configuration (CSV)
   - Temporary file handling

## 📚 Learning Path

### Phase 1: Understanding the Basics

**Start here:**
1. Read `src/main.c` - Focus on `wWinMain()` and the message loop
2. Understand `WndProc()` - The window procedure that handles messages
3. Study `resources.rc` - How UI is defined

**Key concepts:**
- What is a `HWND`? (Window handle)
- What is a message loop?
- How does Windows send events to your program?

**Recommended reading:**
- [Windows API Tutorial](http://www.winprog.org/tutorial/)
- [MSDN: About Windows](https://docs.microsoft.com/en-us/windows/win32/winmsg/about-windows)

### Phase 2: Dialog Boxes and Controls

**Study these:**
1. `LoginDialogProc()` in `src/main.c`
2. Dialog definitions in `src/resources.rc`
3. How `GetDlgItem()` and `SetDlgItemText()` work

**Try this:**
- Add a new field to the login dialog
- Add a new button and handle its click event
- Change dialog sizes and layouts

**Key concepts:**
- Dialog procedures vs window procedures
- Control IDs and resource identifiers
- Getting and setting control values

### Phase 3: ListView Controls

**Explore:**
1. `MainDialogProc()` - See how the server list is populated
2. `HostDialogProc()` - Host management with ListView
3. ListView column creation and item insertion

**Try this:**
- Add a new column to the server list
- Implement sorting when clicking column headers
- Add icons to the list items

**Key concepts:**
- `LVCOLUMN` and `LVITEM` structures
- ListView extended styles
- Handling `WM_NOTIFY` messages

### Phase 4: Windows APIs in Depth

#### Credential Manager (`src/credentials.c`)
**Learn:**
- How Windows securely stores passwords
- `CredWriteW()`, `CredReadW()`, `CredDeleteW()`
- Working with `CREDENTIALW` structures

**Try this:**
- Store additional metadata with credentials
- List all credentials in the system (advanced)

#### Registry (`src/registry.c`)
**Learn:**
- Registry structure (hives, keys, values)
- `RegOpenKeyExW()`, `RegSetValueExW()`, `RegQueryValueExW()`
- Autostart configuration

**Try this:**
- Save window position to registry
- Store application settings

#### RDP Launch (`src/rdp.c`)
**Learn:**
- RDP file format
- Using `ShellExecuteW()` to launch applications
- Temporary file creation

**Try this:**
- Add more RDP options (screen resolution, color depth)
- Create a preview of RDP settings

#### Global Hotkeys (`src/main.c`)
**Learn:**
- `RegisterHotKey()` / `UnregisterHotKey()` APIs
- `WM_HOTKEY` message handling
- System-wide keyboard shortcuts

**Try this:**
- Add more global hotkeys for different actions
- Customize hotkey combinations
- Handle hotkey conflicts gracefully

#### Dark Mode (`src/darkmode.c`)
**Learn:**
- Registry detection of Windows theme
- `DwmSetWindowAttribute()` for dark title bars
- `WM_CTLCOLOR*` message handling for control theming

**Try this:**
- Add custom dark mode colors
- Support per-dialog theming
- Add theme toggle

#### Network Discovery (`src/adscan.c`)
**Learn:**
- `NetServerEnum()` API from NetAPI32
- Computer enumeration on domain/workgroup
- `NetApiBufferFree()` for proper memory cleanup

**Try this:**
- Filter computers by type
- Add more network scan options
- Display scan progress

### Phase 5: Advanced Topics

#### File I/O (`src/hosts.c`)
**Learn:**
- Unicode file operations with `_wfopen_s()`
- CSV parsing
- Dynamic memory allocation with `malloc()`/`realloc()`

**Try this:**
- Export hosts to JSON format
- Import hosts from a text file
- Add search/filter functionality

#### System Tray
**Learn:**
- `NOTIFYICONDATA` structure
- `Shell_NotifyIcon()` API
- Tray icon events

**Try this:**
- Add custom icon to tray
- Show balloon notifications
- Add more menu items

## 🔨 Exercises for Practice

### Beginner
1. **Change the window title** when credentials are saved
2. **Add a status bar** showing how many hosts are loaded
3. **Add a "Clear All" button** to delete all hosts
4. **Change colors** of dialogs and controls

### Intermediate
5. **Add a connection history** - Log each RDP connection with timestamp
6. **Implement search** - Filter hosts as user types
7. **Add host groups** - Organize hosts into categories
8. **Custom RDP settings** - Let user choose resolution per host

### Advanced
9. **Multi-monitor support** - Choose which monitor for RDP
10. **Port scanning** - Check if RDP port (3389) is open before connecting
11. **Encrypted storage** - Encrypt the hosts.csv file
12. **Connection profiles** - Multiple credential sets
13. **Custom hotkeys** - Add more global hotkeys for different actions
14. **Connection status** - Show online/offline status of hosts

## 🐛 Debugging Tips

### Using OutputDebugString
Add debug output:
```c
wchar_t debugMsg[256];
swprintf_s(debugMsg, 256, L"Host count: %d\n", hostCount);
OutputDebugStringW(debugMsg);
```

View with [DebugView](https://docs.microsoft.com/en-us/sysinternals/downloads/debugview).

### Using MessageBox for Quick Checks
```c
wchar_t buffer[256];
swprintf_s(buffer, 256, L"Value: %d", someValue);
MessageBoxW(NULL, buffer, L"Debug", MB_OK);
```

### GDB Debugging
```bash
# Build the application first
.\build.bat

# Run in debugger
gdb build/WinRDP.exe

# In GDB:
(gdb) break main.c:50      # Set breakpoint
(gdb) run                  # Run program
(gdb) print someVariable   # Inspect variable
(gdb) continue            # Continue execution
```

## 📖 Documentation References

### Essential MSDN Pages
- [Windows Data Types](https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types)
- [Window Styles](https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles)
- [Window Messages](https://docs.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues)
- [Common Controls](https://docs.microsoft.com/en-us/windows/win32/controls/common-controls-intro)
- [Dialog Boxes](https://docs.microsoft.com/en-us/windows/win32/dlgbox/dialog-boxes)

### Code Comments
Every file in `src/` is heavily commented. Read the comments as you go—they explain:
- **Why** things are done a certain way
- **What** each Windows API function does
- **How** to use structures and parameters

## 🎓 Learning Checklist

- [ ] I understand what `wWinMain()` does
- [ ] I can explain what a message loop is
- [ ] I understand window procedures (WndProc)
- [ ] I know how to create and handle dialogs
- [ ] I can work with edit controls and buttons
- [ ] I understand ListView controls
- [ ] I know how to use Windows Credential Manager
- [ ] I can read and write registry values
- [ ] I understand how to launch external programs
- [ ] I can work with files using C file I/O
- [ ] I can compile and debug my own changes

## 🧪 Testing Your Changes

### Quick Test Checklist

**Application Startup:**
- [x] Single instance enforcement works
- [x] System tray icon appears
- [x] Login dialog appears
- [x] Modern UI enabled

**Credential Management:**
- [x] Save/load global credentials
- [x] Save/load per-host credentials
- [x] Delete credentials
- [x] Per-host fallback to global

**Host Management:**
- [x] Add new hosts
- [x] Edit existing hosts
- [x] Delete hosts
- [x] Search/filter works

**Advanced Features:**
- [x] Global hotkey (Ctrl+Shift+R)
- [x] Bulk delete (Ctrl+Shift+Alt+D)
- [x] Network discovery
- [x] Dark mode detection

**System Integration:**
- [x] Autostart toggle works
- [x] RDP connections launch
- [x] CSV file persists data
- [x] Registry operations

### Testing Dark Mode
1. Open Windows Settings → Personalization → Colors
2. Choose "Dark" as app mode
3. Launch WinRDP
4. Verify all dialogs display in dark mode

---

## 🚀 What's Next?

Once you're comfortable with this codebase:

1. **Extend it** - Add the features from the exercises above
2. **Start a new project** - Build something different (file manager, note app, etc.)
3. **Explore Win32 further** - Try GDI for custom drawing, or COM for advanced features
4. **Share your knowledge** - Teach others or contribute to open source

## 💡 Tips for Success

- **Read the code slowly** - Don't rush. Understand each line.
- **Experiment freely** - Change things and see what happens.
- **Use the documentation** - MSDN is your friend.
- **Ask questions** - Windows API has a large community.
- **Build often** - Compile frequently to catch errors early.
- **Comment your changes** - Helps you remember why you did something.

## 📞 Getting Help

- **MSDN Documentation**: https://docs.microsoft.com/en-us/windows/win32/
- **Stack Overflow**: Tag your questions with `winapi` and `c`
- **r/C_Programming**: Reddit community for C help
- **theForger's Win32 Tutorial**: http://www.winprog.org/tutorial/

Happy coding! 🎉

