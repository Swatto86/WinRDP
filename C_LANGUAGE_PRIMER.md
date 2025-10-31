# C Language Primer for WinRDP

This document explains the **C language features** used in the WinRDP project. If you're new to C or need a refresher, start here before diving into the Windows API concepts.

## 📚 Table of Contents

1. [Pointers and Memory](#1-pointers-and-memory)
2. [Structures (struct)](#2-structures-struct)
3. [Arrays and Strings](#3-arrays-and-strings)
4. [Function Pointers](#4-function-pointers)
5. [Static Variables](#5-static-variables)
6. [Type Casting](#6-type-casting)
7. [Preprocessor Directives](#7-preprocessor-directives)
8. [Windows-Specific C](#8-windows-specific-c)
9. [Common Patterns in WinRDP](#9-common-patterns-in-winrdp)
10. [Best Practices](#10-best-practices)

---

## 1. Pointers and Memory

### What is a Pointer?

A pointer is a variable that stores a **memory address** rather than a value directly.

```c
int age = 25;          // Regular variable
int* pAge = &age;      // Pointer to age (stores address of age)
```

### The Key Operators

#### `&` - Address-of Operator
Gets the memory address of a variable:

```c
int value = 42;
int* ptr = &value;     // ptr now holds the address of value
```

#### `*` - Dereference Operator
Accesses the value at a memory address:

```c
int value = 42;
int* ptr = &value;     // ptr points to value
int x = *ptr;          // x = 42 (dereference ptr to get value)
*ptr = 100;            // Changes value to 100
```

### Pointer-to-Pointer (Double Pointer)

Used when a function needs to modify a pointer itself:

```c
// Example from hosts.c
BOOL LoadHosts(Host** hosts, int* count)
{
    // Allocate memory and modify the caller's pointer
    *hosts = malloc(10 * sizeof(Host));
    *count = 10;
    return TRUE;
}

// Usage:
Host* myHosts = NULL;
int myCount = 0;
LoadHosts(&myHosts, &myCount);  // Pass addresses so function can modify them
// Now myHosts points to allocated memory!
```

**Why `Host**` instead of `Host*`?**

```c
// Won't work - pass by value:
BOOL LoadHosts(Host* hosts, int* count)
{
    hosts = malloc(10 * sizeof(Host));  // Only modifies local copy!
    return TRUE;
}

// Works - pass by reference:
BOOL LoadHosts(Host** hosts, int* count)
{
    *hosts = malloc(10 * sizeof(Host));  // Modifies caller's pointer!
    return TRUE;
}
```

### Memory Management Functions

#### `malloc()` - Allocate Memory
Allocates memory on the **heap** (persists until freed):

```c
// Allocate space for 10 Host structures
Host* hosts = (Host*)malloc(10 * sizeof(Host));

// Always check if allocation succeeded!
if (hosts == NULL)
{
    // Out of memory! Handle error
    return FALSE;
}
```

#### `realloc()` - Resize Memory
Changes the size of previously allocated memory:

```c
// Safe realloc pattern (from hosts.c)
Host* newHosts = (Host*)realloc(hosts, 20 * sizeof(Host));
if (newHosts == NULL)
{
    // Realloc failed! Original 'hosts' is still valid
    free(hosts);
    return FALSE;
}
hosts = newHosts;  // Success! Update pointer
```

**Critical:** Use a temporary variable! If realloc fails, the original pointer is still valid.

#### `free()` - Deallocate Memory
Releases memory back to the system:

```c
Host* hosts = malloc(10 * sizeof(Host));
// ... use hosts ...
free(hosts);       // Release memory
hosts = NULL;      // Good practice: avoid dangling pointer
```

### Memory Regions

```
┌─────────────────────┐
│   Stack             │  Local variables, function parameters
│   (automatic)       │  Automatically cleaned up
├─────────────────────┤
│   Heap              │  malloc/realloc allocations
│   (dynamic)         │  MUST manually free()
├─────────────────────┤
│   Global/Static     │  Global and static variables
│   (static storage)  │  Exist for program lifetime
├─────────────────────┤
│   Code              │  Executable instructions
└─────────────────────┘
```

**Example from WinRDP:**

```c
// Global storage (exists entire program)
static Host* g_hosts = NULL;

void MyFunction()
{
    // Stack (automatic cleanup when function returns)
    int localVar = 42;
    
    // Heap (manual management required)
    Host* dynamicHosts = malloc(10 * sizeof(Host));
    
    // Must clean up before returning!
    free(dynamicHosts);
}
```

---

## 2. Structures (struct)

### What is a Structure?

A `struct` groups related data together into a single type:

```c
// Define a structure
struct Point {
    int x;
    int y;
};

// Create and use it
struct Point p1;
p1.x = 10;
p1.y = 20;
```

### typedef - Creating Type Aliases

`typedef` gives a name to a type, eliminating the need for the `struct` keyword:

```c
// Without typedef (verbose):
struct Point {
    int x;
    int y;
};
struct Point p1;  // Must use "struct" keyword

// With typedef (cleaner):
typedef struct {
    int x;
    int y;
} Point;
Point p1;  // No "struct" needed!
```

### Structures in WinRDP

**Example 1: Host Information**
```c
// From hosts.h
typedef struct {
    wchar_t hostname[256];
    wchar_t description[256];
} Host;

// Usage:
Host myServer;
wcscpy_s(myServer.hostname, 256, L"SERVER01");
wcscpy_s(myServer.description, 256, L"Web Server");
```

**Example 2: Nested/Complex Structures**
```c
// From main.c
typedef struct {
    wchar_t domain[256];
    wchar_t username[256];
    wchar_t password[256];
    BOOL useCredentials;
    BOOL includeWorkstations;
    BOOL includeServers;
    BOOL includeDomainControllers;
} ScanParams;
```

### Accessing Structure Members

```c
Host server;
server.hostname[0] = L'S';              // Direct access
server.description[0] = L'M';

Host* pServer = &server;
pServer->hostname[0] = L'S';            // Pointer access (arrow notation)
(*pServer).hostname[0] = L'S';          // Equivalent to above
```

### Structure Initialization

```c
// Zero-initialize (all fields set to 0/NULL)
Host server = {0};

// Partial initialization
CREDENTIALW cred = {0};
cred.Type = CRED_TYPE_GENERIC;
cred.TargetName = L"MyApp";
```

**Why `{0}`?** In C, `{0}` initializes all fields to zero/null:
- Numeric fields → 0
- Pointers → NULL
- Arrays → zero-filled

---

## 3. Arrays and Strings

### Fixed-Size Arrays

Arrays allocate contiguous memory for multiple elements:

```c
// Array of 256 wide characters
wchar_t hostname[256];

// Access elements:
hostname[0] = L'A';
hostname[1] = L'B';
hostname[255] = L'\0';  // Null terminator
```

**Important:** Arrays are 0-indexed! `hostname[256]` declares 256 elements: indices 0-255.

### Dynamic Arrays (using malloc)

```c
// Allocate array of 10 Host structures
int count = 10;
Host* hosts = malloc(count * sizeof(Host));

// Access like a normal array:
hosts[0].hostname[0] = L'A';
hosts[5].hostname[0] = L'B';

// Don't forget to free!
free(hosts);
```

### C Strings (Character Arrays)

In C, strings are arrays of characters terminated by `\0`:

```c
char narrow[] = "Hello";     // Narrow (ASCII) string
// Internally: {'H', 'e', 'l', 'l', 'o', '\0'}

wchar_t wide[] = L"Hello";   // Wide (Unicode) string
// Internally: {L'H', L'e', L'l', L'l', L'o', L'\0'}
```

### Wide Strings (wchar_t) - Used Throughout WinRDP

**Why wide strings?** To support international characters (Unicode).

```c
// Narrow string - only ASCII
char name[] = "John";         // Works for English

// Wide string - supports all languages
wchar_t name[] = L"日本語";   // Works for Japanese, Arabic, etc.
```

**String Literals:**
- `"text"` - Narrow string (char*)
- `L"text"` - Wide string (wchar_t*)

### String Functions

**Narrow (char) strings:**
```c
strlen(str)        // Length
strcpy(dst, src)   // Copy
strcmp(s1, s2)     // Compare
strcat(dst, src)   // Concatenate
```

**Wide (wchar_t) strings - Used in WinRDP:**
```c
wcslen(str)              // Length
wcscpy(dst, src)         // Copy (UNSAFE!)
wcscpy_s(dst, size, src) // Safe copy (preferred!)
wcscmp(s1, s2)           // Compare
wcsstr(haystack, needle) // Find substring
_wcslwr_s(str, size)     // Convert to lowercase
```

**Example from main.c:**
```c
// Search functionality - case insensitive
wchar_t searchLower[256] = {0};
wcsncpy_s(searchLower, 256, searchText, _TRUNCATE);  // Safe copy
_wcslwr_s(searchLower, 256);                         // Convert to lowercase

if (wcsstr(hostnameLower, searchLower) != NULL)      // Find substring
{
    // Match found!
}
```

---

## 4. Function Pointers

### What is a Function Pointer?

A pointer that stores the address of a function (used for callbacks):

```c
// Regular function
int Add(int a, int b) { return a + b; }

// Function pointer
int (*operation)(int, int);  // Pointer to function taking 2 ints, returning int
operation = Add;             // Point to Add function
int result = operation(5, 3); // Call through pointer: result = 8
```

### Function Pointers in WinRDP

**Dialog Procedures:**
```c
// Function pointer type definition
typedef INT_PTR (CALLBACK *DLGPROC)(HWND, UINT, WPARAM, LPARAM);

// Your dialog procedure (implements the type above)
INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
            // Initialize dialog
            return TRUE;
        // ... handle other messages
    }
    return FALSE;
}

// Pass function pointer to Windows API
DialogBox(hInstance, MAKEINTRESOURCE(IDD_LOGIN), NULL, LoginDialogProc);
//                                                       ^^^^^^^^^^^^^^
//                                                       Function pointer!
```

**Why function pointers?**
- Windows calls YOUR function when events occur
- You don't call `LoginDialogProc()` directly
- Windows calls it for you when dialog events happen

### Dynamic Procedure Loading (Advanced)

From darkmode.c:
```c
// Define function pointer type
typedef BOOL (*fnAllowDarkModeForWindow)(HWND hWnd, BOOL allow);

// Get function address at runtime
HMODULE hUxtheme = LoadLibraryW(L"uxtheme.dll");
fnAllowDarkModeForWindow AllowDarkModeForWindow = 
    (fnAllowDarkModeForWindow)GetProcAddress(hUxtheme, MAKEINTRESOURCEA(135));

// Call it
if (AllowDarkModeForWindow != NULL)
{
    AllowDarkModeForWindow(hwnd, TRUE);
}
```

---

## 5. Static Variables

### What Does `static` Mean?

`static` has different meanings depending on context:

### 1. Static Variables Inside Functions

**Persist between function calls:**

```c
void CountCalls()
{
    static int count = 0;  // Initialized only ONCE (first call)
    count++;
    printf("Called %d times\n", count);
}

// First call:  "Called 1 times"
// Second call: "Called 2 times"  (count persists!)
// Third call:  "Called 3 times"
```

**Example from WinRDP:**
```c
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // These persist between calls to this function
    static Host* hosts = NULL;
    static int hostCount = 0;
    
    // Each time Windows calls this function, hosts/hostCount retain their values
}
```

### 2. Static Variables/Functions at File Scope

**Limits visibility to current file (translation unit):**

```c
// In darkmode.c:
static HBRUSH g_hBrushDialogBg = NULL;  // Only visible in darkmode.c
static HBRUSH g_hBrushControlBg = NULL; // Cannot be accessed from main.c

static void InternalHelper()  // Function only usable in this file
{
    // ...
}
```

**Benefits:**
- Prevents naming conflicts
- Encapsulation (hiding internal implementation)
- Compiler can optimize better

---

## 6. Type Casting

### What is Casting?

Converting a value from one type to another:

```c
int x = 10;
double y = (double)x;  // Cast int to double: y = 10.0
```

### Common Casts in WinRDP

**1. malloc Returns void\***
```c
// malloc returns void*, cast to specific type
Host* hosts = (Host*)malloc(10 * sizeof(Host));
//            ^^^^^^^
//            Cast void* to Host*
```

**2. Windows API Parameter Casting**
```c
// lParam is LPARAM (integer), but we pass pointer
DialogBoxParam(hInstance, IDD_DIALOG, hwnd, DialogProc, (LPARAM)&params);
//                                                       ^^^^^^^^^^^^^^^^
//                                                       Cast pointer to LPARAM
```

**3. Function Pointer Casting**
```c
// GetProcAddress returns FARPROC, cast to our function type
fnAllowDarkModeForWindow func = 
    (fnAllowDarkModeForWindow)GetProcAddress(hUxtheme, MAKEINTRESOURCEA(135));
//  ^^^^^^^^^^^^^^^^^^^^^^^^^
//  Cast to specific function pointer type
```

**4. Retrieving Stored Data**
```c
// Store original index in ListView item
item.lParam = (LPARAM)i;  // Cast int to LPARAM

// Retrieve it later
int hostIndex = (int)item.lParam;  // Cast LPARAM back to int
```

---

## 7. Preprocessor Directives

The preprocessor runs **before** compilation, handling directives starting with `#`.

### `#include` - Include Files

```c
#include <windows.h>   // System header (search standard paths)
#include "config.h"    // Local header (search project directory)
```

### `#define` - Macros and Constants

```c
// Constant definition
#define MAX_HOSTNAME_LEN 256
#define HOSTS_FILE_NAME L"hosts.csv"

// Usage:
wchar_t hostname[MAX_HOSTNAME_LEN];
FILE* file = fopen(HOSTS_FILE_NAME, "r");
```

**Function-like macros:**
```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
int bigger = MAX(10, 20);  // Expands to: ((10) > (20) ? (10) : (20))
```

### Header Guards - Prevent Double Inclusion

```c
// In hosts.h:
#ifndef HOSTS_H      // If HOSTS_H not defined...
#define HOSTS_H      // Define it now

// ... header contents ...

#endif // HOSTS_H    // End of conditional
```

**Why?** Prevents errors if a header is included multiple times:
```c
// Without guards:
#include "hosts.h"
#include "main.h"    // Also includes hosts.h
// ERROR: Host struct defined twice!

// With guards:
// Second inclusion is skipped, no error
```

### Conditional Compilation

```c
#ifdef DEBUG
    printf("Debug: x = %d\n", x);  // Only compiled in debug builds
#endif

#ifndef UNICODE
    #error "This project requires UNICODE"
#endif
```

### Compiler-Specific Pragmas

```c
// Suppress specific warning (from darkmode.c)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
    // Code that triggers warning
#pragma GCC diagnostic pop
```

---

## 8. Windows-Specific C

### Windows Types

Windows defines its own types (for portability and clarity):

```c
// Windows Type    C Type         Purpose
BOOL             int             Boolean (TRUE/FALSE, not true/false!)
DWORD            unsigned long   32-bit unsigned integer
WORD             unsigned short  16-bit unsigned integer
BYTE             unsigned char   8-bit unsigned integer
HWND             void*           Window handle
LPARAM           long            Message parameter
WPARAM           unsigned int    Message parameter
```

**Important:** `BOOL` is NOT the same as C99 `bool`!

```c
// Windows BOOL:
BOOL success = TRUE;   // TRUE = 1, FALSE = 0
if (success) { }       // Any non-zero is true

// C99 bool:
bool success = true;   // true = 1, false = 0
if (success) { }       // Only 1 and 0
```

### Wide Character Functions (_s Secure Versions)

Microsoft provides "secure" versions with `_s` suffix:

```c
// UNSAFE (buffer overflow risk):
wcscpy(dst, src);          // No bounds checking!
wcscat(dst, src);          // Can overflow!

// SAFE (bounds checked):
wcscpy_s(dst, dstSize, src);           // Checks buffer size
wcscat_s(dst, dstSize, src);           // Prevents overflow
wcsncpy_s(dst, dstSize, src, _TRUNCATE); // Truncates if too long
_wcslwr_s(str, strSize);               // Lowercase with size check
```

**Always prefer `_s` versions for security!**

### File I/O - Secure and Wide

```c
// Modern secure file opening:
FILE* file = NULL;
errno_t err = _wfopen_s(&file, L"data.csv", L"rb");
//            ^^^^^^^^^^
//            Secure version - checks for errors
if (err != 0 || file == NULL)
{
    // Handle error
}

// Wide character file operations:
fwprintf(file, L"Text: %ls\n", wideString);  // %ls for wide strings!
fgetws(buffer, 1024, file);                   // Read wide chars
```

### Windows Calling Conventions

```c
// CALLBACK - used for functions Windows calls
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// WINAPI - used for Windows API functions
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow);
```

**What are these?** Calling conventions determine:
- How parameters are passed (stack vs registers)
- Who cleans up the stack (caller vs callee)
- Parameter order

You don't need to understand the details, just use them where Windows expects them!

---

## 9. Common Patterns in WinRDP

### Pattern 1: Output Parameters

Returning multiple values from a function:

```c
// Function modifies caller's variables
BOOL LoadHosts(Host** hosts, int* count)
{
    *hosts = malloc(10 * sizeof(Host));  // Modify caller's pointer
    *count = 10;                         // Modify caller's int
    return TRUE;                         // Return success/failure
}

// Caller:
Host* myHosts = NULL;
int myCount = 0;
if (LoadHosts(&myHosts, &myCount))  // Pass addresses
{
    // myHosts and myCount now have values!
}
```

### Pattern 2: Structure Initialization

Always initialize structures to zero:

```c
// Zero-initialize all fields
LVITEMW item = {0};

// Then set specific fields
item.mask = LVIF_TEXT;
item.iItem = 0;
item.pszText = L"Text";
```

**Why?** Prevents using uninitialized memory which causes unpredictable behavior.

### Pattern 3: Safe Realloc

Never overwrite the original pointer:

```c
// BAD - loses memory on failure:
hosts = realloc(hosts, newSize);
if (hosts == NULL)  // Too late! Lost the original pointer

// GOOD - use temporary:
Host* temp = realloc(hosts, newSize);
if (temp == NULL)
{
    free(hosts);  // Can still free original
    return FALSE;
}
hosts = temp;  // Safe to update now
```

### Pattern 4: Null-Terminated String Handling

```c
// Always ensure null termination
wchar_t buffer[256];
wcsncpy_s(buffer, 256, source, _TRUNCATE);  // _TRUNCATE ensures \0
buffer[255] = L'\0';  // Redundant but defensive

// Check for empty strings
if (buffer[0] == L'\0')  // Empty string check
{
    // String is empty
}
```

### Pattern 5: Windows Message Handling

```c
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
            // Initialize
            return TRUE;  // Handled
        
        case WM_COMMAND:
            switch (LOWORD(wParam))  // Control ID
            {
                case IDC_BTN_OK:
                    // Handle button click
                    return TRUE;
            }
            break;  // Not handled
    }
    return FALSE;  // Not handled
}
```

**Pattern:** Return `TRUE` if handled, `FALSE` if not.

### Pattern 6: Resource Cleanup

```c
BOOL DoWork()
{
    FILE* file = NULL;
    Host* hosts = NULL;
    
    // Allocate resources
    _wfopen_s(&file, L"data.csv", L"rb");
    if (file == NULL) return FALSE;
    
    hosts = malloc(10 * sizeof(Host));
    if (hosts == NULL)
    {
        fclose(file);  // Clean up file before returning!
        return FALSE;
    }
    
    // ... do work ...
    
    // Clean up (in reverse order of allocation)
    free(hosts);
    fclose(file);
    return TRUE;
}
```

**Rule:** Always clean up resources before returning from a function!

---

## 10. Best Practices

### Memory Management

✅ **DO:**
- Always check if `malloc`/`realloc` returns `NULL`
- Always `free()` what you `malloc()`
- Set pointers to `NULL` after freeing
- Use safe realloc pattern with temporary variable

❌ **DON'T:**
- Dereference `NULL` pointers
- Use freed memory (dangling pointers)
- Forget to free memory (memory leaks)
- Free the same memory twice (double-free)

### String Handling

✅ **DO:**
- Use `_s` secure versions (`wcscpy_s`, `wcsncpy_s`, etc.)
- Always check buffer sizes
- Ensure null termination
- Use `_TRUNCATE` for safe copying

❌ **DON'T:**
- Use unsafe functions (`wcscpy`, `wcscat`)
- Forget null terminators
- Assume string length without checking

### Error Handling

✅ **DO:**
- Check return values of all functions
- Clean up resources before returning on error
- Initialize variables before use
- Validate input parameters

❌ **DON'T:**
- Ignore return values
- Leave resources open on error paths
- Use uninitialized variables
- Assume parameters are valid

### Code Organization

✅ **DO:**
- Use header guards in all `.h` files
- Use `static` for file-local functions/variables
- Comment complex algorithms
- Keep functions focused and small

❌ **DON'T:**
- Expose internal implementation details
- Write functions longer than 100-150 lines
- Use magic numbers (use `#define` constants)

---

## 🎓 Learning Path

**If you're new to C:**
1. Read sections 1-3 (Pointers, Structs, Arrays) thoroughly
2. Trace through `src/hosts.c` - LoadHosts() function
3. Understand the memory allocation and pointer usage
4. Move to sections 4-5 (Function Pointers, Static)
5. Study a dialog procedure in `src/main.c`

**If you know C but are new to Windows:**
1. Focus on section 8 (Windows-Specific C)
2. Study section 9 (Common Patterns)
3. Read the Windows API examples in README.md

**Exercises:**
1. Write a function that returns two values using output parameters
2. Create a dynamic array that grows using realloc
3. Implement a function pointer callback example
4. Trace memory allocations in `LoadHosts()` with pen and paper

---

## 📚 Additional Resources

**C Language:**
- "The C Programming Language" by Kernighan & Ritchie (K&R)
- "C Programming: A Modern Approach" by K. N. King
- [Learn C](https://www.learn-c.org/)

**Memory Management:**
- [Understanding Pointers](https://boredzo.org/pointers/)
- [Dynamic Memory Allocation in C](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)DynamicStorage.html)

**Windows C Programming:**
- [MSDN: Windows Data Types](https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types)
- [Secure CRT Functions](https://docs.microsoft.com/en-us/cpp/c-runtime-library/security-features-in-the-crt)

---

## 🎯 Summary

**Key C Concepts in WinRDP:**
- ✅ Pointers and pointer-to-pointer for output parameters
- ✅ Structures with `typedef` for data organization
- ✅ Dynamic memory management (`malloc`, `realloc`, `free`)
- ✅ Function pointers for Windows callbacks
- ✅ Static variables for persistent state
- ✅ Wide character strings for Unicode support
- ✅ Secure string functions (`_s` versions)
- ✅ Proper error handling and resource cleanup

**This project is an excellent way to learn:**
- Real-world C programming
- Memory management in practice
- Windows API integration
- Professional coding patterns

Now you're ready to dive into the Windows API concepts! 🚀

