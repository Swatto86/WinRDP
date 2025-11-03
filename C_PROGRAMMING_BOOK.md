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

*This is the first third of the book. The book continues with Chapter 7 (Strings), Chapter 8 (Structures), and then progresses through Advanced C, Windows Programming, and ultimately building the complete WinRDP application.*

*Would you like me to continue with the remaining chapters?*

---

**To be continued in Part II...**

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
