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
User Action (click, keypress)
         ↓
   Windows OS
         ↓
  Message Queue ← PostMessage() adds messages here
         ↓
   GetMessage() retrieves from queue
         ↓
  TranslateMessage() translates keyboard messages
         ↓
  DispatchMessage() sends to window procedure
         ↓
   WindowProc() processes the message
         ↓ (if SendMessage used)
   Returns immediately to sender
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

### Data Flow Example: Connecting to a Server

Let's trace what happens when you double-click a server:

```
User double-clicks "Production Server" in ListView
             ↓
    main.c (WM_NOTIFY handler)
             ↓
    Gets selected hostname → "server1.example.com"
             ↓
    credentials.c: LoadCredentials("server1.example.com")
             ↓
    Returns username/password from Windows Credential Manager
             ↓
    rdp.c: LaunchRDPWithDefaults(hostname, username, password)
             ↓
    Creates temporary .rdp file with connection settings
             ↓
    Launches mstsc.exe (Windows RDP client)
             ↓
    You're connected!
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

### config.h Implementation

Create `src/config.h`:

```c
#ifndef CONFIG_H
#define CONFIG_H

#include <windows.h>

// ============================================================================
// APPLICATION INFORMATION
// ============================================================================

#define APP_NAME        L"WinRDP"
#define APP_VERSION     L"1.0.0"
#define APP_AUTHOR      L"Your Name"
#define APP_COPYRIGHT   L"Copyright © 2024"

// ============================================================================
// WINDOW CONFIGURATION
// ============================================================================

// Main window dimensions
#define MAIN_WINDOW_WIDTH   600
#define MAIN_WINDOW_HEIGHT  400

// Dialog dimensions
#define LOGIN_DLG_WIDTH     350
#define LOGIN_DLG_HEIGHT    200

// Main window class name
#define MAIN_WINDOW_CLASS   L"WinRDP_MainWindow"

// ============================================================================
// RESOURCE IDs
// ============================================================================

// Icons
#define IDI_APP             100

// Dialogs
#define IDD_LOGIN           101
#define IDD_MAIN            102

// Menu IDs
#define ID_TRAY_OPEN        200
#define ID_TRAY_EXIT        201
#define ID_TRAY_ABOUT       202
#define ID_TRAY_AUTOSTART   203

// Control IDs
#define IDC_USERNAME        1001
#define IDC_PASSWORD        1002
#define IDC_REMEMBER        1003
#define IDC_HOSTLIST        1004
#define IDC_ADD_HOST        1005
#define IDC_REMOVE_HOST     1006
#define IDC_CONNECT         1007
#define IDC_HOSTNAME        1008
#define IDC_DESCRIPTION     1009
#define IDC_SCAN_NETWORK    1010

// ============================================================================
// SYSTEM TRAY CONFIGURATION
// ============================================================================

// Custom message for system tray
#define WM_TRAYICON         (WM_USER + 1)

// System tray icon ID
#define TRAY_ICON_ID        1

// ============================================================================
// HOTKEY CONFIGURATION
// ============================================================================

// Global hotkey ID
#define HOTKEY_SHOW         1

// Default: Ctrl+Shift+R
#define HOTKEY_MODIFIERS    (MOD_CONTROL | MOD_SHIFT)
#define HOTKEY_VK           'R'

// ============================================================================
// FILE PATHS
// ============================================================================

// Host list CSV file (in user's Documents folder)
#define HOSTS_FILENAME      L"winrdp_hosts.csv"

// Credential target prefix (for Windows Credential Manager)
#define CRED_TARGET_PREFIX  L"WinRDP:"

// ============================================================================
// REGISTRY PATHS
// ============================================================================

// Autostart registry key
#define AUTOSTART_KEY       L"Software\\Microsoft\\Windows\\CurrentVersion\\Run"
#define AUTOSTART_VALUE     L"WinRDP"

// ============================================================================
// APPLICATION BEHAVIOR
// ============================================================================

// Maximum hosts in list
#define MAX_HOSTS           1000

// CSV line buffer size
#define CSV_LINE_SIZE       1024

// RDP file template path
#define RDP_TEMP_FILE       L"%TEMP%\\winrdp_temp.rdp"

// ============================================================================
// UTILITY MACROS
// ============================================================================

// Safe string copy (prevents buffer overflow)
#define SAFE_STRCPY(dest, src) \
    wcsncpy_s(dest, _countof(dest), src, _TRUNCATE)

// Safe string concatenate
#define SAFE_STRCAT(dest, src) \
    wcsncat_s(dest, _countof(dest), src, _TRUNCATE)

// Get array element count
#define ARRAYSIZE(arr)  (sizeof(arr) / sizeof(arr[0]))

#endif // CONFIG_H
```

### Understanding config.h

Let's break down the key sections:

**1. Application Information**
```c
#define APP_NAME        L"WinRDP"
#define APP_VERSION     L"1.0.0"
```
- Used in window titles, about dialogs, error messages
- The `L` prefix means **wide string** (Unicode)

**2. Resource IDs**
```c
#define IDI_APP             100
#define IDD_LOGIN           101
```
- Numeric IDs for resources (icons, dialogs, menus)
- Must be unique across the application
- Grouped logically (icons 100-199, dialogs 101-199, etc.)

**3. System Tray Configuration**
```c
#define WM_TRAYICON         (WM_USER + 1)
```
- Custom Windows message for system tray clicks
- `WM_USER + 1` ensures it doesn't conflict with standard messages

**4. Utility Macros**
```c
#define SAFE_STRCPY(dest, src) \
    wcsncpy_s(dest, _countof(dest), src, _TRUNCATE)
```
- Helper macros used throughout the code
- `SAFE_STRCPY` prevents buffer overflows
- `_TRUNCATE` safely handles strings that are too long

**Why use #define for constants?**
- Easy to change in one place
- Compiler replaces them at compile time (no runtime cost)
- Makes code more readable: `MAIN_WINDOW_WIDTH` vs `600`

## Resource Files: The GUI Definition

Windows applications use **resource files** (.rc) to define:
- Dialogs and their controls
- Menus
- Icons and bitmaps
- Version information
- Strings

### resource.h: Resource IDs

Create `src/resource.h`:

```c
#ifndef RESOURCE_H
#define RESOURCE_H

// This file is included by both C code and resource compiler (rc.exe)
// Keep it simple - only #define statements

// Icons
#define IDI_APP             100

// Dialogs
#define IDD_LOGIN           101
#define IDD_MAIN            102
#define IDD_ADD_HOST        103

// Menus
#define IDM_TRAY_MENU       200

// Menu items
#define ID_TRAY_OPEN        201
#define ID_TRAY_EXIT        202
#define ID_TRAY_ABOUT       203
#define ID_TRAY_AUTOSTART   204

// Controls (must match config.h)
#define IDC_USERNAME        1001
#define IDC_PASSWORD        1002
#define IDC_REMEMBER        1003
#define IDC_HOSTLIST        1004
#define IDC_ADD_HOST        1005
#define IDC_REMOVE_HOST     1006
#define IDC_CONNECT         1007
#define IDC_HOSTNAME        1008
#define IDC_DESCRIPTION     1009
#define IDC_SCAN_NETWORK    1010

#endif // RESOURCE_H
```

### resources.rc: Dialog Definitions

Create `src/resources.rc`:

```rc
#include "resource.h"
#include <windows.h>

// ============================================================================
// ICONS
// ============================================================================

IDI_APP ICON "app.ico"

// ============================================================================
// MENUS
// ============================================================================

IDM_TRAY_MENU MENU
BEGIN
    POPUP "TrayMenu"
    BEGIN
        MENUITEM "Open WinRDP",         ID_TRAY_OPEN
        MENUITEM "Start with Windows",  ID_TRAY_AUTOSTART
        MENUITEM SEPARATOR
        MENUITEM "About",               ID_TRAY_ABOUT
        MENUITEM "Exit",                ID_TRAY_EXIT
    END
END

// ============================================================================
// DIALOGS
// ============================================================================

// Login Dialog
IDD_LOGIN DIALOGEX 0, 0, 250, 140
STYLE DS_MODALFRAME | DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "WinRDP - Login"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Username:",IDC_STATIC,20,20,80,12
    EDITTEXT        IDC_USERNAME,20,35,210,14,ES_AUTOHSCROLL
    
    LTEXT           "Password:",IDC_STATIC,20,55,80,12
    EDITTEXT        IDC_PASSWORD,20,70,210,14,ES_PASSWORD | ES_AUTOHSCROLL
    
    CONTROL         "Remember credentials",IDC_REMEMBER,"Button",
                    BS_AUTOCHECKBOX | WS_TABSTOP,20,95,150,12
    
    DEFPUSHBUTTON   "Login",IDOK,80,115,50,16
    PUSHBUTTON      "Cancel",IDCANCEL,140,115,50,16
END

// Main Dialog (Host List)
IDD_MAIN DIALOGEX 0, 0, 500, 350
STYLE DS_SETFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | 
      WS_MINIMIZEBOX | WS_MAXIMIZEBOX
CAPTION "WinRDP - RDP Connection Manager"
FONT 9, "Segoe UI"
BEGIN
    CONTROL         "",IDC_HOSTLIST,"SysListView32",
                    LVS_REPORT | LVS_SINGLESEL | WS_BORDER | WS_TABSTOP,
                    10,10,480,280
    
    PUSHBUTTON      "Connect",IDC_CONNECT,10,300,70,24
    PUSHBUTTON      "Add Host",IDC_ADD_HOST,90,300,70,24
    PUSHBUTTON      "Remove",IDC_REMOVE_HOST,170,300,70,24
    PUSHBUTTON      "Scan Network",IDC_SCAN_NETWORK,250,300,90,24
END

// Add Host Dialog
IDD_ADD_HOST DIALOGEX 0, 0, 300, 150
STYLE DS_MODALFRAME | DS_CENTER | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Add RDP Host"
FONT 9, "Segoe UI"
BEGIN
    LTEXT           "Hostname or IP:",IDC_STATIC,20,20,100,12
    EDITTEXT        IDC_HOSTNAME,20,35,260,14,ES_AUTOHSCROLL
    
    LTEXT           "Description:",IDC_STATIC,20,60,100,12
    EDITTEXT        IDC_DESCRIPTION,20,75,260,14,ES_AUTOHSCROLL
    
    DEFPUSHBUTTON   "Add",IDOK,100,115,50,16
    PUSHBUTTON      "Cancel",IDCANCEL,160,115,50,16
END
```

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
EDITTEXT IDC_USERNAME, 20, 35, 210, 14, ES_AUTOHSCROLL
      |         |       |   |    |    |       |
      |         |       |   |    |    |       Styles
      |         |       |   |    |    Height
      |         |       |   |    Width
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

- **Chapter 18**: Utility functions (CenterWindow, ShowError, etc.)
- **Chapter 19**: Host management (LoadHosts, SaveHosts)
- **Chapter 20**: Credential storage (Windows Credential Manager)
- **Chapter 21**: System tray integration
- **Chapter 22**: ListView population and selection
- **Chapter 23**: RDP connection logic
- **Chapter 24**: Complete system tray with context menu

Each chapter adds working features to this skeleton!

## Exercise 17.1: Customize the Application

Modify `config.h` to customize WinRDP:

1. Change `APP_NAME` to your own name
2. Change `APP_AUTHOR` to your name
3. Change `APP_VERSION` to "1.0.0-beta"
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

---
