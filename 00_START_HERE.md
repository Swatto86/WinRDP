# 🎓 WinRDP - Start Here!

Welcome to **WinRDP**, an educational project for learning **Windows API programming in pure C**!

## 🚀 Quick Start (3 Steps)

### 1️⃣ Install a Compiler

**Option A: MinGW (Recommended)**
- Download: https://www.msys2.org/
- Install MSYS2, then in MSYS2 terminal:
  ```bash
  pacman -S mingw-w64-x86_64-gcc
  ```

**Option B: Visual Studio**
- Download: Visual Studio Community (free)
- Install with "Desktop development with C++"

### 2️⃣ Build the Project

Simply double-click: **`build.bat`**

Or in terminal:
```cmd
cd C:\Users\me-sw\WinRDP
.\build.bat
```

### 3️⃣ Run It!

```cmd
.\build\WinRDP.exe
```

The app will:
- Show a system tray icon
- Display a login dialog to enter RDP credentials
- Let you manage and connect to RDP servers

## 📚 Documentation Guide

**Read these in order:**

1. **C_LANGUAGE_PRIMER.md** ← ⭐ NEW! C language concepts explained (START HERE if new to C)
2. **BUILD_INSTRUCTIONS.md** ← How to compile the project
3. **README.md** ← Overview and features
4. **GETTING_STARTED.md** ← Learning path and exercises
5. **PROJECT_SUMMARY.md** ← Architecture and technical details

## 🎯 What You'll Learn

**C Language Fundamentals:**
- ✅ Pointers and pointer-to-pointer patterns
- ✅ Structures and typedef
- ✅ Dynamic memory management (malloc/realloc/free)
- ✅ Function pointers and callbacks
- ✅ Wide character strings (Unicode)

**Windows API:**
- ✅ Windows message loop and event handling
- ✅ Creating dialogs and controls
- ✅ ListView controls for data display
- ✅ Windows Credential Manager API
- ✅ Global hotkeys (RegisterHotKey, WM_HOTKEY)
- ✅ Registry operations
- ✅ System tray programming
- ✅ File I/O with Unicode
- ✅ Process launching (ShellExecuteW)
- ✅ Resource files (.rc)

## 📁 Project Structure

```
WinRDP/
├── 00_START_HERE.md        ← YOU ARE HERE
├── C_LANGUAGE_PRIMER.md    ← ⭐ C concepts explained (read first!)
├── README.md               ← Main documentation
├── GETTING_STARTED.md      ← Learning guide
├── BUILD_INSTRUCTIONS.md   ← Build help
├── PROJECT_SUMMARY.md      ← Technical overview
│
├── build.bat               ← Build script (auto-detects GCC/MSVC)
│
└── src/                    ← Source code
    ├── main.c              ← Entry point, UI, dialogs
    ├── credentials.c       ← Credential Manager API
    ├── hosts.c             ← CSV file management (GREAT for learning pointers!)
    ├── rdp.c               ← RDP launching
    ├── registry.c          ← Registry operations
    ├── utils.c             ← Helper functions
    ├── darkmode.c          ← Dark mode theming
    ├── adscan.c            ← Network computer scanning
    ├── *.h                 ← Header files
    └── resources.rc        ← Dialog definitions
```

## 🔧 First Steps for Learning

### Step 0: Understand C (if needed)
- **New to C?** Read `C_LANGUAGE_PRIMER.md` first!
- Focus on sections 1-3 (Pointers, Structs, Arrays)
- Then come back here

### Step 1: Build and Run
- Run `build.bat`
- Launch `build\WinRDP.exe`
- Try adding a server and connecting

### Step 2: Read the Code
Start with these files in order:
1. `C_LANGUAGE_PRIMER.md` - Understand C concepts (if you haven't already)
2. `src/hosts.c` - **Best file for learning pointers!** Read LoadHosts() thoroughly
3. `src/main.c` - Read `wWinMain()` and a dialog procedure
4. `src/resources.rc` - See how UI is defined
5. `src/credentials.c` - Learn Credential Manager
6. `src/rdp.c` - RDP file generation

### Step 3: Make Changes
Try these exercises:
- Change the window title
- Add a new button to a dialog
- Add a new column to the host list
- Save an additional setting

### Step 4: Explore Advanced Topics
- Add connection history (already implemented: search functionality ✓)
- Create host groups
- Add custom RDP settings per host
- Implement connection profiles

## 💡 Key Files to Study

| File | Lines | Learn About |
|------|-------|-------------|
| `C_LANGUAGE_PRIMER.md` | ~900 | ⭐ Pointers, structs, memory, C concepts |
| `hosts.c` | ~550 | **Best for learning!** malloc/realloc/pointers |
| `main.c` | ~1400 | Message loop, dialogs, ListView, search |
| `adscan.c` | ~200 | NetAPI, filtering, dynamic memory |
| `darkmode.c` | ~200 | Function pointers, WinAPI theming |
| `credentials.c` | ~300 | Windows Credential Manager |
| `rdp.c` | ~250 | File I/O, wide strings, ShellExecute |
| `registry.c` | ~200 | Registry API, autostart |
| `resources.rc` | ~200 | Dialog layout, controls |

**Every file is heavily commented for learning!**

## 🐛 Troubleshooting

### Build Issues

**"gcc not found"**
- Install MinGW or use Visual Studio
- Or just run `build.bat` (auto-detects compiler)

**"Cannot find commctrl.h"**
- You need MinGW-w64 (not old MinGW.org)
- Or install Windows SDK with Visual Studio

### Runtime Issues

**"Failed to save credentials"**
- Check Windows Credential Manager permissions
- Try running as administrator

**"mstsc.exe not found"**
- RDP client is built into Windows Professional/Enterprise
- Not available on Windows Home edition

## 📖 Resources for Learning

**Tutorials:**
- [theForger's Win32 API Tutorial](http://www.winprog.org/tutorial/)
- [Microsoft Win32 Documentation](https://docs.microsoft.com/en-us/windows/win32/)

**Books:**
- "Programming Windows" by Charles Petzold (classic!)
- "Windows via C/C++" by Jeffrey Richter

**Communities:**
- Stack Overflow (tag: winapi)
- r/C_Programming on Reddit

## 🎯 Goals of This Project

1. **Teach Windows API** - Real-world example, not "Hello World"
2. **Show pure C** - No frameworks, no dependencies
3. **Demonstrate best practices** - Error handling, Unicode, memory management
4. **Provide working code** - Actually useful application
5. **Encourage learning** - Heavily commented, multiple docs

## ✨ What Makes This Different

Unlike most tutorials:
- ✅ **Complete application**, not fragments
- ✅ **Real functionality**, not just demos
- ✅ **Production quality**, with error handling
- ✅ **Heavily documented**, every concept explained
- ✅ **Modular design**, easy to extend
- ✅ **Modern C** (C11 standard)

## 🚀 Ready to Start?

1. **Build it**: Run `build.bat`
2. **Try it**: Launch `build\WinRDP.exe`
3. **Read it**: Start with `src/main.c`
4. **Change it**: Make your first modification
5. **Learn it**: Follow the exercises in GETTING_STARTED.md

## 💬 Questions?

- Read the extensive comments in the source code
- Check the documentation files
- Search MSDN for specific API functions
- Ask on Stack Overflow with the `winapi` tag

## 🎉 Have Fun!

Windows programming might seem complex at first, but by working through this project, you'll gain a solid understanding of how Windows applications work at a fundamental level.

**Remember**: Every Windows application (even complex ones) is built on these same principles!

Happy coding! 🖥️

---

**Next Steps:**
1. Open `build.bat` and run it
2. Read `GETTING_STARTED.md` for the learning path
3. Explore `src/main.c` to understand the code
4. Try the exercises and build your own features!

