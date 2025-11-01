# In-Depth Code Commentary

## Educational Notes on Windows API Programming

This document provides detailed explanations of key concepts used in WinRDP.

### 1. **Message-Driven Architecture**

Windows applications are fundamentally different from console programs:

```c
// Console program:
int main() {
    while (condition) {
        // Your code controls the flow
    }
}

// Windows program:
int WINAPI wWinMain(...) {
    while (GetMessage(&msg, NULL, 0, 0)) {
        // Windows controls the flow
        // Your code REACTS to messages
        DispatchMessage(&msg);
    }
}
```

**Key concepts:**
- **Event-driven**: Windows sends messages, you respond
- **Message queue**: Windows maintains a queue of events
- **Message pump**: The `while(GetMessage())` loop processes events
- **Window procedures**: Your callback functions handle specific messages

### 2. **Window Procedures (WndProc)**

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_CREATE:    // Window being created
        case WM_PAINT:     // Need to redraw
        case WM_DESTROY:   // Window being destroyed
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
```

**Important:**
- **CALLBACK**: Special calling convention for Windows callbacks
- **hwnd**: Handle to the window (like a pointer/ID)
- **msg**: The message type (WM_CREATE, WM_PAINT, etc.)
- **wParam/lParam**: Message-specific data
- **Return value**: Tells Windows if you handled the message

**Common messages:**
- `WM_CREATE`: Window just created (initialize)
- `WM_DESTROY`: Window being destroyed (cleanup)
- `WM_PAINT`: Window needs repainting
- `WM_COMMAND`: User clicked button/menu
- `WM_NOTIFY`: Control notification (ListView, etc.)
- `WM_HOTKEY`: Global hotkey was pressed

### 3. **Dialog Boxes vs Windows**

**Regular Windows:**
- You create and manage everything
- Full control, more complex
- Used for main application windows

**Dialog Boxes:**
- Windows creates/manages automatically
- Easier for forms and UI
- Used for settings, input, etc.

```c
// Dialog procedure returns TRUE/FALSE (did you handle it?)
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_INITDIALOG:
            // Initialize dialog
            return TRUE;  // TRUE = you handled it
        case WM_COMMAND:
            // Button clicked
            return TRUE;
    }
    return FALSE;  // FALSE = you didn't handle it
}
```

### 4. **Handle vs Pointer**

```c
HWND hwnd;      // Handle to a window
HINSTANCE hInst; // Handle to application instance
HICON hIcon;    // Handle to an icon
```

**What is a handle?**
- Think of it as an "ID card" for a Windows object
- NOT a direct pointer (Windows manages the actual object)
- Opaque type (you don't look inside, just pass it around)
- Windows can move/resize objects, handle stays valid

**Why not pointers?**
- Windows needs to manage memory across processes
- Handles allow Windows to reorganize memory
- More stable across DLL boundaries
- Security (you can't access arbitrary memory)

### 5. **Wide Characters (Unicode)**

```c
wchar_t str[] = L"Hello";  // L prefix = wide string
MessageBoxW(NULL, L"Text", L"Title", MB_OK);  // W = wide version
```

**Why wide characters?**
- Support for international characters (中文, العربية, etc.)
- Windows internally uses UTF-16
- `W` functions (MessageBoxW) use wide chars
- `A` functions (MessageBoxA) use narrow/ANSI (legacy)

**Best practice:**
- Always use `W` versions in new code
- Use `L""` for string literals
- Use `wchar_t` for string variables

### 6. **File I/O with UTF-8**

```c
// Writing UTF-8:
FILE* file;
_wfopen_s(&file, L"file.txt", L"wb");  // Binary mode
unsigned char bom[3] = {0xEF, 0xBB, 0xBF};  // UTF-8 BOM
fwrite(bom, 1, 3, file);

// Convert wide string to UTF-8:
WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, utf8Str, size, NULL, NULL);
```

**Why binary mode?**
- Text mode does CRLF conversion (changes data!)
- Binary mode writes exactly what you tell it
- Full control over encoding

**Why UTF-8 BOM?**
- Tells programs "this is UTF-8"
- Notepad, Excel recognize it properly
- Optional but recommended for Windows

### 7. **Resource Files (.rc)**

```rc
IDD_DIALOG DIALOGEX 0, 0, 200, 100
BEGIN
    LTEXT "Label", IDC_STATIC, 10, 10, 50, 10
    EDITTEXT IDC_EDIT, 70, 8, 100, 14
END
```

**Coordinate system:**
- **Dialog units**: NOT pixels!
- Based on font size (portable across DPI)
- Windows converts to pixels automatically
- Format: `X, Y, Width, Height`

**Common controls:**
- `LTEXT`: Static text (label)
- `EDITTEXT`: Text input box
- `PUSHBUTTON`: Clickable button
- `DEFPUSHBUTTON`: Default button (Enter key)
- `CONTROL`: Generic control (ListView, etc.)

### 8. **ListView Control**

```c
// Create columns:
LVCOLUMN col = {0};
col.mask = LVCF_TEXT | LVCF_WIDTH;
col.pszText = L"Column Name";
col.cx = 200;  // Width in pixels
ListView_InsertColumn(hList, 0, &col);

// Add items:
LVITEM item = {0};
item.mask = LVIF_TEXT;
item.iItem = 0;  // Row number
item.iSubItem = 0;  // Column number
item.pszText = L"Cell Text";
ListView_InsertItem(hList, &item);
```

**Important concepts:**
- **mask**: Tells Windows which fields are valid
- **iItem**: Row index (0-based)
- **iSubItem**: Column index (0 = first column)
- Must call `InsertItem` for first column, `SetItemText` for others

### 9. **System Tray Icons**

```c
NOTIFYICONDATA nid = {0};
nid.cbSize = sizeof(NOTIFYICONDATA);
nid.hWnd = hwnd;
nid.uID = ID_TRAYICON;
nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
nid.uCallbackMessage = WM_TRAYICON;  // Custom message
nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wcscpy_s(nid.szTip, L"Tooltip text");

Shell_NotifyIcon(NIM_ADD, &nid);  // Add to tray
```

**How it works:**
- Windows displays icon in system tray
- User clicks icon → Windows sends `WM_TRAYICON` to your window
- You check `lParam` for which mouse button
- Show menu or window in response

### 10. **Credential Manager**

```c
CREDENTIALW cred = {0};
cred.Type = CRED_TYPE_GENERIC;
cred.TargetName = L"MyApp:Credentials";
cred.CredentialBlobSize = sizeof(password);
cred.CredentialBlob = (LPBYTE)password;
cred.Persist = CRED_PERSIST_LOCAL_MACHINE;

CredWriteW(&cred, 0);  // Save
CredReadW(L"MyApp:Credentials", CRED_TYPE_GENERIC, 0, &pCred);  // Read
CredEnumerateW(NULL, 0, &count, &credentials);  // List all credentials
CredDeleteW(L"MyApp:Credentials", CRED_TYPE_GENERIC, 0);  // Delete
CredFree(credentials);  // Free memory from CredReadW/CredEnumerateW
```

**Security notes:**
- Credentials stored encrypted by Windows
- Only current user can access
- Survives reboots
- Can be backed up with system
- Better than storing in plain text files!
- `CredEnumerateW` enumerates all credentials (must free with `CredFree`)

### 11. **Global Hotkeys**

```c
// Register a global hotkey (works from anywhere in Windows)
RegisterHotKey(hwnd, ID_HOTKEY, MOD_CONTROL | MOD_SHIFT, 'R');

// Handle the hotkey press
case WM_HOTKEY:
    if (wParam == ID_HOTKEY) {
        // Hotkey was pressed - do something
    }
    return 0;

// Always unregister when done
UnregisterHotKey(hwnd, ID_HOTKEY);
```

**Key concepts:**
- **RegisterHotKey**: Registers key combination system-wide
- **WM_HOTKEY**: Message sent when hotkey is pressed
- **Modifiers**: MOD_CONTROL, MOD_SHIFT, MOD_ALT, MOD_WIN
- **Virtual keys**: Use virtual key codes (e.g., 0x44 for 'D')
- **UnregisterHotKey**: Required to free the hotkey
- Hotkeys registered in WM_CREATE, unregistered in WM_DESTROY
- Works even when your application doesn't have focus!

**Best practices:**
- Always unregister hotkeys to prevent conflicts
- Check return value (registration might fail if in use)
- Use unique hotkey IDs for each hotkey
- Silently handle failures (app still works without hotkey)

### 12. **Registry Operations**

```c
HKEY hKey;
RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\MyApp", 0, KEY_READ, &hKey);

DWORD value;
DWORD size = sizeof(value);
RegQueryValueExW(hKey, L"Setting", NULL, NULL, (LPBYTE)&value, &size);

RegCloseKey(hKey);  // ALWAYS close!
```

**Registry hierarchy:**
- `HKEY_CURRENT_USER`: Per-user settings
- `HKEY_LOCAL_MACHINE`: Machine-wide settings
- `Software`: Applications store settings here
- `Microsoft\\Windows\\CurrentVersion\\Run`: Autostart programs

**Best practices:**
- Always close keys (`RegCloseKey`)
- Check return values
- Use appropriate hive (HKCU vs HKLM)
- Don't write to system areas

### 13. **Dark Mode Support**

Modern Windows applications should support dark mode. Here's how WinRDP implements it:

```c
// Detect Windows dark mode from registry
BOOL IsDarkModeEnabled(void)
{
    HKEY hKey;
    DWORD dwValue = 1; // Default to light mode
    DWORD dwSize = sizeof(DWORD);
    
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        RegQueryValueExW(hKey, L"AppsUseLightTheme", NULL, NULL, 
                         (LPBYTE)&dwValue, &dwSize);
        RegCloseKey(hKey);
    }
    
    return (dwValue == 0); // 0 = Dark mode
}

// Apply dark title bar (Windows 10+)
BOOL ApplyDarkModeToDialog(HWND hwnd)
{
    BOOL darkMode = IsDarkModeEnabled();
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE, 
                          &darkMode, sizeof(darkMode));
    
    // Create brushes for dark backgrounds
    if (darkMode) {
        g_hBrushDialogBg = CreateSolidBrush(RGB(43, 43, 43));
        g_hBrushControlBg = CreateSolidBrush(RGB(55, 55, 55));
    }
}

// Handle control color messages
HBRUSH Callback WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_CTLCOLORDLG:
            return g_hBrushDialogBg;  // Dialog background
        case WM_CTLCOLORSTATIC:
            SetTextColor((HDC)wParam, RGB(220, 220, 220));
            SetBkColor((HDC)wParam, RGB(43, 43, 43));
            return g_hBrushDialogBg;
        case WM_CTLCOLOREDIT:
            SetTextColor((HDC)wParam, RGB(220, 220, 220));
            SetBkColor((HDC)wParam, RGB(55, 55, 55));
            return g_hBrushControlBg;
    }
}
```

**Key concepts:**
- **Registry Detection**: Reads `AppsUseLightTheme` from registry
- **DwmSetWindowAttribute**: Modern API for dark title bars (Windows 10 1809+)
- **WM_CTLCOLOR*** messages: Intercept control painting for custom colors
- **GDI Brushes**: Create solid color brushes for backgrounds
- **SetTextColor/SetBkColor**: Change text and background colors

**Best practices:**
- Detect system preference automatically
- Use `GetProcAddress` for newer APIs (compatibility)
- Create brushes once, reuse them
- Clean up brushes on exit
- Works without dark mode (graceful degradation)

**Files**: `darkmode.c`, `darkmode.h`

### 14. **Network Discovery**

WinRDP can scan the network for computers using NetAPI32:

```c
// Scan for computers in domain/workgroup
BOOL ScanForComputers(const wchar_t* domain, BOOL includeWorkstations,
                      BOOL includeServers, BOOL includeDomainControllers,
                      ComputerInfo** computers, int* count)
{
    SERVER_INFO_101* buffer = NULL;
    DWORD entriesRead, totalEntries, resumeHandle = 0;
    
    // Call NetAPI32 to enumerate servers
    NET_API_STATUS status = NetServerEnum(NULL, 101, (LPBYTE*)&buffer,
                                           MAX_PREFERRED_LENGTH,
                                           &entriesRead, &totalEntries,
                                           SV_TYPE_ALL, NULL, &resumeHandle);
    
    if (status == NERR_Success) {
        // Process the buffer...
        // Filter by type (workstation, server, DC)
        // Convert to ComputerInfo structures
    }
    
    // ALWAYS free NetAPI buffers
    if (buffer != NULL)
        NetApiBufferFree(buffer);
    
    return TRUE;
}
```

**Key concepts:**
- **NetServerEnum**: Enumerates servers/computers in domain/workgroup
- **SERVER_INFO_101**: Structure containing server information
- **NetApiBufferFree**: Required cleanup for NetAPI buffers
- **SV_TYPE_***: Flags for filtering server types
- **MAX_PREFERRED_LENGTH**: Tells API to allocate buffer for all results

**Best practices:**
- Always call `NetApiBufferFree` for allocated buffers
- Filter results by server type as needed
- Handle NERR_Success and other return codes
- Use MAX_PREFERRED_LENGTH for large networks
- Resume handle for large result sets

**Files**: `adscan.c`, `adscan.h`

### 15. **Error Handling**

```c
// Windows functions return different things:

BOOL success = CreateDirectory(L"folder", NULL);
if (!success) {
    DWORD error = GetLastError();
    // ERROR_ALREADY_EXISTS, ERROR_ACCESS_DENIED, etc.
}

HANDLE hFile = CreateFileW(L"file.txt", ...);
if (hFile == INVALID_HANDLE_VALUE) {
    // Failed to open file
}
```

**Common patterns:**
- `BOOL` functions: TRUE = success, FALSE = failure
- `HANDLE` functions: NULL or INVALID_HANDLE_VALUE = failure
- `GetLastError()`: Gets detailed error code
- Always check return values!

### 16. **Single Instance (Mutex)**

```c
HANDLE hMutex = CreateMutexW(NULL, TRUE, L"MyApp_Mutex");
if (GetLastError() == ERROR_ALREADY_EXISTS) {
    // Another instance is running!
    CloseHandle(hMutex);
    return 0;
}

// ... run application ...

CloseHandle(hMutex);  // Release on exit
```

**How it works:**
- Mutex = Mutual Exclusion object
- Only one process can "own" a named mutex
- `CreateMutex` with same name returns handle but sets `ERROR_ALREADY_EXISTS`
- Check error even if handle is valid!

### 17. **Memory Management**

```c
// Allocate:
Host* hosts = (Host*)malloc(count * sizeof(Host));
if (hosts == NULL) {
    // Out of memory!
}

// Resize:
Host* newHosts = (Host*)realloc(hosts, newCount * sizeof(Host));
if (newHosts == NULL) {
    // Failed - original pointer still valid!
    free(hosts);
}
hosts = newHosts;

// Free:
free(hosts);
hosts = NULL;  // Good practice
```

**Important:**
- Always check if `malloc`/`realloc` returns NULL
- `realloc` can fail - keeps original if so
- Always `free` what you `malloc`
- Set pointer to NULL after freeing (prevents double-free)

### 18. **String Safety**

```c
// UNSAFE:
wcscpy(dest, src);  // Buffer overflow risk!
wcscat(dest, src);  // Buffer overflow risk!

// SAFE:
wcsncpy_s(dest, destSize, src, _TRUNCATE);  // Safe copy
StringCchCopyW(dest, destSize, src);        // Alternative
```

**Why *_s functions?**
- Check buffer sizes
- Prevent overflow attacks
- Always null-terminate
- `_TRUNCATE`: Cut off if too long (safe)

## Common Pitfalls

###1. **Forgetting to Call DefWindowProc**
```c
// WRONG:
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: return 0;
    }
    return 0;  // BUG: Other messages not handled!
}

// CORRECT:
return DefWindowProc(hwnd, msg, wParam, lParam);  // Handle others
```

### 2. **Dialog Return Values**
```c
// Dialog proc:
return TRUE;   // "I handled this message"
return FALSE;  // "I didn't handle it"

// Window proc:
return 0;      // Usually means "I handled it"
return DefWindowProc(...);  // Let Windows handle it
```

### 3. **Resource Leaks**
```c
// DON'T FORGET:
CloseHandle(hMutex);
RegCloseKey(hKey);
fclose(file);
free(memory);
DeleteObject(hBrush);
```

### 4. **Wide vs Narrow**
```c
// WRONG (mixing):
MessageBoxA(NULL, L"Wide string", ...);  // A = narrow function

// CORRECT:
MessageBoxW(NULL, L"Wide string", ...);  // W = wide function
```

## Further Learning

1. **Charles Petzold - "Programming Windows"**: The Bible of Windows programming
2. **MSDN Documentation**: Official Microsoft docs
3. **Raymond Chen's Blog**: "The Old New Thing" - insider knowledge
4. **Win32 API Reference**: Complete function documentation

## Conclusion

Windows programming seems complex, but it's really about:
1. Responding to messages
2. Managing resources properly
3. Following Windows conventions
4. Checking return values

Once you understand the message-driven model, everything else follows naturally!

