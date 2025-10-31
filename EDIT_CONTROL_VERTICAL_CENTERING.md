# Vertical Text Centering in Edit Controls

## The Problem

Windows single-line edit controls (`EDITTEXT` with `ES_AUTOHSCROLL`) don't support vertical text alignment. The text appears slightly high within the control, which can look unpolished.

## Solutions (Ranked by Complexity)

### 1. **Make Controls Taller** ✅ (What we're using)

The simplest and most effective approach:

```rc
// Instead of standard 14px height:
EDITTEXT IDC_EDIT, 10, 10, 200, 14

// Use 20-24px height:
EDITTEXT IDC_EDIT, 10, 10, 200, 22
```

**Pros:**
- No code changes needed
- Looks more modern (easier to click)
- Text appears more centered visually
- Matches modern UI guidelines

**Cons:**
- Text still isn't perfectly centered
- Takes more vertical space

### 2. **Multiline Trick** 🎯 (Best for single-line appearance)

Use `ES_MULTILINE` but configure it to act like single-line:

```rc
EDITTEXT IDC_EDIT, 10, 10, 200, 24, ES_MULTILINE | ES_AUTOHSCROLL
```

```c
// In WM_INITDIALOG:
HWND hEdit = GetDlgItem(hwnd, IDC_EDIT);

// Set single-line behavior
SendMessage(hEdit, EM_SETLIMITTEXT, 256, 0);  // Max length

// Center text vertically (only works with ES_MULTILINE)
RECT rect;
GetClientRect(hEdit, &rect);
SendMessage(hEdit, EM_SETRECT, 0, (LPARAM)&rect);

// Prevent actual multiline behavior
SendMessage(hEdit, EM_FMTLINES, FALSE, 0);
```

**Pros:**
- Text can be vertically centered
- Still looks like single-line control
- No custom drawing needed

**Cons:**
- User can press Enter (need to handle in WM_COMMAND)
- Slightly more complex setup
- May have multiline quirks

### 3. **Custom Font and Metrics** 📏

Adjust font size to better fit the control:

```c
// Create slightly larger font
HFONT hFont = CreateFont(
    14,                        // Height (larger = more centered appearance)
    0,                         // Width (0 = default)
    0, 0,                      // Escapement, Orientation
    FW_NORMAL,                 // Weight
    FALSE, FALSE, FALSE,       // Italic, Underline, Strikeout
    DEFAULT_CHARSET,
    OUT_DEFAULT_PRECIS,
    CLIP_DEFAULT_PRECIS,
    CLEARTYPE_QUALITY,         // Quality
    DEFAULT_PITCH | FF_DONTCARE,
    L"Segoe UI"               // Font name
);

SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);
```

**Pros:**
- Fine-grained control
- Can match other UI elements
- No structural changes

**Cons:**
- Font must be deleted on cleanup
- Trial and error to get right height
- Still not perfect centering

### 4. **Subclass and Custom Draw** 🎨 (Most control)

Completely custom rendering:

```c
LRESULT CALLBACK EditSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, 
                                  LPARAM lParam, UINT_PTR uIdSubclass, 
                                  DWORD_PTR dwRefData)
{
    if (msg == WM_PAINT) {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        // Custom drawing code here
        // Draw border, background, centered text
        
        EndPaint(hwnd, &ps);
        return 0;
    }
    
    return DefSubclassProc(hwnd, msg, wParam, lParam);
}

// Subclass the edit control:
SetWindowSubclass(hEdit, EditSubclassProc, 0, 0);
```

**Pros:**
- Perfect control over appearance
- Can add custom styling
- Professional result

**Cons:**
- Very complex (100+ lines of code)
- Must handle all drawing yourself
- Must handle caret positioning
- Must handle selection rendering
- High maintenance

### 5. **Owner-Drawn Custom Control** 🏗️ (Maximum control)

Create your own edit control from scratch:

```c
LRESULT CALLBACK CustomEditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
        case WM_CREATE:
            // Initialize edit buffer
            break;
        case WM_PAINT:
            // Draw everything
            break;
        case WM_CHAR:
            // Handle text input
            break;
        case WM_KEYDOWN:
            // Handle cursor movement
            break;
        case WM_LBUTTONDOWN:
            // Handle mouse clicks
            break;
        case WM_SETFOCUS:
        case WM_KILLFOCUS:
            // Handle caret
            break;
        // ... many more messages
    }
}
```

**Pros:**
- Ultimate control
- Can add any feature you want
- Learning experience

**Cons:**
- Extremely complex (500+ lines)
- Must implement all edit functionality
- Clipboard, undo/redo, internationalization
- Not recommended unless absolutely necessary

## Recommended Approach for WinRDP

**Use taller controls (20-24px) + proper spacing**

This gives:
- Modern appearance
- Better clickability
- Visual balance
- No code complexity

For inputs that need perfect centering:
- Consider using the **multiline trick** (#2)
- Only for important/visible fields
- Trade-off: slight complexity for better appearance

## When to Use Custom Drawing

Only if:
- Building a commercial product
- Specific brand requirements
- Budget for maintenance
- Team familiar with GDI/GDI+

For educational/learning projects:
- Standard controls + good sizing = 95% of the way there
- Focus on functionality and learning Windows API
- Avoid complexity that obscures the learning goals

## Visual Comparison

```
Standard 14px:
┌────────────────┐
│Text            │  ← Text sits high
└────────────────┘

Taller 22px:
┌────────────────┐
│                │
│Text            │  ← Appears more centered
│                │
└────────────────┘

Custom Drawn:
┌────────────────┐
│      Text      │  ← Perfectly centered
└────────────────┘
```

## Conclusion

For most applications, including WinRDP:
- **20-24px tall controls** provide good visual centering
- **Consistent spacing** makes layout look intentional
- **Modern = taller controls** anyway (easier to click)
- Save custom drawing for when it's truly needed

The slight imperfection is acceptable and matches many professional applications!

