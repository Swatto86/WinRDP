# Building Real Windows Applications in C
## A Hands-On Journey from Basics to a Complete RDP Manager

**Author:** Created from the WinRDP Educational Project  
**Target Audience:** Beginners to Intermediate C Programmers  
**Prerequisites:** Basic computer literacy, willingness to learn

---

# Table of Contents

## Part I: C Fundamentals
1. [Introduction to C Programming](#chapter-1-introduction-to-c-programming) ✅
2. [Variables, Data Types, and Operators](#chapter-2-variables-data-types-and-operators) ✅
3. [Control Flow: Making Decisions](#chapter-3-control-flow-making-decisions) ✅
4. [Functions: Building Blocks of Programs](#chapter-4-functions-building-blocks-of-programs) ✅
5. [Arrays: Working with Multiple Values](#chapter-5-arrays-working-with-multiple-values) ✅
6. [Pointers: The Heart of C](#chapter-6-pointers-the-heart-of-c) ✅
7. [Strings: Text Processing in C](#chapter-7-strings-text-processing-in-c) ✅
8. [Structures: Organizing Related Data](#chapter-8-structures-organizing-related-data) ✅

## Part II: Advanced C Concepts
9. [Dynamic Memory Management](#chapter-9-dynamic-memory-management) ✅
10. [File Input/Output](#chapter-10-file-inputoutput) ✅
11. [Function Pointers and Callbacks](#chapter-11-function-pointers-and-callbacks) ✅
12. [Preprocessor and Multi-File Programs](#chapter-12-preprocessor-and-multi-file-programs) ✅

## Part III: Windows Programming Basics
13. [Introduction to Windows Programming](#chapter-13-introduction-to-windows-programming) ✅
14. [Your First Windows Application](#chapter-14-your-first-windows-application) ✅
15. [Windows Message System](#chapter-15-windows-message-system) ✅
16. [Dialog Boxes and Controls](#chapter-16-dialog-boxes-and-controls) ✅

## Part IV: Building WinRDP Core
17. [Project Setup and Architecture](#chapter-17-project-setup-and-architecture) ✅
18. [Configuration and Utilities](#chapter-18-configuration-and-utilities) ✅
19. [CSV File Management](#chapter-19-csv-file-management) ✅ ⭐ **UPDATED v1.2.0**
20. [Windows Credential Manager](#chapter-20-windows-credential-manager) ✅ ⭐ **UPDATED v1.2.0**
21. [Main Application Window](#chapter-21-main-application-window) ✅
22. [ListView Control for Host Display](#chapter-22-listview-control-for-host-display) ✅ ⭐ **UPDATED v1.2.0**
23. [RDP Connection Logic](#chapter-23-rdp-connection-logic) ✅
24. [System Tray Integration](#chapter-24-system-tray-integration) ✅

## Part V: Advanced Features
25. [Registry Operations and Autostart](#chapter-25-registry-operations-and-autostart) ✅
26. [Global Hotkeys](#chapter-26-global-hotkeys) ✅
27. [Dark Mode Support](#chapter-27-dark-mode-support) ✅
28. [Network Computer Discovery](#chapter-28-network-computer-discovery) ✅
29. [Building and Distribution](#chapter-29-building-and-distribution) ✅

## Part VI: Testing and Quality Assurance
30. [System Testing and Integration](#chapter-30-system-testing-and-integration) ✅

## Appendices
- [A: Setting Up Your Development Environment](#appendix-a-setting-up-your-development-environment) ✅
- [B: Common Mistakes and How to Avoid Them](#appendix-b-common-mistakes-and-how-to-avoid-them) ✅
- [C: Windows API Quick Reference](#appendix-c-windows-api-quick-reference) ✅
- [D: Further Learning Resources](#appendix-d-further-learning-resources) ✅

---

# Foreword

Welcome to an exciting journey into C programming! This book takes a unique approach: instead of teaching C concepts in isolation, we'll build a complete, real-world Windows application together. By the end of this book, you'll have created **WinRDP**, a fully functional Remote Desktop connection manager with features like:

- Secure credential storage
- System tray integration
- Global keyboard shortcuts
- Dark mode support
- Network computer discovery
- Professional installer

Every chapter builds on the previous ones, introducing new concepts exactly when you need them. You'll learn by doing, writing real code that solves actual problems.

## Who This Book Is For

- **Beginners** who want to learn C programming from scratch
- **Intermediate programmers** looking to understand Windows API programming
- **Anyone** interested in systems programming and desktop applications
- **Developers** who want to see how production-quality C code is structured

## What Makes This Book Different

Most programming books teach concepts in isolation with toy examples. This book is different:

1. **Real Application**: Every line of code you write contributes to a complete, useful application
2. **Progressive Complexity**: Concepts are introduced exactly when needed, not all at once
3. **Hands-On**: Every chapter includes working code and exercises
4. **Production Quality**: Learn best practices, error handling, and professional patterns
5. **Modern C**: Uses modern Windows API while teaching timeless C fundamentals

## How to Use This Book

- **Type the code yourself**: Don't copy-paste! Typing helps you internalize patterns
- **Do the exercises**: They reinforce concepts and build muscle memory
- **Experiment**: Modify code, break things, fix them. That's how you learn!
- **Build incrementally**: Each chapter adds features. Test as you go
- **Reference the repository**: The complete WinRDP source code is available for reference

Let's begin your journey into C programming!

---

# Part I: C Fundamentals

# Chapter 1: Introduction to C Programming

## What Is C?

C is a powerful, efficient programming language created in 1972 by Dennis Ritchie at Bell Labs. Despite being over 50 years old, C remains one of the most important programming languages because:

1. **Operating Systems**: Windows, Linux, and macOS are largely written in C
2. **Performance**: C gives you direct control over computer hardware
3. **Portability**: C programs can run on virtually any computer
4. **Foundation**: Most modern languages (C++, C#, Java, JavaScript) borrowed from C

## Why Learn C?

- **Understand Computing**: C teaches you how computers really work
- **Performance**: C programs are typically the fastest
- **Systems Programming**: Essential for operating systems, drivers, embedded systems
- **Windows API**: The Windows operating system is built on C APIs
- **Foundation**: Once you know C, learning other languages becomes easier

## Your First C Program

Let's start with the traditional "Hello, World!" program:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

Let's break this down:

### Line 1: `#include <stdio.h>`
- **#include**: Tells the compiler to include another file
- **stdio.h**: Standard Input/Output header file containing `printf`
- Think of it as "importing" functionality we need

### Line 3: `int main(void)`
- **int**: The function returns an integer value
- **main**: Every C program starts executing here
- **void**: This function takes no parameters
- **{ }**: Curly braces define the function body

### Line 5: `printf("Hello, World!\n");`
- **printf**: Print formatted text to screen
- **"Hello, World!\n"**: The text to print
- **\n**: Newline character (moves to next line)
- **;**: Every statement ends with a semicolon

### Line 6: `return 0;`
- **return**: Exit the function
- **0**: By convention, 0 means "success" to the operating system

## Compiling and Running

To turn your C code into an executable program:

1. **Write** the code in a text editor (save as `hello.c`)
2. **Compile** it: `gcc hello.c -o hello.exe`
3. **Run** it: `./hello.exe` or just `hello` on Windows

```bash
# Compilation
gcc hello.c -o hello.exe

# Execution
./hello.exe
```

Output:
```
Hello, World!
```

## Understanding the Compilation Process

```
Source Code (hello.c)
        ↓
    Preprocessor (handles #include, #define)
        ↓
    Compiler (converts to assembly, then machine code)
        ↓
    Linker (combines with libraries)
        ↓
Executable (hello.exe)
```

## Exercise 1.1: Hello, Your Name!

Modify the program to print your name:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, [Your Name]!\n");
    return 0;
}
```

## Exercise 1.2: Multiple Lines

Print three lines of text:

```c
#include <stdio.h>

int main(void)
{
    printf("Line 1\n");
    printf("Line 2\n");
    printf("Line 3\n");
    return 0;
}
```

## Common Mistakes

### Mistake 1: Forgetting Semicolons
```c
printf("Hello")  // ERROR: Missing semicolon
```

### Mistake 2: Case Sensitivity
```c
Printf("Hello");  // ERROR: Capital P (should be lowercase)
```

### Mistake 3: Missing Quotes
```c
printf(Hello);  // ERROR: Missing quotes around string
```

## Summary

You've learned:
- ✅ What C is and why it's important
- ✅ The structure of a C program
- ✅ How to write, compile, and run code
- ✅ Basic syntax rules (semicolons, case-sensitivity)

**Next Chapter**: We'll dive into variables and data types!

---

# Chapter 2: Variables, Data Types, and Operators

## What Are Variables?

Variables are named containers that store values. Think of them as labeled boxes:

```c
int age = 25;        // Box labeled "age" contains 25
float height = 5.9;  // Box labeled "height" contains 5.9
char grade = 'A';    // Box labeled "grade" contains 'A'
```

## Basic Data Types

### Integer Types

```c
int number = 42;           // Whole numbers (-2147483648 to 2147483647)
short small = 100;         // Smaller range (-32768 to 32767)
long big = 1000000L;       // Larger range
unsigned int positive = 50; // Only positive (0 to 4294967295)
```

### Floating-Point Types

```c
float price = 19.99f;      // Single precision (6-7 digits)
double precise = 3.14159;  // Double precision (15-16 digits)
```

### Character Type

```c
char letter = 'A';         // Single character
char newline = '\n';       // Special character (newline)
```

### Boolean (in modern C)

```c
#include <stdbool.h>
bool isActive = true;      // true or false
```

## Variable Declaration and Initialization

```c
// Declaration only (value is undefined)
int x;

// Declaration with initialization (recommended)
int y = 10;

// Multiple declarations
int a, b, c;

// Multiple initializations
int d = 1, e = 2, f = 3;
```

## Operators

### Arithmetic Operators

```c
int a = 10, b = 3;
int sum = a + b;         // 13 (addition)
int diff = a - b;        // 7 (subtraction)
int product = a * b;     // 30 (multiplication)
int quotient = a / b;    // 3 (integer division!)
int remainder = a % b;   // 1 (modulus - remainder)
```

**Important**: Integer division truncates! `10 / 3 = 3`, not `3.33`.

### Comparison Operators

```c
int x = 5, y = 10;
x == y;  // false (equal to)
x != y;  // true (not equal to)
x < y;   // true (less than)
x > y;   // false (greater than)
x <= y;  // true (less than or equal)
x >= y;  // false (greater than or equal)
```

### Logical Operators

```c
bool a = true, b = false;
a && b;  // false (AND - both must be true)
a || b;  // true (OR - at least one true)
!a;      // false (NOT - inverts value)
```

### Assignment Operators

```c
int x = 10;
x += 5;  // x = x + 5;  → x is now 15
x -= 3;  // x = x - 3;  → x is now 12
x *= 2;  // x = x * 2;  → x is now 24
x /= 4;  // x = x / 4;  → x is now 6
x %= 4;  // x = x % 4;  → x is now 2
```

### Increment/Decrement

```c
int count = 5;
count++;  // Post-increment: count becomes 6
++count;  // Pre-increment: count becomes 7
count--;  // Post-decrement: count becomes 6
--count;  // Pre-decrement: count becomes 5
```

## printf: Printing Variables

```c
int age = 25;
float height = 5.9f;
char grade = 'A';

printf("Age: %d\n", age);           // %d for int
printf("Height: %.1f\n", height);   // %f for float
printf("Grade: %c\n", grade);       // %c for char
```

### Format Specifiers

Format specifiers tell `printf` how to display variables. They always start with `%` and end with a letter indicating the data type.

#### Common Format Specifiers

| Specifier | Type | Example |
|-----------|------|---------|
| `%d` or `%i` | int | `printf("%d", 42);` |
| `%u` | unsigned int | `printf("%u", 42u);` |
| `%ld` | long int | `printf("%ld", 123456L);` |
| `%lld` | long long int | `printf("%lld", 123456789LL);` |
| `%f` | float/double | `printf("%f", 3.14);` |
| `%lf` | double (scanf only) | `scanf("%lf", &d);` |
| `%c` | char | `printf("%c", 'A');` |
| `%s` | string | `printf("%s", "Hello");` |
| `%p` | pointer | `printf("%p", ptr);` |
| `%x` | hexadecimal (lowercase) | `printf("%x", 255);` |
| `%X` | hexadecimal (uppercase) | `printf("%X", 255);` |
| `%o` | octal | `printf("%o", 8);` |
| `%%` | literal % | `printf("50%%");` |

### Format Specifier Anatomy

A complete format specifier has this structure:
```
%[flags][width][.precision][length]specifier
```

**Example**: `%.2f` means "float with 2 decimal places"
- `%` = start of specifier
- `.2` = precision (2 decimal places)
- `f` = float/double type

### Precision Control

Control decimal places for floating-point numbers:

```c
float pi = 3.14159;

printf("%f\n", pi);      // 3.141590 (default: 6 decimals)
printf("%.1f\n", pi);    // 3.1 (1 decimal place)
printf("%.2f\n", pi);    // 3.14 (2 decimal places)
printf("%.3f\n", pi);    // 3.142 (3 decimal places)
printf("%.0f\n", pi);    // 3 (no decimal places, rounded)
```

### Width Control

Control the minimum number of characters to print:

```c
int num = 42;

printf("%d\n", num);     // "42" (no padding)
printf("%5d\n", num);    // "   42" (width 5, right-aligned)
printf("%2d\n", num);    // "42" (width smaller than number, no effect)
printf("%-5d\n", num);   // "42   " (width 5, left-aligned)
printf("%05d\n", num);   // "00042" (zero-padded, width 5)
```

### Combining Width and Precision

```c
float price = 19.5;

printf("%8.2f\n", price);    // "   19.50" (width 8, 2 decimals, right-aligned)
printf("%-8.2f\n", price);   // "19.50   " (width 8, 2 decimals, left-aligned)
printf("%08.2f\n", price);   // "00019.50" (width 8, 2 decimals, zero-padded)
```

### Practical Examples

```c
// Currency formatting
float cost = 29.99;
printf("Price: $%.2f\n", cost);  // Price: $29.99

// Temperature with 1 decimal
float temp = 72.456;
printf("Temperature: %.1f°F\n", temp);  // Temperature: 72.5°F

// Alignment in tables
printf("%-10s %8.2f\n", "Apples", 2.50);
printf("%-10s %8.2f\n", "Bananas", 1.99);
// Output:
// Apples        2.50
// Bananas       1.99

// Percentage with 1 decimal
float percent = 87.654;
printf("Score: %.1f%%\n", percent);  // Score: 87.7%
```

## scanf: Reading Input

```c
int age;
printf("Enter your age: ");
scanf("%d", &age);  // Note the & (address-of operator)
printf("You are %d years old.\n", age);
```

**Important**: Always use `&` before the variable in `scanf`!

## Type Conversion

### Implicit Conversion (Automatic)

```c
int i = 5;
float f = i;  // Automatically converts 5 to 5.0
```

### Explicit Conversion (Casting)

```c
float price = 19.99f;
int dollars = (int)price;  // 19 (fractional part discarded)

int a = 10, b = 3;
float result = (float)a / b;  // 3.333... (without cast: 3)
```

## Practical Example: Temperature Converter

```c
#include <stdio.h>

int main(void)
{
    float celsius, fahrenheit;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    
    printf("%.1f°C = %.1f°F\n", celsius, fahrenheit);
    
    return 0;
}
```

## Exercise 2.1: Rectangle Area

Write a program that calculates the area of a rectangle:

```c
#include <stdio.h>

int main(void)
{
    float length, width, area;
    
    printf("Enter length: ");
    scanf("%f", &length);
    
    printf("Enter width: ");
    scanf("%f", &width);
    
    area = length * width;
    
    printf("Area: %.2f\n", area);
    
    return 0;
}
```

## Exercise 2.2: Simple Calculator

Create a calculator that adds two numbers:

```c
#include <stdio.h>

int main(void)
{
    int num1, num2, sum;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);
    
    sum = num1 + num2;
    
    printf("%d + %d = %d\n", num1, num2, sum);
    
    return 0;
}
```

## Exercise 2.3: Integer Division Trap

What does this program output? Run it and see!

```c
#include <stdio.h>

int main(void)
{
    int a = 7, b = 2;
    int result1 = a / b;
    float result2 = a / b;
    float result3 = (float)a / b;
    
    printf("a / b = %d\n", result1);
    printf("a / b (float) = %f\n", result2);
    printf("(float)a / b = %f\n", result3);
    
    return 0;
}
```

**Lesson**: Always cast when dividing integers if you want fractional results!

## Common Mistakes

### Mistake 1: Forgetting & in scanf
```c
int age;
scanf("%d", age);  // ERROR: Missing & before age
```

### Mistake 2: Wrong Format Specifier
```c
int x = 5;
printf("%f", x);  // WRONG: %d for int, not %f
```

### Mistake 3: Uninitialized Variables
```c
int x;
printf("%d", x);  // BAD: x has undefined value
```

## Summary

You've learned:
- ✅ How to declare and initialize variables
- ✅ Basic data types (int, float, char, bool)
- ✅ Arithmetic, comparison, and logical operators
- ✅ How to print and read variables
- ✅ Type conversion and casting

**Next Chapter**: We'll learn how to make decisions with if statements!

---

# Chapter 3: Control Flow: Making Decisions

## The if Statement

Programs need to make decisions based on conditions:

```c
int age = 18;

if (age >= 18)
{
    printf("You can vote!\n");
}
```

### Syntax
```c
if (condition)
{
    // Code executes if condition is true
}
```

## if-else Statement

Execute different code based on a condition:

```c
int temperature = 30;

if (temperature > 25)
{
    printf("It's hot outside!\n");
}
else
{
    printf("It's cool outside.\n");
}
```

## if-else if-else Chain

Handle multiple conditions:

```c
int score = 85;

if (score >= 90)
{
    printf("Grade: A\n");
}
else if (score >= 80)
{
    printf("Grade: B\n");
}
else if (score >= 70)
{
    printf("Grade: C\n");
}
else if (score >= 60)
{
    printf("Grade: D\n");
}
else
{
    printf("Grade: F\n");
}
```

## switch Statement

Better for testing one variable against multiple values:

```c
char grade = 'B';

switch (grade)
{
    case 'A':
        printf("Excellent!\n");
        break;
    case 'B':
        printf("Good!\n");
        break;
    case 'C':
        printf("Fair.\n");
        break;
    case 'D':
        printf("Poor.\n");
        break;
    case 'F':
        printf("Fail.\n");
        break;
    default:
        printf("Invalid grade.\n");
        break;
}
```

**Important**: Don't forget `break`! Without it, execution "falls through" to the next case.

## The while Loop

Repeat code while a condition is true:

```c
int count = 1;

while (count <= 5)
{
    printf("Count: %d\n", count);
    count++;
}
```

Output:
```
Count: 1
Count: 2
Count: 3
Count: 4
Count: 5
```

## The for Loop

More concise when you know how many iterations:

```c
for (int i = 1; i <= 5; i++)
{
    printf("Iteration: %d\n", i);
}
```

### for Loop Anatomy
```c
for (initialization; condition; increment)
{
    // Loop body
}
```

1. **initialization**: Runs once before loop starts
2. **condition**: Checked before each iteration
3. **increment**: Runs after each iteration

### Example: Sum First 10 Numbers

```c
int sum = 0;

for (int i = 1; i <= 10; i++)
{
    sum += i;
}

printf("Sum: %d\n", sum);  // 55
```

## The do-while Loop

Executes at least once, then checks condition:

```c
int number;

do
{
    printf("Enter a positive number: ");
    scanf("%d", &number);
} while (number <= 0);

printf("You entered: %d\n", number);
```

**Key Difference**: `do-while` guarantees at least one execution.

## break and continue

### break: Exit Loop Early

```c
for (int i = 1; i <= 10; i++)
{
    if (i == 5)
    {
        break;  // Exit loop when i is 5
    }
    printf("%d ", i);
}
// Output: 1 2 3 4
```

### continue: Skip Current Iteration

```c
for (int i = 1; i <= 5; i++)
{
    if (i == 3)
    {
        continue;  // Skip when i is 3
    }
    printf("%d ", i);
}
// Output: 1 2 4 5
```

## Nested Loops

Loops inside loops:

```c
// Multiplication table
for (int i = 1; i <= 5; i++)
{
    for (int j = 1; j <= 5; j++)
    {
        printf("%3d ", i * j);
    }
    printf("\n");
}
```

Output:
```
  1   2   3   4   5
  2   4   6   8  10
  3   6   9  12  15
  4   8  12  16  20
  5  10  15  20  25
```

## Practical Examples

### Example 1: Number Guessing Game

```c
#include <stdio.h>

int main(void)
{
    int secret = 42;
    int guess;
    int attempts = 0;
    
    printf("Guess the number (1-100): \n");
    
    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < secret)
        {
            printf("Too low! Try again.\n");
        }
        else if (guess > secret)
        {
            printf("Too high! Try again.\n");
        }
    } while (guess != secret);
    
    printf("Correct! You guessed in %d attempts.\n", attempts);
    
    return 0;
}
```

### Example 2: Menu System

```c
#include <stdio.h>

int main(void)
{
    int choice;
    
    do
    {
        printf("\n=== Menu ===\n");
        printf("1. Say Hello\n");
        printf("2. Show Date\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Hello, World!\n");
                break;
            case 2:
                printf("Today is a great day!\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}
```

## Exercise 3.1: Even or Odd

Write a program that checks if a number is even or odd:

```c
#include <stdio.h>

int main(void)
{
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number % 2 == 0)
    {
        printf("%d is even.\n", number);
    }
    else
    {
        printf("%d is odd.\n", number);
    }
    
    return 0;
}
```

## Exercise 3.2: Factorial Calculator

Calculate factorial using a loop:

```c
#include <stdio.h>

int main(void)
{
    int n;
    long factorial = 1;
    
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    
    printf("%d! = %ld\n", n, factorial);
    
    return 0;
}
```

## Exercise 3.3: Prime Number Checker

Check if a number is prime:

```c
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int number;
    bool isPrime = true;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    if (number <= 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime)
    {
        printf("%d is prime.\n", number);
    }
    else
    {
        printf("%d is not prime.\n", number);
    }
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Assignment in Condition
```c
int x = 5;
if (x = 10)  // BUG: Should be x == 10
{
    // Always executes!
}
```

### Mistake 2: Missing Braces
```c
if (condition)
    statement1;
    statement2;  // NOT part of if!
```

Always use braces to be clear:
```c
if (condition)
{
    statement1;
    statement2;
}
```

### Mistake 3: Infinite Loops
```c
int i = 0;
while (i < 10)
{
    printf("%d\n", i);
    // Forgot to increment i!
}
```

## Summary

You've learned:
- ✅ How to make decisions with if/else
- ✅ Multiple conditions with switch
- ✅ Repeating code with while, for, and do-while loops
- ✅ Controlling loops with break and continue
- ✅ Building practical programs with control flow

**Next Chapter**: Functions - organizing code into reusable pieces!

---

# Chapter 4: Functions: Building Blocks of Programs

## What Are Functions?

Functions are reusable blocks of code that perform specific tasks. They help:
- **Organize** code into logical pieces
- **Reuse** code instead of repeating it
- **Test** individual pieces independently
- **Maintain** code more easily

## Function Basics

### Syntax
```c
return_type function_name(parameters)
{
    // Function body
    return value;
}
```

### Simple Example
```c
int add(int a, int b)
{
    int sum = a + b;
    return sum;
}

int main(void)
{
    int result = add(5, 3);
    printf("5 + 3 = %d\n", result);  // Output: 5 + 3 = 8
    return 0;
}
```

## Function Components

### Return Type
The type of value the function returns:

```c
int getAge()          // Returns an integer
float getPrice()      // Returns a float
void printMessage()   // Returns nothing (void)
```

### Parameters
Values passed to the function:

```c
// No parameters
void sayHello()
{
    printf("Hello!\n");
}

// One parameter
void greet(char* name)
{
    printf("Hello, %s!\n", name);
}

// Multiple parameters
int multiply(int x, int y)
{
    return x * y;
}
```

### Return Statement
Exits the function and optionally returns a value:

```c
int square(int x)
{
    return x * x;  // Returns x squared
}

void printHeader()
{
    printf("=== HEADER ===\n");
    return;  // Optional for void functions
}
```

## Function Declaration vs Definition

### Declaration (Prototype)
Tells compiler the function exists:

```c
int add(int a, int b);  // Declaration
```

### Definition
The actual function implementation:

```c
int add(int a, int b)   // Definition
{
    return a + b;
}
```

### Complete Example
```c
#include <stdio.h>

// Function declarations (prototypes)
int add(int a, int b);
int subtract(int a, int b);

int main(void)
{
    int result1 = add(10, 5);
    int result2 = subtract(10, 5);
    
    printf("10 + 5 = %d\n", result1);
    printf("10 - 5 = %d\n", result2);
    
    return 0;
}

// Function definitions
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}
```

## Pass by Value

In C, parameters are passed by value (copied):

```c
void modifyValue(int x)
{
    x = 100;  // Only modifies local copy
    printf("Inside function: %d\n", x);
}

int main(void)
{
    int num = 5;
    modifyValue(num);
    printf("Outside function: %d\n", num);  // Still 5!
    return 0;
}
```

Output:
```
Inside function: 100
Outside function: 5
```

## Scope and Lifetime

### Local Variables
Variables declared inside a function:

```c
void myFunction()
{
    int local = 10;  // Only exists in this function
}

int main(void)
{
    // printf("%d", local);  // ERROR: local doesn't exist here
    return 0;
}
```

### Global Variables
Variables declared outside all functions:

```c
int global = 100;  // Available everywhere

void printGlobal()
{
    printf("Global: %d\n", global);
}

int main(void)
{
    printf("Global: %d\n", global);
    printGlobal();
    return 0;
}
```

**Warning**: Use global variables sparingly! They make code harder to understand and debug.

## Practical Examples

### Example 1: Temperature Converter Functions

```c
#include <stdio.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);

int main(void)
{
    float temp;
    int choice;
    
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    printf("Enter temperature: ");
    scanf("%f", &temp);
    
    if (choice == 1)
    {
        float result = celsiusToFahrenheit(temp);
        printf("%.1f°C = %.1f°F\n", temp, result);
    }
    else if (choice == 2)
    {
        float result = fahrenheitToCelsius(temp);
        printf("%.1f°F = %.1f°C\n", temp, result);
    }
    
    return 0;
}

float celsiusToFahrenheit(float celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
```

### Example 2: Math Helper Functions

```c
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isEven(int number);
bool isPrime(int number);
int factorial(int n);

int main(void)
{
    int num = 17;
    
    printf("%d is %s\n", num, isEven(num) ? "even" : "odd");
    printf("%d is %s\n", num, isPrime(num) ? "prime" : "not prime");
    printf("%d! = %d\n", 5, factorial(5));
    
    return 0;
}

bool isEven(int number)
{
    return (number % 2 == 0);
}

bool isPrime(int number)
{
    if (number <= 1)
        return false;
    
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    
    return true;
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    
    return result;
}
```

## Recursion

A function can call itself:

```c
int factorial(int n)
{
    if (n <= 1)
        return 1;  // Base case
    
    return n * factorial(n - 1);  // Recursive case
}
```

**How it works:**
```
factorial(5)
= 5 * factorial(4)
= 5 * (4 * factorial(3))
= 5 * (4 * (3 * factorial(2)))
= 5 * (4 * (3 * (2 * factorial(1))))
= 5 * (4 * (3 * (2 * 1)))
= 120
```

## Exercise 4.1: Calculator Functions

Create a calculator with functions:

```c
#include <stdio.h>

// Function prototypes
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main(void)
{
    float num1, num2;
    char op;
    
    printf("Enter calculation (e.g., 5 + 3): ");
    scanf("%f %c %f", &num1, &op, &num2);
    
    float result;
    
    switch (op)
    {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    
    printf("Result: %.2f\n", result);
    
    return 0;
}

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    if (b == 0)
    {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}
```

## Exercise 4.2: Min/Max Functions

Write functions to find minimum and maximum:

```c
#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    int x = 10, y = 20;
    printf("Min: %d\n", min(x, y));
    printf("Max: %d\n", max(x, y));
    return 0;
}
```

## Exercise 4.3: Power Function

Implement power function (x^n):

```c
#include <stdio.h>

double power(double base, int exponent)
{
    double result = 1.0;
    
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    
    return result;
}

int main(void)
{
    printf("2^8 = %.0f\n", power(2, 8));
    printf("3.5^3 = %.2f\n", power(3.5, 3));
    return 0;
}
```

## Summary

You've learned:
- ✅ How to declare and define functions
- ✅ Function parameters and return values
- ✅ Pass by value concept
- ✅ Variable scope (local vs global)
- ✅ How to organize code with functions
- ✅ Recursion basics

**Next Chapter**: Arrays - working with collections of data!

---

# Chapter 5: Arrays: Working with Multiple Values

## What Are Arrays?

Arrays store multiple values of the same type in **contiguous memory**:

```c
int numbers[5];  // Array of 5 integers
```

### Memory Layout: How Arrays Are Stored

```
┌────────────────────────────────────────────────────────────────┐
│          ARRAY IN CONTIGUOUS MEMORY (int numbers[5])           │
├─────────┬────────┬─────────┬──────────────────────────────────┤
│ Address │ Value  │  Index  │          Variable Name           │
├─────────┼────────┼─────────┼──────────────────────────────────┤
│ 0x1000  │   10   │    0    │  numbers[0]                      │
│ 0x1004  │   20   │    1    │  numbers[1]                      │
│ 0x1008  │   30   │    2    │  numbers[2]                      │
│ 0x100C  │   40   │    3    │  numbers[3]                      │
│ 0x1010  │   50   │    4    │  numbers[4]                      │
└─────────┴────────┴─────────┴──────────────────────────────────┘
  ^                                          ^
  │                                          │
  numbers (base address)              Last element
  Array starts here                   (base + 4*sizeof(int))

Visual representation:
     numbers
       │
       ▼
   ┌──────┬──────┬──────┬──────┬──────┐
   │  10  │  20  │  30  │  40  │  50  │  ◄── Contiguous in memory
   └──────┴──────┴──────┴──────┴──────┘
   [0]    [1]    [2]    [3]    [4]      ◄── Indices (0-based)
   0x1000 0x1004 0x1008 0x100C 0x1010   ◄── Actual addresses

🔑 Key Facts:
   • Elements are stored back-to-back in memory
   • Each int takes 4 bytes (on most systems)
   • Array name (numbers) = address of first element
   • numbers[i] is at address: numbers + (i * sizeof(int))
```

## Array Declaration and Initialization

### Declaration
```c
int scores[10];        // Array of 10 integers (uninitialized)
float prices[5];       // Array of 5 floats
char letters[26];      // Array of 26 characters
```

### Initialization
```c
// Initialize all elements
int numbers[5] = {10, 20, 30, 40, 50};

// Partial initialization (rest are zero)
int values[5] = {1, 2};  // {1, 2, 0, 0, 0}

// Let compiler count elements
int data[] = {1, 2, 3, 4};  // Size is 4

// Initialize all to zero
int zeros[100] = {0};
```

## Accessing Array Elements

Arrays are **zero-indexed** (first element is at index 0):

```c
int numbers[5] = {10, 20, 30, 40, 50};

printf("%d\n", numbers[0]);  // 10 (first element)
printf("%d\n", numbers[1]);  // 20
printf("%d\n", numbers[4]);  // 50 (last element)

// Modify elements
numbers[2] = 99;
printf("%d\n", numbers[2]);  // 99
```

## Iterating Through Arrays

### Using for Loop

```c
int scores[5] = {85, 90, 78, 92, 88};

// Print all elements
for (int i = 0; i < 5; i++)
{
    printf("Score %d: %d\n", i + 1, scores[i]);
}

// Calculate sum
int sum = 0;
for (int i = 0; i < 5; i++)
{
    sum += scores[i];
}
float average = sum / 5.0;
printf("Average: %.1f\n", average);
```

## Array Size

```c
int numbers[] = {1, 2, 3, 4, 5};

// Get number of elements
int size = sizeof(numbers) / sizeof(numbers[0]);
printf("Array size: %d\n", size);  // 5
```

**How it works:**
- `sizeof(numbers)`: Total bytes (e.g., 20 bytes for 5 ints)
- `sizeof(numbers[0])`: Bytes per element (e.g., 4 bytes for int)
- Division gives number of elements

## Multi-Dimensional Arrays

### Two-Dimensional Arrays (Matrices)

```c
// 3x4 matrix (3 rows, 4 columns)
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Access elements
printf("%d\n", matrix[0][0]);  // 1
printf("%d\n", matrix[1][2]);  // 7
printf("%d\n", matrix[2][3]);  // 12
```

### Memory Layout: 2D Arrays

```
LOGICAL VIEW (how we think about it):
┌────┬────┬────┬────┐
│  1 │  2 │  3 │  4 │  Row 0
├────┼────┼────┼────┤
│  5 │  6 │  7 │  8 │  Row 1
├────┼────┼────┼────┤
│  9 │ 10 │ 11 │ 12 │  Row 2
└────┴────┴────┴────┘
Col  0    1    2    3

PHYSICAL MEMORY (how it's actually stored - ROW-MAJOR ORDER):
┌───────────────────────────────────────────────────────────────┐
│              matrix[3][4] in Contiguous Memory                │
├─────────┬─────┬──────────┬──────────────────────────────────┤
│ Address │Value│  Access  │       Description                │
├─────────┼─────┼──────────┼──────────────────────────────────┤
│ 0x1000  │  1  │matrix[0][0]│ Row 0, Column 0               │
│ 0x1004  │  2  │matrix[0][1]│ Row 0, Column 1               │
│ 0x1008  │  3  │matrix[0][2]│ Row 0, Column 2               │
│ 0x100C  │  4  │matrix[0][3]│ Row 0, Column 3               │
│ 0x1010  │  5  │matrix[1][0]│ Row 1, Column 0               │
│ 0x1014  │  6  │matrix[1][1]│ Row 1, Column 1               │
│ 0x1018  │  7  │matrix[1][2]│ Row 1, Column 2               │
│ 0x101C  │  8  │matrix[1][3]│ Row 1, Column 3               │
│ 0x1020  │  9  │matrix[2][0]│ Row 2, Column 0               │
│ 0x1024  │ 10  │matrix[2][1]│ Row 2, Column 1               │
│ 0x1028  │ 11  │matrix[2][2]│ Row 2, Column 2               │
│ 0x102C  │ 12  │matrix[2][3]│ Row 2, Column 3               │
└─────────┴─────┴──────────┴──────────────────────────────────┘
    │       └───── Row 0 ────┘└───── Row 1 ────┘└───── Row 2 ────┘
    │
    matrix (base address)

Address calculation: matrix[row][col] = base + (row * 4 + col) * sizeof(int)
Example: matrix[1][2] = 0x1000 + (1*4 + 2)*4 = 0x1000 + 24 = 0x1018 ✓

🔑 Key: 2D arrays are stored as a single contiguous block in row-major order!
```

### Iterating Through 2D Arrays

```c
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

for (int row = 0; row < 3; row++)
{
    for (int col = 0; col < 4; col++)
    {
        printf("%3d ", matrix[row][col]);
    }
    printf("\n");
}
```

Output:
```
  1   2   3   4
  5   6   7   8
  9  10  11  12
```

## Arrays and Functions

Arrays are passed to functions by reference (more on this in Chapter 6):

```c
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void modifyArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= 2;  // Modifies original array!
    }
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printArray(numbers, size);      // 1 2 3 4 5
    modifyArray(numbers, size);
    printArray(numbers, size);      // 2 4 6 8 10
    
    return 0;
}
```

## Common Array Operations

### Finding Maximum

```c
int findMax(int arr[], int size)
{
    int max = arr[0];
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}
```

### Searching for a Value

```c
int search(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;  // Return index where found
        }
    }
    
    return -1;  // Not found
}
```

### Reversing an Array

```c
void reverse(int arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        // Swap arr[i] with arr[size - 1 - i]
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
```

## Practical Example: Grade Manager

```c
#include <stdio.h>

#define MAX_STUDENTS 50

float calculateAverage(float grades[], int count)
{
    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += grades[i];
    }
    return sum / count;
}

int countAboveAverage(float grades[], int count, float average)
{
    int countAbove = 0;
    for (int i = 0; i < count; i++)
    {
        if (grades[i] > average)
        {
            countAbove++;
        }
    }
    return countAbove;
}

int main(void)
{
    float grades[MAX_STUDENTS];
    int numStudents;
    
    printf("How many students? ");
    scanf("%d", &numStudents);
    
    if (numStudents > MAX_STUDENTS)
    {
        printf("Too many students!\n");
        return 1;
    }
    
    // Input grades
    for (int i = 0; i < numStudents; i++)
    {
        printf("Enter grade for student %d: ", i + 1);
        scanf("%f", &grades[i]);
    }
    
    // Calculate and display statistics
    float average = calculateAverage(grades, numStudents);
    int above = countAboveAverage(grades, numStudents, average);
    
    printf("\nStatistics:\n");
    printf("Average: %.2f\n", average);
    printf("Students above average: %d\n", above);
    
    return 0;
}
```

## Exercise 5.1: Array Sum and Product

Calculate sum and product of array elements:

```c
#include <stdio.h>

int main(void)
{
    int numbers[] = {2, 4, 6, 8, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int sum = 0;
    int product = 1;
    
    for (int i = 0; i < size; i++)
    {
        sum += numbers[i];
        product *= numbers[i];
    }
    
    printf("Sum: %d\n", sum);          // 30
    printf("Product: %d\n", product);  // 3840
    
    return 0;
}
```

## Exercise 5.2: Bubble Sort

Implement simple sorting:

```c
#include <stdio.h>

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Before sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    bubbleSort(numbers, size);
    
    printf("After sorting: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Exercise 5.3: Matrix Addition

Add two matrices:

```c
#include <stdio.h>

#define ROWS 2
#define COLS 3

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int matrix[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[ROWS][COLS] = {{7, 8, 9}, {10, 11, 12}};
    int result[ROWS][COLS];
    
    addMatrices(matrix1, matrix2, result);
    
    printf("Matrix 1:\n");
    printMatrix(matrix1);
    
    printf("\nMatrix 2:\n");
    printMatrix(matrix2);
    
    printf("\nSum:\n");
    printMatrix(result);
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Out of Bounds Access
```c
int arr[5] = {1, 2, 3, 4, 5};
printf("%d", arr[5]);  // ERROR: Index 5 doesn't exist!
// Valid indices: 0, 1, 2, 3, 4
```

### Mistake 2: Forgetting Array Size
```c
void printArray(int arr[])  // Size information lost!
{
    // sizeof(arr) doesn't work here!
}
```

Always pass size as separate parameter:
```c
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
```

### Mistake 3: Uninitialized Arrays
```c
int arr[5];
for (int i = 0; i < 5; i++)
{
    printf("%d ", arr[i]);  // Garbage values!
}
```

Initialize arrays:
```c
int arr[5] = {0};  // All zeros
```

## Summary

You've learned:
- ✅ How to declare and initialize arrays
- ✅ Accessing and modifying array elements
- ✅ Iterating through arrays with loops
- ✅ Multi-dimensional arrays (matrices)
- ✅ Passing arrays to functions
- ✅ Common array operations (search, sort, etc.)

**Next Chapter**: Pointers - the most powerful feature of C!

---

# Chapter 6: Pointers: The Heart of C

## What Are Pointers?

A pointer is a variable that stores a **memory address**:

```c
int age = 25;        // Regular variable
int* pAge = &age;    // Pointer to age
```

### Visual Memory Layout

```
┌─────────────────────────────────────────────────────────────┐
│                    MEMORY LAYOUT                             │
├─────────────┬─────────────┬──────────────┬──────────────────┤
│  Address    │    Value    │   Variable   │   Description    │
├─────────────┼─────────────┼──────────────┼──────────────────┤
│  0x1000     │     25      │     age      │  Integer value   │
│  0x2000     │   0x1000    │    pAge      │  Pointer to age  │
└─────────────┴─────────────┴──────────────┴──────────────────┘

Visual flow:
    age                     pAge
  ┌──────┐                ┌──────┐
  │  25  │ ◄──────────────│0x1000│
  └──────┘                └──────┘
  @0x1000                 @0x2000
```

**Key Insight**: `pAge` doesn't contain 25, it contains the **address** of `age` (0x1000).

### Memory Layout: Multiple Pointers

```c
int x = 10;
int* p1 = &x;
int* p2 = &x;
int** pp = &p1;  // Pointer to pointer!
```

```
┌──────────────────────────────────────────────────────────────────┐
│                   MULTI-LEVEL POINTER LAYOUT                      │
├──────────┬──────────┬──────────┬───────────────────────────────┤
│ Address  │  Value   │ Variable │        Explanation            │
├──────────┼──────────┼──────────┼───────────────────────────────┤
│ 0x1000   │   10     │    x     │  The actual integer           │
│ 0x2000   │ 0x1000   │    p1    │  Points to x                  │
│ 0x3000   │ 0x1000   │    p2    │  Also points to x             │
│ 0x4000   │ 0x2000   │    pp    │  Points to p1 (pointer->ptr)  │
└──────────┴──────────┴──────────┴───────────────────────────────┘

Visual representation:
         pp               p1                x
       ┌──────┐         ┌──────┐         ┌──────┐
       │0x2000│────────►│0x1000│────────►│  10  │
       └──────┘         └──────┘         └──────┘
       @0x4000          @0x2000          @0x1000
                          ▲
                          │
                        p2│
                       ┌──────┐
                       │0x1000│
                       └──────┘
                       @0x3000

To access x: *p1 or *p2
To access x through pp: **pp (dereference twice)
```

## The Two Key Operators

### & (Address-of Operator)

Gets the memory address of a variable:

```c
int x = 42;
printf("Value: %d\n", x);          // 42
printf("Address: %p\n", (void*)&x); // 0x7ffc3a5b2c (example address)
```

### * (Dereference Operator)

Accesses the value at a memory address:

```c
int x = 42;
int* ptr = &x;      // ptr points to x

printf("%d\n", x);    // 42 (direct access)
printf("%d\n", *ptr); // 42 (through pointer)

*ptr = 100;           // Modify x through pointer
printf("%d\n", x);    // 100 (x has changed!)
```

## Pointer Declaration

```c
int* ptr1;      // Pointer to int
float* ptr2;    // Pointer to float
char* ptr3;     // Pointer to char

// These are all equivalent:
int *ptr4;
int * ptr5;
int*ptr6;
```

**Style tip**: Use `int* ptr` to emphasize "pointer to int".

## NULL Pointers

Always initialize pointers:

```c
int* ptr = NULL;  // Points to nothing

if (ptr == NULL)
{
    printf("Pointer is null\n");
}

// Dereferencing NULL crashes the program!
// *ptr = 10;  // DON'T DO THIS!
```

## Pointers and Functions

### Passing by Reference

Remember Chapter 4? Parameters are passed by value:

```c
void tryToModify(int x)
{
    x = 100;  // Only modifies local copy
}

int main(void)
{
    int num = 5;
    tryToModify(num);
    printf("%d\n", num);  // Still 5
    return 0;
}
```

With pointers, we can actually modify the original:

```c
void modify(int* x)
{
    *x = 100;  // Modifies value at address
}

int main(void)
{
    int num = 5;
    modify(&num);       // Pass address
    printf("%d\n", num); // Now 100!
    return 0;
}
```

### Example: Swap Function

```c
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 10, y = 20;
    
    printf("Before: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("After: x=%d, y=%d\n", x, y);
    
    return 0;
}
```

Output:
```
Before: x=10, y=20
After: x=20, y=10
```

### Memory Diagram: How swap() Works

```
BEFORE SWAP:
┌─────────────────────────────────────────────────────────┐
│  main() stack frame                                     │
├──────────┬──────────┬──────────┬─────────────────────────┤
│ Address  │  Value   │ Variable │     Description         │
├──────────┼──────────┼──────────┼─────────────────────────┤
│ 0x1000   │    10    │    x     │  First number           │
│ 0x1004   │    20    │    y     │  Second number          │
└──────────┴──────────┴──────────┴─────────────────────────┘

CALLING swap(&x, &y):
┌─────────────────────────────────────────────────────────┐
│  swap() stack frame                                     │
├──────────┬──────────┬──────────┬─────────────────────────┤
│ Address  │  Value   │ Variable │     Description         │
├──────────┼──────────┼──────────┼─────────────────────────┤
│ 0x2000   │ 0x1000   │    a     │  Pointer to x           │
│ 0x2004   │ 0x1004   │    b     │  Pointer to y           │
│ 0x2008   │    10    │   temp   │  Temporary storage      │
└──────────┴──────────┴──────────┴─────────────────────────┘
          │           │
          │           └──────────┐
          └──────┐               │
                 ▼               ▼
┌──────────┬──────────┬──────────┬─────────────────────────┐
│ 0x1000   │    10    │    x     │ ◄── *a points here      │
│ 0x1004   │    20    │    y     │ ◄── *b points here      │
└──────────┴──────────┴──────────┴─────────────────────────┘

STEP 1: temp = *a  (save value at address a)
STEP 2: *a = *b    (write value from address b to address a)
STEP 3: *b = temp  (write saved value to address b)

AFTER SWAP:
┌─────────────────────────────────────────────────────────┐
│  main() stack frame                                     │
├──────────┬──────────┬──────────┬─────────────────────────┤
│ Address  │  Value   │ Variable │     Description         │
├──────────┼──────────┼──────────┼─────────────────────────┤
│ 0x1000   │    20    │    x     │  Now contains 20!       │
│ 0x1004   │    10    │    y     │  Now contains 10!       │
└──────────┴──────────┴──────────┴─────────────────────────┘

🔑 Key: Pointers let functions modify variables in the caller's scope!
```

## Pointers and Arrays

**Key Concept**: An array name is a pointer to its first element!

```c
int numbers[5] = {10, 20, 30, 40, 50};

// These are equivalent:
printf("%d\n", numbers[0]);   // 10
printf("%d\n", *numbers);     // 10

// These are equivalent:
printf("%d\n", numbers[2]);   // 30
printf("%d\n", *(numbers + 2)); // 30
```

### Pointer Arithmetic

```c
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr;  // Points to arr[0]

printf("%d\n", *ptr);       // 10
ptr++;                      // Move to next element
printf("%d\n", *ptr);       // 20
ptr += 2;                   // Move 2 elements forward
printf("%d\n", *ptr);       // 40
```

#### Memory Layout: Array and Pointer Arithmetic

```
┌────────────────────────────────────────────────────────────────────┐
│                  ARRAY IN CONTIGUOUS MEMORY                        │
├─────────┬────────┬─────────┬──────────────────────────────────────┤
│ Address │ Value  │  Index  │           Access Methods             │
├─────────┼────────┼─────────┼──────────────────────────────────────┤
│ 0x1000  │   10   │  arr[0] │  *arr or *(arr+0) or *ptr            │
│ 0x1004  │   20   │  arr[1] │  *(arr+1) or arr[1] or *(ptr+1)      │
│ 0x1008  │   30   │  arr[2] │  *(arr+2) or arr[2] or *(ptr+2)      │
│ 0x100C  │   40   │  arr[3] │  *(arr+3) or arr[3] or *(ptr+3)      │
│ 0x1010  │   50   │  arr[4] │  *(arr+4) or arr[4] or *(ptr+4)      │
└─────────┴────────┴─────────┴──────────────────────────────────────┘
           ▲                            ▲
           │                            │
           │                            │
       arr (base)                  After ptr++, ptr+=2
     ptr = 0x1000                   ptr = 0x100C

Visual representation:
     ptr                arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
   ┌──────┐            ┌──────┬──────┬──────┬──────┬──────┐
   │0x1000│───────────►│  10  │  20  │  30  │  40  │  50  │
   └──────┘            └──────┴──────┴──────┴──────┴──────┘
   Initially           0x1000 0x1004 0x1008 0x100C 0x1010

   After ptr++:        After ptr += 2:
   ptr = 0x1004        ptr = 0x100C
       │                   │
       ▼                   ▼
   ┌──────┬──────┬──────┬──────┬──────┐
   │  10  │  20  │  30  │  40  │  50  │
   └──────┴──────┴──────┴──────┴──────┘

🔑 Key: ptr++ adds sizeof(int) (4 bytes) to the pointer!
       ptr+2 adds 2*sizeof(int) (8 bytes)
```

### Array-Pointer Equivalence Diagram

```
┌──────────────────────────────────────────────────────────────────────┐
│            ARRAY AND POINTER RELATIONSHIP EXPLAINED                   │
└──────────────────────────────────────────────────────────────────────┘

DECLARATION:
───────────
int numbers[5] = {10, 20, 30, 40, 50};

IN MEMORY:
─────────
┌─────────────────────────────────────────────────────────────────┐
│  numbers (array name)                                           │
│     │                                                            │
│     ▼                                                            │
│  ┌──────┬──────┬──────┬──────┬──────┐                          │
│  │  10  │  20  │  30  │  40  │  50  │                          │
│  └──────┴──────┴──────┴──────┴──────┘                          │
│  [0]    [1]    [2]    [3]    [4]                                │
│  0x1000 0x1004 0x1008 0x100C 0x1010                             │
└─────────────────────────────────────────────────────────────────┘

ACCESSING ELEMENTS - ALL THESE ARE EQUIVALENT:
──────────────────────────────────────────────

Element 0:  numbers[0]   ≡   *(numbers + 0)   ≡   *(numbers)   ≡   *&numbers[0]
Element 1:  numbers[1]   ≡   *(numbers + 1)   ≡   *(numbers+1)
Element 2:  numbers[2]   ≡   *(numbers + 2)   ≡   *(numbers+2)
Element i:  numbers[i]   ≡   *(numbers + i)

FORMULA:  numbers[i]  ≡  *(numbers + i)
                      ≡  *((int*)((char*)numbers + i*sizeof(int)))

ADDRESS CALCULATION:
────────────────────
&numbers[0]  = numbers      = 0x1000
&numbers[1]  = numbers + 1  = 0x1004  (0x1000 + 1*4)
&numbers[2]  = numbers + 2  = 0x1008  (0x1000 + 2*4)
&numbers[i]  = numbers + i  = 0x1000 + i*4

WHEN PASSED TO FUNCTION:
────────────────────────
void function(int arr[5])    │  All three declarations
void function(int arr[])     │  are EXACTLY the same!
void function(int* arr)      │  Array decays to pointer
                             ▼
        ┌──────────────────────────────────┐
        │  Inside function: arr is a       │
        │  POINTER, not an array!          │
        │                                  │
        │  sizeof(arr) = sizeof(int*)      │
        │  NOT sizeof(int[5])              │
        └──────────────────────────────────┘

VISUAL: Array Decay When Passing to Function
────────────────────────────────────────────

MAIN FUNCTION:                    CALLED FUNCTION:
─────────────                    ─────────────────

int numbers[5] = {...};          void func(int* arr) {
    │                                │
    │ Pass array                     │ arr is just a pointer
    ▼                                │
┌──────┬──────┬──────┬──────┬──────┐◄┐
│  10  │  20  │  30  │  40  │  50  │ │
└──────┴──────┴──────┴──────┴──────┘ │
0x1000                                │
                                      │
func(numbers);  ──────────────────────┘
                 (Passes address 0x1000)

KEY DIFFERENCES BETWEEN ARRAYS AND POINTERS:
────────────────────────────────────────────
┌───────────────────┬─────────────────┬──────────────────────┐
│    Feature        │     Array       │       Pointer        │
├───────────────────┼─────────────────┼──────────────────────┤
│ sizeof()          │ Full array size │ Pointer size (4/8)   │
│ Declaration       │ int arr[5]      │ int* ptr             │
│ Storage           │ Stack/Data seg  │ Address only         │
│ Reassignment      │ Not allowed     │ Can point elsewhere  │
│ In function param │ Decays to ptr   │ Is already ptr       │
│ & operator        │ Gives address   │ Gives address of ptr │
└───────────────────┴─────────────────┴──────────────────────┘
```

### Iterating with Pointers

```c
int numbers[5] = {10, 20, 30, 40, 50};

// Method 1: Array indexing
for (int i = 0; i < 5; i++)
{
    printf("%d ", numbers[i]);
}

// Method 2: Pointer arithmetic
for (int* ptr = numbers; ptr < numbers + 5; ptr++)
{
    printf("%d ", *ptr);
}
```

## Pointer to Pointer (Double Pointer)

A pointer that points to another pointer:

```c
int x = 42;
int* ptr = &x;       // Pointer to x
int** pptr = &ptr;   // Pointer to ptr

printf("%d\n", x);      // 42
printf("%d\n", *ptr);   // 42
printf("%d\n", **pptr); // 42 (double dereference)
```

Visual:
```
x:     [ 42 ]
       ^
       |
ptr:   [&x ]
       ^
       |
pptr:  [&ptr]
```

### Why Double Pointers?

Used when a function needs to modify a pointer:

```c
void allocateMemory(int** ptr)
{
    *ptr = malloc(sizeof(int));  // Modify caller's pointer
    **ptr = 100;                 // Set value
}

int main(void)
{
    int* myPtr = NULL;
    allocateMemory(&myPtr);  // Pass address of pointer
    printf("%d\n", *myPtr);  // 100
    free(myPtr);
    return 0;
}
```

## Practical Example: Multiple Return Values

Functions can return multiple values using pointers:

```c
void calculate(int a, int b, int* sum, int* product, int* difference)
{
    *sum = a + b;
    *product = a * b;
    *difference = a - b;
}

int main(void)
{
    int s, p, d;
    
    calculate(10, 5, &s, &p, &d);
    
    printf("Sum: %d\n", s);         // 15
    printf("Product: %d\n", p);     // 50
    printf("Difference: %d\n", d);  // 5
    
    return 0;
}
```

## Exercise 6.1: Pointer Basics

Practice basic pointer operations:

```c
#include <stdio.h>

int main(void)
{
    int x = 10, y = 20;
    int* px = &x;
    int* py = &y;
    
    printf("x = %d, y = %d\n", x, y);
    
    // Swap values using pointers
    int temp = *px;
    *px = *py;
    *py = temp;
    
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}
```

## Exercise 6.2: Array Modification

Modify array elements using pointer arithmetic:

```c
#include <stdio.h>

void doubleValues(int* arr, int size)
{
    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        *ptr *= 2;
    }
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Before: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    doubleValues(numbers, size);
    
    printf("After: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Exercise 6.3: Min and Max with Pointers

Find minimum and maximum using pointers:

```c
#include <stdio.h>

void findMinMax(int* arr, int size, int* min, int* max)
{
    *min = *arr;
    *max = *arr;
    
    for (int* ptr = arr; ptr < arr + size; ptr++)
    {
        if (*ptr < *min) *min = *ptr;
        if (*ptr > *max) *max = *ptr;
    }
}

int main(void)
{
    int numbers[] = {45, 23, 78, 12, 90, 34};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int min, max;
    
    findMinMax(numbers, size, &min, &max);
    
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Dereferencing Uninitialized Pointers
```c
int* ptr;      // Uninitialized (points to random address)
*ptr = 42;     // CRASH! Writing to random memory
```

Always initialize:
```c
int* ptr = NULL;  // Or point to actual variable
```

### Mistake 2: Losing Pointer Value
```c
int arr[5] = {1, 2, 3, 4, 5};
int* ptr = arr;

while (*ptr != 0)  // Will go past array end!
{
    ptr++;
}
```

### Mistake 3: Pointer vs Value Confusion
```c
int x = 10;
int* ptr = &x;

printf("%d\n", ptr);   // WRONG: Prints address, not value
printf("%d\n", *ptr);  // CORRECT: Prints 10
```

## Memory Diagram Practice

Given this code:
```c
int a = 5;
int b = 10;
int* p1 = &a;
int* p2 = &b;
*p1 = *p2;
```

Draw the memory:
```
Before *p1 = *p2:
a: [5]  b: [10]
   ^       ^
   |       |
p1:[&a]  p2:[&b]

After *p1 = *p2:
a: [10] b: [10]
   ^       ^
   |       |
p1:[&a]  p2:[&b]
```

## Summary

You've learned:
- ✅ What pointers are and why they're important
- ✅ Address-of (&) and dereference (*) operators
- ✅ Passing by reference with pointers
- ✅ Relationship between pointers and arrays
- ✅ Pointer arithmetic
- ✅ Double pointers (pointer to pointer)

**Next Chapter**: Strings - arrays of characters!

---

# Chapter 7: Strings: Text Processing in C

## What Are Strings?

In C, strings are arrays of characters terminated by a null character (`'\0'`):

```c
char name[] = "Hello";
```

Memory layout:
```
Index:  0    1    2    3    4    5
Value: ['H']['e']['l']['l']['o']['\0']
```

The `'\0'` marks the end of the string. Without it, functions wouldn't know where the string ends!

## String Declaration and Initialization

### Method 1: Character Array with Initializer

```c
char str1[] = "Hello";  // Size is automatically 6 (5 + '\0')
char str2[10] = "Hi";   // Size is 10, only first 3 used
```

### Method 2: Character Array with Manual Initialization

```c
char str3[] = {'H', 'e', 'l', 'l', 'o', '\0'};  // Must add '\0'!
```

### Method 3: Pointer to String Literal

```c
char* str4 = "Hello";  // Points to read-only memory
```

**Important**: String literals are read-only! Don't try to modify them:

```c
char* str = "Hello";
str[0] = 'J';  // CRASH! Can't modify string literal
```

Use array form if you need to modify:

```c
char str[] = "Hello";
str[0] = 'J';  // OK! str is now "Jello"
```

## String Input/Output

### Outputting Strings

```c
char name[] = "Alice";
printf("%s\n", name);           // Alice
printf("Hello, %s!\n", name);   // Hello, Alice!
```

### Inputting Strings

#### Method 1: scanf (stops at whitespace)

```c
char name[50];
printf("Enter your name: ");
scanf("%s", name);  // Note: No & needed (array name is already pointer)
```

**Problem**: `scanf("%s", ...)` stops at first space!

```
Input:  John Smith
Result: name = "John"  (Smith is lost!)
```

#### Method 2: fgets (reads whole line)

```c
char line[100];
printf("Enter text: ");
fgets(line, sizeof(line), stdin);  // Reads up to 99 chars + '\0'
```

**fgets** reads the newline character too. You may want to remove it:

```c
// Remove trailing newline
int len = strlen(line);
if (len > 0 && line[len - 1] == '\n')
{
    line[len - 1] = '\0';
}
```

## String Library Functions

Include `<string.h>` for these functions:

### strlen - String Length

```c
char str[] = "Hello";
int len = strlen(str);  // 5 (doesn't count '\0')
```

### strcpy - String Copy

```c
char source[] = "Hello";
char dest[20];
strcpy(dest, source);  // dest now contains "Hello"
```

**Warning**: Make sure destination is large enough!

```c
char dest[3];
strcpy(dest, "Hello");  // BUFFER OVERFLOW! Dangerous!
```

### strncpy - Safe String Copy

```c
char dest[10];
strncpy(dest, "Hello World", sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';  // Ensure null termination
```

### strcat - String Concatenation

```c
char str1[20] = "Hello";
char str2[] = " World";
strcat(str1, str2);  // str1 is now "Hello World"
```

### strncat - Safe String Concatenation

```c
char str1[20] = "Hello";
strncat(str1, " World", sizeof(str1) - strlen(str1) - 1);
```

### strcmp - String Comparison

```c
char str1[] = "Apple";
char str2[] = "Banana";

int result = strcmp(str1, str2);
// result < 0 if str1 < str2 (alphabetically)
// result == 0 if str1 == str2 (equal)
// result > 0 if str1 > str2

if (strcmp(str1, str2) == 0)
{
    printf("Strings are equal\n");
}
```

**Important**: Don't use `==` to compare strings!

```c
if (str1 == str2)  // WRONG! Compares addresses, not content
if (strcmp(str1, str2) == 0)  // CORRECT!
```

### strchr - Find Character

```c
char str[] = "Hello World";
char* p = strchr(str, 'W');

if (p != NULL)
{
    printf("Found at index: %ld\n", p - str);  // 6
}
```

### strstr - Find Substring

```c
char str[] = "Hello World";
char* p = strstr(str, "World");

if (p != NULL)
{
    printf("Found substring at: %s\n", p);  // "World"
}
```

## Common String Operations

### Example 1: Converting to Uppercase

```c
void toUpper(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;  // Or use toupper() from <ctype.h>
        }
    }
}

int main(void)
{
    char text[] = "hello";
    toUpper(text);
    printf("%s\n", text);  // HELLO
    return 0;
}
```

Using `<ctype.h>`:

```c
#include <ctype.h>

void toUpper(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = toupper(str[i]);
    }
}
```

### Example 2: Counting Words

```c
#include <stdio.h>
#include <ctype.h>

int countWords(char* str)
{
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            inWord = 1;
            count++;
        }
    }
    
    return count;
}

int main(void)
{
    char text[] = "Hello World from C";
    printf("Word count: %d\n", countWords(text));  // 4
    return 0;
}
```

### Example 3: Reversing a String

```c
void reverseString(char* str)
{
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main(void)
{
    char text[] = "Hello";
    reverseString(text);
    printf("%s\n", text);  // olleH
    return 0;
}
```

## String Arrays

Array of strings (2D char array):

```c
char days[][10] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

for (int i = 0; i < 7; i++)
{
    printf("%s\n", days[i]);
}
```

Or using array of pointers:

```c
char* days[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

for (int i = 0; i < 7; i++)
{
    printf("%s\n", days[i]);
}
```

## Practical Example: Password Validator

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isValidPassword(char* password)
{
    int len = strlen(password);
    
    // Check length
    if (len < 8)
    {
        printf("Password must be at least 8 characters\n");
        return false;
    }
    
    // Check for uppercase, lowercase, and digit
    bool hasUpper = false, hasLower = false, hasDigit = false;
    
    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i])) hasUpper = true;
        if (islower(password[i])) hasLower = true;
        if (isdigit(password[i])) hasDigit = true;
    }
    
    if (!hasUpper)
    {
        printf("Password must contain uppercase letter\n");
        return false;
    }
    if (!hasLower)
    {
        printf("Password must contain lowercase letter\n");
        return false;
    }
    if (!hasDigit)
    {
        printf("Password must contain digit\n");
        return false;
    }
    
    return true;
}

int main(void)
{
    char password[100];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    if (isValidPassword(password))
    {
        printf("Valid password!\n");
    }
    else
    {
        printf("Invalid password.\n");
    }
    
    return 0;
}
```

## Exercise 7.1: String Palindrome Checker

Check if a string is a palindrome:

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* str)
{
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    
    return true;
}

int main(void)
{
    char word[100];
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    if (isPalindrome(word))
    {
        printf("%s is a palindrome\n", word);
    }
    else
    {
        printf("%s is not a palindrome\n", word);
    }
    
    return 0;
}
```

## Exercise 7.2: String Tokenization

Split a string by delimiter:

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "apple,banana,orange,grape";
    char* token;
    
    token = strtok(str, ",");
    
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    
    return 0;
}
```

Output:
```
apple
banana
orange
grape
```

## Exercise 7.3: Custom String Copy Function

Implement your own strcpy:

```c
#include <stdio.h>

void myStrcpy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Don't forget null terminator!
}

int main(void)
{
    char source[] = "Hello";
    char destination[20];
    
    myStrcpy(destination, source);
    printf("Copied: %s\n", destination);
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Forgetting Null Terminator

```c
char str[5];
str[0] = 'H';
str[1] = 'i';
// Missing '\0'!
printf("%s\n", str);  // Prints garbage after "Hi"
```

### Mistake 2: Buffer Overflow

```c
char small[5] = "Hi";
strcat(small, " World");  // OVERFLOW! Only room for 4 chars + '\0'
```

### Mistake 3: Modifying String Literals

```c
char* str = "Hello";
str[0] = 'J';  // CRASH! String literal is read-only
```

Use array instead:
```c
char str[] = "Hello";
str[0] = 'J';  // OK
```

### Mistake 4: Using == for Comparison

```c
char str1[] = "Hello";
char str2[] = "Hello";

if (str1 == str2)  // WRONG! Compares addresses
{
    // Never executes!
}

if (strcmp(str1, str2) == 0)  // CORRECT!
{
    // This works!
}
```

## Summary

You've learned:
- ✅ How strings work in C (character arrays with '\0')
- ✅ String input/output (printf, scanf, fgets)
- ✅ String library functions (strlen, strcpy, strcmp, etc.)
- ✅ Common string operations (uppercase, reverse, etc.)
- ✅ String arrays and 2D character arrays
- ✅ How to avoid common string pitfalls

**Next Chapter**: Structures - organizing related data together!

---

# Chapter 8: Structures: Organizing Related Data

## What Are Structures?

Structures (structs) let you group related data of different types:

```c
struct Person {
    char name[50];
    int age;
    float height;
};
```

Think of a struct as a custom data type that bundles related information.

### Memory Layout: How Structures Are Stored

```
┌──────────────────────────────────────────────────────────────────┐
│                   STRUCTURE MEMORY LAYOUT                         │
│                    struct Person person;                          │
├─────────┬──────────┬─────────────┬─────────────────────────────────┤
│ Offset  │   Size   │   Member    │        Description            │
├─────────┼──────────┼─────────────┼─────────────────────────────────┤
│ 0       │  50 bytes│  name[50]   │  Character array              │
│ 50      │  4 bytes │  age        │  Integer (32-bit)             │
│ 54      │  4 bytes │  height     │  Float (32-bit)               │
└─────────┴──────────┴─────────────┴─────────────────────────────────┘
Total size: 58 bytes

Visual representation (assuming struct at 0x1000):
     person
       │
       ▼
   ┌────────────────────────────────────┐
   │  name[50]                          │  0x1000 - 0x1031 (50 bytes)
   │  "Alice\0..."                      │
   ├──────────────┬─────────────────────┤
   │  age = 30    │  height = 5.6      │  0x1032-0x1035, 0x1036-0x1039
   └──────────────┴─────────────────────┘  (4 bytes each)

Memory addresses:
   person.name    @ 0x1000
   person.age     @ 0x1032  (name[0] + 50)
   person.height  @ 0x1036  (age address + 4)

🔑 Key: All members are stored together in a single memory block!
```

### Memory Layout: Structure Padding and Alignment

**Important concept**: Compilers add "padding" bytes for performance!

```c
struct Example {
    char c;      // 1 byte
    int i;       // 4 bytes
    char d;      // 1 byte
};
```

```
NAIVE LAYOUT (what you might expect - 6 bytes):
┌────┬────────────┬────┐
│ c  │     i      │ d  │
└────┴────────────┴────┘
  1       4         1    = 6 bytes total

ACTUAL LAYOUT (with padding for alignment - 12 bytes):
┌────┬────────────────┬────────────┬────┬────────────────┐
│ c  │  padding (3)   │     i      │ d  │  padding (3)   │
└────┴────────────────┴────────────┴────┴────────────────┘
  1         3              4         1          3
  
Offset:   0    1-3         4-7       8         9-11

Memory diagram:
┌──────────────────────────────────────────────────────────┐
│ Address │ Byte │  Content  │     Description            │
├─────────┼──────┼───────────┼────────────────────────────┤
│ 0x1000  │  0   │    'A'    │  c (char)                  │
│ 0x1001  │  1   │  (pad)    │  Padding for alignment     │
│ 0x1002  │  2   │  (pad)    │  Padding for alignment     │
│ 0x1003  │  3   │  (pad)    │  Padding for alignment     │
│ 0x1004  │  4   │  42       │  i (int) - byte 0          │
│ 0x1005  │  5   │  0        │  i (int) - byte 1          │
│ 0x1006  │  6   │  0        │  i (int) - byte 2          │
│ 0x1007  │  7   │  0        │  i (int) - byte 3          │
│ 0x1008  │  8   │  'B'      │  d (char)                  │
│ 0x1009  │  9   │  (pad)    │  Trailing padding          │
│ 0x100A  │  10  │  (pad)    │  Trailing padding          │
│ 0x100B  │  11  │  (pad)    │  Trailing padding          │
└─────────┴──────┴───────────┴────────────────────────────┘

Why padding? int must be aligned on 4-byte boundary (0x1004)!
Total size: 12 bytes (not 6!) - Check with sizeof(struct Example)

BETTER LAYOUT (minimize padding by ordering largest to smallest):
struct BetterExample {
    int i;       // 4 bytes
    char c;      // 1 byte
    char d;      // 1 byte
};  // Total: 8 bytes (only 2 bytes padding at end)

┌────────────┬────┬────┬────────┐
│     i      │ c  │ d  │  pad   │
└────────────┴────┴────┴────────┘
      4        1    1      2      = 8 bytes total

🔑 Tip: Order struct members from largest to smallest to minimize padding!
```

## Defining Structures

### Basic Syntax

```c
struct Person {
    char name[50];
    int age;
    float height;
};
```

### Creating Structure Variables

```c
struct Person person1;  // Declare a Person
```

### Initialization

```c
// Method 1: Initialize at declaration
struct Person person1 = {"Alice", 30, 5.6};

// Method 2: Designated initializers (C99)
struct Person person2 = {
    .name = "Bob",
    .age = 25,
    .height = 5.9
};

// Method 3: Assign after declaration
struct Person person3;
strcpy(person3.name, "Charlie");
person3.age = 35;
person3.height = 6.0;
```

## Accessing Structure Members

Use the dot (`.`) operator:

```c
struct Person person = {"Alice", 30, 5.6};

printf("Name: %s\n", person.name);     // Alice
printf("Age: %d\n", person.age);       // 30
printf("Height: %.1f\n", person.height); // 5.6

// Modify members
person.age = 31;
strcpy(person.name, "Alice Smith");
```

## typedef for Cleaner Code

Instead of writing `struct Person` every time:

```c
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Now you can use Person directly:
Person person1;
Person person2 = {"Bob", 25, 5.9};
```

**This is the recommended style!**

## Structures and Functions

### Passing by Value

```c
void printPerson(Person p)
{
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Height: %.1f\n", p.height);
}

int main(void)
{
    Person person = {"Alice", 30, 5.6};
    printPerson(person);
    return 0;
}
```

### Passing by Pointer (Efficient)

For large structures, use pointers to avoid copying:

```c
void printPerson(Person* p)
{
    printf("Name: %s\n", p->name);      // -> is used for pointer access
    printf("Age: %d\n", p->age);
    printf("Height: %.1f\n", p->height);
}

int main(void)
{
    Person person = {"Alice", 30, 5.6};
    printPerson(&person);  // Pass address
    return 0;
}
```

**Arrow Operator** (`->`):
- `p->name` is shorthand for `(*p).name`
- Used to access members through a pointer

### Returning Structures

```c
Person createPerson(char* name, int age, float height)
{
    Person p;
    strcpy(p.name, name);
    p.age = age;
    p.height = height;
    return p;
}

int main(void)
{
    Person person = createPerson("Bob", 25, 5.9);
    printPerson(&person);
    return 0;
}
```

## Nested Structures

Structures can contain other structures:

```c
typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    Date birthDate;
    float salary;
} Employee;

int main(void)
{
    Employee emp = {
        .name = "John Doe",
        .birthDate = {15, 3, 1990},
        .salary = 50000.0
    };
    
    printf("Name: %s\n", emp.name);
    printf("Birth Date: %d/%d/%d\n", 
           emp.birthDate.day,
           emp.birthDate.month,
           emp.birthDate.year);
    printf("Salary: $%.2f\n", emp.salary);
    
    return 0;
}
```

## Arrays of Structures

```c
#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 3;
    
    // Initialize students
    students[0] = (Student){"Alice", 1001, 3.8};
    students[1] = (Student){"Bob", 1002, 3.5};
    students[2] = (Student){"Charlie", 1003, 3.9};
    
    // Print all students
    for (int i = 0; i < count; i++)
    {
        printf("Student: %s (ID: %d, GPA: %.2f)\n",
               students[i].name,
               students[i].id,
               students[i].gpa);
    }
    
    return 0;
}
```

## Practical Example: Contact Management System

```c
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int count;
} ContactList;

void addContact(ContactList* list, char* name, char* phone, char* email)
{
    if (list->count >= MAX_CONTACTS)
    {
        printf("Contact list is full!\n");
        return;
    }
    
    Contact* c = &list->contacts[list->count];
    strcpy(c->name, name);
    strcpy(c->phone, phone);
    strcpy(c->email, email);
    list->count++;
    
    printf("Contact added!\n");
}

void printContact(Contact* c)
{
    printf("Name:  %s\n", c->name);
    printf("Phone: %s\n", c->phone);
    printf("Email: %s\n", c->email);
    printf("---\n");
}

void listContacts(ContactList* list)
{
    if (list->count == 0)
    {
        printf("No contacts.\n");
        return;
    }
    
    for (int i = 0; i < list->count; i++)
    {
        printf("%d. ", i + 1);
        printContact(&list->contacts[i]);
    }
}

Contact* findContact(ContactList* list, char* name)
{
    for (int i = 0; i < list->count; i++)
    {
        if (strcmp(list->contacts[i].name, name) == 0)
        {
            return &list->contacts[i];
        }
    }
    return NULL;
}

int main(void)
{
    ContactList myContacts = {.count = 0};
    
    addContact(&myContacts, "Alice", "555-1234", "alice@email.com");
    addContact(&myContacts, "Bob", "555-5678", "bob@email.com");
    addContact(&myContacts, "Charlie", "555-9012", "charlie@email.com");
    
    printf("\n=== All Contacts ===\n");
    listContacts(&myContacts);
    
    printf("\n=== Search for Bob ===\n");
    Contact* found = findContact(&myContacts, "Bob");
    if (found != NULL)
    {
        printContact(found);
    }
    else
    {
        printf("Contact not found.\n");
    }
    
    return 0;
}
```

## Structure Padding and Size

Structures may have padding for alignment:

```c
#include <stdio.h>

typedef struct {
    char c;     // 1 byte
    int i;      // 4 bytes
    char d;     // 1 byte
} Example;

int main(void)
{
    printf("Size: %zu bytes\n", sizeof(Example));
    // Might print 12 instead of 6 due to padding!
    return 0;
}
```

Memory layout (typical):
```
[c][pad][pad][pad][i][i][i][i][d][pad][pad][pad]
 1   1   1   1   4  4  4  4  1   1   1   1  = 12 bytes
```

## WinRDP Connection: Host Structure

This is how WinRDP stores RDP server information:

```c
typedef struct {
    wchar_t hostname[256];     // Server name or IP
    wchar_t description[256];  // Friendly description
} Host;
```

Loading hosts from CSV file:

```c
Host* hosts = NULL;
int hostCount = 0;

// Dynamic array that grows as needed
hosts = realloc(hosts, (hostCount + 1) * sizeof(Host));
wcscpy(hosts[hostCount].hostname, L"server1.example.com");
wcscpy(hosts[hostCount].description, L"Production Server");
hostCount++;
```

**You'll build this in Chapter 19!**

## Exercise 8.1: Rectangle Structure

Create a structure for rectangles:

```c
#include <stdio.h>

typedef struct {
    float width;
    float height;
} Rectangle;

float area(Rectangle r)
{
    return r.width * r.height;
}

float perimeter(Rectangle r)
{
    return 2 * (r.width + r.height);
}

int main(void)
{
    Rectangle rect = {5.0, 3.0};
    
    printf("Area: %.2f\n", area(rect));
    printf("Perimeter: %.2f\n", perimeter(rect));
    
    return 0;
}
```

## Exercise 8.2: Book Database

Create a simple book database:

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[50];
    int year;
    float price;
} Book;

void printBook(Book* b)
{
    printf("Title:  %s\n", b->title);
    printf("Author: %s\n", b->author);
    printf("Year:   %d\n", b->year);
    printf("Price:  $%.2f\n", b->price);
    printf("---\n");
}

int main(void)
{
    Book books[3] = {
        {"The C Programming Language", "K&R", 1978, 59.99},
        {"C Primer Plus", "Stephen Prata", 2013, 49.99},
        {"Expert C Programming", "Peter van der Linden", 1994, 44.99}
    };
    
    for (int i = 0; i < 3; i++)
    {
        printBook(&books[i]);
    }
    
    return 0;
}
```

## Exercise 8.3: Linked List Node

Introduction to linked lists:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;  // Pointer to next node
} Node;

Node* createNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void)
{
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    
    printList(head);  // 1 -> 2 -> 3 -> NULL
    
    // Free memory (we'll cover this properly in Chapter 9)
    Node* current = head;
    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Forgetting -> with Pointers

```c
Person* p = &person;
printf("%s", p.name);  // WRONG! Use -> for pointers
printf("%s", p->name); // CORRECT!
```

### Mistake 2: Comparing Structs with ==

```c
Person p1 = {"Alice", 30, 5.6};
Person p2 = {"Alice", 30, 5.6};

if (p1 == p2)  // ERROR! Can't compare structs directly
```

Write a comparison function instead:

```c
bool equalPersons(Person* p1, Person* p2)
{
    return strcmp(p1->name, p2->name) == 0 &&
           p1->age == p2->age &&
           p1->height == p2->height;
}
```

### Mistake 3: Returning Pointer to Local Variable

```c
Person* createPerson()
{
    Person p = {"Alice", 30, 5.6};
    return &p;  // DANGER! p is destroyed when function returns
}
```

Return by value or use dynamic allocation:

```c
Person createPerson()  // Return by value (OK)
{
    Person p = {"Alice", 30, 5.6};
    return p;
}

Person* createPerson()  // Dynamic allocation (OK)
{
    Person* p = malloc(sizeof(Person));
    strcpy(p->name, "Alice");
    p->age = 30;
    p->height = 5.6;
    return p;
}
```

## Summary

You've learned:
- ✅ What structures are and why they're useful
- ✅ How to define and use structures
- ✅ typedef for cleaner code
- ✅ Passing structures to functions (by value and by pointer)
- ✅ Nested structures and arrays of structures
- ✅ The arrow operator (->) for pointer member access
- ✅ How structures are used in real programs (WinRDP example)

**Congratulations!** You've completed Part I (C Fundamentals)! You now understand:
- Variables and data types
- Control flow (if, loops)
- Functions
- Arrays
- Pointers
- Strings
- Structures

**Next: Part II - Advanced C Concepts!**

---

# Part II: Advanced C Concepts

# Chapter 9: Dynamic Memory Management

## Why Dynamic Memory?

So far, we've used **static memory** (arrays with fixed size):

```c
int numbers[100];  // What if we need 200? Or only 10?
```

**Dynamic memory** lets us allocate memory at runtime based on actual needs:

```c
int size;
printf("How many numbers? ");
scanf("%d", &size);
int* numbers = malloc(size * sizeof(int));  // Allocate exactly what we need!
```

## The Stack vs The Heap

### Stack Memory (Automatic)
- Local variables
- Fixed size
- Automatically freed when function returns
- Fast but limited

```c
void function()
{
    int x = 10;  // On stack
    // Automatically freed when function ends
}
```

### Heap Memory (Dynamic)
- Allocated with malloc/calloc
- Variable size
- Must be manually freed
- Slower but flexible

```c
int* ptr = malloc(100 * sizeof(int));  // On heap
// Must free manually!
free(ptr);
```

## malloc - Memory Allocation

Allocates uninitialized memory:

```c
#include <stdlib.h>

int* numbers = malloc(5 * sizeof(int));
if (numbers == NULL)
{
    printf("Memory allocation failed!\n");
    return 1;
}

// Use the memory
numbers[0] = 10;
numbers[1] = 20;
// ...

free(numbers);  // Always free!
```

**Important**: Always check if `malloc` returns `NULL` (allocation failed)!

## calloc - Cleared Allocation

Like `malloc`, but initializes memory to zero:

```c
int* numbers = calloc(5, sizeof(int));
// All elements are 0
```

**Syntax**: `calloc(count, size_per_element)`

## realloc - Resize Memory

Change the size of allocated memory:

```c
int* numbers = malloc(5 * sizeof(int));

// Need more space!
numbers = realloc(numbers, 10 * sizeof(int));

if (numbers == NULL)
{
    printf("Reallocation failed!\n");
    return 1;
}

free(numbers);
```

**How realloc works**:
1. Allocates new block (if needed)
2. Copies old data to new block
3. Frees old block
4. Returns pointer to new block

## free - Deallocate Memory

**Critical**: Always free dynamically allocated memory!

```c
int* ptr = malloc(sizeof(int) * 100);
// Use ptr...
free(ptr);
ptr = NULL;  // Good practice: prevent use after free
```

## Dynamic Arrays

Creating a growable array:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* arr = NULL;
    int capacity = 0;
    int size = 0;
    
    // Add elements dynamically
    for (int i = 0; i < 10; i++)
    {
        if (size >= capacity)
        {
            // Grow array
            capacity = (capacity == 0) ? 1 : capacity * 2;
            arr = realloc(arr, capacity * sizeof(int));
            
            if (arr == NULL)
            {
                printf("Allocation failed!\n");
                return 1;
            }
        }
        
        arr[size++] = i * 10;
    }
    
    // Print array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    return 0;
}
```

## Memory Leaks

**Memory leak**: Allocated memory that's never freed.

```c
void leakyFunction()
{
    int* ptr = malloc(1000 * sizeof(int));
    // Forgot to free!
}  // Memory is lost forever!

int main(void)
{
    for (int i = 0; i < 1000; i++)
    {
        leakyFunction();  // Leaks 4KB each iteration!
    }
    return 0;
}
```

**How to prevent**:
- Every `malloc` must have a matching `free`
- Use tools like Valgrind to detect leaks
- Set freed pointers to NULL

## Dynamic Strings

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createString(const char* str)
{
    char* copy = malloc((strlen(str) + 1) * sizeof(char));
    if (copy != NULL)
    {
        strcpy(copy, str);
    }
    return copy;
}

int main(void)
{
    char* greeting = createString("Hello, World!");
    printf("%s\n", greeting);
    free(greeting);
    return 0;
}
```

## Dynamic Structures

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int age;
} Person;

Person* createPerson(const char* name, int age)
{
    Person* p = malloc(sizeof(Person));
    if (p == NULL) return NULL;
    
    p->name = malloc(strlen(name) + 1);
    if (p->name == NULL)
    {
        free(p);
        return NULL;
    }
    
    strcpy(p->name, name);
    p->age = age;
    
    return p;
}

void freePerson(Person* p)
{
    if (p != NULL)
    {
        free(p->name);  // Free nested allocation first!
        free(p);
    }
}

int main(void)
{
    Person* person = createPerson("Alice", 30);
    printf("Name: %s, Age: %d\n", person->name, person->age);
    freePerson(person);
    return 0;
}
```

## WinRDP Connection: Dynamic Host List

WinRDP uses dynamic allocation for its host list:

```c
typedef struct {
    wchar_t hostname[256];
    wchar_t description[256];
} Host;

Host* hosts = NULL;
int hostCount = 0;

void addHost(const wchar_t* hostname, const wchar_t* description)
{
    // Grow array
    Host* temp = realloc(hosts, (hostCount + 1) * sizeof(Host));
    if (temp == NULL)
    {
        // Handle error
        return;
    }
    
    hosts = temp;
    wcscpy(hosts[hostCount].hostname, hostname);
    wcscpy(hosts[hostCount].description, description);
    hostCount++;
}

void freeHosts()
{
    free(hosts);
    hosts = NULL;
    hostCount = 0;
}
```

**You'll implement this in Chapter 19!**

## Practical Example: Dynamic Student Database

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int id;
    float gpa;
} Student;

typedef struct {
    Student* students;
    int count;
    int capacity;
} Database;

Database* createDatabase()
{
    Database* db = malloc(sizeof(Database));
    db->students = NULL;
    db->count = 0;
    db->capacity = 0;
    return db;
}

void addStudent(Database* db, const char* name, int id, float gpa)
{
    if (db->count >= db->capacity)
    {
        int newCapacity = (db->capacity == 0) ? 4 : db->capacity * 2;
        Student* temp = realloc(db->students, newCapacity * sizeof(Student));
        
        if (temp == NULL)
        {
            printf("Failed to allocate memory!\n");
            return;
        }
        
        db->students = temp;
        db->capacity = newCapacity;
    }
    
    Student* s = &db->students[db->count];
    s->name = malloc(strlen(name) + 1);
    strcpy(s->name, name);
    s->id = id;
    s->gpa = gpa;
    db->count++;
}

void printDatabase(Database* db)
{
    for (int i = 0; i < db->count; i++)
    {
        printf("%d. %s (ID: %d, GPA: %.2f)\n",
               i + 1,
               db->students[i].name,
               db->students[i].id,
               db->students[i].gpa);
    }
}

void freeDatabase(Database* db)
{
    for (int i = 0; i < db->count; i++)
    {
        free(db->students[i].name);
    }
    free(db->students);
    free(db);
}

int main(void)
{
    Database* db = createDatabase();
    
    addStudent(db, "Alice", 1001, 3.8);
    addStudent(db, "Bob", 1002, 3.5);
    addStudent(db, "Charlie", 1003, 3.9);
    
    printDatabase(db);
    
    freeDatabase(db);
    return 0;
}
```

## Common Memory Management Patterns

### Pattern 1: Create and Destroy Functions

```c
// Create
Thing* createThing()
{
    Thing* t = malloc(sizeof(Thing));
    // Initialize...
    return t;
}

// Destroy
void freeThing(Thing* t)
{
    // Free nested allocations
    free(t);
}
```

### Pattern 2: Growing Arrays

```c
void addElement(Array* arr, int value)
{
    if (arr->size >= arr->capacity)
    {
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = value;
}
```

### Pattern 3: String Duplication

```c
char* duplicate(const char* str)
{
    char* copy = malloc(strlen(str) + 1);
    if (copy != NULL)
    {
        strcpy(copy, str);
    }
    return copy;
}
```

## Exercise 9.1: Dynamic Matrix

Create a dynamic 2D array:

```c
#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols)
{
    int** matrix = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main(void)
{
    int** matrix = createMatrix(3, 4);
    
    // Use matrix...
    matrix[0][0] = 1;
    matrix[1][2] = 5;
    
    freeMatrix(matrix, 3);
    return 0;
}
```

## Exercise 9.2: String Array

Create a dynamic array of strings:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createStringArray(int count)
{
    return calloc(count, sizeof(char*));
}

void setString(char** arr, int index, const char* str)
{
    arr[index] = malloc(strlen(str) + 1);
    strcpy(arr[index], str);
}

void freeStringArray(char** arr, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

int main(void)
{
    char** names = createStringArray(3);
    
    setString(names, 0, "Alice");
    setString(names, 1, "Bob");
    setString(names, 2, "Charlie");
    
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", names[i]);
    }
    
    freeStringArray(names, 3);
    return 0;
}
```

## Common Mistakes

### Mistake 1: Using After Free

```c
int* ptr = malloc(sizeof(int));
*ptr = 42;
free(ptr);
*ptr = 100;  // DANGER! Use after free
```

### Mistake 2: Double Free

```c
int* ptr = malloc(sizeof(int));
free(ptr);
free(ptr);  // CRASH! Double free
```

### Mistake 3: Memory Leaks

```c
int* ptr = malloc(100 * sizeof(int));
ptr = malloc(200 * sizeof(int));  // LEAK! Lost first allocation
```

### Mistake 4: Freeing Stack Memory

```c
int x = 10;
int* ptr = &x;
free(ptr);  // CRASH! Can't free stack memory
```

### Mistake 5: Not Checking malloc Return

```c
int* ptr = malloc(1000000000 * sizeof(int));  // Might fail!
ptr[0] = 10;  // CRASH if malloc returned NULL
```

Always check:
```c
int* ptr = malloc(size);
if (ptr == NULL)
{
    // Handle error
}
```

## Memory Debugging Tips

### Tip 1: Set Freed Pointers to NULL

```c
free(ptr);
ptr = NULL;  // Prevents use-after-free bugs
```

### Tip 2: Use Valgrind (Linux/Mac)

```bash
valgrind --leak-check=full ./program
```

### Tip 3: Initialize to NULL

```c
char* str = NULL;  // So you can safely check if(str != NULL)
```

### Tip 4: Pair malloc with free

```c
// If this function allocates...
Data* createData();

// There should be a matching free function
void freeData(Data* d);
```

## Summary

You've learned:
- ✅ The difference between stack and heap memory
- ✅ How to allocate memory dynamically (malloc, calloc, realloc)
- ✅ How to free memory (free)
- ✅ Dynamic arrays and structures
- ✅ Common memory management patterns
- ✅ How to avoid memory leaks and errors
- ✅ How WinRDP manages its dynamic host list

**Next Chapter**: File Input/Output - reading and writing data!

---

# Chapter 10: File Input/Output

## Why File I/O?

Programs need to save data permanently and load it later:
- Save game progress
- Store user settings
- Read configuration files
- Process data files
- Log application activity

## File Pointers

In C, files are accessed through `FILE*` pointers:

```c
#include <stdio.h>

FILE* file = fopen("data.txt", "r");  // Open for reading
```

## Opening Files: fopen

```c
FILE* fopen(const char* filename, const char* mode);
```

### File Modes

| Mode | Description | File Must Exist? |
|------|-------------|------------------|
| `"r"` | Read | Yes |
| `"w"` | Write (truncate) | No (creates if needed) |
| `"a"` | Append | No (creates if needed) |
| `"r+"` | Read + Write | Yes |
| `"w+"` | Read + Write (truncate) | No |
| `"a+"` | Read + Append | No |

### Example

```c
FILE* file = fopen("data.txt", "r");
if (file == NULL)
{
    printf("Error opening file!\n");
    return 1;
}

// Use file...

fclose(file);  // Always close!
```

## Closing Files: fclose

```c
int fclose(FILE* file);
```

**Always close files** when done! This:
- Flushes buffered data
- Releases system resources
- Prevents data corruption

## Reading Text Files

### Reading Character by Character: fgetc

```c
FILE* file = fopen("data.txt", "r");
if (file == NULL) return 1;

int ch;
while ((ch = fgetc(file)) != EOF)
{
    putchar(ch);  // Print character
}

fclose(file);
```

### Reading Line by Line: fgets

```c
char line[256];

FILE* file = fopen("data.txt", "r");
if (file == NULL) return 1;

while (fgets(line, sizeof(line), file) != NULL)
{
    printf("%s", line);
}

fclose(file);
```

**fgets** includes the newline character if present.

### Reading Formatted Data: fscanf

```c
FILE* file = fopen("data.txt", "r");
if (file == NULL) return 1;

int age;
char name[50];

while (fscanf(file, "%s %d", name, &age) == 2)
{
    printf("Name: %s, Age: %d\n", name, age);
}

fclose(file);
```

## Writing Text Files

### Writing Character by Character: fputc

```c
FILE* file = fopen("output.txt", "w");
if (file == NULL) return 1;

char message[] = "Hello, File!";
for (int i = 0; message[i] != '\0'; i++)
{
    fputc(message[i], file);
}

fclose(file);
```

### Writing Strings: fputs

```c
FILE* file = fopen("output.txt", "w");
if (file == NULL) return 1;

fputs("Line 1\n", file);
fputs("Line 2\n", file);
fputs("Line 3\n", file);

fclose(file);
```

### Writing Formatted Data: fprintf

```c
FILE* file = fopen("output.txt", "w");
if (file == NULL) return 1;

fprintf(file, "Name: %s\n", "Alice");
fprintf(file, "Age: %d\n", 30);
fprintf(file, "GPA: %.2f\n", 3.85);

fclose(file);
```

## Binary File I/O

### Writing Binary Data: fwrite

```c
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

Student student = {"Alice", 20, 3.8};

FILE* file = fopen("student.dat", "wb");  // "wb" = write binary
if (file == NULL) return 1;

fwrite(&student, sizeof(Student), 1, file);

fclose(file);
```

### Reading Binary Data: fread

```c
Student student;

FILE* file = fopen("student.dat", "rb");  // "rb" = read binary
if (file == NULL) return 1;

if (fread(&student, sizeof(Student), 1, file) == 1)
{
    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %.2f\n", student.gpa);
}

fclose(file);
```

## File Positioning

### ftell - Get Current Position

```c
long position = ftell(file);
printf("Current position: %ld\n", position);
```

### fseek - Set Position

```c
fseek(file, 0, SEEK_SET);  // Beginning of file
fseek(file, 0, SEEK_END);  // End of file
fseek(file, 10, SEEK_CUR); // 10 bytes from current position
```

### rewind - Go to Beginning

```c
rewind(file);  // Same as fseek(file, 0, SEEK_SET)
```

## Checking File Status

### feof - Check for End of File

```c
if (feof(file))
{
    printf("Reached end of file\n");
}
```

### ferror - Check for Errors

```c
if (ferror(file))
{
    printf("File error occurred\n");
}
```

## Practical Example: Student Record Manager

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int id;
    float gpa;
} Student;

void saveStudent(const char* filename, Student* student)
{
    FILE* file = fopen(filename, "ab");  // Append binary
    if (file == NULL)
    {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fwrite(student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student saved!\n");
}

void loadStudents(const char* filename)
{
    FILE* file = fopen(filename, "rb");  // Read binary
    if (file == NULL)
    {
        printf("No students file found.\n");
        return;
    }
    
    Student student;
    printf("\n=== All Students ===\n");
    while (fread(&student, sizeof(Student), 1, file) == 1)
    {
        printf("Name: %s, ID: %d, GPA: %.2f\n",
               student.name, student.id, student.gpa);
    }
    
    fclose(file);
}

int main(void)
{
    Student s1 = {"Alice", 1001, 3.8};
    Student s2 = {"Bob", 1002, 3.5};
    Student s3 = {"Charlie", 1003, 3.9};
    
    saveStudent("students.dat", &s1);
    saveStudent("students.dat", &s2);
    saveStudent("students.dat", &s3);
    
    loadStudents("students.dat");
    
    return 0;
}
```

## CSV File Parsing

CSV (Comma-Separated Values) files are common data format:

```c
#include <stdio.h>
#include <string.h>

void parseCSV(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening CSV file!\n");
        return;
    }
    
    char line[256];
    
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // Remove newline
        line[strcspn(line, "\n")] = '\0';
        
        char* name = strtok(line, ",");
        char* age = strtok(NULL, ",");
        char* city = strtok(NULL, ",");
        
        if (name && age && city)
        {
            printf("Name: %s, Age: %s, City: %s\n", name, age, city);
        }
    }
    
    fclose(file);
}

int main(void)
{
    // Assume data.csv contains:
    // Alice,30,New York
    // Bob,25,Los Angeles
    // Charlie,35,Chicago
    
    parseCSV("data.csv");
    return 0;
}
```

## WinRDP Connection: Loading Hosts from CSV

WinRDP stores RDP servers in a CSV file:

```c
// hosts.csv format:
// hostname,description
// server1.example.com,Production Server
// server2.example.com,Development Server

Host* LoadHosts(int* count)
{
    FILE* file = _wfopen(L"hosts.csv", L"r, ccs=UTF-8");
    if (file == NULL)
    {
        *count = 0;
        return NULL;
    }
    
    Host* hosts = NULL;
    *count = 0;
    wchar_t line[1024];
    
    while (fgetswc(line, 1024, file) != NULL)
    {
        // Skip empty lines
        if (wcslen(line) == 0) continue;
        
        // Parse comma-separated values
        wchar_t* hostname = wcstok(line, L",");
        wchar_t* description = wcstok(NULL, L",");
        
        if (hostname && description)
        {
            // Grow array
            hosts = realloc(hosts, (*count + 1) * sizeof(Host));
            wcscpy(hosts[*count].hostname, hostname);
            wcscpy(hosts[*count].description, description);
            (*count)++;
        }
    }
    
    fclose(file);
    return hosts;
}
```

**You'll implement this in Chapter 19!**

## Exercise 10.1: File Copy Program

Copy one file to another:

```c
#include <stdio.h>

void copyFile(const char* source, const char* dest)
{
    FILE* src = fopen(source, "rb");
    if (src == NULL)
    {
        printf("Error opening source file!\n");
        return;
    }
    
    FILE* dst = fopen(dest, "wb");
    if (dst == NULL)
    {
        printf("Error opening destination file!\n");
        fclose(src);
        return;
    }
    
    int ch;
    while ((ch = fgetc(src)) != EOF)
    {
        fputc(ch, dst);
    }
    
    fclose(src);
    fclose(dst);
    printf("File copied successfully!\n");
}

int main(void)
{
    copyFile("input.txt", "output.txt");
    return 0;
}
```

## Exercise 10.2: Word Count

Count words, lines, and characters in a file:

```c
#include <stdio.h>
#include <ctype.h>

void fileStats(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;
    int ch;
    
    while ((ch = fgetc(file)) != EOF)
    {
        chars++;
        
        if (ch == '\n')
        {
            lines++;
        }
        
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (!inWord)
        {
            inWord = 1;
            words++;
        }
    }
    
    fclose(file);
    
    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

int main(void)
{
    fileStats("document.txt");
    return 0;
}
```

## Exercise 10.3: Simple Database

Create a contact database:

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

void addContact()
{
    Contact c;
    printf("Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';
    
    printf("Phone: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = '\0';
    
    printf("Email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = '\0';
    
    FILE* file = fopen("contacts.dat", "ab");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    
    fwrite(&c, sizeof(Contact), 1, file);
    fclose(file);
    printf("Contact added!\n");
}

void listContacts()
{
    FILE* file = fopen("contacts.dat", "rb");
    if (file == NULL)
    {
        printf("No contacts found.\n");
        return;
    }
    
    Contact c;
    printf("\n=== Contacts ===\n");
    while (fread(&c, sizeof(Contact), 1, file) == 1)
    {
        printf("Name:  %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("Email: %s\n", c.email);
        printf("---\n");
    }
    
    fclose(file);
}

int main(void)
{
    int choice;
    
    do
    {
        printf("\n1. Add Contact\n");
        printf("2. List Contacts\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline
        
        switch (choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Forgetting to Check fopen Result

```c
FILE* file = fopen("data.txt", "r");
// Forgot to check if file is NULL!
fgetc(file);  // CRASH if file doesn't exist!
```

Always check:
```c
FILE* file = fopen("data.txt", "r");
if (file == NULL)
{
    printf("Error opening file!\n");
    return 1;
}
```

### Mistake 2: Not Closing Files

```c
FILE* file = fopen("data.txt", "w");
fprintf(file, "Data");
// Forgot fclose(file)!
// Data might not be written!
```

### Mistake 3: Wrong Mode

```c
FILE* file = fopen("data.txt", "r");  // Read mode
fprintf(file, "Test");  // WRONG! Can't write in read mode
```

### Mistake 4: Buffer Overflows

```c
char line[10];
fgets(line, 100, file);  // WRONG! Buffer is only 10!
```

Correct:
```c
fgets(line, sizeof(line), file);
```

## File I/O Best Practices

### 1. Always Check Return Values

```c
if (fopen(...) == NULL) { /* handle error */ }
if (fread(...) != expected) { /* handle error */ }
```

### 2. Close Files in All Code Paths

```c
FILE* file = fopen("data.txt", "r");
if (file == NULL) return 1;

if (error_condition)
{
    fclose(file);  // Don't forget!
    return 1;
}

fclose(file);
```

### 3. Use Binary Mode for Binary Data

```c
fopen("data.dat", "wb");  // Binary write
fopen("data.dat", "rb");  // Binary read
```

### 4. Flush When Necessary

```c
fprintf(file, "Important data");
fflush(file);  // Force write to disk now
```

## Summary

You've learned:
- ✅ How to open and close files (fopen, fclose)
- ✅ Reading from files (fgetc, fgets, fscanf, fread)
- ✅ Writing to files (fputc, fputs, fprintf, fwrite)
- ✅ Binary vs text file I/O
- ✅ File positioning (fseek, ftell, rewind)
- ✅ CSV file parsing
- ✅ How WinRDP loads hosts from CSV files
- ✅ Best practices for file handling

**Next Chapter**: Function Pointers and Callbacks!

---

# Chapter 11: Function Pointers and Callbacks

## What Are Function Pointers?

Just like we can have pointers to data, we can have pointers to functions:

```c
int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*funcPtr)(int, int) = add;  // Function pointer
    int result = funcPtr(5, 3);      // Call through pointer
    printf("Result: %d\n", result);   // 8
    return 0;
}
```

## Function Pointer Syntax

### Declaration

```c
return_type (*pointer_name)(parameter_types);
```

### Examples

```c
// Pointer to function that returns int and takes two ints
int (*operation)(int, int);

// Pointer to function that returns void and takes a char*
void (*printer)(char*);

// Pointer to function that returns float and takes no parameters
float (*calculator)(void);
```

## Using Function Pointers

### Example: Math Operations

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int main(void)
{
    int (*operation)(int, int);
    
    operation = add;
    printf("5 + 3 = %d\n", operation(5, 3));
    
    operation = subtract;
    printf("5 - 3 = %d\n", operation(5, 3));
    
    operation = multiply;
    printf("5 * 3 = %d\n", operation(5, 3));
    
    operation = divide;
    printf("15 / 3 = %d\n", operation(15, 3));
    
    return 0;
}
```

## Arrays of Function Pointers

```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main(void)
{
    int (*operations[3])(int, int) = {add, subtract, multiply};
    
    char* names[] = {"Add", "Subtract", "Multiply"};
    
    for (int i = 0; i < 3; i++)
    {
        int result = operations[i](10, 5);
        printf("%s: %d\n", names[i], result);
    }
    
    return 0;
}
```

Output:
```
Add: 15
Subtract: 5
Multiply: 50
```

## Callbacks

A **callback** is a function passed to another function to be called later:

```c
#include <stdio.h>

// Function that takes a callback
void forEach(int* arr, int size, void (*callback)(int))
{
    for (int i = 0; i < size; i++)
    {
        callback(arr[i]);
    }
}

// Callback functions
void printNumber(int n)
{
    printf("%d ", n);
}

void printSquare(int n)
{
    printf("%d ", n * n);
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Numbers: ");
    forEach(numbers, size, printNumber);
    printf("\n");
    
    printf("Squares: ");
    forEach(numbers, size, printSquare);
    printf("\n");
    
    return 0;
}
```

## Practical Example: Generic Sorting

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function type
typedef int (*CompareFunc)(const void*, const void*);

// Compare integers
int compareInts(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

// Compare strings
int compareStrings(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

int main(void)
{
    // Sort integers
    int numbers[] = {5, 2, 8, 1, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    qsort(numbers, size, sizeof(int), compareInts);
    
    printf("Sorted numbers: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // Sort strings
    char* names[] = {"Charlie", "Alice", "Bob"};
    size = 3;
    
    qsort(names, size, sizeof(char*), compareStrings);
    
    printf("Sorted names: ");
    for (int i = 0; i < size; i++)
    {
        printf("%s ", names[i]);
    }
    printf("\n");
    
    return 0;
}
```

## Windows Callback Functions

Windows API uses callbacks extensively. Here's a preview:

```c
// Window procedure callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

**You'll use this in Chapter 15!**

## Function Pointers in Structures

```c
#include <stdio.h>

typedef struct {
    char name[50];
    int (*calculate)(int, int);
} Operation;

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main(void)
{
    Operation ops[] = {
        {"Addition", add},
        {"Multiplication", multiply}
    };
    
    for (int i = 0; i < 2; i++)
    {
        int result = ops[i].calculate(5, 3);
        printf("%s: %d\n", ops[i].name, result);
    }
    
    return 0;
}
```

## Practical Example: Event System

```c
#include <stdio.h>
#include <string.h>

#define MAX_LISTENERS 10

typedef void (*EventHandler)(const char*);

typedef struct {
    EventHandler listeners[MAX_LISTENERS];
    int count;
} EventManager;

void initEventManager(EventManager* em)
{
    em->count = 0;
}

void addEventListener(EventManager* em, EventHandler handler)
{
    if (em->count < MAX_LISTENERS)
    {
        em->listeners[em->count++] = handler;
    }
}

void triggerEvent(EventManager* em, const char* message)
{
    for (int i = 0; i < em->count; i++)
    {
        em->listeners[i](message);
    }
}

// Event handlers
void onLog(const char* msg)
{
    printf("[LOG] %s\n", msg);
}

void onAlert(const char* msg)
{
    printf("[ALERT] %s\n", msg);
}

void onSave(const char* msg)
{
    printf("[SAVE] Saving: %s\n", msg);
}

int main(void)
{
    EventManager em;
    initEventManager(&em);
    
    addEventListener(&em, onLog);
    addEventListener(&em, onAlert);
    addEventListener(&em, onSave);
    
    triggerEvent(&em, "Important event occurred!");
    
    return 0;
}
```

Output:
```
[LOG] Important event occurred!
[ALERT] Important event occurred!
[SAVE] Saving: Important event occurred!
```

## typedef for Cleaner Code

Instead of writing function pointer syntax repeatedly:

```c
typedef int (*BinaryOp)(int, int);

BinaryOp operation = add;  // Much cleaner!
```

Complete example:

```c
#include <stdio.h>

typedef int (*BinaryOp)(int, int);

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

int calculate(int a, int b, BinaryOp op)
{
    return op(a, b);
}

int main(void)
{
    printf("10 + 5 = %d\n", calculate(10, 5, add));
    printf("10 - 5 = %d\n", calculate(10, 5, subtract));
    return 0;
}
```

## Exercise 11.1: Calculator with Function Pointers

```c
#include <stdio.h>

typedef float (*Operation)(float, float);

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return b != 0 ? a / b : 0; }

int main(void)
{
    Operation ops[] = {add, subtract, multiply, divide};
    char* symbols[] = {"+", "-", "*", "/"};
    
    float a = 10.0f, b = 5.0f;
    
    for (int i = 0; i < 4; i++)
    {
        float result = ops[i](a, b);
        printf("%.1f %s %.1f = %.2f\n", a, symbols[i], b, result);
    }
    
    return 0;
}
```

## Exercise 11.2: Filter Function

```c
#include <stdio.h>
#include <stdbool.h>

typedef bool (*FilterFunc)(int);

bool isEven(int n) { return n % 2 == 0; }
bool isPositive(int n) { return n > 0; }
bool isGreaterThan5(int n) { return n > 5; }

int filter(int* arr, int size, int* result, FilterFunc predicate)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (predicate(arr[i]))
        {
            result[count++] = arr[i];
        }
    }
    return count;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int result[10];
    int count;
    
    count = filter(numbers, size, result, isEven);
    printf("Even numbers: ");
    printArray(result, count);
    
    count = filter(numbers, size, result, isGreaterThan5);
    printf("Greater than 5: ");
    printArray(result, count);
    
    return 0;
}
```

## Common Mistakes

### Mistake 1: Incorrect Syntax

```c
int (*func)(int, int);  // CORRECT: Pointer to function

int *func(int, int);    // WRONG: Function returning int*
```

### Mistake 2: Forgetting Parentheses

```c
int (*operation)(int, int);  // Correct
int *operation(int, int);    // Different! Function returning int*
```

### Mistake 3: Not Checking NULL

```c
typedef void (*Callback)(int);

void execute(Callback cb, int value)
{
    cb(value);  // CRASH if cb is NULL!
}
```

Always check:
```c
void execute(Callback cb, int value)
{
    if (cb != NULL)
    {
        cb(value);
    }
}
```

## Summary

You've learned:
- ✅ What function pointers are and how to declare them
- ✅ How to use function pointers for flexible code
- ✅ Arrays of function pointers
- ✅ Callbacks and event handlers
- ✅ How to use typedef for cleaner syntax
- ✅ Practical applications (sorting, filtering, events)
- ✅ Preview of Windows callback functions

**Next Chapter**: Preprocessor and Multi-File Programs!

---

# Chapter 12: Preprocessor and Multi-File Programs

## The C Preprocessor

The preprocessor processes your code **before** compilation:

```
Source Code (.c)
     ↓
Preprocessor (#include, #define, etc.)
     ↓
Expanded Code
     ↓
Compiler
     ↓
Object Code (.o)
```

## #include Directive

Includes content from another file:

### System Headers

```c
#include <stdio.h>   // System header (standard library)
#include <stdlib.h>
#include <string.h>
```

### Local Headers

```c
#include "myheader.h"  // Local header (your file)
#include "utils.h"
```

**Difference:**
- `<>` searches system directories
- `""` searches current directory first, then system

## #define Directive

### Simple Macros

```c
#define PI 3.14159
#define MAX_SIZE 100
#define PROGRAM_NAME "My Program"

int main(void)
{
    float radius = 5.0;
    float area = PI * radius * radius;
    printf("Area: %.2f\n", area);
    return 0;
}
```

### Function-like Macros

```c
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main(void)
{
    printf("5 squared: %d\n", SQUARE(5));      // 25
    printf("Max(10, 20): %d\n", MAX(10, 20));  // 20
    printf("Min(10, 20): %d\n", MIN(10, 20));  // 10
    return 0;
}
```

**Important**: Always use parentheses in macros!

```c
#define SQUARE(x) x * x     // BAD!
SQUARE(2 + 3)  // Expands to: 2 + 3 * 2 + 3 = 11 (WRONG!)

#define SQUARE(x) ((x) * (x))  // GOOD!
SQUARE(2 + 3)  // Expands to: ((2 + 3) * (2 + 3)) = 25 (CORRECT!)
```

## Conditional Compilation

### #ifdef, #ifndef, #endif

```c
#define DEBUG

#ifdef DEBUG
    printf("Debug: x = %d\n", x);
#endif
```

```c
#ifndef UTILS_H
#define UTILS_H

// Header content...

#endif  // UTILS_H
```

### #if, #elif, #else

```c
#define VERSION 2

#if VERSION == 1
    printf("Version 1\n");
#elif VERSION == 2
    printf("Version 2\n");
#else
    printf("Unknown version\n");
#endif
```

## Header Guards

Prevent multiple inclusion of the same header:

```c
// utils.h
#ifndef UTILS_H
#define UTILS_H

void printMessage(const char* msg);
int add(int a, int b);

#endif  // UTILS_H
```

Without header guards:
```c
#include "utils.h"
#include "utils.h"  // ERROR: Functions defined twice!
```

With header guards:
```c
#include "utils.h"
#include "utils.h"  // OK: Second inclusion is skipped
```

## Multi-File Programs

### File Structure

```
project/
├── main.c          (main function)
├── utils.h         (declarations)
├── utils.c         (implementations)
├── math_ops.h
└── math_ops.c
```

### Example: math_ops.h (Header File)

```c
#ifndef MATH_OPS_H
#define MATH_OPS_H

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(float a, float b);

#endif  // MATH_OPS_H
```

### Example: math_ops.c (Implementation File)

```c
#include "math_ops.h"

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

float divide(float a, float b)
{
    if (b != 0)
        return a / b;
    return 0.0f;
}
```

### Example: main.c

```c
#include <stdio.h>
#include "math_ops.h"

int main(void)
{
    printf("10 + 5 = %d\n", add(10, 5));
    printf("10 - 5 = %d\n", subtract(10, 5));
    printf("10 * 5 = %d\n", multiply(10, 5));
    printf("10 / 5 = %.1f\n", divide(10.0f, 5.0f));
    return 0;
}
```

### Compilation

```bash
gcc main.c math_ops.c -o program
```

Or separately:

```bash
gcc -c main.c        # Creates main.o
gcc -c math_ops.c    # Creates math_ops.o
gcc main.o math_ops.o -o program  # Links object files
```

## Static vs Extern

### static - File Scope Only

```c
// utils.c
static int helperFunction()  // Only visible in this file
{
    return 42;
}

void publicFunction()  // Visible to other files
{
    int result = helperFunction();
}
```

### extern - Access Global Variables

```c
// globals.c
int globalCounter = 0;

// main.c
extern int globalCounter;  // Declare that it exists elsewhere

int main(void)
{
    globalCounter++;
    return 0;
}
```

## Practical Example: Modular Calculator

### calculator.h

```c
#ifndef CALCULATOR_H
#define CALCULATOR_H

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

#endif
```

### calculator.c

```c
#include "calculator.h"

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    if (b != 0.0f)
        return a / b;
    return 0.0f;
}
```

### main.c

```c
#include <stdio.h>
#include "calculator.h"

int main(void)
{
    float a, b;
    char op;
    
    printf("Enter calculation (e.g., 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);
    
    float result;
    
    switch (op)
    {
        case '+': result = add(a, b); break;
        case '-': result = subtract(a, b); break;
        case '*': result = multiply(a, b); break;
        case '/': result = divide(a, b); break;
        default:
            printf("Invalid operator!\n");
            return 1;
    }
    
    printf("Result: %.2f\n", result);
    return 0;
}
```

### Compilation

```bash
gcc main.c calculator.c -o calc
```

## WinRDP Module Structure

WinRDP is organized into modules:

```
src/
├── main.c          - Entry point, WinMain
├── config.h        - Configuration constants
├── hosts.h/c       - Host management
├── credentials.h/c - Credential storage
├── rdp.h/c         - RDP connection logic
├── utils.c         - Utility functions
├── darkmode.h/c    - Dark mode support
├── adscan.h/c      - Network scanning
└── registry.h/c    - Registry operations
```

### Example: hosts.h

```c
#ifndef HOSTS_H
#define HOSTS_H

#include <windows.h>

typedef struct {
    wchar_t hostname[256];
    wchar_t description[256];
} Host;

Host* LoadHosts(int* count);
void SaveHosts(Host* hosts, int count);
void FreeHosts(Host* hosts);

#endif  // HOSTS_H
```

**You'll build this structure in Chapter 17!**

## Common Preprocessor Macros

```c
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define SAFE_FREE(p) do { if (p) { free(p); (p) = NULL; } } while(0)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

Usage:

```c
int numbers[] = {1, 2, 3, 4, 5};
int size = ARRAY_SIZE(numbers);  // 5

char* str = malloc(100);
SAFE_FREE(str);  // Frees and sets to NULL
```

## Predefined Macros

```c
#include <stdio.h>

int main(void)
{
    printf("File: %s\n", __FILE__);      // Current file name
    printf("Line: %d\n", __LINE__);      // Current line number
    printf("Date: %s\n", __DATE__);      // Compilation date
    printf("Time: %s\n", __TIME__);      // Compilation time
    printf("Function: %s\n", __func__);  // Current function (C99)
    return 0;
}
```

## Exercise 12.1: String Utilities Module

### string_utils.h

```c
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stdbool.h>

void toUpper(char* str);
void toLower(char* str);
bool isPalindrome(const char* str);
int countWords(const char* str);

#endif
```

### string_utils.c

```c
#include "string_utils.h"
#include <ctype.h>
#include <string.h>

void toUpper(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

void toLower(char* str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

bool isPalindrome(const char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}

int countWords(const char* str)
{
    int count = 0;
    bool inWord = false;
    
    for (int i = 0; str[i]; i++)
    {
        if (isspace(str[i]))
        {
            inWord = false;
        }
        else if (!inWord)
        {
            inWord = true;
            count++;
        }
    }
    
    return count;
}
```

### test_string_utils.c

```c
#include <stdio.h>
#include <string.h>
#include "string_utils.h"

int main(void)
{
    char text[] = "Hello World";
    
    printf("Original: %s\n", text);
    
    toUpper(text);
    printf("Uppercase: %s\n", text);
    
    toLower(text);
    printf("Lowercase: %s\n", text);
    
    char word[] = "racecar";
    printf("%s is %sa palindrome\n", word, 
           isPalindrome(word) ? "" : "not ");
    
    char sentence[] = "The quick brown fox";
    printf("Words in '%s': %d\n", sentence, countWords(sentence));
    
    return 0;
}
```

### Compilation

```bash
gcc test_string_utils.c string_utils.c -o test
```

## Common Mistakes

### Mistake 1: Missing Header Guards

```c
// Bad: No header guard
// utils.h
void function();
```

```c
// Good: With header guard
// utils.h
#ifndef UTILS_H
#define UTILS_H

void function();

#endif
```

### Mistake 2: Including .c Files

```c
#include "utils.c"  // WRONG! Include .h files, compile .c files
```

```c
#include "utils.h"  // CORRECT!
```

### Mistake 3: Circular Dependencies

```c
// a.h includes b.h
// b.h includes a.h
// CIRCULAR DEPENDENCY!
```

Solution: Use forward declarations:

```c
// a.h
typedef struct B B;  // Forward declaration
struct A {
    B* b;
};
```

### Mistake 4: Unparenthesized Macros

```c
#define DOUBLE(x) x + x       // BAD!
int result = DOUBLE(2) * 3;   // Expands to: 2 + 2 * 3 = 8 (WRONG!)

#define DOUBLE(x) ((x) + (x)) // GOOD!
int result = DOUBLE(2) * 3;   // Expands to: ((2) + (2)) * 3 = 12 (CORRECT!)
```

## Best Practices

### 1. One Module Per Feature

```
hosts.h/c     - Host management
credentials.h/c - Credentials
rdp.h/c       - RDP logic
```

### 2. Keep Headers Minimal

```c
// Header: Only declarations
void function();

// Source: Implementation
void function()
{
    // Implementation here
}
```

### 3. Use const for Read-Only Parameters

```c
void printString(const char* str);
int compare(const int* a, const int* b);
```

### 4. Document Public APIs

```c
/**
 * Adds two integers.
 * @param a First integer
 * @param b Second integer
 * @return Sum of a and b
 */
int add(int a, int b);
```

## Summary

You've learned:
- ✅ How the C preprocessor works
- ✅ #include, #define, and conditional compilation
- ✅ Header guards to prevent multiple inclusion
- ✅ How to organize code into multiple files
- ✅ Header files (.h) vs implementation files (.c)
- ✅ static and extern keywords
- ✅ Modular program structure
- ✅ How WinRDP is organized into modules
- ✅ Best practices for multi-file projects

**Congratulations!** You've completed Part II (Advanced C Concepts)!

You now have a solid foundation in:
- **Part I**: C fundamentals (variables, functions, arrays, pointers, strings, structures)
- **Part II**: Advanced C (dynamic memory, file I/O, function pointers, multi-file projects)

**Next: Part III - Windows Programming Basics!**

In Part III, you'll learn:
- How Windows applications work
- The Windows API
- Creating windows and dialogs
- Handling user input
- Message-driven programming

Then in Parts IV and V, you'll apply everything you've learned to build the complete WinRDP application!

---

# Quick Reference Card

## Compilation
```bash
gcc source.c -o program.exe
./program.exe
```

## Basic Syntax
```c
#include <stdio.h>

int main(void)
{
    // Your code here
    return 0;
}
```

## Data Types
- `int` - Integer numbers
- `float` - Decimal numbers (single precision)
- `double` - Decimal numbers (double precision)
- `char` - Single character
- `bool` - True/false (include `<stdbool.h>`)

## printf Format Specifiers
- `%d` - int
- `%f` - float/double
- `%c` - char
- `%s` - string
- `%p` - pointer

## Control Flow
```c
if (condition) { }
else if (condition) { }
else { }

switch (value) {
    case 1: break;
    default: break;
}

while (condition) { }
for (init; condition; increment) { }
do { } while (condition);
```

## Pointers Quick Reference
```c
int x = 42;
int* ptr = &x;    // ptr points to x
*ptr = 100;       // Modify x through pointer
```

---

# Part III: Windows Programming Basics

Welcome to Part III! You now have a solid foundation in C programming. In this part, you'll learn how to create Windows applications using the Win32 API. These chapters prepare you to build the complete WinRDP application in Parts IV and V.

---

# Chapter 13: Introduction to Windows Programming

## Welcome to Windows Development

Congratulations on completing Parts I and II! You now understand C fundamentals and advanced concepts. Now it's time to apply that knowledge to build **real Windows applications**.

In this chapter, you'll learn:
- How Windows applications differ from console programs
- The Win32 API architecture
- The message-driven programming model
- Key Windows concepts and terminology
- How WinRDP fits into the Windows ecosystem

## Console vs. Windows Applications

### Console Programs (What You've Been Writing)

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

**Characteristics:**
- Text-based interface
- Sequential execution (top to bottom)
- Simple input/output (printf/scanf)
- Exits when main() returns

### Windows GUI Applications

Windows applications are fundamentally different:
- **Graphical** interface (windows, buttons, menus)
- **Event-driven** (responds to user actions)
- **Message-based** (operating system communicates via messages)
- **Persistent** (runs until user closes the window)

**Example of Windows program structure:**
```c
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Create and register window class
    // Create window
    // Message loop (stays running)
    
    return 0;
}
```

## The Win32 API

### What is Win32 API?

The **Windows API** (Application Programming Interface), also called **Win32 API**, is a collection of functions provided by Windows for building applications.

**Key areas:**
- **Window management** - Creating and managing windows
- **Graphics** - Drawing and painting
- **Input** - Keyboard, mouse, touch
- **File system** - Files and directories
- **Networking** - Network communication
- **System services** - Registry, processes, threads

### Header Files

The main header for Windows programming:

```c
#include <windows.h>
```

This single header includes everything you need:
- Window functions
- Message definitions
- Standard controls
- System functions
- Data types

### Windows Data Types

Windows defines special data types (they're all based on standard C types):

| Windows Type | C Equivalent | Description |
|--------------|--------------|-------------|
| `HWND` | Pointer | Handle to a window |
| `HINSTANCE` | Pointer | Handle to an instance (program) |
| `LPSTR` | `char*` | Long pointer to string (ANSI) |
| `LPWSTR` | `wchar_t*` | Long pointer to wide string (Unicode) |
| `DWORD` | `unsigned long` | 32-bit unsigned integer |
| `UINT` | `unsigned int` | Unsigned integer |
| `BOOL` | `int` | Boolean (TRUE or FALSE) |
| `LPARAM` | Long | Message parameter |
| `WPARAM` | Word | Message parameter |

**Why special types?**
- **Portability** - Can adapt to different Windows versions
- **Clarity** - Type names indicate purpose (HWND = window handle)
- **Legacy** - Some names come from 16-bit Windows days

### Example: Basic Windows Types

```c
HWND hwnd;              // Handle to a window
HINSTANCE hInstance;    // Handle to current program instance
BOOL success;           // Boolean value
DWORD flags;            // 32-bit flags/options
LPWSTR text;            // Pointer to wide string (Unicode)
```

## The Message-Driven Model

### How Console Programs Work

```
Start → Execute line 1 → Execute line 2 → ... → End
```

Simple, sequential flow.

### How Windows Programs Work

```
Start → Create Window → Enter Message Loop → Process Events → Exit
                              ↑                    ↓
                              └────────────────────┘
                              (Runs until app closes)
```

**Windows programs are event-driven:**
1. Program creates a window
2. Enters a **message loop**
3. Windows sends **messages** (user clicks, types, moves mouse, etc.)
4. Program **handles** messages and responds
5. Loop continues until user closes the application

### What Are Messages?

**Messages** are notifications from Windows about events:

| Message | Meaning |
|---------|---------|
| `WM_CREATE` | Window is being created |
| `WM_DESTROY` | Window is being destroyed |
| `WM_PAINT` | Window needs to be redrawn |
| `WM_LBUTTONDOWN` | Left mouse button clicked |
| `WM_KEYDOWN` | Keyboard key pressed |
| `WM_COMMAND` | Menu item or button clicked |
| `WM_CLOSE` | User clicked the X button |

**Message structure:**
```c
typedef struct {
    HWND   hwnd;      // Window that receives the message
    UINT   message;   // Message type (WM_PAINT, WM_KEYDOWN, etc.)
    WPARAM wParam;    // Additional info (depends on message)
    LPARAM lParam;    // Additional info (depends on message)
    DWORD  time;      // When message was posted
    POINT  pt;        // Mouse cursor position
} MSG;
```

### The Message Loop

Every Windows application has a message loop:

```c
MSG msg;

// Message loop
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);   // Translate keyboard input
    DispatchMessage(&msg);    // Send message to window procedure
}
```

**What happens:**
1. `GetMessage()` - Gets next message from queue (blocks if no messages)
2. `TranslateMessage()` - Converts keyboard messages to character messages
3. `DispatchMessage()` - Sends message to your **window procedure** for handling

### Window Procedure (WndProc)

The **window procedure** is a callback function that handles messages:

```c
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);  // Exit the application
            return 0;
            
        case WM_PAINT:
            // Draw in the window
            return 0;
            
        case WM_LBUTTONDOWN:
            // Handle mouse click
            return 0;
    }
    
    // Let Windows handle unprocessed messages
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

**Pattern:**
1. Switch on message type
2. Handle messages you care about
3. Call `DefWindowProc()` for everything else

## Basic Windows Program Structure

Here's the skeleton of every Windows program:

```c
#include <windows.h>

// Window procedure (handles messages)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // 1. REGISTER WINDOW CLASS
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;        // Our window procedure
    wc.hInstance = hInstance;           // Current instance
    wc.lpszClassName = L"MyWindowClass";
    
    RegisterClass(&wc);
    
    // 2. CREATE WINDOW
    HWND hwnd = CreateWindowEx(
        0,                           // Extended styles
        L"MyWindowClass",            // Class name
        L"My Application",           // Window title
        WS_OVERLAPPEDWINDOW,         // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, // Position
        800, 600,                    // Size
        NULL, NULL,                  // Parent, Menu
        hInstance, NULL              // Instance, Extra
    );
    
    // 3. SHOW WINDOW
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // 4. MESSAGE LOOP
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

// Window procedure implementation
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

### The Four Steps

Every Windows program follows these steps:

1. **Register Window Class** - Defines window properties
2. **Create Window** - Creates the actual window
3. **Show Window** - Makes window visible
4. **Message Loop** - Processes events

## Understanding WinMain

### WinMain vs main

Console programs use `main()`:
```c
int main(void)
```

Windows GUI programs use `WinMain()`:
```c
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
```

### WinMain Parameters

| Parameter | Description |
|-----------|-------------|
| `hInstance` | Handle to current instance of your program |
| `hPrevInstance` | Obsolete (always NULL in modern Windows) |
| `lpCmdLine` | Command-line arguments as a string |
| `nCmdShow` | How window should be displayed (normal, minimized, etc.) |

### WINAPI and Calling Conventions

`WINAPI` is a calling convention (`__stdcall`):
```c
int WINAPI WinMain(...)
```

It specifies how parameters are passed and cleaned up. You'll see it on Windows API functions:
```c
BOOL WINAPI ShowWindow(HWND hWnd, int nCmdShow);
```

## Windows Handles

### What is a Handle?

A **handle** is an identifier for a Windows resource:

```c
HWND hwnd;           // Handle to a window
HDC hdc;             // Handle to a device context (for drawing)
HINSTANCE hInstance; // Handle to program instance
HICON hIcon;         // Handle to an icon
HBRUSH hBrush;       // Handle to a brush
HMENU hMenu;         // Handle to a menu
```

**Think of handles as:**
- Reference numbers (like a ticket number)
- Windows uses them to track resources
- You pass handles to Windows functions

### Using Handles

```c
// Get a window handle
HWND hwnd = CreateWindowEx(...);

// Use it to show the window
ShowWindow(hwnd, SW_SHOW);

// Use it to set window text
SetWindowText(hwnd, L"New Title");

// Use it to destroy the window
DestroyWindow(hwnd);
```

## Unicode vs. ANSI

### Two String Types

Windows supports two character encodings:

**ANSI (8-bit characters):**
```c
char* str = "Hello";
```

**Unicode (16-bit characters):**
```c
wchar_t* str = L"Hello";  // Note the L prefix
```

### Windows String Functions

Most Windows functions have two versions:

```c
// ANSI version
int MessageBoxA(HWND hWnd, const char* lpText, const char* lpCaption, UINT uType);

// Unicode version  
int MessageBoxW(HWND hWnd, const wchar_t* lpText, const wchar_t* lpCaption, UINT uType);
```

**The generic macro:**
```c
MessageBox  // Becomes MessageBoxA or MessageBoxW depending on settings
```

### Modern Recommendation: Use Unicode

**WinRDP uses Unicode** (all wide strings and W versions):

```c
#define UNICODE
#define _UNICODE
#include <windows.h>

// Now use wchar_t strings with L prefix
wchar_t title[] = L"WinRDP";
MessageBoxW(NULL, L"Hello, Unicode!", L"Title", MB_OK);
```

**Why Unicode?**
- ✅ Supports all languages (Chinese, Arabic, emoji, etc.)
- ✅ Required for modern Windows APIs
- ✅ Recommended by Microsoft
- ✅ WinRDP is fully Unicode

## Common Windows API Functions

Here are some functions you'll use frequently:

### Message Boxes

```c
MessageBoxW(NULL, L"Hello, World!", L"Greeting", MB_OK);
```

Types:
- `MB_OK` - OK button
- `MB_OKCANCEL` - OK and Cancel buttons
- `MB_YESNO` - Yes and No buttons
- `MB_ICONERROR` - Error icon
- `MB_ICONINFORMATION` - Info icon

### Window Functions

```c
// Show/hide window
ShowWindow(hwnd, SW_SHOW);      // Show
ShowWindow(hwnd, SW_HIDE);      // Hide

// Set window text
SetWindowTextW(hwnd, L"New Title");

// Get window text
wchar_t buffer[256];
GetWindowTextW(hwnd, buffer, 256);

// Enable/disable window
EnableWindow(hwnd, TRUE);   // Enable
EnableWindow(hwnd, FALSE);  // Disable
```

### Drawing Functions

```c
// Get device context for drawing
HDC hdc = GetDC(hwnd);

// Draw text
TextOutW(hdc, 10, 10, L"Hello", 5);

// Draw line
MoveToEx(hdc, 0, 0, NULL);
LineTo(hdc, 100, 100);

// Release device context
ReleaseDC(hwnd, hdc);
```

## How WinRDP Uses Windows API

Let's see how WinRDP uses concepts you've just learned:

### 1. WinMain Entry Point

```c
// main.c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    // Create system tray icon
    // Show login dialog
    // Enter message loop
    return 0;
}
```

Note: `wWinMain` is the Unicode version of `WinMain`.

### 2. Message Handling

```c
// main.c
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            // Handle button clicks, menu items
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        case WM_TRAYICON:  // Custom message for system tray
            // Handle tray icon clicks
            break;
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

### 3. Creating Dialogs

```c
// main.c
HWND hDlg = CreateDialogParam(
    hInstance,
    MAKEINTRESOURCE(IDD_MAIN_DIALOG),  // Dialog resource ID
    hwnd,
    MainDialogProc,                     // Dialog procedure
    0
);
```

### 4. Windows Credential Manager API

```c
// credentials.c
BOOL SaveCredentials(const wchar_t* target, const wchar_t* username, 
                     const wchar_t* password)
{
    CREDENTIALW cred = {0};
    cred.Type = CRED_TYPE_GENERIC;
    cred.TargetName = (LPWSTR)target;
    cred.UserName = (LPWSTR)username;
    // ...
    
    return CredWriteW(&cred, 0);
}
```

### 5. System Tray Integration

```c
// main.c
NOTIFYICONDATAW nid = {0};
nid.cbSize = sizeof(nid);
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
nid.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));
wcscpy(nid.szTip, L"WinRDP");

Shell_NotifyIconW(NIM_ADD, &nid);
```

## Development Environment

### Compilers

**Option 1: MinGW-w64 (Recommended for this book)**
```bash
gcc -o winrdp.exe main.c -mwindows -lcomctl32 -ladvapi32
```

**Option 2: Visual Studio**
- Full IDE with visual designers
- Integrated debugger
- IntelliSense (autocomplete)

### Compilation Flags

For Windows GUI programs:
```bash
gcc program.c -o program.exe -mwindows
```

**Flags explained:**
- `-mwindows` - Creates Windows GUI app (not console)
- `-lcomctl32` - Link common controls library
- `-ladvapi32` - Link advanced Windows APIs
- `-lgdi32` - Link graphics library

### WinRDP Build Command

```bash
gcc src/*.c -o winrdp.exe -mwindows ^
    -lcomctl32 -ladvapi32 -lgdi32 -lshell32 ^
    -lnetapi32 -lcredui -ldwmapi -municode
```

## Resource Files

Windows programs use **resource files** (.rc) to define:
- Icons
- Dialogs
- Menus
- Strings

### Example: Dialog Resource

```rc
IDD_MAIN_DIALOG DIALOG 0, 0, 400, 300
STYLE DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Host Manager"
FONT 9, "Segoe UI"
BEGIN
    CONTROL "", IDC_HOST_LIST, "SysListView32", 
            LVS_REPORT | WS_BORDER, 10, 10, 380, 250
    PUSHBUTTON "Connect", IDC_BTN_CONNECT, 10, 270, 70, 24
END
```

### Compiling Resources

```bash
windres resources.rc -o resources.o
gcc main.c resources.o -o program.exe -mwindows
```

WinRDP's resource file is `src/resources.rc`.

## Error Handling

### Windows API Error Codes

Most Windows functions return:
- `TRUE`/`FALSE` for success/failure
- `NULL` for invalid handles
- `0` for errors

**Get error details:**
```c
DWORD error = GetLastError();
```

### Example: Error Handling

```c
HWND hwnd = CreateWindowEx(...);
if (hwnd == NULL)
{
    DWORD error = GetLastError();
    MessageBoxW(NULL, L"Failed to create window!", L"Error", MB_ICONERROR);
    return 1;
}
```

### Formatted Error Messages

```c
void ShowError(const wchar_t* message)
{
    DWORD error = GetLastError();
    wchar_t buffer[512];
    
    FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM,
        NULL,
        error,
        0,
        buffer,
        512,
        NULL
    );
    
    MessageBoxW(NULL, buffer, message, MB_ICONERROR);
}
```

WinRDP has a `ShowError()` function in `utils.c`.

## Key Concepts Summary

Let's review the key concepts:

### 1. Message-Driven Architecture
Windows apps don't execute sequentially - they **respond to messages** (events).

### 2. Handles
Everything in Windows is referenced by a **handle** (HWND, HDC, HINSTANCE, etc.).

### 3. Window Procedure
Every window has a **callback function** that processes messages.

### 4. Message Loop
The heart of every Windows app - continuously processes messages.

### 5. Unicode
Modern Windows apps should use **wide strings** (`wchar_t`, L"text").

### 6. Win32 API
A massive library of functions for everything Windows-related.

## A Simple Example

Let's see a minimal but complete Windows program:

```c
#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            if (MessageBoxW(hwnd, L"Really quit?", L"Confirm", 
                           MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return 0;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            TextOutW(hdc, 10, 10, L"Hello, Windows!", 15);
            
            EndPaint(hwnd, &ps);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"SimpleWindowClass";
    
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClassW(&wc);
    
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Simple Window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 300,
        NULL, NULL, hInstance, NULL
    );
    
    if (hwnd == NULL)
    {
        return 1;
    }
    
    ShowWindow(hwnd, nCmdShow);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}
```

**Compile it:**
```bash
gcc simple.c -o simple.exe -mwindows -municode
```

**What it does:**
- Creates a window
- Displays "Hello, Windows!" text
- Asks for confirmation before closing
- Demonstrates the four-step process

## Exercises

### Exercise 1: Compile and Run
1. Type the simple example above into a file called `simple.c`
2. Compile it with gcc
3. Run it and observe the window

### Exercise 2: Modify the Text
Change the `WM_PAINT` handler to display:
- Your name
- The current date
- Multiple lines of text

### Exercise 3: Add a Button
Research the `CreateWindowEx()` function and try adding a button to the window.

**Hint:**
```c
CreateWindowExW(0, L"BUTTON", L"Click Me!", 
                WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
                10, 50, 100, 30,
                hwnd, (HMENU)1, hInstance, NULL);
```

### Exercise 4: Handle Button Click
Handle the `WM_COMMAND` message to detect button clicks.

**Hint:**
```c
case WM_COMMAND:
    if (LOWORD(wParam) == 1)  // Button ID
    {
        MessageBoxW(hwnd, L"Button clicked!", L"Info", MB_OK);
    }
    return 0;
```

## Common Mistakes

### Mistake 1: Forgetting to Handle WM_DESTROY

```c
// WRONG - program won't exit
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Missing WM_DESTROY handler!
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// CORRECT
case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
```

### Mistake 2: Forgetting L Prefix for Wide Strings

```c
// WRONG with Unicode
CreateWindowExW(..., "MyClass", ...);  // char*, should be wchar_t*

// CORRECT
CreateWindowExW(..., L"MyClass", ...);  // wchar_t*
```

### Mistake 3: Not Checking for NULL

```c
// WRONG - no error checking
HWND hwnd = CreateWindowExW(...);
ShowWindow(hwnd, SW_SHOW);  // Crashes if hwnd is NULL!

// CORRECT
HWND hwnd = CreateWindowExW(...);
if (hwnd == NULL)
{
    MessageBoxW(NULL, L"Failed to create window!", L"Error", MB_ICONERROR);
    return 1;
}
ShowWindow(hwnd, SW_SHOW);
```

### Mistake 4: Using ANSI Functions with Unicode

```c
// WRONG - mixing A and W versions
#define UNICODE
CreateWindowExA(...);  // ANSI function with Unicode defined!

// CORRECT - use W versions consistently
CreateWindowExW(...);
```

## Resources and Documentation

### Official Documentation
- **MSDN (Microsoft Developer Network)**: https://docs.microsoft.com/windows/win32/
- Search for any Windows function, constant, or structure

### Recommended Reading
- **theForger's Win32 Tutorial**: Excellent beginner-friendly tutorial
- **Programming Windows** by Charles Petzold: Classic Windows programming book
- **Windows via C/C++** by Jeffrey Richter: Advanced Windows internals

### WinRDP Source Code
Study these files to see real-world Windows API usage:
- `src/main.c` - WinMain, message loop, window creation
- `src/utils.c` - Helper functions
- `src/resources.rc` - Dialog definitions

## Summary

You've learned:
- ✅ Difference between console and Windows GUI programs
- ✅ Win32 API basics and common data types
- ✅ Message-driven programming model
- ✅ Window procedures and message handling
- ✅ WinMain entry point
- ✅ Handles and how they work
- ✅ Unicode vs. ANSI strings (use Unicode!)
- ✅ Basic Windows API functions
- ✅ How WinRDP uses these concepts
- ✅ Compilation and error handling

**Next Chapter**: Creating your first real Windows application with proper window classes, controls, and event handling!

---

# Chapter 14: Your First Windows Application

## Building a Complete Windows Program

In Chapter 13, you learned the theory behind Windows programming. Now it's time to build a complete, functional Windows application from scratch!

In this chapter, you'll:
- Create a proper window class with all necessary properties
- Build a window with controls (buttons, text fields)
- Handle user events (button clicks, keyboard input)
- Understand window styles and extended styles
- Create a real calculator program

## Project: Simple Calculator

We'll build a simple calculator with:
- A text display showing the current number
- Number buttons (0-9)
- Operation buttons (+, -, *, /, =)
- Clear button (C)

**Why a calculator?**
- Demonstrates multiple controls
- Handles user input
- Shows state management
- Real-world functionality
- Not too simple, not too complex

## Step 1: Project Setup

### Create the File

Create `calculator.c`:

```c
#include <windows.h>
#include <stdio.h>

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    // We'll fill this in step by step
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // We'll fill this in step by step
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

### Compile Command

```bash
gcc calculator.c -o calculator.exe -mwindows -municode
```

**Note**: We'll add more code incrementally and test as we go.

## Step 2: Registering the Window Class

The window class defines properties for all windows of that type.

### WNDCLASSW Structure

```c
typedef struct {
    UINT        style;           // Class styles (CS_* constants)
    WNDPROC     lpfnWndProc;     // Pointer to window procedure
    int         cbClsExtra;      // Extra bytes for class (usually 0)
    int         cbWndExtra;      // Extra bytes for window (usually 0)
    HINSTANCE   hInstance;       // Instance handle
    HICON       hIcon;           // Icon handle
    HCURSOR     hCursor;         // Cursor handle
    HBRUSH      hbrBackground;   // Background brush
    LPCWSTR     lpszMenuName;    // Menu name (NULL if no menu)
    LPCWSTR     lpszClassName;   // Class name
} WNDCLASSW;
```

### Fill in WinMain - Part 1

```c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"CalculatorWindowClass";
    
    // 1. DEFINE WINDOW CLASS
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;              // Our message handler
    wc.hInstance = hInstance;                 // Current instance
    wc.lpszClassName = CLASS_NAME;            // Class name
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Standard arrow cursor
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // White background
    wc.style = CS_HREDRAW | CS_VREDRAW;       // Redraw on resize
    
    // 2. REGISTER WINDOW CLASS
    if (!RegisterClassW(&wc))
    {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error",
                   MB_ICONERROR | MB_OK);
        return 0;
    }
    
    // More code to come...
    
    return 0;
}
```

**Key points:**
- `CS_HREDRAW | CS_VREDRAW` - Redraws entire window when resized
- `LoadCursor(NULL, IDC_ARROW)` - Loads standard arrow cursor
- `(HBRUSH)(COLOR_WINDOW + 1)` - Uses system window color
- Always check if `RegisterClassW` succeeds!

### Common Window Class Styles

| Style | Description |
|-------|-------------|
| `CS_HREDRAW` | Redraw when width changes |
| `CS_VREDRAW` | Redraw when height changes |
| `CS_DBLCLKS` | Enable double-click messages |
| `CS_OWNDC` | Allocates unique device context |

## Step 3: Creating the Window

Now create the actual window:

### CreateWindowExW Function

```c
HWND CreateWindowExW(
    DWORD dwExStyle,        // Extended window style
    LPCWSTR lpClassName,    // Window class name
    LPCWSTR lpWindowName,   // Window title
    DWORD dwStyle,          // Window style
    int x,                  // X position
    int y,                  // Y position
    int nWidth,             // Width
    int nHeight,            // Height
    HWND hWndParent,        // Parent window (NULL = top-level)
    HMENU hMenu,            // Menu or child ID
    HINSTANCE hInstance,    // Instance handle
    LPVOID lpParam          // Creation parameters
);
```

### Fill in WinMain - Part 2

```c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    // ... previous code (register window class) ...
    
    // 3. CREATE WINDOW
    HWND hwnd = CreateWindowExW(
        0,                                  // Optional extended styles
        CLASS_NAME,                         // Window class
        L"Simple Calculator",               // Window title
        WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX), // Style
        CW_USEDEFAULT, CW_USEDEFAULT,      // Position (default)
        320, 400,                           // Size (320x400)
        NULL,                               // Parent window
        NULL,                               // Menu
        hInstance,                          // Instance handle
        NULL                                // Additional data
    );
    
    if (hwnd == NULL)
    {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error",
                   MB_ICONERROR | MB_OK);
        return 0;
    }
    
    // More code to come...
    
    return 0;
}
```

**Window style explained:**
```c
WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX)
```

- `WS_OVERLAPPEDWINDOW` - Standard window (title bar, borders, min/max/close)
- `~(WS_THICKFRAME | WS_MAXIMIZEBOX)` - Remove resizing and maximize button
- Result: Fixed-size window (perfect for calculator!)

### Common Window Styles

| Style | Description |
|-------|-------------|
| `WS_OVERLAPPEDWINDOW` | Standard window with all decorations |
| `WS_POPUP` | Pop-up window (no decorations) |
| `WS_VISIBLE` | Initially visible |
| `WS_CHILD` | Child window |
| `WS_BORDER` | Window with border |
| `WS_CAPTION` | Window with title bar |
| `WS_THICKFRAME` | Resizable border |
| `WS_MINIMIZEBOX` | Minimize button |
| `WS_MAXIMIZEBOX` | Maximize button |

### Extended Window Styles

| Extended Style | Description |
|----------------|-------------|
| `WS_EX_TOPMOST` | Always on top |
| `WS_EX_CLIENTEDGE` | 3D sunken border |
| `WS_EX_TOOLWINDOW` | Tool window (thin title bar) |
| `WS_EX_LAYERED` | Layered window (transparency) |

## Step 4: Show Window and Message Loop

### Fill in WinMain - Part 3 (Complete)

```c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    // ... previous code (register class, create window) ...
    
    // 4. SHOW WINDOW
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // 5. MESSAGE LOOP
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}
```

**Why `UpdateWindow()`?**
- Sends an immediate `WM_PAINT` message
- Ensures window is drawn right away
- Without it, window might not appear until first event

**Message loop explained:**
```c
while (GetMessage(&msg, NULL, 0, 0) > 0)
```
- Returns 0 when `WM_QUIT` received (exit program)
- Returns -1 on error
- Returns positive value for all other messages

## Step 5: Basic Window Procedure

Now let's handle basic window messages:

```c
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // Window is being created
            // We'll add controls here later
            return 0;
        }
        
        case WM_DESTROY:
        {
            // Window is being destroyed
            PostQuitMessage(0);
            return 0;
        }
        
        case WM_PAINT:
        {
            // Window needs to be drawn
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // Background is painted automatically (white)
            
            EndPaint(hwnd, &ps);
            return 0;
        }
        
        case WM_CLOSE:
        {
            // User clicked X button
            if (MessageBoxW(hwnd, L"Really quit?", L"Calculator",
                           MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

**Test it now!** You should see an empty window with a confirmation dialog when closing.

## Step 6: Adding Controls

Windows controls are just child windows. Let's add the calculator display:

### Control IDs

Define constants for control IDs:

```c
#define IDC_DISPLAY 1001
#define IDC_BTN_0   2000
#define IDC_BTN_1   2001
// ... we'll add more later
```

### Creating the Display

Add to `WM_CREATE` handler:

```c
case WM_CREATE:
{
    // Display (read-only edit control)
    HWND hDisplay = CreateWindowExW(
        WS_EX_CLIENTEDGE,              // Sunken 3D border
        L"EDIT",                       // Edit control class
        L"0",                          // Initial text
        WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY, // Styles
        10, 10, 280, 30,               // Position and size
        hwnd,                          // Parent window
        (HMENU)IDC_DISPLAY,            // Control ID
        GetModuleHandle(NULL),         // Instance handle
        NULL                           // No extra data
    );
    
    // Set larger font for display
    HFONT hFont = CreateFontW(
        24,                     // Height
        0,                      // Width (auto)
        0, 0,                   // Escapement, orientation
        FW_NORMAL,              // Weight
        FALSE, FALSE, FALSE,    // Italic, underline, strikeout
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_DONTCARE,
        L"Arial"                // Font name
    );
    
    SendMessage(hDisplay, WM_SETFONT, (WPARAM)hFont, TRUE);
    
    return 0;
}
```

**Edit control styles:**
- `ES_RIGHT` - Right-aligned text (like calculators)
- `ES_READONLY` - Can't type in it directly
- `WS_CHILD` - Child window
- `WS_VISIBLE` - Visible immediately

### Creating Buttons

Let's add number buttons 0-9:

```c
case WM_CREATE:
{
    // ... display creation code ...
    
    // Button layout: 4 columns x 5 rows
    int btnWidth = 60;
    int btnHeight = 50;
    int btnX = 10;
    int btnY = 50;
    int spacing = 5;
    
    // Number buttons (layout like a calculator)
    const wchar_t* labels[] = {
        L"7", L"8", L"9", L"/",
        L"4", L"5", L"6", L"*",
        L"1", L"2", L"3", L"-",
        L"C", L"0", L"=", L"+"
    };
    
    int id = IDC_BTN_0;
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            int x = btnX + col * (btnWidth + spacing);
            int y = btnY + row * (btnHeight + spacing);
            
            CreateWindowExW(
                0,
                L"BUTTON",
                labels[row * 4 + col],
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                x, y, btnWidth, btnHeight,
                hwnd,
                (HMENU)(LONG_PTR)(id++),
                GetModuleHandle(NULL),
                NULL
            );
        }
    }
    
    return 0;
}
```

**Button styles:**
- `BS_PUSHBUTTON` - Standard push button
- `BS_DEFPUSHBUTTON` - Default button (thick border)
- `BS_CHECKBOX` - Checkbox
- `BS_RADIOBUTTON` - Radio button

## Step 7: Handling Button Clicks

Buttons send `WM_COMMAND` messages when clicked:

```c
// Global variables for calculator state
double g_value = 0.0;
double g_operand = 0.0;
wchar_t g_operator = L'\0';
BOOL g_newNumber = TRUE;

// Helper function to update display
void UpdateDisplay(HWND hwnd)
{
    wchar_t buffer[32];
    swprintf(buffer, 32, L"%.10g", g_value);
    SetWindowTextW(GetDlgItem(hwnd, IDC_DISPLAY), buffer);
}

// Handle button clicks
case WM_COMMAND:
{
    int id = LOWORD(wParam);
    
    // Number buttons (0-9)
    if (id >= IDC_BTN_0 && id <= IDC_BTN_9)
    {
        int digit = id - IDC_BTN_0;
        
        if (g_newNumber)
        {
            g_value = digit;
            g_newNumber = FALSE;
        }
        else
        {
            g_value = g_value * 10 + digit;
        }
        
        UpdateDisplay(hwnd);
    }
    // Clear button
    else if (id == IDC_BTN_CLEAR)
    {
        g_value = 0.0;
        g_operand = 0.0;
        g_operator = L'\0';
        g_newNumber = TRUE;
        UpdateDisplay(hwnd);
    }
    // Operator buttons (+, -, *, /)
    else if (id == IDC_BTN_PLUS || id == IDC_BTN_MINUS ||
             id == IDC_BTN_MULTIPLY || id == IDC_BTN_DIVIDE)
    {
        g_operand = g_value;
        
        switch (id)
        {
            case IDC_BTN_PLUS:     g_operator = L'+'; break;
            case IDC_BTN_MINUS:    g_operator = L'-'; break;
            case IDC_BTN_MULTIPLY: g_operator = L'*'; break;
            case IDC_BTN_DIVIDE:   g_operator = L'/'; break;
        }
        
        g_newNumber = TRUE;
    }
    // Equals button
    else if (id == IDC_BTN_EQUALS)
    {
        switch (g_operator)
        {
            case L'+': g_value = g_operand + g_value; break;
            case L'-': g_value = g_operand - g_value; break;
            case L'*': g_value = g_operand * g_value; break;
            case L'/':
                if (g_value != 0.0)
                    g_value = g_operand / g_value;
                else
                    MessageBoxW(hwnd, L"Cannot divide by zero!",
                               L"Error", MB_ICONERROR);
                break;
        }
        
        g_operator = L'\0';
        g_newNumber = TRUE;
        UpdateDisplay(hwnd);
    }
    
    return 0;
}
```

**WM_COMMAND explained:**
```c
int id = LOWORD(wParam);      // Control ID
int notifyCode = HIWORD(wParam); // Notification code (BN_CLICKED, etc.)
HWND hControl = (HWND)lParam;    // Handle to control
```

## Complete Calculator Code

Here's the full working calculator:

```c
#include <windows.h>
#include <stdio.h>

// Control IDs
#define IDC_DISPLAY       1001
#define IDC_BTN_0         2000
#define IDC_BTN_1         2001
#define IDC_BTN_2         2002
#define IDC_BTN_3         2003
#define IDC_BTN_4         2004
#define IDC_BTN_5         2005
#define IDC_BTN_6         2006
#define IDC_BTN_7         2007
#define IDC_BTN_8         2008
#define IDC_BTN_9         2009
#define IDC_BTN_PLUS      2010
#define IDC_BTN_MINUS     2011
#define IDC_BTN_MULTIPLY  2012
#define IDC_BTN_DIVIDE    2013
#define IDC_BTN_EQUALS    2014
#define IDC_BTN_CLEAR     2015

// Calculator state
double g_value = 0.0;
double g_operand = 0.0;
wchar_t g_operator = L'\0';
BOOL g_newNumber = TRUE;

// Function prototypes
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void UpdateDisplay(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"CalculatorWindowClass";
    
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    
    if (!RegisterClassW(&wc))
    {
        MessageBoxW(NULL, L"Window Registration Failed!", L"Error",
                   MB_ICONERROR | MB_OK);
        return 0;
    }
    
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"Simple Calculator",
        WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
        CW_USEDEFAULT, CW_USEDEFAULT,
        320, 400,
        NULL, NULL, hInstance, NULL
    );
    
    if (hwnd == NULL)
    {
        MessageBoxW(NULL, L"Window Creation Failed!", L"Error",
                   MB_ICONERROR | MB_OK);
        return 0;
    }
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

void UpdateDisplay(HWND hwnd)
{
    wchar_t buffer[32];
    swprintf(buffer, 32, L"%.10g", g_value);
    SetWindowTextW(GetDlgItem(hwnd, IDC_DISPLAY), buffer);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // Display
            HWND hDisplay = CreateWindowExW(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"0",
                WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY,
                10, 10, 280, 30,
                hwnd,
                (HMENU)IDC_DISPLAY,
                GetModuleHandle(NULL),
                NULL
            );
            
            HFONT hFont = CreateFontW(
                24, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial"
            );
            
            SendMessage(hDisplay, WM_SETFONT, (WPARAM)hFont, TRUE);
            
            // Buttons
            typedef struct {
                const wchar_t* text;
                int id;
            } ButtonInfo;
            
            ButtonInfo buttons[] = {
                {L"7", IDC_BTN_7}, {L"8", IDC_BTN_8}, {L"9", IDC_BTN_9}, {L"/", IDC_BTN_DIVIDE},
                {L"4", IDC_BTN_4}, {L"5", IDC_BTN_5}, {L"6", IDC_BTN_6}, {L"*", IDC_BTN_MULTIPLY},
                {L"1", IDC_BTN_1}, {L"2", IDC_BTN_2}, {L"3", IDC_BTN_3}, {L"-", IDC_BTN_MINUS},
                {L"C", IDC_BTN_CLEAR}, {L"0", IDC_BTN_0}, {L"=", IDC_BTN_EQUALS}, {L"+", IDC_BTN_PLUS}
            };
            
            int btnWidth = 60;
            int btnHeight = 50;
            int btnX = 10;
            int btnY = 50;
            int spacing = 5;
            
            for (int i = 0; i < 16; i++)
            {
                int row = i / 4;
                int col = i % 4;
                int x = btnX + col * (btnWidth + spacing);
                int y = btnY + row * (btnHeight + spacing);
                
                CreateWindowExW(
                    0,
                    L"BUTTON",
                    buttons[i].text,
                    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                    x, y, btnWidth, btnHeight,
                    hwnd,
                    (HMENU)(LONG_PTR)buttons[i].id,
                    GetModuleHandle(NULL),
                    NULL
                );
            }
            
            return 0;
        }
        
        case WM_COMMAND:
        {
            int id = LOWORD(wParam);
            
            if (id >= IDC_BTN_0 && id <= IDC_BTN_9)
            {
                int digit = id - IDC_BTN_0;
                
                if (g_newNumber)
                {
                    g_value = digit;
                    g_newNumber = FALSE;
                }
                else
                {
                    g_value = g_value * 10 + digit;
                }
                
                UpdateDisplay(hwnd);
            }
            else if (id == IDC_BTN_CLEAR)
            {
                g_value = 0.0;
                g_operand = 0.0;
                g_operator = L'\0';
                g_newNumber = TRUE;
                UpdateDisplay(hwnd);
            }
            else if (id == IDC_BTN_PLUS || id == IDC_BTN_MINUS ||
                     id == IDC_BTN_MULTIPLY || id == IDC_BTN_DIVIDE)
            {
                g_operand = g_value;
                
                switch (id)
                {
                    case IDC_BTN_PLUS:     g_operator = L'+'; break;
                    case IDC_BTN_MINUS:    g_operator = L'-'; break;
                    case IDC_BTN_MULTIPLY: g_operator = L'*'; break;
                    case IDC_BTN_DIVIDE:   g_operator = L'/'; break;
                }
                
                g_newNumber = TRUE;
            }
            else if (id == IDC_BTN_EQUALS)
            {
                switch (g_operator)
                {
                    case L'+': g_value = g_operand + g_value; break;
                    case L'-': g_value = g_operand - g_value; break;
                    case L'*': g_value = g_operand * g_value; break;
                    case L'/':
                        if (g_value != 0.0)
                            g_value = g_operand / g_value;
                        else
                            MessageBoxW(hwnd, L"Cannot divide by zero!",
                                       L"Error", MB_ICONERROR);
                        break;
                }
                
                g_operator = L'\0';
                g_newNumber = TRUE;
                UpdateDisplay(hwnd);
            }
            
            return 0;
        }
        
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
        
        case WM_CLOSE:
        {
            if (MessageBoxW(hwnd, L"Really quit?", L"Calculator",
                           MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

**Compile and run:**
```bash
gcc calculator.c -o calculator.exe -mwindows -municode
calculator.exe
```

## Understanding Control Positioning

### Absolute Positioning

We used absolute pixel coordinates:

```c
CreateWindowExW(..., 10, 10, 280, 30, ...);
//                   ^   ^    ^   ^
//                   X   Y    W   H
```

**Coordinate system:**
- (0, 0) is top-left corner of parent window
- X increases to the right
- Y increases downward

### Better Approach: Calculate Positions

```c
RECT clientRect;
GetClientRect(hwnd, &clientRect);

int clientWidth = clientRect.right - clientRect.left;
int clientHeight = clientRect.bottom - clientRect.top;

// Center a button
int btnWidth = 100;
int btnHeight = 30;
int x = (clientWidth - btnWidth) / 2;
int y = (clientHeight - btnHeight) / 2;
```

### Handle Window Resize

```c
case WM_SIZE:
{
    int width = LOWORD(lParam);
    int height = HIWORD(lParam);
    
    // Reposition controls based on new size
    HWND hDisplay = GetDlgItem(hwnd, IDC_DISPLAY);
    SetWindowPos(hDisplay, NULL, 10, 10, width - 20, 30,
                 SWP_NOZORDER);
    
    return 0;
}
```

## Common Control Types

### Edit Controls

```c
CreateWindowExW(0, L"EDIT", L"Initial text",
                WS_CHILD | WS_VISIBLE | WS_BORDER,
                x, y, width, height,
                hwnd, (HMENU)ID, hInstance, NULL);
```

**Styles:**
- `ES_LEFT`, `ES_CENTER`, `ES_RIGHT` - Text alignment
- `ES_MULTILINE` - Multiple lines
- `ES_READONLY` - Read-only
- `ES_PASSWORD` - Hide text with *
- `ES_NUMBER` - Only numbers allowed

### Static Controls (Labels)

```c
CreateWindowExW(0, L"STATIC", L"Label text:",
                WS_CHILD | WS_VISIBLE,
                x, y, width, height,
                hwnd, NULL, hInstance, NULL);
```

### Checkboxes

```c
CreateWindowExW(0, L"BUTTON", L"Enable feature",
                WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
                x, y, width, height,
                hwnd, (HMENU)ID, hInstance, NULL);
```

**Check state:**
```c
BOOL isChecked = (SendMessage(hCheckbox, BM_GETCHECK, 0, 0) == BST_CHECKED);
```

### List Boxes

```c
HWND hList = CreateWindowExW(WS_EX_CLIENTEDGE, L"LISTBOX", NULL,
                              WS_CHILD | WS_VISIBLE | LBS_NOTIFY,
                              x, y, width, height,
                              hwnd, (HMENU)ID, hInstance, NULL);

// Add items
SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"Item 1");
SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)L"Item 2");
```

### Combo Boxes (Drop-down lists)

```c
HWND hCombo = CreateWindowExW(0, L"COMBOBOX", NULL,
                               WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST,
                               x, y, width, height,
                               hwnd, (HMENU)ID, hInstance, NULL);

// Add items
SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"Option 1");
SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)L"Option 2");
```

## Exercises

### Exercise 1: Add Decimal Point
Add a decimal point button to make the calculator support floating-point numbers.

**Hint:**
- Add `IDC_BTN_DECIMAL` constant
- Create button with L"." text
- In WM_COMMAND, append a decimal point if not already present

### Exercise 2: Keyboard Input
Make the calculator respond to keyboard input (number keys, operators).

**Hint:**
- Handle `WM_KEYDOWN` message
- Check `wParam` for virtual key codes (VK_0 through VK_9)
- Call same logic as button clicks

```c
case WM_KEYDOWN:
{
    if (wParam >= '0' && wParam <= '9')
    {
        // Same logic as number button
    }
    return 0;
}
```

### Exercise 3: Memory Functions
Add M+, M-, MR, MC buttons for memory functions.

### Exercise 4: Better Layout
Use `WM_SIZE` to dynamically resize controls when window is resized.

### Exercise 5: Scientific Calculator
Add square root, power, sin, cos, tan functions.

## Common Mistakes

### Mistake 1: Forgetting WS_CHILD

```c
// WRONG - control won't appear
CreateWindowExW(0, L"BUTTON", L"Click", WS_VISIBLE, ...);

// CORRECT
CreateWindowExW(0, L"BUTTON", L"Click", WS_CHILD | WS_VISIBLE, ...);
```

### Mistake 2: Wrong Control ID Type

```c
// WRONG - ID might be truncated
HMENU hMenu = (HMENU)IDC_BUTTON;  // If IDC_BUTTON > 16 bits

// CORRECT (for 64-bit compatibility)
HMENU hMenu = (HMENU)(LONG_PTR)IDC_BUTTON;
```

### Mistake 3: Not Handling WM_COMMAND

```c
// WRONG - buttons won't do anything
case WM_COMMAND:
{
    return 0;  // Missing button logic!
}

// CORRECT
case WM_COMMAND:
{
    int id = LOWORD(wParam);
    // Handle each button ID
    return 0;
}
```

### Mistake 4: Hard-coding Positions

```c
// WRONG - won't adapt to different window sizes
CreateWindowExW(..., 100, 200, 50, 30, ...);

// BETTER - calculate based on window size
RECT rc;
GetClientRect(hwnd, &rc);
int x = (rc.right - 50) / 2;  // Center horizontally
```

## Summary

You've learned:
- ✅ How to register a window class with `RegisterClassW`
- ✅ Creating windows with `CreateWindowExW`
- ✅ Window styles and extended styles
- ✅ Adding controls (buttons, edit controls)
- ✅ Handling `WM_COMMAND` for button clicks
- ✅ State management (calculator state)
- ✅ Common control types and their uses
- ✅ Building a complete functional application

**Next Chapter**: Understanding the Windows message system in depth, including custom messages, message queues, and advanced event handling!

---

# Chapter 15: Windows Message System

## Deep Dive into Windows Messages

In Chapters 13 and 14, you learned the basics of Windows messages. Now let's explore the message system in depth to understand how Windows applications truly work.

In this chapter, you'll learn:
- How the message queue works
- Different types of messages (queued vs sent)
- Custom messages and WM_USER
- Message parameters (wParam and lParam)
- PostMessage vs SendMessage
- How WinRDP uses messages for communication

## Message Flow Architecture

### The Complete Picture

```
┌──────────────────────────────────────────────────────────────────────┐
│                    WINDOWS MESSAGE FLOW DIAGRAM                       │
└──────────────────────────────────────────────────────────────────────┘

USER ACTIONS                          WINDOWS SYSTEM                    YOUR APP
─────────────                        ───────────────                  ──────────

  Mouse Click ──────┐
  Keyboard Press ───┤
  Timer Expires ────┤            ┌─────────────────┐
  Window Resize ────┼───────────►│  Windows OS     │
  Menu Selection ───┤            │  Event System   │
  Button Click  ────┘            └────────┬────────┘
                                          │
                                          │ Generates
                                          │ Message
                                          ▼
                       ┌──────────────────────────────────┐
                       │     THREAD MESSAGE QUEUE          │
                       │  (One per UI thread)              │
                       │                                   │
                       │  ┌────┐ ┌────┐ ┌────┐ ┌────┐   │
                       │  │MSG1│→│MSG2│→│MSG3│→│MSG4│   │
                       │  └────┘ └────┘ └────┘ └────┘   │
                       │    ▲                             │
                       │    │ PostMessage()               │
                       │    │ (async - returns instantly) │
                       └────┼───────────────────┬─────────┘
                            │                   │
           ┌────────────────┘                   │
           │                                    │
           │ SendMessage()                      │ GetMessage()
           │ (sync - waits)                     │ (blocks until
           │ BYPASSES QUEUE                     │  message ready)
           │                                    │
           │                ┌───────────────────┘
           │                │
           │                ▼
           │      ┌──────────────────┐
           │      │ TranslateMessage │  Converts WM_KEYDOWN to
           │      │       ↓          │  WM_CHAR for text input
           │      │ DispatchMessage  │  Routes to Window Proc
           │      └─────────┬────────┘
           │                │
           └────────────────┼──────────────────┐
                            │                   │
                            ▼                   │
                  ┌──────────────────┐         │
                  │   Your Window    │◄────────┘
                  │   Procedure      │
                  │   (WndProc)      │
                  │                  │
                  │  switch(msg) {   │
                  │    case WM_...:  │
                  │      // Handle   │
                  │  }               │
                  └─────────┬────────┘
                            │
                            │ Return value
                            ▼
                     (Back to caller)

KEY CONCEPTS:
┌─────────────────────────────────────────────────────────────────────┐
│ PostMessage → Async  → Adds to queue  → Returns immediately         │
│ SendMessage → Sync   → Bypasses queue → Waits for WindowProc result │
│ GetMessage  → Blocks → Waits for msg  → Drives message loop         │
└─────────────────────────────────────────────────────────────────────┘
```

### Message Queue

Each thread that creates windows has its own **message queue**:

```c
// Message loop
MSG msg;
while (GetMessage(&msg, NULL, 0, 0) > 0)  // Blocks until message arrives
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

**What GetMessage does:**
1. Checks if there are messages in the queue
2. If yes, retrieves the next message
3. If no, **blocks** (waits) until a message arrives
4. Returns 0 when WM_QUIT received (exits the loop)
5. Returns -1 on error

## Queued vs. Sent Messages

### Queued Messages

**Queued messages** go into the message queue:

```c
PostMessage(hwnd, WM_COMMAND, ID_BUTTON, 0);
```

**Characteristics:**
- Asynchronous (doesn't wait)
- Goes into message queue
- Processed by message loop
- Returns immediately

**Examples of queued messages:**
- `WM_KEYDOWN` - Key pressed
- `WM_MOUSEMOVE` - Mouse moved
- `WM_LBUTTONDOWN` - Left button clicked
- `WM_TIMER` - Timer expired
- `WM_PAINT` - Window needs repainting
- `WM_QUIT` - Application should exit

### Sent Messages

**Sent messages** bypass the queue and go directly to window procedure:

```c
SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)L"New Title");
```

**Characteristics:**
- Synchronous (waits for processing)
- Bypasses message queue
- Goes directly to WindowProc
- Returns result from WindowProc

**Examples of sent messages:**
- `WM_SETTEXT` - Set window text
- `WM_GETTEXT` - Get window text
- `WM_SETFONT` - Set control font
- Most control messages (BM_*, EM_*, LB_*, etc.)

### When to Use Each

**Use PostMessage when:**
- You don't need an immediate result
- Calling from another thread
- Want to avoid blocking

**Use SendMessage when:**
- You need the return value
- Must complete before continuing
- Same thread

### Example: The Difference

```c
// PostMessage - returns immediately
PostMessage(hwnd, WM_CLOSE, 0, 0);
printf("This runs immediately!\n");  // Executes before window closes

// SendMessage - waits for completion
SendMessage(hwnd, WM_CLOSE, 0, 0);
printf("This runs after window closes!\n");  // Executes after close completes
```

### Visual Comparison: PostMessage vs SendMessage

```
┌────────────────────────────────────────────────────────────────────────┐
│                   POST MESSAGE (ASYNCHRONOUS)                           │
└────────────────────────────────────────────────────────────────────────┘

Your Code                    Message Queue                Window Proc
─────────                    ─────────────                ───────────

PostMessage(hwnd, WM_...) ──┐
                            │
Returns IMMEDIATELY ◄───────┤
                            │
Continue executing...       │
printf("Done!")             │
                            │
More code runs...           │
                            ▼
                         ┌─────┐
                         │ MSG │  Added to queue
                         └─────┘
                            │
                            │ (Later, when message
                            │  loop processes it)
                            │
                            ▼
                         WindowProc()
                         processes message
                         (Your code already moved on!)


┌────────────────────────────────────────────────────────────────────────┐
│                    SEND MESSAGE (SYNCHRONOUS)                           │
└────────────────────────────────────────────────────────────────────────┘

Your Code                    (Queue bypassed)            Window Proc
─────────                                                ───────────

SendMessage(hwnd, WM_...) ──────────────────────────────►WindowProc()
                                                         processes
WAITS... ⏳                                              message
(Blocked)                                                    │
                                                            │
                                                            │ Processing...
                                                            │
                                                            ▼
Returns with result ◄─────────────────────────────────── return value
                                                         
Now continue...
printf("Done!")                                          (Already finished)


KEY DIFFERENCES:
┌──────────────┬────────────────────┬────────────────────────────────┐
│   Feature    │   PostMessage      │        SendMessage             │
├──────────────┼────────────────────┼────────────────────────────────┤
│ Execution    │ Asynchronous       │ Synchronous (blocks)           │
│ Queue        │ Goes to queue      │ Bypasses queue                 │
│ Return       │ Immediately        │ After WindowProc completes     │
│ Result       │ Success/fail only  │ Returns WindowProc result      │
│ Thread-safe  │ Yes (cross-thread) │ Careful (same thread usually)  │
│ Use case     │ Fire and forget    │ Need result or synchronization │
└──────────────┴────────────────────┴────────────────────────────────┘
```

## Understanding wParam and lParam

Every message has two parameters carrying additional information:

```c
LRESULT WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
```

### What They Mean

- **wParam**: Usually contains small values (IDs, flags, keys)
- **lParam**: Usually contains larger data (pointers, coordinates, handles)

**Historical note:** "W" = Word (16-bit), "L" = Long (32-bit). On modern 64-bit systems, both are pointer-sized.

### Common Message Parameters

#### WM_COMMAND
```c
case WM_COMMAND:
{
    int id = LOWORD(wParam);        // Control ID or menu ID
    int notifyCode = HIWORD(wParam); // Notification code
    HWND hControl = (HWND)lParam;    // Handle to control
}
```

#### WM_SIZE
```c
case WM_SIZE:
{
    int type = wParam;           // SIZE_MAXIMIZED, SIZE_MINIMIZED, etc.
    int width = LOWORD(lParam);  // New width
    int height = HIWORD(lParam); // New height
}
```

#### WM_MOUSEMOVE
```c
case WM_MOUSEMOVE:
{
    int x = LOWORD(lParam);      // X coordinate
    int y = HIWORD(lParam);      // Y coordinate
    UINT flags = wParam;         // MK_LBUTTON, MK_RBUTTON, etc.
}
```

#### WM_KEYDOWN
```c
case WM_KEYDOWN:
{
    int virtualKey = wParam;     // VK_RETURN, VK_ESCAPE, VK_A, etc.
    int repeatCount = LOWORD(lParam);
    int scanCode = (lParam >> 16) & 0xFF;
    BOOL wasDown = (lParam >> 30) & 1;
}
```

#### WM_PAINT
```c
case WM_PAINT:
{
    // wParam and lParam are not used
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    // ... drawing code ...
    EndPaint(hwnd, &ps);
}
```

## Custom Messages

You can define your own messages for communication within your app:

### Defining Custom Messages

```c
#define WM_TRAYICON (WM_USER + 1)
#define WM_HOSTSLOADED (WM_USER + 2)
#define WM_CONNECTIONDONE (WM_USER + 3)
```

**Important:**
- Start at `WM_USER` (0x0400)
- `WM_USER` through `0x7FFF` are for application use
- Above `0x7FFF` are system-defined

### Using Custom Messages

```c
// Send custom message
PostMessage(hwnd, WM_TRAYICON, iconID, WM_LBUTTONDOWN);

// Handle custom message
case WM_TRAYICON:
{
    UINT iconID = (UINT)wParam;
    UINT mouseMsg = (UINT)lParam;
    
    if (mouseMsg == WM_LBUTTONDOWN)
    {
        // User clicked tray icon
    }
    return 0;
}
```

### WinRDP Custom Message Example

WinRDP uses a custom message for system tray clicks:

```c
#define WM_TRAYICON (WM_USER + 1)

// Register tray icon with this message
NOTIFYICONDATAW nid = {0};
nid.uCallbackMessage = WM_TRAYICON;  // Send WM_TRAYICON when clicked
// ... register tray icon ...

// Handle tray icon clicks
case WM_TRAYICON:
{
    if (lParam == WM_LBUTTONDOWN)
    {
        // Show main window
    }
    else if (lParam == WM_RBUTTONDOWN)
    {
        // Show context menu
    }
    return 0;
}
```

## Message Categories

### Window Management Messages

| Message | When Sent |
|---------|-----------|
| `WM_CREATE` | Window is being created |
| `WM_DESTROY` | Window is being destroyed |
| `WM_CLOSE` | User clicked X button |
| `WM_ACTIVATE` | Window activated/deactivated |
| `WM_SETFOCUS` | Window gained keyboard focus |
| `WM_KILLFOCUS` | Window lost keyboard focus |
| `WM_MOVE` | Window was moved |
| `WM_SIZE` | Window was resized |
| `WM_SHOWWINDOW` | Window shown/hidden |

### Input Messages

| Message | When Sent |
|---------|-----------|
| `WM_KEYDOWN` | Key pressed |
| `WM_KEYUP` | Key released |
| `WM_CHAR` | Character input |
| `WM_LBUTTONDOWN` | Left mouse button pressed |
| `WM_LBUTTONUP` | Left mouse button released |
| `WM_RBUTTONDOWN` | Right mouse button pressed |
| `WM_MOUSEMOVE` | Mouse moved |
| `WM_MOUSEWHEEL` | Mouse wheel scrolled |

### Drawing Messages

| Message | When Sent |
|---------|-----------|
| `WM_PAINT` | Window needs repainting |
| `WM_ERASEBKGND` | Background needs erasing |
| `WM_CTLCOLORBTN` | Button needs coloring |
| `WM_CTLCOLOREDIT` | Edit control needs coloring |
| `WM_CTLCOLORSTATIC` | Static control needs coloring |

### Control Messages

| Message | When Sent |
|---------|-----------|
| `WM_COMMAND` | Menu item or control notification |
| `WM_NOTIFY` | Control sending detailed notification |
| `WM_HSCROLL` | Horizontal scroll |
| `WM_VSCROLL` | Vertical scroll |

## PeekMessage vs. GetMessage

### GetMessage - Blocking

```c
MSG msg;
while (GetMessage(&msg, NULL, 0, 0) > 0)  // Blocks if no messages
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

**Use GetMessage when:**
- Normal application behavior
- Low CPU usage (sleeps when no messages)
- Standard Windows applications

### PeekMessage - Non-Blocking

```c
MSG msg;
while (TRUE)
{
    // Check for messages without blocking
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            break;
            
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    else
    {
        // No messages - do background work
        UpdateAnimation();
        RenderFrame();
    }
}
```

**Use PeekMessage when:**
- Games that need continuous rendering
- Real-time applications
- Background processing needed
- Warning: Higher CPU usage!

## Message Filtering

You can filter which messages GetMessage retrieves:

```c
GetMessage(&msg, hwnd, WM_KEYFIRST, WM_KEYLAST);  // Only keyboard messages
```

**Parameters:**
```c
BOOL GetMessage(
    MSG* lpMsg,     // Receives message
    HWND hWnd,      // NULL = all windows in thread
    UINT wMsgMin,   // Minimum message value (0 = all)
    UINT wMsgMax    // Maximum message value (0 = all)
);
```

## Broadcasting Messages

### Send to All Top-Level Windows

```c
SendMessage(HWND_BROADCAST, WM_SETTINGCHANGE, 0, 0);
```

This sends the message to ALL top-level windows in the system.

### Send to Child Windows

```c
// Send to all children
EnumChildWindows(hwndParent, EnumChildProc, lParam);

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
{
    SendMessage(hwnd, WM_SETFONT, (WPARAM)hFont, TRUE);
    return TRUE;  // Continue enumeration
}
```

## Timers and WM_TIMER

Timers generate periodic `WM_TIMER` messages:

### Creating a Timer

```c
// In WM_CREATE or initialization
SetTimer(
    hwnd,        // Window to receive WM_TIMER
    1,           // Timer ID
    1000,        // Interval in milliseconds (1 second)
    NULL         // Timer procedure (NULL = use WM_TIMER)
);
```

### Handling WM_TIMER

```c
case WM_TIMER:
{
    int timerID = (int)wParam;
    
    if (timerID == 1)
    {
        // Update clock, check for updates, etc.
        UpdateClock(hwnd);
    }
    
    return 0;
}
```

### Destroying Timer

```c
// In WM_DESTROY
KillTimer(hwnd, 1);  // Kill timer with ID 1
```

### Timer Callback (Alternative)

```c
void CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime)
{
    // This runs when timer fires
    // No WM_TIMER message sent
}

// Set timer with callback
SetTimer(hwnd, 1, 1000, TimerProc);
```

## Practical Example: Auto-Saving Application

Let's build an application that auto-saves every 5 seconds:

```c
#include <windows.h>
#include <stdio.h>

#define IDC_EDIT 1001
#define TIMER_AUTOSAVE 1

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void SaveContent(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    const wchar_t CLASS_NAME[] = L"AutoSaveEditor";
    
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    
    RegisterClassW(&wc);
    
    HWND hwnd = CreateWindowExW(
        0, CLASS_NAME, L"Auto-Save Editor",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 600, 400,
        NULL, NULL, hInstance, NULL
    );
    
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
        {
            // Create multiline edit control
            CreateWindowExW(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"Type something...\nIt will auto-save every 5 seconds.",
                WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL,
                10, 10, 560, 320,
                hwnd,
                (HMENU)IDC_EDIT,
                GetModuleHandle(NULL),
                NULL
            );
            
            // Start auto-save timer (5 seconds)
            SetTimer(hwnd, TIMER_AUTOSAVE, 5000, NULL);
            
            return 0;
        }
        
        case WM_TIMER:
        {
            if (wParam == TIMER_AUTOSAVE)
            {
                SaveContent(hwnd);
            }
            return 0;
        }
        
        case WM_SIZE:
        {
            // Resize edit control when window resizes
            int width = LOWORD(lParam);
            int height = HIWORD(lParam);
            
            HWND hEdit = GetDlgItem(hwnd, IDC_EDIT);
            SetWindowPos(hEdit, NULL, 10, 10, width - 20, height - 60, SWP_NOZORDER);
            
            return 0;
        }
        
        case WM_CLOSE:
        {
            // Save before closing
            SaveContent(hwnd);
            DestroyWindow(hwnd);
            return 0;
        }
        
        case WM_DESTROY:
        {
            KillTimer(hwnd, TIMER_AUTOSAVE);
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void SaveContent(HWND hwnd)
{
    HWND hEdit = GetDlgItem(hwnd, IDC_EDIT);
    
    // Get text length
    int length = GetWindowTextLengthW(hEdit);
    if (length == 0)
        return;
    
    // Allocate buffer
    wchar_t* buffer = (wchar_t*)malloc((length + 1) * sizeof(wchar_t));
    if (buffer == NULL)
        return;
    
    // Get text
    GetWindowTextW(hEdit, buffer, length + 1);
    
    // Save to file
    FILE* file = _wfopen(L"autosave.txt", L"w, ccs=UTF-8");
    if (file)
    {
        fwprintf(file, L"%s", buffer);
        fclose(file);
        
        // Show saved message in title
        wchar_t title[64];
        swprintf(title, 64, L"Auto-Save Editor - Saved at %d ms", GetTickCount());
        SetWindowTextW(hwnd, title);
    }
    
    free(buffer);
}
```

**Compile:**
```bash
gcc autosave.c -o autosave.exe -mwindows -municode
```

**What it does:**
- Creates a text editor
- Automatically saves content every 5 seconds
- Updates window title when saved
- Saves on close

## Message Return Values

The return value of WindowProc has meaning:

```c
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            return 0;        // Success
            // return -1;    // Failure (window won't be created)
            
        case WM_CLOSE:
            DestroyWindow(hwnd);
            return 0;        // Message processed
            
        case WM_NCHITTEST:
            return HTCLIENT; // Says cursor is in client area
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

**Common return values:**
- `0` - Message processed successfully
- `-1` - Error (for some messages like WM_CREATE)
- Specific values (for WM_NCHITTEST, WM_CTLCOLOR*, etc.)

## DefWindowProc: The Default Handler

Always call `DefWindowProc` for unhandled messages:

```c
return DefWindowProc(hwnd, uMsg, wParam, lParam);
```

**What DefWindowProc does:**
- Provides default behavior for all messages
- Ensures window behaves normally
- Required for proper window operation

**Messages you should NOT call DefWindowProc for:**
- Messages you fully handle
- Messages where you return a specific value

## Message Processing Order

When you send a message:

1. **Sent messages** processed first (SendMessage)
2. **Paint messages** (WM_PAINT) processed next
3. **Posted messages** processed last (PostMessage)
4. **Timers** processed when no other messages

### Priority Example

```c
PostMessage(hwnd, WM_USER, 1, 0);      // Queued - processed last
SendMessage(hwnd, WM_USER, 2, 0);      // Sent - processed first
PostMessage(hwnd, WM_USER, 3, 0);      // Queued - processed last

// Processing order: 2, 1, 3
```

## Inter-Thread Communication

For communicating between threads, use messages:

### From Worker Thread to UI Thread

```c
// Worker thread
DWORD WINAPI WorkerThread(LPVOID param)
{
    HWND hwndMain = (HWND)param;
    
    // Do work...
    
    // Notify UI thread (safe!)
    PostMessage(hwndMain, WM_WORKCOMPLETE, 0, 0);
    
    return 0;
}

// UI thread window procedure
case WM_WORKCOMPLETE:
{
    MessageBoxW(hwnd, L"Work complete!", L"Info", MB_OK);
    return 0;
}
```

**Important:**
- Use `PostMessage` (not SendMessage) from other threads
- Never access UI controls directly from worker threads
- Always communicate via messages

## Debugging Messages

### Message Logger

Useful for debugging - log all messages:

```c
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Log message (for debugging)
    #ifdef DEBUG_MESSAGES
    wchar_t buffer[256];
    swprintf(buffer, 256, L"Message: 0x%04X, wParam: 0x%08X, lParam: 0x%08X\n",
             uMsg, (UINT)wParam, (UINT)lParam);
    OutputDebugStringW(buffer);
    #endif
    
    // Process message
    switch (uMsg)
    {
        // ... handle messages ...
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
```

Use DebugView from Microsoft to see OutputDebugString output.

## Summary of Message Functions

| Function | Purpose | Blocks? |
|----------|---------|---------|
| `GetMessage` | Retrieve message from queue | Yes |
| `PeekMessage` | Check for message | No |
| `PostMessage` | Add message to queue | No |
| `SendMessage` | Send directly to WindowProc | Yes |
| `DispatchMessage` | Call WindowProc with message | Yes |
| `TranslateMessage` | Convert keyboard messages | No |
| `PostQuitMessage` | Add WM_QUIT to queue | No |

## Exercises

### Exercise 1: Clock Application
Create an application that shows the current time and updates every second using WM_TIMER.

**Hint:**
```c
SetTimer(hwnd, 1, 1000, NULL);

case WM_TIMER:
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    // Update display
}
```

### Exercise 2: Mouse Tracker
Create a window that displays the current mouse position using WM_MOUSEMOVE.

### Exercise 3: Custom Message
Define a custom message and send it between two windows.

### Exercise 4: Key Logger
Log all key presses (WM_KEYDOWN) to a file with timestamps.

### Exercise 5: Progress Indicator
Create a progress bar that updates via custom messages from a worker thread.

## Common Mistakes

### Mistake 1: Forgetting DefWindowProc

```c
// WRONG - window won't work properly
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return 0;  // WRONG! Missing DefWindowProc
}

// CORRECT
return DefWindowProc(hwnd, uMsg, wParam, lParam);
```

### Mistake 2: Using SendMessage from Wrong Thread

```c
// WRONG - can deadlock!
DWORD WINAPI WorkerThread(LPVOID param)
{
    HWND hwnd = (HWND)param;
    SendMessage(hwnd, WM_USER, 0, 0);  // Can deadlock!
}

// CORRECT
PostMessage(hwnd, WM_USER, 0, 0);  // Safe!
```

### Mistake 3: Not Killing Timers

```c
// WRONG - timer keeps running after window destroyed
case WM_DESTROY:
{
    PostQuitMessage(0);
    return 0;
}

// CORRECT
case WM_DESTROY:
{
    KillTimer(hwnd, TIMER_ID);
    PostQuitMessage(0);
    return 0;
}
```

### Mistake 4: Blocking in WindowProc

```c
// WRONG - UI freezes!
case WM_COMMAND:
{
    if (id == IDC_PROCESS)
    {
        Sleep(5000);  // UI freezes for 5 seconds!
    }
}

// CORRECT - use worker thread
case WM_COMMAND:
{
    if (id == IDC_PROCESS)
    {
        CreateThread(NULL, 0, WorkerThread, hwnd, 0, NULL);
    }
}
```

## How WinRDP Uses Messages

### System Tray Icon

```c
#define WM_TRAYICON (WM_USER + 1)

// Register tray icon
nid.uCallbackMessage = WM_TRAYICON;
Shell_NotifyIconW(NIM_ADD, &nid);

// Handle clicks
case WM_TRAYICON:
{
    if (lParam == WM_LBUTTONDOWN)
    {
        // Show/hide main window
    }
    else if (lParam == WM_RBUTTONDOWN)
    {
        // Show context menu
    }
}
```

### ListView Notifications

```c
case WM_NOTIFY:
{
    LPNMHDR pnmhdr = (LPNMHDR)lParam;
    
    if (pnmhdr->idFrom == IDC_HOST_LIST)
    {
        if (pnmhdr->code == NM_DBLCLK)
        {
            // User double-clicked host - connect!
            ConnectToSelectedHost();
        }
    }
}
```

### Global Hotkey

```c
#define HOTKEY_ID 1

// Register hotkey (Ctrl+Shift+R)
RegisterHotKey(hwnd, HOTKEY_ID, MOD_CONTROL | MOD_SHIFT, 'R');

// Handle hotkey
case WM_HOTKEY:
{
    if (wParam == HOTKEY_ID)
    {
        // Show main window
        ShowWindow(hwnd, SW_SHOW);
    }
}
```

## Summary

You've learned:
- ✅ How message queues work
- ✅ Difference between queued and sent messages
- ✅ PostMessage vs SendMessage
- ✅ Message parameters (wParam and lParam)
- ✅ Custom messages with WM_USER
- ✅ Timers and WM_TIMER
- ✅ Inter-thread communication with messages
- ✅ Message processing order and priorities
- ✅ DefWindowProc and return values
- ✅ How to debug messages

**Next Chapter**: Dialog boxes and controls - creating professional dialog-based applications like WinRDP!

---

# Chapter 16: Dialog Boxes and Controls

## Professional User Interfaces with Dialogs

So far, you've created windows manually with CreateWindowEx. But most Windows applications use **dialog boxes** for their interface - they're easier to create and maintain!

In this chapter, you'll learn:
- What dialog boxes are and why use them
- Creating dialogs with resource files
- Dialog procedures vs window procedures
- Common dialog boxes (File Open, Color Picker, etc.)
- How WinRDP uses dialogs
- Building a login dialog

## What Are Dialog Boxes?

### Dialog vs Window

**Traditional Window:**
- Created with CreateWindowEx
- Manual control positioning
- Write lots of positioning code
- Hard to maintain

**Dialog Box:**
- Defined in resource file (.rc)
- Visual layout (can use editors)
- Automatic tab order
- Easier to maintain

### Types of Dialogs

**Modal Dialog:**
- Blocks parent window
- Must close before using parent
- Used for critical input

**Modeless Dialog:**
- Doesn't block parent
- Can switch between parent and dialog
- Used for tool windows, find/replace

## Resource Files (.rc)

Resource files define dialogs, menus, icons, and strings:

### Example Resource File

Create `resources.rc`:

```rc
#include "resource.h"

// Dialog definition
IDD_LOGIN DIALOG 0, 0, 200, 100
STYLE DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Login"
FONT 9, "Segoe UI"
BEGIN
    LTEXT "Username:", IDC_STATIC, 10, 10, 60, 12
    EDITTEXT IDC_USERNAME, 70, 10, 120, 14, ES_AUTOHSCROLL
    
    LTEXT "Password:", IDC_STATIC, 10, 30, 60, 12
    EDITTEXT IDC_PASSWORD, 70, 30, 120, 14, ES_AUTOHSCROLL | ES_PASSWORD
    
    DEFPUSHBUTTON "OK", IDOK, 50, 70, 50, 14
    PUSHBUTTON "Cancel", IDCANCEL, 110, 70, 50, 14
END
```

Create `resource.h`:

```c
#define IDD_LOGIN 101
#define IDC_USERNAME 1001
#define IDC_PASSWORD 1002
#define IDC_STATIC -1
```

### Dialog Resource Syntax

```rc
IDD_DIALOGID DIALOG x, y, width, height
STYLE style_flags
CAPTION "title"
FONT pointsize, "fontname"
BEGIN
    // Controls go here
END
```

**Style flags:**
- `DS_CENTER` - Center on screen
- `DS_MODALFRAME` - Modal dialog frame
- `WS_POPUP` - Pop-up window
- `WS_CAPTION` - Has title bar
- `WS_SYSMENU` - Has system menu (X button)

### Control Types in Resources

```rc
PUSHBUTTON "text", id, x, y, width, height
DEFPUSHBUTTON "text", id, x, y, width, height  // Default button
EDITTEXT id, x, y, width, height, styles
LTEXT "text", id, x, y, width, height          // Left-aligned label
RTEXT "text", id, x, y, width, height          // Right-aligned label
CTEXT "text", id, x, y, width, height          // Centered label
CHECKBOX "text", id, x, y, width, height
RADIOBUTTON "text", id, x, y, width, height
LISTBOX id, x, y, width, height, styles
COMBOBOX id, x, y, width, height, styles
CONTROL "text", id, "class", styles, x, y, width, height
```

## Dialog Procedures

Dialog procedures are similar to window procedures:

```c
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
            // Initialize dialog
            return TRUE;
            
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                    // OK button clicked
                    EndDialog(hDlg, IDOK);
                    return TRUE;
                    
                case IDCANCEL:
                    // Cancel button clicked
                    EndDialog(hDlg, IDCANCEL);
                    return TRUE;
            }
            break;
    }
    
    return FALSE;  // Not TRUE or DefWindowProc!
}
```

**Key differences from WindowProc:**
- Returns `INT_PTR` (not LRESULT)
- Returns `TRUE` if message processed, `FALSE` if not
- **No** DefWindowProc - just return FALSE
- Use `WM_INITDIALOG` instead of WM_CREATE
- Use `EndDialog` to close (not DestroyWindow)

## Creating Modal Dialogs

### DialogBox Function

```c
INT_PTR result = DialogBox(
    hInstance,              // Application instance
    MAKEINTRESOURCE(IDD_LOGIN),  // Dialog resource ID
    hwndParent,             // Parent window
    DialogProc              // Dialog procedure
);

if (result == IDOK)
{
    // User clicked OK
}
else if (result == IDCANCEL)
{
    // User clicked Cancel
}
```

**MAKEINTRESOURCE:** Converts integer ID to resource name.

## Getting/Setting Dialog Control Values

### Getting Text from Edit Control

```c
case WM_COMMAND:
{
    if (LOWORD(wParam) == IDOK)
    {
        wchar_t username[256];
        wchar_t password[256];
        
        GetDlgItemTextW(hDlg, IDC_USERNAME, username, 256);
        GetDlgItemTextW(hDlg, IDC_PASSWORD, password, 256);
        
        // Validate and process
        if (ValidateLogin(username, password))
        {
            EndDialog(hDlg, IDOK);
        }
        else
        {
            MessageBoxW(hDlg, L"Invalid credentials!", L"Error", MB_OK | MB_ICONERROR);
        }
        
        return TRUE;
    }
}
```

### Setting Text to Control

```c
case WM_INITDIALOG:
{
    SetDlgItemTextW(hDlg, IDC_USERNAME, L"DefaultUser");
    return TRUE;
}
```

### Getting Checkbox State

```c
BOOL isChecked = IsDlgButtonChecked(hDlg, IDC_REMEMBER);
```

### Setting Checkbox State

```c
CheckDlgButton(hDlg, IDC_REMEMBER, BST_CHECKED);    // Check
CheckDlgButton(hDlg, IDC_REMEMBER, BST_UNCHECKED);  // Uncheck
```

## Complete Login Dialog Example

### resources.rc

```rc
#include "resource.h"

IDD_LOGIN DIALOG 0, 0, 250, 120
STYLE DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Login to WinRDP"
FONT 9, "Segoe UI"
BEGIN
    ICON IDI_APP_ICON, IDC_STATIC, 10, 10, 20, 20
    
    LTEXT "Username:", IDC_STATIC, 40, 15, 60, 12
    EDITTEXT IDC_USERNAME, 100, 12, 140, 14, ES_AUTOHSCROLL
    
    LTEXT "Password:", IDC_STATIC, 40, 35, 60, 12
    EDITTEXT IDC_PASSWORD, 100, 32, 140, 14, ES_AUTOHSCROLL | ES_PASSWORD
    
    AUTOCHECKBOX "Remember me", IDC_REMEMBER, 100, 52, 140, 12
    
    LTEXT "Domain:", IDC_STATIC, 40, 72, 60, 12
    COMBOBOX IDC_DOMAIN, 100, 70, 140, 50, CBS_DROPDOWN | CBS_SORT | WS_VSCROLL
    
    DEFPUSHBUTTON "OK", IDOK, 90, 95, 70, 16
    PUSHBUTTON "Cancel", IDCANCEL, 170, 95, 70, 16
END
```

### resource.h

```c
#ifndef RESOURCE_H
#define RESOURCE_H

#define IDD_LOGIN 101
#define IDC_USERNAME 1001
#define IDC_PASSWORD 1002
#define IDC_REMEMBER 1003
#define IDC_DOMAIN 1004
#define IDI_APP_ICON 2001
#define IDC_STATIC -1

#endif
```

### login.c

```c
#include <windows.h>
#include <stdio.h>
#include "resource.h"

typedef struct {
    wchar_t username[256];
    wchar_t password[256];
    wchar_t domain[256];
    BOOL remember;
} LoginInfo;

INT_PTR CALLBACK LoginDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{
    LoginInfo info = {0};
    
    INT_PTR result = DialogBoxParam(
        hInstance,
        MAKEINTRESOURCE(IDD_LOGIN),
        NULL,
        LoginDialogProc,
        (LPARAM)&info
    );
    
    if (result == IDOK)
    {
        wchar_t message[512];
        swprintf(message, 512, L"Logged in as:\nUser: %s\nDomain: %s\nRemember: %s",
                info.username, info.domain, info.remember ? L"Yes" : L"No");
        MessageBoxW(NULL, message, L"Success", MB_OK);
    }
    else
    {
        MessageBoxW(NULL, L"Login cancelled", L"Cancelled", MB_OK);
    }
    
    return 0;
}

INT_PTR CALLBACK LoginDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static LoginInfo* pInfo = NULL;
    
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            // Store pointer to LoginInfo
            pInfo = (LoginInfo*)lParam;
            
            // Set default username
            SetDlgItemTextW(hDlg, IDC_USERNAME, L"admin");
            
            // Add domains to combo box
            SendDlgItemMessageW(hDlg, IDC_DOMAIN, CB_ADDSTRING, 0, (LPARAM)L"WORKGROUP");
            SendDlgItemMessageW(hDlg, IDC_DOMAIN, CB_ADDSTRING, 0, (LPARAM)L"DOMAIN1");
            SendDlgItemMessageW(hDlg, IDC_DOMAIN, CB_ADDSTRING, 0, (LPARAM)L"DOMAIN2");
            SendDlgItemMessageW(hDlg, IDC_DOMAIN, CB_SETCURSEL, 0, 0);  // Select first
            
            // Focus on password field
            SetFocus(GetDlgItem(hDlg, IDC_PASSWORD));
            return FALSE;  // We set focus manually
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // Get values
                    GetDlgItemTextW(hDlg, IDC_USERNAME, pInfo->username, 256);
                    GetDlgItemTextW(hDlg, IDC_PASSWORD, pInfo->password, 256);
                    GetDlgItemTextW(hDlg, IDC_DOMAIN, pInfo->domain, 256);
                    pInfo->remember = IsDlgButtonChecked(hDlg, IDC_REMEMBER);
                    
                    // Validate
                    if (wcslen(pInfo->username) == 0)
                    {
                        MessageBoxW(hDlg, L"Please enter a username", L"Error", 
                                   MB_OK | MB_ICONERROR);
                        SetFocus(GetDlgItem(hDlg, IDC_USERNAME));
                        return TRUE;
                    }
                    
                    if (wcslen(pInfo->password) == 0)
                    {
                        MessageBoxW(hDlg, L"Please enter a password", L"Error",
                                   MB_OK | MB_ICONERROR);
                        SetFocus(GetDlgItem(hDlg, IDC_PASSWORD));
                        return TRUE;
                    }
                    
                    // Success
                    EndDialog(hDlg, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                {
                    EndDialog(hDlg, IDCANCEL);
                    return TRUE;
                }
            }
            break;
        }
        
        case WM_CLOSE:
        {
            EndDialog(hDlg, IDCANCEL);
            return TRUE;
        }
    }
    
    return FALSE;
}
```

### Compiling with Resources

```bash
# Compile resource file
windres resources.rc -o resources.o

# Compile and link
gcc login.c resources.o -o login.exe -mwindows -municode
```

## Modeless Dialogs

Modeless dialogs don't block the parent:

### Creating Modeless Dialog

```c
HWND hDlg = CreateDialogParam(
    hInstance,
    MAKEINTRESOURCE(IDD_FIND),
    hwndParent,
    FindDialogProc,
    0
);

ShowWindow(hDlg, SW_SHOW);
```

**Key difference:** Returns HWND (not INT_PTR).

### Message Loop for Modeless Dialogs

```c
MSG msg;
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
    // Check if message is for modeless dialog
    if (hDlg == NULL || !IsDialogMessage(hDlg, &msg))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
```

**IsDialogMessage:** Handles tab key, accelerators, etc.

### Closing Modeless Dialog

```c
case IDCANCEL:
{
    DestroyWindow(hDlg);  // Not EndDialog!
    hDlg = NULL;
    return TRUE;
}
```

## Common Dialogs

Windows provides standard dialogs for common tasks:

### File Open Dialog

```c
#include <commdlg.h>

wchar_t filename[MAX_PATH] = L"";

OPENFILENAMEW ofn = {0};
ofn.lStructSize = sizeof(ofn);
ofn.hwndOwner = hwnd;
ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
ofn.lpstrFile = filename;
ofn.nMaxFile = MAX_PATH;
ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
ofn.lpstrTitle = L"Open File";

if (GetOpenFileNameW(&ofn))
{
    // User selected a file
    MessageBoxW(hwnd, filename, L"Selected", MB_OK);
}
```

### File Save Dialog

```c
OPENFILENAMEW ofn = {0};
ofn.lStructSize = sizeof(ofn);
ofn.hwndOwner = hwnd;
ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
ofn.lpstrFile = filename;
ofn.nMaxFile = MAX_PATH;
ofn.Flags = OFN_OVERWRITEPROMPT;
ofn.lpstrDefExt = L"txt";
ofn.lpstrTitle = L"Save File";

if (GetSaveFileNameW(&ofn))
{
    // User entered a filename
}
```

### Color Picker Dialog

```c
CHOOSECOLORW cc = {0};
COLORREF customColors[16] = {0};

cc.lStructSize = sizeof(cc);
cc.hwndOwner = hwnd;
cc.lpCustColors = customColors;
cc.Flags = CC_FULLOPEN | CC_RGBINIT;
cc.rgbResult = RGB(255, 0, 0);  // Initial color (red)

if (ChooseColorW(&cc))
{
    COLORREF color = cc.rgbResult;
    
    // Extract RGB components
    BYTE r = GetRValue(color);
    BYTE g = GetGValue(color);
    BYTE b = GetBValue(color);
}
```

### Font Picker Dialog

```c
CHOOSEFONTW cf = {0};
LOGFONTW lf = {0};

cf.lStructSize = sizeof(cf);
cf.hwndOwner = hwnd;
cf.lpLogFont = &lf;
cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

if (ChooseFontW(&cf))
{
    // Create font from LOGFONT
    HFONT hFont = CreateFontIndirectW(&lf);
    
    // Use font...
    SendMessage(hControl, WM_SETFONT, (WPARAM)hFont, TRUE);
}
```

## ListView Control (Advanced)

ListView is essential for displaying lists - WinRDP uses it for the host list:

### Creating ListView

```c
HWND hListView = CreateWindowExW(
    0,
    WC_LISTVIEW,  // "SysListView32"
    L"",
    WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
    10, 10, 500, 300,
    hwnd,
    (HMENU)IDC_LISTVIEW,
    hInstance,
    NULL
);

// Enable full row select and grid lines
ListView_SetExtendedListViewStyle(hListView, 
    LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
```

### Adding Columns

```c
LVCOLUMNW lvc = {0};
lvc.mask = LVCF_TEXT | LVCF_WIDTH;

// Column 1: Hostname
lvc.pszText = L"Hostname";
lvc.cx = 150;
ListView_InsertColumn(hListView, 0, &lvc);

// Column 2: Description
lvc.pszText = L"Description";
lvc.cx = 250;
ListView_InsertColumn(hListView, 1, &lvc);

// Column 3: Status
lvc.pszText = L"Status";
lvc.cx = 100;
ListView_InsertColumn(hListView, 2, &lvc);
```

### Adding Items

```c
LVITEMW lvi = {0};
lvi.mask = LVIF_TEXT;
lvi.iItem = 0;
lvi.iSubItem = 0;
lvi.pszText = L"server1.local";
int index = ListView_InsertItem(hListView, &lvi);

// Set subitems (columns)
ListView_SetItemText(hListView, index, 1, L"Production Server");
ListView_SetItemText(hListView, index, 2, L"Online");
```

### Getting Selected Item

```c
int selected = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
if (selected != -1)
{
    wchar_t hostname[256];
    ListView_GetItemText(hListView, selected, 0, hostname, 256);
    
    wchar_t msg[300];
    swprintf(msg, 300, L"Selected: %s", hostname);
    MessageBoxW(hwnd, msg, L"Info", MB_OK);
}
```

### Handling Double-Click

```c
case WM_NOTIFY:
{
    LPNMHDR pnmhdr = (LPNMHDR)lParam;
    
    if (pnmhdr->idFrom == IDC_LISTVIEW && pnmhdr->code == NM_DBLCLK)
    {
        // Get selected item
        int selected = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
        if (selected != -1)
        {
            wchar_t hostname[256];
            ListView_GetItemText(hListView, selected, 0, hostname, 256);
            
            // Connect to server
            ConnectToHost(hostname);
        }
    }
    
    return 0;
}
```

## How WinRDP Uses Dialogs

### Main Dialog (Modeless)

WinRDP's main interface is a modeless dialog:

```c
// main.c
HWND hMainDlg = CreateDialogParam(
    hInstance,
    MAKEINTRESOURCE(IDD_MAIN_DIALOG),
    hwnd,
    MainDialogProc,
    0
);
```

**Benefits:**
- Easy layout with resource file
- Automatic control management
- Tab order handling

### Login Dialog (Modal)

```c
INT_PTR result = DialogBoxParam(
    hInstance,
    MAKEINTRESOURCE(IDD_LOGIN),
    hwnd,
    LoginDialogProc,
    0
);

if (result == IDOK)
{
    // User logged in - show main dialog
}
```

### Host ListView

```c
// Populate ListView with hosts from CSV
for (int i = 0; i < hostCount; i++)
{
    LVITEMW lvi = {0};
    lvi.mask = LVIF_TEXT | LVIF_PARAM;
    lvi.iItem = i;
    lvi.pszText = hosts[i].hostname;
    lvi.lParam = (LPARAM)&hosts[i];
    
    int index = ListView_InsertItem(hListView, &lvi);
    ListView_SetItemText(hListView, index, 1, hosts[i].description);
}
```

## Dialog Units vs Pixels

Resource files use **dialog units**, not pixels:

**Dialog units** are based on font size:
- 4 horizontal dialog units = average character width
- 8 vertical dialog units = average character height

**Why?** Dialogs scale properly with different font sizes.

**Convert dialog units to pixels:**

```c
RECT rc = {0, 0, 100, 50};  // 100x50 dialog units
MapDialogRect(hDlg, &rc);
// rc now contains pixel coordinates
```

## Tab Order and Keyboard Navigation

Windows automatically handles:
- **Tab** - Move to next control
- **Shift+Tab** - Move to previous control
- **Alt+Letter** - Activate control with that mnemonic

### WinRDP Keyboard Flow (v1.2.0 Update)

The 1.2.0 polish pass standardized keyboard-first navigation across every dialog:

- **Login dialog:** `Username → Password → Delete Saved → Save & Continue → Cancel`
- **Main dialog:** `Search → Server List → Connect → Manage Hosts → Edit Credentials → Close`
- **Manage Hosts dialog:** `Search → Host List → Add Host → Edit Host → Delete Host → Scan Domain → Close`
- **Add/Edit Host dialog:** `Hostname → Description → Use custom credentials → Username → Password → Save → Cancel`
- **Scan Domain dialog:** `Domain → Workstations → Servers → Domain Controllers → Scan → Cancel`

> **Enter key shortcuts**
> - Press **Enter** on a selected host in the main dialog to connect instantly (mirrors the `Connect` button)
> - Press **Enter** on a selected host in the management dialog to open the edit form
> - Default buttons (`DEFPUSHBUTTON`) now reflect the common action in each dialog, so the Enter key always does the right thing

### Setting Tab Order

In resource file, define controls in tab order:

```rc
BEGIN
    EDITTEXT IDC_FIRST, ...     // Tab order: 1
    EDITTEXT IDC_SECOND, ...    // Tab order: 2
    PUSHBUTTON "OK", IDOK, ...  // Tab order: 3
END
```

### Mnemonics (Keyboard Shortcuts)

Use & in control text:

```rc
PUSHBUTTON "&OK", IDOK, ...       // Alt+O
PUSHBUTTON "&Cancel", IDCANCEL, ... // Alt+C
LTEXT "&Username:", IDC_STATIC, ... // Alt+U focuses next control
```

## Dialog Templates in Code (Without .rc)

You can create dialogs without resource files:

```c
typedef struct {
    DLGTEMPLATE dlg;
    WORD menu;
    WORD windowClass;
    WCHAR title[20];
    // Followed by control definitions
} DialogTemplate;

// Complex - usually better to use .rc files!
```

**Recommendation:** Use resource files - they're much easier!

## Exercises

### Exercise 1: Settings Dialog
Create a settings dialog with checkboxes, radio buttons, and combo boxes.

### Exercise 2: About Dialog
Create an "About" dialog showing version, copyright, and a logo.

**Hint:**
```rc
IDD_ABOUT DIALOG 0, 0, 200, 100
BEGIN
    ICON IDI_APP, IDC_STATIC, 10, 10, 20, 20
    LTEXT "MyApp v1.0", IDC_STATIC, 40, 10, 150, 12
    LTEXT "Copyright 2024", IDC_STATIC, 40, 25, 150, 12
    DEFPUSHBUTTON "OK", IDOK, 75, 80, 50, 14
END
```

### Exercise 3: Find and Replace
Create modeless Find and Replace dialogs.

### Exercise 4: ListView Manager
Create an app that manages a list of tasks with Add, Edit, Delete buttons.

### Exercise 5: Wizard
Create a multi-page wizard using multiple dialogs.

## Common Mistakes

### Mistake 1: Using DefWindowProc in Dialog Procedure

```c
// WRONG
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // ...
    return DefWindowProc(hDlg, uMsg, wParam, lParam);  // WRONG!
}

// CORRECT
return FALSE;  // Let dialog manager handle it
```

### Mistake 2: DestroyWindow Instead of EndDialog

```c
// WRONG - for modal dialog
case IDOK:
{
    DestroyWindow(hDlg);  // WRONG!
}

// CORRECT
case IDOK:
{
    EndDialog(hDlg, IDOK);
}
```

### Mistake 3: Forgetting to Process Modeless Dialog Messages

```c
// WRONG - tab key won't work!
MSG msg;
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}

// CORRECT
while (GetMessage(&msg, NULL, 0, 0) > 0)
{
    if (!IsDialogMessage(hDlg, &msg))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}
```

### Mistake 4: Not Initializing Common Controls

For ListView, TreeView, etc., initialize first:

```c
// In WinMain, before creating controls
INITCOMMONCONTROLSEX icc = {0};
icc.dwSize = sizeof(icc);
icc.dwICC = ICC_LISTVIEW_CLASSES;
InitCommonControlsEx(&icc);
```

## Summary

You've learned:
- ✅ What dialog boxes are and their advantages
- ✅ Resource files (.rc) for dialog definitions
- ✅ Dialog procedures and their differences from window procedures
- ✅ Modal vs modeless dialogs
- ✅ Getting/setting control values
- ✅ Common dialogs (file, color, font)
- ✅ ListView control for displaying lists
- ✅ How WinRDP uses dialogs
- ✅ Tab order and keyboard navigation

**Congratulations!** You've completed Part III (Windows Programming Basics)!

You now know:
- Part I: C Fundamentals
- Part II: Advanced C Concepts
- Part III: Windows Programming Basics

**Next: Part IV - Building WinRDP Core!**

In Part IV, you'll apply everything you've learned to build the complete WinRDP application, module by module, feature by feature!

---

# Part III Complete!

You now have all the Windows programming knowledge needed to build real applications. In Part IV, we'll build WinRDP from scratch, starting with project setup and progressively adding each feature.

**Preview of Part IV:**
- Chapter 17: Project Setup and Architecture
- Chapter 18: Configuration and Utilities
- Chapter 19: CSV File Management (hosts.c)
- Chapter 20: Windows Credential Manager (credentials.c)
- Chapter 21: Main Application Window (main.c)
- Chapter 22: ListView Control for Host Display
- Chapter 23: RDP Connection Logic (rdp.c)
- Chapter 24: System Tray Integration

Ready to build something real? Let's continue! 🚀

---

# PART IV: BUILDING WINRDP CORE

This is where everything comes together! In the next 8 chapters, you'll build WinRDP from the ground up, module by module. Each chapter adds a working feature to the application.

**What You'll Build:**
- Chapter 17: Project structure and architecture
- Chapter 18: Configuration and utility functions
- Chapter 19: CSV file management for host lists
- Chapter 20: Secure credential storage
- Chapter 21: Main application window with system tray
- Chapter 22: ListView control to display hosts
- Chapter 23: RDP connection functionality
- Chapter 24: Complete system tray integration

By the end of Part IV, you'll have a **fully functional RDP connection manager**!

---

# Chapter 17: Project Setup and Architecture

## Introduction

You've learned C fundamentals, advanced concepts, and Windows programming basics. Now it's time to apply all that knowledge to build WinRDP - a complete, professional Windows application.

In this chapter, you'll:
- Understand WinRDP's architecture and design decisions
- Set up the project structure
- Create header files for configuration
- Learn how modules work together
- Build your first version (a skeleton that compiles)

**By the end of this chapter**, you'll have a compiling project ready to add features to!

## Understanding WinRDP's Architecture

### What Does WinRDP Do?

WinRDP is a **Remote Desktop Connection Manager** that:
1. Stores a list of RDP servers (hostnames and descriptions)
2. Saves credentials securely using Windows Credential Manager
3. Lives in the system tray for quick access
4. Launches RDP connections with one click
5. Supports features like dark mode, hotkeys, and network scanning

### The Modular Design

WinRDP is organized into **8 modules**, each with a specific responsibility:

```
WinRDP Architecture
│
├── main.c              - Application entry point, main window, dialogs
├── config.h            - Configuration constants and macros
├── utils.c             - Helper functions (CenterWindow, ShowError, etc.)
├── hosts.c             - Host list management (Load, Save, Add, Remove)
├── credentials.c       - Secure password storage (Windows Credential Manager)
├── rdp.c               - RDP connection logic (create .rdp files, launch)
├── registry.c          - Windows Registry operations (autostart feature)
├── adscan.c            - Network computer discovery
└── darkmode.c          - Dark mode theme support
```

**Why modular?**
- **Easier to understand**: Each file has a clear purpose
- **Easier to test**: Test one module at a time
- **Easier to extend**: Add features without breaking existing code
- **Professional**: Real applications are organized this way

### Module Interaction Diagram

Here's how all WinRDP modules interact with each other:

```
┌──────────────────────────────────────────────────────────────────────────┐
│                      WINRDP MODULE ARCHITECTURE                           │
└──────────────────────────────────────────────────────────────────────────┘

                           ┌──────────────────┐
                           │    main.c        │  ◄─── Entry Point & UI
                           │  ┌────────────┐  │      • WinMain()
                           │  │  WndProc   │  │      • Dialogs
                           │  │  Dialogs   │  │      • Message Loop
                           │  │  UI Logic  │  │      • Event Handling
                           │  └────────────┘  │
                           └────────┬─────────┘
                                    │
                    ┌───────────────┼───────────────┐
                    │               │               │
                    ▼               ▼               ▼
        ┌──────────────────┐   ┌──────────────┐   ┌──────────────────┐
        │   hosts.c        │   │credentials.c │   │    rdp.c         │
        │                  │   │              │   │                  │
        │ • LoadHosts()    │   │• LoadCreds() │   │• CreateRDPFile() │
        │ • SaveHosts()    │   │• SaveCreds() │   │• LaunchRDP()     │
        │ • AddHost()      │   │• DeleteCreds()│   │                  │
        │ • DeleteHost()   │   │              │   │                  │
        │                  │   │              │   │                  │
        │ [CSV Storage]    │   │ [Credential  │   │ [RDP Launcher]   │
        │ hosts.csv        │   │  Manager]    │   │ mstsc.exe        │
        └──────┬───────────┘   └──────┬───────┘   └─────────┬────────┘
               │                      │                      │
               │                      │                      │
               ▼                      ▼                      ▼
        ┌──────────────┐      ┌──────────────┐      ┌──────────────┐
        │encryption.c  │      │ Windows      │      │ Windows      │
        │              │      │ Credential   │      │ Shell        │
        │• EncryptData │      │ Manager API  │      │ (mstsc.exe)  │
        │• DecryptData │      │              │      │              │
        │              │      │ CredWrite()  │      │ RDP Client   │
        │ [DPAPI]      │      │ CredRead()   │      │              │
        └──────────────┘      └──────────────┘      └──────────────┘

                    ┌───────────────────────────────┐
                    │      SUPPORTING MODULES       │
                    └───────────────────────────────┘
                                    │
                    ┌───────────────┼───────────────┐
                    │               │               │
                    ▼               ▼               ▼
        ┌──────────────────┐   ┌────────────┐   ┌───────────────┐
        │  registry.c      │   │ adscan.c   │   │ darkmode.c    │
        │                  │   │            │   │               │
        │• Autostart       │   │• Network   │   │• Dark Theme   │
        │• Settings        │   │  Discovery │   │• UI Colors    │
        │                  │   │• AD Query  │   │               │
        │ [Registry API]   │   │ [NetAPI]   │   │ [DWM API]     │
        └──────────────────┘   └────────────┘   └───────────────┘

                           ┌──────────────────┐
                           │    utils.c       │
                           │                  │
                           │• CenterWindow()  │
                           │• ShowError()     │
                           │• ShowInfo()      │  ◄─── Called by all
                           │                  │       modules
                           └──────────────────┘

                           ┌──────────────────┐
                           │   config.h       │
                           │                  │
                           │• Constants       │
                           │• #defines        │
                           │• Shared types    │  ◄─── Included by all
                           │                  │
                           └──────────────────┘
```

### Data Flow Example: Connecting to a Server

Let's trace what happens when you double-click a server:

```
┌──────────────────────────────────────────────────────────────────────────┐
│          CONNECTION FLOW: User Double-Clicks Server in List               │
└──────────────────────────────────────────────────────────────────────────┘

USER                    MAIN.C                   MODULES              WINDOWS
────                    ──────                   ───────              ───────

Double-click ────►  WM_NOTIFY
"Server1"           (NM_DBLCLK)
                         │
                         │ Get selected item
                         ▼
                    ListView_GetItem()
                         │
                         │ hostname = "server1.com"
                         ▼
                    ┌──────────────┐
                    │ Try per-host │
                    │ credentials  │────────► LoadRDPCredentials()
                    └──────┬───────┘                │
                           │                        │ Query:
                           │                        │ "WinRDP:TERMSRV/server1.com"
                           │                        ▼
                           │                   Windows Credential
                           │                   Manager
                           │                        │
                           │   ┌────────────────────┤
                           │   │ Found?             │
                           │   │ Yes ──► Return username/password
                           │   │ No  ──► Try global credentials
                           │   │              │
                           ◄───┴──────────────┘
                           │
                           │ Got credentials
                           ▼
                    LaunchRDPWithDefaults()
                           │
                           │────────────────────► CreateRDPFile()
                           │                            │
                           │                            │ Build RDP config:
                           │                            │ • full address:s:server1.com
                           │                            │ • username:s:admin
                           │                            │ • screen mode:i:2
                           │                            │ • etc...
                           │                            ▼
                           │                      Save to:
                           │                      "AppData\WinRDP\server1.rdp"
                           │                            │
                           ◄────────────────────────────┘
                           │
                           │ RDP file path
                           ▼
                    SaveRDPCredentials() ─────────► Windows Credential
                    (for RDP session)               Manager
                           │                             │
                           │                             │ Store:
                           │                             │ "TERMSRV/server1.com"
                           │                             │ username + password
                           │                             │
                           ◄─────────────────────────────┘
                           │
                           ▼
                    ShellExecuteW(
                      "mstsc.exe",
                      "server1.rdp"
                    ) ──────────────────────────────────► Launch
                           │                              mstsc.exe
                           │                                  │
                           │                                  │ Read RDP file
                           │                                  │ Load credentials
                           │                                  │ from Cred Mgr
                           │                                  │
                           │                                  ▼
                           │                             Connect to
                           │                             server1.com
                           │                                  │
                           ▼                                  ▼
                    UpdateLastConnected() ──────►      [Connected!]
                    (Update timestamp)                 RDP Session
                           │                           Active
                           ▼
                    Return to message loop
                    (Dialog remains open)

TIMING: This entire flow completes in ~100-200 milliseconds! ⚡
```

Each module has a specific job, and they work together seamlessly.

## Project Structure

### Directory Layout

```
WinRDP/
│
├── src/                      - Source code directory
│   ├── main.c                - Application entry point
│   ├── config.h              - Configuration and constants
│   ├── utils.c               - Utility functions
│   ├── hosts.c               - Host management
│   ├── hosts.h               - Host module interface
│   ├── credentials.c         - Credential storage
│   ├── credentials.h         - Credentials module interface
│   ├── rdp.c                 - RDP connection logic
│   ├── rdp.h                 - RDP module interface
│   ├── registry.c            - Registry operations
│   ├── registry.h            - Registry module interface
│   ├── adscan.c              - Network scanning
│   ├── adscan.h              - AD scan module interface
│   ├── darkmode.c            - Dark mode support
│   ├── darkmode.h            - Dark mode module interface
│   ├── resource.h            - Resource IDs (dialogs, icons, menus)
│   ├── resources.rc          - Resource definitions
│   ├── app.manifest          - Application manifest (DPI awareness)
│   └── app.ico               - Application icon
│
├── build.bat                 - Build script
├── installer.nsi             - NSIS installer script
└── README.md                 - Project documentation
```

### Header Files (.h) vs Implementation Files (.c)

**Header files** (.h) declare:
- Function prototypes
- Structure definitions
- Constants that other modules need

**Implementation files** (.c) contain:
- Actual function implementations
- Internal (static) helper functions
- The logic that does the work

**Example:**

```c
// hosts.h - Interface (what other modules can use)
#ifndef HOSTS_H
#define HOSTS_H

#include <windows.h>

typedef struct {
    wchar_t hostname[256];
    wchar_t description[256];
} Host;

Host* LoadHosts(int* count);
void SaveHosts(Host* hosts, int count);
void FreeHosts(Host* hosts);

#endif
```

```c
// hosts.c - Implementation (how it actually works)
#include "hosts.h"
#include <stdio.h>
#include <stdlib.h>

// Internal helper function (static = only visible in this file)
static void TrimWhitespace(wchar_t* str)
{
    // Implementation...
}

// Public function (declared in hosts.h)
Host* LoadHosts(int* count)
{
    // Implementation that other modules can call
}
```

**Why separate them?**
- Other modules include the `.h` file to know what functions are available
- The `.c` file can change internally without affecting other modules
- Reduces compilation dependencies (faster builds)

## Creating config.h: Application Configuration

`config.h` is the first file we'll create. It contains:
- Application name and version
- Window dimensions and styles
- Resource IDs
- System tray configuration
- File paths

### config.h Implementation (Updated for v1.2.0)

Create `src/config.h`:

```c
#ifndef CONFIG_H
#define CONFIG_H

#include <windows.h>

// Application metadata
#define APP_NAME                L"WinRDP"
#define APP_VERSION             L"1.4.0"
#define APP_CLASS_NAME          L"WinRDPWindowClass"
#define APP_WINDOW_TITLE        L"WinRDP Manager"

// Credential storage targets (Windows Credential Manager)
#define CRED_TARGET_NAME        L"WinRDP:DefaultCredentials"
#define CRED_TARGET_PREFIX      L"WinRDP:TERMSRV/"

// File locations
#define HOSTS_FILE_NAME         L"hosts.csv"

// Registry autostart settings
#define REG_RUN_KEY             L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define REG_APP_NAME            L"WinRDP"

// Buffer sizes used throughout the app
#define MAX_HOSTNAME_LEN        256
#define MAX_DESCRIPTION_LEN     512
#define MAX_USERNAME_LEN        256
#define MAX_PASSWORD_LEN        256

// Utility helpers shared across modules
void CenterWindow(HWND hwnd);
void ShowErrorMessage(HWND hwnd, const wchar_t* message);
void ShowInfoMessage(HWND hwnd, const wchar_t* message);

#endif // CONFIG_H
```

### Understanding config.h

Let's break down the key sections and why they matter in the current codebase:

**1. Application metadata**
```c
#define APP_NAME        L"WinRDP"
#define APP_VERSION     L"1.2.0"
```
- Used to brand window captions, dialog titles, and the About box
- Version number now tracks the shipping build (v1.2.0 introduces persistent RDP files and UI polish)

**2. Credential targets**
```c
#define CRED_TARGET_NAME   L"WinRDP:DefaultCredentials"
#define CRED_TARGET_PREFIX L"WinRDP:TERMSRV/"
```
- `CRED_TARGET_NAME` identifies the **global credentials** that auto-fill connections
- `CRED_TARGET_PREFIX` enables per-host credentials like `WinRDP:TERMSRV/server01`
- These constants are shared by `credentials.c` and `rdp.c` to keep naming consistent when saving to Windows Credential Manager

**3. File locations and registry data**
```c
#define HOSTS_FILE_NAME  L"hosts.csv"
#define REG_RUN_KEY      L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
```
- `HOSTS_FILE_NAME` is combined with the executable path at runtime, ensuring autostart sessions open the correct CSV
- `REG_RUN_KEY` / `REG_APP_NAME` allow Chapter 25's autostart feature to register the app with Windows safely

**4. Buffer sizing**
```c
#define MAX_HOSTNAME_LEN 256
#define MAX_DESCRIPTION_LEN 512
```
- These limits align with UI expectations (text boxes sized to 256 or 512 characters)
- Ensures every module allocates consistent buffers before reading CSV data or credentials

**5. Shared helpers**
```c
void ShowErrorMessage(HWND hwnd, const wchar_t* message);
```
- Declared here so any module can show consistent, branded dialogs without re-declaring the functions

**Why centralize these constants?**
- Adjusting branding or versioning for a release becomes a single-file change
- Prevents magic strings scattered across modules (e.g., `"WinRDP:TERMSRV/"`)
- Keeps new features—like the persistent credential and RDP storage introduced in v1.2.0—easy to document and maintain

## Resource Files: The GUI Definition

Windows applications use **resource files** (.rc) to define:
- Dialogs and their controls
- Menus
- Icons and bitmaps
- Version information
- Strings

### resource.h: Resource IDs (Updated for v1.2.0 UI)

Create `src/resource.h`:

```c
#ifndef RESOURCE_H
#define RESOURCE_H

// Dialog identifiers
#define IDD_LOGIN               100
#define IDD_MAIN                101
#define IDD_HOSTS               102
#define IDD_ADD_HOST            103
#define IDD_SCAN_RESULTS        104
#define IDD_SCAN_DOMAIN         105
#define IDD_ABOUT               106

// Login dialog controls
#define IDC_EDIT_USERNAME       200
#define IDC_EDIT_PASSWORD       201
#define IDC_BTN_SAVE_CREDS      202
#define IDC_BTN_DELETE_CREDS    203
#define IDC_STATIC_STATUS       204

// Main dialog controls
#define IDC_LIST_SERVERS        210
#define IDC_EDIT_SEARCH         211
#define IDC_BTN_CONNECT         212
#define IDC_BTN_MANAGE          213
#define IDC_BTN_EDIT_CREDS      214
#define IDC_STATIC_HOST_COUNT   215

// Host management dialog
#define IDC_LIST_HOSTS          220
#define IDC_BTN_ADD_HOST        221
#define IDC_BTN_EDIT_HOST       222
#define IDC_BTN_DELETE_HOST     223
#define IDC_BTN_SCAN_DOMAIN     224
#define IDC_EDIT_SEARCH_HOSTS   225
#define IDC_STATIC_HOSTS_COUNT  226

// Add/Edit host dialog
#define IDC_EDIT_HOSTNAME       230
#define IDC_EDIT_DESCRIPTION    231
#define IDC_CHECK_USE_HOST_CREDS 232
#define IDC_EDIT_HOST_USERNAME  233
#define IDC_EDIT_HOST_PASSWORD  234
#define IDC_STATIC_HOST_USERNAME 235
#define IDC_STATIC_HOST_PASSWORD 236

// Scan results dialog
#define IDC_LIST_SCAN_RESULTS   240
#define IDC_BTN_ADD_SELECTED    241
#define IDC_STATIC_SCAN_STATUS  242

// Scan domain dialog
#define IDC_EDIT_DOMAIN         250
#define IDC_CHECK_WORKSTATIONS  254
#define IDC_CHECK_SERVERS       255
#define IDC_CHECK_DOMAIN_CTRL   256

// Menu and hotkey identifiers
#define IDM_OPEN                300
#define IDM_EXIT                301
#define IDM_ABOUT               302     // Autostart toggle reuses this ID
#define IDM_DELETE_ALL          303
#define IDM_GLOBAL_HOTKEY       304
#define IDM_ABOUT_DIALOG        305

// Dynamic recent-connection menu range (Tray → Recent Servers)
#define IDM_RECENT_START        310
#define IDM_RECENT_END          319

// System tray plumbing
#define ID_TRAYICON             400
#define WM_TRAYICON             (WM_USER + 1)

// Icon resource
#define IDI_MAINICON            500

// Accelerator tables
#define IDM_HOSTS_ACCEL         600

#endif // RESOURCE_H
```

### resources.rc: Dialog & Menu Layouts (Keyboard-First UX)

Create `src/resources.rc`:

```rc
/*
 * WinRDP Resources
 * - UTF-8 encoded via #pragma for clean non-ANSI text
 * - Consistent 13px single-line edit controls per UX polish in v1.2.0
 * - Uniform 100px buttons for visual balance
 */

#pragma code_page(65001)

#include <windows.h>
#include "resource.h"

IDI_MAINICON ICON "app.ico"
1 RT_MANIFEST "app.manifest"

// Login Dialog — countdown suppressed when editing credentials mid-session
IDD_LOGIN DIALOGEX 0, 0, 320, 145
STYLE DS_MODALFRAME | DS_CENTER | DS_SHELLFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Enter Credentials"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Username:",              IDC_STATIC,            15, 18, 60, 10
    EDITTEXT        IDC_EDIT_USERNAME,        85, 15, 220, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    LTEXT           "Password:",              IDC_STATIC,            15, 45, 60, 10
    EDITTEXT        IDC_EDIT_PASSWORD,        85, 42, 220, 13, ES_PASSWORD | ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    LTEXT           "",                       IDC_STATIC_STATUS,     15, 72, 200, 10
    PUSHBUTTON      "Delete Saved",          IDC_BTN_DELETE_CREDS, 220, 69, 85, 18, WS_TABSTOP

    CONTROL         "",                      IDC_STATIC,             "Static", SS_ETCHEDHORZ, 15, 103, 290, 1

    DEFPUSHBUTTON   "Save && Continue",      IDOK,                  135, 115, 85, 22, WS_TABSTOP
    PUSHBUTTON      "Cancel",                IDCANCEL,              225, 115, 80, 22, WS_TABSTOP
END

// Main Dialog — search + host count + Edit Credentials button (new in v1.2.0)
IDD_MAIN DIALOGEX 0, 0, 500, 380
STYLE DS_MODALFRAME | DS_CENTER | DS_SHELLFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Connect to Server"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Search:",                IDC_STATIC,            15, 15, 40, 10
    EDITTEXT        IDC_EDIT_SEARCH,          60, 12, 420, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    CONTROL         "",                      IDC_LIST_SERVERS,      "SysListView32",
                    LVS_REPORT | LVS_SINGLESEL | WS_BORDER | WS_TABSTOP,
                    15, 42, 470, 286

    LTEXT           "",                       IDC_STATIC_HOST_COUNT, 15, 333, 470, 10

    DEFPUSHBUTTON   "Connect",               IDC_BTN_CONNECT,      15, 353, 100, 20, WS_TABSTOP
    PUSHBUTTON      "Manage Hosts",          IDC_BTN_MANAGE,      120, 353, 100, 20, WS_TABSTOP
    PUSHBUTTON      "Edit Credentials",      IDC_BTN_EDIT_CREDS,  225, 353, 100, 20, WS_TABSTOP
    PUSHBUTTON      "Close",                 IDCANCEL,            330, 353, 100, 20, WS_TABSTOP
END

// Host Management Dialog — mirrors main dialog layout with filtering + counts
IDD_HOSTS DIALOGEX 0, 0, 550, 430
STYLE DS_MODALFRAME | DS_CENTER | DS_SHELLFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Manage Hosts"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Search:",                IDC_STATIC,            15, 15, 30, 10
    EDITTEXT        IDC_EDIT_SEARCH_HOSTS,    50, 12, 485, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    CONTROL         "",                      IDC_LIST_HOSTS,        "SysListView32",
                    LVS_REPORT | LVS_SINGLESEL | WS_BORDER | WS_TABSTOP,
                    15, 35, 520, 335

    LTEXT           "",                       IDC_STATIC_HOSTS_COUNT, 15, 375, 520, 10

    PUSHBUTTON      "Add Host",              IDC_BTN_ADD_HOST,     15, 395, 90, 22, WS_TABSTOP
    PUSHBUTTON      "Edit Host",             IDC_BTN_EDIT_HOST,   110, 395, 90, 22, WS_TABSTOP
    PUSHBUTTON      "Delete Host",           IDC_BTN_DELETE_HOST, 205, 395, 90, 22, WS_TABSTOP
    PUSHBUTTON      "Scan Domain",           IDC_BTN_SCAN_DOMAIN, 300, 395, 95, 22, WS_TABSTOP
    DEFPUSHBUTTON   "Close",                 IDCANCEL,            445, 395, 90, 22, WS_TABSTOP
END

// Add/Edit Host Dialog — supports per-host credential override
IDD_ADD_HOST DIALOGEX 0, 0, 380, 270
STYLE DS_MODALFRAME | DS_CENTER | DS_SHELLFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Add/Edit Host"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Hostname:",             IDC_STATIC,            15, 20, 65, 10
    EDITTEXT        IDC_EDIT_HOSTNAME,        90, 17, 275, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    LTEXT           "Description:",          IDC_STATIC,            15, 50, 65, 10
    EDITTEXT        IDC_EDIT_DESCRIPTION,     90, 47, 275, 45,
                    ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN | WS_VSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    GROUPBOX        "Per-Host Credentials (Optional)", IDC_STATIC, 15, 100, 350, 115
    AUTOCHECKBOX    "Use custom credentials for this host", IDC_CHECK_USE_HOST_CREDS, 25, 115, 250, 12, WS_TABSTOP

    LTEXT           "Username:",             IDC_STATIC_HOST_USERNAME, 25, 135, 60, 10
    EDITTEXT        IDC_EDIT_HOST_USERNAME,   90, 132, 270, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    LTEXT           "Password:",             IDC_STATIC_HOST_PASSWORD, 25, 165, 60, 10
    EDITTEXT        IDC_EDIT_HOST_PASSWORD,   90, 162, 270, 13, ES_PASSWORD | ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE

    LTEXT           "Leave unchecked to use global credentials", IDC_STATIC, 90, 190, 270, 10

    DEFPUSHBUTTON   "Save",                  IDOK,                 205, 225, 80, 20, WS_TABSTOP
    PUSHBUTTON      "Cancel",                IDCANCEL,             290, 225, 75, 20, WS_TABSTOP
END

// Additional dialogs (Scan Domain, About, etc.) follow similar patterns in the repo
```

> **UX polish (v1.2.0)**
> - Uniform 13px single-line edit controls → consistent baseline across dialogs
> - Button widths standardized to 90–100px → balanced visual rhythm
> - New `Edit Credentials` button provides in-session access to the login workflow
> - Status labels (`IDC_STATIC_HOST_COUNT` / `IDC_STATIC_HOSTS_COUNT`) show filtered counts in real time

### Understanding Resource Files

**DIALOGEX syntax:**
```rc
IDD_LOGIN DIALOGEX 0, 0, 250, 140
        |        |  |   |    |
        |        |  |   |    Height (dialog units)
        |        |  |   Width (dialog units)
        |        |  Y position
        |        X position
        Dialog ID
```

**Control syntax:**
```rc
EDITTEXT IDC_EDIT_USERNAME, 85, 15, 220, 13, ES_AUTOHSCROLL | WS_TABSTOP, WS_EX_CLIENTEDGE
      |         |       |   |    |    |       |       |
      |         |       |   |    |    |       |       Extended styles
      |         |       |   |    |    |       Styles (ES_*, WS_TABSTOP)
      |         |       |   |    |    Height (dialog units)
      |         |       |   |    Width (dialog units)
      |         |       |   Y position
      |         |       X position
      |         Control ID
      Control type
```

**Common control types:**
- `LTEXT` - Static text label
- `EDITTEXT` - Text input box
- `PUSHBUTTON` - Standard button
- `DEFPUSHBUTTON` - Default button (Enter key)
- `CONTROL` - Generic control (ListView, CheckBox, etc.)

**Common styles:**
- `ES_PASSWORD` - Hide text with bullets (•••)
- `ES_AUTOHSCROLL` - Allow horizontal scrolling
- `LVS_REPORT` - ListView in report (details) mode
- `WS_TABSTOP` - Control is part of tab order

## Application Manifest: Modern Windows Features

Windows applications should include a **manifest file** to:
- Enable high DPI awareness (sharp text on high-res displays)
- Declare Windows version compatibility
- Request administrator privileges (if needed)
- Enable visual styles

Create `src/app.manifest`:

```xml
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <assemblyIdentity
    version="1.0.0.0"
    processorArchitecture="*"
    name="WinRDP"
    type="win32"
  />
  
  <description>WinRDP - RDP Connection Manager</description>
  
  <!-- Windows version compatibility -->
  <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
    <application>
      <!-- Windows 10 and 11 -->
      <supportedOS Id="{8e0f7a12-bfb3-4fe8-b9a5-48fd50a15a9a}"/>
      <!-- Windows 8.1 -->
      <supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}"/>
      <!-- Windows 8 -->
      <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}"/>
      <!-- Windows 7 -->
      <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}"/>
    </application>
  </compatibility>
  
  <!-- DPI awareness (for sharp text on high-res displays) -->
  <application xmlns="urn:schemas-microsoft-com:asm.v3">
    <windowsSettings>
      <dpiAware xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">
        true
      </dpiAware>
      <dpiAwareness xmlns="http://schemas.microsoft.com/SMI/2016/WindowsSettings">
        PerMonitorV2
      </dpiAwareness>
    </windowsSettings>
  </application>
  
  <!-- Enable visual styles (modern look and feel) -->
  <dependency>
    <dependentAssembly>
      <assemblyIdentity
        type="win32"
        name="Microsoft.Windows.Common-Controls"
        version="6.0.0.0"
        processorArchitecture="*"
        publicKeyToken="6595b64144ccf1df"
        language="*"
      />
    </dependentAssembly>
  </dependency>
</assembly>
```

**Why include a manifest?**
- Without it, text looks blurry on high-DPI displays
- Controls use old Windows XP style
- Application may have compatibility issues
- Professional applications always include one

## Application Icon: Professional Visual Identity (NEW v1.2.0)

> **💡 What's New in WinRDP v1.2.0**
> 
> - ✨ Professional blue monitor icon with green frame
> - ✨ Multi-resolution ICO file (16x16 to 256x256)
> - ✨ Automated PowerShell script for icon generation
> - ✨ Clear visibility at all sizes

A professional application needs a distinctive, recognizable icon. In version 1.2.0, WinRDP introduced a modern icon design featuring a blue monitor screen with a vibrant green bezel.

### Why Icons Matter

Your application icon appears in:
- **System tray** (16x16 pixels)
- **Taskbar** (32x32 pixels)
- **Alt+Tab switcher** (48x48 pixels)
- **Start Menu** (256x256 pixels on Windows 10/11)
- **Desktop shortcuts** (various sizes)
- **File Explorer** (multiple sizes)

**Poor icon design:**
```
❌ Too detailed (illegible at small sizes)
❌ Low contrast (hard to see on any background)
❌ Wrong format (PNG instead of ICO)
❌ Single resolution (blurry when scaled)
```

**Good icon design (WinRDP):**
```
✅ Simple, recognizable shape (monitor)
✅ High contrast colors (blue screen + green frame)
✅ Multi-resolution ICO file (sharp at all sizes)
✅ Clear at 16x16 (most important size!)
```

### The WinRDP Icon Design

**Color scheme:**
- **Blue screen** (#0078D4) - Windows accent color, represents RDP connection
- **Green bezel** (#00AA00) - Vibrant, stands out in system tray
- **Black stand** (#000000) - Grounded, professional
- **White background** - Transparent in actual icon

**Design rationale:**
- **Monitor shape** → Immediately conveys "remote desktop"
- **Green color** → Eye-catching in crowded system tray
- **Simple geometry** → Scales well to tiny sizes
- **Professional look** → Enterprise-ready appearance

### Multi-Resolution ICO Files

Windows ICO files can contain multiple image sizes in one file:

```
app.ico (Multi-resolution icon)
├── 16x16   - System tray
├── 20x20   - Small taskbar
├── 24x24   - Small taskbar (120 DPI)
├── 32x32   - Taskbar
├── 40x40   - Taskbar (125 DPI)
├── 48x48   - Alt+Tab, Explorer
├── 64x64   - Explorer (large)
├── 96x96   - Explorer (150 DPI)
├── 128x128 - Start Menu
└── 256x256 - Start Menu (high DPI)
```

**Why multiple sizes?**
- Windows picks the best size for each context
- Prevents blurry/pixelated appearance
- Supports high-DPI displays (150%, 200% scaling)
- Each size can be optimized differently

**Wrong approach:**
```
❌ Single 256x256 PNG → Windows scales down → Blurry at 16x16
```

**Correct approach:**
```
✅ Multi-resolution ICO → Windows uses exact size → Always sharp
```

### Creating Icons with PowerShell

WinRDP includes `create_icon.ps1`, an automated PowerShell script that generates the icon programmatically.

**File: create_icon.ps1**

```powershell
# WinRDP Icon Generator
# Creates a professional multi-resolution ICO file
# Blue monitor with green bezel design

Add-Type -AssemblyName System.Drawing

# Icon sizes to generate
$sizes = @(16, 20, 24, 32, 40, 48, 64, 96, 128, 256)

# Color definitions
$blueScreen = [System.Drawing.Color]::FromArgb(0, 120, 212)   # #0078D4
$greenBezel = [System.Drawing.Color]::FromArgb(0, 170, 0)     # #00AA00
$blackStand = [System.Drawing.Color]::Black
$white = [System.Drawing.Color]::White

function Draw-MonitorIcon {
    param($size)
    
    $bitmap = New-Object System.Drawing.Bitmap($size, $size)
    $graphics = [System.Drawing.Graphics]::FromImage($bitmap)
    $graphics.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
    
    # Calculate proportions
    $padding = [Math]::Max(1, $size * 0.1)
    $screenWidth = $size - ($padding * 2)
    $screenHeight = $screenWidth * 0.6
    $bezelThickness = [Math]::Max(1, $size * 0.08)
    
    # Draw green bezel (outer rectangle)
    $bezelBrush = New-Object System.Drawing.SolidBrush($greenBezel)
    $bezelRect = New-Object System.Drawing.Rectangle($padding, $padding, $screenWidth, $screenHeight)
    $graphics.FillRectangle($bezelBrush, $bezelRect)
    
    # Draw blue screen (inner rectangle)
    $screenBrush = New-Object System.Drawing.SolidBrush($blueScreen)
    $screenRect = New-Object System.Drawing.Rectangle(
        $padding + $bezelThickness,
        $padding + $bezelThickness,
        $screenWidth - ($bezelThickness * 2),
        $screenHeight - ($bezelThickness * 2)
    )
    $graphics.FillRectangle($screenBrush, $screenRect)
    
    # Draw monitor stand (black trapezoid)
    $standTop = $padding + $screenHeight
    $standHeight = $size * 0.15
    $standWidth = $screenWidth * 0.3
    $standX = ($size - $standWidth) / 2
    
    $standBrush = New-Object System.Drawing.SolidBrush($blackStand)
    $standRect = New-Object System.Drawing.Rectangle($standX, $standTop, $standWidth, $standHeight)
    $graphics.FillRectangle($standBrush, $standRect)
    
    # Cleanup
    $graphics.Dispose()
    $bezelBrush.Dispose()
    $screenBrush.Dispose()
    $standBrush.Dispose()
    
    return $bitmap
}

# Generate all sizes
Write-Host "Generating WinRDP icon..."
$icons = @()

foreach ($size in $sizes) {
    Write-Host "  Creating ${size}x${size} version..."
    $icons += Draw-MonitorIcon -size $size
}

# Save as multi-resolution ICO
$outputPath = "src\app.ico"
$icons[0].Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Icon)

Write-Host "Icon saved to: $outputPath"
Write-Host "Done!"

# Cleanup
foreach ($icon in $icons) {
    $icon.Dispose()
}
```

**To generate the icon:**
```powershell
# Run in PowerShell
.\create_icon.ps1
```

**Output:**
```
Generating WinRDP icon...
  Creating 16x16 version...
  Creating 20x20 version...
  Creating 24x24 version...
  ...
  Creating 256x256 version...
Icon saved to: src\app.ico
Done!
```

### Understanding the Icon Script

**1. Assembly loading:**
```powershell
Add-Type -AssemblyName System.Drawing
```
Loads .NET graphics library for drawing shapes.

**2. Size-based calculations:**
```powershell
$padding = [Math]::Max(1, $size * 0.1)        # 10% padding
$screenHeight = $screenWidth * 0.6            # 16:10 aspect ratio
$bezelThickness = [Math]::Max(1, $size * 0.08) # 8% bezel
```
Proportions scale correctly at any size.

**3. Anti-aliasing:**
```powershell
$graphics.SmoothingMode = [System.Drawing.Drawing2D.SmoothingMode]::AntiAlias
```
Smooth edges (no jagged pixels).

**4. Multi-resolution ICO:**
```powershell
$icons[0].Save($outputPath, [System.Drawing.Imaging.ImageFormat]::Icon)
```
Saves all sizes in a single .ico file.

### Using the Icon in Your Application

**1. Add to resources.rc:**
```rc
#include "resource.h"
#include <windows.h>

// Icons
IDI_MAINICON ICON "app.ico"
```

**2. Reference in window class:**
```c
WNDCLASSEXW wc = {0};
wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));
wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON)); // Small icon
```

**3. Set dialog icon:**
```c
// In WM_INITDIALOG:
SendMessage(hDlg, WM_SETICON, ICON_BIG, 
    (LPARAM)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON)));
SendMessage(hDlg, WM_SETICON, ICON_SMALL,
    (LPARAM)LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON)));
```

**4. System tray icon:**
```c
NOTIFYICONDATA nid = {0};
nid.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MAINICON));
Shell_NotifyIcon(NIM_ADD, &nid);
```

### Icon Design Best Practices

**DO:**
- ✅ Test at 16x16 first (hardest size!)
- ✅ Use high-contrast colors
- ✅ Keep design simple and geometric
- ✅ Make it unique and recognizable
- ✅ Include all standard sizes (16-256)

**DON'T:**
- ❌ Use gradients (hard to see at small sizes)
- ❌ Include fine details or text
- ❌ Copy other application icons
- ❌ Use only one resolution
- ❌ Forget transparency (if needed)

### Alternative: Using Existing Icon Files

If you have an icon from a designer:

**1. Convert to ICO format:**
```
Use online tools:
- converticon.com
- icoconvert.com
- favicon.io

Or desktop tools:
- GIMP (free)
- Adobe Photoshop
- Paint.NET
```

**2. Ensure multiple sizes:**
```
Your ICO file should contain:
16x16, 32x32, 48x48, 256x256 (minimum)
```

**3. Verify with icon viewer:**
```
Right-click app.ico → Properties
Check that multiple sizes are present
```

## Creating the Build Script

Create `build.bat` in the project root:

```batch
@echo off
REM ========================================
REM WinRDP Build Script
REM ========================================

echo Building WinRDP...

REM Compiler and options
set CC=gcc
set CFLAGS=-O2 -Wall -Wextra -municode -mwindows
set LIBS=-lcomctl32 -lcomdlg32 -ladvapi32 -lcredui -lnetapi32 -ldwmapi -lshlwapi

REM Resource compiler
set RC=windres

REM Output
set OUTPUT=WinRDP.exe

REM Compile resources
echo Compiling resources...
%RC% src\resources.rc -O coff -o resources.o
if %errorlevel% neq 0 (
    echo Resource compilation failed!
    exit /b %errorlevel%
)

REM Compile and link
echo Compiling and linking...
%CC% %CFLAGS% ^
    src\main.c ^
    src\utils.c ^
    src\hosts.c ^
    src\credentials.c ^
    src\rdp.c ^
    src\registry.c ^
    src\adscan.c ^
    src\darkmode.c ^
    resources.o ^
    %LIBS% ^
    -o %OUTPUT%

if %errorlevel% neq 0 (
    echo Build failed!
    exit /b %errorlevel%
)

REM Clean up
del resources.o

echo.
echo Build successful! Output: %OUTPUT%
echo.
```

### Understanding the Build Script

**Compiler flags:**
- `-O2` - Optimize for speed
- `-Wall -Wextra` - Show all warnings (helps catch bugs)
- `-municode` - Use Unicode (wWinMain instead of WinMain)
- `-mwindows` - Build GUI application (not console)

**Libraries to link:**
- `-lcomctl32` - Common controls (ListView, etc.)
- `-lcomdlg32` - Common dialogs (Open File, Save File)
- `-ladvapi32` - Advanced API (Registry)
- `-lcredui` - Credential Manager
- `-lnetapi32` - Network API (computer scanning)
- `-ldwmapi` - Desktop Window Manager (dark mode)
- `-lshlwapi` - Shell Light-weight API (string functions)

**The `^` character:**
In batch files, `^` continues a command on the next line (like `\` in C).

## Creating a Minimal Skeleton

Now let's create a minimal `main.c` that compiles successfully:

Create `src/main.c`:

```c
#include <windows.h>
#include <commctrl.h>
#include "config.h"
#include "resource.h"

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

INT_PTR CALLBACK LoginDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK MainDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

// ============================================================================
// GLOBAL VARIABLES
// ============================================================================

HINSTANCE g_hInstance = NULL;
HWND g_hMainDialog = NULL;

// ============================================================================
// LOGIN DIALOG PROCEDURE
// ============================================================================

INT_PTR CALLBACK LoginDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            // Center the dialog
            RECT rc;
            GetWindowRect(hDlg, &rc);
            int x = (GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2;
            int y = (GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2;
            SetWindowPos(hDlg, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
            
            // Set default username (you can load from Credential Manager later)
            SetDlgItemTextW(hDlg, IDC_USERNAME, L"");
            
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // TODO: Validate credentials
                    // For now, just accept anything
                    EndDialog(hDlg, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                {
                    EndDialog(hDlg, IDCANCEL);
                    return TRUE;
                }
            }
            break;
        }
    }
    
    return FALSE;
}

// ============================================================================
// MAIN DIALOG PROCEDURE
// ============================================================================

INT_PTR CALLBACK MainDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            g_hMainDialog = hDlg;
            
            // TODO: Initialize ListView
            // TODO: Load hosts
            // TODO: Create system tray icon
            
            MessageBoxW(hDlg, L"Main dialog loaded! We'll add features here.",
                       APP_NAME, MB_OK | MB_ICONINFORMATION);
            
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_CONNECT:
                {
                    MessageBoxW(hDlg, L"Connect button clicked!\nWe'll implement this in Chapter 23.",
                               APP_NAME, MB_OK | MB_ICONINFORMATION);
                    return TRUE;
                }
                
                case IDC_ADD_HOST:
                {
                    MessageBoxW(hDlg, L"Add Host button clicked!\nWe'll implement this in Chapter 19.",
                               APP_NAME, MB_OK | MB_ICONINFORMATION);
                    return TRUE;
                }
            }
            break;
        }
        
        case WM_CLOSE:
        {
            EndDialog(hDlg, 0);
            return TRUE;
        }
    }
    
    return FALSE;
}

// ============================================================================
// WINMAIN - APPLICATION ENTRY POINT
// ============================================================================

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPWSTR lpCmdLine, int nCmdShow)
{
    // Unused parameters
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;
    
    g_hInstance = hInstance;
    
    // Initialize common controls
    INITCOMMONCONTROLSEX icc = {0};
    icc.dwSize = sizeof(icc);
    icc.dwICC = ICC_LISTVIEW_CLASSES | ICC_TREEVIEW_CLASSES | ICC_BAR_CLASSES;
    InitCommonControlsEx(&icc);
    
    // Show login dialog
    INT_PTR loginResult = DialogBoxW(hInstance, MAKEINTRESOURCEW(IDD_LOGIN),
                                     NULL, LoginDialogProc);
    
    if (loginResult != IDOK)
    {
        // User canceled login
        return 0;
    }
    
    // Show main dialog
    DialogBoxW(hInstance, MAKEINTRESOURCEW(IDD_MAIN), NULL, MainDialogProc);
    
    return 0;
}
```

### Understanding the Skeleton

**1. Header includes:**
```c
#include <windows.h>      // Windows API
#include <commctrl.h>     // Common controls (ListView)
#include "config.h"       // Our configuration
#include "resource.h"     // Resource IDs
```

**2. Global variables:**
```c
HINSTANCE g_hInstance = NULL;   // Application instance handle
HWND g_hMainDialog = NULL;      // Main dialog window handle
```
These are global because many Windows functions need them.

**3. wWinMain vs WinMain:**
```c
int WINAPI wWinMain(...)  // Unicode version (preferred)
```
The `w` prefix means wide characters (Unicode). We use `-municode` flag to enable this.

**4. Dialog flow:**
```
wWinMain starts
    ↓
DialogBoxW(IDD_LOGIN) - Show login dialog
    ↓
User clicks OK → loginResult = IDOK
    ↓
DialogBoxW(IDD_MAIN) - Show main dialog
    ↓
User closes main dialog
    ↓
Application exits
```

## Building the Skeleton

### Prerequisites

You need:
- **MinGW-w64** (GCC compiler for Windows)
- **windres** (Resource compiler, comes with MinGW)

### Building

1. Open Command Prompt
2. Navigate to project directory:
   ```
   cd C:\path\to\WinRDP
   ```
3. Run the build script:
   ```
   build.bat
   ```

You should see:
```
Building WinRDP...
Compiling resources...
Compiling and linking...
Build successful! Output: WinRDP.exe
```

### Testing

Run `WinRDP.exe`:

1. **Login dialog appears** - Click OK
2. **Main dialog appears** - Click buttons to see message boxes
3. **Close the dialog** - Application exits

**Congratulations!** You have a compiling Windows application skeleton!

## What's Next?

In the next chapters, we'll add functionality:

- **Chapter 18**: Configuration and Utilities
- **Chapter 19**: CSV File Management (LoadHosts, SaveHosts)
- **Chapter 20**: Credential storage (Windows Credential Manager)
- **Chapter 21**: Main Application Window
- **Chapter 22**: ListView Control for Host Display
- **Chapter 23**: RDP connection logic
- **Chapter 24**: System Tray Integration

Each chapter adds working features to this skeleton!

## Exercise 17.1: Customize the Application

Modify `config.h` to customize WinRDP:

1. Change `APP_NAME` to your own name
2. Change `APP_AUTHOR` to your name
3. Change `APP_VERSION` to match your release version
4. Rebuild and verify the changes appear in window titles

**Hint:** You'll see the changes in the dialog captions.

## Exercise 17.2: Add an About Dialog

1. Add a new dialog ID to `resource.h`:
   ```c
   #define IDD_ABOUT  104
   ```

2. Add the dialog to `resources.rc`:
   ```rc
   IDD_ABOUT DIALOGEX 0, 0, 250, 150
   STYLE DS_MODALFRAME | DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
   CAPTION "About WinRDP"
   FONT 9, "Segoe UI"
   BEGIN
       LTEXT "WinRDP v1.0.0", IDC_STATIC, 20, 20, 210, 20
       LTEXT "RDP Connection Manager", IDC_STATIC, 20, 45, 210, 12
       LTEXT "Built with C and Win32 API", IDC_STATIC, 20, 65, 210, 12
       DEFPUSHBUTTON "OK", IDOK, 100, 115, 50, 16
   END
   ```

3. Add an "About" button to the main dialog in `resources.rc`
4. Handle the button click in `MainDialogProc`
5. Show the About dialog using `DialogBoxW`

**Solution:**

In `MainDialogProc`, add:
```c
case IDC_ABOUT:  // Add IDC_ABOUT to resource.h
{
    DialogBoxW(g_hInstance, MAKEINTRESOURCEW(IDD_ABOUT), 
               hDlg, AboutDialogProc);
    return TRUE;
}
```

And implement `AboutDialogProc`:
```c
INT_PTR CALLBACK AboutDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_COMMAND && LOWORD(wParam) == IDOK)
    {
        EndDialog(hDlg, IDOK);
        return TRUE;
    }
    return FALSE;
}
```

## Exercise 17.3: Add Debug Output

Add a function to show debug messages during development:

```c
#ifdef _DEBUG
void DebugLog(const wchar_t* format, ...)
{
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    vswprintf_s(buffer, 1024, format, args);
    va_end(args);
    
    OutputDebugStringW(buffer);
    OutputDebugStringW(L"\n");
}
#else
#define DebugLog(...)  // No-op in release builds
#endif
```

Use it in your code:
```c
DebugLog(L"Login dialog initialized");
DebugLog(L"Username: %s", username);
```

View output with **DebugView** (from Microsoft Sysinternals).

## Common Mistakes

### Mistake 1: Forgetting to Initialize Common Controls

```c
// WRONG - ListView won't work!
int WINAPI wWinMain(...)
{
    DialogBoxW(...);  // ListView will be blank!
}

// CORRECT
int WINAPI wWinMain(...)
{
    INITCOMMONCONTROLSEX icc = {0};
    icc.dwSize = sizeof(icc);
    icc.dwICC = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&icc);
    
    DialogBoxW(...);
}
```

### Mistake 2: Mismatched Resource IDs

```c
// resource.h
#define IDC_USERNAME  1001

// resources.rc
EDITTEXT IDC_USRNAME, 20, 35, 210, 14  // Typo! Wrong ID used

// Result: GetDlgItemText fails silently
```

**Fix:** Use the constants from `resource.h` in both C code and .rc file.

### Mistake 3: Not Handling Dialog Closure

```c
// WRONG - Dialog can't be closed!
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_COMMAND:
            // Handle buttons...
            break;
        // Missing WM_CLOSE handler!
    }
    return FALSE;
}

// CORRECT
case WM_CLOSE:
{
    EndDialog(hDlg, 0);
    return TRUE;
}
```

### Mistake 4: Wrong Dialog Procedure Return Values

```c
// WRONG
INT_PTR CALLBACK DialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
            // Do initialization...
            return FALSE;  // WRONG! Should return TRUE
    }
    return TRUE;  // WRONG! Should return FALSE for unhandled messages
}

// CORRECT
case WM_INITDIALOG:
    // Do initialization...
    return TRUE;  // Processed

// At the end
return FALSE;  // Not processed, let dialog manager handle it
```

## Summary

You've learned:
- ✅ WinRDP's modular architecture (8 modules)
- ✅ How modules work together
- ✅ Project directory structure
- ✅ Header files (.h) vs implementation files (.c)
- ✅ Configuration with `config.h`
- ✅ Resource files (dialogs, menus, icons)
- ✅ Application manifest for modern Windows features
- ✅ Build scripts to compile the project
- ✅ Creating a compiling skeleton application

**You now have:**
- A project structure ready to grow
- Dialogs defined in resources
- A build script that works
- A skeleton application that runs!

**Next chapter:** We'll add utility functions to make development easier!

---

# Chapter 18: Configuration and Utilities

## Introduction

In Chapter 17, you set up the project structure and got a skeleton application running. Now we'll build the **foundation layer** - utility functions that every module will use.

Think of utilities as your toolbox. Instead of writing the same code repeatedly, you create reusable functions once and call them everywhere.

In this chapter, you'll create:
- Window positioning functions (CenterWindow)
- Error message helpers (ShowError, ShowWarning)
- String manipulation utilities
- File path helpers
- Debug logging functions

**By the end of this chapter**, you'll have a solid utility library that makes the rest of development much easier!

## Why Utilities Matter

### Without Utilities:

```c
// Centering a window - 8 lines of code
RECT rc;
GetWindowRect(hwnd, &rc);
int width = rc.right - rc.left;
int height = rc.bottom - rc.top;
int screenWidth = GetSystemMetrics(SM_CXSCREEN);
int screenHeight = GetSystemMetrics(SM_CYSCREEN);
int x = (screenWidth - width) / 2;
int y = (screenHeight - height) / 2;
SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

// You'd have to copy these 8 lines everywhere you want to center a window!
```

### With Utilities:

```c
CenterWindow(hwnd);  // One line!
```

**Benefits:**
- **Less code** - One line instead of 8
- **Less bugs** - Tested once, works everywhere
- **Easier maintenance** - Fix bugs in one place
- **More readable** - `CenterWindow(hwnd)` is self-documenting

## Creating utils.c and utils.h

### utils.h - Interface

Create `src/utils.h`:

```c
#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <stdbool.h>

// ============================================================================
// WINDOW UTILITIES
// ============================================================================

// Center a window on the screen
void CenterWindow(HWND hwnd);

// Center a window relative to its parent
void CenterWindowOnParent(HWND hwnd, HWND hParent);

// ============================================================================
// MESSAGE BOX HELPERS
// ============================================================================

// Show error message
void ShowError(HWND hwnd, const wchar_t* message);

// Show warning message
void ShowWarning(HWND hwnd, const wchar_t* message);

// Show information message
void ShowInfo(HWND hwnd, const wchar_t* message);

// Show error with formatted message
void ShowErrorF(HWND hwnd, const wchar_t* format, ...);

// ============================================================================
// STRING UTILITIES
// ============================================================================

// Trim whitespace from both ends of a string
void TrimWhitespace(wchar_t* str);

// Check if string is empty or only whitespace
bool IsEmptyString(const wchar_t* str);

// Safe string copy (prevents buffer overflow)
void SafeStringCopy(wchar_t* dest, size_t destSize, const wchar_t* src);

// Compare strings case-insensitively
bool StringEqualsIgnoreCase(const wchar_t* str1, const wchar_t* str2);

// ============================================================================
// FILE PATH UTILITIES
// ============================================================================

// Get path to user's Documents folder
bool GetDocumentsFolder(wchar_t* path, size_t pathSize);

// Get path to TEMP folder
bool GetTempFolder(wchar_t* path, size_t pathSize);

// Combine two path components
void PathCombine(wchar_t* dest, size_t destSize, 
                 const wchar_t* path1, const wchar_t* path2);

// Check if file exists
bool FileExists(const wchar_t* path);

// ============================================================================
// SYSTEM UTILITIES
// ============================================================================

// Get Windows error message from error code
void GetLastErrorMessage(wchar_t* buffer, size_t bufferSize);

// Run executable (like ShellExecute, but simpler)
bool RunExecutable(const wchar_t* exePath, const wchar_t* parameters);

// ============================================================================
// DEBUG UTILITIES
// ============================================================================

#ifdef _DEBUG
// Debug log output (only in debug builds)
void DebugLog(const wchar_t* format, ...);
#else
#define DebugLog(...)  // No-op in release builds
#endif

#endif // UTILS_H
```

### utils.c - Implementation

Create `src/utils.c`:

```c
#include "utils.h"
#include "config.h"
#include <shlobj.h>  // For SHGetFolderPath
#include <shlwapi.h> // For PathCombine
#include <stdio.h>
#include <ctype.h>

// ============================================================================
// WINDOW UTILITIES
// ============================================================================

void CenterWindow(HWND hwnd)
{
    RECT rc;
    GetWindowRect(hwnd, &rc);
    
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;
    
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2;
    
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

void CenterWindowOnParent(HWND hwnd, HWND hParent)
{
    if (hParent == NULL)
    {
        CenterWindow(hwnd);
        return;
    }
    
    RECT rcChild, rcParent;
    GetWindowRect(hwnd, &rcChild);
    GetWindowRect(hParent, &rcParent);
    
    int childWidth = rcChild.right - rcChild.left;
    int childHeight = rcChild.bottom - rcChild.top;
    
    int parentWidth = rcParent.right - rcParent.left;
    int parentHeight = rcParent.bottom - rcParent.top;
    
    int x = rcParent.left + (parentWidth - childWidth) / 2;
    int y = rcParent.top + (parentHeight - childHeight) / 2;
    
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

// ============================================================================
// MESSAGE BOX HELPERS
// ============================================================================

void ShowError(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, APP_NAME, MB_OK | MB_ICONERROR);
}

void ShowWarning(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, APP_NAME, MB_OK | MB_ICONWARNING);
}

void ShowInfo(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, APP_NAME, MB_OK | MB_ICONINFORMATION);
}

void ShowErrorF(HWND hwnd, const wchar_t* format, ...)
{
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    vswprintf_s(buffer, 1024, format, args);
    va_end(args);
    
    ShowError(hwnd, buffer);
}

// ============================================================================
// STRING UTILITIES
// ============================================================================

void TrimWhitespace(wchar_t* str)
{
    if (str == NULL || *str == L'\0')
        return;
    
    // Trim leading whitespace
    wchar_t* start = str;
    while (*start && iswspace(*start))
        start++;
    
    // Trim trailing whitespace
    wchar_t* end = start + wcslen(start) - 1;
    while (end > start && iswspace(*end))
        end--;
    
    // Move trimmed string to beginning
    size_t len = end - start + 1;
    if (start != str)
        memmove(str, start, (len + 1) * sizeof(wchar_t));
    else
        str[len] = L'\0';
}

bool IsEmptyString(const wchar_t* str)
{
    if (str == NULL || *str == L'\0')
        return true;
    
    while (*str)
    {
        if (!iswspace(*str))
            return false;
        str++;
    }
    
    return true;
}

void SafeStringCopy(wchar_t* dest, size_t destSize, const wchar_t* src)
{
    if (dest == NULL || src == NULL || destSize == 0)
        return;
    
    wcsncpy_s(dest, destSize, src, _TRUNCATE);
}

bool StringEqualsIgnoreCase(const wchar_t* str1, const wchar_t* str2)
{
    if (str1 == NULL || str2 == NULL)
        return false;
    
    return _wcsicmp(str1, str2) == 0;
}

// ============================================================================
// FILE PATH UTILITIES
// ============================================================================

bool GetDocumentsFolder(wchar_t* path, size_t pathSize)
{
    HRESULT hr = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 
                                   SHGFP_TYPE_CURRENT, path);
    return SUCCEEDED(hr);
}

bool GetTempFolder(wchar_t* path, size_t pathSize)
{
    DWORD len = GetTempPathW((DWORD)pathSize, path);
    return len > 0 && len < pathSize;
}

void PathCombine(wchar_t* dest, size_t destSize, 
                 const wchar_t* path1, const wchar_t* path2)
{
    if (dest == NULL || path1 == NULL || path2 == NULL || destSize == 0)
        return;
    
    // Use Windows PathCombine function
    wchar_t temp[MAX_PATH];
    PathCombineW(temp, path1, path2);
    SafeStringCopy(dest, destSize, temp);
}

bool FileExists(const wchar_t* path)
{
    DWORD attrib = GetFileAttributesW(path);
    return (attrib != INVALID_FILE_ATTRIBUTES && 
            !(attrib & FILE_ATTRIBUTE_DIRECTORY));
}

// ============================================================================
// SYSTEM UTILITIES
// ============================================================================

void GetLastErrorMessage(wchar_t* buffer, size_t bufferSize)
{
    DWORD error = GetLastError();
    
    FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        buffer,
        (DWORD)bufferSize,
        NULL
    );
    
    // Remove trailing newline
    size_t len = wcslen(buffer);
    if (len > 0 && buffer[len - 1] == L'\n')
        buffer[len - 1] = L'\0';
    if (len > 1 && buffer[len - 2] == L'\r')
        buffer[len - 2] = L'\0';
}

bool RunExecutable(const wchar_t* exePath, const wchar_t* parameters)
{
    SHELLEXECUTEINFOW sei = {0};
    sei.cbSize = sizeof(sei);
    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
    sei.lpVerb = L"open";
    sei.lpFile = exePath;
    sei.lpParameters = parameters;
    sei.nShow = SW_SHOWNORMAL;
    
    return ShellExecuteExW(&sei);
}

// ============================================================================
// DEBUG UTILITIES
// ============================================================================

#ifdef _DEBUG
void DebugLog(const wchar_t* format, ...)
{
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    vswprintf_s(buffer, 1024, format, args);
    va_end(args);
    
    OutputDebugStringW(L"[WinRDP] ");
    OutputDebugStringW(buffer);
    OutputDebugStringW(L"\n");
}
#endif
```

## Understanding Key Utility Functions

### 1. CenterWindow - Window Positioning

```c
void CenterWindow(HWND hwnd)
{
    // Get window dimensions
    RECT rc;
    GetWindowRect(hwnd, &rc);
    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;
    
    // Get screen dimensions
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    
    // Calculate centered position
    int x = (screenWidth - width) / 2;
    int y = (screenHeight - height) / 2;
    
    // Move window
    SetWindowPos(hwnd, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}
```

**How it works:**
1. `GetWindowRect` gets the window's current position and size
2. `GetSystemMetrics(SM_CXSCREEN)` gets screen width
3. Calculate: `x = (screen_width - window_width) / 2`
4. `SetWindowPos` moves the window
   - `SWP_NOSIZE` = don't change size
   - `SWP_NOZORDER` = don't change Z-order (layer)

**Usage:**
```c
// In WM_INITDIALOG
CenterWindow(hDlg);
```

### 2. ShowError - User-Friendly Error Messages

```c
void ShowError(HWND hwnd, const wchar_t* message)
{
    MessageBoxW(hwnd, message, APP_NAME, MB_OK | MB_ICONERROR);
}
```

**Usage:**
```c
if (file == NULL)
{
    ShowError(hwnd, L"Failed to open file!");
    return;
}
```

**With formatted messages:**
```c
void ShowErrorF(HWND hwnd, const wchar_t* format, ...)
{
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    vswprintf_s(buffer, 1024, format, args);
    va_end(args);
    
    ShowError(hwnd, buffer);
}
```

**Usage:**
```c
ShowErrorF(hwnd, L"Failed to load '%s': %d", filename, error);
```

**Variadic functions (`...`):**
- Like `printf`, can accept any number of arguments
- `va_list`, `va_start`, `va_end` macros handle variable arguments
- `vswprintf_s` is like `swprintf_s` but takes `va_list`

### 3. TrimWhitespace - String Cleanup

```c
void TrimWhitespace(wchar_t* str)
{
    // Find first non-whitespace character
    wchar_t* start = str;
    while (*start && iswspace(*start))
        start++;
    
    // Find last non-whitespace character
    wchar_t* end = start + wcslen(start) - 1;
    while (end > start && iswspace(*end))
        end--;
    
    // Calculate trimmed length
    size_t len = end - start + 1;
    
    // Move trimmed string to beginning
    if (start != str)
        memmove(str, start, (len + 1) * sizeof(wchar_t));
    else
        str[len] = L'\0';
}
```

**How it works:**
1. Find first non-space character (trim leading)
2. Find last non-space character (trim trailing)
3. Move trimmed portion to beginning of string
4. Add null terminator

**Usage:**
```c
wchar_t input[256];
GetDlgItemTextW(hDlg, IDC_HOSTNAME, input, 256);
TrimWhitespace(input);  // Remove spaces before/after

if (IsEmptyString(input))
{
    ShowError(hDlg, L"Hostname cannot be empty!");
    return;
}
```

### 4. GetDocumentsFolder - User Data Location

```c
bool GetDocumentsFolder(wchar_t* path, size_t pathSize)
{
    HRESULT hr = SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 
                                   SHGFP_TYPE_CURRENT, path);
    return SUCCEEDED(hr);
}
```

**What is CSIDL_PERSONAL?**
- `CSIDL_PERSONAL` = User's Documents folder
- On Windows: `C:\Users\YourName\Documents`
- Returns localized path (works in any language)

**Usage:**
```c
wchar_t hostsPath[MAX_PATH];
if (GetDocumentsFolder(hostsPath, MAX_PATH))
{
    PathCombine(hostsPath, MAX_PATH, hostsPath, L"winrdp_hosts.csv");
    // hostsPath now contains: C:\Users\YourName\Documents\winrdp_hosts.csv
}
```

**Why not hardcode the path?**
```c
// BAD - Breaks on non-English Windows
wchar_t path[] = L"C:\\Users\\YourName\\Documents\\file.csv";

// GOOD - Works everywhere
GetDocumentsFolder(path, MAX_PATH);
```

### 5. GetLastErrorMessage - Decode Windows Errors

```c
void GetLastErrorMessage(wchar_t* buffer, size_t bufferSize)
{
    DWORD error = GetLastError();
    
    FormatMessageW(
        FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        buffer,
        (DWORD)bufferSize,
        NULL
    );
}
```

**How it works:**
1. `GetLastError()` gets the last Windows API error code
2. `FormatMessageW` converts error code to human-readable message
3. Returns string like "The system cannot find the file specified."

**Usage:**
```c
FILE* file = _wfopen(path, L"r");
if (file == NULL)
{
    wchar_t errorMsg[256];
    GetLastErrorMessage(errorMsg, 256);
    ShowErrorF(hwnd, L"Failed to open file:\n%s", errorMsg);
    return;
}
```

### 6. DebugLog - Development Logging

```c
#ifdef _DEBUG
void DebugLog(const wchar_t* format, ...)
{
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    vswprintf_s(buffer, 1024, format, args);
    va_end(args);
    
    OutputDebugStringW(L"[WinRDP] ");
    OutputDebugStringW(buffer);
    OutputDebugStringW(L"\n");
}
#endif
```

**What is `OutputDebugStringW`?**
- Sends messages to the debugger output
- View with Visual Studio debugger or DebugView tool
- Only included in debug builds (`#ifdef _DEBUG`)

**Usage:**
```c
DebugLog(L"Loading hosts from: %s", hostsPath);
DebugLog(L"Found %d hosts", hostCount);
DebugLog(L"Connecting to %s with user %s", hostname, username);
```

## Integrating Utilities into main.c

Now update `src/main.c` to use the new utilities:

```c
#include <windows.h>
#include <commctrl.h>
#include "config.h"
#include "resource.h"
#include "utils.h"  // Add this!

// ... (rest of includes and forward declarations)

INT_PTR CALLBACK LoginDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            // Use utility function instead of manual centering!
            CenterWindow(hDlg);
            
            SetDlgItemTextW(hDlg, IDC_USERNAME, L"");
            
            DebugLog(L"Login dialog initialized");
            
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    wchar_t username[256];
                    wchar_t password[256];
                    
                    GetDlgItemTextW(hDlg, IDC_USERNAME, username, 256);
                    GetDlgItemTextW(hDlg, IDC_PASSWORD, password, 256);
                    
                    // Use utility functions!
                    TrimWhitespace(username);
                    TrimWhitespace(password);
                    
                    if (IsEmptyString(username))
                    {
                        ShowWarning(hDlg, L"Username cannot be empty!");
                        SetFocus(GetDlgItem(hDlg, IDC_USERNAME));
                        return TRUE;
                    }
                    
                    if (IsEmptyString(password))
                    {
                        ShowWarning(hDlg, L"Password cannot be empty!");
                        SetFocus(GetDlgItem(hDlg, IDC_PASSWORD));
                        return TRUE;
                    }
                    
                    DebugLog(L"Login successful for user: %s", username);
                    
                    EndDialog(hDlg, IDOK);
                    return TRUE;
                }
                
                case IDCANCEL:
                {
                    EndDialog(hDlg, IDCANCEL);
                    return TRUE;
                }
            }
            break;
        }
    }
    
    return FALSE;
}

INT_PTR CALLBACK MainDialogProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_INITDIALOG:
        {
            g_hMainDialog = hDlg;
            
            CenterWindow(hDlg);
            
            ShowInfo(hDlg, L"Main dialog initialized!\nWe'll add features soon.");
            
            DebugLog(L"Main dialog initialized");
            
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_CONNECT:
                {
                    ShowInfo(hDlg, L"Connect feature coming in Chapter 23!");
                    return TRUE;
                }
                
                case IDC_ADD_HOST:
                {
                    ShowInfo(hDlg, L"Add Host feature coming in Chapter 19!");
                    return TRUE;
                }
                
                case IDC_REMOVE_HOST:
                {
                    ShowInfo(hDlg, L"Remove Host feature coming in Chapter 19!");
                    return TRUE;
                }
            }
            break;
        }
        
        case WM_CLOSE:
        {
            EndDialog(hDlg, 0);
            return TRUE;
        }
    }
    
    return FALSE;
}
```

## Building with Utilities

Your `build.bat` should already include `utils.c`:

```batch
%CC% %CFLAGS% ^
    src\main.c ^
    src\utils.c ^
    ...
```

Build and test:
```
build.bat
WinRDP.exe
```

Now dialogs center themselves automatically, error messages are cleaner, and debug logging helps during development!

## Exercise 18.1: Add a Confirmation Dialog

Create a utility function for confirmation dialogs:

```c
// In utils.h
bool ShowConfirmation(HWND hwnd, const wchar_t* message);

// In utils.c
bool ShowConfirmation(HWND hwnd, const wchar_t* message)
{
    int result = MessageBoxW(hwnd, message, APP_NAME, 
                            MB_YESNO | MB_ICONQUESTION);
    return (result == IDYES);
}
```

**Usage:**
```c
if (ShowConfirmation(hDlg, L"Delete this host?"))
{
    // User clicked Yes
    DeleteHost();
}
```

## Exercise 18.2: Get Application Path

Add a function to get the directory where WinRDP.exe is located:

```c
// In utils.h
bool GetApplicationFolder(wchar_t* path, size_t pathSize);

// In utils.c
bool GetApplicationFolder(wchar_t* path, size_t pathSize)
{
    DWORD len = GetModuleFileNameW(NULL, path, (DWORD)pathSize);
    if (len == 0 || len >= pathSize)
        return false;
    
    // Remove filename, keep directory
    wchar_t* lastSlash = wcsrchr(path, L'\\');
    if (lastSlash != NULL)
        *lastSlash = L'\0';
    
    return true;
}
```

**Usage:**
```c
wchar_t appDir[MAX_PATH];
if (GetApplicationFolder(appDir, MAX_PATH))
{
    DebugLog(L"Application directory: %s", appDir);
}
```

## Exercise 18.3: File Size Utility

Add a function to get file size:

```c
// In utils.h
bool GetFileSize(const wchar_t* path, DWORD* sizeOut);

// In utils.c
bool GetFileSize(const wchar_t* path, DWORD* sizeOut)
{
    WIN32_FILE_ATTRIBUTE_DATA fileInfo;
    if (!GetFileAttributesExW(path, GetFileExInfoStandard, &fileInfo))
        return false;
    
    // Assuming file is less than 4GB (DWORD max)
    *sizeOut = fileInfo.nFileSizeLow;
    return true;
}
```

**Usage:**
```c
DWORD size;
if (GetFileSize(L"hosts.csv", &size))
{
    DebugLog(L"hosts.csv size: %lu bytes", size);
}
```

## Common Mistakes

### Mistake 1: Not Checking Return Values

```c
// WRONG - What if GetDocumentsFolder fails?
wchar_t path[MAX_PATH];
GetDocumentsFolder(path, MAX_PATH);
PathCombine(path, MAX_PATH, path, L"file.csv");  // path might be garbage!

// CORRECT
wchar_t path[MAX_PATH];
if (!GetDocumentsFolder(path, MAX_PATH))
{
    ShowError(hwnd, L"Failed to get Documents folder!");
    return;
}
PathCombine(path, MAX_PATH, path, L"file.csv");
```

### Mistake 2: Buffer Overflow in String Functions

```c
// DANGEROUS - wcscpy doesn't check buffer size
wchar_t buffer[10];
wcscpy(buffer, veryLongString);  // BUFFER OVERFLOW!

// SAFE - Use SafeStringCopy or wcsncpy_s
wchar_t buffer[10];
SafeStringCopy(buffer, 10, veryLongString);  // Truncates safely
```

### Mistake 3: Forgetting to Trim User Input

```c
// WRONG - User enters "  server1  " (with spaces)
GetDlgItemTextW(hDlg, IDC_HOSTNAME, hostname, 256);
if (wcscmp(hostname, L"server1") == 0)  // Doesn't match!
{
    // This code never runs because of extra spaces
}

// CORRECT
GetDlgItemTextW(hDlg, IDC_HOSTNAME, hostname, 256);
TrimWhitespace(hostname);  // Now it's "server1"
if (wcscmp(hostname, L"server1") == 0)
{
    // Works!
}
```

### Mistake 4: Using OutputDebugString in Release Builds

```c
// WRONG - Debug code in release builds (slows down application)
OutputDebugStringW(L"Debug message");

// CORRECT - Only in debug builds
#ifdef _DEBUG
OutputDebugStringW(L"Debug message");
#endif

// EVEN BETTER - Use DebugLog utility
DebugLog(L"Debug message");  // Automatically excluded in release builds
```

## Summary

You've learned:
- ✅ Why utilities reduce code duplication and bugs
- ✅ Window positioning (`CenterWindow`, `CenterWindowOnParent`)
- ✅ User-friendly error messages (`ShowError`, `ShowWarning`, `ShowErrorF`)
- ✅ String manipulation (`TrimWhitespace`, `IsEmptyString`, `SafeStringCopy`)
- ✅ File paths (`GetDocumentsFolder`, `PathCombine`, `FileExists`)
- ✅ System utilities (`GetLastErrorMessage`, `RunExecutable`)
- ✅ Debug logging (`DebugLog`, `OutputDebugStringW`)
- ✅ Variadic functions (functions with variable arguments)

**You now have:**
- A complete utility library (`utils.h` and `utils.c`)
- Reusable functions used throughout WinRDP
- Better error handling and user messages
- Debug logging for development

**Next chapter:** We'll implement host management (loading and saving the server list)!


# Chapter 19: CSV File Management

> **📝 What's New in WinRDP v1.2.0**
> 
> This chapter has been updated to reflect new features:
> - ✨ Last connected timestamps tracking
> - ✨ Recent connections feature (GetRecentHosts)
> - ✨ Persistent file path handling (fixes autostart issues)
> - ✨ Enhanced 3-field CSV format
> - ✨ Bulk delete functionality

## Introduction

In this chapter, we'll implement the host management system for WinRDP. We need a way to:

1. **Store a list of RDP servers** (hostname, description, and last connected time)
2. **Load the list** when the application starts
3. **Save changes** when users add or delete servers
4. **Persist data** across application restarts
5. **Track connection history** for recent connections feature

We'll use a **CSV (Comma-Separated Values) file** for storage. CSV is:
- ✅ **Simple** - Easy to read and write
- ✅ **Human-readable** - Users can edit it with Notepad if needed
- ✅ **Universal** - Works with Excel, spreadsheet programs
- ✅ **Lightweight** - No external database needed

This chapter demonstrates:
- **Dynamic memory allocation** with `malloc` and `realloc`
- **Growing arrays** (we don't know how many hosts beforehand)
- **File I/O** with UTF-8 encoding for international characters
- **CSV parsing** with proper quote handling
- **Memory management patterns** you'll use in every C project
- **Persistent file paths** (critical for autostart scenarios)

## What We're Building

We'll create the `hosts.h` and `hosts.c` module that provides:

```c
// The Host structure - represents one RDP server
typedef struct {
    wchar_t hostname[MAX_HOSTNAME_LEN];
    wchar_t description[MAX_DESCRIPTION_LEN];
    wchar_t lastConnected[64];  // NEW: ISO 8601 format timestamp or "Never"
} Host;

// Core functions
BOOL LoadHosts(Host** hosts, int* count);      // Load from CSV
BOOL SaveHosts(const Host* hosts, int count);  // Save to CSV
BOOL AddHost(const wchar_t* hostname, const wchar_t* description);
BOOL DeleteHost(const wchar_t* hostname);
BOOL DeleteAllHosts(void);                     // NEW: Bulk delete all hosts
BOOL UpdateLastConnected(const wchar_t* hostname);  // NEW: Update timestamp
BOOL GetRecentHosts(Host** hosts, int* count, int maxCount);  // NEW: Get recent
void FreeHosts(Host* hosts, int count);        // Free memory
```

### Example CSV File

```csv
hostname,description,lastConnected
server1.company.com,Production Server,2025-11-07 09:30:15
192.168.1.100,Development Machine,2025-11-06 14:20:00
laptop-office,John's Office Laptop,Never
```

**What's new in the CSV format:**
- **Third column**: `lastConnected` - timestamp when the connection was last used
- **ISO 8601 format**: `YYYY-MM-DD HH:MM:SS` for easy sorting and parsing
- **"Never" value**: For hosts that haven't been connected to yet
- **Backward compatible**: Old 2-field format still works (defaults to "Never")

## The Host Structure

First, let's define what data we need for each server:

```c
typedef struct {
    wchar_t hostname[MAX_HOSTNAME_LEN];       // e.g., "server1.company.com"
    wchar_t description[MAX_DESCRIPTION_LEN]; // e.g., "Production Server"
    wchar_t lastConnected[64];                // NEW: "2025-11-07 09:30:15" or "Never"
} Host;
```

**Design decisions:**

1. **Fixed-size arrays** vs. pointers:
   - We use `wchar_t hostname[256]` not `wchar_t* hostname`
   - **Pros**: Simpler memory management, all memory in one block
   - **Cons**: Wastes some space if strings are short
   - **Choice**: Simplicity wins for an educational project

2. **Wide strings** (`wchar_t`):
   - Windows API uses Unicode (UTF-16)
   - Handles international characters (Chinese, Arabic, emoji, etc.)
   - All Windows functions use `W` suffix: `MessageBoxW`, `CreateFileW`

3. **lastConnected field** (NEW):
   - Tracks when each host was last connected to
   - ISO 8601 format for proper sorting (newer timestamps > older)
   - "Never" for hosts never connected
   - Enables "Recent Connections" feature in system tray
   - 64 characters is plenty for the timestamp format

## Memory Management Strategy

This is the **heart of the chapter**. Let's understand the challenge:

### The Problem

```c
// We want to do this:
Host* hosts = LoadHostsFromFile();

// But how big should the array be?
Host hosts[???];  // We don't know how many hosts!
```

We **don't know beforehand** how many hosts are in the file. Could be 5, could be 500.

### The Solution: Dynamic Allocation

```c
// 1. Start with initial capacity
Host* hosts = malloc(10 * sizeof(Host));

// 2. As we read more hosts, grow the array
if (count >= capacity) {
    capacity *= 2;  // Double the size
    hosts = realloc(hosts, capacity * sizeof(Host));
}

// 3. When done, free the memory
free(hosts);
```

This is called a **dynamic array** or **growable array** - fundamental to C programming!

## Loading Hosts: Step by Step

Let's build the `LoadHosts` function piece by piece.

### Step 1: Function Signature

```c
BOOL LoadHosts(Host** hosts, int* count)
```

**Why `Host**` (pointer-to-pointer)?**

The function needs to:
1. Allocate memory for an array
2. Return the pointer to that array to the caller
3. Also return the count of items

```c
// Inside LoadHosts:
*hosts = malloc(...);  // Allocate memory
*count = num_items;    // Set count

// Caller uses it like this:
Host* myHosts = NULL;
int myCount = 0;
LoadHosts(&myHosts, &myCount);
// Now myHosts points to the allocated array
```

This is a **common C pattern** for returning dynamically allocated data.

### Step 2: Persistent File Path Handling (CRITICAL!)

> **⚠️ Critical Bug Fix**
> 
> Early versions of WinRDP used relative paths like `"hosts.csv"`. This **breaks when the app autostarts with Windows** because the working directory is `C:\Windows\System32` instead of the executable's directory!

**The Problem:**

```c
// WRONG - Breaks on autostart!
_wfopen_s(&file, L"hosts.csv", L"rb");
// This looks for C:\Windows\System32\hosts.csv (wrong!)
```

**The Solution: Absolute Paths**

We need to construct an absolute path based on where the executable is located:

```c
static BOOL get_hosts_file_path(wchar_t* path, size_t pathLen)
{
    wchar_t exePath[MAX_PATH];
    
    // Get the full path to the executable
    if (GetModuleFileNameW(NULL, exePath, MAX_PATH) == 0)
    {
        return FALSE;
    }
    
    // Find the last backslash to get the directory
    wchar_t* lastSlash = wcsrchr(exePath, L'\\');
    if (lastSlash == NULL)
    {
        return FALSE;
    }
    
    // Terminate the string at the last backslash
    *(lastSlash + 1) = L'\0';
    
    // Build the full path: executable_directory + hosts.csv
    if (swprintf_s(path, pathLen, L"%s%s", exePath, HOSTS_FILE_NAME) < 0)
    {
        return FALSE;
    }
    
    return TRUE;
}
```

**How it works:**

1. `GetModuleFileNameW(NULL, ...)` - Get full path to current executable
   - Example: `C:\Program Files\WinRDP\winrdp.exe`

2. `wcsrchr(exePath, L'\\')` - Find last backslash
   - Pointer to: `\winrdp.exe`

3. `*(lastSlash + 1) = L'\0'` - Truncate after last backslash
   - Result: `C:\Program Files\WinRDP\`

4. `swprintf_s(...)` - Append filename
   - Final: `C:\Program Files\WinRDP\hosts.csv`

**Why this matters:**
- ✅ Works from any working directory
- ✅ Works when autostarting with Windows
- ✅ Works when launched from shortcuts
- ✅ Works when launched from other programs

### Step 3: Initialize and Open File

```c
BOOL LoadHosts(Host** hosts, int* count)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t hostsFilePath[MAX_PATH];  // NEW: Store full path
    
    // ALWAYS initialize output parameters first!
    *hosts = NULL;
    *count = 0;
    
    // NEW: Get the full path to hosts.csv (critical for autostart)
    if (!get_hosts_file_path(hostsFilePath, MAX_PATH))
    {
        return FALSE;
    }
    
    // Try to open the file with absolute path
    err = _wfopen_s(&file, hostsFilePath, L"rb");
    if (err != 0 || file == NULL)
    {
        // File doesn't exist - that's okay, return empty list
        return TRUE;
    }
    
    // ... continue reading ...
}
```

**Key points:**
- `_wfopen_s` is the **secure version** of `fopen` (Microsoft)
- `L"rb"` means read (`r`) in binary mode (`b`)
- **NEW**: Use `get_hosts_file_path()` to construct absolute path
- If file doesn't exist, we return an empty list (not an error!)

### Step 4: Handle UTF-8 BOM

```c
// Skip UTF-8 BOM (Byte Order Mark) if present
unsigned char bom[3];
fread(bom, 1, 3, file);

// Check for BOM: 0xEF, 0xBB, 0xBF
if (!(bom[0] == 0xEF && bom[1] == 0xBB && bom[2] == 0xBF))
{
    // No BOM, rewind to start
    fseek(file, 0, SEEK_SET);
}
```

**What's a BOM?**
- **Byte Order Mark**: 3-byte sequence at file start indicating UTF-8 encoding
- Many text editors (Notepad) add it automatically
- We need to skip it or first line will be corrupted

### Step 5: Allocate Initial Array

```c
int capacity = 10;  // Start with space for 10 hosts
*hosts = (Host*)malloc(capacity * sizeof(Host));

// CRITICAL: Check if allocation succeeded!
if (*hosts == NULL)
{
    fclose(file);  // Don't leak file handle!
    return FALSE;
}
```

**Memory allocation can fail!** Always check:
- Out of memory
- Requested size too large
- Memory fragmentation

### Step 6: Read and Grow Loop

```c
char line[1024];
BOOL firstLine = TRUE;

while (fgets(line, 1024, file) != NULL)
{
    // Skip header line
    if (firstLine) {
        firstLine = FALSE;
        continue;
    }
    
    // Convert UTF-8 to wide string
    wchar_t wline[1024];
    MultiByteToWideChar(CP_UTF8, 0, line, -1, wline, 1024);
    
    // Skip empty lines
    if (wcslen(trim_whitespace(wline)) == 0)
        continue;
    
    // GROW ARRAY IF NEEDED
    if (*count >= capacity)
    {
        capacity *= 2;  // Double capacity
        
        // SAFE REALLOC PATTERN: Use temporary variable!
        Host* newHosts = (Host*)realloc(*hosts, capacity * sizeof(Host));
        
        if (newHosts == NULL)
        {
            // Realloc failed! Clean up and return error
            FreeHosts(*hosts, *count);
            fclose(file);
            return FALSE;
        }
        
        *hosts = newHosts;  // Success! Update pointer
    }
    
    // Parse CSV line and add to array
    if (parse_csv_line(wline, &(*hosts)[*count]))
    {
        (*count)++;
    }
}

fclose(file);
return TRUE;
```

### The Growing Array Algorithm

Let's visualize what happens:

```
Initial:     [H][H][H][H][H][H][H][H][H][H]  (capacity = 10)
             [0][1][2][3][4][5][6][7][8][9]

After 10:    Full! Need to grow.

Realloc:     [H][H][H][H][H][H][H][H][H][H][H][H][H][H][H][H][H][H][H][H]
             [0][1][2][3][4][5][6][7][8][9][10][11]...[19]
             (capacity = 20)

After 20:    Full again! Realloc to 40.

After 40:    Full again! Realloc to 80.
```

**Why double the size?**
- **Efficient**: For N items, we only resize O(log N) times
- **Not wasteful**: At most 50% wasted space
- **Industry standard**: std::vector in C++ does this

## The Realloc Pattern: Critical Safety!

This is **one of the most important patterns in C**:

```c
// WRONG - DANGEROUS!
hosts = realloc(hosts, newSize);
// If realloc fails, hosts is now NULL and original data is lost!

// CORRECT - SAFE!
Host* newHosts = realloc(hosts, newSize);
if (newHosts == NULL) {
    // Realloc failed, but 'hosts' still points to original data
    free(hosts);  // Clean up original
    return ERROR;
}
hosts = newHosts;  // Success! Update pointer
```

**Why this matters:**
- `realloc(ptr, size)` returns `NULL` on failure
- But it **doesn't free the original** `ptr`
- If you overwrite `ptr` with `NULL`, you **leak memory**!

## Parsing CSV Lines

CSV parsing is trickier than it looks, especially with our new 3-field format!

```c
static BOOL parse_csv_line(wchar_t* line, Host* host)
{
    // Remove newline
    line[wcscspn(line, L"\r\n")] = L'\0';
    
    // Find the first comma
    wchar_t* comma1 = wcschr(line, L',');
    
    if (comma1 == NULL) {
        // No comma - just hostname, no description or lastConnected
        wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, 
                  trim_whitespace(line), _TRUNCATE);
        host->description[0] = L'\0';
        wcscpy_s(host->lastConnected, 64, L"Never");  // NEW: Default value
        return TRUE;
    }
    
    // Split at the first comma
    *comma1 = L'\0';  // Terminate hostname string at comma
    wchar_t* hostname = trim_whitespace(line);
    wchar_t* remainder = comma1 + 1;
    
    // NEW: Find the second comma for lastConnected field
    wchar_t* comma2 = wcschr(remainder, L',');
    wchar_t* description;
    wchar_t* lastConnected;
    
    if (comma2 == NULL) {
        // No second comma - we have hostname,description (old 2-field format)
        // This maintains backward compatibility!
        description = trim_whitespace(remainder);
        lastConnected = L"Never";
    } else {
        // We have hostname,description,lastConnected (new 3-field format)
        *comma2 = L'\0';
        description = trim_whitespace(remainder);
        lastConnected = trim_whitespace(comma2 + 1);
    }
    
    // Remove quotes from hostname if present
    if (hostname[0] == L'"') {
        hostname++;
        size_t len = wcslen(hostname);
        if (len > 0 && hostname[len-1] == L'"')
            hostname[len-1] = L'\0';
    }
    
    // Remove quotes from description if present
    if (description[0] == L'"') {
        description++;
        size_t len = wcslen(description);
        if (len > 0 && description[len-1] == L'"')
            description[len-1] = L'\0';
    }
    
    // Copy to host structure
    wcsncpy_s(host->hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
    wcsncpy_s(host->description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
    wcsncpy_s(host->lastConnected, 64, lastConnected, _TRUNCATE);  // NEW
    
    return TRUE;
}
```

**CSV Complications:**
- Trailing/leading whitespace: `"  server1  , Production Server  "`
- Quotes: `"server,1","Production, Main Server"`
- Empty fields: `server1,,`
- No comma: `server1`
- **NEW**: Three fields: `server1,Description,2025-11-07 09:30:15`
- **NEW**: Backward compatibility with 2-field format: `server1,Description`
- **NEW**: Default to "Never" if lastConnected missing

## Saving Hosts

Saving is simpler than loading (we know the count):

```c
BOOL SaveHosts(const Host* hosts, int count)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t hostsFilePath[MAX_PATH];  // NEW: Use absolute path
    
    // NEW: Get the full path to hosts.csv
    if (!get_hosts_file_path(hostsFilePath, MAX_PATH))
    {
        return FALSE;
    }
    
    // Open file for writing (overwrites existing)
    err = _wfopen_s(&file, hostsFilePath, L"wb");
    if (err != 0 || file == NULL)
        return FALSE;
    
    // Write UTF-8 BOM
    unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
    fwrite(bom, 1, 3, file);
    
    // Write CSV header - NEW: Added lastConnected column
    const char* header = "hostname,description,lastConnected\r\n";
    fwrite(header, 1, strlen(header), file);
    
    // Write each host
    for (int i = 0; i < count; i++)
    {
        // Convert wide strings to UTF-8
        char utf8_hostname[MAX_HOSTNAME_LEN * 3];
        char utf8_description[MAX_DESCRIPTION_LEN * 3];
        char utf8_lastConnected[200];  // NEW: Third field
        
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].hostname, -1, 
                           utf8_hostname, sizeof(utf8_hostname), NULL, NULL);
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].description, -1, 
                           utf8_description, sizeof(utf8_description), NULL, NULL);
        WideCharToMultiByte(CP_UTF8, 0, hosts[i].lastConnected, -1,  // NEW
                           utf8_lastConnected, sizeof(utf8_lastConnected), NULL, NULL);
        
        // Write hostname with quotes if contains comma
        BOOL hostnameNeedsQuotes = (strchr(utf8_hostname, ',') != NULL);
        if (hostnameNeedsQuotes)
        {
            fwrite("\"", 1, 1, file);
            fwrite(utf8_hostname, 1, strlen(utf8_hostname), file);
            fwrite("\"", 1, 1, file);
        }
        else
        {
            fwrite(utf8_hostname, 1, strlen(utf8_hostname), file);
        }
        
        // Write comma
        fwrite(",", 1, 1, file);
        
        // Write description with quotes if contains comma
        BOOL descNeedsQuotes = (strchr(utf8_description, ',') != NULL);
        if (descNeedsQuotes)
        {
            fwrite("\"", 1, 1, file);
            fwrite(utf8_description, 1, strlen(utf8_description), file);
            fwrite("\"", 1, 1, file);
        }
        else
        {
            fwrite(utf8_description, 1, strlen(utf8_description), file);
        }
        
        // Write comma
        fwrite(",", 1, 1, file);
        
        // NEW: Write lastConnected (timestamps don't contain commas, no quoting needed)
        fwrite(utf8_lastConnected, 1, strlen(utf8_lastConnected), file);
        
        // Write newline
        fwrite("\r\n", 1, 2, file);
        
        // Flush after each write
        fflush(file);
    }
    
    fclose(file);
    return TRUE;
}
```

**Key points:**
- **NEW**: Use `get_hosts_file_path()` for absolute path
- `L"wb"` = write binary mode (prevents Windows newline conversion)
- `\r\n` = Windows line endings (CRLF)
- Quote fields that contain commas
- **NEW**: Write third field (lastConnected) - timestamps don't need quoting
- `fflush()` ensures data is written immediately

## Adding a Host

```c
BOOL AddHost(const wchar_t* hostname, const wchar_t* description)
{
    Host* hosts = NULL;
    int count = 0;
    
    // Load existing hosts
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Check if host already exists (update description)
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            // Update existing host
            wcsncpy_s(hosts[i].description, MAX_DESCRIPTION_LEN, 
                     description, _TRUNCATE);
            
            BOOL result = SaveHosts(hosts, count);
            FreeHosts(hosts, count);
            return result;
        }
    }
    
    // Add new host - grow array by one
    Host* newHosts = (Host*)realloc(hosts, (count + 1) * sizeof(Host));
    if (newHosts == NULL)
    {
        FreeHosts(hosts, count);
        return FALSE;
    }
    hosts = newHosts;
    
    // Copy new host data
    wcsncpy_s(hosts[count].hostname, MAX_HOSTNAME_LEN, hostname, _TRUNCATE);
    wcsncpy_s(hosts[count].description, MAX_DESCRIPTION_LEN, description, _TRUNCATE);
    wcscpy_s(hosts[count].lastConnected, 64, L"Never");  // NEW: Initialize to "Never"
    count++;
    
    // Save and cleanup
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
    return result;
}
```

**Pattern: Load-Modify-Save-Free**
1. Load entire list into memory
2. Modify in memory
3. Save back to file
4. Free memory

**NEW**: When adding a host, initialize `lastConnected` to `"Never"` since it hasn't been connected to yet.

This is simple but rewrites the whole file each time. Fine for small lists.

## Deleting a Host

```c
BOOL DeleteHost(const wchar_t* hostname)
{
    Host* hosts = NULL;
    int count = 0;
    
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Find host
    int foundIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1)
    {
        FreeHosts(hosts, count);
        return FALSE;  // Not found
    }
    
    // Shift remaining hosts down
    for (int i = foundIndex; i < count - 1; i++)
    {
        hosts[i] = hosts[i + 1];
    }
    count--;
    
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
    return result;
}
```

**Array deletion**: Shift all elements after deleted item leftward.

```
Before: [A][B][C][D][E]
Delete C (index 2):
Step 1: [A][B][D][D][E]  (copy D to position 2)
Step 2: [A][B][D][E][E]  (copy E to position 3)
After:  [A][B][D][E]     (count = 4)
```

## Updating Last Connected Timestamp (NEW!)

> **🔗 Related Chapters**
> 
> - Chapter 22: How timestamps are displayed in the ListView
> - Chapter 23: How UpdateLastConnected() is called after successful RDP connection
> - Chapter 24: How recent connections appear in tray menu

One of the most useful features in WinRDP v1.2.0 is tracking when you last connected to each server. This enables the "Recent Connections" menu in the system tray.

```c
BOOL UpdateLastConnected(const wchar_t* hostname)
{
    Host* hosts = NULL;
    int count = 0;
    
    // Load all hosts
    if (!LoadHosts(&hosts, &count))
        return FALSE;
    
    // Find the host to update
    int foundIndex = -1;
    for (int i = 0; i < count; i++)
    {
        if (_wcsicmp(hosts[i].hostname, hostname) == 0)
        {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex == -1)
    {
        FreeHosts(hosts, count);
        return FALSE;  // Host not found
    }
    
    // Get current time from Windows
    SYSTEMTIME st;
    GetLocalTime(&st);
    
    // Format as ISO 8601-like: YYYY-MM-DD HH:MM:SS
    swprintf_s(hosts[foundIndex].lastConnected, 64, 
               L"%04d-%02d-%02d %02d:%02d:%02d",
               st.wYear, st.wMonth, st.wDay,
               st.wHour, st.wMinute, st.wSecond);
    
    // Save and cleanup
    BOOL result = SaveHosts(hosts, count);
    FreeHosts(hosts, count);
    return result;
}
```

**Key points:**

1. **SYSTEMTIME structure**: Windows API structure for date/time
   ```c
   typedef struct _SYSTEMTIME {
       WORD wYear;
       WORD wMonth;       // 1-12
       WORD wDayOfWeek;   // 0-6 (Sunday = 0)
       WORD wDay;         // 1-31
       WORD wHour;        // 0-23
       WORD wMinute;      // 0-59
       WORD wSecond;      // 0-59
       WORD wMilliseconds;
   } SYSTEMTIME;
   ```

2. **GetLocalTime()**: Gets current local time (not UTC)
   - Alternative: `GetSystemTime()` for UTC
   - We use local time because users think in local time

3. **ISO 8601 format**: `YYYY-MM-DD HH:MM:SS`
   - **Sortable**: String comparison works! "2025-11-07" > "2025-11-06"
   - **Human-readable**: Easy to understand at a glance
   - **Parseable**: Can convert back to SYSTEMTIME if needed

4. **swprintf_s**: Wide-character version of sprintf_s
   - `%04d` = 4 digits, zero-padded (2025)
   - `%02d` = 2 digits, zero-padded (09, not 9)

**Usage in WinRDP:**

```c
// After successfully launching RDP connection (Chapter 23):
if (ConnectToHost(hostname))
{
    UpdateLastConnected(hostname);  // Record the connection
}
```

## Getting Recent Hosts (NEW!)

The "Recent Connections" feature needs to quickly retrieve the 3-5 most recently connected hosts. Let's implement that:

```c
BOOL GetRecentHosts(Host** hosts, int* count, int maxCount)
{
    Host* allHosts = NULL;
    int allCount = 0;
    
    // Initialize output parameters
    *hosts = NULL;
    *count = 0;
    
    // Load all hosts
    if (!LoadHosts(&allHosts, &allCount))
        return FALSE;
    
    if (allCount == 0)
    {
        // No hosts at all
        return TRUE;
    }
    
    // Filter out hosts that have never been connected to
    Host* connectedHosts = (Host*)malloc(allCount * sizeof(Host));
    if (connectedHosts == NULL)
    {
        FreeHosts(allHosts, allCount);
        return FALSE;
    }
    
    int connectedCount = 0;
    for (int i = 0; i < allCount; i++)
    {
        // Skip hosts that have never been connected to
        if (_wcsicmp(allHosts[i].lastConnected, L"Never") != 0)
        {
            connectedHosts[connectedCount] = allHosts[i];
            connectedCount++;
        }
    }
    
    // Free the original list
    FreeHosts(allHosts, allCount);
    
    if (connectedCount == 0)
    {
        // No connected hosts
        free(connectedHosts);
        return TRUE;
    }
    
    // Sort by lastConnected timestamp (descending - most recent first)
    // Simple bubble sort is fine for small lists (typically < 10 items)
    for (int i = 0; i < connectedCount - 1; i++)
    {
        for (int j = 0; j < connectedCount - i - 1; j++)
        {
            // Compare timestamps (ISO 8601 format sorts correctly!)
            if (wcscmp(connectedHosts[j].lastConnected, 
                       connectedHosts[j + 1].lastConnected) < 0)
            {
                // Swap
                Host temp = connectedHosts[j];
                connectedHosts[j] = connectedHosts[j + 1];
                connectedHosts[j + 1] = temp;
            }
        }
    }
    
    // Return only the requested number of most recent hosts
    int resultCount = (connectedCount < maxCount) ? connectedCount : maxCount;
    
    Host* result = (Host*)malloc(resultCount * sizeof(Host));
    if (result == NULL)
    {
        free(connectedHosts);
        return FALSE;
    }
    
    // Copy the most recent hosts to result array
    for (int i = 0; i < resultCount; i++)
    {
        result[i] = connectedHosts[i];
    }
    
    free(connectedHosts);
    
    // Set output parameters
    *hosts = result;
    *count = resultCount;
    
    return TRUE;
}
```

**Algorithm breakdown:**

1. **Load all hosts** from CSV file

2. **Filter**: Copy only hosts with lastConnected != "Never"
   ```
   All: [Host1: Never, Host2: 2025-11-07 09:30, Host3: Never, Host4: 2025-11-06 14:20]
   Filtered: [Host2: 2025-11-07 09:30, Host4: 2025-11-06 14:20]
   ```

3. **Sort** by timestamp descending (newest first)
   ```
   Before: [Host2: 2025-11-07 09:30, Host4: 2025-11-06 14:20]
   After:  [Host2: 2025-11-07 09:30, Host4: 2025-11-06 14:20]  (already sorted!)
   ```

4. **Take top N** (usually 3-5 for system tray menu)
   ```
   If maxCount = 3, return first 3 items
   ```

**Why bubble sort?**
- Simple to understand
- Fine for small lists (<100 items)
- Stable sort (preserves order of equal items)
- For large lists, use qsort() instead

**ISO 8601 sorting magic:**
```c
wcscmp(L"2025-11-07 09:30:15", L"2025-11-06 14:20:00") > 0
// "2025-11-07" > "2025-11-06" (string comparison works!)
```

**Usage example:**

```c
// In system tray menu update (Chapter 24):
Host* recentHosts = NULL;
int recentCount = 0;

if (GetRecentHosts(&recentHosts, &recentCount, 5))
{
    // Show top 5 in tray menu
    for (int i = 0; i < recentCount; i++)
    {
        wchar_t menuText[256];
        swprintf_s(menuText, 256, L"%s - %s", 
                   recentHosts[i].hostname,
                   recentHosts[i].description);
        // Add to menu...
    }
    
    FreeHosts(recentHosts, recentCount);
}
```

## Deleting All Hosts (NEW!)

Sometimes users want to start fresh. We provide a bulk delete function:

```c
BOOL DeleteAllHosts(void)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t hostsFilePath[MAX_PATH];
    
    // Get the full path to hosts.csv
    if (!get_hosts_file_path(hostsFilePath, MAX_PATH))
    {
        return FALSE;
    }
    
    // Open file for writing (overwrites existing)
    err = _wfopen_s(&file, hostsFilePath, L"wb");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write UTF-8 BOM
    unsigned char bom[3] = {0xEF, 0xBB, 0xBF};
    fwrite(bom, 1, 3, file);
    
    // Write CSV header only (no hosts!)
    const char* header = "hostname,description,lastConnected\r\n";
    fwrite(header, 1, strlen(header), file);
    
    fclose(file);
    return TRUE;
}
```

**Why not just delete the file?**
- Better to keep the file with header
- Consistent with LoadHosts() expecting header line
- Next save operation doesn't need to create file from scratch

**Security note:**
In WinRDP, this function is activated by a **secret hotkey** (Ctrl+Shift+Delete+Delete) to prevent accidental data loss. We'll cover that in Chapter 26 (Global Hotkeys).

## Freeing Memory

```c
void FreeHosts(Host* hosts, int count)
{
    UNREFERENCED_PARAMETER(count);  // Don't need count for our simple case
    
    if (hosts != NULL)
    {
        free(hosts);
        // NOTE: We can't set hosts = NULL here because it's a local copy
        // Caller should set their pointer to NULL
    }
}
```

**Memory management rule:**
> Every `malloc` must have exactly one `free`.

**Alternative design** (better but more complex):

```c
void FreeHosts(Host** hosts, int count)
{
    if (*hosts != NULL)
    {
        free(*hosts);
        *hosts = NULL;  // Clear caller's pointer
    }
}

// Usage:
FreeHosts(&hosts, count);  // Caller's 'hosts' is set to NULL
```

## Complete hosts.h Header

```c
#ifndef HOSTS_H
#define HOSTS_H

#include <windows.h>
#include "config.h"

// Host structure - represents an RDP server
typedef struct {
    wchar_t hostname[MAX_HOSTNAME_LEN];
    wchar_t description[MAX_DESCRIPTION_LEN];
    wchar_t lastConnected[64];  // NEW: ISO 8601 format or "Never"
} Host;

// Host management functions
BOOL LoadHosts(Host** hosts, int* count);
BOOL SaveHosts(const Host* hosts, int count);
BOOL AddHost(const wchar_t* hostname, const wchar_t* description);
BOOL DeleteHost(const wchar_t* hostname);
BOOL DeleteAllHosts(void);                                          // NEW
BOOL UpdateLastConnected(const wchar_t* hostname);                   // NEW
BOOL GetRecentHosts(Host** hosts, int* count, int maxCount);         // NEW
void FreeHosts(Host* hosts, int count);

#endif // HOSTS_H
```

## Testing the Module

Let's write a simple test program:

```c
#include <stdio.h>
#include <windows.h>
#include "hosts.h"

int main(void)
{
    // Test 1: Add some hosts
    printf("Adding hosts...\n");
    AddHost(L"server1.company.com", L"Production Server");
    AddHost(L"192.168.1.100", L"Development Machine");
    AddHost(L"laptop-office", L"John's Laptop");
    
    // Test 2: Load and display
    Host* hosts = NULL;
    int count = 0;
    
    if (LoadHosts(&hosts, &count))
    {
        printf("Loaded %d hosts:\n", count);
        for (int i = 0; i < count; i++)
        {
            wprintf(L"  %d. %s - %s\n", i+1, 
                   hosts[i].hostname, 
                   hosts[i].description);
        }
        
        // Test 3: Update existing host
        printf("\nUpdating server1...\n");
        AddHost(L"server1.company.com", L"Updated Description");
        
        // Test 4: Delete a host
        printf("Deleting laptop-office...\n");
        DeleteHost(L"laptop-office");
        
        // Reload and display
        FreeHosts(hosts, count);
        if (LoadHosts(&hosts, &count))
        {
            printf("\nAfter modifications:\n");
            for (int i = 0; i < count; i++)
            {
                wprintf(L"  %d. %s - %s\n", i+1, 
                       hosts[i].hostname, 
                       hosts[i].description);
            }
        }
        
        FreeHosts(hosts, count);
    }
    
    return 0;
}
```

**Expected output:**
```
Adding hosts...
Loaded 3 hosts:
  1. server1.company.com - Production Server
  2. 192.168.1.100 - Development Machine
  3. laptop-office - John's Laptop

Updating server1...
Deleting laptop-office...

After modifications:
  1. server1.company.com - Updated Description
  2. 192.168.1.100 - Development Machine
```

## Memory Management Patterns Summary

Let's review the key patterns you learned:

### Pattern 1: Allocate-Check-Use-Free

```c
// 1. Allocate
Host* hosts = malloc(10 * sizeof(Host));

// 2. Check
if (hosts == NULL) {
    return ERROR;
}

// 3. Use
hosts[0] = ...;
hosts[1] = ...;

// 4. Free
free(hosts);
```

### Pattern 2: Safe Realloc

```c
// ALWAYS use temporary variable!
Host* temp = realloc(hosts, newSize);
if (temp == NULL) {
    // Original 'hosts' is still valid
    free(hosts);
    return ERROR;
}
hosts = temp;  // Success
```

### Pattern 3: Output Parameter Initialization

```c
BOOL LoadHosts(Host** hosts, int* count)
{
    // ALWAYS initialize output parameters first!
    *hosts = NULL;
    *count = 0;
    
    // ... rest of function ...
}
```

### Pattern 4: Cleanup on Error

```c
BOOL LoadHosts(Host** hosts, int* count)
{
    *hosts = malloc(...);
    FILE* file = fopen(...);
    
    if (error_condition)
    {
        // Clean up all allocated resources!
        if (*hosts) free(*hosts);
        if (file) fclose(file);
        return FALSE;
    }
    
    // ... success path ...
}
```

## Common Mistakes

### Mistake 1: Forgetting to Free Memory

```c
// WRONG - Memory leak!
void ProcessHosts(void)
{
    Host* hosts = NULL;
    int count = 0;
    
    LoadHosts(&hosts, &count);
    
    // Do something with hosts...
    
    // Oops! Forgot to FreeHosts()!
    // Memory is leaked!
}

// CORRECT
void ProcessHosts(void)
{
    Host* hosts = NULL;
    int count = 0;
    
    LoadHosts(&hosts, &count);
    
    // Do something with hosts...
    
    FreeHosts(hosts, count);  // Always free!
}
```

### Mistake 2: Using Freed Memory

```c
// WRONG - Use after free!
FreeHosts(hosts, count);
printf("Host 0: %s\n", hosts[0].hostname);  // CRASH!

// CORRECT
printf("Host 0: %s\n", hosts[0].hostname);
FreeHosts(hosts, count);
hosts = NULL;  // Good practice: clear pointer after freeing
```

### Mistake 3: Double Free

```c
// WRONG - Double free causes crash!
FreeHosts(hosts, count);
FreeHosts(hosts, count);  // CRASH! Already freed!

// CORRECT
FreeHosts(hosts, count);
hosts = NULL;  // Now calling FreeHosts(NULL, count) is safe
```

### Mistake 4: Not Checking Malloc/Realloc

```c
// WRONG - No error checking!
hosts = malloc(count * sizeof(Host));
hosts[0] = ...;  // If malloc failed, this crashes!

// CORRECT
hosts = malloc(count * sizeof(Host));
if (hosts == NULL) {
    // Handle error
    return FALSE;
}
hosts[0] = ...;
```

### Mistake 5: Pointer Confusion

```c
// WRONG - Doesn't modify caller's pointer!
void LoadData(Host* hosts)
{
    hosts = malloc(...);  // Only modifies local copy!
}

Host* myHosts = NULL;
LoadData(myHosts);
// myHosts is still NULL!

// CORRECT - Use pointer-to-pointer
void LoadData(Host** hosts)
{
    *hosts = malloc(...);  // Modifies caller's pointer!
}

Host* myHosts = NULL;
LoadData(&myHosts);
// myHosts now points to allocated memory!
```

## Exercises

### Exercise 1: Add Validation

Modify `AddHost` to validate inputs:
- Hostname cannot be empty
- Hostname cannot contain spaces
- Description is optional but limited to 256 characters

```c
BOOL AddHost(const wchar_t* hostname, const wchar_t* description)
{
    // Validate hostname
    if (hostname == NULL || wcslen(hostname) == 0)
    {
        MessageBoxW(NULL, L"Hostname cannot be empty", L"Error", MB_OK);
        return FALSE;
    }
    
    if (wcschr(hostname, L' ') != NULL)
    {
        MessageBoxW(NULL, L"Hostname cannot contain spaces", L"Error", MB_OK);
        return FALSE;
    }
    
    // TODO: Rest of AddHost implementation
}
```

### Exercise 2: Count Hosts

Write a function to count hosts without loading them all:

```c
int CountHosts(void)
{
    Host* hosts = NULL;
    int count = 0;
    
    if (LoadHosts(&hosts, &count))
    {
        FreeHosts(hosts, count);
        return count;
    }
    
    return 0;
}
```

Can you make this more efficient? (Hint: Read file line by line without allocating)

### Exercise 3: Find Host

Write a function to check if a host exists:

```c
BOOL HostExists(const wchar_t* hostname)
{
    Host* hosts = NULL;
    int count = 0;
    BOOL found = FALSE;
    
    if (LoadHosts(&hosts, &count))
    {
        for (int i = 0; i < count; i++)
        {
            if (_wcsicmp(hosts[i].hostname, hostname) == 0)
            {
                found = TRUE;
                break;
            }
        }
        FreeHosts(hosts, count);
    }
    
    return found;
}
```

### Exercise 4: Export to JSON

Extend the module to save hosts in JSON format:

```json
{
  "hosts": [
    {
      "hostname": "server1.company.com",
      "description": "Production Server"
    },
    {
      "hostname": "192.168.1.100",
      "description": "Development Machine"
    }
  ]
}
```

```c
BOOL SaveHostsAsJSON(const Host* hosts, int count)
{
    // TODO: Implement JSON export
    return FALSE;
}
```

### Exercise 5: Import from Text File

Write a function to import hosts from a simple text file:

```
server1.company.com
192.168.1.100
laptop-office
```

```c
BOOL ImportHostsFromTextFile(const wchar_t* filename)
{
    FILE* file = NULL;
    errno_t err = _wfopen_s(&file, filename, L"r");
    
    if (err != 0 || file == NULL)
        return FALSE;
    
    // TODO: Read each line, add as host with empty description
    
    fclose(file);
    return TRUE;
}
```

## Real-World Applications

The techniques you learned apply to many scenarios:

### 1. Contact Lists
```c
typedef struct {
    wchar_t name[256];
    wchar_t email[256];
    wchar_t phone[50];
} Contact;

BOOL LoadContacts(Contact** contacts, int* count);
```

### 2. Game High Scores
```c
typedef struct {
    wchar_t playerName[100];
    int score;
    time_t date;
} HighScore;

BOOL LoadHighScores(HighScore** scores, int* count);
```

### 3. Configuration Files
```c
typedef struct {
    wchar_t key[256];
    wchar_t value[1024];
} ConfigEntry;

BOOL LoadConfig(ConfigEntry** entries, int* count);
```

### 4. Log File Parsing
```c
typedef struct {
    time_t timestamp;
    wchar_t level[20];  // INFO, WARNING, ERROR
    wchar_t message[512];
} LogEntry;

BOOL LoadLogs(LogEntry** entries, int* count);
```

## Performance Considerations

### Time Complexity

- **LoadHosts**: O(n) where n = number of hosts
- **SaveHosts**: O(n)
- **AddHost**: O(n) - must load all hosts
- **DeleteHost**: O(n) - must load all hosts

### Memory Usage

- **LoadHosts**: O(n) - allocates array for all hosts
- **Wasted space**: Up to 50% if array grew (fine for small lists)

### Optimization Ideas

For large datasets (1000+ hosts):

1. **Database**: Use SQLite instead of CSV
2. **Incremental writes**: Append to file instead of rewriting
3. **Caching**: Keep loaded hosts in memory
4. **Indexing**: Create index for fast lookups

Example caching approach:

```c
// Global cache
static Host* g_cachedHosts = NULL;
static int g_cachedCount = 0;
static BOOL g_cacheValid = FALSE;

BOOL LoadHostsCached(Host** hosts, int* count)
{
    if (g_cacheValid)
    {
        *hosts = g_cachedHosts;
        *count = g_cachedCount;
        return TRUE;
    }
    
    // Load from file
    if (LoadHosts(&g_cachedHosts, &g_cachedCount))
    {
        g_cacheValid = TRUE;
        *hosts = g_cachedHosts;
        *count = g_cachedCount;
        return TRUE;
    }
    
    return FALSE;
}

void InvalidateHostsCache(void)
{
    g_cacheValid = FALSE;
}
```

## UTF-8 and Unicode

Let's clarify character encoding:

### What is UTF-8?

- **Variable-length encoding**: 1-4 bytes per character
- **ASCII compatible**: First 127 characters are same as ASCII
- **Universal**: Can represent all languages

### Why Use UTF-8 for Files?

- Small file size for English text
- Compatible with most text editors
- Standard for web and cross-platform

### Why Use UTF-16 (wchar_t) in Memory?

- Windows API uses UTF-16
- Easier string manipulation in Windows
- Direct compatibility with Windows functions

### Conversion Functions

```c
// UTF-8 (file) → UTF-16 (memory)
MultiByteToWideChar(CP_UTF8, 0, utf8String, -1, wideString, size);

// UTF-16 (memory) → UTF-8 (file)
WideCharToMultiByte(CP_UTF8, 0, wideString, -1, utf8String, size, NULL, NULL);
```

### Practical Example

```c
// Reading UTF-8 from file
char utf8Line[256];
fgets(utf8Line, 256, file);

// Convert to wide string for processing
wchar_t wideLine[256];
MultiByteToWideChar(CP_UTF8, 0, utf8Line, -1, wideLine, 256);

// Use Windows API with wide string
MessageBoxW(NULL, wideLine, L"Info", MB_OK);
```

## Integration with WinRDP

In later chapters, we'll use these functions to:

1. **Load hosts at startup**:
```c
// In WinMain
LoadHosts(&g_hosts, &g_hostCount);
PopulateListView(g_hosts, g_hostCount);
```

2. **Add hosts from UI**:
```c
// In Add Host button handler
wchar_t hostname[256], description[256];
GetDlgItemTextW(hDlg, IDC_HOSTNAME, hostname, 256);
GetDlgItemTextW(hDlg, IDC_DESCRIPTION, description, 256);
AddHost(hostname, description);
RefreshListView();
```

3. **Delete hosts**:
```c
// In Delete button handler
int selectedIndex = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
if (selectedIndex >= 0)
{
    DeleteHost(g_hosts[selectedIndex].hostname);
    ReloadHosts();
}
```

## Summary

You've learned:
- ✅ **Dynamic memory allocation** with `malloc` and `realloc`
- ✅ **Growing arrays** - the fundamental dynamic data structure
- ✅ **Safe realloc pattern** - critical for preventing leaks
- ✅ **Pointer-to-pointer** pattern for returning allocated data
- ✅ **CSV file format** - simple persistent storage
- ✅ **UTF-8 and UTF-16** conversion for Windows
- ✅ **File I/O** with error handling
- ✅ **Load-Modify-Save-Free** pattern
- ✅ **Memory management discipline** - every malloc has a free
- ✅ **NEW: Persistent file paths** with `GetModuleFileNameW()` (fixes autostart issues)
- ✅ **NEW: Timestamp tracking** with `SYSTEMTIME` and ISO 8601 format
- ✅ **NEW: Recent connections** feature with sorting and filtering
- ✅ **NEW: Enhanced CSV parsing** for 3-field format with backward compatibility
- ✅ **NEW: Bulk delete** functionality

**You now have:**
- Complete host management module (`hosts.h` and `hosts.c`)
- Ability to load/save RDP server lists with connection history
- Last connected timestamp tracking (enables "Recent Connections")
- Persistent file path handling (works with Windows autostart)
- Foundation for building the UI in later chapters
- Essential C patterns used in every real project

**Key new features:**
- `UpdateLastConnected()` - Records when a host was last accessed
- `GetRecentHosts()` - Retrieves most recently connected hosts
- `DeleteAllHosts()` - Bulk delete with security considerations
- `get_hosts_file_path()` - Constructs absolute paths (critical for autostart)

**Next chapter:** We'll implement secure credential storage using Windows Credential Manager!


# Chapter 20: Windows Credential Manager

> **📝 What's New in WinRDP v1.2.0**
> 
> This chapter has been updated to reflect new features:
> - ✨ Per-host credentials system (unique credentials for each server)
> - ✨ Two-tier credential lookup (per-host → global fallback)
> - ✨ SaveRDPCredentials/LoadRDPCredentials/DeleteRDPCredentials functions
> - ✨ Bulk credential deletion (DeleteAllWinRDPCredentials)
> - ✨ Credential target naming conventions

> **🔗 Related Chapters**
> 
> - Chapter 19: How hosts are stored and managed
> - Chapter 23: How credentials are used in RDP connections
> - Chapter 24: How per-host credentials integrate with UI

## Introduction

In the previous chapter, we stored hostnames and descriptions in a CSV file. But what about **passwords**?

**❌ Never store passwords in plain text files!**

```c
// NEVER DO THIS!
fprintf(file, "%s,%s,%s\n", hostname, username, password);
```

If you store passwords in plain text:
- Anyone with file access can read them
- Malware can steal them easily
- Backups expose them
- It's a **massive security risk**

In this chapter, we'll use the **Windows Credential Manager** - a secure, encrypted storage system built into Windows. It's the same system Windows uses to store:
- Saved website passwords
- Network share credentials  
- RDP saved credentials
- VPN passwords

You'll learn:
- ✅ Windows Credential Manager API (`wincred.h`)
- ✅ Secure password storage with encryption
- ✅ **NEW: Per-host and global credential management** (two-tier system)
- ✅ The `CREDENTIALW` structure
- ✅ Best practices for handling passwords in memory
- ✅ **NEW: Credential enumeration and bulk operations**

## What is Windows Credential Manager?

### User's Perspective

Open Windows Credential Manager on your PC:
1. Press `Win + R`
2. Type `control /name Microsoft.CredentialManager`
3. Press Enter

You'll see stored credentials for:
- Windows Credentials (domain passwords, etc.)
- Web Credentials (browser saved passwords)
- Generic Credentials (applications like WinRDP)

### Programmer's Perspective

Windows Credential Manager provides:
- **Encrypted storage** - Passwords encrypted with user's Windows password
- **Per-user isolation** - Each Windows user has separate credential store
- **System integration** - Works with Windows security model
- **Simple API** - 4 main functions: Write, Read, Delete, Enumerate

### Security Model

```
Your Password
     ↓
CredWriteW() → [Encrypted with Windows credentials] → System storage
     ↓
CredReadW() ← [Decrypted automatically] ← System storage
     ↓
Your Password (in memory)
```

**Key security features:**
- Passwords encrypted at rest (on disk)
- Decryption tied to Windows user account
- No access from other Windows users
- Protected from casual file browsing

## The Credential API

Four main functions in `wincred.h`:

### 1. CredWriteW - Save a Credential

```c
BOOL CredWriteW(
    PCREDENTIALW Credential,  // Pointer to credential structure
    DWORD Flags               // Usually 0
);
```

### 2. CredReadW - Retrieve a Credential

```c
BOOL CredReadW(
    LPCWSTR TargetName,       // Name/identifier of credential
    DWORD Type,               // CRED_TYPE_GENERIC for us
    DWORD Flags,              // Usually 0
    PCREDENTIALW *Credential  // Receives pointer to credential
);
```

**Important**: `CredReadW` allocates memory! Must free with `CredFree()`.

### 3. CredDeleteW - Delete a Credential

```c
BOOL CredDeleteW(
    LPCWSTR TargetName,  // Name/identifier of credential
    DWORD Type,          // CRED_TYPE_GENERIC
    DWORD Flags          // Usually 0
);
```

### 4. CredFree - Free Memory

```c
VOID CredFree(
    PVOID Buffer  // Pointer returned by CredReadW or CredEnumerateW
);
```

## The CREDENTIALW Structure

```c
typedef struct _CREDENTIALW {
    DWORD Flags;              // Usually 0
    DWORD Type;               // CRED_TYPE_GENERIC for applications
    LPWSTR TargetName;        // Unique identifier (e.g., "WinRDP:server1")
    LPWSTR Comment;           // Optional description
    FILETIME LastWritten;     // Automatically set by system
    DWORD CredentialBlobSize; // Size of password in bytes
    LPBYTE CredentialBlob;    // The actual password (as binary data)
    DWORD Persist;            // How long to keep (CRED_PERSIST_LOCAL_MACHINE)
    DWORD AttributeCount;     // Usually 0
    PCREDENTIAL_ATTRIBUTEW Attributes;  // Usually NULL
    LPWSTR TargetAlias;       // Usually NULL
    LPWSTR UserName;          // The username
} CREDENTIALW, *PCREDENTIALW;
```

**Key fields we use:**
- `Type` = `CRED_TYPE_GENERIC` (for application credentials)
- `TargetName` = Unique identifier (like "WinRDP:DefaultCredentials")
- `UserName` = The username
- `CredentialBlob` = The password (stored as bytes)
- `CredentialBlobSize` = Password length in bytes
- `Persist` = `CRED_PERSIST_LOCAL_MACHINE` (save permanently)

## Saving Credentials

Let's implement the `SaveCredentials` function:

```c
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password)
{
    CREDENTIALW cred = {0};  // Initialize all fields to 0
    
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;  // "WinRDP:DefaultCredentials"
    
    // Set up the credential structure
    cred.Type = CRED_TYPE_GENERIC;                    // Generic app credential
    cred.TargetName = (LPWSTR)targetName;             // Identifier
    cred.CredentialBlobSize = (DWORD)(wcslen(password) * sizeof(wchar_t));
    cred.CredentialBlob = (LPBYTE)password;           // Password as bytes
    cred.Persist = CRED_PERSIST_LOCAL_MACHINE;        // Save permanently
    cred.UserName = (LPWSTR)username;                 // Username
    
    // Write to Credential Manager
    if (!CredWriteW(&cred, 0))
    {
        DWORD error = GetLastError();
        wchar_t errorMsg[256];
        swprintf(errorMsg, 256, L"Failed to save credentials. Error: %lu", error);
        MessageBoxW(NULL, errorMsg, L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    return TRUE;
}
```

### Understanding CredentialBlob

**Why is password stored as bytes (`LPBYTE`)?**

The Credential Manager stores passwords as **binary blobs** - it doesn't care if it's text, image data, or encryption keys. This flexibility allows storing any type of secret.

```c
// Password as string
wchar_t password[] = L"MyPassword123";

// Size in bytes (not characters!)
// Each wchar_t is 2 bytes
DWORD size = wcslen(password) * sizeof(wchar_t);
// For "MyPassword123": 13 characters * 2 bytes = 26 bytes

// Cast to LPBYTE for storage
LPBYTE blob = (LPBYTE)password;
```

### Credential Types

```c
// Generic credentials (for applications like WinRDP)
cred.Type = CRED_TYPE_GENERIC;

// Domain credentials (for Windows networks)
cred.Type = CRED_TYPE_DOMAIN_PASSWORD;

// Certificate-based credentials
cred.Type = CRED_TYPE_DOMAIN_CERTIFICATE;
```

We use `CRED_TYPE_GENERIC` for application-specific credentials.

### Persistence Options

```c
// Session only (deleted when user logs out)
cred.Persist = CRED_PERSIST_SESSION;

// Permanent (survives logout and reboot)
cred.Persist = CRED_PERSIST_LOCAL_MACHINE;

// Enterprise (roams with user profile - requires AD)
cred.Persist = CRED_PERSIST_ENTERPRISE;
```

We use `CRED_PERSIST_LOCAL_MACHINE` so credentials survive reboots.

## Loading Credentials

```c
BOOL LoadCredentials(const wchar_t* targetName, wchar_t* username, wchar_t* password)
{
    PCREDENTIALW pcred = NULL;
    
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;
    
    // Read the credential
    // CredReadW allocates memory - we must free it!
    if (!CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred))
    {
        // Credential not found or other error
        return FALSE;
    }
    
    // Copy username
    if (pcred->UserName != NULL)
    {
        wcsncpy_s(username, MAX_USERNAME_LEN, pcred->UserName, _TRUNCATE);
    }
    else
    {
        username[0] = L'\0';  // Empty username
    }
    
    // Copy password from binary blob back to string
    if (pcred->CredentialBlob != NULL && pcred->CredentialBlobSize > 0)
    {
        // Calculate string length (blob size / 2 bytes per wchar_t)
        size_t passwordLen = pcred->CredentialBlobSize / sizeof(wchar_t);
        
        // Prevent buffer overflow
        if (passwordLen >= MAX_PASSWORD_LEN)
            passwordLen = MAX_PASSWORD_LEN - 1;
        
        // Copy password
        wcsncpy_s(password, MAX_PASSWORD_LEN, 
                 (wchar_t*)pcred->CredentialBlob, passwordLen);
        password[passwordLen] = L'\0';  // Null-terminate
    }
    else
    {
        password[0] = L'\0';  // Empty password
    }
    
    // CRITICAL: Free memory allocated by CredReadW
    CredFree(pcred);
    
    return TRUE;
}
```

### Memory Management with CredReadW

**Important pattern:**

```c
PCREDENTIALW pcred = NULL;

// CredReadW allocates memory for us
if (CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred))
{
    // Use pcred...
    
    // MUST free with CredFree, not free()!
    CredFree(pcred);
}
```

**Why `CredFree` instead of `free()`?**
- `CredReadW` may allocate multiple memory blocks
- `CredFree` handles all internal allocations
- Using `free()` would cause memory leaks or crashes

## Deleting Credentials

```c
BOOL DeleteCredentials(const wchar_t* targetName)
{
    // Use default target name if none provided
    if (targetName == NULL)
        targetName = CRED_TARGET_NAME;
    
    if (!CredDeleteW(targetName, CRED_TYPE_GENERIC, 0))
    {
        DWORD error = GetLastError();
        
        // ERROR_NOT_FOUND is okay - credential didn't exist
        if (error == ERROR_NOT_FOUND)
            return TRUE;
        
        return FALSE;
    }
    
    return TRUE;
}
```

**Error handling note:**
- `ERROR_NOT_FOUND` (1168) means credential doesn't exist
- We treat this as success (goal achieved: no credential exists)
- Other errors are actual failures

## Per-Host Credentials (NEW!)

> **💡 Key Feature**
> 
> WinRDP v1.2.0 introduces a **two-tier credential system** that provides flexibility:
> - Use one set of credentials for most servers (convenience)
> - Override with specific credentials for sensitive servers (security)

WinRDP supports two types of credentials:

1. **Global credentials** (`"WinRDP:DefaultCredentials"`) - Used as default for all servers
2. **Per-host credentials** (`"WinRDP:TERMSRV/hostname"`) - Specific to one server

### Credential Hierarchy

```
Connection Request for "server1.company.com"
         ↓
┌────────────────────────────────────────────┐
│ Step 1: Check per-host credentials        │
│ Look for: "WinRDP:TERMSRV/server1..."     │
└────────────────────────────────────────────┘
         ↓
    Found? ──Yes──→ Use per-host credentials
         │
         No
         ↓
┌────────────────────────────────────────────┐
│ Step 2: Check global credentials          │
│ Look for: "WinRDP:DefaultCredentials"     │
└────────────────────────────────────────────┘
         ↓
    Found? ──Yes──→ Use global credentials
         │
         No
         ↓
    Show login dialog (no credentials saved)
```

### Target Name Convention

```c
// Global credentials (used as fallback)
"WinRDP:DefaultCredentials"

// Per-host credentials (take precedence)
"WinRDP:TERMSRV/server1.company.com"
"WinRDP:TERMSRV/192.168.1.100"
"WinRDP:TERMSRV/production-db-01"
```

**Why "TERMSRV"?**
- Matches Windows RDP client convention
- TERMSRV = Terminal Services (old name for RDP)
- Helps organize credentials in Credential Manager
- RDP client expects format: `TERMSRV/hostname`
- Distinguishes per-host from global credentials

**Why this design?**
- **Convenience**: Most servers use the same credentials (global)
- **Security**: Production/sensitive servers get unique credentials (per-host)
- **Flexibility**: Easy to override global credentials for specific hosts
- **No complexity**: Users don't need to manage credentials for every server

### Saving Per-Host Credentials

```c
BOOL SaveRDPCredentials(const wchar_t* hostname, const wchar_t* username, 
                        const wchar_t* password)
{
    wchar_t targetName[512];
    
    // Format: "WinRDP:TERMSRV/hostname"
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    // Example: "WinRDP:TERMSRV/server1.company.com"
    
    return SaveCredentials(targetName, username, password);
}
```

Where `CRED_TARGET_PREFIX` is defined in `config.h`:

```c
#define CRED_TARGET_PREFIX L"WinRDP:TERMSRV/"
```

### Loading Per-Host Credentials

```c
BOOL LoadRDPCredentials(const wchar_t* hostname, wchar_t* username, wchar_t* password)
{
    wchar_t targetName[512];
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    // Example: "WinRDP:TERMSRV/server1.company.com"
    
    return LoadCredentials(targetName, username, password);
}
```

**Returns:**
- `TRUE` if per-host credentials exist for this hostname
- `FALSE` if no per-host credentials (use global credentials instead)

### Deleting Per-Host Credentials (NEW!)

```c
BOOL DeleteRDPCredentials(const wchar_t* hostname)
{
    wchar_t targetName[512];
    swprintf_s(targetName, 512, L"%s%s", CRED_TARGET_PREFIX, hostname);
    
    return DeleteCredentials(targetName);
}
```

**Use cases:**
- User wants to revert to global credentials for a specific host
- User changes credentials and wants to re-enter them
- Host is decommissioned/no longer used
- Security policy requires credential rotation

**Example usage in UI:**

```c
// User right-clicks on host in ListView, selects "Delete Host Credentials"
if (MessageBoxW(hWnd, 
                L"Delete saved credentials for this host?\n"
                L"Global credentials will be used instead.",
                L"Confirm", MB_YESNO) == IDYES)
{
    if (DeleteRDPCredentials(selectedHostname))
    {
        MessageBoxW(hWnd, L"Credentials deleted.", L"Success", MB_OK);
    }
}
```

### Connection Logic with Two-Tier Fallback

When connecting to a server, we implement a two-tier lookup:

```c
BOOL GetCredentialsForHost(const wchar_t* hostname, 
                           wchar_t* username, wchar_t* password)
{
    // Step 1: Try per-host credentials first (highest priority)
    if (LoadRDPCredentials(hostname, username, password))
    {
        // Found per-host credentials for this specific server
        wprintf(L"Using per-host credentials for %s\n", hostname);
        return TRUE;
    }
    
    // Step 2: Fall back to global credentials (default)
    if (LoadCredentials(NULL, username, password))
    {
        // Use global/default credentials
        wprintf(L"Using global credentials for %s\n", hostname);
        return TRUE;
    }
    
    // Step 3: No credentials found at all
    return FALSE;
}

// Usage in connection code:
wchar_t username[MAX_USERNAME_LEN];
wchar_t password[MAX_PASSWORD_LEN];

if (GetCredentialsForHost(hostname, username, password))
{
    // Have credentials - proceed with connection
    ConnectToServer(hostname, username, password);
}
else
{
    // No credentials saved - prompt user
    ShowLoginDialog();
}
```

**Real-world example:**

```
You have:
- Global: username="john.doe", password="Password123"
- Per-host for "prod-server": username="admin", password="AdminPass!"

Connections:
- Connect to "dev-server"  → Uses global (john.doe)
- Connect to "test-server" → Uses global (john.doe)
- Connect to "prod-server" → Uses per-host (admin)  ✨
```

**Benefits of this approach:**
- ✅ **Convenience**: Set global credentials once, works for most servers
- ✅ **Security**: Override with stronger credentials for production servers
- ✅ **Flexibility**: Add per-host credentials anytime without affecting others
- ✅ **Clean fallback**: Simple if-else logic, no complex credential management

## Bulk Credential Deletion (NEW!)

> **⚠️ Important Use Cases**
> 
> - User clicks "Delete All Credentials" (with confirmation!)
> - Application uninstaller cleanup
> - Security hotkey (Ctrl+Shift+Delete+Delete in WinRDP)
> - Reset to fresh state

To delete all WinRDP credentials, we need to:
1. Enumerate all credentials (CredEnumerateW)
2. Filter for WinRDP credentials (pattern matching)
3. Delete each matching credential
4. Clean up allocated memory

```c
BOOL DeleteAllWinRDPCredentials(void)
{
    DWORD count = 0;
    PCREDENTIALW* credentials = NULL;
    int deletedCount = 0;
    
    // Enumerate all credentials for current user
    // credentials will point to an array of PCREDENTIALW pointers
    if (!CredEnumerateW(NULL, 0, &count, &credentials))
    {
        DWORD error = GetLastError();
        
        // ERROR_NOT_FOUND is okay - just means no credentials exist
        if (error == ERROR_NOT_FOUND)
        {
            return TRUE;  // Success: no credentials to delete
        }
        
        // Other errors are actual failures
        return FALSE;
    }
    
    // Iterate through all credentials
    for (DWORD i = 0; i < count; i++)
    {
        // Check if this credential belongs to WinRDP
        // Match both "WinRDP:DefaultCredentials" and "WinRDP:TERMSRV/..."
        if (credentials[i]->TargetName != NULL &&
            wcsstr(credentials[i]->TargetName, L"WinRDP:") == credentials[i]->TargetName)
        {
            // Delete this credential
            if (CredDeleteW(credentials[i]->TargetName, CRED_TYPE_GENERIC, 0))
            {
                deletedCount++;
            }
            // Note: We don't fail if individual delete fails,
            // we just continue with the rest
        }
    }
    
    // IMPORTANT: Free the memory allocated by CredEnumerateW
    if (credentials != NULL)
    {
        CredFree(credentials);
    }
    
    // Return success if we got here (even if deletedCount is 0)
    return TRUE;
}
```

### Understanding CredEnumerateW

```c
BOOL CredEnumerateW(
    LPCWSTR Filter,               // NULL = all credentials
    DWORD Flags,                  // 0 for default
    DWORD *Count,                 // Receives count
    PCREDENTIALW **Credentials    // Receives pointer to array
);
```

**Memory allocation:**
```c
PCREDENTIALW* credentials;  // Pointer to array of pointers
// After CredEnumerateW:
// credentials[0] → First CREDENTIALW
// credentials[1] → Second CREDENTIALW
// ...
// credentials[count-1] → Last CREDENTIALW
```

**Example with 3 credentials:**
```
credentials → [ptr] [ptr] [ptr]
               ↓     ↓     ↓
            Cred1  Cred2  Cred3
```

### Pattern Matching with wcsstr

**Key points:**
- `CredEnumerateW` returns **all credentials** for current user (not just WinRDP)
- We filter for ones starting with `"WinRDP:"`
- `wcsstr(target, L"WinRDP:") == target` checks if string starts with prefix
- Must free with `CredFree(credentials)` - it's an array

**How the prefix check works:**

```c
// Check if targetName starts with "WinRDP:"
wcsstr(targetName, L"WinRDP:") == targetName
```

Breakdown:
- `wcsstr(str, substr)` finds `substr` in `str`, returns pointer to first occurrence
- If `substr` is at the start, it returns pointer to start of `str`
- If `substr` is elsewhere or not found, returns different pointer or NULL
- Comparing result to `str` checks if match is at position 0

**Examples:**

```c
// Example 1: Match!
wchar_t* name1 = L"WinRDP:DefaultCredentials";
wcsstr(name1, L"WinRDP:") == name1  // TRUE ✅

// Example 2: No match (wrong prefix)
wchar_t* name2 = L"Microsoft:Office";
wcsstr(name2, L"WinRDP:") == name2  // FALSE ❌

// Example 3: No match (substring present but not at start)
wchar_t* name3 = L"NotWinRDP:Something";
wcsstr(name3, L"WinRDP:") == name3  // FALSE ❌

// Example 4: Match! (per-host credential)
wchar_t* name4 = L"WinRDP:TERMSRV/server1";
wcsstr(name4, L"WinRDP:") == name4  // TRUE ✅
```

**What gets deleted:**
```c
"WinRDP:DefaultCredentials"         // ✅ Deleted (global)
"WinRDP:TERMSRV/server1.com"        // ✅ Deleted (per-host)
"WinRDP:TERMSRV/192.168.1.100"      // ✅ Deleted (per-host)
"Microsoft:Office365"                // ❌ Kept (not ours)
"GitHub:PersonalAccessToken"         // ❌ Kept (not ours)
```

### Security Considerations

**Always confirm before deleting:**

```c
// In UI code:
int result = MessageBoxW(
    hWnd,
    L"This will delete ALL saved credentials.\n"
    L"You will need to re-enter them.\n\n"
    L"Are you sure?",
    L"Confirm Delete All",
    MB_YESNO | MB_ICONWARNING
);

if (result == IDYES)
{
    if (DeleteAllWinRDPCredentials())
    {
        MessageBoxW(hWnd, L"All credentials deleted.", L"Success", MB_OK);
    }
}
```

**In WinRDP:**
- Activated by secret hotkey: Ctrl+Shift+Delete+Delete (must press Delete twice!)
- Requires confirmation dialog
- Shows count of deleted credentials
- Logs action (for auditing)

### Checking for Prefix

```c
// Check if targetName starts with "WinRDP:"
wcsstr(targetName, L"WinRDP:") == targetName
```

How it works:
- `wcsstr(str, substr)` finds `substr` in `str`
- Returns pointer to first occurrence
- If `substr` is at the start, returns `str` itself
- If not found or not at start, returns different pointer or NULL

```c
wchar_t* target = L"WinRDP:DefaultCredentials";

// Find "WinRDP:" in target
wchar_t* found = wcsstr(target, L"WinRDP:");
// found points to start of "WinRDP:" in target

// Is "WinRDP:" at the beginning?
if (found == target)  // Yes!
    printf("Starts with WinRDP:\n");
```

## Complete credentials.h Header

```c
#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <windows.h>

// General credential management
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password);
BOOL LoadCredentials(const wchar_t* targetName, wchar_t* username, wchar_t* password);
BOOL DeleteCredentials(const wchar_t* targetName);

// RDP-specific credential management
BOOL SaveRDPCredentials(const wchar_t* hostname, const wchar_t* username, 
                        const wchar_t* password);
BOOL LoadRDPCredentials(const wchar_t* hostname, wchar_t* username, wchar_t* password);
BOOL DeleteRDPCredentials(const wchar_t* hostname);
BOOL DeleteAllWinRDPCredentials(void);

#endif // CREDENTIALS_H
```

## Testing the Module

Simple test program:

```c
#include <stdio.h>
#include <windows.h>
#include "credentials.h"

int main(void)
{
    wchar_t username[256];
    wchar_t password[256];
    
    // Test 1: Save global credentials
    printf("Saving global credentials...\n");
    SaveCredentials(NULL, L"john.doe", L"SecurePassword123");
    
    // Test 2: Load global credentials
    printf("Loading global credentials...\n");
    if (LoadCredentials(NULL, username, password))
    {
        wprintf(L"Username: %s\n", username);
        wprintf(L"Password: %s\n", password);
    }
    
    // Test 3: Save per-host credentials
    printf("\nSaving credentials for server1...\n");
    SaveRDPCredentials(L"server1.company.com", L"admin", L"AdminPass456");
    
    printf("Saving credentials for server2...\n");
    SaveRDPCredentials(L"192.168.1.100", L"devuser", L"DevPass789");
    
    // Test 4: Load per-host credentials
    printf("\nLoading credentials for server1...\n");
    if (LoadRDPCredentials(L"server1.company.com", username, password))
    {
        wprintf(L"Username: %s\n", username);
        wprintf(L"Password: %s\n", password);
    }
    
    // Test 5: Delete specific credential
    printf("\nDeleting credentials for server2...\n");
    DeleteRDPCredentials(L"192.168.1.100");
    
    // Test 6: Try to load deleted credential
    printf("Trying to load deleted credential...\n");
    if (!LoadRDPCredentials(L"192.168.1.100", username, password))
    {
        printf("Correctly returned FALSE - credential deleted!\n");
    }
    
    // Test 7: Clean up all WinRDP credentials
    printf("\nDeleting all WinRDP credentials...\n");
    DeleteAllWinRDPCredentials();
    
    printf("\nAll tests complete!\n");
    return 0;
}
```

**Verify with Windows Credential Manager:**
1. Run the test program
2. Open Credential Manager (`control /name Microsoft.CredentialManager`)
3. Look under "Windows Credentials" → "Generic Credentials"
4. You should see `WinRDP:DefaultCredentials` and `WinRDP:TERMSRV/server1.company.com`

## Security Best Practices

### 1. Zero Memory After Use

```c
// Load password
wchar_t password[256];
LoadCredentials(NULL, username, password);

// Use password
ConnectToServer(hostname, username, password);

// IMPORTANT: Clear password from memory
SecureZeroMemory(password, sizeof(password));
```

**Why?**
- Passwords stay in memory until overwritten
- Memory dumps could expose them
- `SecureZeroMemory` prevents compiler optimization from removing the zeroing

### 2. Never Log Passwords

```c
// NEVER DO THIS!
wprintf(L"Debug: Password is %s\n", password);
OutputDebugStringW(password);
fprintf(logfile, "Password: %s", password);

// Instead
wprintf(L"Debug: Password loaded: %s\n", password[0] ? L"Yes" : L"No");
```

### 3. Validate Before Storing

```c
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password)
{
    // Validate inputs
    if (username == NULL || wcslen(username) == 0)
    {
        MessageBoxW(NULL, L"Username cannot be empty", L"Error", MB_OK);
        return FALSE;
    }
    
    if (password == NULL || wcslen(password) == 0)
    {
        MessageBoxW(NULL, L"Password cannot be empty", L"Error", MB_OK);
        return FALSE;
    }
    
    // Proceed with saving...
}
```

### 4. Handle Errors Gracefully

```c
if (!SaveCredentials(NULL, username, password))
{
    // Don't reveal why it failed to potential attackers
    MessageBoxW(NULL, 
               L"Failed to save credentials. Please try again.", 
               L"Error", 
               MB_OK | MB_ICONERROR);
    // Log detailed error internally for debugging
    DebugLog(L"CredWriteW failed with error %lu", GetLastError());
}
```

### 5. Limit Password Length

```c
#define MAX_PASSWORD_LEN 256

// Prevent buffer overflows
if (wcslen(password) >= MAX_PASSWORD_LEN)
{
    MessageBoxW(NULL, L"Password too long", L"Error", MB_OK);
    return FALSE;
}
```

## Common Mistakes

### Mistake 1: Storing Plain Text Passwords

```c
// WRONG - NEVER DO THIS!
fprintf(file, "%s,%s,%s\n", hostname, username, password);

// CORRECT - Use Credential Manager
SaveRDPCredentials(hostname, username, password);
```

### Mistake 2: Forgetting to Free Memory

```c
// WRONG
PCREDENTIALW pcred = NULL;
CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred);
// Use pcred...
// Oops! Forgot CredFree(pcred) - memory leak!

// CORRECT
PCREDENTIALW pcred = NULL;
if (CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred))
{
    // Use pcred...
    CredFree(pcred);  // Always free!
}
```

### Mistake 3: Wrong Blob Size

```c
// WRONG - Forgot to multiply by sizeof(wchar_t)
cred.CredentialBlobSize = wcslen(password);  // This is character count!

// CORRECT - Size in bytes
cred.CredentialBlobSize = wcslen(password) * sizeof(wchar_t);
```

### Mistake 4: Not Null-Terminating

```c
// WRONG - No null terminator!
size_t len = pcred->CredentialBlobSize / sizeof(wchar_t);
wcsncpy_s(password, MAX_PASSWORD_LEN, (wchar_t*)pcred->CredentialBlob, len);
// password may not be null-terminated!

// CORRECT - Explicitly null-terminate
wcsncpy_s(password, MAX_PASSWORD_LEN, (wchar_t*)pcred->CredentialBlob, len);
password[len] = L'\0';  // Ensure null termination
```

### Mistake 5: Using free() Instead of CredFree()

```c
// WRONG
PCREDENTIALW pcred = NULL;
CredReadW(targetName, CRED_TYPE_GENERIC, 0, &pcred);
free(pcred);  // Wrong! Use CredFree()

// CORRECT
CredFree(pcred);
```

## Exercises

### Exercise 1: Credential Validation

Add validation to `SaveCredentials`:

```c
BOOL SaveCredentials(const wchar_t* targetName, const wchar_t* username, 
                     const wchar_t* password)
{
    // Validate username
    if (username == NULL || wcslen(username) == 0) {
        MessageBoxW(NULL, L"Username cannot be empty", L"Error", MB_OK);
        return FALSE;
    }
    
    // Validate password
    if (password == NULL || wcslen(password) == 0) {
        MessageBoxW(NULL, L"Password cannot be empty", L"Error", MB_OK);
        return FALSE;
    }
    
    // Validate password length
    if (wcslen(password) >= MAX_PASSWORD_LEN) {
        MessageBoxW(NULL, L"Password too long", L"Error", MB_OK);
        return FALSE;
    }
    
    // TODO: Add more validations
    // - Check for invalid characters in username
    // - Ensure password meets complexity requirements
    // - Validate targetName format
    
    // Rest of SaveCredentials...
}
```

### Exercise 2: Password Strength Checker

Write a function to check password strength:

```c
typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} PasswordStrength;

PasswordStrength CheckPasswordStrength(const wchar_t* password)
{
    size_t len = wcslen(password);
    BOOL hasUpper = FALSE;
    BOOL hasLower = FALSE;
    BOOL hasDigit = FALSE;
    BOOL hasSpecial = FALSE;
    
    // Check length
    if (len < 8)
        return WEAK;
    
    // Analyze characters
    for (size_t i = 0; i < len; i++)
    {
        if (iswupper(password[i])) hasUpper = TRUE;
        if (iswlower(password[i])) hasLower = TRUE;
        if (iswdigit(password[i])) hasDigit = TRUE;
        if (wcschr(L"!@#$%^&*()_+-=[]{}|;:,.<>?", password[i])) 
            hasSpecial = TRUE;
    }
    
    // Determine strength
    int criteria = hasUpper + hasLower + hasDigit + hasSpecial;
    
    if (criteria >= 3 && len >= 12)
        return STRONG;
    else if (criteria >= 2 && len >= 8)
        return MEDIUM;
    else
        return WEAK;
}
```

### Exercise 3: Credential Export/Import

For backup purposes (user must provide master password):

```c
// Export credentials to encrypted file
BOOL ExportCredentials(const wchar_t* filename, const wchar_t* masterPassword)
{
    // TODO: 
    // 1. Enumerate all WinRDP credentials
    // 2. Encrypt with masterPassword
    // 3. Write to file
    return FALSE;
}

// Import credentials from encrypted file
BOOL ImportCredentials(const wchar_t* filename, const wchar_t* masterPassword)
{
    // TODO:
    // 1. Read encrypted file
    // 2. Decrypt with masterPassword
    // 3. Restore credentials to Credential Manager
    return FALSE;
}
```

### Exercise 4: Credential History

Track when credentials were last used:

```c
typedef struct {
    wchar_t hostname[256];
    wchar_t username[256];
    SYSTEMTIME lastUsed;
} CredentialInfo;

BOOL SaveCredentialHistory(const wchar_t* hostname, const wchar_t* username)
{
    SYSTEMTIME st;
    GetLocalTime(&st);
    
    // TODO: Save to registry or file
    return FALSE;
}

BOOL GetCredentialHistory(CredentialInfo** history, int* count)
{
    // TODO: Load from registry or file
    return FALSE;
}
```

### Exercise 5: Credential Change Detection

Notify user if credentials haven't been changed in 90 days:

```c
BOOL ShouldChangePassword(const wchar_t* hostname)
{
    // TODO:
    // 1. Get lastChanged date from metadata
    // 2. Calculate days since change
    // 3. Return TRUE if > 90 days
    return FALSE;
}

void CheckPasswordExpiry(void)
{
    // TODO:
    // 1. Enumerate all credentials
    // 2. Check each with ShouldChangePassword
    // 3. Show warning for expired passwords
}
```

## Integration with WinRDP

How we'll use credentials in the main application:

### 1. Login Dialog

```c
// When user clicks "Save Credentials" checkbox and logs in
if (IsDlgButtonChecked(hDlg, IDC_SAVE_CREDENTIALS) == BST_CHECKED)
{
    wchar_t username[256], password[256];
    GetDlgItemTextW(hDlg, IDC_USERNAME, username, 256);
    GetDlgItemTextW(hDlg, IDC_PASSWORD, password, 256);
    
    SaveCredentials(NULL, username, password);
}
```

### 2. Per-Host Credentials Dialog

```c
// Save credentials for specific host
void OnSaveHostCredentials(HWND hDlg, const wchar_t* hostname)
{
    wchar_t username[256], password[256];
    GetDlgItemTextW(hDlg, IDC_USERNAME, username, 256);
    GetDlgItemTextW(hDlg, IDC_PASSWORD, password, 256);
    
    SaveRDPCredentials(hostname, username, password);
}
```

### 3. Auto-Login on Startup

```c
// In WinMain
wchar_t username[256], password[256];

if (LoadCredentials(NULL, username, password))
{
    // Auto-login with saved credentials
    g_isLoggedIn = TRUE;
    ShowMainWindow();
}
else
{
    // Show login dialog
    ShowLoginDialog();
}
```

### 4. RDP Connection

```c
// When connecting to a host
void ConnectToHost(const wchar_t* hostname)
{
    wchar_t username[256], password[256];
    
    // Try per-host credentials first
    if (!LoadRDPCredentials(hostname, username, password))
    {
        // Fall back to global credentials
        if (!LoadCredentials(NULL, username, password))
        {
            MessageBoxW(NULL, L"No credentials saved", L"Info", MB_OK);
            return;
        }
    }
    
    // Launch RDP with credentials
    LaunchRDP(hostname, username, password);
    
    // Clear password from memory
    SecureZeroMemory(password, sizeof(password));
}
```

## Windows Credential Manager Limitations

Be aware of these limitations:

### 1. Per-User Storage

```c
// Credentials are per Windows user
// User A cannot access User B's credentials
// This is a security feature, not a bug!
```

### 2. No Password Sharing

```c
// Cannot share credentials between applications
// Each app should have unique TargetName prefix
// e.g., "WinRDP:...", "MyApp:...", "AnotherApp:..."
```

### 3. Size Limits

```c
// TargetName: 256 characters max
// UserName: 513 characters max
// CredentialBlob: 512 bytes max (256 wchar_t characters)
```

### 4. No Built-in Expiration

```c
// Credentials don't expire automatically
// You must implement expiration logic yourself
// Use Comment field or separate metadata file
```

## Alternative Storage Options

For comparison, here are other ways to store credentials:

### 1. Windows Registry (❌ Not Secure)

```c
// DON'T DO THIS!
RegSetValueExW(hKey, L"Password", 0, REG_SZ, 
              (BYTE*)password, wcslen(password) * sizeof(wchar_t));
```

**Problems:**
- Plain text in registry
- Easy to export and read
- Not encrypted

### 2. Configuration File (❌ Very Bad)

```c
// NEVER DO THIS!
fprintf(file, "password=%s\n", password);
```

**Problems:**
- Plain text on disk
- Visible in backups
- Can't control file permissions reliably

### 3. Database (❌ Still Not Secure Without Encryption)

```c
// INSECURE!
sqlite3_exec(db, "INSERT INTO creds VALUES ('user', 'password')", ...);
```

**Problems:**
- Plain text in database file
- Database files are easy to copy

### 4. Encrypted File (✅ Possible but Complex)

```c
// Better, but you have to implement encryption yourself
EncryptPasswordToFile(password, "creds.dat", encryptionKey);
```

**Challenges:**
- Where do you store the encryption key?
- Have to implement secure encryption
- Error-prone

### 5. Windows Credential Manager (✅ Best Choice)

```c
// CORRECT!
SaveCredentials(NULL, username, password);
```

**Advantages:**
- ✅ Built-in encryption
- ✅ Integrated with Windows security
- ✅ No key management needed
- ✅ Simple API
- ✅ Per-user isolation

**Conclusion:** Use Windows Credential Manager for Windows applications!

## Summary

You've learned:
- ✅ **Windows Credential Manager** - Secure password storage API
- ✅ **CREDENTIALW structure** - How credentials are represented
- ✅ **CredWriteW/CredReadW/CredDeleteW** - Core API functions
- ✅ **CredEnumerateW** - Bulk operations on credentials
- ✅ **CredFree** - Proper memory management
- ✅ **NEW: Two-tier credential system** - Per-host credentials with global fallback
- ✅ **NEW: SaveRDPCredentials/LoadRDPCredentials/DeleteRDPCredentials** - Per-host management
- ✅ **NEW: DeleteAllWinRDPCredentials** - Bulk deletion with pattern matching
- ✅ **Security best practices** - Zero memory, avoid logging, validate inputs
- ✅ **Target naming conventions** - Global vs per-host credential formats
- ✅ **Credential enumeration** - Finding all application credentials

**You now have:**
- Secure credential storage module (`credentials.h` and `credentials.c`)
- Ability to save/load passwords safely
- **NEW: Per-host credential support** with automatic fallback to global
- **NEW: Bulk credential operations** for cleanup scenarios
- Foundation for secure RDP connections

**Key new features:**
- **Two-tier lookup**: Check per-host first, fall back to global
- **Target name formats**: `"WinRDP:DefaultCredentials"` vs `"WinRDP:TERMSRV/hostname"`
- **Pattern matching**: `wcsstr()` to filter WinRDP credentials
- **Security hotkey**: Ctrl+Shift+Delete+Delete for bulk deletion (Chapter 26)

**Real-world benefits:**
- Use one set of credentials for most servers (convenience)
- Override with specific credentials for production/sensitive servers (security)
- Easy credential rotation per host
- Clean uninstall with DeleteAllWinRDPCredentials()

**Next chapter:** We'll implement the main application window with system tray icon and login dialog!


# Chapter 21: Main Application Window

**What You'll Learn:**
- Creating the WinMain entry point for Windows GUI applications
- Registering and creating the main window
- Implementing system tray icons
- Creating and managing dialogs
- Setting up the Windows message loop
- Handling global hotkeys
- Single instance application pattern

**Why It Matters:**
This chapter brings together everything we've learned to create the main application structure. You'll see how WinRDP initializes, displays a login dialog, creates a system tray icon, and processes Windows messages. This is where the application truly comes to life!

## Introduction

We've built several important modules:
- **hosts.c**: CSV file management for storing RDP hosts
- **credentials.c**: Secure credential storage via Windows Credential Manager
- **utils.c**: Helper functions for windows and dialogs

Now it's time to create the main application that ties everything together. In this chapter, we'll implement `main.c`, the heart of WinRDP.

## The Windows Application Entry Point: WinMain

Unlike console programs that use `main()`, Windows GUI applications use `WinMain()`:

```c
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPWSTR lpCmdLine, int nCmdShow)
{
    // Application initialization and setup
    g_hInstance = hInstance;
    
    // Initialize common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_LISTVIEW_CLASSES | ICC_STANDARD_CLASSES;
    InitCommonControlsEx(&icex);
    
    // Register window class
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WinRDP_MainWindow";
    RegisterClassExW(&wc);
    
    // Create window
    HWND hwnd = CreateWindowExW(0, L"WinRDP_MainWindow", L"WinRDP",
                                WS_OVERLAPPEDWINDOW, 0, 0, 0, 0,
                                NULL, NULL, hInstance, NULL);
    
    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}
```

### WinMain Parameters

Let's understand each parameter:

**HINSTANCE hInstance**
- Handle to the current application instance
- Used to identify your application to Windows
- Pass this to window creation, resource loading, etc.

**HINSTANCE hPrevInstance**
- Always NULL in modern Windows
- Legacy parameter from 16-bit Windows
- Can be ignored with `UNREFERENCED_PARAMETER(hPrevInstance);`

**LPWSTR lpCmdLine**
- Command line arguments as a wide string
- Example: if user runs `WinRDP.exe --autostart`, lpCmdLine is `L"--autostart"`
- Use `GetCommandLineW()` for more flexibility

**int nCmdShow**
- How the window should be displayed initially
- `SW_SHOWNORMAL`, `SW_HIDE`, `SW_MINIMIZE`, `SW_MAXIMIZE`, etc.
- Windows passes this based on how the user launched the app

## Message Flow in a Windows Application

Understanding the message flow is crucial:

```
Program Start
    ↓
WinMain() called
    ↓
Initialize (load DLLs, register classes, etc.)
    ↓
Create Window
    ↓
Show Window (optional)
    ↓
Enter Message Loop ←───────────┐
    ↓                          │
GetMessage() blocks until      │
a message arrives              │
    ↓                          │
TranslateMessage()             │
(converts keyboard input)      │
    ↓                          │
DispatchMessage()              │
(calls WndProc)                │
    ↓                          │
WndProc processes message      │
    ↓                          │
Return to loop ────────────────┘
    ↓
GetMessage() returns 0
(WM_QUIT received)
    ↓
Exit WinMain
    ↓
Program Ends
```

## System Tray Implementation

System tray icons allow applications to run in the background:

```c
BOOL InitSystemTray(HWND hwnd)
{
    NOTIFYICONDATAW nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATAW);
    nid.hWnd = hwnd;
    nid.uID = 1;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_TRAYICON;
    nid.hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    wcscpy_s(nid.szTip, 128, L"WinRDP Manager");
    
    return Shell_NotifyIconW(NIM_ADD, &nid);
}
```

### Handling Tray Icon Events

```c
case WM_TRAYICON:
    switch (LOWORD(lParam))
    {
        case WM_LBUTTONUP:
            // Left click - show main dialog
            DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), 
                     hwnd, MainDialogProc);
            break;
            
        case WM_RBUTTONUP:
            // Right click - show context menu
            ShowContextMenu(hwnd);
            break;
    }
    return 0;
```

## Global Hotkeys (Toggle Behaviour in v1.2.0)

Register the Ctrl+Shift+R hotkey once during `WM_CREATE`, then let the handler decide whether to **show or hide** the main dialog:

```c
// Register Ctrl+Shift+R in WM_CREATE
RegisterHotKey(hwnd, IDM_GLOBAL_HOTKEY, MOD_CONTROL | MOD_SHIFT, 'R');

// Handle in WndProc
case WM_HOTKEY:
    if (wParam == IDM_GLOBAL_HOTKEY)
    {
        wchar_t username[MAX_USERNAME_LEN];
        wchar_t password[MAX_PASSWORD_LEN];

        if (LoadCredentials(NULL, username, password))
        {
            if (g_hwndMainDialog == NULL)
            {
                // Not visible yet → show the main server list
                DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_MAIN), hwnd, MainDialogProc);
            }
            else if (IsWindowVisible(g_hwndMainDialog) && !IsIconic(g_hwndMainDialog))
            {
                // Already visible → close it for quick dismiss
                PostMessage(g_hwndMainDialog, WM_CLOSE, 0, 0);
            }
            else
            {
                // Created but hidden/minimized → bring it back to the foreground
                ShowWindow(g_hwndMainDialog, SW_RESTORE);
                SetForegroundWindow(g_hwndMainDialog);
            }
        }
        else
        {
            // No global creds yet → toggle the login dialog instead (no countdown in edit mode)
            if (g_hwndLoginDialog == NULL)
            {
                DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), hwnd, LoginDialogProc, 0);
            }
            else if (IsWindowVisible(g_hwndLoginDialog) && !IsIconic(g_hwndLoginDialog))
            {
                PostMessage(g_hwndLoginDialog, WM_CLOSE, 0, 0);
            }
            else
            {
                ShowWindow(g_hwndLoginDialog, SW_RESTORE);
                SetForegroundWindow(g_hwndLoginDialog);
            }
        }
    }
    return 0;
```

**Why the toggle?** WinRDP behaves like a command palette: tap the hotkey to summon the list, tap it again to dismiss. If the user has not saved default credentials yet, the same shortcut pivots to the login dialog so they can supply them without touching the mouse.

## Auto-Close Countdown Timer in Login Dialog (NEW!)

> **⏱️ User Experience Enhancement**
>
> When the login dialog opens at startup with saved credentials, it shows a 5-second countdown and automatically closes, taking the user straight to the main dialog. This eliminates an unnecessary click when credentials are already saved.

The auto-close countdown timer is a UX polish feature added in v1.2.0 that provides a smooth startup experience when credentials are already saved. When the login dialog detects existing credentials at startup, it displays a countdown timer and automatically closes after 5 seconds, immediately showing the main server list.

### Why This Feature Exists

**The Problem:**
```
User starts WinRDP → Login dialog appears → Credentials already filled
→ User must click "Save & Continue" → Finally sees server list
```

**The Solution:**
```
User starts WinRDP → Login dialog appears → Credentials already filled
→ "✓ Credentials saved - Auto-closing in 5 seconds..." → Countdown → Auto-close
→ Server list appears automatically
```

### Implementation: State Management with Static Variables

The countdown timer uses static variables to maintain state across dialog messages:

```c
INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Static variables persist across messages
    static int s_countdownSeconds = 0;
    static BOOL s_isEditMode = FALSE;
    
    switch (msg)
    {
        // ... message handling
    }
}
```

**Why static variables?**

Dialog procedures are called repeatedly for different messages. Static variables allow us to remember the countdown state between calls:

```c
Call 1: WM_INITDIALOG  → s_countdownSeconds = 5  → Start timer
Call 2: WM_TIMER       → s_countdownSeconds = 4  → Update display
Call 3: WM_TIMER       → s_countdownSeconds = 3  → Update display
Call 4: WM_TIMER       → s_countdownSeconds = 2  → Update display
Call 5: WM_TIMER       → s_countdownSeconds = 1  → Update display
Call 6: WM_TIMER       → s_countdownSeconds = 0  → Kill timer, close dialog
```

### Timer ID Definition

Define a unique timer ID in `main.c`:

```c
// Timer ID for auto-close countdown
#define TIMER_AUTO_CLOSE_LOGIN 1
```

**Why define a timer ID?**
- Multiple timers can exist in the same window
- Each needs a unique ID to distinguish them
- Using constants makes code more readable than magic numbers

### WM_INITDIALOG: Starting the Countdown

```c
case WM_INITDIALOG:
{
    // Track this dialog instance
    g_hwndLoginDialog = hwnd;
    
    // Reset countdown
    s_countdownSeconds = 0;
    
    // Check if we're opening in edit mode (lParam = 1 means editing)
    s_isEditMode = (lParam == 1);
    
    // Dialog is being initialized
    CenterWindow(hwnd);
    ApplyDarkModeToDialog(hwnd);
    
    // Set dialog icon
    HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_MAINICON));
    SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
    
    // Try to load existing credentials
    wchar_t username[MAX_USERNAME_LEN];
    wchar_t password[MAX_PASSWORD_LEN];
    
    if (LoadCredentials(NULL, username, password))
    {
        // Credentials exist - populate the fields
        SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username);
        SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password);
        
        // Show delete button
        ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_SHOW);
        
        // Only show countdown and start timer if NOT in edit mode
        if (!s_isEditMode)
        {
            // Show compact status message and start countdown
            s_countdownSeconds = 5;
            wchar_t statusMsg[128];
            swprintf_s(statusMsg, 128, L"✓ Credentials saved - Auto-closing in %d seconds...", s_countdownSeconds);
            SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
            
            // Start timer - fires every 1 second (1000 milliseconds)
            SetTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN, 1000, NULL);
        }
        else
        {
            // Edit mode - show simple status without countdown
            SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"✓ Credentials saved");
        }
    }
    else
    {
        // No credentials - hide the delete button
        ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_HIDE);
        SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"");
    }
    
    return TRUE;
}
```

**Key points:**

1. **`DialogBoxParam` with lParam** - Caller passes `0` for normal mode (with countdown) or `1` for edit mode (no countdown)
2. **Edit mode check** - `s_isEditMode = (lParam == 1)` determines behavior
3. **Conditional timer** - Timer only starts if NOT in edit mode AND credentials exist
4. **SetTimer parameters**:
   - `hwnd` - Window to receive WM_TIMER messages
   - `TIMER_AUTO_CLOSE_LOGIN` - Timer ID (our constant)
   - `1000` - Interval in milliseconds (1 second)
   - `NULL` - No callback function (use WM_TIMER message instead)

### WM_TIMER: Countdown Logic

```c
case WM_TIMER:
{
    // Handle timer events
    if (wParam == TIMER_AUTO_CLOSE_LOGIN)
    {
        // Decrement countdown
        s_countdownSeconds--;
        
        if (s_countdownSeconds > 0)
        {
            // Update countdown message
            wchar_t statusMsg[128];
            swprintf_s(statusMsg, 128, L"✓ Credentials saved - Auto-closing in %d seconds...", s_countdownSeconds);
            SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
        }
        else
        {
            // Time's up - kill timer, close login dialog
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            
            // Close the login dialog (returns IDOK to WinMain)
            EndDialog(hwnd, IDOK);
        }
    }
    return TRUE;
}
```

**How it works:**

1. **Timer fires** - Windows sends `WM_TIMER` every 1000ms
2. **Check timer ID** - Multiple timers might exist, so verify it's ours
3. **Decrement** - Reduce `s_countdownSeconds` by 1
4. **Update UI** - Show new countdown value to user
5. **Final check** - When countdown reaches 0:
   - **KillTimer** - Stop timer (no more WM_TIMER messages)
   - **EndDialog** - Close dialog with IDOK result
   - **WinMain** - Receives IDOK and opens main dialog

### Canceling the Countdown

Users can interact with the dialog to cancel the countdown:

```c
case WM_COMMAND:
    switch (LOWORD(wParam))
    {
        case IDOK:
        {
            // Kill timer if it's running (user clicked OK manually)
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            
            // User clicked OK - save credentials
            wchar_t username[MAX_USERNAME_LEN];
            wchar_t password[MAX_PASSWORD_LEN];
            
            GetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username, MAX_USERNAME_LEN);
            GetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password, MAX_PASSWORD_LEN);
            
            // Validate and save...
            if (SaveCredentials(NULL, username, password))
            {
                ShowInfoMessage(hwnd, L"Credentials saved successfully!");
                EndDialog(hwnd, IDOK);
            }
            return TRUE;
        }

        case IDC_BTN_DELETE_CREDS:
        {
            // Kill timer if running
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            
            // Delete saved credentials
            if (DeleteCredentials(NULL))
            {
                SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, L"");
                SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, L"");
                SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, L"");
                ShowWindow(GetDlgItem(hwnd, IDC_BTN_DELETE_CREDS), SW_HIDE);
                ShowInfoMessage(hwnd, L"Credentials deleted.");
            }
            return TRUE;
        }

        case IDCANCEL:
            // Kill timer if running
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            s_countdownSeconds = 0;
            g_hwndLoginDialog = NULL;
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }
    break;

case WM_CLOSE:
    // Kill timer if running
    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
    s_countdownSeconds = 0;
    g_hwndLoginDialog = NULL;
    EndDialog(hwnd, IDCANCEL);
    return TRUE;
```

**Important:** Always call `KillTimer` before the dialog closes!
- Prevents timer from firing after dialog is destroyed
- Avoids sending messages to invalid window handle
- Proper resource cleanup

### Edit Mode vs Normal Mode

The dialog supports two modes:

**Normal Mode (Startup with Countdown):**
```c
// Called from WinMain at startup
DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), 
              g_hwndMain, LoginDialogProc, 0);
```
- lParam = 0
- Shows countdown if credentials exist
- Auto-closes after 5 seconds
- Smooth startup experience

**Edit Mode (No Countdown):**
```c
// Called from main dialog's "Edit Credentials" button
DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), 
              hwnd, LoginDialogProc, 1);
```
- lParam = 1
- No countdown, even if credentials exist
- User explicitly wants to edit credentials
- Simple status: "✓ Credentials saved"

### Visual Flow

```
┌──────────────────────────────────────────────┐
│           WinRDP - Enter Credentials         │
├──────────────────────────────────────────────┤
│ Username:  [administrator              ]     │
│ Password:  [**************             ]     │
│                                              │
│ ✓ Credentials saved - Auto-closing in 5...  │    ← Countdown display
│                            [Delete Saved]     │
│                                              │
│          [Save & Continue]  [Cancel]         │
└──────────────────────────────────────────────┘

After 1 second:

┌──────────────────────────────────────────────┐
│           WinRDP - Enter Credentials         │
├──────────────────────────────────────────────┤
│ Username:  [administrator              ]     │
│ Password:  [**************             ]     │
│                                              │
│ ✓ Credentials saved - Auto-closing in 4...  │    ← Updated countdown
│                            [Delete Saved]     │
│                                              │
│          [Save & Continue]  [Cancel]         │
└──────────────────────────────────────────────┘

... continues until 0, then dialog closes automatically ...
```

### Complete Code Summary

```c
// Timer ID definition
#define TIMER_AUTO_CLOSE_LOGIN 1

INT_PTR CALLBACK LoginDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    // Static variables for state persistence
    static int s_countdownSeconds = 0;
    static BOOL s_isEditMode = FALSE;

    switch (msg)
    {
        case WM_INITDIALOG:
        {
            s_countdownSeconds = 0;
            s_isEditMode = (lParam == 1);  // Check edit mode
            
            wchar_t username[MAX_USERNAME_LEN];
            wchar_t password[MAX_PASSWORD_LEN];
            
            if (LoadCredentials(NULL, username, password))
            {
                SetDlgItemTextW(hwnd, IDC_EDIT_USERNAME, username);
                SetDlgItemTextW(hwnd, IDC_EDIT_PASSWORD, password);
                
                if (!s_isEditMode)
                {
                    // Start countdown timer
                    s_countdownSeconds = 5;
                    wchar_t statusMsg[128];
                    swprintf_s(statusMsg, 128, 
                              L"✓ Credentials saved - Auto-closing in %d seconds...", 
                              s_countdownSeconds);
                    SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
                    SetTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN, 1000, NULL);
                }
            }
            return TRUE;
        }
        
        case WM_TIMER:
        {
            if (wParam == TIMER_AUTO_CLOSE_LOGIN)
            {
                s_countdownSeconds--;
                
                if (s_countdownSeconds > 0)
                {
                    // Update countdown display
                    wchar_t statusMsg[128];
                    swprintf_s(statusMsg, 128, 
                              L"✓ Credentials saved - Auto-closing in %d seconds...", 
                              s_countdownSeconds);
                    SetDlgItemTextW(hwnd, IDC_STATIC_STATUS, statusMsg);
                }
                else
                {
                    // Time's up - close dialog
                    KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
                    EndDialog(hwnd, IDOK);
                }
            }
            return TRUE;
        }

        case WM_COMMAND:
            // Always kill timer when user interacts
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            // ... handle commands ...
            break;

        case WM_CLOSE:
        case WM_DESTROY:
            KillTimer(hwnd, TIMER_AUTO_CLOSE_LOGIN);
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }

    return FALSE;
}
```

### Key Takeaways

**Benefits:**
- ✅ **Smooth UX** - One less click for returning users
- ✅ **Still accessible** - Users can cancel anytime by clicking
- ✅ **Mode-aware** - No countdown when explicitly editing
- ✅ **Clean implementation** - Static variables + timers

**Technical concepts:**
- **SetTimer/KillTimer** - Windows timer management
- **WM_TIMER** - Periodic message handling
- **Static variables** - State persistence across messages
- **DialogBoxParam** - Passing mode flags via lParam
- **Resource cleanup** - Always kill timers before destroying windows

**Common mistakes:**
- ❌ Forgetting to kill timer → Crashes when timer fires on destroyed window
- ❌ Not handling user interaction → Timer keeps running even when user clicks
- ❌ Using same countdown in edit mode → Annoying UX when user wants to edit

**Next steps:**
- **Try it!** - Build and run WinRDP to see the countdown in action
- **Experiment** - Change countdown from 5 to 3 seconds
- **Extend** - Add a "Don't show this again" checkbox
- **Polish** - Add visual progress bar instead of text countdown

## Summary

You've learned:
- ✅ WinMain entry point and parameters
- ✅ Windows message loop architecture
- ✅ System tray icon implementation  
- ✅ Global hotkey registration
- ✅ Dialog creation and management
- ✅ **NEW: Auto-close countdown timer** with state management

**Next chapter:** ListView controls for displaying host lists!


# Chapter 22: ListView Control for Host Display

> **📝 What's New in WinRDP v1.2.0**
> 
> This chapter has been updated to reflect new features:
> - ✨ Three-column layout (Hostname, Description, Last Connected)
> - ✨ Column sorting with click-to-sort headers
> - ✨ Real-time search/filter functionality
> - ✨ Dynamic host count status label
> - ✨ lParam preservation for filtered view stability
> - ✨ Dummy column workaround for centering

> **🔗 Related Chapters**
> 
> - Chapter 19: How hosts and lastConnected timestamps are stored
> - Chapter 21: Main dialog creation and message handling
> - Chapter 23: How hosts are launched from ListView selection

**What You'll Learn:**
- Creating and configuring ListView controls
- **NEW: Adding three columns** including Last Connected timestamp
- Populating ListViews with data
- **NEW: Implementing column sorting** with ascending/descending toggle
- **NEW: Real-time search/filter** with case-insensitive matching
- **NEW: Using lParam to preserve data indices** after filtering
- Handling ListView selection and double-click events
- Working with extended ListView styles
- **NEW: Dynamic status labels** showing filter state

**Why It Matters:**
The ListView control is essential for displaying tabular data in Windows applications. In this chapter, you'll learn how to create a professional-looking host list that users can browse, search, filter, and sort. This is a critical UI component that appears in countless Windows applications.

## Introduction

Now that we have the main application structure from Chapter 21, it's time to display our RDP hosts in a user-friendly way. We'll use the **ListView control** - Windows' built-in control for displaying data in rows and columns (like Excel or File Explorer).

## What is a ListView Control?

A ListView displays items in various views:
- **Report view** (what we'll use): Rows and columns like a spreadsheet
- **Icon view**: Large icons with labels
- **List view**: Single-column list
- **Small icon view**: Small icons in columns

```c
// WinRDP uses Report View:
// ┌────────────────────────────────────────┐
// │ Hostname        │ Description          │
// ├────────────────────────────────────────┤
// │ server01        │ Production Server    │
// │ dev-machine     │ Development Box      │
// │ backup-srv      │ Backup Server        │
// └────────────────────────────────────────┘
```

## Creating a ListView Control

ListViews are typically created in dialog resources, but we configure them in code:

```c
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Get handle to ListView control (defined in dialog resource)
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
            
            // Set extended styles
            ListView_SetExtendedListViewStyle(hList, 
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Add columns
            AddListViewColumns(hList);
            
            // Load and display data
            if (LoadHosts(&hosts, &hostCount))
            {
                RefreshHostListView(hList, hosts, hostCount, NULL);
            }
            
            return TRUE;
        }
    }
    
    return FALSE;
}
```

## Extended ListView Styles

Extended styles enhance ListView appearance and behavior:

```c
ListView_SetExtendedListViewStyle(hList,
    LVS_EX_FULLROWSELECT |   // Select entire row, not just first column
    LVS_EX_GRIDLINES |        // Show grid lines between cells
    LVS_EX_DOUBLEBUFFER       // Reduce flicker when redrawing
);

// Other useful styles:
LVS_EX_CHECKBOXES         // Add checkboxes to first column
LVS_EX_HEADERDRAGDROP     // Allow column reordering
LVS_EX_SUBITEMIMAGES      // Show images in subitems
LVS_EX_INFOTIP            // Show tooltips
```

## Adding Columns to ListView

Columns define the structure of the ListView:

```c
void AddListViewColumns(HWND hList)
{
    // Get ListView width for calculating column sizes
    RECT rcList;
    GetClientRect(hList, &rcList);
    int listWidth = rcList.right - rcList.left;
    
    LVCOLUMNW col = {0};
    
    // Important: Column 0 cannot be centered in Report view!
    // Workaround: Add an invisible dummy column at position 0
    col.mask = LVCF_TEXT | LVCF_WIDTH;
    col.pszText = L"";
    col.cx = 1;  // Nearly invisible (just 1 pixel)
    ListView_InsertColumn(hList, 0, &col);
    
    // Now add real columns that CAN be centered
    col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
    col.fmt = LVCFMT_CENTER;  // Center text in column
    
    // Column 1: Hostname
    col.pszText = L"Hostname";
    col.cx = 170;  // Fixed width for hostnames
    ListView_InsertColumn(hList, 1, &col);
    
    // Column 2: Description (takes most space)
    col.pszText = L"Description";
    col.cx = listWidth - 170 - 160 - 5;  // Fill remaining space
    ListView_InsertColumn(hList, 2, &col);
    
    // Column 3: Last Connected (NEW!)
    col.pszText = L"Last Connected";
    col.cx = 160;  // Fixed width for timestamps
    ListView_InsertColumn(hList, 3, &col);
}
```

**Column width calculation:**
```
Total width = 800 pixels (example)
- Column 0 (dummy) = 1 pixel
- Column 1 (Hostname) = 170 pixels
- Column 2 (Description) = 800 - 170 - 160 - 5 = 465 pixels
- Column 3 (Last Connected) = 160 pixels
- Padding = 5 pixels (scrollbar, borders)
```

**Why these widths?**
- **Hostname (170px)**: Fits typical hostnames like "server01.company.com"
- **Description (flexible)**: Takes remaining space, adapts to window size
- **Last Connected (160px)**: Fits "YYYY-MM-DD HH:MM:SS" or "Never"
```

### The Column 0 Centering Problem

**Why the dummy column?**

Windows has a quirk: Column 0 in Report view cannot be centered. It's always left-aligned. The workaround:

```c
// Add a 1-pixel wide dummy column at position 0
col.cx = 1;
ListView_InsertColumn(hList, 0, &col);

// Then add your real columns at positions 1, 2, 3...
// These CAN be centered!
col.fmt = LVCFMT_CENTER;
ListView_InsertColumn(hList, 1, &col);  // Now we can center!
```

### LVCOLUMN Structure

```c
typedef struct {
    UINT mask;        // Which fields are valid (LVCF_TEXT, LVCF_WIDTH, etc.)
    int fmt;          // Alignment (LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_RIGHT)
    int cx;           // Column width in pixels
    LPWSTR pszText;   // Column header text
    // ... other fields for images, sorting, etc.
} LVCOLUMNW;

// mask values:
LVCF_FMT      // fmt field is valid
LVCF_WIDTH    // cx field is valid
LVCF_TEXT     // pszText field is valid
LVCF_SUBITEM  // iSubItem field is valid
```

## Populating the ListView

Add items and subitems to display data:

```c
void RefreshHostListView(HWND hList, Host* hosts, int hostCount, const wchar_t* searchText)
{
    // Clear existing items
    ListView_DeleteAllItems(hList);
    
    if (hosts == NULL || hostCount == 0)
        return;
    
    // Filtering logic (optional)
    BOOL hasFilter = (searchText != NULL && wcslen(searchText) > 0);
    wchar_t searchLower[256] = {0};
    if (hasFilter)
    {
        wcsncpy_s(searchLower, 256, searchText, _TRUNCATE);
        _wcslwr_s(searchLower, 256);  // Convert to lowercase
    }
    
    // Add each host to the ListView
    int displayIndex = 0;
    for (int i = 0; i < hostCount; i++)
    {
        // Apply filter if specified
        if (hasFilter)
        {
            wchar_t hostnameLower[256], descLower[256];
            wcsncpy_s(hostnameLower, 256, hosts[i].hostname, _TRUNCATE);
            _wcslwr_s(hostnameLower, 256);
            wcsncpy_s(descLower, 256, hosts[i].description, _TRUNCATE);
            _wcslwr_s(descLower, 256);
            
            // Skip if no match
            if (wcsstr(hostnameLower, searchLower) == NULL &&
                wcsstr(descLower, searchLower) == NULL)
            {
                continue;
            }
        }
        
        // Insert item
        LVITEMW item = {0};
        item.mask = LVIF_TEXT | LVIF_PARAM;
        item.iItem = displayIndex;
        item.iSubItem = 0;
        item.pszText = L"";  // Dummy column (column 0)
        item.lParam = (LPARAM)i;  // CRITICAL: Store original index!
        ListView_InsertItem(hList, &item);
        
        // Set text for columns (remember: 0 is dummy, real columns are 1,2,3)
        ListView_SetItemText(hList, displayIndex, 1, hosts[i].hostname);      // Column 1
        ListView_SetItemText(hList, displayIndex, 2, hosts[i].description);   // Column 2
        ListView_SetItemText(hList, displayIndex, 3, hosts[i].lastConnected); // Column 3 (NEW!)
        
        displayIndex++;
    }
    
    return displayIndex;  // Return number of displayed items
}

/**
 * Why lParam is CRITICAL:
 *
 * Problem: When filtering, ListView row indices don't match array indices!
 * 
 * Example:
 *   Array: [server1, server2, server3, server4, server5]
 *   Filter "2" shows only: server2, server3
 *   ListView indices: [0, 1]
 *   Array indices:    [1, 2]  <- NOT the same!
 * 
 * Solution: Store original array index in lParam
 * 
 * When user clicks row 0:
 *   ListView row = 0
 *   Get item.lParam = 1  (the original array index)
 *   Access hosts[1] = server2  <- Correct!
 * 
 * Without lParam, we'd try hosts[0] = server1 <- WRONG!
 */
```

### LVITEM Structure

```c
typedef struct {
    UINT mask;         // Which fields are valid
    int iItem;         // Row index
    int iSubItem;      // Column index (0 = first column)
    UINT state;        // Item state (selected, focused, etc.)
    UINT stateMask;    // Which state bits are valid
    LPWSTR pszText;    // Item text
    int cchTextMax;    // Size of pszText buffer
    int iImage;        // Image index
    LPARAM lParam;     // User-defined data
    // ... more fields
} LVITEMW;

// mask values:
LVIF_TEXT      // pszText is valid
LVIF_IMAGE     // iImage is valid
LVIF_PARAM     // lParam is valid
LVIF_STATE     // state and stateMask are valid
```

### Adding Items Step-by-Step

```c
// 1. Create and insert the base item
LVITEMW item = {0};
item.mask = LVIF_TEXT | LVIF_PARAM;
item.iItem = 0;          // Row 0
item.iSubItem = 0;       // Column 0
item.pszText = L"";      // Empty text for dummy column
item.lParam = 123;       // Store custom data (e.g., original index)
int index = ListView_InsertItem(hList, &item);

// 2. Set text for other columns (subitems)
ListView_SetItemText(hList, index, 1, L"server01");           // Column 1: Hostname
ListView_SetItemText(hList, index, 2, L"Production Server");  // Column 2: Description
ListView_SetItemText(hList, index, 3, L"2025-11-07 09:30:15"); // Column 3: Last Connected
```

### The lParam Trick (CRITICAL for Filtering!)

> **💡 Key Concept**
>
> When filtering the ListView, displayed row indices ≠ original array indices!
> Use `lParam` to store the original array index so you can access the correct data.

**The Problem:**

```
Original array:
  Index: 0        1        2        3        4
  Host:  prod-01  dev-02   prod-03  test-04  dev-05

Filter by "prod" shows:
  ListView Row: 0        1
  Host:         prod-01  prod-03
  Array Index:  0        2        <- Not sequential!

User clicks row 1:
  ❌ WRONG: hosts[1] = dev-02  (not visible!)
  ✅ RIGHT: hosts[2] = prod-03 (what user sees)
```

**The Solution:**

```c
// When inserting item, store original array index in lParam
item.lParam = (LPARAM)i;  // i = original array index
ListView_InsertItem(hList, &item);

// When handling click, retrieve original index from lParam
LVITEMW item = {0};
item.mask = LVIF_PARAM;
item.iItem = selectedRow;  // ListView row
ListView_GetItem(hList, &item);
int originalIndex = (int)item.lParam;  // Original array index!

// Now access correct host
connectToHost(hosts[originalIndex].hostname);  // ✅ Correct!
```

**Real-world example:**

```c
case NM_DBLCLK:  // User double-clicked a row
{
    int selectedRow = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
    
    // DON'T do this:
    // connectToHost(hosts[selectedRow].hostname);  // ❌ WRONG!
    
    // DO this:
    LVITEMW item = {0};
    item.mask = LVIF_PARAM;
    item.iItem = selectedRow;
    ListView_GetItem(hList, &item);
    int originalIndex = (int)item.lParam;
    connectToHost(hosts[originalIndex].hostname);  // ✅ Correct!
}
```

## Handling ListView Events

Respond to user interactions with the ListView:

```c
case WM_NOTIFY:
{
    LPNMHDR pnmhdr = (LPNMHDR)lParam;
    
    // Check if notification is from our ListView
    if (pnmhdr->idFrom == IDC_LIST_SERVERS)
    {
        switch (pnmhdr->code)
        {
            case NM_DBLCLK:
            {
                // Double-click - connect to selected host
                HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                
                if (selected >= 0)
                {
                    // Get the original host index from lParam
                    LVITEMW item = {0};
                    item.mask = LVIF_PARAM;
                    item.iItem = selected;
                    ListView_GetItem(hList, &item);
                    int hostIndex = (int)item.lParam;
                    
                    // Connect to the host
                    if (hostIndex >= 0 && hostIndex < hostCount)
                    {
                        LaunchRDPWithDefaults(hosts[hostIndex].hostname);
                    }
                }
                return TRUE;
            }
            
            case LVN_ITEMCHANGED:
            {
                // Selection changed
                // Update UI based on selection
                return TRUE;
            }
        }
    }
    break;
}
```

### Common ListView Notifications

```c
NM_CLICK        // Single click
NM_DBLCLK       // Double-click
NM_RCLICK       // Right-click
LVN_ITEMCHANGED // Item changed (selected, focused, etc.)
LVN_COLUMNCLICK // Column header clicked
LVN_KEYDOWN     // Key pressed
LVN_BEGINLABELEDIT // User started editing item text
LVN_ENDLABELEDIT   // User finished editing item text
```

## Getting ListView Selection

Multiple ways to get the selected item:

```c
// Method 1: Get first selected item
int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
if (selected >= 0)
{
    // Item 'selected' is selected
}

// Method 2: Iterate all selected items (for multi-select)
int index = -1;
while ((index = ListView_GetNextItem(hList, index, LVNI_SELECTED)) != -1)
{
    // Process item 'index'
}

// Method 3: Get focused item
int focused = ListView_GetNextItem(hList, -1, LVNI_FOCUSED);
```

### ListView_GetNextItem Function

```c
int ListView_GetNextItem(
    HWND hList,      // ListView handle
    int iStart,      // Start searching from this index (-1 = start from beginning)
    UINT flags       // What to search for
);

// flags:
LVNI_ALL        // All items
LVNI_FOCUSED    // Item with focus
LVNI_SELECTED   // Selected items
LVNI_CUT        // Items marked for cut
LVNI_DROPHILITED // Drop highlighted items

// Returns: Index of next item, or -1 if none found
```

## Implementing Search/Filter

Real-time search as user types:

```c
case WM_COMMAND:
{
    if (LOWORD(wParam) == IDC_EDIT_SEARCH && HIWORD(wParam) == EN_CHANGE)
    {
        // Search text changed - refresh list with filter
        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
        
        // Get search text
        wchar_t searchText[256] = {0};
        GetWindowTextW(hSearch, searchText, 256);
        
        // Refresh ListView with filter
        RefreshHostListView(hList, hosts, hostCount, searchText);
        
        return TRUE;
    }
    break;
}
```

### Case-Insensitive Searching

```c
// Convert both search term and data to lowercase
wchar_t searchLower[256], hostnameLower[256];

wcsncpy_s(searchLower, 256, searchText, _TRUNCATE);
_wcslwr_s(searchLower, 256);

wcsncpy_s(hostnameLower, 256, hostname, _TRUNCATE);
_wcslwr_s(hostnameLower, 256);

// Check if hostname contains search text
if (wcsstr(hostnameLower, searchLower) != NULL)
{
    // Match found!
}
```

## Practical Example: Complete ListView Dialog

```c
INT_PTR CALLBACK MainDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static Host* hosts = NULL;
    static int hostCount = 0;
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            CenterWindow(hwnd);
            
            // Get ListView handle
            HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
            
            // Set extended styles
            ListView_SetExtendedListViewStyle(hList,
                LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);
            
            // Get ListView dimensions
            RECT rcList;
            GetClientRect(hList, &rcList);
            int listWidth = rcList.right - rcList.left;
            
            // Add columns
            LVCOLUMNW col = {0};
            
            // Dummy column
            col.mask = LVCF_TEXT | LVCF_WIDTH;
            col.pszText = L"";
            col.cx = 1;
            ListView_InsertColumn(hList, 0, &col);
            
            // Real columns
            col.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_FMT;
            col.fmt = LVCFMT_CENTER;
            
            col.pszText = L"Hostname";
            col.cx = 180;
            ListView_InsertColumn(hList, 1, &col);
            
            col.pszText = L"Description";
            col.cx = listWidth - 180 - 5;
            ListView_InsertColumn(hList, 2, &col);
            
            // Load hosts
            if (LoadHosts(&hosts, &hostCount))
            {
                RefreshHostListView(hList, hosts, hostCount, NULL);
            }
            
            return TRUE;
        }
        
        case WM_NOTIFY:
        {
            LPNMHDR pnmhdr = (LPNMHDR)lParam;
            if (pnmhdr->idFrom == IDC_LIST_SERVERS && pnmhdr->code == NM_DBLCLK)
            {
                // Double-click - connect
                HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
                
                if (selected >= 0)
                {
                    LVITEMW item = {0};
                    item.mask = LVIF_PARAM;
                    item.iItem = selected;
                    ListView_GetItem(hList, &item);
                    int hostIndex = (int)item.lParam;
                    
                    if (hostIndex >= 0 && hostIndex < hostCount)
                    {
                        LaunchRDPWithDefaults(hosts[hostIndex].hostname);
                        EndDialog(hwnd, IDOK);
                    }
                }
            }
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDC_EDIT_SEARCH:
                    if (HIWORD(wParam) == EN_CHANGE)
                    {
                        // Update filter
                        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
                        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
                        
                        wchar_t searchText[256];
                        GetWindowTextW(hSearch, searchText, 256);
                        
                        RefreshHostListView(hList, hosts, hostCount, searchText);
                    }
                    return TRUE;
                
                case IDCANCEL:
                    if (hosts)
                    {
                        FreeHosts(hosts, hostCount);
                        hosts = NULL;
                    }
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;
        }
        
        case WM_CLOSE:
            if (hosts)
            {
                FreeHosts(hosts, hostCount);
                hosts = NULL;
            }
            EndDialog(hwnd, IDCANCEL);
            return TRUE;
    }
    
    return FALSE;
}
```

## ListView Best Practices

### 1. Use lParam to Store Data

```c
// Store original array index in lParam
item.lParam = (LPARAM)i;

// Later, retrieve it reliably
LVITEMW item = {0};
item.mask = LVIF_PARAM;
item.iItem = selectedRow;
ListView_GetItem(hList, &item);
int originalIndex = (int)item.lParam;
```

**Why?** After filtering, ListView row numbers don't match array indices. lParam preserves the mapping.

### 2. Delete All Items Before Refreshing

```c
// Always clear before repopulating
ListView_DeleteAllItems(hList);

// Then add new items
for (int i = 0; i < count; i++)
{
    // Add item...
}
```

### 3. Use Virtual ListViews for Large Datasets

```c
// For 10,000+ items, use LVS_OWNERDATA style
// ListView asks you for data on-demand (only visible rows)
// Significantly faster and more memory-efficient
```

### 4. Disable Redraw During Bulk Operations

```c
// Temporarily disable redrawing
SendMessage(hList, WM_SETREDRAW, FALSE, 0);

// Add many items
for (int i = 0; i < 1000; i++)
{
    ListView_InsertItem(...);
}

// Re-enable redrawing and force refresh
SendMessage(hList, WM_SETREDRAW, TRUE, 0);
InvalidateRect(hList, NULL, TRUE);
```

## Common ListView Issues and Solutions

### Issue 1: Column 0 Won't Center

**Problem:**
```c
col.fmt = LVCFMT_CENTER;
ListView_InsertColumn(hList, 0, &col);  // Still left-aligned!
```

**Solution:**
```c
// Add dummy column at 0, real columns at 1, 2, ...
ListView_InsertColumn(hList, 0, &dummyCol);
ListView_InsertColumn(hList, 1, &realCol);  // This can be centered
```

### Issue 2: Selection Lost After Refresh

**Problem:**
```c
ListView_DeleteAllItems(hList);
// Repopulate...
// Previously selected item is no longer selected
```

**Solution:**
```c
// Save selection before refresh
int saved = ListView_GetNextItem(hList, -1, LVNI_SELECTED);

// Refresh
ListView_DeleteAllItems(hList);
// Repopulate...

// Restore selection
if (saved >= 0 && saved < newCount)
{
    ListView_SetItemState(hList, saved, LVIS_SELECTED, LVIS_SELECTED);
    ListView_EnsureVisible(hList, saved, FALSE);
}
```

### Issue 3: Flickering During Updates

**Solution:**
```c
// Use LVS_EX_DOUBLEBUFFER
ListView_SetExtendedListViewStyle(hList, LVS_EX_DOUBLEBUFFER);

// Or disable redraw during updates
SendMessage(hList, WM_SETREDRAW, FALSE, 0);
// Update...
SendMessage(hList, WM_SETREDRAW, TRUE, 0);
```

## Exercises

### Exercise 1: Add Row Numbers

Add a column showing row numbers:

```c
// TODO: Add a "No." column
col.pszText = L"No.";
col.cx = 40;
ListView_InsertColumn(hList, 1, &col);

// When adding items, set row number
wchar_t rowNum[16];
swprintf_s(rowNum, 16, L"%d", displayIndex + 1);
ListView_SetItemText(hList, displayIndex, 1, rowNum);
```

### Exercise 2: Implement Column Sorting

Sort by column when header clicked:

```c
// TODO: Handle LVN_COLUMNCLICK
case LVN_COLUMNCLICK:
{
    LPNMLISTVIEW pnmv = (LPNMLISTVIEW)lParam;
    int column = pnmv->iSubItem;
    
    // Sort by column
    // (Hint: Use ListView_SortItems)
    break;
}
```

### Exercise 3: Highlight Search Terms

Highlight matching text in a different color:

```c
// TODO: Use custom drawing (NM_CUSTOMDRAW)
// Detect if item text contains search term
// Draw with highlighted background
```

### Exercise 4: Export to CSV

Add an "Export" button that saves the current filtered view to CSV:

```c
// TODO:
// 1. Get count: ListView_GetItemCount(hList)
// 2. For each item, get text: ListView_GetItemText(...)
// 3. Write to CSV file
```

### Exercise 5: Alternate Row Colors

Display alternating row colors (like Excel):

```c
// TODO: Handle NM_CUSTOMDRAW
case NM_CUSTOMDRAW:
{
    LPNMLVCUSTOMDRAW pcd = (LPNMLVCUSTOMDRAW)lParam;
    
    if (pcd->nmcd.dwDrawStage == CDDS_PREPAINT)
        return CDRF_NOTIFYITEMDRAW;
    
    if (pcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
    {
        // Set background color based on row index
        if (pcd->nmcd.dwItemSpec % 2 == 0)
            pcd->clrTextBk = RGB(240, 240, 240);
        
        return CDRF_NEWFONT;
    }
    
    return CDRF_DODEFAULT;
}
```

## Column Sorting (NEW!)

> **💡 Professional Feature**
>
> Click column headers to sort! Click again to toggle between ascending/descending.

### The Sort Parameters Structure

```c
typedef struct {
    Host* hosts;          // Pointer to host array
    int hostCount;        // Number of hosts
    int sortColumn;       // Which column to sort by (1=Hostname, 2=Description, 3=LastConnected)
    BOOL sortAscending;   // TRUE = ascending, FALSE = descending
} SortParams;

// Global variable to track sort state
static SortParams sortParams = {NULL, 0, 1, TRUE};
```

### Handling Column Header Clicks

```c
case LVN_COLUMNCLICK:
{
    // User clicked a column header
    LPNMLISTVIEW pnmlv = (LPNMLISTVIEW)lParam;
    HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
    
    int clickedColumn = pnmlv->iSubItem;
    
    // Only sort if clicking on actual columns (not dummy column 0)
    if (clickedColumn == 1 || clickedColumn == 2 || clickedColumn == 3)
    {
        // If clicking the same column, toggle sort direction
        if (sortParams.sortColumn == clickedColumn)
        {
            sortParams.sortAscending = !sortParams.sortAscending;
        }
        else
        {
            // New column - default to ascending
            sortParams.sortColumn = clickedColumn;
            sortParams.sortAscending = TRUE;
        }
        
        // Update sort params with current host data
        sortParams.hosts = hosts;
        sortParams.hostCount = hostCount;
        
        // Perform the sort
        ListView_SortItems(hList, CompareListViewItems, (LPARAM)&sortParams);
    }
    return TRUE;
}
```

### The Comparison Function

```c
int CALLBACK CompareListViewItems(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
    SortParams* params = (SortParams*)lParamSort;
    
    // lParam1 and lParam2 are the original array indices (from lParam!)
    int index1 = (int)lParam1;
    int index2 = (int)lParam2;
    
    // Bounds check
    if (index1 < 0 || index1 >= params->hostCount || 
        index2 < 0 || index2 >= params->hostCount)
    {
        return 0;
    }
    
    // Get the hosts to compare
    Host* host1 = &params->hosts[index1];
    Host* host2 = &params->hosts[index2];
    
    int result = 0;
    
    // Compare based on sort column
    if (params->sortColumn == 1)
    {
        // Sort by hostname
        result = _wcsicmp(host1->hostname, host2->hostname);
    }
    else if (params->sortColumn == 2)
    {
        // Sort by description
        result = _wcsicmp(host1->description, host2->description);
    }
    else if (params->sortColumn == 3)
    {
        // Sort by last connected timestamp
        // Special handling: "Never" should sort to the end
        BOOL host1Never = (_wcsicmp(host1->lastConnected, L"Never") == 0);
        BOOL host2Never = (_wcsicmp(host2->lastConnected, L"Never") == 0);
        
        if (host1Never && host2Never)
        {
            result = 0;  // Both "Never" - equal
        }
        else if (host1Never)
        {
            result = 1;  // host1 is "Never" - sorts later
        }
        else if (host2Never)
        {
            result = -1;  // host2 is "Never" - host1 sorts earlier
        }
        else
        {
            // Both have dates - ISO format sorts correctly with string compare!
            result = wcscmp(host1->lastConnected, host2->lastConnected);
        }
    }
    
    // Reverse for descending sort
    if (!params->sortAscending)
    {
        result = -result;
    }
    
    return result;
}
```

**Why this works:**
- `ListView_SortItems()` calls our comparison function for each pair of items
- `lParam1` and `lParam2` are the `lParam` values we stored (original array indices)
- We compare the actual Host data, not the ListView display text
- ISO 8601 timestamps sort correctly with simple string comparison!

**Sorting examples:**

```
Hostname ascending:
  dev-server
  prod-server
  test-server

Last Connected descending (most recent first):
  2025-11-07 14:30:00  (today)
  2025-11-06 09:15:00  (yesterday)
  2025-10-15 16:45:00  (weeks ago)
  Never                (never connected)
```

## Real-Time Search/Filter (NEW!)

> **⚡ User Experience**
>
> As users type in the search box, the list updates instantly - no "Search" button needed!

### Setting Up the Search Box

```c
case IDC_EDIT_SEARCH:
{
    // Handle search text changes
    if (HIWORD(wParam) == EN_CHANGE)
    {
        HWND hList = GetDlgItem(hwnd, IDC_LIST_SERVERS);
        HWND hSearch = GetDlgItem(hwnd, IDC_EDIT_SEARCH);
        
        // Get search text
        wchar_t searchText[256] = {0};
        GetWindowTextW(hSearch, searchText, 256);
        
        // Refresh list with filter
        int displayedCount = RefreshHostListView(hList, hosts, hostCount, searchText);
        
        // Update status label
        UpdateHostCountLabel(hwnd, IDC_STATIC_HOST_COUNT, displayedCount, hostCount);
    }
    return TRUE;
}
```

### Enhanced RefreshHostListView with Filtering

The complete implementation (from earlier) now includes:

```c
int RefreshHostListView(HWND hList, Host* hosts, int hostCount, const wchar_t* searchText)
{
    ListView_DeleteAllItems(hList);
    
    if (hosts == NULL || hostCount == 0)
        return 0;
    
    // Check if we have a search filter
    BOOL hasFilter = (searchText != NULL && wcslen(searchText) > 0);
    
    // Convert search text to lowercase for case-insensitive search
    wchar_t searchLower[256] = {0};
    if (hasFilter)
    {
        wcsncpy_s(searchLower, 256, searchText, _TRUNCATE);
        _wcslwr_s(searchLower, 256);  // Convert to lowercase
    }
    
    // Add hosts to list, filtering if necessary
    int displayIndex = 0;
    for (int i = 0; i < hostCount; i++)
    {
        // If filtering, check if hostname or description matches
        if (hasFilter)
        {
            wchar_t hostnameLower[256] = {0};
            wchar_t descriptionLower[256] = {0};
            
            wcsncpy_s(hostnameLower, 256, hosts[i].hostname, _TRUNCATE);
            _wcslwr_s(hostnameLower, 256);
            
            wcsncpy_s(descriptionLower, 256, hosts[i].description, _TRUNCATE);
            _wcslwr_s(descriptionLower, 256);
            
            // Skip if neither hostname nor description contains the search text
            if (wcsstr(hostnameLower, searchLower) == NULL && 
                wcsstr(descriptionLower, searchLower) == NULL)
            {
                continue;  // Skip this host
            }
        }
        
        // Insert the item (filtering passed or no filter)
        LVITEMW item = {0};
        item.mask = LVIF_TEXT | LVIF_PARAM;
        item.iItem = displayIndex;
        item.iSubItem = 0;
        item.pszText = L"";
        item.lParam = (LPARAM)i;  // Store original index!
        ListView_InsertItem(hList, &item);
        
        ListView_SetItemText(hList, displayIndex, 1, hosts[i].hostname);
        ListView_SetItemText(hList, displayIndex, 2, hosts[i].description);
        ListView_SetItemText(hList, displayIndex, 3, hosts[i].lastConnected);
        
        displayIndex++;
    }
    
    return displayIndex;  // Number of items displayed
}
```

**Key points:**
- Case-insensitive matching with `_wcslwr_s()`
- Searches both hostname AND description
- Substring matching with `wcsstr()`
- Returns count of displayed items for status label

## Host Count Status Label (NEW!)

> **📊 User Feedback**
>
> Show "5 hosts" normally, or "Showing 2 of 5 hosts" when filtering.

```c
void UpdateHostCountLabel(HWND hwndDialog, int labelId, int displayedCount, int totalCount)
{
    wchar_t statusText[128];
    
    if (displayedCount == totalCount)
    {
        // No filtering - show simple count
        swprintf_s(statusText, 128, L"%d host%s", 
                  totalCount, (totalCount == 1 ? L"" : L"s"));
    }
    else
    {
        // Filtering active - show "X of Y hosts"
        swprintf_s(statusText, 128, L"Showing %d of %d host%s", 
                  displayedCount, totalCount, (totalCount == 1 ? L"" : L"s"));
    }
    
    SetDlgItemTextW(hwndDialog, labelId, statusText);
}
```

**Examples:**
```
No filter:
  "5 hosts"
  "1 host"   (singular)
  "0 hosts"

With filter "prod":
  "Showing 2 of 5 hosts"
  "Showing 1 of 5 host"
  "Showing 0 of 5 hosts"
```

## Edit Global Credentials Button (NEW!)

> **🔑 Quick Credential Swaps**
>
> Give users a way to update their default credentials without restarting the app.

```c
case IDC_BTN_EDIT_CREDS:
{
    ShowWindow(hwnd, SW_HIDE);

    if (g_hwndLoginDialog == NULL)
    {
        // Pass 1 → edit mode. Login dialog skips the startup countdown.
        DialogBoxParam(g_hInstance, MAKEINTRESOURCE(IDD_LOGIN), hwnd, LoginDialogProc, 1);
    }
    else
    {
        SetForegroundWindow(g_hwndLoginDialog);
    }

    ShowWindow(hwnd, SW_SHOW);
    SetForegroundWindow(hwnd);
    return TRUE;
}
```

**How it works:**
- The main dialog hides while the login dialog is on screen, preventing overlapping modals.
- Passing `1` as the dialog parameter switches the login dialog into **edit mode**—no countdown timer, just a simple "✓ Credentials saved" status message.
- When the login dialog closes, the main dialog pops back to the foreground so the user can keep working.
- Pressing **Enter** inside the login dialog still triggers the default `Save & Continue` button for quick keyboard workflows.

## Summary

You've learned:
- ✅ Creating and configuring ListView controls
- ✅ Adding columns (with the dummy column trick for centering)
- ✅ **NEW: Three-column layout** with Last Connected timestamp
- ✅ Populating ListViews with data
- ✅ **NEW: Using lParam** to preserve original indices during filtering
- ✅ Handling double-click to connect
- ✅ **NEW: Column sorting** with click-to-sort headers
- ✅ **NEW: Real-time search/filter** with instant updates
- ✅ **NEW: Dynamic status labels** showing filter state
- ✅ Common ListView pitfalls and solutions

**You now have:**
- A fully functional host list display with sorting
- Real-time search/filter capability  
- Professional user feedback (status labels)
- Double-click to connect
- Column sorting (click headers to sort)
- Professional-looking data presentation

**Key techniques:**
- **lParam trick**: Store original array index to handle filtering correctly
- **Comparison callback**: Custom sorting logic with `ListView_SortItems()`
- **EN_CHANGE**: Real-time filtering as user types
- **Case-insensitive search**: `_wcslwr_s()` for user-friendly matching
- **ISO 8601 sorting**: Timestamps sort correctly with string comparison

**Next chapter:** Implementing RDP connection logic to actually connect to servers!



# Chapter 23: RDP Connection Logic

> **📝 What's New in WinRDP v1.2.0**
> 
> This chapter has been updated to reflect new features:
> - ✨ Persistent RDP files in AppData\Roaming (eliminates security warnings!)
> - ✨ Filename sanitization for safe file creation
> - ✨ Enhanced RDP settings (~40 optimized parameters)
> - ✨ Integration with UpdateLastConnected() timestamp tracking
> - ✨ Two-tier credential lookup with per-host support

> **🔗 Related Chapters**
> 
> - Chapter 19: UpdateLastConnected() called after successful connection
> - Chapter 20: Two-tier credential system (per-host → global)
> - Chapter 22: How hosts are selected from ListView

**What You'll Learn:**
- Creating RDP configuration files programmatically
- **NEW: Persistent file storage** in AppData\Roaming (prevents security warnings)
- **NEW: Filename sanitization** for hostname-to-filename conversion
- Understanding the RDP file format
- **NEW: Enhanced RDP settings** for optimal user experience
- Launching external applications with ShellExecuteW
- Implementing credential strategies (per-host vs. global)
- **NEW: Integrating with timestamp tracking** for connection history

**Why It Matters:**
This is the moment everything comes together! You've built the UI, stored credentials securely, and managed host lists. Now you'll implement the core functionality: launching RDP connections to servers. This chapter shows how to integrate with external applications (mstsc.exe), eliminate security warnings with persistent files, and track connection history.

## Introduction

Windows Remote Desktop Protocol (RDP) uses `.rdp` files to configure connections. These are simple text files with key-value pairs that tell `mstsc.exe` (Microsoft Terminal Services Client) how to connect to a server.

In this chapter, we'll:
1. Generate RDP configuration files
2. Implement a two-tier credential strategy (per-host, then global)
3. Launch mstsc.exe with our configuration
4. Clean up temporary files

## The RDP File Format

RDP files are plain text files with a simple format:

```
setting_name:type:value

Types:
  i: = integer
  s: = string
  b: = binary (base64 encoded)
```

### Example RDP File

```rdp
screen mode id:i:2
full address:s:server01.company.com
username:s:administrator
authentication level:i:0
redirectclipboard:i:1
redirectprinters:i:1
session bpp:i:32
```

### Common RDP Settings

```c
// Display Settings
screen mode id:i:2              // 2 = full screen, 1 = windowed
desktopwidth:i:1920             // Screen width
desktopheight:i:1080            // Screen height
session bpp:i:32                // Color depth (bits per pixel)

// Connection Settings
full address:s:hostname         // Server to connect to
username:s:username             // Username (optional)

// Authentication
authentication level:i:0        // 0 = Don't require server auth
prompt for credentials:i:0      // 0 = Use saved credentials

// Redirection (Sharing with remote PC)
redirectclipboard:i:1           // 1 = Share clipboard
redirectprinters:i:1            // 1 = Share printers
redirectsmartcards:i:1          // 1 = Share smart cards
redirectcomports:i:0            // 0 = Don't share COM ports

// Performance
compression:i:1                 // Enable compression
connection type:i:7             // 7 = Auto-detect
networkautodetect:i:1           // Enable network auto-detection

// Experience
disable wallpaper:i:0           // 0 = Show wallpaper
allow font smoothing:i:1        // 1 = Enable font smoothing
allow desktop composition:i:1   // 1 = Enable Aero effects
```

## Creating RDP Files

Let's implement the function that creates RDP configuration files:

```c
BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   wchar_t* outputPath, size_t outputLen)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t tempPath[MAX_PATH];
    wchar_t rdpPath[MAX_PATH];
    
    // Get Windows temp directory
    if (GetTempPathW(MAX_PATH, tempPath) == 0)
    {
        return FALSE;
    }
    
    // Create unique filename with timestamp
    time_t now = time(NULL);
    swprintf_s(rdpPath, MAX_PATH, L"%sWinRDP_%lld.rdp", tempPath, (long long)now);
    
    // Open file for writing (UTF-8 encoding)
    err = _wfopen_s(&file, rdpPath, L"w, ccs=UTF-8");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write RDP configuration
    fwprintf(file, L"screen mode id:i:2\n");
    fwprintf(file, L"desktopwidth:i:1920\n");
    fwprintf(file, L"desktopheight:i:1080\n");
    fwprintf(file, L"session bpp:i:32\n");
    fwprintf(file, L"full address:s:%ls\n", hostname);
    fwprintf(file, L"authentication level:i:0\n");
    fwprintf(file, L"prompt for credentials:i:0\n");
    fwprintf(file, L"redirectclipboard:i:1\n");
    fwprintf(file, L"redirectprinters:i:1\n");
    
    // Add username if provided
    if (username != NULL && wcslen(username) > 0)
    {
        fwprintf(file, L"username:s:%ls\n", username);
    }
    
    fclose(file);
    
    // Return path to caller
    wcsncpy_s(outputPath, outputLen, rdpPath, _TRUNCATE);
    
    return TRUE;
}
```

> **⚠️ PROBLEM: Temp Files Show Security Warning!**
>
> The above code creates temp files which causes Windows to show this warning **every time**:
> 
> ```
> ┌─────────────────────────────────────────┐
> │ Remote Desktop Connection               │
> ├─────────────────────────────────────────┤
> │ Do you want to connect?                 │
> │                                         │
> │ Publisher: Unknown                      │
> │ From: C:\Users\...\Temp\WinRDP_123.rdp │
> │                                         │
> │ [x] Don't ask me again for...          │
> │                                         │
> │      [Connect]    [Cancel]              │
> └─────────────────────────────────────────┘
> ```
>
> **Annoying!** Users have to click this every single time they connect.

## Persistent RDP Files (NEW!) - Eliminating Security Warnings

> **💡 Solution**
>
> Store RDP files in a **persistent location** (AppData\Roaming) with **consistent filenames**.
> Windows remembers "trusted" locations and stops showing the warning!

### GetRDPStoragePath - Create Persistent Directory

```c
static BOOL GetRDPStoragePath(wchar_t* path, size_t pathLen)
{
    wchar_t appDataPath[MAX_PATH];
    
    // Get the Roaming AppData directory
    // Typically: C:\Users\[Username]\AppData\Roaming
    if (FAILED(SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, appDataPath)))
    {
        return FALSE;
    }
    
    // Build path: AppData\Roaming\WinRDP\Connections
    swprintf_s(path, pathLen, L"%s\\WinRDP\\Connections", appDataPath);
    
    // Create the directory if it doesn't exist
    wchar_t winrdpPath[MAX_PATH];
    swprintf_s(winrdpPath, MAX_PATH, L"%s\\WinRDP", appDataPath);
    CreateDirectoryW(winrdpPath, NULL);      // Create WinRDP folder
    CreateDirectoryW(path, NULL);             // Create Connections subfolder
    
    return TRUE;
}
```

**Why AppData\Roaming?**
- ✅ User-specific (no admin rights needed)
- ✅ Persistent across reboots
- ✅ Roams with user profile (in domain environments)
- ✅ Standard location for application data
- ✅ Not shown in temp file warnings

**SHGetFolderPathW parameters:**
```c
CSIDL_APPDATA      // AppData\Roaming
CSIDL_LOCAL_APPDATA // AppData\Local
CSIDL_DESKTOP      // Desktop
CSIDL_PERSONAL     // Documents (My Documents)
```

## Filename Sanitization (NEW!)

> **⚠️ Problem: Hostnames Can Contain Invalid Characters!**
>
> ```c
> Hostname: "server01:3389"      // Contains : (invalid in Windows filenames)
> Hostname: "192.168.1.100/vm"   // Contains / (invalid)
> Hostname: "dev\\test"          // Contains \ (invalid)
> ```
>
> These would crash or fail when used as filenames!

```c
static void SanitizeHostnameForFilename(const wchar_t* hostname, 
                                        wchar_t* output, size_t outputLen)
{
    size_t i = 0;
    size_t maxLen = outputLen - 1;
    
    while (hostname[i] != L'\0' && i < maxLen)
    {
        wchar_t c = hostname[i];
        
        // Replace invalid filename characters with underscores
        // Invalid in Windows: < > : " / \ | ? *
        if (c == L'<' || c == L'>' || c == L':' || c == L'"' ||
            c == L'/' || c == L'\\' || c == L'|' || c == L'?' || c == L'*')
        {
            output[i] = L'_';
        }
        else
        {
            output[i] = c;
        }
        i++;
    }
    output[i] = L'\0';
}
```

**Examples:**
```c
"server01:3389"        → "server01_3389.rdp"
"192.168.1.100/vm"     → "192.168.1.100_vm.rdp"
"prod\\app-server"     → "prod__app-server.rdp"
"test?debug=true"      → "test_debug=true.rdp"
```

## Updated CreateRDPFile with Persistent Storage (NEW!)

```c
BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   wchar_t* outputPath, size_t outputLen)
{
    FILE* file = NULL;
    errno_t err;
    wchar_t storagePath[MAX_PATH];
    wchar_t rdpPath[MAX_PATH];
    wchar_t sanitizedHost[MAX_PATH];
    
    // Get the persistent storage directory in AppData\Roaming
    if (!GetRDPStoragePath(storagePath, MAX_PATH))
    {
        return FALSE;
    }
    
    // Sanitize the hostname for use as a filename
    SanitizeHostnameForFilename(hostname, sanitizedHost, MAX_PATH);
    
    // Create a persistent filename based on the hostname
    // Same hostname → same file → no security warning!
    swprintf_s(rdpPath, MAX_PATH, L"%s\\%s.rdp", storagePath, sanitizedHost);
    
    // Open file for writing (overwrites existing)
    err = _wfopen_s(&file, rdpPath, L"w, ccs=UTF-8");
    if (err != 0 || file == NULL)
    {
        return FALSE;
    }
    
    // Write comprehensive RDP configuration (40+ settings!)
    fwprintf(file, L"screen mode id:i:2\n");
    fwprintf(file, L"use multimon:i:0\n");
    fwprintf(file, L"desktopwidth:i:1920\n");
    fwprintf(file, L"desktopheight:i:1080\n");
    fwprintf(file, L"session bpp:i:32\n");
    fwprintf(file, L"full address:s:%ls\n", hostname);
    fwprintf(file, L"compression:i:1\n");
    fwprintf(file, L"keyboardhook:i:2\n");
    fwprintf(file, L"audiocapturemode:i:0\n");
    fwprintf(file, L"videoplaybackmode:i:1\n");
    fwprintf(file, L"connection type:i:7\n");
    fwprintf(file, L"networkautodetect:i:1\n");
    fwprintf(file, L"bandwidthautodetect:i:1\n");
    fwprintf(file, L"displayconnectionbar:i:1\n");
    fwprintf(file, L"enableworkspacereconnect:i:1\n");
    fwprintf(file, L"disable wallpaper:i:0\n");
    fwprintf(file, L"allow font smoothing:i:1\n");
    fwprintf(file, L"allow desktop composition:i:1\n");
    fwprintf(file, L"disable full window drag:i:0\n");
    fwprintf(file, L"disable menu anims:i:0\n");
    fwprintf(file, L"disable themes:i:0\n");
    fwprintf(file, L"disable cursor setting:i:0\n");
    fwprintf(file, L"bitmapcachepersistenable:i:1\n");
    fwprintf(file, L"audiomode:i:0\n");
    fwprintf(file, L"redirectprinters:i:1\n");
    fwprintf(file, L"redirectcomports:i:0\n");
    fwprintf(file, L"redirectsmartcards:i:1\n");
    fwprintf(file, L"redirectclipboard:i:1\n");
    fwprintf(file, L"redirectposdevices:i:0\n");
    fwprintf(file, L"autoreconnection enabled:i:1\n");
    fwprintf(file, L"authentication level:i:0\n");
    fwprintf(file, L"prompt for credentials:i:0\n");
    fwprintf(file, L"negotiate security layer:i:1\n");
    fwprintf(file, L"remoteapplicationmode:i:0\n");
    fwprintf(file, L"alternate shell:s:\n");
    fwprintf(file, L"shell working directory:s:\n");
    fwprintf(file, L"gatewayhostname:s:\n");
    fwprintf(file, L"gatewayusagemethod:i:4\n");
    fwprintf(file, L"gatewaycredentialssource:i:4\n");
    fwprintf(file, L"gatewayprofileusagemethod:i:0\n");
    fwprintf(file, L"promptcredentialonce:i:1\n");
    fwprintf(file, L"use redirection server name:i:0\n");
    
    // Add username if provided
    if (username != NULL && wcslen(username) > 0)
    {
        fwprintf(file, L"username:s:%ls\n", username);
    }
    
    fclose(file);
    
    // Return the path to the caller
    wcsncpy_s(outputPath, outputLen, rdpPath, _TRUNCATE);
    
    return TRUE;
}
```

**Benefits of Persistent Files:**
- ✅ **No security warning** after first connection
- ✅ **Better performance** (no file creation overhead each time)
- ✅ **User can edit** RDP files manually if needed
- ✅ **Settings persist** even if app is closed
- ✅ **One file per host** (organized, predictable)

**File locations:**
```
C:\Users\YourName\AppData\Roaming\WinRDP\Connections\
    ├── server01.company.com.rdp
    ├── 192.168.1.100.rdp
    ├── prod-db-server.rdp
    └── dev_test_3389.rdp
```

### Old Approach: GetTempPathW Function (For Reference)

```c
DWORD GetTempPathW(
    DWORD nBufferLength,   // Size of buffer
    LPWSTR lpBuffer        // Buffer to receive path
);

// Returns: Number of characters copied (excluding null terminator)
//          0 on failure

// Typical temp path: C:\Users\[Username]\AppData\Local\Temp\

wchar_t tempPath[MAX_PATH];
DWORD result = GetTempPathW(MAX_PATH, tempPath);
if (result > 0 && result < MAX_PATH)
{
    // Success - tempPath contains the temp directory
    // Example: L"C:\Users\John\AppData\Local\Temp\"
}
```

### Creating Unique Filenames

```c
// Use timestamp to avoid conflicts
time_t now = time(NULL);
swprintf_s(rdpPath, MAX_PATH, L"%sWinRDP_%lld.rdp", tempPath, (long long)now);

// Result: C:\Users\John\AppData\Local\Temp\WinRDP_1699564823.rdp

// Alternatively, use GetTempFileNameW for guaranteed unique names:
wchar_t uniquePath[MAX_PATH];
GetTempFileNameW(tempPath, L"RDP", 0, uniquePath);
// Creates: C:\Users\John\AppData\Local\Temp\RDP1234.tmp
```

### Writing UTF-8 Text Files

```c
// Open file with UTF-8 encoding
FILE* file;
_wfopen_s(&file, path, L"w, ccs=UTF-8");

// Write wide strings (automatically converted to UTF-8)
fwprintf(file, L"full address:s:%ls\n", hostname);

// Close
fclose(file);

// UTF-8 encoding ensures international characters work correctly
```

## The Two-Tier Credential Strategy

WinRDP uses a flexible credential system:

```
Connection Request
    ↓
Check for per-host credentials (hostname-specific)
    ↓
Found? → Use per-host credentials
    ↓
Not found? → Check for global credentials
    ↓
Found? → Use global credentials
    ↓
Not found? → Show error
```

### Implementation

```c
BOOL LaunchRDP(const wchar_t* hostname, const wchar_t* username, 
               const wchar_t* password)
{
    wchar_t rdpPath[MAX_PATH];
    wchar_t actualUsername[MAX_USERNAME_LEN];
    wchar_t actualPassword[MAX_PASSWORD_LEN];
    
    // Determine which credentials to use
    if (username == NULL || password == NULL)
    {
        // Step 1: Try per-host credentials
        if (LoadRDPCredentials(hostname, actualUsername, actualPassword))
        {
            // Per-host credentials found - use them
            // These are stored as "WinRDP:TERMSRV/hostname"
        }
        // Step 2: Fall back to global credentials
        else if (LoadCredentials(NULL, actualUsername, actualPassword))
        {
            // Global credentials found - use them
            // These are stored as "WinRDP:DefaultCredentials"
        }
        else
        {
            // No credentials available
            MessageBoxW(NULL, 
                       L"No credentials found. Please log in first.",
                       L"Error", MB_OK | MB_ICONERROR);
            return FALSE;
        }
    }
    else
    {
        // Explicit credentials provided - use them
        wcsncpy_s(actualUsername, MAX_USERNAME_LEN, username, _TRUNCATE);
        wcsncpy_s(actualPassword, MAX_PASSWORD_LEN, password, _TRUNCATE);
    }
    
    // Save credentials for RDP session
    // Windows RDP expects credentials in format: TERMSRV/hostname
    if (!SaveRDPCredentials(hostname, actualUsername, actualPassword))
    {
        MessageBoxW(NULL, L"Failed to save RDP credentials.", 
                   L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    // Create RDP file
    if (!CreateRDPFile(hostname, actualUsername, rdpPath, MAX_PATH))
    {
        MessageBoxW(NULL, L"Failed to create RDP file.", 
                   L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    // Launch mstsc.exe
    HINSTANCE result = ShellExecuteW(
        NULL,                   // No parent window
        L"open",                // Action: open
        L"mstsc.exe",           // Program: RDP client
        rdpPath,                // Parameter: path to RDP file
        NULL,                   // Working directory: default
        SW_SHOWNORMAL           // Show window normally
    );
    
    // Check for errors
    if ((INT_PTR)result <= 32)
    {
        wchar_t errorMsg[256];
        swprintf_s(errorMsg, 256, 
                  L"Failed to launch RDP client.\nError code: %d", 
                  (int)(INT_PTR)result);
        MessageBoxW(NULL, errorMsg, L"Error", MB_OK | MB_ICONERROR);
        
        // Clean up RDP file
        DeleteFileW(rdpPath);
        return FALSE;
    }
    
    // Give mstsc.exe time to read the file
    Sleep(1000);
    
    // Clean up temporary RDP file
    DeleteFileW(rdpPath);
    
    return TRUE;
}
```

### Why Save Credentials Again?

```c
// We already have credentials in Credential Manager as:
// "WinRDP:DefaultCredentials" or "WinRDP:TERMSRV/hostname"

// But we need to save them AGAIN as:
// "TERMSRV/hostname" (without "WinRDP:" prefix)

SaveRDPCredentials(hostname, username, password);

// Why? Because mstsc.exe expects credentials in a specific format:
// Target: TERMSRV/hostname
// This is how Windows RDP client looks up credentials
```

## LaunchRDP Function (NEW!) - Two-Tier Credentials + Connection Tracking

The heart of WinRDP is the `LaunchRDP()` function. It implements the two-tier credential system (per-host first, then global fallback) and integrates with connection timestamp tracking from Chapter 19.

```c
BOOL LaunchRDP(const wchar_t* hostname, const wchar_t* username, const wchar_t* password)
{
    wchar_t rdpPath[MAX_PATH];
    wchar_t finalUsername[CRED_MAX_USERNAME_LENGTH] = L"";
    wchar_t finalPassword[CRED_MAX_CREDENTIAL_BLOB_SIZE / sizeof(wchar_t)] = L"";
    
    // STEP 1: Resolve credentials using two-tier strategy
    if (username != NULL && wcslen(username) > 0)
    {
        // Use provided credentials
        wcsncpy_s(finalUsername, CRED_MAX_USERNAME_LENGTH, username, _TRUNCATE);
        if (password != NULL)
        {
            wcsncpy_s(finalPassword, CRED_MAX_CREDENTIAL_BLOB_SIZE / sizeof(wchar_t), 
                     password, _TRUNCATE);
        }
    }
    else
    {
        // Try per-host credentials first
        if (!LoadRDPCredentials(hostname, finalUsername, finalPassword))
        {
            // Fall back to global credentials
            LoadCredentials(NULL, finalUsername, finalPassword);
        }
        // If both fail, finalUsername/finalPassword remain empty
        // mstsc.exe will prompt the user for credentials
    }
    
    // STEP 2: Create persistent RDP file
    if (!CreateRDPFile(hostname, finalUsername, rdpPath, MAX_PATH))
    {
        MessageBoxW(NULL, L"Failed to create RDP file", L"Error", MB_ICONERROR);
        return FALSE;
    }
    
    // STEP 3: Launch mstsc.exe
    HINSTANCE result = ShellExecuteW(
        NULL,           // No parent window
        L"open",        // Open action
        L"mstsc.exe",   // Remote Desktop Connection executable
        rdpPath,        // RDP file as parameter
        NULL,           // No working directory
        SW_SHOWNORMAL   // Show window normally
    );
    
    // STEP 4: Check for errors
    if ((INT_PTR)result <= 32)
    {
        MessageBoxW(NULL, L"Failed to launch mstsc.exe", L"Error", MB_ICONERROR);
        return FALSE;
    }
    
    // Success! (Note: We DON'T delete the file - it's persistent)
    return TRUE;
}
```

**Credential Resolution Flow:**
```
┌─────────────────────────────────────────────────┐
│ LaunchRDP(hostname, username, password)         │
└────────────────┬────────────────────────────────┘
                 │
         ┌───────▼────────┐
         │ Credentials    │
         │ provided?      │
         └───┬────────┬───┘
             │        │
            YES       NO
             │        │
             │        ├──────────────────────┐
             │        │ Try per-host first   │
             │        │ LoadRDPCredentials() │
             │        └──────────┬───────────┘
             │                   │
             │              ┌────▼─────┐
             │              │ Found?   │
             │              └──┬───┬───┘
             │                 │   │
             │                YES  NO
             │                 │   │
             │                 │   ├──────────────────┐
             │                 │   │ Try global       │
             │                 │   │ LoadCredentials()│
             │                 │   └──────┬───────────┘
             │                 │          │
             └─────────────────┴──────────┘
                               │
                    ┌──────────▼───────────┐
                    │ CreateRDPFile()      │
                    │ ShellExecuteW()      │
                    └──────────────────────┘
```

## LaunchRDPWithDefaults (NEW!) - Connection Tracking Integration

This convenience function adds automatic connection timestamp updates:

```c
BOOL LaunchRDPWithDefaults(const wchar_t* hostname)
{
    // Launch using two-tier credential strategy
    if (LaunchRDP(hostname, NULL, NULL))
    {
        // Update the lastConnected timestamp (see Chapter 19)
        UpdateLastConnected(hostname);
        return TRUE;
    }
    return FALSE;
}
```

**Why separate function?**
- `LaunchRDP()` = low-level, doesn't modify data
- `LaunchRDPWithDefaults()` = high-level, updates timestamps, used by UI

**Usage in UI code (from Chapter 22):**
```c
case IDC_BTN_CONNECT:
{
    int selectedIndex = ListView_GetNextItem(hListView, -1, LVNI_SELECTED);
    if (selectedIndex != -1)
    {
        // Get hostname from ListView
        wchar_t hostname[256];
        ListView_GetItemText(hListView, selectedIndex, 0, hostname, 256);
        
        // Connect and update timestamp
        if (LaunchRDPWithDefaults(hostname))
        {
            // Refresh ListView to show new "Last Connected" time
            RefreshHostListView(hListView);
        }
    }
    break;
}
```

**Complete flow:**
```
User clicks "Connect" button
    ↓
LaunchRDPWithDefaults("server01.company.com")
    ↓
LaunchRDP() → Creates RDP file, launches mstsc.exe
    ↓
Success? → UpdateLastConnected() → Saves timestamp to CSV
    ↓
RefreshHostListView() → Shows "2025-01-17T14:30:25Z" in Last Connected column
```

## Launching External Applications with ShellExecuteW

`ShellExecuteW` is a powerful function for launching programs and opening files:

```c
HINSTANCE ShellExecuteW(
    HWND hwnd,               // Parent window (NULL = none)
    LPCWSTR lpOperation,     // Action: "open", "edit", "print", etc.
    LPCWSTR lpFile,          // File or program to execute
    LPCWSTR lpParameters,    // Command-line parameters
    LPCWSTR lpDirectory,     // Working directory (NULL = current)
    INT nShowCmd             // How to show the window
);

// Returns: Value > 32 on success, <= 32 on error
```

### ShellExecuteW Examples

```c
// 1. Launch a program
ShellExecuteW(NULL, L"open", L"notepad.exe", L"readme.txt", NULL, SW_SHOWNORMAL);

// 2. Open a file with default program
ShellExecuteW(NULL, L"open", L"document.pdf", NULL, NULL, SW_SHOWNORMAL);

// 3. Open a URL in browser
ShellExecuteW(NULL, L"open", L"https://www.example.com", NULL, NULL, SW_SHOWNORMAL);

// 4. Open Windows Explorer to a folder
ShellExecuteW(NULL, L"explore", L"C:\\Users", NULL, NULL, SW_SHOWNORMAL);

// 5. Print a file
ShellExecuteW(NULL, L"print", L"document.docx", NULL, NULL, SW_HIDE);
```

### Common lpOperation Values

```c
"open"     // Open file or program
"edit"     // Open file in editor
"explore"  // Open folder in Explorer
"find"     // Open search dialog
"print"    // Print file
NULL       // Use default action (usually "open")
```

### nShowCmd Values

```c
SW_HIDE            // Hidden
SW_SHOWNORMAL      // Normal window
SW_SHOWMINIMIZED   // Minimized
SW_SHOWMAXIMIZED   // Maximized
SW_SHOWNOACTIVATE  // Show without activating
```

### Error Codes

```c
// ShellExecuteW returns <= 32 on error
if ((INT_PTR)result <= 32)
{
    switch ((INT_PTR)result)
    {
        case 0:  // Out of memory
        case SE_ERR_FNF:  // File not found (2)
        case SE_ERR_PNF:  // Path not found (3)
        case SE_ERR_ACCESSDENIED:  // Access denied (5)
        case SE_ERR_OOM:  // Out of memory (8)
        case SE_ERR_NOASSOC:  // No association (31)
            // Handle error
            break;
    }
}
```

## Temporary File Management

When creating temporary files, always clean them up:

```c
wchar_t tempFile[MAX_PATH];

// 1. Create temp file
if (CreateRDPFile(hostname, username, tempFile, MAX_PATH))
{
    // 2. Use the file
    ShellExecuteW(NULL, L"open", L"mstsc.exe", tempFile, NULL, SW_SHOWNORMAL);
    
    // 3. Wait for application to read it
    Sleep(1000);  // 1 second should be enough
    
    // 4. Delete temp file
    DeleteFileW(tempFile);
}
```

### DeleteFileW Function

```c
BOOL DeleteFileW(
    LPCWSTR lpFileName  // File to delete
);

// Returns: TRUE on success, FALSE on failure

// Example:
if (!DeleteFileW(L"C:\\temp\\file.txt"))
{
    DWORD error = GetLastError();
    // File might be in use, locked, or doesn't exist
}
```

### Why Sleep Before Deleting?

```c
// Launch mstsc.exe
ShellExecuteW(NULL, L"open", L"mstsc.exe", rdpPath, NULL, SW_SHOWNORMAL);

// Wait 1 second
Sleep(1000);

// Now safe to delete
DeleteFileW(rdpPath);

// Why wait?
// ShellExecuteW returns BEFORE mstsc.exe finishes reading the RDP file
// If we delete immediately, mstsc.exe might not have opened the file yet
// 1 second is more than enough time for mstsc.exe to open and read the file
```

## Convenience Functions

Provide simple wrapper functions for common operations:

```c
// Connect using default credentials (two-tier strategy)
BOOL LaunchRDPWithDefaults(const wchar_t* hostname)
{
    return LaunchRDP(hostname, NULL, NULL);
}

// Connect with specific credentials
BOOL LaunchRDPWithCredentials(const wchar_t* hostname,
                              const wchar_t* username,
                              const wchar_t* password)
{
    return LaunchRDP(hostname, username, password);
}

// Quick connect (prompt for credentials if needed)
BOOL QuickConnect(const wchar_t* hostname)
{
    wchar_t user[256], pass[256];
    
    // Try to load credentials
    if (!LoadRDPCredentials(hostname, user, pass) &&
        !LoadCredentials(NULL, user, pass))
    {
        // No saved credentials - show dialog to get them
        if (!PromptForCredentials(user, 256, pass, 256))
        {
            return FALSE;  // User cancelled
        }
    }
    
    return LaunchRDP(hostname, user, pass);
}
```

## Complete rdp.h Header

```c
#ifndef RDP_H
#define RDP_H

#include <windows.h>

// Create RDP configuration file
BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   wchar_t* outputPath, size_t outputLen);

// Launch RDP connection
BOOL LaunchRDP(const wchar_t* hostname, const wchar_t* username, 
               const wchar_t* password);

// Convenience function: connect with default credentials
BOOL LaunchRDPWithDefaults(const wchar_t* hostname);

#endif // RDP_H
```

## Testing the RDP Module

Create a simple test program:

```c
#include <windows.h>
#include <stdio.h>
#include "rdp.h"
#include "credentials.h"

int main(void)
{
    // Initialize
    wprintf(L"RDP Module Test\n\n");
    
    // Test 1: Create RDP file
    wprintf(L"Test 1: Creating RDP file...\n");
    wchar_t rdpPath[MAX_PATH];
    if (CreateRDPFile(L"server01", L"admin", rdpPath, MAX_PATH))
    {
        wprintf(L"  Success! File created: %ls\n", rdpPath);
        DeleteFileW(rdpPath);
    }
    else
    {
        wprintf(L"  FAILED\n");
    }
    
    // Test 2: Save test credentials
    wprintf(L"\nTest 2: Saving test credentials...\n");
    if (SaveCredentials(NULL, L"testuser", L"testpass"))
    {
        wprintf(L"  Success!\n");
    }
    
    // Test 3: Launch RDP (will fail if server doesn't exist)
    wprintf(L"\nTest 3: Launching RDP connection...\n");
    wprintf(L"  (This will fail if 'server01' doesn't exist)\n");
    if (LaunchRDPWithDefaults(L"server01"))
    {
        wprintf(L"  RDP launched successfully!\n");
    }
    else
    {
        wprintf(L"  Launch failed (expected if server doesn't exist)\n");
    }
    
    // Cleanup
    DeleteCredentials(NULL);
    
    wprintf(L"\nTests complete. Press Enter to exit...\n");
    getchar();
    
    return 0;
}
```

## Practical Example: Quick Connect Dialog

A simple dialog for quick RDP connections:

```c
INT_PTR CALLBACK QuickConnectDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
            CenterWindow(hwnd);
            SetFocus(GetDlgItem(hwnd, IDC_EDIT_HOSTNAME));
            return FALSE;  // We set focus manually
        
        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                {
                    // Get hostname
                    wchar_t hostname[256];
                    GetDlgItemTextW(hwnd, IDC_EDIT_HOSTNAME, hostname, 256);
                    
                    if (wcslen(hostname) == 0)
                    {
                        MessageBoxW(hwnd, L"Please enter a hostname.", 
                                   L"Error", MB_OK | MB_ICONERROR);
                        return TRUE;
                    }
                    
                    // Connect
                    if (LaunchRDPWithDefaults(hostname))
                    {
                        EndDialog(hwnd, IDOK);
                    }
                    else
                    {
                        MessageBoxW(hwnd, L"Failed to connect.", 
                                   L"Error", MB_OK | MB_ICONERROR);
                    }
                    
                    return TRUE;
                }
                
                case IDCANCEL:
                    EndDialog(hwnd, IDCANCEL);
                    return TRUE;
            }
            break;
    }
    
    return FALSE;
}

// Usage:
DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_QUICK_CONNECT), 
         hwnd, QuickConnectDialogProc);
```

## Security Considerations

### 1. Clean Up Sensitive Data

```c
// Zero out password from memory after use
SecureZeroMemory(password, sizeof(password));

// SecureZeroMemory guarantees the compiler won't optimize away the zeroing
// (Unlike memset, which might be optimized away)
```

### 2. Temporary File Permissions

```c
// RDP files may contain sensitive information
// Windows temp directory is usually secure (user-only access)
// But for extra security, you could:

SECURITY_ATTRIBUTES sa = {0};
sa.nLength = sizeof(SECURITY_ATTRIBUTES);
sa.lpSecurityDescriptor = NULL;  // Use default (user-only)
sa.bInheritHandle = FALSE;

// Then use CreateFile with security attributes
// (More complex than _wfopen_s)
```

### 3. Validate Input

```c
// Always validate hostname
BOOL IsValidHostname(const wchar_t* hostname)
{
    if (hostname == NULL || wcslen(hostname) == 0)
        return FALSE;
    
    // Check for invalid characters
    if (wcspbrk(hostname, L"<>:\"/\\|?*") != NULL)
        return FALSE;
    
    // Check length
    if (wcslen(hostname) > 255)
        return FALSE;
    
    return TRUE;
}

// Use before launching RDP
if (!IsValidHostname(hostname))
{
    MessageBoxW(NULL, L"Invalid hostname.", L"Error", MB_OK);
    return FALSE;
}
```

## Common Issues and Solutions

### Issue 1: mstsc.exe Not Found

**Problem:**
```c
ShellExecuteW(NULL, L"open", L"mstsc.exe", ...);
// Error: File not found
```

**Solution:**
```c
// mstsc.exe should be in %SystemRoot%\System32
// Usually in PATH, but to be safe:

wchar_t mstscPath[MAX_PATH];
GetSystemDirectoryW(mstscPath, MAX_PATH);
wcscat_s(mstscPath, MAX_PATH, L"\\mstsc.exe");

// Now use full path
ShellExecuteW(NULL, L"open", mstscPath, ...);
```

### Issue 2: Credentials Not Working

**Problem:**
```c
// RDP prompts for credentials even though we saved them
```

**Solution:**
```c
// Ensure credentials are saved with correct target name:
// "TERMSRV/hostname" (not "WinRDP:TERMSRV/hostname")

SaveRDPCredentials(hostname, username, password);

// And ensure "prompt for credentials:i:0" in RDP file
fwprintf(file, L"prompt for credentials:i:0\n");
```

### Issue 3: Temp File Still Exists

**Problem:**
```c
// Temp RDP files accumulating in temp directory
```

**Solution:**
```c
// Ensure Sleep() is long enough
Sleep(1000);  // 1 second

// And always delete in all code paths
if (!DeleteFileW(rdpPath))
{
    // File might still be open - try again after a delay
    Sleep(500);
    DeleteFileW(rdpPath);
}
```

## Exercises

### Exercise 1: Custom Screen Resolution

Allow user to specify screen resolution:

```c
// TODO: Add parameters
BOOL CreateRDPFile(const wchar_t* hostname, const wchar_t* username,
                   int width, int height,  // Add these
                   wchar_t* outputPath, size_t outputLen)
{
    // ...
    fwprintf(file, L"desktopwidth:i:%d\n", width);
    fwprintf(file, L"desktopheight:i:%d\n", height);
    // ...
}
```

### Exercise 2: RDP File Presets

Create preset configurations (low bandwidth, high quality, etc.):

```c
// TODO: Implement
typedef enum {
    RDP_PRESET_LOW_BANDWIDTH,
    RDP_PRESET_HIGH_QUALITY,
    RDP_PRESET_BALANCED
} RDPPreset;

BOOL CreateRDPFileWithPreset(const wchar_t* hostname, 
                             const wchar_t* username,
                             RDPPreset preset,
                             wchar_t* outputPath, size_t outputLen);
```

### Exercise 3: Connection History

Log all RDP connections:

```c
// TODO: Implement
typedef struct {
    wchar_t hostname[256];
    wchar_t username[256];
    SYSTEMTIME timestamp;
} ConnectionLog;

void LogConnection(const wchar_t* hostname, const wchar_t* username);
BOOL GetConnectionHistory(ConnectionLog** logs, int* count);
```

### Exercise 4: Batch Connect

Connect to multiple servers sequentially:

```c
// TODO: Implement
BOOL BatchConnect(const wchar_t** hostnames, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (!LaunchRDPWithDefaults(hostnames[i]))
        {
            // Log error and continue
        }
        
        Sleep(2000);  // Wait between launches
    }
    
    return TRUE;
}
```

### Exercise 5: mstsc.exe Options

Add support for mstsc.exe command-line options:

```c
// mstsc.exe supports various command-line options:
// /v:hostname     - Connect to hostname
// /admin          - Connect to console session
// /f              - Full screen mode
// /w:width /h:height - Set resolution

// TODO: Modify LaunchRDP to accept flags:
typedef enum {
    RDP_FLAG_NONE = 0,
    RDP_FLAG_ADMIN = 1,
    RDP_FLAG_FULLSCREEN = 2,
    RDP_FLAG_CONSOLE = 4
} RDPFlags;

BOOL LaunchRDPWithFlags(const wchar_t* hostname, RDPFlags flags);
```

## Summary

You've learned:
- ✅ Creating RDP configuration files programmatically with 40+ settings
- ✅ Understanding the RDP file format and common parameters
- ✅ **NEW!** Implementing persistent RDP files in AppData\Roaming to eliminate security warnings
- ✅ **NEW!** Using GetRDPStoragePath() with SHGetFolderPathW(CSIDL_APPDATA) for proper directory creation
- ✅ **NEW!** Sanitizing hostnames for safe filename usage (SanitizeHostnameForFilename)
- ✅ Implementing two-tier credential strategy (per-host, then global) in LaunchRDP()
- ✅ **NEW!** Integrating connection timestamp tracking with LaunchRDPWithDefaults()
- ✅ Launching external applications with ShellExecuteW
- ✅ Process launching and error handling
- ✅ Security considerations for credential handling

**What's New in v1.2.0:**
- 🎯 **Persistent RDP files** → No more security warnings!
- 🎯 **Enhanced configuration** → 40+ RDP settings (up from ~10)
- 🎯 **Filename sanitization** → Handles invalid characters safely
- 🎯 **Connection tracking** → Automatic lastConnected timestamp updates
- 🎯 **AppData storage** → Organized in WinRDP\Connections folder

**You now have:**
- Complete RDP connection functionality with no security warnings
- Two-tier credential resolution (per-host → global → prompt)
- Automatic connection history tracking (integrates with Chapter 19)
- Persistent, organized RDP file storage (integrates with Chapter 20)
- Foundation for system tray quick-connect (coming in Chapter 24)

**🎉 Congratulations! WinRDP is now fully functional! 🎉**

Your application can:
- ✅ Store credentials securely
- ✅ Manage a list of RDP hosts
- ✅ Display hosts in a searchable list
- ✅ Connect to servers with one double-click
- ✅ Run in the system tray
- ✅ Respond to global hotkeys

**Next chapter:** We'll add system tray integration and polish the application with advanced features!

---

# What's Left to Implement in This Book

## Current Status: Chapters 1-23 Complete! ✅

### ✅ Completed Content

**Part I: C Fundamentals (Chapters 1-8) - 100% Complete**
- Chapter 1: Introduction to C Programming
- Chapter 2: Variables, Data Types, and Operators
- Chapter 3: Control Flow: Making Decisions
- Chapter 4: Functions: Building Blocks of Programs
- Chapter 5: Arrays: Working with Multiple Values
- Chapter 6: Pointers: The Heart of C
- Chapter 7: Strings: Text Processing in C
- Chapter 8: Structures: Organizing Related Data

**Part II: Advanced C Concepts (Chapters 9-12) - 100% Complete**
- Chapter 9: Dynamic Memory Management
- Chapter 10: File Input/Output
- Chapter 11: Function Pointers and Callbacks
- Chapter 12: Preprocessor and Multi-File Programs

**Part III: Windows Programming Basics (Chapters 13-16) - 100% Complete**
- Chapter 13: Introduction to Windows Programming
- Chapter 14: Your First Windows Application
- Chapter 15: Windows Message System
- Chapter 16: Dialog Boxes and Controls

**Part IV: Building WinRDP Core (Chapters 17-23) - 87.5% Complete**
- Chapter 17: Project Setup and Architecture ✅
- Chapter 18: Configuration and Utilities ✅
- Chapter 19: CSV File Management ✅
- Chapter 20: Windows Credential Manager ✅
- Chapter 21: Main Application Window ✅
- Chapter 22: ListView Control for Host Display ✅
- Chapter 23: RDP Connection Logic ✅

### 📝 To Be Written

**Part IV: Building WinRDP Core (Chapter 24)**

**Chapter 24: System Tray Integration**
- **What it will cover:**
  - Understanding the NOTIFYICONDATA structure
  - Adding icons to the system tray
  - Handling tray icon messages (WM_USER + custom messages)
  - Creating context menus for tray icons
  - Showing/hiding the main window
  - Implementing balloon notifications
  - Tray icon animation
  
- **Skills you'll learn:**
  - Shell_NotifyIcon API
  - Custom window messages
  - Context menu creation with CreatePopupMenu
  - Message handling for tray icons
  - Window visibility management

- **WinRDP files covered:**
  - Integration in `main.c` (existing code shows implementation)
  - System tray icon resource usage
  - Menu handling for Show/Hide/Exit options

---

**Part V: Advanced Features (Chapters 25-29)**

**Chapter 25: Registry Operations and Autostart**
- **What it will cover:**
  - Windows Registry basics and structure
  - RegCreateKeyEx and RegOpenKeyEx APIs
  - Reading registry values with RegQueryValueEx
  - Writing registry values with RegSetValueEx
  - Implementing "Start with Windows" functionality
  - Registry key: HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run
  - Checking if application is in autostart
  - Error handling for registry operations
  
- **Skills you'll learn:**
  - Windows Registry API
  - Application autostart implementation
  - Security considerations (HKCU vs HKLM)
  - Proper error handling for registry operations
  
- **WinRDP files covered:**
  - `registry.h` and `registry.c` implementation
  - CheckAutoStart and SetAutoStart functions
  - Integration with main window checkbox

**Chapter 26: Global Hotkeys**
- **What it will cover:**
  - RegisterHotKey and UnregisterHotKey APIs
  - Virtual key codes (VK_* constants)
  - Modifier keys (MOD_CONTROL, MOD_SHIFT, etc.)
  - Handling WM_HOTKEY messages
  - Implementing Ctrl+Shift+R hotkey
  - Bringing window to foreground with SetForegroundWindow
  - Hotkey conflicts and error handling
  
- **Skills you'll learn:**
  - System-wide keyboard shortcuts
  - Virtual key code usage
  - Window activation and focus management
  - Handling hotkey conflicts gracefully
  
- **WinRDP implementation:**
  - Hotkey registration in WM_INITDIALOG
  - WM_HOTKEY handler to show main window
  - Cleanup in WM_DESTROY

**Chapter 27: Dark Mode Support**
- **What it will cover:**
  - Detecting Windows dark mode from registry
  - DwmSetWindowAttribute for title bar theming
  - Custom control painting with WM_CTLCOLOR* messages
  - Creating custom brushes for dark backgrounds
  - Undocumented APIs (SetPreferredAppMode, AllowDarkModeForWindow)
  - Dynamic function loading with GetProcAddress
  - Theme-aware color schemes
  
- **Skills you'll learn:**
  - Registry-based theme detection
  - DWM (Desktop Window Manager) API
  - Custom control painting
  - Working with undocumented Windows APIs
  - Dynamic DLL function loading
  - Resource management (brushes, pens)
  
- **WinRDP files covered:**
  - `darkmode.h` and `darkmode.c` complete implementation
  - InitDarkMode and ApplyDarkModeToWindow functions
  - Custom message handlers for control painting
  - Color scheme management

**Chapter 28: Network Computer Discovery**
- **What it will cover:**
  - NetServerEnum API for network enumeration
  - Filtering by server type (workstations, servers, domain controllers)
  - SV_TYPE_* constants and their meanings
  - Progress dialogs with CreateDialogParam
  - Multi-threading considerations for network operations
  - Handling network timeouts
  - Unicode string handling in network APIs
  - Memory management with NetApiBufferFree
  
- **Skills you'll learn:**
  - Windows Network API (netapi32.dll)
  - Enumerating network resources
  - Threading and UI responsiveness
  - Progress indication for long operations
  - Working with network data structures (SERVER_INFO_101)
  
- **WinRDP files covered:**
  - `adscan.h` and `adscan.c` implementation
  - ScanNetworkComputers function
  - Dialog integration for scan results
  - Automatic host addition from scan

**Chapter 29: Building and Distribution**
- **What it will cover:**
  - Creating professional build scripts (build.bat)
  - Compiler flags and optimization
  - Resource compilation (windres)
  - Application manifests for UAC and DPI awareness
  - Icon resource creation
  - NSIS (Nullsoft Scriptable Install System) basics
  - Creating installer scripts (installer.nsi)
  - Install/uninstall functionality
  - Registry entries for uninstaller
  - Start menu shortcuts
  - Version information in executables
  - Code signing considerations (overview)
  
- **Skills you'll learn:**
  - Professional build automation
  - Windows resource management
  - Application manifest creation
  - Installer creation with NSIS
  - Distribution best practices
  - Version control in binaries
  
- **WinRDP files covered:**
  - `build.bat` script explanation
  - `build-installer.bat` usage
  - `installer.nsi` detailed walkthrough
  - `app.manifest` explanation
  - Resource file (resources.rc) compilation

---

**Appendices**

**Appendix A: Setting Up Your Development Environment**
- **What it will cover:**
  - Installing MinGW-w64 (GCC for Windows)
  - Installing Visual Studio Community Edition
  - Configuring PATH environment variable
  - Installing NSIS for installer creation
  - Recommended text editors (VS Code, Notepad++, Visual Studio)
  - Configuring syntax highlighting and IntelliSense
  - Installing Git for version control
  - Windows SDK considerations
  - Debugging tools (DebugView, Process Monitor)
  - Troubleshooting common setup issues

**Appendix B: Common Mistakes and How to Avoid Them**
- **What it will cover:**
  - Memory leaks and detection strategies
  - Pointer errors (null dereference, dangling pointers)
  - Buffer overflows and bounds checking
  - Forgetting to free allocated memory
  - Incorrect string handling (missing null terminators)
  - Resource leaks (handles, file descriptors)
  - Race conditions in message handling
  - Incorrect type casting
  - Integer overflow issues
  - Wide vs. narrow string mixing
  - Common Windows API pitfalls
  - Debugging strategies and tools
  - Best practices checklist

**Appendix C: Windows API Quick Reference**
- **What it will cover:**
  - Common Windows data types (HWND, LPARAM, WPARAM, etc.)
  - Frequently used Windows messages
  - Common control styles and flags
  - String functions (wide character versions)
  - File I/O functions
  - Memory allocation functions
  - Registry functions
  - Error handling macros and functions
  - Useful utility functions
  - Quick reference tables

**Appendix D: Further Learning Resources**
- **What it will cover:**
  - Recommended books:
    - "The C Programming Language" by Kernighan & Ritchie
    - "Expert C Programming" by Peter van der Linden
    - "Programming Windows" by Charles Petzold
    - "Windows System Programming" by Johnson M. Hart
  - Online resources:
    - Microsoft Docs (MSDN)
    - cppreference.com
    - Stack Overflow
    - theForger's Win32 Tutorial
  - Community forums and help:
    - r/C_Programming (Reddit)
    - Windows programming forums
    - Stack Overflow tags (c, winapi)
  - Video tutorials and courses
  - Practice project ideas
  - Open source projects to study
  - Next steps in your programming journey

---

## Summary of What You've Accomplished So Far

By completing Chapters 1-23, you have:

### **Mastered C Programming Fundamentals**
- ✅ Variables, data types, and operators
- ✅ Control flow and decision making
- ✅ Functions and modular programming
- ✅ Arrays and multi-dimensional data
- ✅ Pointers and memory addressing
- ✅ String manipulation in C
- ✅ Structures and data organization
- ✅ Dynamic memory management
- ✅ File input/output operations
- ✅ Function pointers and callbacks
- ✅ Preprocessor and multi-file programs

### **Learned Windows Programming**
- ✅ Win32 API architecture
- ✅ Message-driven programming model
- ✅ Creating windows and dialogs
- ✅ Using standard controls
- ✅ Resource files and compilation

### **Built a Complete Application**
- ✅ Professional project structure
- ✅ Configuration management
- ✅ Utility functions and helpers
- ✅ CSV file parsing and management
- ✅ Secure credential storage with Windows Credential Manager
- ✅ Main application window with dialogs
- ✅ ListView control for data display
- ✅ RDP connection functionality
- ✅ Searchable host list
- ✅ Double-click to connect
- ✅ Add/Edit/Delete host management

### **Your WinRDP Application Currently Has:**
- ✅ ~3,000 lines of production-quality C code
- ✅ 7 out of 8 modules fully implemented
- ✅ Complete core functionality (working RDP manager!)
- ✅ Professional error handling
- ✅ Unicode support throughout
- ✅ Secure credential storage
- ✅ User-friendly interface

---

## What Remains to Complete WinRDP

### **Chapter 24: System Tray Integration** (1 chapter)
Add the system tray icon so WinRDP can run minimized in the background with quick access.

### **Part V: Advanced Features** (5 chapters)
Polish the application with professional features:
- Autostart with Windows
- Global hotkey access
- Dark mode support
- Network computer scanning
- Professional installer

### **Appendices** (4 sections)
Reference material and additional resources for continued learning.

---

## Estimated Time to Complete

Based on the pattern established in the existing chapters:

- **Chapter 24**: ~2 hours to read and implement
- **Chapters 25-29**: ~8-10 hours total (2 hours per chapter)
- **Appendices**: Reference material, read as needed

**Total remaining**: ~12-14 hours of learning and implementation

---

# Chapter 24: System Tray Integration

**What You'll Learn:**
- Understanding the Windows system tray (notification area)
- Working with NOTIFYICONDATA structure
- Shell_NotifyIcon API for tray management
- Creating context menus for tray icons
- Handling tray icon messages and events
- Implementing show/hide window functionality

## Introduction

The Windows system tray (also called the notification area) is that small section in the bottom-right corner of your screen where icons for background applications appear. Adding system tray support transforms WinRDP from a simple window application into a professional tool that can run in the background and be accessed instantly when needed.

In this chapter, we'll implement full system tray integration, allowing users to:
- Minimize WinRDP to the system tray
- Right-click the tray icon for a context menu
- Restore the window by clicking the icon
- Exit the application from the tray menu

## Understanding the System Tray

### What Is the System Tray?

The system tray is perfect for applications that:
- Run in the background
- Don't need constant user attention
- Provide quick access when needed
- Show status or notifications

Common examples: antivirus software, cloud sync apps, volume control, network status.

### Windows API for System Tray

Windows provides the **Shell_NotifyIcon** function to interact with the system tray. This function can:
- Add an icon to the tray
- Remove an icon from the tray
- Modify an existing icon
- Display balloon notifications (modern Windows shows toast notifications)

## The NOTIFYICONDATA Structure

The core of system tray programming is the `NOTIFYICONDATA` structure:

```c
typedef struct _NOTIFYICONDATA {
    DWORD cbSize;              // Size of this structure
    HWND hWnd;                 // Window to receive messages
    UINT uID;                  // Icon identifier
    UINT uFlags;               // Flags indicating which fields are valid
    UINT uCallbackMessage;     // Message sent to hWnd
    HICON hIcon;               // Icon handle
    WCHAR szTip[128];          // Tooltip text
    DWORD dwState;             // State flags
    DWORD dwStateMask;         // State mask
    WCHAR szInfo[256];         // Balloon notification text
    UINT uTimeout;             // Balloon notification timeout
    WCHAR szInfoTitle[64];     // Balloon notification title
    DWORD dwInfoFlags;         // Balloon notification flags
} NOTIFYICONDATA;
```

**Key Fields:**
- `cbSize`: Always set to `sizeof(NOTIFYICONDATA)`
- `hWnd`: Your window that will receive tray icon messages
- `uID`: Unique ID for this tray icon (use a constant like `ID_TRAYICON`)
- `uFlags`: Combination of flags (NIF_ICON, NIF_MESSAGE, NIF_TIP, etc.)
- `uCallbackMessage`: Custom message ID (like `WM_TRAYICON`)
- `hIcon`: The icon to display
- `szTip`: Tooltip shown when hovering over icon

## Implementing System Tray Support

### Step 1: Define Constants

Add these to your `resource.h`:

```c
// Tray icon
#define ID_TRAYICON     1001
#define WM_TRAYICON     (WM_USER + 1)

// Tray menu items
#define IDM_OPEN        2001
#define IDM_EXIT        2002
#define IDM_ABOUT       2003
```

### Step 2: Create the InitSystemTray Function

```c
// main.c
BOOL InitSystemTray(HWND hwnd)
{
    NOTIFYICONDATA nid = {0};
    
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    nid.uCallbackMessage = WM_TRAYICON;
    
    // Load the application icon
    nid.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_APPICON));
    if (nid.hIcon == NULL) {
        nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // Fallback to default icon
    }
    
    // Set tooltip text
    wcscpy_s(nid.szTip, sizeof(nid.szTip) / sizeof(WCHAR), L"WinRDP - RDP Connection Manager");
    
    // Add icon to system tray
    if (!Shell_NotifyIcon(NIM_ADD, &nid)) {
        MessageBox(hwnd, L"Failed to add system tray icon", L"Error", MB_OK | MB_ICONERROR);
        return FALSE;
    }
    
    return TRUE;
}
```

**What This Does:**
1. Creates a `NOTIFYICONDATA` structure
2. Sets required fields (size, window handle, icon ID)
3. Specifies flags: NIF_ICON (has icon), NIF_MESSAGE (sends messages), NIF_TIP (has tooltip)
4. Sets custom message `WM_TRAYICON` to receive tray events
5. Loads application icon (or uses default)
6. Sets tooltip text
7. Calls `Shell_NotifyIcon` with `NIM_ADD` to add icon to tray

### Step 3: Handle Tray Icon Messages

Add to your `WndProc`:

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            // Initialize system tray icon
            if (!InitSystemTray(hwnd)) {
                return -1;  // Fail window creation
            }
            return 0;
        }
        
        case WM_TRAYICON:
        {
            // Handle tray icon events
            switch (LOWORD(lParam))
            {
                case WM_LBUTTONDOWN:
                case WM_LBUTTONDBLCLK:
                {
                    // Left click or double-click - show main dialog
                    ShowMainDialog(hwnd);
                    break;
                }
                
                case WM_RBUTTONDOWN:
                case WM_CONTEXTMENU:
                {
                    // Right click - show context menu
                    ShowTrayMenu(hwnd);
                    break;
                }
            }
            return 0;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDM_OPEN:
                    ShowMainDialog(hwnd);
                    break;
                    
                case IDM_ABOUT:
                    ShowAboutDialog(hwnd);
                    break;
                    
                case IDM_EXIT:
                    PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break;
            }
            return 0;
        }
        
        case WM_DESTROY:
        {
            // Remove tray icon before exiting
            NOTIFYICONDATA nid = {0};
            nid.cbSize = sizeof(NOTIFYICONDATA);
            nid.hWnd = hwnd;
            nid.uID = ID_TRAYICON;
            Shell_NotifyIcon(NIM_DELETE, &nid);
            
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

**Understanding the Message Handling:**

1. **WM_CREATE**: Initialize tray icon when window is created
2. **WM_TRAYICON**: Custom message sent when user interacts with tray icon
   - `LOWORD(lParam)` contains the mouse message (WM_LBUTTONDOWN, WM_RBUTTONDOWN, etc.)
3. **WM_COMMAND**: Handle menu item selections
4. **WM_DESTROY**: Remove tray icon before application exits

### Step 4: Create the Context Menu

```c
void ShowContextMenu(HWND hwnd)
{
    POINT pt;
    GetCursorPos(&pt);

    HMENU hMenu = CreatePopupMenu();
    if (hMenu == NULL)
        return;

    Host* recentHosts = NULL;
    int recentCount = 0;

    if (GetRecentHosts(&recentHosts, &recentCount, 5) && recentCount > 0)
    {
        AppendMenuW(hMenu, MF_STRING | MF_GRAYED, 0, L"Recent Connections:");

        for (int i = 0; i < recentCount; i++)
        {
            wchar_t menuText[256];
            swprintf_s(menuText, 256, L"%s — %s",
                       recentHosts[i].hostname,
                       recentHosts[i].description[0] ? recentHosts[i].description : L"No description");

            AppendMenuW(hMenu, MF_STRING, IDM_RECENT_START + i, menuText);
        }

        AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
    }

    AppendMenuW(hMenu, MF_STRING, IDM_OPEN, L"Open");
    AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);

    UINT autostartFlags = MF_STRING;
    if (IsAutostartEnabled())
    {
        autostartFlags |= MF_CHECKED;
    }
    AppendMenuW(hMenu, autostartFlags, IDM_ABOUT, L"Start with Windows");

    AppendMenuW(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenuW(hMenu, MF_STRING, IDM_ABOUT_DIALOG, L"About");
    AppendMenuW(hMenu, MF_STRING, IDM_EXIT, L"Exit");

    SetMenuDefaultItem(hMenu, IDM_OPEN, FALSE);
    SetForegroundWindow(hwnd);

    TrackPopupMenu(hMenu, TPM_BOTTOMALIGN | TPM_LEFTALIGN,
                   pt.x, pt.y, 0, hwnd, NULL);

    DestroyMenu(hMenu);
    PostMessage(hwnd, WM_NULL, 0, 0);

    if (recentHosts != NULL)
    {
        FreeHosts(recentHosts, recentCount);
    }
}
```

**Key Points:**

- Recent connections appear **at the top** of the menu for one-click access
- `IDM_RECENT_START + i` maps each menu item back to the host entry when the user clicks it
- The autostart item doubles as a checkbox (`MF_CHECKED`) so users can see its current state
- `SetMenuDefaultItem` keeps **Open** bold, matching standard Windows UX
- `FreeHosts` cleans up the temporary array allocated by `GetRecentHosts`
- `SetForegroundWindow` / `PostMessage(WM_NULL)` remain necessary Windows quirks for reliable popup menus

### Step 5: Show/Hide Window Functions

```c
// Global to track if main dialog is open
static HWND g_hwndMainDialog = NULL;

void ShowMainDialog(HWND hwndParent)
{
    // If dialog already exists, just bring it to front
    if (g_hwndMainDialog != NULL && IsWindow(g_hwndMainDialog)) {
        SetForegroundWindow(g_hwndMainDialog);
        return;
    }
    
    // Check if credentials exist
    wchar_t username[256], password[256];
    if (!LoadCredentials(NULL, username, sizeof(username)/sizeof(wchar_t),
                         password, sizeof(password)/sizeof(wchar_t))) {
        // No credentials - show login dialog first
        DialogBox(GetModuleHandle(NULL), 
                  MAKEINTRESOURCE(IDD_LOGIN),
                  hwndParent,
                  LoginDialogProc);
    }
    
    // Show main dialog
    g_hwndMainDialog = CreateDialog(GetModuleHandle(NULL),
                                    MAKEINTRESOURCE(IDD_MAIN),
                                    hwndParent,
                                    MainDialogProc);
    
    if (g_hwndMainDialog != NULL) {
        ShowWindow(g_hwndMainDialog, SW_SHOW);
    }
}
```

## Complete System Tray Example

Here's a complete, minimal example demonstrating system tray integration:

```c
#include <windows.h>
#include <shellapi.h>
#include "resource.h"

#define WM_TRAYICON (WM_USER + 1)
#define ID_TRAYICON 1001
#define IDM_OPEN 2001
#define IDM_EXIT 2002

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void ShowTrayMenu(HWND hwnd);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"SystemTrayDemo";
    
    RegisterClassW(&wc);
    
    // Create hidden window (just for receiving messages)
    HWND hwnd = CreateWindowW(L"SystemTrayDemo", L"System Tray Demo",
                              0, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);
    
    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static NOTIFYICONDATA nid = {0};
    
    switch (msg)
    {
        case WM_CREATE:
        {
            // Initialize tray icon
            nid.cbSize = sizeof(NOTIFYICONDATA);
            nid.hWnd = hwnd;
            nid.uID = ID_TRAYICON;
            nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
            nid.uCallbackMessage = WM_TRAYICON;
            nid.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            wcscpy_s(nid.szTip, 128, L"System Tray Demo");
            
            Shell_NotifyIcon(NIM_ADD, &nid);
            return 0;
        }
        
        case WM_TRAYICON:
        {
            switch (LOWORD(lParam))
            {
                case WM_LBUTTONDBLCLK:
                    MessageBox(hwnd, L"Tray icon double-clicked!", L"Demo", MB_OK);
                    break;
                    
                case WM_RBUTTONDOWN:
                    ShowTrayMenu(hwnd);
                    break;
            }
            return 0;
        }
        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDM_OPEN:
                    MessageBox(hwnd, L"Open clicked", L"Demo", MB_OK);
                    break;
                    
                case IDM_EXIT:
                    PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break;
            }
            return 0;
        }
        
        case WM_DESTROY:
        {
            Shell_NotifyIcon(NIM_DELETE, &nid);
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

void ShowTrayMenu(HWND hwnd)
{
    POINT pt;
    GetCursorPos(&pt);
    
    HMENU hMenu = CreatePopupMenu();
    AppendMenu(hMenu, MF_STRING, IDM_OPEN, L"&Open");
    AppendMenu(hMenu, MF_SEPARATOR, 0, NULL);
    AppendMenu(hMenu, MF_STRING, IDM_EXIT, L"E&xit");
    
    SetForegroundWindow(hwnd);
    TrackPopupMenu(hMenu, TPM_BOTTOMALIGN, pt.x, pt.y, 0, hwnd, NULL);
    DestroyMenu(hMenu);
    PostMessage(hwnd, WM_NULL, 0, 0);
}
```

## Updating Icons Dynamically

You can change the tray icon to show status:

```c
void UpdateTrayIcon(HWND hwnd, HICON hNewIcon, const wchar_t* newTooltip)
{
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    nid.uFlags = NIF_ICON | NIF_TIP;
    nid.hIcon = hNewIcon;
    wcscpy_s(nid.szTip, 128, newTooltip);
    
    Shell_NotifyIcon(NIM_MODIFY, &nid);
}
```

**Use Cases:**
- Show different icons for online/offline status
- Animate icon during activity
- Update tooltip with current information

## Balloon Notifications (Legacy)

Modern Windows shows toast notifications, but older systems use balloons:

```c
void ShowBalloonNotification(HWND hwnd, const wchar_t* title, const wchar_t* message)
{
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    nid.uFlags = NIF_INFO;
    
    wcscpy_s(nid.szInfoTitle, 64, title);
    wcscpy_s(nid.szInfo, 256, message);
    nid.dwInfoFlags = NIIF_INFO;  // Info icon (can be NIIF_WARNING, NIIF_ERROR)
    nid.uTimeout = 3000;  // Deprecated, but can set to 0 for default
    
    Shell_NotifyIcon(NIM_MODIFY, &nid);
}
```

## Best Practices for System Tray Applications

### 1. Always Remove Icon on Exit
```c
case WM_DESTROY:
{
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    Shell_NotifyIcon(NIM_DELETE, &nid);
    
    PostQuitMessage(0);
    return 0;
}
```

**Why:** Prevents "ghost icons" that remain after application crashes.

### 2. Provide Multiple Ways to Open

- Left-click: Show main window
- Double-click: Show main window
- Right-click → Open: Show main window
- Global hotkey: Show main window (we'll add this in Chapter 26)

**Why:** Different users have different preferences.

### 3. Always Include Exit Option

```c
AppendMenu(hMenu, MF_STRING, IDM_EXIT, L"E&xit");
```

**Why:** Users must be able to close your application easily.

### 4. Use Descriptive Tooltips

```c
wcscpy_s(nid.szTip, 128, L"WinRDP - 5 servers configured");
```

**Why:** Tooltip helps users identify your app among many tray icons.

### 5. Handle Explorer Crashes

Windows Explorer can crash and restart, taking tray icons with it. Handle this:

```c
case WM_TASKBARCREATED:  // Custom message (register with RegisterWindowMessage)
{
    // Re-add tray icon after Explorer restarts
    InitSystemTray(hwnd);
    return 0;
}
```

Register the message:

```c
// Global variable
UINT g_uTaskbarCreated = 0;

// In wWinMain, before message loop
g_uTaskbarCreated = RegisterWindowMessage(L"TaskbarCreated");

// In WndProc
if (msg == g_uTaskbarCreated) {
    InitSystemTray(hwnd);
    return 0;
}
```

## Integrating with WinRDP

Now let's integrate system tray into the complete WinRDP application:

### Updated WinRDP main.c Structure

```c
// Global state
static HWND g_hwndMain = NULL;
static HWND g_hwndMainDialog = NULL;
static UINT g_uTaskbarCreated = 0;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine, int nCmdShow)
{
    // Check single instance (using mutex from earlier chapters)
    HANDLE hMutex = CreateMutexW(NULL, TRUE, L"WinRDP_SingleInstance");
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(hMutex);
        return 0;
    }
    
    // Initialize common controls
    INITCOMMONCONTROLSEX icex;
    icex.dwSize = sizeof(INITCOMMONCONTROLSEX);
    icex.dwICC = ICC_LISTVIEW_CLASSES;
    InitCommonControlsEx(&icex);
    
    // Register custom message for taskbar recreation
    g_uTaskbarCreated = RegisterWindowMessage(L"TaskbarCreated");
    
    // Register window class
    WNDCLASSEXW wc = {0};
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WinRDP_MainWindow";
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPICON));
    RegisterClassExW(&wc);
    
    // Create hidden main window (for messages)
    g_hwndMain = CreateWindowExW(0, L"WinRDP_MainWindow", L"WinRDP",
                                 0, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);
    
    if (g_hwndMain == NULL) {
        MessageBox(NULL, L"Failed to create window", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    
    // Initialize system tray
    if (!InitSystemTray(g_hwndMain)) {
        MessageBox(NULL, L"Failed to initialize system tray", L"Error", MB_OK | MB_ICONERROR);
        DestroyWindow(g_hwndMain);
        return 1;
    }
    
    // Show login dialog on startup
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_LOGIN), g_hwndMain, LoginDialogProc);
    
    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        // Check if dialog exists and handle dialog messages
        if (g_hwndMainDialog == NULL || !IsDialogMessage(g_hwndMainDialog, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    CloseHandle(hMutex);
    return (int)msg.wParam;
}
```

## Exercise 24.1: Basic System Tray

Create a minimal application that:
1. Shows a system tray icon on startup
2. Opens a message box when icon is double-clicked
3. Shows a context menu on right-click with "Exit" option
4. Properly removes icon when exiting

**Challenge:** Add a menu item to change the tooltip text.

## Exercise 24.2: Status Icon

Create an application that:
1. Shows different colored icons based on status (green = OK, red = error)
2. Updates the icon every 5 seconds randomly
3. Shows current status in tooltip
4. Has menu options to manually set status

**Hint:** Use `SetTimer` to trigger status changes.

## Exercise 24.3: Notification System

Add to Exercise 24.2:
1. Show balloon notification when status changes
2. Allow user to disable notifications via menu
3. Keep count of status changes and show in tooltip

## Common Mistakes and Solutions

### Mistake 1: Forgetting to Remove Icon

```c
// WRONG - Icon persists after crash
case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

// CORRECT - Always clean up
case WM_DESTROY:
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    Shell_NotifyIcon(NIM_DELETE, &nid);
    PostQuitMessage(0);
    return 0;
```

### Mistake 2: Menu Doesn't Dismiss Properly

```c
// WRONG - Menu stays visible
TrackPopupMenu(hMenu, TPM_BOTTOMALIGN, pt.x, pt.y, 0, hwnd, NULL);
DestroyMenu(hMenu);

// CORRECT - Requires SetForegroundWindow and WM_NULL
SetForegroundWindow(hwnd);  // Before TrackPopupMenu
TrackPopupMenu(hMenu, TPM_BOTTOMALIGN, pt.x, pt.y, 0, hwnd, NULL);
DestroyMenu(hMenu);
PostMessage(hwnd, WM_NULL, 0, 0);  // After TrackPopupMenu
```

**Why:** Windows has special requirements for popup menus from tray icons. These calls ensure proper behavior.

### Mistake 3: Icon Not Recreated After Explorer Crash

```c
// WRONG - Icon disappears permanently if Explorer crashes

// CORRECT - Handle TaskbarCreated message
g_uTaskbarCreated = RegisterWindowMessage(L"TaskbarCreated");

// In WndProc:
if (msg == g_uTaskbarCreated) {
    InitSystemTray(hwnd);
    return 0;
}
```

## Advanced Features

### Multiple Tray Icons

You can have multiple tray icons by using different IDs:

```c
#define ID_TRAYICON_MAIN   1001
#define ID_TRAYICON_STATUS 1002

// Add first icon
nid.uID = ID_TRAYICON_MAIN;
Shell_NotifyIcon(NIM_ADD, &nid);

// Add second icon
nid.uID = ID_TRAYICON_STATUS;
nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
wcscpy_s(nid.szTip, 128, L"Status Icon");
Shell_NotifyIcon(NIM_ADD, &nid);
```

### Animated Tray Icons

Create animation by cycling through icons:

```c
HICON g_animIcons[4];  // Array of animation frames
int g_currentFrame = 0;

void AnimateTrayIcon(HWND hwnd)
{
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    nid.uFlags = NIF_ICON;
    nid.hIcon = g_animIcons[g_currentFrame];
    
    Shell_NotifyIcon(NIM_MODIFY, &nid);
    
    g_currentFrame = (g_currentFrame + 1) % 4;
}

// Call from WM_TIMER handler
SetTimer(hwnd, IDT_ANIMATE, 500, NULL);  // 500ms per frame
```

## Testing Your System Tray Implementation

### Test Checklist

1. ☐ Icon appears in system tray on startup
2. ☐ Tooltip shows when hovering over icon
3. ☐ Left-click opens main window
4. ☐ Double-click opens main window
5. ☐ Right-click shows context menu
6. ☐ Menu items work correctly
7. ☐ Icon disappears when application exits
8. ☐ Application can be closed from tray menu
9. ☐ Icon reappears after Explorer restart (kill and restart explorer.exe)
10. ☐ No ghost icons remain after crashes

### Testing Explorer Crash Recovery

1. Run your application
2. Open Task Manager
3. Find "Windows Explorer" process
4. Right-click → End Task (desktop will disappear)
5. File → Run new task → explorer.exe (desktop returns)
6. Your tray icon should reappear automatically

## Summary

In this chapter, you learned:

### **System Tray Fundamentals**
- ✅ Understanding Windows notification area
- ✅ NOTIFYICONDATA structure
- ✅ Shell_NotifyIcon API (NIM_ADD, NIM_DELETE, NIM_MODIFY)
- ✅ Tray icon messages and callbacks

### **Implementation Skills**
- ✅ Adding icons to system tray
- ✅ Creating context menus
- ✅ Handling tray icon clicks
- ✅ Showing/hiding windows
- ✅ Updating icons dynamically

### **Best Practices**
- ✅ Always remove icon on exit
- ✅ Handle Explorer crashes
- ✅ Provide multiple access methods
- ✅ Use descriptive tooltips
- ✅ Always include Exit option

### **Your WinRDP Application Now Has:**
- ✅ Full system tray integration
- ✅ Background operation capability
- ✅ Quick access from system tray
- ✅ Professional Windows application behavior

**Congratulations!** You've completed Part IV. Your WinRDP application now has all core functionality and can operate as a professional background application. In Part V, we'll add advanced features that make WinRDP truly stand out.

---

# Part V: Advanced Features

# Chapter 25: Registry Operations and Autostart

**What You'll Learn:**
- Understanding the Windows Registry structure
- Reading and writing registry values
- Working with registry keys and paths
- Implementing "Start with Windows" functionality
- Best practices for registry operations
- Error handling and security considerations

## Introduction

The Windows Registry is a hierarchical database that stores configuration settings and options for the Windows operating system and installed applications. Learning to work with the registry is essential for implementing features like:
- Automatically starting your application when Windows boots
- Storing application preferences
- Reading system configuration
- Integrating with Windows properly

In this chapter, we'll implement autostart functionality for WinRDP, allowing it to launch automatically when Windows starts - a feature expected in professional system tray applications.

## Understanding the Windows Registry

### What Is the Registry?

The Registry replaced the old .INI files used in early Windows versions. It provides:
- **Centralized storage** for system and application settings
- **Hierarchical structure** (like folders and files)
- **Different data types** (strings, numbers, binary data)
- **Security** (access control on keys)
- **Performance** (optimized for quick lookups)

### Registry Structure

The registry is organized into **hives** (root keys):

```
HKEY_LOCAL_MACHINE (HKLM)
│   System-wide settings, available to all users
│   Requires administrator rights to modify
│
HKEY_CURRENT_USER (HKCU)
│   Settings for currently logged-in user
│   User can modify without admin rights
│
HKEY_CLASSES_ROOT (HKCR)
│   File associations and COM registration
│
HKEY_USERS (HKU)
│   Settings for all user profiles
│
HKEY_CURRENT_CONFIG (HKCC)
    Current hardware profile settings
```

**For WinRDP, we'll use HKEY_CURRENT_USER** because:
- User-specific settings (each user can choose whether to autostart)
- No administrator rights required
- Follows Windows best practices

### Common Registry Paths

```
HKCU\Software\YourCompanyName\YourAppName
    Your application settings

HKCU\Software\Microsoft\Windows\CurrentVersion\Run
    Programs that start with Windows (current user)

HKLM\Software\Microsoft\Windows\CurrentVersion\Run
    Programs that start with Windows (all users, requires admin)
```

## Windows Registry API

### Key Functions

```c
// Open a registry key
LONG RegOpenKeyExW(
    HKEY hKey,              // Root key (HKEY_CURRENT_USER, etc.)
    LPCWSTR lpSubKey,       // Path to subkey
    DWORD ulOptions,        // Reserved, must be 0
    REGSAM samDesired,      // Access rights (KEY_READ, KEY_WRITE, etc.)
    PHKEY phkResult         // Receives handle to opened key
);

// Create a new key (or open if exists)
LONG RegCreateKeyExW(
    HKEY hKey,
    LPCWSTR lpSubKey,
    DWORD Reserved,
    LPWSTR lpClass,
    DWORD dwOptions,
    REGSAM samDesired,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    PHKEY phkResult,
    LPDWORD lpdwDisposition
);

// Read a value
LONG RegQueryValueExW(
    HKEY hKey,              // Handle to open key
    LPCWSTR lpValueName,    // Name of value
    LPDWORD lpReserved,     // Reserved, must be NULL
    LPDWORD lpType,         // Receives value type
    LPBYTE lpData,          // Buffer for value data
    LPDWORD lpcbData        // Size of buffer
);

// Write a value
LONG RegSetValueExW(
    HKEY hKey,
    LPCWSTR lpValueName,
    DWORD Reserved,
    DWORD dwType,           // Value type (REG_SZ, REG_DWORD, etc.)
    const BYTE *lpData,     // Value data
    DWORD cbData            // Size of data
);

// Delete a value
LONG RegDeleteValueW(
    HKEY hKey,
    LPCWSTR lpValueName
);

// Close a key handle
LONG RegCloseKey(
    HKEY hKey
);
```

### Return Values

All registry functions return `ERROR_SUCCESS` (0) on success, or an error code:

```c
ERROR_SUCCESS          // 0 - Success
ERROR_FILE_NOT_FOUND   // Key or value doesn't exist
ERROR_ACCESS_DENIED    // Insufficient permissions
ERROR_MORE_DATA        // Buffer too small
```

## Implementing Autostart

### Step 1: Enable Autostart

```c
// registry.c
#include <windows.h>

BOOL EnableAutostart(void)
{
    HKEY hKey;
    wchar_t szPath[MAX_PATH];
    LONG result;
    
    // Get full path to current executable
    if (GetModuleFileNameW(NULL, szPath, MAX_PATH) == 0) {
        return FALSE;
    }
    
    // Open the Run key
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_WRITE,
        &hKey
    );
    
    if (result != ERROR_SUCCESS) {
        return FALSE;
    }
    
    // Write the value
    result = RegSetValueExW(
        hKey,
        L"WinRDP",                              // Value name
        0,
        REG_SZ,                                 // String type
        (BYTE*)szPath,                          // Executable path
        (DWORD)((wcslen(szPath) + 1) * sizeof(wchar_t))  // Size in bytes
    );
    
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS);
}
```

**What This Does:**
1. Gets full path to the running executable using `GetModuleFileNameW`
2. Opens the `Run` registry key with write access
3. Creates/updates a value named "WinRDP" with the executable path
4. Windows will now launch this program on startup
5. Closes the registry key handle

### Step 2: Disable Autostart

```c
BOOL DisableAutostart(void)
{
    HKEY hKey;
    LONG result;
    
    // Open the Run key
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_WRITE,
        &hKey
    );
    
    if (result != ERROR_SUCCESS) {
        return FALSE;
    }
    
    // Delete the value
    result = RegDeleteValueW(hKey, L"WinRDP");
    
    RegCloseKey(hKey);
    
    // ERROR_FILE_NOT_FOUND means it wasn't there - that's OK
    return (result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);
}
```

### Step 3: Check Autostart Status

```c
BOOL IsAutostartEnabled(void)
{
    HKEY hKey;
    LONG result;
    wchar_t szValue[MAX_PATH];
    DWORD dwSize = sizeof(szValue);
    DWORD dwType;
    
    // Open the Run key for reading
    result = RegOpenKeyExW(
        HKEY_CURRENT_USER,
        L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_READ,
        &hKey
    );
    
    if (result != ERROR_SUCCESS) {
        return FALSE;
    }
    
    // Try to read the value
    result = RegQueryValueExW(
        hKey,
        L"WinRDP",
        NULL,
        &dwType,
        (LPBYTE)szValue,
        &dwSize
    );
    
    RegCloseKey(hKey);
    
    // If value exists and is a string, autostart is enabled
    return (result == ERROR_SUCCESS && dwType == REG_SZ);
}
```

### Step 4: Toggle Function

```c
BOOL ToggleAutostart(void)
{
    if (IsAutostartEnabled()) {
        return DisableAutostart();
    } else {
        return EnableAutostart();
    }
}
```

## Complete Registry Module

Here's a complete `registry.h` and `registry.c`:

**registry.h:**
```c
#ifndef REGISTRY_H
#define REGISTRY_H

#include <windows.h>

// Autostart functions
BOOL EnableAutostart(void);
BOOL DisableAutostart(void);
BOOL IsAutostartEnabled(void);
BOOL ToggleAutostart(void);

// Application settings (optional)
BOOL SaveStringSetting(const wchar_t* name, const wchar_t* value);
BOOL LoadStringSetting(const wchar_t* name, wchar_t* value, DWORD valueSize);
BOOL SaveDwordSetting(const wchar_t* name, DWORD value);
BOOL LoadDwordSetting(const wchar_t* name, DWORD* value);

#endif // REGISTRY_H
```

**registry.c:**
```c
#include "registry.h"
#include <wchar.h>

#define APP_REG_PATH L"Software\\WinRDP"
#define RUN_REG_PATH L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define APP_NAME L"WinRDP"

// Autostart implementation
BOOL EnableAutostart(void)
{
    HKEY hKey;
    wchar_t szPath[MAX_PATH];
    LONG result;
    
    if (GetModuleFileNameW(NULL, szPath, MAX_PATH) == 0)
        return FALSE;
    
    result = RegOpenKeyExW(HKEY_CURRENT_USER, RUN_REG_PATH, 0, KEY_WRITE, &hKey);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegSetValueExW(hKey, APP_NAME, 0, REG_SZ, (BYTE*)szPath,
                            (DWORD)((wcslen(szPath) + 1) * sizeof(wchar_t)));
    
    RegCloseKey(hKey);
    return (result == ERROR_SUCCESS);
}

BOOL DisableAutostart(void)
{
    HKEY hKey;
    LONG result;
    
    result = RegOpenKeyExW(HKEY_CURRENT_USER, RUN_REG_PATH, 0, KEY_WRITE, &hKey);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegDeleteValueW(hKey, APP_NAME);
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);
}

BOOL IsAutostartEnabled(void)
{
    HKEY hKey;
    LONG result;
    wchar_t szValue[MAX_PATH];
    DWORD dwSize = sizeof(szValue);
    DWORD dwType;
    
    result = RegOpenKeyExW(HKEY_CURRENT_USER, RUN_REG_PATH, 0, KEY_READ, &hKey);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegQueryValueExW(hKey, APP_NAME, NULL, &dwType, (LPBYTE)szValue, &dwSize);
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS && dwType == REG_SZ);
}

BOOL ToggleAutostart(void)
{
    return IsAutostartEnabled() ? DisableAutostart() : EnableAutostart();
}

// Application settings implementation
BOOL SaveStringSetting(const wchar_t* name, const wchar_t* value)
{
    HKEY hKey;
    LONG result;
    
    // Create or open our application key
    result = RegCreateKeyExW(HKEY_CURRENT_USER, APP_REG_PATH, 0, NULL, 0,
                            KEY_WRITE, NULL, &hKey, NULL);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegSetValueExW(hKey, name, 0, REG_SZ, (BYTE*)value,
                            (DWORD)((wcslen(value) + 1) * sizeof(wchar_t)));
    
    RegCloseKey(hKey);
    return (result == ERROR_SUCCESS);
}

BOOL LoadStringSetting(const wchar_t* name, wchar_t* value, DWORD valueSize)
{
    HKEY hKey;
    LONG result;
    DWORD dwType;
    DWORD dwSize = valueSize * sizeof(wchar_t);
    
    result = RegOpenKeyExW(HKEY_CURRENT_USER, APP_REG_PATH, 0, KEY_READ, &hKey);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegQueryValueExW(hKey, name, NULL, &dwType, (LPBYTE)value, &dwSize);
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS && dwType == REG_SZ);
}

BOOL SaveDwordSetting(const wchar_t* name, DWORD value)
{
    HKEY hKey;
    LONG result;
    
    result = RegCreateKeyExW(HKEY_CURRENT_USER, APP_REG_PATH, 0, NULL, 0,
                            KEY_WRITE, NULL, &hKey, NULL);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegSetValueExW(hKey, name, 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
    
    RegCloseKey(hKey);
    return (result == ERROR_SUCCESS);
}

BOOL LoadDwordSetting(const wchar_t* name, DWORD* value)
{
    HKEY hKey;
    LONG result;
    DWORD dwType;
    DWORD dwSize = sizeof(DWORD);
    
    result = RegOpenKeyExW(HKEY_CURRENT_USER, APP_REG_PATH, 0, KEY_READ, &hKey);
    if (result != ERROR_SUCCESS)
        return FALSE;
    
    result = RegQueryValueExW(hKey, name, NULL, &dwType, (LPBYTE)value, &dwSize);
    RegCloseKey(hKey);
    
    return (result == ERROR_SUCCESS && dwType == REG_DWORD);
}
```

## Integrating with WinRDP UI

### Add Menu Item

In your `resources.rc`, add a menu item:

```rc
POPUP "Options"
BEGIN
    MENUITEM "Start with Windows", IDM_AUTOSTART
END
```

### Handle Menu Click

In your dialog procedure:

```c
case WM_INITDIALOG:
{
    // ... other initialization ...
    
    // Check menu item if autostart is enabled
    HMENU hMenu = GetMenu(hwnd);
    if (IsAutostartEnabled()) {
        CheckMenuItem(hMenu, IDM_AUTOSTART, MF_CHECKED);
    }
    return TRUE;
}

case WM_COMMAND:
{
    switch (LOWORD(wParam))
    {
        case IDM_AUTOSTART:
        {
            HMENU hMenu = GetMenu(hwnd);
            
            if (IsAutostartEnabled()) {
                if (DisableAutostart()) {
                    CheckMenuItem(hMenu, IDM_AUTOSTART, MF_UNCHECKED);
                    MessageBox(hwnd, L"Autostart disabled", L"WinRDP", MB_OK | MB_ICONINFORMATION);
                }
            } else {
                if (EnableAutostart()) {
                    CheckMenuItem(hMenu, IDM_AUTOSTART, MF_CHECKED);
                    MessageBox(hwnd, L"WinRDP will now start with Windows", L"WinRDP", MB_OK | MB_ICONINFORMATION);
                }
            }
            break;
        }
    }
    return TRUE;
}
```

## Registry Data Types

### Common Types

```c
REG_SZ          // Null-terminated string
REG_EXPAND_SZ   // String with environment variables (%USERPROFILE%)
REG_DWORD       // 32-bit number
REG_QWORD       // 64-bit number
REG_BINARY      // Binary data
REG_MULTI_SZ    // Multiple null-terminated strings
```

### Examples

**String:**
```c
wchar_t* value = L"Hello, World!";
RegSetValueExW(hKey, L"MyString", 0, REG_SZ, (BYTE*)value,
               (wcslen(value) + 1) * sizeof(wchar_t));
```

**DWORD (number):**
```c
DWORD value = 42;
RegSetValueExW(hKey, L"MyNumber", 0, REG_DWORD, (BYTE*)&value, sizeof(DWORD));
```

**Binary Data:**
```c
BYTE data[] = {0x01, 0x02, 0x03, 0x04};
RegSetValueExW(hKey, L"MyData", 0, REG_BINARY, data, sizeof(data));
```

## Best Practices

### 1. Always Close Registry Keys

```c
HKEY hKey;
RegOpenKeyExW(HKEY_CURRENT_USER, L"Some\\Path", 0, KEY_READ, &hKey);

// ... use the key ...

RegCloseKey(hKey);  // ALWAYS close!
```

**Why:** Leaked handles waste resources and can cause issues.

### 2. Check Return Values

```c
LONG result = RegOpenKeyExW(...);
if (result != ERROR_SUCCESS) {
    // Handle error
    return FALSE;
}
```

**Why:** Registry operations can fail for many reasons (permissions, missing keys, etc.)

### 3. Use Appropriate Access Rights

```c
// Reading only - use KEY_READ
RegOpenKeyExW(hKey, path, 0, KEY_READ, &hKey);

// Writing only - use KEY_WRITE
RegOpenKeyExW(hKey, path, 0, KEY_WRITE, &hKey);

// Both - use KEY_READ | KEY_WRITE
RegOpenKeyExW(hKey, path, 0, KEY_READ | KEY_WRITE, &hKey);
```

**Why:** Requesting minimum necessary permissions follows security best practices.

### 4. Use Your Company/App Path

```c
// GOOD: Use your own path
HKCU\Software\YourCompany\YourApp

// BAD: Write to root Software key
HKCU\Software\MySetting
```

**Why:** Prevents conflicts with other applications.

### 5. Handle Missing Keys Gracefully

```c
BOOL LoadSetting(void)
{
    HKEY hKey;
    if (RegOpenKeyExW(...) != ERROR_SUCCESS) {
        // Key doesn't exist - use default value
        return FALSE;
    }
    
    // ... read value ...
}
```

**Why:** First-run applications won't have registry entries yet.

## Security Considerations

### UAC and Admin Rights

```c
// HKCU - No admin rights needed ✓
RegOpenKeyExW(HKEY_CURRENT_USER, ...);

// HKLM - Requires admin rights ✗
RegOpenKeyExW(HKEY_LOCAL_MACHINE, ...);
```

**For WinRDP:** Always use HKEY_CURRENT_USER to avoid requiring admin rights.

### Registry Virtualization

On modern Windows, applications without admin rights writing to HKLM get **virtualized** - Windows redirects writes to a per-user location. Avoid this by:
- Using HKEY_CURRENT_USER for user settings
- Requesting admin rights explicitly if you must write to HKLM

## Advanced Registry Operations

### Enumerating Values

```c
void EnumerateValues(HKEY hKey)
{
    DWORD index = 0;
    wchar_t valueName[256];
    DWORD valueNameSize;
    
    while (TRUE)
    {
        valueNameSize = sizeof(valueName) / sizeof(wchar_t);
        
        LONG result = RegEnumValueW(hKey, index, valueName, &valueNameSize,
                                     NULL, NULL, NULL, NULL);
        
        if (result == ERROR_NO_MORE_ITEMS)
            break;
        
        if (result != ERROR_SUCCESS)
            break;
        
        wprintf(L"Value: %s\n", valueName);
        index++;
    }
}
```

### Enumerating Subkeys

```c
void EnumerateSubkeys(HKEY hKey)
{
    DWORD index = 0;
    wchar_t subkeyName[256];
    DWORD subkeyNameSize;
    
    while (TRUE)
    {
        subkeyNameSize = sizeof(subkeyName) / sizeof(wchar_t);
        
        LONG result = RegEnumKeyExW(hKey, index, subkeyName, &subkeyNameSize,
                                     NULL, NULL, NULL, NULL);
        
        if (result == ERROR_NO_MORE_ITEMS)
            break;
        
        if (result != ERROR_SUCCESS)
            break;
        
        wprintf(L"Subkey: %s\n", subkeyName);
        index++;
    }
}
```

### Deleting a Key

```c
BOOL DeleteRegistryKey(void)
{
    LONG result = RegDeleteKeyW(HKEY_CURRENT_USER, L"Software\\WinRDP\\Temp");
    return (result == ERROR_SUCCESS || result == ERROR_FILE_NOT_FOUND);
}
```

**Warning:** Be very careful with `RegDeleteKey` - it can delete entire branches!

## Testing Autostart

### Manual Testing

1. **Enable autostart** in your application
2. **Open Registry Editor** (regedit.exe)
3. Navigate to: `HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run`
4. Verify "WinRDP" entry exists with correct path
5. **Log out and log back in** (or restart)
6. Verify application starts automatically
7. **Disable autostart** in your application
8. Verify registry entry is removed
9. Log out and log back in - application should NOT start

### Programmatic Testing

```c
void TestAutostart(void)
{
    printf("Testing autostart functionality...\n");
    
    // Initial state should be disabled (for clean test)
    if (IsAutostartEnabled()) {
        printf("Disabling autostart for clean test...\n");
        DisableAutostart();
    }
    
    // Test enabling
    if (EnableAutostart()) {
        printf("✓ EnableAutostart() succeeded\n");
    } else {
        printf("✗ EnableAutostart() failed\n");
    }
    
    // Verify enabled
    if (IsAutostartEnabled()) {
        printf("✓ IsAutostartEnabled() returns TRUE\n");
    } else {
        printf("✗ IsAutostartEnabled() returns FALSE\n");
    }
    
    // Test disabling
    if (DisableAutostart()) {
        printf("✓ DisableAutostart() succeeded\n");
    } else {
        printf("✗ DisableAutostart() failed\n");
    }
    
    // Verify disabled
    if (!IsAutostartEnabled()) {
        printf("✓ IsAutostartEnabled() returns FALSE\n");
    } else {
        printf("✗ IsAutostartEnabled() returns TRUE\n");
    }
    
    printf("Autostart test complete!\n");
}
```

## Storing Other Application Settings

Beyond autostart, you can store various settings:

### Window Position

```c
// Save window position
BOOL SaveWindowPosition(int x, int y, int width, int height)
{
    HKEY hKey;
    if (RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\WinRDP\\Window",
                       0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS)
        return FALSE;
    
    RegSetValueExW(hKey, L"X", 0, REG_DWORD, (BYTE*)&x, sizeof(DWORD));
    RegSetValueExW(hKey, L"Y", 0, REG_DWORD, (BYTE*)&y, sizeof(DWORD));
    RegSetValueExW(hKey, L"Width", 0, REG_DWORD, (BYTE*)&width, sizeof(DWORD));
    RegSetValueExW(hKey, L"Height", 0, REG_DWORD, (BYTE*)&height, sizeof(DWORD));
    
    RegCloseKey(hKey);
    return TRUE;
}

// Load window position
BOOL LoadWindowPosition(int* x, int* y, int* width, int* height)
{
    HKEY hKey;
    DWORD dwSize = sizeof(DWORD);
    
    if (RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\WinRDP\\Window",
                     0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return FALSE;
    
    RegQueryValueExW(hKey, L"X", NULL, NULL, (LPBYTE)x, &dwSize);
    RegQueryValueExW(hKey, L"Y", NULL, NULL, (LPBYTE)y, &dwSize);
    RegQueryValueExW(hKey, L"Width", NULL, NULL, (LPBYTE)width, &dwSize);
    RegQueryValueExW(hKey, L"Height", NULL, NULL, (LPBYTE)height, &dwSize);
    
    RegCloseKey(hKey);
    return TRUE;
}
```

### User Preferences

```c
typedef struct {
    BOOL showNotifications;
    BOOL minimizeToTray;
    BOOL confirmBeforeConnect;
    wchar_t defaultDomain[64];
} AppPreferences;

BOOL SavePreferences(const AppPreferences* prefs)
{
    HKEY hKey;
    if (RegCreateKeyExW(HKEY_CURRENT_USER, L"Software\\WinRDP\\Preferences",
                       0, NULL, 0, KEY_WRITE, NULL, &hKey, NULL) != ERROR_SUCCESS)
        return FALSE;
    
    DWORD dwValue;
    
    dwValue = prefs->showNotifications;
    RegSetValueExW(hKey, L"ShowNotifications", 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
    
    dwValue = prefs->minimizeToTray;
    RegSetValueExW(hKey, L"MinimizeToTray", 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
    
    dwValue = prefs->confirmBeforeConnect;
    RegSetValueExW(hKey, L"ConfirmBeforeConnect", 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));
    
    RegSetValueExW(hKey, L"DefaultDomain", 0, REG_SZ, (BYTE*)prefs->defaultDomain,
                   (wcslen(prefs->defaultDomain) + 1) * sizeof(wchar_t));
    
    RegCloseKey(hKey);
    return TRUE;
}
```

## Common Mistakes and Solutions

### Mistake 1: Not Multiplying String Length by sizeof(wchar_t)

```c
// WRONG - Only writes first half of string
RegSetValueExW(hKey, L"Value", 0, REG_SZ, (BYTE*)str, wcslen(str));

// CORRECT - Multiply by sizeof(wchar_t), add 1 for null terminator
RegSetValueExW(hKey, L"Value", 0, REG_SZ, (BYTE*)str,
               (wcslen(str) + 1) * sizeof(wchar_t));
```

### Mistake 2: Forgetting to Close Keys

```c
// WRONG - Leaks handle
HKEY hKey;
RegOpenKeyExW(..., &hKey);
if (someCondition) {
    return FALSE;  // Forgot to close hKey!
}
RegCloseKey(hKey);

// CORRECT - Always close
HKEY hKey;
RegOpenKeyExW(..., &hKey);
if (someCondition) {
    RegCloseKey(hKey);
    return FALSE;
}
RegCloseKey(hKey);
```

### Mistake 3: Not Checking Return Values

```c
// WRONG - Assumes success
RegOpenKeyExW(...);  // What if this fails?
RegQueryValueExW(...);  // Will crash if key not opened!

// CORRECT - Check errors
if (RegOpenKeyExW(...) != ERROR_SUCCESS) {
    return FALSE;
}
```

## Exercise 25.1: Basic Registry

Write a program that:
1. Saves your name to the registry
2. Reads it back and displays it
3. Deletes the value
4. Handles errors gracefully

**Key:** `HKCU\Software\MyApp`
**Value:** "UserName"

## Exercise 25.2: Settings Manager

Create a settings system that:
1. Saves and loads window position
2. Saves and loads user preferences (3+ boolean options)
3. Provides default values if registry entries don't exist
4. Has a "Reset to Defaults" function

## Exercise 25.3: Autostart with Arguments

Enhance the autostart feature:
1. Add `/minimized` argument when starting with Windows
2. Parse command-line arguments in wWinMain
3. Start minimized to tray if `/minimized` is present
4. Show normal window if argument not present

**Hint:**
```c
wchar_t szPath[MAX_PATH * 2];
GetModuleFileNameW(NULL, szPath, MAX_PATH);
wcscat_s(szPath, MAX_PATH * 2, L" /minimized");
// Now save szPath to registry
```

## Summary

In this chapter, you learned:

### **Registry Fundamentals**
- ✅ Understanding Windows Registry structure
- ✅ Registry hives (HKCU, HKLM, etc.)
- ✅ Registry data types (REG_SZ, REG_DWORD, etc.)
- ✅ Best practices and security considerations

### **Registry API**
- ✅ RegOpenKeyExW - Opening keys
- ✅ RegCreateKeyExW - Creating keys
- ✅ RegQueryValueExW - Reading values
- ✅ RegSetValueExW - Writing values
- ✅ RegDeleteValueW - Deleting values
- ✅ RegCloseKey - Closing handles

### **Autostart Implementation**
- ✅ EnableAutostart() - Add to Windows startup
- ✅ DisableAutostart() - Remove from startup
- ✅ IsAutostartEnabled() - Check status
- ✅ ToggleAutostart() - Switch on/off

### **Application Settings**
- ✅ Storing user preferences
- ✅ Saving window positions
- ✅ Loading default values
- ✅ Managing configuration data

### **Your WinRDP Application Now Has:**
- ✅ "Start with Windows" functionality
- ✅ Professional Windows integration
- ✅ Persistent application settings
- ✅ Registry-based configuration

**Next:** In Chapter 26, we'll add global hotkeys so users can instantly access WinRDP from anywhere in Windows with a keyboard shortcut!

---

# Chapter 26: Global Hotkeys

**What You'll Learn:**
- Understanding Windows hotkey system
- RegisterHotKey and UnregisterHotKey APIs
- Handling WM_HOTKEY messages
- Virtual key codes and modifier keys
- Implementing Ctrl+Shift+R for WinRDP
- Best practices for hotkey management

## Introduction

Global hotkeys (also called system-wide keyboard shortcuts) allow users to trigger your application from anywhere in Windows - even when your application doesn't have focus. This is a powerful feature that makes WinRDP instantly accessible with a simple keyboard combination.

In this chapter, we'll implement **Ctrl+Shift+R** to open WinRDP from anywhere, making it as convenient as the Windows Task Manager (Ctrl+Shift+Esc) or Task Switcher (Alt+Tab).

## Why Global Hotkeys Matter

Global hotkeys provide:
- **Instant access** - No need to find window in taskbar or system tray
- **Professional feel** - Modern applications support keyboard shortcuts
- **Efficiency** - Power users love keyboard-driven workflows
- **Accessibility** - Quick access without mouse navigation

**Common Examples:**
- **Ctrl+Shift+Esc** - Task Manager
- **Win+D** - Show Desktop
- **Win+L** - Lock Computer
- **Ctrl+Alt+Del** - Security options

## Understanding Windows Hotkeys

### How Hotkeys Work

1. Application **registers** a hotkey with Windows
2. Windows **monitors** all keyboard input system-wide
3. When the key combination is pressed, Windows sends **WM_HOTKEY** message to your window
4. Your application **handles** the message and performs the action
5. When application exits, it **unregisters** the hotkey

### Virtual Key Codes

Windows uses **virtual key codes** to identify keys, independent of keyboard layout:

```c
// Letter keys
'A' through 'Z'         // 0x41 through 0x5A
'0' through '9'         // 0x30 through 0x39

// Function keys
VK_F1 through VK_F12    // Function keys

// Special keys
VK_ESCAPE               // Escape key
VK_RETURN               // Enter key
VK_SPACE                // Space bar
VK_BACK                 // Backspace
VK_TAB                  // Tab key
VK_DELETE               // Delete key
VK_INSERT               // Insert key

// Navigation keys
VK_HOME, VK_END         // Home, End
VK_PRIOR, VK_NEXT       // Page Up, Page Down
VK_UP, VK_DOWN          // Arrow keys
VK_LEFT, VK_RIGHT

// Media keys
VK_VOLUME_MUTE          // Mute
VK_VOLUME_DOWN          // Volume down
VK_VOLUME_UP            // Volume up
VK_MEDIA_PLAY_PAUSE     // Play/Pause
```

### Modifier Keys

Modifiers are combined with regular keys to create shortcuts:

```c
MOD_CONTROL     // Ctrl key
MOD_SHIFT       // Shift key
MOD_ALT         // Alt key
MOD_WIN         // Windows key (use carefully!)

// Combine with bitwise OR:
MOD_CONTROL | MOD_SHIFT                  // Ctrl+Shift
MOD_CONTROL | MOD_ALT                    // Ctrl+Alt
MOD_CONTROL | MOD_SHIFT | MOD_ALT        // Ctrl+Shift+Alt
```

## The RegisterHotKey API

```c
BOOL RegisterHotKey(
    HWND hWnd,          // Window to receive WM_HOTKEY messages
    int id,             // Hotkey identifier (unique per window)
    UINT fsModifiers,   // Modifier keys (MOD_CONTROL, etc.)
    UINT vk             // Virtual key code
);
```

**Parameters:**
- `hWnd`: Your window handle (can be NULL for thread message queue)
- `id`: Unique identifier for this hotkey (you define this)
- `fsModifiers`: Combination of MOD_* flags
- `vk`: Virtual key code for the key

**Returns:**
- `TRUE` if successful
- `FALSE` if failed (hotkey already in use, invalid parameters, etc.)

## Implementing Global Hotkeys in WinRDP

### Step 1: Define Hotkey Constants

Add to `resource.h`:

```c
// Hotkey IDs
#define ID_HOTKEY_OPEN      1001    // Ctrl+Shift+R - Open WinRDP
#define ID_HOTKEY_BULK_DELETE 1002  // Ctrl+Shift+Alt+D - Bulk delete (secret)
```

### Step 2: Register Hotkeys on Startup

```c
// In WndProc, handle WM_CREATE
case WM_CREATE:
{
    // Register Ctrl+Shift+R to open WinRDP
    if (!RegisterHotKey(hwnd, ID_HOTKEY_OPEN, 
                        MOD_CONTROL | MOD_SHIFT, 'R')) {
        // Hotkey registration failed (maybe already in use)
        // Application still works, just without hotkey
        OutputDebugString(L"Failed to register Ctrl+Shift+R hotkey\n");
    }
    
    // Register secret bulk delete hotkey: Ctrl+Shift+Alt+D
    if (!RegisterHotKey(hwnd, ID_HOTKEY_BULK_DELETE,
                        MOD_CONTROL | MOD_SHIFT | MOD_ALT, 'D')) {
        OutputDebugString(L"Failed to register Ctrl+Shift+Alt+D hotkey\n");
    }
    
    return 0;
}
```

**Important:** Don't fail window creation if hotkey registration fails. The application should work fine without hotkeys.

### Step 3: Handle Hotkey Messages

```c
case WM_HOTKEY:
{
    switch (wParam)  // wParam contains the hotkey ID
    {
        case ID_HOTKEY_OPEN:
        {
            // Ctrl+Shift+R pressed - open main dialog
            
            // Check if credentials exist
            wchar_t username[256], password[256];
            if (!LoadCredentials(NULL, username, sizeof(username)/sizeof(wchar_t),
                                password, sizeof(password)/sizeof(wchar_t))) {
                // No credentials - show login dialog first
                DialogBox(GetModuleHandle(NULL), 
                         MAKEINTRESOURCE(IDD_LOGIN),
                         hwnd,
                         LoginDialogProc);
            }
            
            // Show main dialog
            ShowMainDialog(hwnd);
            break;
        }
        
        case ID_HOTKEY_BULK_DELETE:
        {
            // Ctrl+Shift+Alt+D pressed - secret bulk delete feature
            
            // Confirm action (this is destructive!)
            int result = MessageBox(hwnd,
                L"This will delete ALL hosts and credentials!\n\n"
                L"Are you sure you want to continue?",
                L"Bulk Delete - Confirmation Required",
                MB_YESNO | MB_ICONWARNING | MB_DEFBUTTON2);
            
            if (result == IDYES) {
                // Delete all hosts
                DeleteAllHosts();
                
                // Delete all credentials
                DeleteAllCredentials();
                
                MessageBox(hwnd,
                    L"All data has been deleted.",
                    L"Bulk Delete Complete",
                    MB_OK | MB_ICONINFORMATION);
            }
            break;
        }
    }
    return 0;
}
```

### Step 4: Unregister Hotkeys on Exit

```c
case WM_DESTROY:
{
    // Unregister all hotkeys
    UnregisterHotKey(hwnd, ID_HOTKEY_OPEN);
    UnregisterHotKey(hwnd, ID_HOTKEY_BULK_DELETE);
    
    // Remove tray icon
    NOTIFYICONDATA nid = {0};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hwnd;
    nid.uID = ID_TRAYICON;
    Shell_NotifyIcon(NIM_DELETE, &nid);
    
    PostQuitMessage(0);
    return 0;
}
```

**Why unregister?** If you don't unregister, the hotkey remains registered to your (now dead) window, and no one can use that combination until the user logs out.

## Complete Hotkey Example

Here's a complete minimal example:

```c
#include <windows.h>

#define ID_HOTKEY_HELLO 1001
#define ID_HOTKEY_EXIT  1002

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSW wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"HotkeyDemo";
    
    RegisterClassW(&wc);
    
    // Create hidden window (just for messages)
    HWND hwnd = CreateWindowW(L"HotkeyDemo", L"Hotkey Demo",
                              0, 0, 0, 0, 0, NULL, NULL, hInstance, NULL);
    
    MessageBox(NULL,
        L"Hotkeys registered:\n\n"
        L"Ctrl+Shift+H - Show message\n"
        L"Ctrl+Shift+Q - Exit application",
        L"Hotkey Demo",
        MB_OK | MB_ICONINFORMATION);
    
    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            // Register Ctrl+Shift+H
            if (!RegisterHotKey(hwnd, ID_HOTKEY_HELLO, MOD_CONTROL | MOD_SHIFT, 'H')) {
                MessageBox(hwnd, L"Failed to register Ctrl+Shift+H", L"Error", MB_OK);
            }
            
            // Register Ctrl+Shift+Q
            if (!RegisterHotKey(hwnd, ID_HOTKEY_EXIT, MOD_CONTROL | MOD_SHIFT, 'Q')) {
                MessageBox(hwnd, L"Failed to register Ctrl+Shift+Q", L"Error", MB_OK);
            }
            
            return 0;
        }
        
        case WM_HOTKEY:
        {
            switch (wParam)
            {
                case ID_HOTKEY_HELLO:
                    MessageBox(hwnd, L"Hello from global hotkey!", L"Hotkey Demo", MB_OK);
                    break;
                    
                case ID_HOTKEY_EXIT:
                    PostMessage(hwnd, WM_CLOSE, 0, 0);
                    break;
            }
            return 0;
        }
        
        case WM_DESTROY:
        {
            UnregisterHotKey(hwnd, ID_HOTKEY_HELLO);
            UnregisterHotKey(hwnd, ID_HOTKEY_EXIT);
            PostQuitMessage(0);
            return 0;
        }
    }
    
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
```

**Test it:** Compile and run, then press Ctrl+Shift+H from any application - the message box appears!

## Advanced Hotkey Techniques

### Dynamic Hotkey Registration

Allow users to customize hotkeys:

```c
typedef struct {
    int id;
    UINT modifiers;
    UINT vk;
    const wchar_t* description;
} HotkeyConfig;

HotkeyConfig g_hotkeys[] = {
    {ID_HOTKEY_OPEN, MOD_CONTROL | MOD_SHIFT, 'R', L"Open WinRDP"},
    {ID_HOTKEY_CONNECT, MOD_CONTROL | MOD_SHIFT, 'C', L"Quick Connect"},
    {0, 0, 0, NULL}  // Sentinel
};

BOOL RegisterAllHotkeys(HWND hwnd)
{
    int registered = 0;
    
    for (int i = 0; g_hotkeys[i].id != 0; i++) {
        if (RegisterHotKey(hwnd, g_hotkeys[i].id,
                          g_hotkeys[i].modifiers,
                          g_hotkeys[i].vk)) {
            registered++;
        } else {
            wchar_t msg[256];
            swprintf_s(msg, 256, L"Failed to register: %s", 
                      g_hotkeys[i].description);
            OutputDebugString(msg);
        }
    }
    
    return registered > 0;  // Success if at least one registered
}

void UnregisterAllHotkeys(HWND hwnd)
{
    for (int i = 0; g_hotkeys[i].id != 0; i++) {
        UnregisterHotKey(hwnd, g_hotkeys[i].id);
    }
}
```

### Checking Hotkey Availability

Before registering, check if hotkey is available:

```c
BOOL IsHotkeyAvailable(UINT modifiers, UINT vk)
{
    // Try to register the hotkey
    BOOL success = RegisterHotKey(NULL, 0, modifiers, vk);
    
    if (success) {
        // It worked - unregister it
        UnregisterHotKey(NULL, 0);
        return TRUE;
    }
    
    return FALSE;
}

// Usage:
if (IsHotkeyAvailable(MOD_CONTROL | MOD_SHIFT, 'R')) {
    // Can use Ctrl+Shift+R
} else {
    // Already in use, suggest alternative
}
```

### MOD_NOREPEAT Flag

Prevent repeated WM_HOTKEY messages when key is held:

```c
// Windows 7+
RegisterHotKey(hwnd, id, MOD_CONTROL | MOD_SHIFT | MOD_NOREPEAT, 'R');
```

**Without MOD_NOREPEAT:** Holding Ctrl+Shift+R sends multiple WM_HOTKEY messages  
**With MOD_NOREPEAT:** Only one WM_HOTKEY message, even if held down

## Best Practices

### 1. Don't Fail If Hotkey Registration Fails

```c
// WRONG - Application won't start if hotkey is in use
if (!RegisterHotKey(hwnd, ID_HOTKEY, MOD_CONTROL | MOD_SHIFT, 'R')) {
    MessageBox(NULL, L"Failed to register hotkey!", L"Error", MB_OK);
    return -1;  // Fail window creation
}

// CORRECT - Application works fine without hotkey
if (!RegisterHotKey(hwnd, ID_HOTKEY, MOD_CONTROL | MOD_SHIFT, 'R')) {
    // Log the failure but continue
    OutputDebugString(L"Note: Hotkey Ctrl+Shift+R not available\n");
}
```

### 2. Always Unregister Hotkeys

```c
case WM_DESTROY:
{
    // ALWAYS unregister before exiting
    UnregisterHotKey(hwnd, ID_HOTKEY_OPEN);
    UnregisterHotKey(hwnd, ID_HOTKEY_BULK_DELETE);
    
    PostQuitMessage(0);
    return 0;
}
```

### 3. Use Uncommon Key Combinations

```c
// AVOID - Too common, likely already in use
RegisterHotKey(hwnd, id, MOD_CONTROL, 'C');  // Ctrl+C - Copy!
RegisterHotKey(hwnd, id, MOD_ALT, VK_F4);    // Alt+F4 - Close window!

// GOOD - Less likely to conflict
RegisterHotKey(hwnd, id, MOD_CONTROL | MOD_SHIFT, 'R');
RegisterHotKey(hwnd, id, MOD_CONTROL | MOD_ALT, 'R');
```

### 4. Document Your Hotkeys

```c
// In your About dialog or Help:
MessageBox(hwnd,
    L"Global Hotkeys:\n\n"
    L"Ctrl+Shift+R - Open WinRDP\n"
    L"Ctrl+Shift+Alt+D - Bulk Delete (with confirmation)",
    L"Keyboard Shortcuts",
    MB_OK | MB_ICONINFORMATION);
```

### 5. Be Careful with Win Key

```c
// Use MOD_WIN sparingly - these are system shortcuts
RegisterHotKey(hwnd, id, MOD_WIN, 'R');  // Win+R opens Run dialog!

// If you must use Win key, combine with others:
RegisterHotKey(hwnd, id, MOD_WIN | MOD_SHIFT, 'R');  // Safer
```

## Common Hotkey Conflicts

### Avoiding System Hotkeys

Windows reserves many hotkey combinations. Avoid these:

```
Win+D          - Show Desktop
Win+E          - Explorer
Win+L          - Lock
Win+R          - Run dialog
Win+Tab        - Task View
Alt+Tab        - Switch windows
Alt+F4         - Close window
Ctrl+Alt+Del   - Security options
Ctrl+Shift+Esc - Task Manager
Ctrl+C/V/X/Z   - Clipboard/Undo
```

### Testing for Conflicts

```c
void TestHotkey(UINT modifiers, UINT vk, const wchar_t* description)
{
    if (RegisterHotKey(NULL, 0, modifiers, vk)) {
        UnregisterHotKey(NULL, 0);
        wprintf(L"✓ Available: %s\n", description);
    } else {
        wprintf(L"✗ In use: %s\n", description);
    }
}

// Test various combinations
TestHotkey(MOD_CONTROL | MOD_SHIFT, 'R', L"Ctrl+Shift+R");
TestHotkey(MOD_CONTROL | MOD_ALT, 'R', L"Ctrl+Alt+R");
TestHotkey(MOD_WIN | MOD_SHIFT, 'R', L"Win+Shift+R");
```

## Handling Hotkey Conflicts

### Graceful Fallback

```c
BOOL TryRegisterHotkey(HWND hwnd)
{
    // Try primary hotkey
    if (RegisterHotKey(hwnd, ID_HOTKEY_OPEN, MOD_CONTROL | MOD_SHIFT, 'R')) {
        return TRUE;
    }
    
    // Try alternative hotkey
    if (RegisterHotKey(hwnd, ID_HOTKEY_OPEN, MOD_CONTROL | MOD_ALT, 'R')) {
        MessageBox(hwnd,
            L"Note: Ctrl+Shift+R was unavailable.\n"
            L"Using Ctrl+Alt+R instead.",
            L"WinRDP",
            MB_OK | MB_ICONINFORMATION);
        return TRUE;
    }
    
    // Both failed
    MessageBox(hwnd,
        L"Could not register global hotkey.\n"
        L"You can still access WinRDP via the system tray.",
        L"WinRDP",
        MB_OK | MB_ICONINFORMATION);
    
    return FALSE;
}
```

### User-Configurable Hotkeys

Let users choose their own hotkey:

```c
// Simple version - hardcode a few options
void ShowHotkeySettings(HWND hwnd)
{
    const wchar_t* options = 
        L"Choose hotkey:\n\n"
        L"1. Ctrl+Shift+R (recommended)\n"
        L"2. Ctrl+Alt+R\n"
        L"3. Win+Shift+R\n"
        L"4. Disable hotkey";
    
    // Show dialog with radio buttons
    // Register selected hotkey
}
```

## Advanced: Custom Hotkey Dialog

```c
INT_PTR CALLBACK HotkeyDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static UINT g_selectedModifiers = MOD_CONTROL | MOD_SHIFT;
    static UINT g_selectedKey = 'R';
    
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Set current hotkey
            CheckRadioButton(hwnd, IDC_RADIO_CTRL, IDC_RADIO_WIN, IDC_RADIO_CTRL);
            CheckDlgButton(hwnd, IDC_CHECK_SHIFT, BST_CHECKED);
            SetDlgItemText(hwnd, IDC_EDIT_KEY, L"R");
            return TRUE;
        }
        
        case WM_COMMAND:
        {
            if (LOWORD(wParam) == IDOK)
            {
                // Build modifiers from checkboxes
                g_selectedModifiers = 0;
                if (IsDlgButtonChecked(hwnd, IDC_CHECK_CTRL))
                    g_selectedModifiers |= MOD_CONTROL;
                if (IsDlgButtonChecked(hwnd, IDC_CHECK_SHIFT))
                    g_selectedModifiers |= MOD_SHIFT;
                if (IsDlgButtonChecked(hwnd, IDC_CHECK_ALT))
                    g_selectedModifiers |= MOD_ALT;
                
                // Get key from edit control
                wchar_t keyText[10];
                GetDlgItemText(hwnd, IDC_EDIT_KEY, keyText, 10);
                g_selectedKey = towupper(keyText[0]);
                
                // Test if available
                if (IsHotkeyAvailable(g_selectedModifiers, g_selectedKey)) {
                    EndDialog(hwnd, IDOK);
                } else {
                    MessageBox(hwnd,
                        L"This hotkey is already in use.\n"
                        L"Please choose another combination.",
                        L"Hotkey In Use",
                        MB_OK | MB_ICONWARNING);
                }
                return TRUE;
            }
            else if (LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hwnd, IDCANCEL);
                return TRUE;
            }
            break;
        }
    }
    
    return FALSE;
}
```

## Debugging Hotkeys

### Check Registration Success

```c
void DebugHotkeys(HWND hwnd)
{
    wchar_t debug[1024] = L"Hotkey Status:\n\n";
    
    if (RegisterHotKey(NULL, 0, MOD_CONTROL | MOD_SHIFT, 'R')) {
        UnregisterHotKey(NULL, 0);
        wcscat_s(debug, 1024, L"Ctrl+Shift+R: Available\n");
    } else {
        wcscat_s(debug, 1024, L"Ctrl+Shift+R: In use\n");
    }
    
    if (RegisterHotKey(NULL, 0, MOD_CONTROL | MOD_ALT, 'R')) {
        UnregisterHotKey(NULL, 0);
        wcscat_s(debug, 1024, L"Ctrl+Alt+R: Available\n");
    } else {
        wcscat_s(debug, 1024, L"Ctrl+Alt+R: In use\n");
    }
    
    MessageBox(hwnd, debug, L"Hotkey Debug", MB_OK);
}
```

### Log Hotkey Messages

```c
case WM_HOTKEY:
{
    wchar_t msg[256];
    swprintf_s(msg, 256, L"WM_HOTKEY received: ID=%d\n", (int)wParam);
    OutputDebugString(msg);
    
    // ... handle hotkey ...
    
    return 0;
}
```

## Exercise 26.1: Simple Hotkey

Create an application that:
1. Registers Ctrl+Shift+M hotkey
2. Shows a message box when hotkey is pressed
3. Properly unregisters on exit

## Exercise 26.2: Multiple Hotkeys

Create an application with three hotkeys:
1. Ctrl+Shift+1 - Show "Option 1"
2. Ctrl+Shift+2 - Show "Option 2"
3. Ctrl+Shift+3 - Show "Option 3"

## Exercise 26.3: Hotkey Configuration

Create an application that:
1. Shows a dialog to configure hotkey
2. Lets user choose modifiers (Ctrl, Shift, Alt)
3. Lets user choose key letter
4. Tests if hotkey is available
5. Saves configuration to registry
6. Loads saved hotkey on startup

## Common Mistakes and Solutions

### Mistake 1: Not Unregistering Hotkeys

```c
// WRONG - Hotkey remains registered after app exits
case WM_DESTROY:
    PostQuitMessage(0);
    return 0;

// CORRECT - Always unregister
case WM_DESTROY:
    UnregisterHotKey(hwnd, ID_HOTKEY_OPEN);
    PostQuitMessage(0);
    return 0;
```

### Mistake 2: Failing Application If Hotkey Fails

```c
// WRONG - App won't start if hotkey is in use
if (!RegisterHotKey(hwnd, id, MOD_CONTROL | MOD_SHIFT, 'R')) {
    MessageBox(NULL, L"Hotkey registration failed!", L"Error", MB_OK);
    return -1;
}

// CORRECT - App works without hotkey
if (!RegisterHotKey(hwnd, id, MOD_CONTROL | MOD_SHIFT, 'R')) {
    // Just log it, app still works fine
    OutputDebugString(L"Hotkey not available\n");
}
```

### Mistake 3: Using Wrong Key Codes

```c
// WRONG - Using lowercase
RegisterHotKey(hwnd, id, MOD_CONTROL, 'r');  // Might work, but inconsistent

// CORRECT - Always use uppercase for letters
RegisterHotKey(hwnd, id, MOD_CONTROL, 'R');
```

## Platform Compatibility

### Windows Versions

- **Windows 2000+**: RegisterHotKey fully supported
- **Windows 7+**: MOD_NOREPEAT flag available
- **Windows 10+**: No special changes

### Limitations

- Maximum ~16,000 hotkeys per thread (theoretical)
- Hotkeys are per-process (can't register same hotkey twice in one app)
- Some combinations reserved by system

## Summary

In this chapter, you learned:

### **Hotkey Fundamentals**
- ✅ Understanding global hotkeys
- ✅ Virtual key codes and modifiers
- ✅ How Windows hotkey system works
- ✅ WM_HOTKEY message handling

### **Hotkey API**
- ✅ RegisterHotKey - Register global hotkey
- ✅ UnregisterHotKey - Remove hotkey
- ✅ MOD_CONTROL, MOD_SHIFT, MOD_ALT - Modifiers
- ✅ MOD_NOREPEAT - Prevent key repeat

### **Implementation Skills**
- ✅ Registering hotkeys on startup
- ✅ Handling WM_HOTKEY messages
- ✅ Unregistering hotkeys properly
- ✅ Graceful fallback when hotkey unavailable
- ✅ Testing hotkey availability

### **Best Practices**
- ✅ Don't fail if hotkey registration fails
- ✅ Always unregister hotkeys
- ✅ Use uncommon key combinations
- ✅ Document hotkeys for users
- ✅ Test for conflicts

### **Your WinRDP Application Now Has:**
- ✅ Ctrl+Shift+R to open from anywhere
- ✅ Ctrl+Shift+Alt+D for bulk delete
- ✅ Instant access without mouse
- ✅ Professional keyboard-driven workflow

**Next:** In Chapter 27, we'll implement dark mode support so WinRDP automatically matches the Windows theme!

---

# Chapter 27: Dark Mode Support

**What You'll Learn:**
- Detecting Windows dark mode settings
- Working with DWM (Desktop Window Manager) API
- Custom control color handling
- Creating dark-themed dialogs
- Function pointers and dynamic API loading
- Backwards compatibility techniques

## Introduction

Modern Windows applications should respect the user's theme preference. Since Windows 10, Microsoft has supported system-wide dark mode, and users expect applications to follow this setting automatically. In this chapter, we'll implement comprehensive dark mode support for WinRDP.

## Understanding Windows Dark Mode

### How Windows Dark Mode Works

Windows 10 (build 1809+) introduced dark mode for applications:
- Users can choose light or dark mode in Settings → Personalization → Colors
- The setting is stored in the registry
- Applications read this setting and adapt their UI
- System APIs help apply dark theme to title bars and controls

### Registry Detection

Windows stores the theme preference here:
```
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Themes\Personalize
Value: AppsUseLightTheme
0 = Dark Mode
1 = Light Mode (default)
```

## Implementing Dark Mode Detection

### Step 1: Check Dark Mode Status

```c
// darkmode.c
#include <windows.h>

BOOL IsDarkModeEnabled(void)
{
    HKEY hKey;
    DWORD dwValue = 1; // Default to light mode
    DWORD dwSize = sizeof(DWORD);
    
    // Read registry setting
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                      0,
                      KEY_READ,
                      &hKey) == ERROR_SUCCESS)
    {
        RegQueryValueExW(hKey, L"AppsUseLightTheme", NULL, NULL, 
                        (LPBYTE)&dwValue, &dwSize);
        RegCloseKey(hKey);
    }
    
    // 0 = Dark Mode, 1 = Light Mode
    return (dwValue == 0);
}
```

### Step 2: Define Dark Mode Colors

```c
// darkmode.h
#define DARK_BG_COLOR       RGB(32, 32, 32)      // Dark background
#define DARK_TEXT_COLOR     RGB(220, 220, 220)   // Light text
#define DARK_DIALOG_BG      RGB(43, 43, 43)      // Dialog background
#define DARK_CONTROL_BG     RGB(55, 55, 55)      // Edit controls, etc.
#define DARK_BORDER_COLOR   RGB(100, 100, 100)   // Borders

// Light mode colors (default Windows)
#define LIGHT_BG_COLOR      RGB(255, 255, 255)
#define LIGHT_TEXT_COLOR    RGB(0, 0, 0)
```

### Step 3: Create Dark Mode Brushes

```c
// Global brushes
static HBRUSH g_hBrushDialogBg = NULL;
static HBRUSH g_hBrushControlBg = NULL;
static BOOL g_bDarkModeEnabled = FALSE;

void InitDarkMode(void)
{
    g_bDarkModeEnabled = IsDarkModeEnabled();
    
    if (!g_bDarkModeEnabled)
        return;
    
    // Create brushes for painting backgrounds
    g_hBrushDialogBg = CreateSolidBrush(DARK_DIALOG_BG);
    g_hBrushControlBg = CreateSolidBrush(DARK_CONTROL_BG);
}

void CleanupDarkMode(void)
{
    if (g_hBrushDialogBg) {
        DeleteObject(g_hBrushDialogBg);
        g_hBrushDialogBg = NULL;
    }
    if (g_hBrushControlBg) {
        DeleteObject(g_hBrushControlBg);
        g_hBrushControlBg = NULL;
    }
}
```

## Applying Dark Mode to Dialogs

### Handling WM_CTLCOLOR Messages

Windows sends WM_CTLCOLOR* messages before drawing controls, allowing you to customize colors:

```c
INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (!g_bDarkModeEnabled)
        return 0;
    
    switch (msg)
    {
        case WM_CTLCOLORDLG:
            // Dialog background
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLORSTATIC:
            // Static text (labels)
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_DIALOG_BG);
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLOREDIT:
            // Edit controls
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
        
        case WM_CTLCOLORLISTBOX:
            // List boxes
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
    }
    
    return 0;
}
```

### Dark Title Bar (Windows 10+)

Use DWM API to make the title bar dark:

```c
#include <dwmapi.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

void ApplyDarkModeToDialog(HWND hwnd)
{
    if (!g_bDarkModeEnabled)
        return;
    
    // Set dark title bar (Windows 10 build 1809+)
    BOOL useDarkMode = TRUE;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE,
                         &useDarkMode, sizeof(useDarkMode));
}
```

### Integrating into Dialog Procedure

```c
INT_PTR CALLBACK MyDialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
        {
            // Apply dark mode to this dialog
            ApplyDarkModeToDialog(hwnd);
            return TRUE;
        }
    }
    
    // Handle dark mode color messages
    INT_PTR result = HandleDarkModeMessages(hwnd, msg, wParam, lParam);
    if (result != 0)
        return result;
    
    // ... rest of dialog handling ...
    
    return FALSE;
}
```

## Complete Dark Mode Module

**darkmode.h:**
```c
#ifndef DARKMODE_H
#define DARKMODE_H

#include <windows.h>

// Color definitions
#define DARK_BG_COLOR       RGB(32, 32, 32)
#define DARK_TEXT_COLOR     RGB(220, 220, 220)
#define DARK_DIALOG_BG      RGB(43, 43, 43)
#define DARK_CONTROL_BG     RGB(55, 55, 55)

// Dark mode functions
BOOL IsDarkModeEnabled(void);
void InitDarkMode(void);
void CleanupDarkMode(void);
void ApplyDarkModeToDialog(HWND hwnd);
void ApplyDarkModeToListView(HWND hListView);
INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif // DARKMODE_H
```

**darkmode.c:**
```c
#include "darkmode.h"
#include <dwmapi.h>
#include <uxtheme.h>
#include <commctrl.h>

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif

static HBRUSH g_hBrushDialogBg = NULL;
static HBRUSH g_hBrushControlBg = NULL;
static BOOL g_bDarkModeEnabled = FALSE;

BOOL IsDarkModeEnabled(void)
{
    HKEY hKey;
    DWORD dwValue = 1;
    DWORD dwSize = sizeof(DWORD);
    
    if (RegOpenKeyExW(HKEY_CURRENT_USER,
                      L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        RegQueryValueExW(hKey, L"AppsUseLightTheme", NULL, NULL,
                        (LPBYTE)&dwValue, &dwSize);
        RegCloseKey(hKey);
    }
    
    return (dwValue == 0);
}

void InitDarkMode(void)
{
    g_bDarkModeEnabled = IsDarkModeEnabled();
    
    if (!g_bDarkModeEnabled)
        return;
    
    g_hBrushDialogBg = CreateSolidBrush(DARK_DIALOG_BG);
    g_hBrushControlBg = CreateSolidBrush(DARK_CONTROL_BG);
}

void CleanupDarkMode(void)
{
    if (g_hBrushDialogBg) {
        DeleteObject(g_hBrushDialogBg);
        g_hBrushDialogBg = NULL;
    }
    if (g_hBrushControlBg) {
        DeleteObject(g_hBrushControlBg);
        g_hBrushControlBg = NULL;
    }
}

void ApplyDarkModeToDialog(HWND hwnd)
{
    if (!g_bDarkModeEnabled)
        return;
    
    BOOL useDarkMode = TRUE;
    DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE,
                         &useDarkMode, sizeof(useDarkMode));
}

void ApplyDarkModeToListView(HWND hListView)
{
    if (!g_bDarkModeEnabled)
        return;
    
    // Set ListView colors for dark mode
    ListView_SetTextColor(hListView, DARK_TEXT_COLOR);
    ListView_SetTextBkColor(hListView, DARK_CONTROL_BG);
    ListView_SetBkColor(hListView, DARK_CONTROL_BG);
}

INT_PTR HandleDarkModeMessages(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (!g_bDarkModeEnabled)
        return 0;
    
    switch (msg)
    {
        case WM_CTLCOLORDLG:
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLORSTATIC:
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_DIALOG_BG);
            return (INT_PTR)g_hBrushDialogBg;
        
        case WM_CTLCOLOREDIT:
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
        
        case WM_CTLCOLORLISTBOX:
            SetTextColor((HDC)wParam, DARK_TEXT_COLOR);
            SetBkColor((HDC)wParam, DARK_CONTROL_BG);
            return (INT_PTR)g_hBrushControlBg;
    }
    
    return 0;
}
```

## Backwards Compatibility

Support older Windows versions that don't have dark mode:

```c
void ApplyDarkModeToDialog(HWND hwnd)
{
    if (!g_bDarkModeEnabled)
        return;
    
    // Check if running on Windows 10 build 1809+
    OSVERSIONINFOEXW osvi = {sizeof(osvi)};
    if (GetVersionExW((OSVERSIONINFOW*)&osvi))
    {
        // Windows 10 is version 10.0
        if (osvi.dwMajorVersion >= 10 && osvi.dwBuildNumber >= 17763)
        {
            // Safe to use DWMWA_USE_IMMERSIVE_DARK_MODE
            BOOL useDarkMode = TRUE;
            DwmSetWindowAttribute(hwnd, DWMWA_USE_IMMERSIVE_DARK_MODE,
                                 &useDarkMode, sizeof(useDarkMode));
        }
    }
}
```

## Summary

In this chapter, you learned:

### **Dark Mode Fundamentals**
- ✅ Detecting Windows dark mode from registry
- ✅ Creating dark color schemes
- ✅ Understanding WM_CTLCOLOR messages

### **Implementation**
- ✅ IsDarkModeEnabled() - Check system preference
- ✅ InitDarkMode() - Initialize dark mode support
- ✅ ApplyDarkModeToDialog() - Dark title bars
- ✅ HandleDarkModeMessages() - Custom control colors

### **Your WinRDP Application Now Has:**
- ✅ Automatic dark mode detection
- ✅ Dark-themed dialogs and controls
- ✅ Professional Windows 10/11 integration
- ✅ Backwards compatibility with older Windows

**Next:** In Chapter 28, we'll implement network computer discovery to automatically find RDP servers!

---

# Chapter 28: Network Computer Discovery

**What You'll Learn:**
- Using NetAPI32 for network enumeration
- NetServerEnum function
- Working with SERVER_INFO structures
- Managing NetAPI buffers
- Filtering computer types

## Introduction

WinRDP can automatically discover computers on your network, saving users from manually entering hostnames. This chapter implements network scanning using Windows NetAPI32.

## The NetServerEnum API

```c
#include <lm.h>  // NetAPI32 header

NET_API_STATUS NetServerEnum(
    LPCWSTR servername,        // NULL = local computer
    DWORD level,               // Info level (101 = name + comment)
    LPBYTE *bufptr,            // Receives buffer pointer
    DWORD prefmaxlen,          // Buffer size preference
    LPDWORD entriesread,       // Entries actually read
    LPDWORD totalentries,      // Total entries available
    DWORD servertype,          // Type filter (SV_TYPE_*)
    LPCWSTR domain,            // Domain (NULL = current)
    LPDWORD resume_handle      // For paging results
);
```

## Complete Implementation

**adscan.h:**
```c
#ifndef ADSCAN_H
#define ADSCAN_H

#include <windows.h>

typedef struct {
    wchar_t name[256];
    wchar_t comment[256];
    DWORD type;
} ComputerInfo;

BOOL ScanForComputers(
    const wchar_t* domain,
    BOOL includeWorkstations,
    BOOL includeServers,
    BOOL includeDomainControllers,
    ComputerInfo** computers,
    int* count
);

void FreeComputerList(ComputerInfo* computers);

#endif
```

**adscan.c:**
```c
#include "adscan.h"
#include <lm.h>
#include <stdlib.h>

#pragma comment(lib, "netapi32.lib")

BOOL ScanForComputers(const wchar_t* domain, BOOL includeWorkstations,
                      BOOL includeServers, BOOL includeDomainControllers,
                      ComputerInfo** computers, int* count)
{
    SERVER_INFO_101* buffer = NULL;
    DWORD entriesRead = 0;
    DWORD totalEntries = 0;
    DWORD resumeHandle = 0;
    DWORD serverType = 0;
    
    *computers = NULL;
    *count = 0;
    
    // Build server type filter
    if (includeWorkstations)
        serverType |= SV_TYPE_WORKSTATION;
    if (includeServers)
        serverType |= SV_TYPE_SERVER;
    if (includeDomainControllers)
        serverType |= SV_TYPE_DOMAIN_CTRL;
    
    // Enumerate servers
    NET_API_STATUS status = NetServerEnum(
        NULL,                    // Local computer
        101,                     // Level 101 (name + comment)
        (LPBYTE*)&buffer,
        MAX_PREFERRED_LENGTH,
        &entriesRead,
        &totalEntries,
        serverType,
        domain,
        &resumeHandle
    );
    
    if (status != NERR_Success)
        return FALSE;
    
    // Allocate result array
    *computers = (ComputerInfo*)malloc(entriesRead * sizeof(ComputerInfo));
    if (*computers == NULL) {
        NetApiBufferFree(buffer);
        return FALSE;
    }
    
    // Copy data
    for (DWORD i = 0; i < entriesRead; i++) {
        wcscpy_s((*computers)[i].name, 256, buffer[i].sv101_name);
        wcscpy_s((*computers)[i].comment, 256, 
                buffer[i].sv101_comment ? buffer[i].sv101_comment : L"");
        (*computers)[i].type = buffer[i].sv101_type;
    }
    
    *count = (int)entriesRead;
    
    // MUST free NetAPI buffer
    NetApiBufferFree(buffer);
    
    return TRUE;
}

void FreeComputerList(ComputerInfo* computers)
{
    free(computers);
}
```

## Integration with WinRDP

```c
// In dialog procedure
case IDC_BTN_SCAN_NETWORK:
{
    ComputerInfo* computers;
    int count;
    
    if (ScanForComputers(NULL, TRUE, TRUE, FALSE, &computers, &count))
    {
        for (int i = 0; i < count; i++) {
            AddHost(computers[i].name, computers[i].comment);
        }
        
        FreeComputerList(computers);
        
        wchar_t msg[256];
        swprintf_s(msg, 256, L"Found %d computers", count);
        MessageBox(hwnd, msg, L"Scan Complete", MB_OK);
        
        RefreshHostList(hwnd);
    }
    break;
}
```

## Summary

In this chapter, you learned:

### **Network APIs**
- ✅ NetServerEnum for computer enumeration
- ✅ SERVER_INFO_101 structure
- ✅ NetApiBufferFree for cleanup

### **Your WinRDP Application Now Has:**
- ✅ Automatic computer discovery
- ✅ Network scanning functionality
- ✅ Easy host addition

**Next:** In Chapter 29, we'll create a professional installer!

---

# Chapter 29: Building and Distribution

**What You'll Learn:**
- Creating build scripts
- Compiling with GCC and MSVC
- NSIS installer creation
- Distribution best practices

## Building WinRDP

### Build Script (build.bat)

```batch
@echo off
echo Building WinRDP...

REM Create build directory
if not exist build mkdir build
if not exist build\obj mkdir build\obj

REM Compile resources
windres src\resources.rc -o build\obj\resources.o

REM Compile C files
gcc -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE ^
    -c src\main.c src\credentials.c src\hosts.c src\rdp.c ^
    src\registry.c src\darkmode.c src\adscan.c src\utils.c ^
    -Isrc

REM Move object files
move *.o build\obj\

REM Link
gcc -mwindows -municode -o build\WinRDP.exe build\obj\*.o ^
    -lcomctl32 -lshell32 -ladvapi32 -lcredui -ldwmapi -lnetapi32

if %errorlevel% == 0 (
    echo Build successful!
    echo Executable: build\WinRDP.exe
) else (
    echo Build failed!
)
```

## NSIS Installer

**installer.nsi:**
```nsis
!define APP_NAME "WinRDP"
!define APP_VERSION "1.4.0"
!define APP_PUBLISHER "Your Name"
!define APP_EXE "WinRDP.exe"

Name "${APP_NAME}"
OutFile "WinRDP-Setup-${APP_VERSION}.exe"
InstallDir "$PROGRAMFILES64\${APP_NAME}"

Page directory
Page instfiles

Section "Install"
    SetOutPath "$INSTDIR"
    File "build\${APP_EXE}"
    
    CreateDirectory "$SMPROGRAMS\${APP_NAME}"
    CreateShortcut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\${APP_EXE}"
    
    WriteUninstaller "$INSTDIR\Uninstall.exe"
    
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" \
                "DisplayName" "${APP_NAME}"
    WriteRegStr HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}" \
                "UninstallString" "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Uninstall"
    Delete "$INSTDIR\${APP_EXE}"
    Delete "$INSTDIR\Uninstall.exe"
    Delete "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk"
    RMDir "$SMPROGRAMS\${APP_NAME}"
    RMDir "$INSTDIR"
    
    DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\${APP_NAME}"
SectionEnd
```

Build installer:
```batch
makensis installer.nsi
```

## Summary

### **Your WinRDP Application Is Now:**
- ✅ Fully compiled and functional
- ✅ Packaged in a professional installer
- ✅ Ready for distribution!

**Congratulations!** You've completed Part V and built a professional Windows application from scratch!

---

# Part VI: Testing and Quality Assurance

# Chapter 30: System Testing and Integration

## Introduction

Testing is a critical phase in software development that ensures your application works correctly, reliably, and meets its requirements. In this chapter, we'll explore various testing strategies for Windows applications, focusing on how to test WinRDP comprehensively.

While C doesn't have built-in testing frameworks like some modern languages, we can still implement systematic testing approaches that ensure our application is production-ready.

## Why Testing Matters

Before diving into testing strategies, let's understand why testing is crucial:

1. **Catch bugs early**: Find issues before users do
2. **Prevent regressions**: Ensure new changes don't break existing functionality
3. **Document behavior**: Tests serve as living documentation
4. **Build confidence**: Ship updates knowing they won't break production
5. **Save time**: Automated tests are faster than manual testing

## Types of Testing

### 1. Unit Testing

**Unit testing** focuses on testing individual functions in isolation.

**Example: Testing String Validation**

```c
// utils.c - Function to test
BOOL IsValidHostname(const wchar_t* hostname)
{
    if (hostname == NULL || wcslen(hostname) == 0)
        return FALSE;
    
    if (wcspbrk(hostname, L"<>:\"/\\|?*") != NULL)
        return FALSE;
    
    if (wcslen(hostname) > 255)
        return FALSE;
    
    return TRUE;
}

// test_utils.c - Unit test
void TestIsValidHostname(void)
{
    // Test NULL input
    assert(IsValidHostname(NULL) == FALSE);
    
    // Test empty string
    assert(IsValidHostname(L"") == FALSE);
    
    // Test valid hostnames
    assert(IsValidHostname(L"server1") == TRUE);
    assert(IsValidHostname(L"192.168.1.100") == TRUE);
    assert(IsValidHostname(L"my-server.domain.com") == TRUE);
    
    // Test invalid characters
    assert(IsValidHostname(L"server<1>") == FALSE);
    assert(IsValidHostname(L"server:123") == FALSE);
    
    // Test too long
    wchar_t longName[300];
    wmemset(longName, L'a', 299);
    longName[299] = L'\0';
    assert(IsValidHostname(longName) == FALSE);
    
    printf("✓ All hostname validation tests passed\n");
}
```

**Creating a Simple Test Framework**

```c
// test_framework.h
#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <assert.h>

// Test statistics
typedef struct {
    int total;
    int passed;
    int failed;
} TestStats;

static TestStats g_TestStats = {0, 0, 0};

// Macros for testing
#define TEST_ASSERT(condition, message) \
    do { \
        g_TestStats.total++; \
        if (condition) { \
            g_TestStats.passed++; \
            printf("  ✓ PASS: %s\n", message); \
        } else { \
            g_TestStats.failed++; \
            printf("  ✗ FAIL: %s\n", message); \
        } \
    } while(0)

#define TEST_ASSERT_EQUAL(expected, actual, message) \
    TEST_ASSERT((expected) == (actual), message)

#define TEST_ASSERT_NOT_NULL(ptr, message) \
    TEST_ASSERT((ptr) != NULL, message)

#define RUN_TEST(test_func) \
    do { \
        printf("\n▶ Running %s...\n", #test_func); \
        test_func(); \
    } while(0)

#define PRINT_TEST_SUMMARY() \
    do { \
        printf("\n" \
               "═══════════════════════════════════\n" \
               "Test Summary\n" \
               "═══════════════════════════════════\n" \
               "Total:  %d\n" \
               "Passed: %d (%.1f%%)\n" \
               "Failed: %d\n" \
               "═══════════════════════════════════\n", \
               g_TestStats.total, \
               g_TestStats.passed, \
               g_TestStats.total > 0 ? (g_TestStats.passed * 100.0 / g_TestStats.total) : 0, \
               g_TestStats.failed); \
    } while(0)

#endif // TEST_FRAMEWORK_H
```

### 2. Integration Testing

**Integration testing** verifies that multiple components work together correctly.

**Example: Testing CSV File Operations**

```c
// test_hosts.c
#include "test_framework.h"
#include "hosts.h"

void TestLoadSaveHosts(void)
{
    const wchar_t* testFile = L"test_hosts.csv";
    
    // Create test data
    HostEntry* hosts = NULL;
    int count = 0;
    
    // Add some test hosts
    if (AddHost(&hosts, &count, L"TestServer1", L"192.168.1.100", L"testuser1"))
    {
        TEST_ASSERT(TRUE, "Added first test host");
    }
    
    if (AddHost(&hosts, &count, L"TestServer2", L"192.168.1.101", L"testuser2"))
    {
        TEST_ASSERT(TRUE, "Added second test host");
    }
    
    TEST_ASSERT_EQUAL(2, count, "Host count is correct");
    
    // Save to file
    BOOL saved = SaveHosts(testFile, hosts, count);
    TEST_ASSERT(saved, "Hosts saved to file");
    
    // Clear current hosts
    FreeHosts(hosts, count);
    hosts = NULL;
    count = 0;
    
    // Load from file
    hosts = LoadHosts(testFile, &count);
    TEST_ASSERT_NOT_NULL(hosts, "Hosts loaded from file");
    TEST_ASSERT_EQUAL(2, count, "Loaded correct number of hosts");
    
    // Verify data
    if (hosts && count >= 2)
    {
        TEST_ASSERT(wcscmp(hosts[0].name, L"TestServer1") == 0, 
                   "First host name correct");
        TEST_ASSERT(wcscmp(hosts[0].address, L"192.168.1.100") == 0, 
                   "First host address correct");
        TEST_ASSERT(wcscmp(hosts[1].name, L"TestServer2") == 0, 
                   "Second host name correct");
    }
    
    // Cleanup
    FreeHosts(hosts, count);
    DeleteFileW(testFile);
}

void TestHostSearch(void)
{
    HostEntry* hosts = NULL;
    int count = 0;
    
    // Add test data
    AddHost(&hosts, &count, L"WebServer", L"192.168.1.100", L"admin");
    AddHost(&hosts, &count, L"DatabaseServer", L"192.168.1.101", L"dbadmin");
    AddHost(&hosts, &count, L"FileServer", L"192.168.1.102", L"admin");
    
    // Test search
    int* results = NULL;
    int resultCount = 0;
    
    SearchHosts(hosts, count, L"server", &results, &resultCount);
    TEST_ASSERT_EQUAL(3, resultCount, "Search 'server' found all hosts");
    
    free(results);
    results = NULL;
    resultCount = 0;
    
    SearchHosts(hosts, count, L"Web", &results, &resultCount);
    TEST_ASSERT_EQUAL(1, resultCount, "Search 'Web' found one host");
    
    // Cleanup
    free(results);
    FreeHosts(hosts, count);
}
```

### 3. Functional Testing

**Functional testing** verifies that features work according to specifications.

**Testing Credential Management**

```c
// test_credentials.c
void TestCredentialOperations(void)
{
    const wchar_t* testHostname = L"test-server.local";
    const wchar_t* testUsername = L"testuser";
    const wchar_t* testPassword = L"testpass123";
    
    // Test saving credentials
    BOOL saved = SaveRDPCredentials(testHostname, testUsername, testPassword);
    TEST_ASSERT(saved, "Credentials saved successfully");
    
    // Test retrieving credentials
    wchar_t retrievedUser[256] = {0};
    wchar_t retrievedPass[256] = {0};
    
    BOOL retrieved = GetRDPCredentials(testHostname, 
                                       retrievedUser, sizeof(retrievedUser)/sizeof(wchar_t),
                                       retrievedPass, sizeof(retrievedPass)/sizeof(wchar_t));
    
    TEST_ASSERT(retrieved, "Credentials retrieved successfully");
    TEST_ASSERT(wcscmp(retrievedUser, testUsername) == 0, "Username matches");
    TEST_ASSERT(wcscmp(retrievedPass, testPassword) == 0, "Password matches");
    
    // Test deleting credentials
    BOOL deleted = DeleteRDPCredentials(testHostname);
    TEST_ASSERT(deleted, "Credentials deleted successfully");
    
    // Verify deletion
    retrieved = GetRDPCredentials(testHostname, 
                                  retrievedUser, sizeof(retrievedUser)/sizeof(wchar_t),
                                  retrievedPass, sizeof(retrievedPass)/sizeof(wchar_t));
    
    TEST_ASSERT(!retrieved, "Credentials no longer exist after deletion");
}
```

### 4. System Testing

**System testing** validates the entire application in a production-like environment.

**Manual Test Checklist**

Create a comprehensive test plan covering all features:

```c
// test_plan.h - System test checklist

typedef struct {
    const char* testCase;
    const char* expectedResult;
    BOOL passed;
} SystemTestCase;

SystemTestCase g_SystemTests[] = {
    // Application Startup
    {"Launch application", "System tray icon appears", FALSE},
    {"Double-click tray icon", "Main window opens", FALSE},
    {"Check dark mode", "Theme applied correctly", FALSE},
    
    // Host Management
    {"Add new host", "Host appears in list", FALSE},
    {"Edit existing host", "Changes saved correctly", FALSE},
    {"Delete host", "Host removed from list", FALSE},
    {"Search hosts", "Matching hosts highlighted", FALSE},
    
    // Credential Management
    {"Save credentials", "Stored in Credential Manager", FALSE},
    {"Update credentials", "New credentials work", FALSE},
    {"Delete credentials", "Credentials removed", FALSE},
    
    // RDP Connection
    {"Connect to host", "RDP client launches", FALSE},
    {"Connect with credentials", "Auto-login works", FALSE},
    {"Quick connect", "Dialog works correctly", FALSE},
    
    // Advanced Features
    {"Global hotkey", "Window activates on hotkey", FALSE},
    {"Network scan", "Discovers computers", FALSE},
    {"Export hosts", "CSV file created", FALSE},
    {"Import hosts", "Hosts loaded correctly", FALSE},
    
    // Settings
    {"Toggle autostart", "Registry key updated", FALSE},
    {"Toggle dark mode", "Theme switches", FALSE},
    {"Change hotkey", "New hotkey works", FALSE},
    
    // Error Handling
    {"Invalid hostname", "Error message shown", FALSE},
    {"Network error", "Graceful error handling", FALSE},
    {"Missing credentials", "Prompts for credentials", FALSE},
    
    // Performance
    {"Load 100+ hosts", "No lag or slowdown", FALSE},
    {"Rapid search", "Instant results", FALSE},
    {"Multiple connections", "All work correctly", FALSE}
};

void PrintSystemTestReport(void)
{
    int total = sizeof(g_SystemTests) / sizeof(SystemTestCase);
    int passed = 0;
    
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("                 SYSTEM TEST REPORT                    \n");
    printf("═══════════════════════════════════════════════════════\n\n");
    
    for (int i = 0; i < total; i++)
    {
        printf("%c %-40s | %s\n",
               g_SystemTests[i].passed ? '✓' : '✗',
               g_SystemTests[i].testCase,
               g_SystemTests[i].expectedResult);
        
        if (g_SystemTests[i].passed)
            passed++;
    }
    
    printf("\n═══════════════════════════════════════════════════════\n");
    printf("Results: %d/%d passed (%.1f%%)\n", 
           passed, total, (passed * 100.0) / total);
    printf("═══════════════════════════════════════════════════════\n");
}
```

## Creating a Test Suite

Let's create a complete test suite for WinRDP:

```c
// test_main.c - Main test runner
#include <windows.h>
#include "test_framework.h"
#include "hosts.h"
#include "credentials.h"
#include "utils.h"

// Forward declarations
void TestIsValidHostname(void);
void TestLoadSaveHosts(void);
void TestHostSearch(void);
void TestCredentialOperations(void);
void TestRDPFileGeneration(void);
void TestMemoryManagement(void);

int main(void)
{
    // Initialize (if needed)
    printf("═══════════════════════════════════\n");
    printf("   WinRDP Test Suite v1.0\n");
    printf("═══════════════════════════════════\n");
    
    // Run all unit tests
    printf("\n▶▶▶ UNIT TESTS\n");
    RUN_TEST(TestIsValidHostname);
    RUN_TEST(TestMemoryManagement);
    
    // Run integration tests
    printf("\n▶▶▶ INTEGRATION TESTS\n");
    RUN_TEST(TestLoadSaveHosts);
    RUN_TEST(TestHostSearch);
    
    // Run functional tests
    printf("\n▶▶▶ FUNCTIONAL TESTS\n");
    RUN_TEST(TestCredentialOperations);
    RUN_TEST(TestRDPFileGeneration);
    
    // Print summary
    PRINT_TEST_SUMMARY();
    
    return g_TestStats.failed == 0 ? 0 : 1;
}

void TestMemoryManagement(void)
{
    // Test memory allocation and deallocation
    HostEntry* hosts = NULL;
    int count = 0;
    
    // Add multiple hosts
    for (int i = 0; i < 10; i++)
    {
        wchar_t name[64];
        wchar_t addr[64];
        swprintf(name, 64, L"Server%d", i);
        swprintf(addr, 64, L"192.168.1.%d", 100 + i);
        
        BOOL added = AddHost(&hosts, &count, name, addr, L"user");
        TEST_ASSERT(added, "Host added successfully");
    }
    
    TEST_ASSERT_EQUAL(10, count, "All hosts added");
    TEST_ASSERT_NOT_NULL(hosts, "Host array allocated");
    
    // Free memory
    FreeHosts(hosts, count);
    
    // Note: Can't directly verify memory was freed,
    // but should run with memory leak detector
    printf("  ℹ Run with memory leak detector to verify\n");
}

void TestRDPFileGeneration(void)
{
    wchar_t rdpPath[MAX_PATH];
    
    BOOL created = CreateRDPFile(L"test-server", L"testuser", 
                                  rdpPath, MAX_PATH);
    
    TEST_ASSERT(created, "RDP file created");
    TEST_ASSERT_NOT_NULL(wcsstr(rdpPath, L".rdp"), "File has .rdp extension");
    
    // Verify file exists
    DWORD attrs = GetFileAttributesW(rdpPath);
    TEST_ASSERT(attrs != INVALID_FILE_ATTRIBUTES, "RDP file exists on disk");
    
    // Read and verify contents
    FILE* file = NULL;
    errno_t err = _wfopen_s(&file, rdpPath, L"r");
    TEST_ASSERT(err == 0 && file != NULL, "RDP file can be opened");
    
    if (file)
    {
        wchar_t line[256];
        BOOL foundFullAddress = FALSE;
        BOOL foundUsername = FALSE;
        
        while (fgetws(line, 256, file))
        {
            if (wcsstr(line, L"full address:s:test-server"))
                foundFullAddress = TRUE;
            if (wcsstr(line, L"username:s:testuser"))
                foundUsername = TRUE;
        }
        
        fclose(file);
        
        TEST_ASSERT(foundFullAddress, "RDP file contains hostname");
        TEST_ASSERT(foundUsername, "RDP file contains username");
    }
    
    // Cleanup
    DeleteFileW(rdpPath);
}
```

## Automated Testing with Scripts

Create batch files to automate testing:

**test.bat**
```batch
@echo off
echo ═══════════════════════════════════
echo   Building Test Suite
echo ═══════════════════════════════════

gcc -o test_suite.exe ^
    test_main.c ^
    src/hosts.c ^
    src/credentials.c ^
    src/utils.c ^
    src/rdp.c ^
    -I./src ^
    -ladvapi32 ^
    -lcredui ^
    -std=c11 ^
    -Wall

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b 1
)

echo.
echo ═══════════════════════════════════
echo   Running Tests
echo ═══════════════════════════════════
echo.

test_suite.exe

set TEST_RESULT=%ERRORLEVEL%

echo.
if %TEST_RESULT% EQU 0 (
    echo ════════════════════════════════
    echo   ✓ All Tests Passed!
    echo ════════════════════════════════
) else (
    echo ════════════════════════════════
    echo   ✗ Some Tests Failed
    echo ════════════════════════════════
)

exit /b %TEST_RESULT%
```

## Memory Leak Detection

Use tools to detect memory leaks:

**Windows: Application Verifier**
```batch
# Enable Application Verifier
appverif -enable Heaps Locks -for WinRDP.exe

# Run application
WinRDP.exe

# Check for leaks in log
```

**Manual Memory Tracking**
```c
// debug_memory.h - Simple memory tracker
#ifdef DEBUG_MEMORY

typedef struct {
    void* ptr;
    size_t size;
    const char* file;
    int line;
} MemAlloc;

static MemAlloc g_Allocations[1000];
static int g_AllocCount = 0;

#define MALLOC(size) debug_malloc(size, __FILE__, __LINE__)
#define FREE(ptr) debug_free(ptr, __FILE__, __LINE__)

void* debug_malloc(size_t size, const char* file, int line)
{
    void* ptr = malloc(size);
    if (ptr && g_AllocCount < 1000)
    {
        g_Allocations[g_AllocCount].ptr = ptr;
        g_Allocations[g_AllocCount].size = size;
        g_Allocations[g_AllocCount].file = file;
        g_Allocations[g_AllocCount].line = line;
        g_AllocCount++;
    }
    return ptr;
}

void debug_free(void* ptr, const char* file, int line)
{
    // Remove from tracking
    for (int i = 0; i < g_AllocCount; i++)
    {
        if (g_Allocations[i].ptr == ptr)
        {
            // Shift remaining allocations
            for (int j = i; j < g_AllocCount - 1; j++)
            {
                g_Allocations[j] = g_Allocations[j + 1];
            }
            g_AllocCount--;
            break;
        }
    }
    free(ptr);
}

void PrintMemoryLeaks(void)
{
    if (g_AllocCount > 0)
    {
        printf("═══════════════════════════════════\n");
        printf("   MEMORY LEAKS DETECTED!\n");
        printf("═══════════════════════════════════\n");
        
        for (int i = 0; i < g_AllocCount; i++)
        {
            printf("Leak: %zu bytes at %p\n"
                   "      Allocated in %s:%d\n",
                   g_Allocations[i].size,
                   g_Allocations[i].ptr,
                   g_Allocations[i].file,
                   g_Allocations[i].line);
        }
    }
    else
    {
        printf("✓ No memory leaks detected\n");
    }
}

#else
#define MALLOC(size) malloc(size)
#define FREE(ptr) free(ptr)
#define PrintMemoryLeaks()
#endif // DEBUG_MEMORY
```

## Performance Testing

Test application performance under load:

```c
// test_performance.c
#include <windows.h>
#include <stdio.h>
#include "hosts.h"

void TestLargeHostList(void)
{
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    
    HostEntry* hosts = NULL;
    int count = 0;
    
    // Test adding 1000 hosts
    QueryPerformanceCounter(&start);
    
    for (int i = 0; i < 1000; i++)
    {
        wchar_t name[64], addr[64];
        swprintf(name, 64, L"Server%04d", i);
        swprintf(addr, 64, L"192.168.%d.%d", i / 256, i % 256);
        AddHost(&hosts, &count, name, addr, L"user");
    }
    
    QueryPerformanceCounter(&end);
    
    double elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Added 1000 hosts in %.3f seconds (%.2f ms per host)\n",
           elapsed, elapsed * 1000.0 / 1000.0);
    
    // Test searching
    int* results = NULL;
    int resultCount = 0;
    
    QueryPerformanceCounter(&start);
    SearchHosts(hosts, count, L"Server05", &results, &resultCount);
    QueryPerformanceCounter(&end);
    
    elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Searched 1000 hosts in %.3f milliseconds\n", elapsed * 1000.0);
    printf("Found %d matches\n", resultCount);
    
    // Cleanup
    free(results);
    FreeHosts(hosts, count);
}

void TestFileIOPerformance(void)
{
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    
    // Create large test file
    HostEntry* hosts = NULL;
    int count = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        wchar_t name[64], addr[64];
        swprintf(name, 64, L"Server%04d", i);
        swprintf(addr, 64, L"192.168.%d.%d", i / 256, i % 256);
        AddHost(&hosts, &count, name, addr, L"user");
    }
    
    // Test save performance
    QueryPerformanceCounter(&start);
    SaveHosts(L"perf_test.csv", hosts, count);
    QueryPerformanceCounter(&end);
    
    double saveTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Saved 1000 hosts in %.3f milliseconds\n", saveTime * 1000.0);
    
    FreeHosts(hosts, count);
    hosts = NULL;
    count = 0;
    
    // Test load performance
    QueryPerformanceCounter(&start);
    hosts = LoadHosts(L"perf_test.csv", &count);
    QueryPerformanceCounter(&end);
    
    double loadTime = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Loaded 1000 hosts in %.3f milliseconds\n", loadTime * 1000.0);
    
    // Cleanup
    FreeHosts(hosts, count);
    DeleteFileW(L"perf_test.csv");
}
```

## UI Testing

Manual UI testing checklist:

### Visual Testing
1. **Layout**: All controls properly positioned
2. **Fonts**: Text readable in all themes
3. **Colors**: Dark mode works correctly
4. **Icons**: Displayed at correct size
5. **Scaling**: Works at different DPI settings

### Interaction Testing
1. **Buttons**: All respond to clicks
2. **Keyboard**: Tab order correct, shortcuts work
3. **Mouse**: Hover effects, right-click menus
4. **Resizing**: Window resizes smoothly
5. **Dialogs**: Modal dialogs work correctly

### Accessibility Testing
1. **Keyboard navigation**: All features accessible via keyboard
2. **Screen readers**: Labels read correctly
3. **High contrast**: Visible in high contrast mode
4. **Focus indicators**: Clear visual focus

## Error Condition Testing

Test how application handles errors:

```c
// test_errors.c
void TestErrorHandling(void)
{
    printf("\n▶ Testing Error Handling\n");
    
    // Test NULL parameters
    TEST_ASSERT(!IsValidHostname(NULL), "Handles NULL hostname");
    TEST_ASSERT(!SaveHosts(NULL, NULL, 0), "Handles NULL in SaveHosts");
    TEST_ASSERT(LoadHosts(L"nonexistent.csv", NULL) == NULL, 
                "Handles missing file");
    
    // Test invalid file paths
    TEST_ASSERT(!SaveHosts(L"C:\\InvalidPath\\<>test.csv", NULL, 0),
                "Handles invalid file path");
    
    // Test disk full (difficult to test automatically)
    printf("  ℹ Manual test: Disk full scenario\n");
    
    // Test permission denied
    printf("  ℹ Manual test: Permission denied scenario\n");
    
    // Test corrupted data
    // Create a corrupted CSV file
    FILE* file = NULL;
    _wfopen_s(&file, L"corrupted.csv", L"w");
    if (file)
    {
        fwprintf(file, L"Invalid,CSV,Data,Without,Proper,Format\n");
        fwprintf(file, L"Missing,Fields\n");
        fclose(file);
    }
    
    int count = 0;
    HostEntry* hosts = LoadHosts(L"corrupted.csv", &count);
    TEST_ASSERT(hosts == NULL || count == 0, 
                "Handles corrupted CSV gracefully");
    
    DeleteFileW(L"corrupted.csv");
}
```

## Regression Testing

Create a baseline test suite to prevent regressions:

```batch
REM regression_test.bat
@echo off

echo Running regression tests...

REM Save baseline
if not exist baseline_results.txt (
    echo Creating baseline...
    test_suite.exe > baseline_results.txt
    echo Baseline created. Run again to compare.
    exit /b 0
)

REM Run current tests
echo Running current tests...
test_suite.exe > current_results.txt

REM Compare results
fc baseline_results.txt current_results.txt > nul
if %ERRORLEVEL% EQU 0 (
    echo ✓ All tests match baseline - No regressions!
) else (
    echo ✗ Tests differ from baseline - Possible regression!
    echo Differences:
    fc baseline_results.txt current_results.txt
)
```

## Continuous Integration

For larger projects, set up CI/CD:

**.github/workflows/test.yml** (if using GitHub)
```yaml
name: Run Tests

on: [push, pull_request]

jobs:
  test:
    runs-on: windows-latest
    
    steps:
    - uses: actions/checkout@v2
    
    - name: Setup MinGW
      uses: egor-tensin/setup-mingw@v2
      
    - name: Build Tests
      run: gcc -o test_suite.exe test_main.c src/*.c -I./src
      
    - name: Run Tests
      run: ./test_suite.exe
      
    - name: Build Application
      run: ./build.bat
```

## Best Practices for Testing

### 1. Test Early and Often
```c
// Don't wait until the end - test as you develop
void NewFeature(void)
{
    // Implement feature
    // ...
    
    // Write test immediately
    TestNewFeature();
}
```

### 2. Test Edge Cases
```c
// Don't just test the happy path
void TestStringCopy(void)
{
    // Normal case
    TEST_ASSERT(CopyString(dest, src) == TRUE, "Normal copy works");
    
    // Edge cases
    TEST_ASSERT(CopyString(NULL, src) == FALSE, "Handles NULL dest");
    TEST_ASSERT(CopyString(dest, NULL) == FALSE, "Handles NULL src");
    TEST_ASSERT(CopyString(dest, "") == TRUE, "Handles empty string");
    TEST_ASSERT(CopyString(dest, veryLongString) == FALSE, "Handles overflow");
}
```

### 3. Keep Tests Independent
```c
// Each test should be able to run alone
void TestA(void)
{
    // Setup
    Initialize();
    
    // Test
    DoSomething();
    
    // Cleanup
    Cleanup();
}

void TestB(void)
{
    // Don't depend on TestA running first!
    Initialize();  // Own setup
    // ...
}
```

### 4. Make Tests Readable
```c
// Good - Clear what's being tested
void TestHostAddition(void)
{
    // Given: Empty host list
    HostEntry* hosts = NULL;
    int count = 0;
    
    // When: Adding a host
    BOOL result = AddHost(&hosts, &count, L"Server1", L"192.168.1.1", L"user");
    
    // Then: Host is added successfully
    TEST_ASSERT(result == TRUE, "Host added successfully");
    TEST_ASSERT(count == 1, "Count is 1");
    TEST_ASSERT(wcscmp(hosts[0].name, L"Server1") == 0, "Name is correct");
}
```

### 5. Test What Matters
```c
// Don't test trivial getters/setters
// DO test business logic, algorithms, edge cases

// Skip this:
void TestGetName(void)
{
    host.name = L"Server1";
    TEST_ASSERT(GetName(&host) == host.name, "Returns name");
}

// Test this instead:
void TestHostValidation(void)
{
    // Complex logic that can have bugs
    TEST_ASSERT(ValidateHost(&invalidHost) == FALSE, "Rejects invalid");
    TEST_ASSERT(ValidateHost(&validHost) == TRUE, "Accepts valid");
}
```

## Integration with Build Process

Update build.bat to include testing:

```batch
REM build.bat - Updated with testing
@echo off
echo ═══════════════════════════════════
echo   Building WinRDP
echo ═══════════════════════════════════

gcc src/*.c -o build/WinRDP.exe -mwindows -lcomctl32 -lnetapi32 -lcredui

if %ERRORLEVEL% NEQ 0 (
    echo Build failed!
    exit /b 1
)

echo Build successful!

REM Run tests if requested
if "%1"=="test" (
    echo.
    echo Running tests...
    call test.bat
)

echo.
echo To run with tests: build.bat test
```

## Exercises

### Exercise 1: Write Unit Tests
Create unit tests for utility functions in `utils.c`:
- Test `CreateTempPath()`
- Test `GetConfigDirectory()`
- Test string validation functions

### Exercise 2: Integration Test
Write an integration test that:
1. Creates a new host list
2. Saves to file
3. Modifies the list
4. Reloads from file
5. Verifies original data is preserved

### Exercise 3: Performance Baseline
Create performance tests and establish baselines:
- Measure load time for 1000 hosts
- Measure search time
- Compare against baselines

### Exercise 4: Error Injection
Test error handling by:
- Creating read-only files
- Filling disk space
- Corrupting data files
- Testing network failures

## Summary

In this chapter, you learned:

- **Different types of testing**: Unit, integration, functional, and system testing
- **Creating test frameworks**: Building simple testing infrastructure in C
- **Automated testing**: Using scripts to run tests automatically
- **Memory leak detection**: Tools and techniques to find memory issues
- **Performance testing**: Measuring and optimizing application performance
- **Error handling**: Testing failure scenarios
- **Best practices**: Writing maintainable, effective tests

Testing is not just about finding bugs—it's about building confidence in your code and ensuring your application works reliably for users.

## Key Takeaways

1. **Test early**: Don't wait until the end to start testing
2. **Test often**: Run tests after every change
3. **Test edge cases**: Don't just test the happy path
4. **Automate**: Manual testing is slow and error-prone
5. **Measure**: Use performance tests to catch slowdowns
6. **Document**: Tests serve as documentation of expected behavior
7. **Keep improving**: Add tests when bugs are found

## What's Next

Now that you understand testing, you can:
- Implement a complete test suite for WinRDP
- Set up automated testing in your build process
- Add performance monitoring
- Create a regression test baseline
- Explore continuous integration tools

Testing makes you a better developer by forcing you to think about edge cases, error conditions, and how your code will be used. It's an investment that pays dividends in code quality and reliability!

---

## What You Can Do Now

Even without the remaining chapters, you have a **fully functional RDP connection manager**! You can:

1. **Use it daily**: Manage your RDP connections
2. **Study the source code**: All features are implemented in `/src`
3. **Extend it yourself**: Try implementing the remaining features by studying the code
4. **Build it**: Use the existing build scripts
5. **Customize it**: Add your own features

The remaining chapters will guide you through the already-implemented advanced features in the codebase, but you have enough knowledge to explore them yourself!

---

## How to Continue Learning

### **Option 1: Wait for Remaining Chapters**
The remaining chapters will be written following the same detailed, example-driven format.

### **Option 2: Study the Source Code**
All features (including those not yet covered in chapters) are fully implemented and well-commented in `/src`:
- Study `main.c` for system tray implementation
- Review `registry.c` for autostart functionality  
- Examine `darkmode.c` for theme support
- Explore `adscan.c` for network scanning

### **Option 3: Build Your Own Features**
Now that you understand the architecture, try adding:
- Custom RDP settings per host
- Connection history logging
- Favorite hosts list
- Import/export functionality
- Multiple credential profiles
- Connection groups/folders

### **Option 4: Build a New Application**
Use what you've learned to create your own Windows application:
- File manager
- Text editor
- System monitor
- Backup utility
- Database viewer
- Custom tool for your workflow

---

## Congratulations! 🎉

You've completed **24 chapters** (23 core chapters + 1 testing chapter) and built a **real, working application**. That's a significant achievement! You now have:

- **Strong C fundamentals**
- **Windows programming skills**
- **A portfolio project**
- **Foundation for any C/Windows project**
- **The ability to read and understand professional C code**

The journey doesn't end here—it's just the beginning of what you can build with C and Windows!

**Keep coding, keep learning, and keep building amazing things!** 🚀

---

# Appendices

# Appendix A: Setting Up Your Development Environment

This appendix provides step-by-step instructions for setting up your C programming environment on Windows.

## Option 1: MinGW-w64 (GCC) - Recommended for Beginners

### Why MinGW-w64?
- ✅ Free and open source
- ✅ Industry-standard GCC compiler
- ✅ Good error messages
- ✅ Cross-platform knowledge
- ✅ Lighter weight than Visual Studio

### Installation Steps

**Step 1: Download MSYS2**

1. Go to https://www.msys2.org/
2. Download the installer (msys2-x86_64-YYYYMMDD.exe)
3. Run the installer
4. Install to default location: `C:\msys64`

**Step 2: Install MinGW-w64 Toolchain**

1. Open MSYS2 MinGW 64-bit terminal (from Start Menu)
2. Update package database:
```bash
pacman -Syu
```
3. Close terminal when prompted, reopen it
4. Install the compiler toolchain:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
```
5. Install additional tools:
```bash
pacman -S mingw-w64-x86_64-gdb  # Debugger
```

**Step 3: Add to System PATH**

1. Open System Environment Variables:
   - Press `Win + R`
   - Type `sysdm.cpl` and press Enter
   - Go to "Advanced" tab
   - Click "Environment Variables"

2. Edit the `Path` variable (User variables):
   - Click "New"
   - Add: `C:\msys64\mingw64\bin`
   - Click "OK" on all dialogs

3. Verify installation:
   - Open Command Prompt (cmd.exe)
   - Type: `gcc --version`
   - Should see GCC version information

### Testing Your Installation

Create `hello.c`:
```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

Compile and run:
```bash
gcc hello.c -o hello.exe
hello.exe
```

Should output: `Hello, World!`

---

## Option 2: Microsoft Visual Studio - Professional IDE

### Why Visual Studio?
- ✅ Professional development environment
- ✅ Excellent debugger
- ✅ IntelliSense code completion
- ✅ Built-in Windows SDK
- ✅ Industry standard for Windows development

### Installation Steps

**Step 1: Download Visual Studio**

1. Go to https://visualstudio.microsoft.com/
2. Download "Visual Studio Community" (free)
3. Run the installer

**Step 2: Select Workload**

In the Visual Studio Installer:
1. Select "Desktop development with C++"
2. Ensure these are checked:
   - MSVC v143 (or latest)
   - Windows 10/11 SDK
   - C++ CMake tools
   - Just-In-Time debugger

3. Click "Install" (requires several GB)

**Step 3: Configure for C Development**

1. Launch Visual Studio
2. Create new project:
   - File → New → Project
   - Select "Empty Project" (C++)
   - Name your project

3. Add a C file:
   - Right-click project in Solution Explorer
   - Add → New Item
   - Select "C++ File (.cpp)"
   - **Rename to .c extension** (important!)

4. Configure for C:
   - Project → Properties
   - C/C++ → Advanced
   - Set "Compile As" to "Compile as C Code (/TC)"

### Using Command Line (Optional)

Open "x64 Native Tools Command Prompt":
```bash
cl /W4 /D_UNICODE /DUNICODE hello.c
hello.exe
```

---

## Option 3: Visual Studio Code - Lightweight Editor

### Why VS Code?
- ✅ Lightweight and fast
- ✅ Excellent extensions
- ✅ Works with GCC or MSVC
- ✅ Modern interface
- ✅ Great for learning

### Setup Steps

**Step 1: Install VS Code**

1. Download from https://code.visualstudio.com/
2. Install with default options

**Step 2: Install Extensions**

Open VS Code and install:
- **C/C++** (by Microsoft) - IntelliSense and debugging
- **Code Runner** (by Jun Han) - Quick execution

**Step 3: Configure for GCC**

Create `.vscode/c_cpp_properties.json`:
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/msys64/mingw64/include"
            ],
            "compilerPath": "C:/msys64/mingw64/bin/gcc.exe",
            "cStandard": "c11",
            "intelliSenseMode": "gcc-x64"
        }
    ]
}
```

**Step 4: Build Configuration**

Create `.vscode/tasks.json`:
```json
{
    "version": "1.2.0.0",
    "tasks": [
        {
            "label": "Build C",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Press `Ctrl+Shift+B` to build!

---

## Installing NSIS (For Chapter 29)

**NSIS** creates professional installers for Windows applications.

**Installation:**
1. Download from https://nsis.sourceforge.io/Download
2. Run the installer
3. Add to PATH: `C:\Program Files (x86)\NSIS`

**Verify:**
```bash
makensis /VERSION
```

---

## Recommended Additional Tools

### Git for Version Control
```bash
# Download from: https://git-scm.com/
# After installation:
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

### DebugView for Windows Debugging
- Download from Sysinternals: https://docs.microsoft.com/en-us/sysinternals/
- View OutputDebugString messages
- Essential for debugging Windows applications

### Dependency Walker
- Download from: https://www.dependencywalker.com/
- See what DLLs your program needs
- Helpful for distribution

### Resource Hacker
- Download from: http://www.angusj.com/resourcehacker/
- Edit .rc resource files visually
- Inspect compiled resources

---

## Troubleshooting Common Issues

### "gcc not found" or "command not found"

**Solution:**
1. Verify GCC is installed: `C:\msys64\mingw64\bin\gcc.exe` exists
2. Check PATH includes: `C:\msys64\mingw64\bin`
3. Restart Command Prompt after PATH changes

### "Cannot open include file: 'windows.h'"

**Solution:**
- **MinGW:** Reinstall with: `pacman -S mingw-w64-x86_64-headers`
- **MSVC:** Install Windows SDK via Visual Studio Installer

### "windres not found"

**Solution:**
```bash
pacman -S mingw-w64-x86_64-binutils
```

### Programs crash immediately

**Solution:**
1. Check for missing DLLs with Dependency Walker
2. For MinGW programs, copy required DLLs from `C:\msys64\mingw64\bin`
3. Or compile with static linking: `-static`

---

## Building WinRDP

Once environment is set up:

```bash
# Clone repository (or download)
cd WinRDP

# Build with GCC
build.bat

# Or build with MSVC (from x64 Native Tools prompt)
cd src
cl /W4 /D_UNICODE /DUNICODE /D_WIN32_WINNT=0x0601 *.c resources.rc
link /OUT:WinRDP.exe *.obj *.res user32.lib gdi32.lib shell32.lib ^
     comctl32.lib advapi32.lib credui.lib dwmapi.lib netapi32.lib
```

---

## Editor Configuration Tips

### For Better Productivity

**Enable Auto-Save:**
- VS Code: File → Auto Save
- Visual Studio: Tools → Options → Environment → Documents → Auto-load changes

**Set Tab Width to 4 Spaces:**
```json
// VS Code settings.json
{
    "editor.tabSize": 4,
    "editor.insertSpaces": true
}
```

**Enable Line Numbers:**
- All editors have this, essential for following book examples

**Syntax Highlighting:**
- Ensure C files are recognized (check bottom-right in VS Code)

---

## Quick Reference Commands

### Compilation
```bash
# Simple compile
gcc program.c -o program.exe

# With warnings
gcc -Wall -Wextra program.c -o program.exe

# With debugging symbols
gcc -g program.c -o program.exe

# Windows GUI application
gcc -mwindows program.c -o program.exe

# Link libraries
gcc program.c -o program.exe -luser32 -lgdi32
```

### Debugging
```bash
# GDB debugger
gdb program.exe

# Common GDB commands:
# run - Start program
# break main - Set breakpoint
# step - Step one line
# print var - Print variable
# quit - Exit
```

### Resource Compilation
```bash
# Compile .rc file
windres resources.rc -o resources.o

# Link with program
gcc main.c resources.o -o program.exe
```

---

Your development environment is now ready! Proceed to Chapter 1 to begin learning C programming.

---

# Appendix B: Common Mistakes and How to Avoid Them

This appendix covers the most common mistakes C programmers make and how to avoid them.

## Memory Management Mistakes

### 1. Memory Leaks

**Mistake:**
```c
void LoadData(void)
{
    char* data = (char*)malloc(1024);
    // ... use data ...
    // Forgot to free!
}
```

**Solution:**
```c
void LoadData(void)
{
    char* data = (char*)malloc(1024);
    if (data == NULL) return;
    
    // ... use data ...
    
    free(data);  // Always free!
}
```

**Rule:** Every `malloc`/`calloc`/`realloc` needs a matching `free`.

### 2. Using Memory After Free

**Mistake:**
```c
char* ptr = (char*)malloc(100);
free(ptr);
strcpy(ptr, "Hello");  // WRONG: Using freed memory!
```

**Solution:**
```c
char* ptr = (char*)malloc(100);
strcpy(ptr, "Hello");
free(ptr);
ptr = NULL;  // Set to NULL after freeing
```

### 3. Freeing Stack Memory

**Mistake:**
```c
void BadFunction(void)
{
    char buffer[100];
    free(buffer);  // WRONG: Can't free stack memory!
}
```

**Solution:**
```c
void GoodFunction(void)
{
    char buffer[100];
    // Just let it go out of scope, no free needed
}
```

**Rule:** Only free memory allocated with `malloc`/`calloc`/`realloc`.

### 4. Double Free

**Mistake:**
```c
char* ptr = (char*)malloc(100);
free(ptr);
free(ptr);  // WRONG: Double free causes crash!
```

**Solution:**
```c
char* ptr = (char*)malloc(100);
free(ptr);
ptr = NULL;  // Prevents double free
if (ptr != NULL) free(ptr);  // Safe
```

---

## Pointer Mistakes

### 5. Dereferencing NULL

**Mistake:**
```c
char* ptr = NULL;
*ptr = 'A';  // CRASH: Dereferencing NULL!
```

**Solution:**
```c
char* ptr = NULL;
if (ptr != NULL) {
    *ptr = 'A';
}
```

**Always check pointers before dereferencing!**

### 6. Uninitialized Pointers

**Mistake:**
```c
char* ptr;  // Contains garbage
*ptr = 'A';  // Probably crash
```

**Solution:**
```c
char* ptr = NULL;  // Always initialize!
ptr = (char*)malloc(10);
if (ptr != NULL) {
    *ptr = 'A';
}
```

### 7. Buffer Overflow

**Mistake:**
```c
char buffer[10];
strcpy(buffer, "This string is way too long!");  // Overflow!
```

**Solution:**
```c
char buffer[10];
strncpy_s(buffer, sizeof(buffer), "Long string", _TRUNCATE);
// Or use safe functions:
strcpy_s(buffer, sizeof(buffer), "Short");
```

### 8. Returning Pointer to Local Variable

**Mistake:**
```c
char* GetName(void)
{
    char name[100] = "John";
    return name;  // WRONG: Returns pointer to stack memory!
}
```

**Solution:**
```c
char* GetName(void)
{
    char* name = (char*)malloc(100);
    if (name != NULL) {
        strcpy_s(name, 100, "John");
    }
    return name;  // Caller must free!
}

// Or use static (but not thread-safe):
char* GetName(void)
{
    static char name[100] = "John";
    return name;
}
```

---

## Windows API Mistakes

### 9. Not Checking Return Values

**Mistake:**
```c
HANDLE hFile = CreateFile(...);
WriteFile(hFile, ...);  // What if CreateFile failed?
```

**Solution:**
```c
HANDLE hFile = CreateFile(...);
if (hFile == INVALID_HANDLE_VALUE) {
    // Handle error
    return FALSE;
}
WriteFile(hFile, ...);
CloseHandle(hFile);
```

### 10. Forgetting to Close Handles

**Mistake:**
```c
HANDLE hFile = CreateFile(...);
// ... use file ...
// Forgot CloseHandle!
```

**Solution:**
```c
HANDLE hFile = CreateFile(...);
if (hFile != INVALID_HANDLE_VALUE) {
    // ... use file ...
    CloseHandle(hFile);  // Always close!
}
```

**Rule:** `CreateFile` → `CloseHandle`, `RegOpenKey` → `RegCloseKey`, etc.

### 11. Mixing Unicode and ANSI

**Mistake:**
```c
wchar_t wide[] = L"Hello";
MessageBoxA(NULL, wide, "Title", MB_OK);  // WRONG: A = ANSI, wide = Unicode
```

**Solution:**
```c
wchar_t wide[] = L"Hello";
MessageBoxW(NULL, wide, L"Title", MB_OK);  // W = Wide/Unicode
```

**Rule:** Use `W` functions with `wchar_t`, `A` functions with `char`.

### 12. Not Multiplying String Size for Unicode

**Mistake:**
```c
wchar_t str[] = L"Hello";
RegSetValueExW(hKey, L"Value", 0, REG_SZ, (BYTE*)str, wcslen(str));
// WRONG: Size should be in bytes!
```

**Solution:**
```c
wchar_t str[] = L"Hello";
RegSetValueExW(hKey, L"Value", 0, REG_SZ, (BYTE*)str,
               (wcslen(str) + 1) * sizeof(wchar_t));  // Bytes, not chars!
```

---

## String Mistakes

### 13. Off-by-One Errors

**Mistake:**
```c
char name[5] = "John";  // Needs 5 chars: J-o-h-n-\0
char bad[4] = "John";   // WRONG: No room for \0!
```

**Solution:**
```c
char name[5] = "John";  // Correct: includes \0
// Or let compiler calculate:
char name[] = "John";   // Automatically [5]
```

### 14. Not Null-Terminating Strings

**Mistake:**
```c
char str[10];
strncpy(str, "LongString", 10);  // Might not null-terminate!
printf("%s", str);  // Could crash
```

**Solution:**
```c
char str[10];
strncpy(str, "LongString", 10);
str[9] = '\0';  // Ensure null termination

// Or use safe version:
strncpy_s(str, sizeof(str), "LongString", _TRUNCATE);
```

---

## Logic Mistakes

### 15. Assignment in Condition

**Mistake:**
```c
if (x = 5) {  // WRONG: Assignment, not comparison!
    printf("x is 5");
}
```

**Solution:**
```c
if (x == 5) {  // Correct: Comparison
    printf("x is 5");
}
```

**Tip:** Some prefer: `if (5 == x)` - can't accidentally assign to constant.

### 16. Comparing Strings with ==

**Mistake:**
```c
char* str1 = "Hello";
char* str2 = "Hello";
if (str1 == str2) {  // WRONG: Compares addresses!
    printf("Equal");
}
```

**Solution:**
```c
char* str1 = "Hello";
char* str2 = "Hello";
if (strcmp(str1, str2) == 0) {  // Correct: Compares contents
    printf("Equal");
}

// For wide strings:
if (wcscmp(wstr1, wstr2) == 0) {
    printf("Equal");
}
```

### 17. Integer Division

**Mistake:**
```c
int a = 5, b = 2;
float result = a / b;  // Result is 2.0, not 2.5!
```

**Solution:**
```c
int a = 5, b = 2;
float result = (float)a / b;  // Cast to float first
// Or:
float result = a / (float)b;
```

---

## Windows-Specific Mistakes

### 18. Not Initializing COM

**Mistake:**
```c
// Using COM objects without initialization
CoCreateInstance(...);  // Might fail
```

**Solution:**
```c
CoInitialize(NULL);  // Or CoInitializeEx
// ... use COM ...
CoUninitialize();
```

### 19. Wrong Subsystem

**Mistake:**
```c
// GUI application showing console window
```

**Solution:**
```bash
# Compile with -mwindows (GCC) or /SUBSYSTEM:WINDOWS (MSVC)
gcc -mwindows program.c -o program.exe
```

### 20. Not Handling DPI Scaling

**Mistake:**
```c
// Hard-coded pixel sizes look wrong on high-DPI displays
```

**Solution:**
```c
// Declare DPI-aware in manifest:
<dpiAware>true</dpiAware>

// Or set programmatically:
SetProcessDPIAware();
```

---

## Debugging Tips

### Finding Memory Leaks

**Windows:**
Use Visual Studio's diagnostic tools or manually:
```c
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
```

**General Approach:**
- Count `malloc` vs `free` calls
- Use debug allocators
- Valgrind (Linux) or Dr. Memory (Windows)

### Finding NULL Pointer Crashes

**Enable crash dumps:**
- Run in debugger
- Note crash address
- Check call stack
- Look for recently dereferenced pointers

### Finding Buffer Overflows

**Tools:**
- Address Sanitizer: `gcc -fsanitize=address`
- Compile-time checks: `gcc -D_FORTIFY_SOURCE=2`
- Use safe string functions (`_s` versions)

---

## Best Practices Checklist

✅ **Always:**
- Check `malloc` return values
- Free allocated memory
- Null-terminate strings
- Close handles/files
- Check API return values
- Use `_s` safe functions
- Initialize variables
- Test with empty/NULL inputs

❌ **Never:**
- Use uninitialized variables
- Return pointers to local variables
- Free stack memory
- Dereference NULL pointers
- Use unsafe string functions
- Ignore compiler warnings
- Mix Unicode and ANSI

---

Most bugs are preventable with careful coding and thorough testing. When in doubt, check for NULL, validate inputs, and handle errors gracefully!

---

# Appendix C: Windows API Quick Reference

Quick reference for the most common Windows API functions, types, and patterns used throughout this book.

## Common Data Types

### Handles and Pointers
```c
HWND        // Window handle
HINSTANCE   // Instance handle  
HDC         // Device context handle
HICON       // Icon handle
HBRUSH      // Brush handle
HMENU       // Menu handle
HANDLE      // Generic handle
LPVOID      // Pointer to void (long pointer)
LPSTR       // Pointer to string (char*)
LPWSTR      // Pointer to wide string (wchar_t*)
```

### Integers
```c
BOOL        // Boolean (TRUE/FALSE, not true/false)
BYTE        // 8-bit unsigned (0-255)
WORD        // 16-bit unsigned
DWORD       // 32-bit unsigned (double word)
INT         // 32-bit signed integer
UINT        // 32-bit unsigned integer
LONG        // 32-bit signed long
WPARAM      // Message parameter (unsigned)
LPARAM      // Message parameter (long)
LRESULT     // Message return value
```

### Strings
```c
CHAR        // 8-bit character
WCHAR       // 16-bit wide character
TCHAR       // Character (CHAR or WCHAR depending on UNICODE)
```

---

## Window Management

### Creating Windows

```c
// Register window class
WNDCLASSEXW wc = {0};
wc.cbSize = sizeof(WNDCLASSEXW);
wc.lpfnWndProc = WndProc;
wc.hInstance = hInstance;
wc.lpszClassName = L"MyWindowClass";
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
wc.hCursor = LoadCursor(NULL, IDC_ARROW);
RegisterClassExW(&wc);

// Create window
HWND hwnd = CreateWindowExW(
    0,                          // Extended style
    L"MyWindowClass",           // Class name
    L"Window Title",            // Window title
    WS_OVERLAPPEDWINDOW,        // Style
    CW_USEDEFAULT, CW_USEDEFAULT,  // Position
    640, 480,                   // Size
    NULL,                       // Parent
    NULL,                       // Menu
    hInstance,                  // Instance
    NULL                        // User data
);

ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);
```

### Message Loop

```c
MSG msg;
while (GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
return (int)msg.wParam;
```

### Window Procedure

```c
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
            // Window created
            return 0;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
```

---

## Common Window Messages

```c
WM_CREATE       // Window being created
WM_DESTROY      // Window being destroyed
WM_CLOSE        // User clicked close button
WM_PAINT        // Window needs repainting
WM_SIZE         // Window resized
WM_MOVE         // Window moved
WM_COMMAND      // Button clicked or menu selected
WM_NOTIFY       // Control notification
WM_TIMER        // Timer expired
WM_KEYDOWN      // Key pressed
WM_CHAR         // Character input
WM_LBUTTONDOWN  // Left mouse button down
WM_RBUTTONDOWN  // Right mouse button down
WM_MOUSEMOVE    // Mouse moved
```

---

## Dialog Boxes

### Creating Dialogs

```c
// Modal dialog
INT_PTR result = DialogBox(
    hInstance,
    MAKEINTRESOURCE(IDD_DIALOG),
    hwndParent,
    DialogProc
);

// Modeless dialog
HWND hDlg = CreateDialog(
    hInstance,
    MAKEINTRESOURCE(IDD_DIALOG),
    hwndParent,
    DialogProc
);
ShowWindow(hDlg, SW_SHOW);
```

### Dialog Procedure

```c
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_INITDIALOG:
            return TRUE;  // TRUE = handled
            
        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK) {
                EndDialog(hwnd, IDOK);
                return TRUE;
            }
            break;
    }
    return FALSE;  // FALSE = not handled
}
```

### Dialog Functions

```c
// Get/Set text
GetDlgItemTextW(hwnd, IDC_EDIT, buffer, bufferSize);
SetDlgItemTextW(hwnd, IDC_EDIT, L"Text");

// Get/Set integer
SetDlgItemInt(hwnd, IDC_EDIT, 42, FALSE);
UINT value = GetDlgItemInt(hwnd, IDC_EDIT, NULL, FALSE);

// Check boxes
CheckDlgButton(hwnd, IDC_CHECK, BST_CHECKED);
UINT state = IsDlgButtonChecked(hwnd, IDC_CHECK);

// Get control handle
HWND hControl = GetDlgItem(hwnd, IDC_BUTTON);
```

---

## Common Controls

### ListView

```c
// Create columns
LVCOLUMN col = {0};
col.mask = LVCF_TEXT | LVCF_WIDTH;
col.pszText = L"Column";
col.cx = 150;
ListView_InsertColumn(hList, 0, &col);

// Add items
LVITEM item = {0};
item.mask = LVIF_TEXT;
item.iItem = 0;
item.pszText = L"Item";
ListView_InsertItem(hList, &item);

// Set subitem
ListView_SetItemText(hList, 0, 1, L"Subitem");

// Get selected item
int selected = ListView_GetNextItem(hList, -1, LVNI_SELECTED);
```

### Buttons

```c
// In WM_COMMAND:
switch (LOWORD(wParam))
{
    case IDC_BUTTON:
        if (HIWORD(wParam) == BN_CLICKED) {
            // Button clicked
        }
        break;
}
```

---

## File Operations

```c
// Open file
HANDLE hFile = CreateFileW(
    L"file.txt",
    GENERIC_READ | GENERIC_WRITE,
    0,
    NULL,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    NULL
);

if (hFile == INVALID_HANDLE_VALUE) {
    // Error
}

// Read file
DWORD bytesRead;
char buffer[1024];
ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL);

// Write file
DWORD bytesWritten;
WriteFile(hFile, data, dataSize, &bytesWritten, NULL);

// Close file
CloseHandle(hFile);
```

---

## Registry Operations

```c
// Open key
HKEY hKey;
RegOpenKeyExW(HKEY_CURRENT_USER, L"Software\\MyApp", 0, KEY_READ, &hKey);

// Read string
wchar_t value[256];
DWORD size = sizeof(value);
RegQueryValueExW(hKey, L"Setting", NULL, NULL, (LPBYTE)value, &size);

// Write string
RegSetValueExW(hKey, L"Setting", 0, REG_SZ, (BYTE*)value,
               (wcslen(value) + 1) * sizeof(wchar_t));

// Read DWORD
DWORD dwValue;
DWORD dwSize = sizeof(DWORD);
RegQueryValueExW(hKey, L"Number", NULL, NULL, (LPBYTE)&dwValue, &dwSize);

// Write DWORD
RegSetValueExW(hKey, L"Number", 0, REG_DWORD, (BYTE*)&dwValue, sizeof(DWORD));

// Close key
RegCloseKey(hKey);
```

---

## Memory Management

```c
// Allocate
void* ptr = malloc(size);
if (ptr == NULL) {
    // Out of memory
}

// Reallocate
void* newPtr = realloc(ptr, newSize);
if (newPtr == NULL) {
    // Error, original pointer still valid
    free(ptr);
} else {
    ptr = newPtr;
}

// Free
free(ptr);
ptr = NULL;  // Good practice
```

---

## String Functions

### ANSI Strings
```c
strlen(str)                 // Length
strcpy(dest, src)           // Copy
strcat(dest, src)           // Concatenate
strcmp(str1, str2)          // Compare (0 = equal)
strstr(haystack, needle)    // Find substring
```

### Wide Strings
```c
wcslen(str)                 // Length
wcscpy(dest, src)           // Copy
wcscat(dest, src)           // Concatenate
wcscmp(str1, str2)          // Compare
wcsstr(haystack, needle)    // Find substring
```

### Safe Versions
```c
strcpy_s(dest, destSize, src)
strcat_s(dest, destSize, src)
wcscpy_s(dest, destSize, src)
wcscat_s(dest, destSize, src)
```

---

## Error Handling

```c
// Get last error
DWORD error = GetLastError();

// Format error message
wchar_t errorMsg[256];
FormatMessageW(
    FORMAT_MESSAGE_FROM_SYSTEM,
    NULL,
    error,
    0,
    errorMsg,
    256,
    NULL
);

// Display error
MessageBoxW(NULL, errorMsg, L"Error", MB_OK | MB_ICONERROR);
```

---

## Common Window Styles

```c
// Window styles
WS_OVERLAPPEDWINDOW    // Standard window
WS_POPUP               // Popup window
WS_CHILD               // Child window
WS_VISIBLE             // Initially visible
WS_DISABLED            // Initially disabled

// Extended styles
WS_EX_TOPMOST          // Always on top
WS_EX_TOOLWINDOW       // Tool window
WS_EX_CLIENTEDGE       // Sunken edge
```

---

## MessageBox Flags

```c
// Buttons
MB_OK                  // OK button
MB_OKCANCEL            // OK and Cancel
MB_YESNO               // Yes and No
MB_YESNOCANCEL         // Yes, No, Cancel
MB_RETRYCANCEL         // Retry and Cancel

// Icons
MB_ICONERROR           // Error icon
MB_ICONWARNING         // Warning icon
MB_ICONINFORMATION     // Info icon
MB_ICONQUESTION        // Question icon

// Default button
MB_DEFBUTTON1          // First button default
MB_DEFBUTTON2          // Second button default
```

---

## Useful Macros

```c
// Extract values from messages
LOWORD(value)          // Low 16 bits
HIWORD(value)          // High 16 bits
MAKEWORD(low, high)    // Combine into WORD
MAKELONG(low, high)    // Combine into LONG

// Resource handling
MAKEINTRESOURCE(id)    // Convert ID to resource pointer

// Color
RGB(r, g, b)           // Create COLORREF
GetRValue(color)       // Extract red
GetGValue(color)       // Extract green
GetBValue(color)       // Extract blue
```

---

This quick reference covers the most frequently used Windows API elements. For complete documentation, refer to the Microsoft Docs: https://docs.microsoft.com/en-us/windows/win32/

---

# Appendix D: Further Learning Resources

This appendix provides curated resources for continuing your C and Windows programming journey.

## Books

### C Programming

**"The C Programming Language" by Kernighan & Ritchie**
- ✅ THE definitive C book
- ✅ Written by C's creator
- ✅ Concise and precise
- 📖 Often called "K&R"
- 💡 Essential reference

**"C Programming: A Modern Approach" by K.N. King**
- ✅ Comprehensive and beginner-friendly
- ✅ Covers C99 and C11
- ✅ Excellent exercises
- 📖 Great for self-study
- 💡 More detailed than K&R

**"Expert C Programming: Deep C Secrets" by Peter van der Linden**
- ✅ Advanced topics
- ✅ Fun and engaging writing
- ✅ War stories from Sun Microsystems
- 📖 For experienced programmers
- 💡 Explains the "why" behind C

### Windows Programming

**"Programming Windows" by Charles Petzold**
- ✅ THE classic Windows programming book
- ✅ Comprehensive coverage
- ✅ Clear explanations
- 📖 Multiple editions available
- 💡 Bible of Windows development

**"Windows via C/C++" by Jeffrey Richter**
- ✅ Deep dive into Windows internals
- ✅ Process, threads, memory
- ✅ Advanced topics
- 📖 For serious Windows developers
- 💡 Understand how Windows works

**"Windows System Programming" by Johnson M. Hart**
- ✅ Practical focus
- ✅ Covers Win32 API extensively
- ✅ Good examples
- 📖 Modern approach
- 💡 Real-world applications

---

## Online Resources

### Official Microsoft Documentation

**Microsoft Docs (docs.microsoft.com)**
- https://docs.microsoft.com/en-us/windows/win32/
- ✅ Official API reference
- ✅ Always up-to-date
- ✅ Code examples
- ✅ Best practices
- 💡 Bookmark this!

**Windows API Index**
- https://docs.microsoft.com/en-us/windows/win32/apiindex/windows-api-list
- Complete alphabetical list of all functions

### Tutorials and Learning Sites

**theForger's Win32 API Tutorial**
- http://www.winprog.org/tutorial/
- ✅ Excellent beginner tutorial
- ✅ Step-by-step approach
- ✅ Complete and free
- 💡 Great starting point

**Learn C**
- https://www.learn-c.org/
- Interactive C tutorial
- Practice in browser
- Good for basics

**C Programming Tutorial (Programiz)**
- https://www.programiz.com/c-programming
- Clear explanations
- Code examples
- Practice exercises

---

## Video Courses

### YouTube Channels

**The Cherno (C++ focus but great fundamentals)**
- https://www.youtube.com/c/TheChernoProject
- Deep dives into C/C++
- Professional quality
- Visual Studio tips

**ChiliTomatoNoodle (DirectX and game dev)**
- https://www.youtube.com/c/ChiliTomatoNoodle
- Windows graphics programming
- Fun and engaging
- Game development

**Jacob Sorber (C and systems programming)**
- https://www.youtube.com/c/JacobSorber
- Excellent C tutorials
- Systems programming
- Short, focused videos

### Online Course Platforms

**Udemy**
- Search for "C Programming"
- Look for high-rated courses
- Wait for sales ($10-15)
- Lifetime access

**Pluralsight**
- Professional courses
- Subscription model
- High quality
- Free trial available

---

## Communities and Forums

### Stack Overflow
- https://stackoverflow.com/questions/tagged/c
- https://stackoverflow.com/questions/tagged/winapi
- ✅ Get help with specific problems
- ✅ Search before asking
- ✅ Millions of answered questions
- 💡 Include minimal, complete examples

### Reddit

**r/C_Programming**
- https://www.reddit.com/r/C_Programming/
- Active community
- Beginner-friendly
- Code reviews

**r/learnprogramming**
- https://www.reddit.com/r/learnprogramming/
- General programming help
- Supportive community
- Good for beginners

### Discord Servers

**The Programmer's Hangout**
- https://discord.gg/programming
- Active help channels
- Friendly community
- Real-time chat

**C/C++ Discord**
- Various servers available
- Search "C programming discord"
- Real-time help

---

## Development Tools

### Compilers and IDEs

**Visual Studio Community (Free)**
- https://visualstudio.microsoft.com/vs/community/
- Professional IDE
- Excellent debugger
- Windows development

**VS Code (Free)**
- https://code.visualstudio.com/
- Lightweight editor
- Great extensions
- Cross-platform

**Code::Blocks (Free)**
- http://www.codeblocks.org/
- Beginner-friendly IDE
- Built for C/C++
- Cross-platform

### Debugging Tools

**Visual Studio Debugger**
- Built into VS
- Best Windows debugger
- Memory inspection
- Call stacks

**GDB (GNU Debugger)**
- https://www.gnu.org/software/gdb/
- Command-line debugger
- Powerful and flexible
- Works with GCC

**DebugView (Sysinternals)**
- https://docs.microsoft.com/en-us/sysinternals/
- View OutputDebugString messages
- System-wide debugging
- Free from Microsoft

**Dependency Walker**
- https://www.dependencywalker.com/
- See DLL dependencies
- Find missing DLLs
- Debug load failures

---

## Practice and Projects

### Project Ideas

**Beginner Projects:**
1. Calculator
2. Todo list manager
3. File encryption tool
4. Password generator
5. Alarm clock

**Intermediate Projects:**
1. File manager
2. Text editor
3. Network chat client
4. Registry editor
5. Process monitor

**Advanced Projects:**
1. Custom shell
2. Debugger
3. Virtual machine
4. Compiler
5. Operating system kernel

### Coding Challenge Sites

**LeetCode**
- https://leetcode.com/
- Algorithm problems
- Interview prep
- Various difficulties

**HackerRank**
- https://www.hackerrank.com/
- C programming track
- Certificates available
- Good for practice

**Project Euler**
- https://projecteuler.net/
- Mathematical problems
- Use C to solve
- Great for algorithms

---

## Blogs and Articles

**Raymond Chen's "The Old New Thing"**
- https://devblogs.microsoft.com/oldnewthing/
- ✅ Windows internals expert
- ✅ Daily posts
- ✅ Historical context
- 💡 Fascinating insights

**Joel on Software**
- https://www.joelonsoftware.com/
- Software development wisdom
- Well-written
- Industry perspectives

**Code Project**
- https://www.codeproject.com/
- Tutorials and articles
- Source code examples
- Active community

---

## Windows API Specific

### MSDN Resources

**Windows API Reference**
- https://docs.microsoft.com/en-us/windows/win32/api/

**Windows Development Guide**
- https://docs.microsoft.com/en-us/windows/apps/develop/

**Code Samples**
- https://github.com/microsoft/Windows-classic-samples

### Tools

**Resource Hacker**
- http://www.angusj.com/resourcehacker/
- Edit .rc files visually
- Inspect resources
- Free tool

**PE Explorer**
- https://www.heaventools.com/
- Inspect EXE files
- Resource editing
- Disassembly

---

## Advanced Topics

### When You're Ready

**Operating Systems**
- "Operating Systems: Three Easy Pieces" (free online)
- Understand OS concepts
- Virtual memory, processes, threads

**Computer Architecture**
- "Computer Systems: A Programmer's Perspective"
- How computers work
- Assembly language
- Memory hierarchy

**Algorithms**
- "Introduction to Algorithms" (CLRS)
- Algorithm analysis
- Data structures
- Essential for serious programming

---

## Open Source Projects to Study

### Small to Medium Projects

**SQLite**
- https://www.sqlite.org/
- Well-written C code
- Database engine
- Excellent documentation

**Redis**
- https://github.com/redis/redis
- In-memory database
- Clean C code
- Great to study

**NotepadNext**
- https://github.com/dail8859/NotepadNext
- Text editor
- Windows API usage
- Active project

### Windows Projects

**Process Hacker**
- https://github.com/processhacker/processhacker
- Advanced task manager
- Deep Windows API usage
- Well-structured

**7-Zip**
- https://www.7-zip.org/
- File archiver
- C and C++ mixed
- High performance

---

## Staying Current

### News and Updates

**Hacker News**
- https://news.ycombinator.com/
- Tech news aggregator
- Programming discussions
- Industry trends

**r/programming**
- https://www.reddit.com/r/programming/
- Programming news
- Discussions
- Various languages

### Podcasts

**Coding Blocks**
- Software engineering topics
- Clean code principles
- Entertaining format

**Programming Throwdown**
- Different languages each episode
- Interview prep
- Industry topics

---

## Career Development

### Portfolio Building

**GitHub**
- https://github.com/
- Host your projects
- Show your code
- Contribute to open source

**Personal Website**
- Blog about your learning
- Showcase projects
- Document solutions
- Build your brand

### Interview Preparation

**Cracking the Coding Interview**
- Classic interview prep book
- Algorithm problems
- Practice questions

**LeetCode**
- Technical interview questions
- Company-specific questions
- Mock interviews

---

## Final Advice

### Learning Path

1. **Master the Basics** - Don't rush fundamentals
2. **Build Projects** - Apply what you learn
3. **Read Code** - Study well-written programs
4. **Join Communities** - Learn from others
5. **Keep Practicing** - Programming is a skill
6. **Stay Curious** - Technology always evolves

### Best Practices

- ✅ Code every day
- ✅ Read documentation
- ✅ Write clean code
- ✅ Comment your code
- ✅ Test thoroughly
- ✅ Learn from mistakes
- ✅ Share knowledge
- ✅ Never stop learning

### Remember

> "The only way to learn a new programming language is by writing programs in it."
> — Dennis Ritchie, creator of C

**You've completed this book - now go build amazing things!** 🚀

---

# End of Book

**Congratulations!** You've completed "Building Real Windows Applications in C"!

You now have:
- ✅ Solid C programming foundation
- ✅ Windows API expertise
- ✅ Complete working application
- ✅ Professional development skills
- ✅ Portfolio-worthy project

## What You've Achieved

Throughout this book, you've learned:
- **C Language:** Pointers, memory, structures, files, and more
- **Windows API:** Messages, dialogs, controls, registry, credentials
- **Real Application:** Built WinRDP from scratch with modern features
- **Best Practices:** Error handling, Unicode, security, testing
- **Distribution:** Build scripts, installers, professional deployment

## Your Next Steps

1. **Extend WinRDP** - Add your own features
2. **Start New Projects** - Apply what you've learned
3. **Contribute to Open Source** - Share your knowledge
4. **Keep Learning** - Explore advanced topics from Appendix D
5. **Help Others** - Teach someone else C programming

## Thank You

Thank you for working through this book. C programming and Windows API development are powerful skills that will serve you well throughout your programming career.

The journey doesn't end here—it's just the beginning of what you can build with C and Windows!

**Keep coding, keep learning, and keep building amazing things!** 🚀

---

**Book Complete:** November 4, 2025  
**Total Chapters:** 34 (30 main chapters + 4 appendices)  
**Completion:** 100% ✅  
**Lines of Content:** ~21,800  
**Your Achievement:** Complete!  

**🎊 CONGRATULATIONS ON COMPLETING THE BOOK! 🎊**

