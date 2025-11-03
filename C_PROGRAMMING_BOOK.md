# Building Real Windows Applications in C
## A Hands-On Journey from Basics to a Complete RDP Manager

**Author:** Created from the WinRDP Educational Project  
**Target Audience:** Beginners to Intermediate C Programmers  
**Prerequisites:** Basic computer literacy, willingness to learn

---

# Table of Contents

## Part I: C Fundamentals
1. [Introduction to C Programming](#chapter-1-introduction-to-c-programming)
2. [Variables, Data Types, and Operators](#chapter-2-variables-data-types-and-operators)
3. [Control Flow: Making Decisions](#chapter-3-control-flow-making-decisions)
4. [Functions: Building Blocks of Programs](#chapter-4-functions-building-blocks-of-programs)
5. [Arrays: Working with Multiple Values](#chapter-5-arrays-working-with-multiple-values)
6. [Pointers: The Heart of C](#chapter-6-pointers-the-heart-of-c)
7. [Strings: Text Processing in C](#chapter-7-strings-text-processing-in-c)
8. [Structures: Organizing Related Data](#chapter-8-structures-organizing-related-data)

## Part II: Advanced C Concepts
9. [Dynamic Memory Management](#chapter-9-dynamic-memory-management)
10. [File Input/Output](#chapter-10-file-inputoutput)
11. [Function Pointers and Callbacks](#chapter-11-function-pointers-and-callbacks)
12. [Preprocessor and Multi-File Programs](#chapter-12-preprocessor-and-multi-file-programs)

## Part III: Windows Programming Basics
13. [Introduction to Windows Programming](#chapter-13-introduction-to-windows-programming)
14. [Your First Windows Application](#chapter-14-your-first-windows-application)
15. [Windows Message System](#chapter-15-windows-message-system)
16. [Dialog Boxes and Controls](#chapter-16-dialog-boxes-and-controls)

## Part IV: Building WinRDP Core
17. [Project Setup: WinRDP Architecture](#chapter-17-project-setup-winrdp-architecture)
18. [Configuration and Utilities](#chapter-18-configuration-and-utilities)
19. [CSV File Management](#chapter-19-csv-file-management)
20. [Windows Credential Manager](#chapter-20-windows-credential-manager)
21. [Main Application Window](#chapter-21-main-application-window)
22. [ListView Control for Host Display](#chapter-22-listview-control-for-host-display)
23. [RDP Connection Logic](#chapter-23-rdp-connection-logic)
24. [System Tray Integration](#chapter-24-system-tray-integration)

## Part V: Advanced Features
25. [Registry Operations and Autostart](#chapter-25-registry-operations-and-autostart)
26. [Global Hotkeys](#chapter-26-global-hotkeys)
27. [Dark Mode Support](#chapter-27-dark-mode-support)
28. [Network Computer Discovery](#chapter-28-network-computer-discovery)
29. [Building and Distribution](#chapter-29-building-and-distribution)

## Appendices
- [A: Setting Up Your Development Environment](#appendix-a-setting-up-your-development-environment)
- [B: Common Mistakes and How to Avoid Them](#appendix-b-common-mistakes-and-how-to-avoid-them)
- [C: Windows API Quick Reference](#appendix-c-windows-api-quick-reference)
- [D: Further Learning Resources](#appendix-d-further-learning-resources)

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

| Specifier | Type | Example |
|-----------|------|---------|
| `%d` | int | `printf("%d", 42);` |
| `%f` | float/double | `printf("%f", 3.14);` |
| `%c` | char | `printf("%c", 'A');` |
| `%s` | string | `printf("%s", "Hello");` |
| `%p` | pointer | `printf("%p", ptr);` |
| `%x` | hexadecimal | `printf("%x", 255);` |

### Formatting Numbers

```c
printf("%.2f", 3.14159);     // 3.14 (2 decimal places)
printf("%5d", 42);           // "   42" (width 5, right-aligned)
printf("%-5d", 42);          // "42   " (width 5, left-aligned)
printf("%05d", 42);          // "00042" (zero-padded)
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

Arrays store multiple values of the same type in contiguous memory:

```c
int numbers[5];  // Array of 5 integers
```

Think of it as a row of boxes, each holding one value:

```
Index:   0    1    2    3    4
Value: [ 10][ 20][ 30][ 40][ 50]
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

Visual representation:
```
Memory Address: 0x1000   0x2000
Value:          [ 25 ]   [0x1000]
Variable:         age      pAge
```

`pAge` doesn't contain 25, it contains the address of `age` (0x1000).

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

Visual:
```
arr:   [10][20][30][40][50]
       ^               ^
       |               |
    Initial          After ptr += 2
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

*End of Part I Preview*

This book continues with comprehensive coverage of strings, structures, dynamic memory, Windows programming, and step-by-step construction of the WinRDP application. Each chapter includes:
- Clear explanations with diagrams
- Working code examples
- Hands-on exercises
- Common pitfalls to avoid
- Building blocks toward the final application

The complete book is approximately 800-1000 pages and takes you from absolute beginner to building a professional Windows application!
