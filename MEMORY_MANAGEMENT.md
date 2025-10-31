# Memory Management in C - Educational Guide

## Why Memory Management Matters

In C, **you** are the memory manager. Unlike languages with garbage collection (Java, C#, Python), C requires manual memory management. Get it wrong, and you get:
- **Memory leaks**: Lost memory that's never freed
- **Crashes**: Accessing freed memory
- **Corruption**: Writing to wrong memory locations
- **Security vulnerabilities**: Buffer overflows

## Stack vs Heap Memory

### Stack Memory

```c
void MyFunction() {
    int x = 42;              // Stack allocation
    char buffer[100];        // Stack allocation
    Host host;               // Stack allocation
    
    // Automatically freed when function returns
}
```

**Characteristics:**
- **Fast**: Simple pointer increment/decrement
- **Automatic**: Freed when function returns
- **Limited size**: Usually 1-8 MB per thread
- **LIFO**: Last In, First Out order
- **Local scope**: Only exists within function

**When to use:**
- Small, fixed-size data
- Short-lived variables
- Known size at compile time

### Heap Memory

```c
void MyFunction() {
    Host* hosts = malloc(10 * sizeof(Host));  // Heap allocation
    
    // Use the memory...
    
    free(hosts);  // MUST manually free!
}
```

**Characteristics:**
- **Slower**: System call to allocate
- **Manual**: You must free it
- **Large size**: Limited by available RAM
- **Flexible**: Can grow/shrink
- **Persistent**: Exists until you free it

**When to use:**
- Dynamic size (unknown at compile time)
- Large data structures
- Need to survive function return
- Share between functions

## Memory Allocation Functions

### malloc - Allocate Memory

```c
// Allocate 100 bytes
void* ptr = malloc(100);

// Allocate array of 10 Hosts
Host* hosts = (Host*)malloc(10 * sizeof(Host));

// Always check for NULL!
if (hosts == NULL) {
    // Out of memory - handle error!
}
```

**Important:**
- Returns NULL if allocation fails
- Memory is **uninitialized** (contains garbage)
- Must cast void* to your type
- Always use `sizeof()` for portability

### calloc - Allocate and Zero

```c
// Allocate and zero-initialize 10 Hosts
Host* hosts = (Host*)calloc(10, sizeof(Host));
```

**Difference from malloc:**
- Initializes memory to zero
- Takes count and size separately
- Slightly slower (zero fill)
- Safer (no garbage values)

### realloc - Resize Memory

```c
Host* hosts = malloc(10 * sizeof(Host));

// Need more space? Resize!
Host* newHosts = (Host*)realloc(hosts, 20 * sizeof(Host));

if (newHosts == NULL) {
    // Realloc failed! Original pointer still valid!
    free(hosts);
} else {
    hosts = newHosts;  // Update pointer
}
```

**Critical behavior:**
- May return same pointer (if room to grow in place)
- May return NEW pointer (if must move)
- If returns NULL, original pointer still valid!
- **Never** do: `hosts = realloc(hosts, newSize);` (loses original on failure!)

### free - Deallocate Memory

```c
Host* hosts = malloc(10 * sizeof(Host));

// Use the memory...

free(hosts);         // Deallocate
hosts = NULL;        // Good practice: prevent use-after-free
```

**Rules:**
- Must free exactly what malloc/calloc/realloc returned
- Only free once (double-free is crash/corruption)
- Don't use memory after freeing it
- Set pointer to NULL after freeing

## Common Memory Errors

### 1. Memory Leak

```c
// BAD: Memory is never freed
void BadFunction() {
    Host* hosts = malloc(10 * sizeof(Host));
    
    if (someCondition) {
        return;  // LEAK! Memory not freed!
    }
    
    free(hosts);  // Only freed if condition is false
}

// GOOD: Always free
void GoodFunction() {
    Host* hosts = malloc(10 * sizeof(Host));
    if (hosts == NULL) return;
    
    if (someCondition) {
        free(hosts);  // Free before return
        return;
    }
    
    free(hosts);  // Also free here
}
```

### 2. Use After Free

```c
// BAD: Using memory after freeing
Host* hosts = malloc(10 * sizeof(Host));
free(hosts);
hosts[0] = someValue;  // CRASH or corruption!

// GOOD: Set to NULL and check
Host* hosts = malloc(10 * sizeof(Host));
free(hosts);
hosts = NULL;

if (hosts != NULL) {  // Won't execute
    hosts[0] = someValue;
}
```

### 3. Double Free

```c
// BAD: Freeing twice
Host* hosts = malloc(10 * sizeof(Host));
free(hosts);
free(hosts);  // CRASH!

// GOOD: Set to NULL
Host* hosts = malloc(10 * sizeof(Host));
free(hosts);
hosts = NULL;
free(hosts);  // Safe: free(NULL) does nothing
```

### 4. Buffer Overflow

```c
// BAD: Writing past allocated size
char* buffer = malloc(10);
strcpy(buffer, "This is way too long!");  // OVERFLOW!

// GOOD: Check size
char* buffer = malloc(10);
strncpy_s(buffer, 10, "Too long", _TRUNCATE);  // Safe
```

### 5. Forgetting to Check NULL

```c
// BAD: Assuming malloc succeeded
Host* hosts = malloc(10 * sizeof(Host));
hosts[0] = value;  // CRASH if malloc returned NULL!

// GOOD: Always check
Host* hosts = malloc(10 * sizeof(Host));
if (hosts == NULL) {
    // Handle error
    return FALSE;
}
hosts[0] = value;  // Safe now
```

## WinRDP Memory Management Examples

### Dynamic Array Growth

```c
// From hosts.c - LoadHosts function
int capacity = 10;  // Initial capacity
*hosts = (Host*)malloc(capacity * sizeof(Host));

while (reading_file) {
    if (*count >= capacity) {
        // Need more space!
        capacity *= 2;  // Double the capacity
        
        Host* newHosts = (Host*)realloc(*hosts, capacity * sizeof(Host));
        if (newHosts == NULL) {
            // Realloc failed - cleanup and return
            FreeHosts(*hosts, *count);
            fclose(file);
            return FALSE;
        }
        *hosts = newHosts;  // Update pointer
    }
    
    // Add item to array
}
```

**Educational points:**
- Start with reasonable initial capacity
- Double size when full (efficient growth pattern)
- Always check realloc return value
- Clean up on failure
- Use separate variable for realloc (don't lose original on failure)

### Adding Single Item

```c
// From hosts.c - AddHost function
Host* newHosts = (Host*)realloc(hosts, (count + 1) * sizeof(Host));
if (newHosts == NULL) {
    FreeHosts(hosts, count);  // Free existing before returning
    return FALSE;
}
hosts = newHosts;

// Copy data into new slot
wcsncpy_s(hosts[count].hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
wcsncpy_s(hosts[count].description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
count++;
```

**Educational points:**
- Grow by one when adding single item
- Clean up existing memory on failure
- Use safe string functions (wcsncpy_s)
- Increment count after successful add

### Freeing Resources

```c
// From hosts.c - FreeHosts function
void FreeHosts(Host* hosts, int count) {
    UNREFERENCED_PARAMETER(count);  // Not needed, but shows we got it
    if (hosts != NULL) {
        free(hosts);
    }
}
```

**Educational points:**
- Always check for NULL before freeing
- free(NULL) is safe, but explicit check is clearer
- Don't need count to free (but might for cleanup in complex structures)

## Windows-Specific Memory Considerations

### Handles vs Pointers

```c
// NOT memory pointers!
HWND hwnd;        // Window handle (opaque ID)
HICON hIcon;      // Icon handle
HMENU hMenu;      // Menu handle

// These are pointers!
Host* hosts;      // Pointer to memory
char* buffer;     // Pointer to memory
```

**Key difference:**
- **Handles**: Windows manages memory, you just hold an ID
- **Pointers**: You manage memory, direct access

**Cleanup:**
- **Handles**: Use Windows cleanup functions (DestroyWindow, DeleteObject)
- **Pointers**: Use free()

### Memory for Window Data

```c
// Static variables in dialog procedure
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static Host* hosts = NULL;  // Persists across calls
    static int count = 0;
    
    switch (msg) {
        case WM_INITDIALOG:
            // Allocate
            LoadHosts(&hosts, &count);
            break;
            
        case WM_CLOSE:
            // Free before closing
            if (hosts != NULL) {
                FreeHosts(hosts, count);
                hosts = NULL;
            }
            break;
    }
}
```

**Why static:**
- Dialog procedures called multiple times
- Need data to persist between calls
- Local variables would be lost
- Alternative: Use SetWindowLongPtr to store pointer in window

### String Memory

```c
// Stack string (automatic)
wchar_t buffer[256];
GetDlgItemTextW(hwnd, IDC_EDIT, buffer, 256);

// Heap string (if size unknown)
int len = GetWindowTextLengthW(hwnd);
wchar_t* buffer = malloc((len + 1) * sizeof(wchar_t));
GetWindowTextW(hwnd, buffer, len + 1);
free(buffer);
```

## Memory Debugging Tools

### Visual Studio

```c
// Enable debug heap in Debug build
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
```

**Reports:**
- Memory leaks on exit
- Heap corruption
- Double frees

### Valgrind (Linux)

```bash
valgrind --leak-check=full ./program
```

### Dr. Memory (Windows/Linux)

```bash
drmemory -- program.exe
```

## Best Practices Summary

### 1. **Always Check Return Values**
```c
Host* hosts = malloc(size);
if (hosts == NULL) {
    // Handle error!
}
```

### 2. **Free What You Allocate**
```c
// Every malloc/calloc/realloc needs a free
Host* hosts = malloc(size);
// ... use ...
free(hosts);
```

### 3. **Set Pointers to NULL After Freeing**
```c
free(hosts);
hosts = NULL;  // Prevents use-after-free
```

### 4. **Use Sizeof for Portability**
```c
// GOOD: Works on any platform
malloc(count * sizeof(Host));

// BAD: Assumes size
malloc(count * 48);  // What if sizeof(Host) changes?
```

### 5. **Safe Realloc Pattern**
```c
// GOOD: Don't lose original on failure
Host* newHosts = realloc(hosts, newSize);
if (newHosts != NULL) {
    hosts = newHosts;
} else {
    // Still have original pointer
    free(hosts);
}

// BAD: Lose pointer on failure
hosts = realloc(hosts, newSize);  // If NULL, original pointer lost!
```

### 6. **Clean Up on All Exit Paths**
```c
void Function() {
    Host* hosts = malloc(size);
    if (hosts == NULL) return;
    
    if (error1) {
        free(hosts);  // Don't forget!
        return;
    }
    
    if (error2) {
        free(hosts);  // Also here!
        return;
    }
    
    free(hosts);  // And normal path
}
```

### 7. **Prefer Stack for Small, Fixed Size**
```c
// GOOD: Small, known size
char buffer[256];

// OVERKILL: Unnecessary heap allocation
char* buffer = malloc(256);
```

## Memory Leak Detection Example

```c
// Add at program start
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
#endif

// Example leak
void LeakyFunction() {
    char* leak = malloc(100);
    // Forgot to free!
}

// On program exit, Visual Studio Output window shows:
// Detected memory leaks!
// {142} normal block at 0x00000000 100 bytes long.
```

## Advanced Topics

### Memory Alignment

```c
// CPU reads memory efficiently when aligned
struct Aligned {
    int x;      // 4 bytes
    char y;     // 1 byte
    // Compiler adds 3 bytes padding
    int z;      // 4 bytes
};  // Total: 12 bytes (not 9!)
```

### Memory Pools

```c
// For many small allocations, use a pool
#define POOL_SIZE 1000
Host hostPool[POOL_SIZE];
int nextFree = 0;

Host* AllocHost() {
    if (nextFree < POOL_SIZE) {
        return &hostPool[nextFree++];
    }
    return NULL;
}
```

### Stack Overflow

```c
// BAD: Huge stack allocation
void BadFunction() {
    char huge[10000000];  // May overflow stack!
}

// GOOD: Use heap for large data
void GoodFunction() {
    char* huge = malloc(10000000);
    if (huge != NULL) {
        // Use it
        free(huge);
    }
}
```

## Key Takeaways

1. **Stack**: Fast, automatic, limited - use for small, fixed-size local data
2. **Heap**: Flexible, manual, unlimited - use for dynamic, large data
3. **Always check NULL** after allocation
4. **Always free** what you allocate
5. **Set to NULL** after freeing
6. **Use safe functions** (strncpy_s, not strcpy)
7. **Test for leaks** in debug builds
8. **Match allocations**: malloc→free, new→delete (C++)

## Further Reading

- [Microsoft Docs - Memory Management](https://docs.microsoft.com/en-us/cpp/c-runtime-library/memory-allocation)
- [Understanding Memory](https://www.gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html)
- "The C Programming Language" by Kernighan & Ritchie (Chapter 5)
- "Expert C Programming" by Peter van der Linden

## Practice Exercise

Try to find the bug in this code:

```c
Host* LoadHostsFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;
    
    Host* hosts = malloc(10 * sizeof(Host));
    int count = 0;
    
    while (count < 10 && ReadHostFromFile(file, &hosts[count])) {
        count++;
    }
    
    fclose(file);
    return hosts;  // Who will free this?
}

void UseHosts() {
    Host* hosts = LoadHostsFromFile("hosts.txt");
    if (hosts) {
        // Use hosts...
    }
    // Missing: free(hosts)!
}
```

**Bug**: Caller must free the returned pointer, but it's not obvious!

**Better design:**
```c
BOOL LoadHostsFromFile(const char* filename, Host** hosts, int* count) {
    // Caller provides pointer to store result
    // Caller knows they must free *hosts
}
```

## Conclusion

Memory management in C is challenging but teaches you what's really happening in your computer. Once you understand manual memory management, garbage-collected languages make much more sense!

**Remember**: Every malloc needs a free. Every allocation needs a check. Every function needs cleanup on all exit paths.

Master these concepts, and you'll write efficient, safe, professional C code! 🎓

