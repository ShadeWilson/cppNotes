# Learn C++

Notes by Shade Wilson from LearnCpp.com

*Oct 18, 2016*

## Chapter 1: C++ Basics

### 1.1 - Structure of a program 
Statements in C++ are terminated with a ; (dont forget!!). All variables must 
be declared before they can be used

Helpful hint: It’s a good idea to put your main() function in
a .cpp file named either main.cpp, or with the same name as your project.
For example, if you are writing a Chess game, you could put your main()
function in chess.cpp.

One of the most commonly used parts of the C++ standard library is
is the iostream library, which contains functionality to write/read
to/from the screen

Compile and run the C++ program 'helloWorld':

```
shadewilson $ g++ -o helloWorld helloWorld.cpp
shadewilson $ ./helloWorld
```

### 1.2 - Comments
```c++
/* This is a multi-line /* comment */ this is not inside the comment */`
```

```c++
// The above comment ends at the first */, not the second */`
```

Comments do not nest

### 1.3 - A first look at variables, initialization, assignment
an object is a piece of memory that can be used to store values

In order to create a variable, we generally use a special kind of declaration
statement called a definition

Ex:
`int x;`

When the CPU executes this statement, a piece of memory from RAM will
be set aside (instantiation). Let's say x is assigned memory location 140

```c++
x = 5;
std::cout << x;  // prints the value of x (memory location 140) to the console
```

In C++, variables are all l-values: a value that has a persistent
address in memory. L comes from the fact than l-values can only be
on the left side of an assignment statement

The opposite of l-values are r-valuesL refer to variables that are not associated
with a persistent memory address. Ex: 5 or expressions like x + 2. They
are generally temporary in nature and discarded at the end of the statement
where they occur.

Examples:
```c++
int y;      // define y as an integer variable
y = 4;      // r-value 4 evaluates to 4, which is then assigned to l-value y
y = 2 + 5;  // r-value 2 + r-value 5 evaluates to r-value 7, which is then assigned to l-value y

int x;      // define x as an integer variable
x = y;      // l-value y evaluates to 7 (from before), which is then assigned to l-value x.
x = x;      // l-value x evaluates to 7, which is then assigned to l-value x (useless!)
x = x + 1;  // l-value x + r-value 1 evaluate to r-value 8, which is then assigned to l-value x.
```

INITIALIZATION vs. ASSIGNMENT

After a variable is defined, a value may be assigned to it via "="
```c++
int x; // this is a variable definition
x = 5; // assign the value 5 to variable x
```

C++ lets you define a var and assign an initial value in one step (initialization)

```c++
int x = 5; // initialize variable x with the value 5`
``

Rule: When giving variables an initial value, favor initialization over assignment.

Caution: uninitialized variables take on any value the was previously
assigned to that memory location (garbage)!

To print multiple things on a line, the output operator can be used
multiple times

```c++
std::cout << "x is equal to: " << x;
std::endl can be used as \n (newline)
std::cin is the opposite of std::cout
```
reads input from the command line using the input operator >>


HOW TO REMEMBER which operator to USE:

<< is used with std::cout and shows the direction that data is moving from
the r-value to the console

`std::cout <<` 4 moves the value of 4 to the console

`>>` is used with std::cin and shows the direction that data is moving from the
console into the variable

`std::cin >> x` moves the value from the console into x


### 1.4 - A first look at functions and return values

Don't forget the parentheses when making a function call

Why return a value back to the OS in int main()?
The value is called the status code, it tells the OS (and any other programs)
whether your program executed successfully or not.

0 == success

1 (or any positive number) == failure

The C++ standard explicitly states that main must return an int. However, if you
do not provide a return statement in main(), the compiler will return 0 on your behalf.
But it is best practice to return a value from main(). You should also define main 
function at the bottom of your code file.

If a function as anon-void return type, it must return a value of that type.
The only exception is main() which will return 0 if a return statement is not
provided. A function can only return a single value back to the caller.

NESTED FUNCTIONS

Functions cannot be nested inside of other functions in C++.

### 1.4a - A first look at function parameters and arguments

A function parameter is a variable used in a function where the value is provided
by the caller of the function

```c++
// This function takes no parameters
// It does not rely on the caller for anything
void doPrint() {
    std::cout << "In doPrint()" << std::endl;
}


// This function takes one integer parameter named x
// The caller will supply the value of x
void printValue(int x)
{
    std::cout << x  << std::endl;
}
```
**Each function parameter is only valid within that function ie is constrained
within the scope of the function!**

An argument is a value passed *from* the caller *to* the function when a function
call is made.

```c++
printValue(6); // 6 is the argument passed to function printValue()
add(2, 3); // 2 and 3 are the arguments passed to function add()
```

When a function is called, the arguments passed in are copied to local variables.
This is called pass by value.

##### Quiz

1) Void functions can't have a return value
2) Non-void functions must have a return statement, all parameters must be passed values
3) 24

### 1.4c - Keywords and naming identifiers

the name of a variable, function, type, or other object in C++ is called an identifier.

Rules:

1) Identifier cannot be a Keywords
2) Identifier can only be composed of letters, numbers, and underscores
3) Must begin with letter or underscore, NOT a number
4) C++ is case sensitive

How should you name a variable or function in C++?

Convention that vars begin with a lowercase letter. If the var name is one word,
the whole thing should be written in lowercase.

```c++
int value; // correct
 
int Value; // incorrect (should start with lower case letter)
int VALUE; // incorrect (should start with lower case letter)
int VaLuE; // incorrect (see your psychiatrist) ;)
```

Generally, functions start with lowercase (some disagreement though). main() and
all functions in the standard C++ library start with lowercase.

Identifier names that start with an uppercase are usually for structs, classes,
and enums.

Either snake_case or camelCase is acceptable for variable and function names that
have multiple words.

```c++
int my_variable_name; // correct (separated by underscores)
void my_function_name() // correct (separated by underscores)
 
int myVariableName; // correct (intercapped/CamelCase)
void myFunctionName(); // correct (intercapped/CamelCase)
 
int my variable name; // invalid (whitespace not allowed)
void my function name(); // invalid (whitespace not allowed) 
 
int MyVariableName; // valid but incorrect (should start with lower case letter)
void MyFunctionName(); // valid but not best practice
```

Note: if you're working within someone else's code, it's generally considered best to
match the style of the code you're working in rather than rigidly follow naming 
conventions.

Also, avoid naming identifiers starting with underscores as those are usually 
left for OS, library, and/or compiler use.

USE DESCRIPTIVE NAMES!!

| Variable | Rank | Note |
| -------- | ---- | ---- |
| int ccount	| Bad	| Nobody knows what a ccount is |
| int customerCount	| Good	| Clear what we’re counting
| int i	| Bad* |	Generally bad unless use is trivial or temporary, such as loop variables |
| int index	| Either	| Okay if obvious what we’re indexing |
| int totalScore	| Good	| Descriptive | 
| int _count	| Bad	| Do not start variable names with underscore |
| int count	| Either	| Okay if obvious what we’re counting |
| int data	| Bad	| What kind of data? |
| int value1, value2	| Either	| Can be hard to differentiate between the two |
| int numberOfApples	| Good	| Descriptive | 
| int monstersKilled	| Good	| Descriptive |
| int x, y	| Bad*	| Generally bad unless use is trivial, such as in trivial mathematical functions |


### 1.4d - First look at local scope

Function parameters and variables defined inside the function body both have 
local scope, meaning those variables can only be seen and used within the function that
defines them.

```c++
#include <iostream>
 
int main()
{
    int x; // variable x is created here
    std::cout << "Enter a value for x: ";
    std::cin >> x;
    std::cout << "You entered: " << x << std::endl;
 
    return 0;
} // variable x is destroyed here
```

Rule: *names used for function parameters or variables inside the function are only 
visible within the function that declares them.*

### 1.5 - First look at operators

| Term | Explanation |
| ---- | ----------- | 
| Expression | a combination of literals, variables, functions, and operators that evaluates to a value | 
| Literal | Fixed value that has been inserted (hardcoded) directly into source code. Ex: 5, 3.14. Always evaluates to itself |
| Operand | A literal, variable, or function that return a value. Supplies that data that the expression works with | 
| Operators | Tell the expression how to combine 1 or more operands to produce a new result. Ex: +, -, =, |

Operators come in three types:

1) **Unary:** act on one operand. Ex: the negative operator (-) in -5.
2) **Binary:** acts on two operands, left and right. Ex: +
3) **Ternary:** act on three operands. Only one in C++

Some operators, like the - operator, have more than one meaning depending on the context.

### 1.6 - White space and basic formatting

C++ compiler generally ignores whitespace. All of these compile fine and do the same thing:

```c++
std::cout << "Hello world!";
 
std::cout               <<            "Hello world!";
 
		std::cout << 		"Hello world!";
 
std::cout
	<< "Hello world!";
```

All of these functions do the same thing too:

```c++
int add(int x, int y) { return x + y; }
 
int add(int x, int y) {
    return x + y; }
 
int add(int x, int y)
{    return x + y; }
 
int add(int x, int y)
{
    return x + y;
}
```
The one exception is inside a string itself. Also, newlines are not allowed in quoted text:

```c++
std::cout << "Hello
     world!" << std::endl; // Not allowed!
```

C++ does not enforce any kind of formatting restrictions. A basic rule of thumb is that the best styles produce the most readable code and are the most consistent.

### 1.7 - Forward declarations and definitions

```c++
#include <iostream>
 
int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << std::endl;
    return 0;
}
 
int add(int x, int y)
{
    return x + y;
}
```

The expected output of the following program would be `The sum of 3 and 4 is: 7` but it's not! In fact, it doesn't compile at all. This is because the compiler reads files sequentially. When the compiler reaches the line where `add()` is used in `main()`, it doesn't know what `add()` is because we haven't defined the function yet.

There's two common ways to fix this issue. The first would be to reorder the program so that `add()` is declared before `main()`. This way, when the compiler reaches `add()` being used in `main()`, it'll already know what the function is.  This change is relatively simple but can be tedious for large programs.

In some cases, this isn't possible. If two functions (A and B) both call each other, there's no way to order the function definitions correctly.

An option to deal with this is to use a forward declaration.

**Forward declaration:** allows us to tell the compiler about the existence of an identifier before actually defining the identifier.

To write a forward declaration of a function, use a declaration statement called a **function prototype**: has functions return type, name, parameters, but not body. It's a statement so must end with a semicolon

```c++
int add(int x, int y); // function prototype includes return type, name, parameters, and semicolon.  No function body!
```

If this is added to the top of the program defined above, now it'll compile!

```c++
#include <iostream>
 
int add(int x, int y); // forward declaration of add() (using a function prototype)
 
int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << std::endl; // this works because we forward declared add() above
    return 0;
}
 
int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}
```

Now when the compiler reaches `add()` in `main()`, it'll know what `add()` looks like and it won't complain anymore.

**Note**: you don't actually have to specify the names of the parameters:

```c++
int add(int, int);
```

Forward declarations are usually used for functions, but can be used for other identifiers like variables and user-defined types, which have different syntax.

**Declarations vs definitions**

**Definition**: actually implements or instantiates (causes memory to be allocated for) the identifier. Examples:

```c++
int add(int x, int y) // defines function add()
{
    return x + y;
}
 
int x; // instantiates (causes memory to be allocated for) an integer variable named x
```

You can only have one definition per identifier. A definition is needed to satisfy the linker.

**Declaration**: a statement that announces an identifier and its type. Examples:

```c++
int add(int x, int y); // declares a function named "add" that takes two int parameters and returns an int.  No body!
int x; // declares an integer variable named x
```

A declaration is all that's needed to satisfy a compiler. BUT if you forget the definition for the identifier, the linker will complain.

Note that `int x` appears in both examples. In C++, all definitions also serve as declarations. This is the case for most declarations; however, there is a small subset of declarations that are not definitions, like function prototypes. These are called **pure declarations**. 

### 1.8 - Programs with multiple files

From command line: When you compile your program, you’ll need to include all of the relevant code files on the compile line. For example: `g++ main.cpp add.cpp -o main`, where main.cpp and add.cpp are the names of the code files and main is the output file.

Need to use a forward declaration to get another file to work on main.

```c++
#include <iostream>
 
int add(int x, int y); // needed so main.cpp knows that add() is a function declared elsewhere
 
int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << std::endl;
    return 0;
}
```

Now the compiler will know about add() when compiling main.cpp.

### 1.8b - Naming conflicts and the std namespace

All identifiers must be non-ambiguous in C++.

Rule: When you use an identifier in a namespace, you always have to identify the namespace along with the identifier

### 1.9 - Header files

A header file or and include file usually have a .h extension but can also have a .hpp extension or none at all. Their purpose is to hold declarations for other files to use so you don't have to forward declare every individual function you want.

**Using standard library header files:**

```c++
#include <iostream>
int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```

This program never defines cout but can still use it because it is declared in a header file called `iostream`.


What we had before:

add.cpp

```c++
int add(int x, int y) {
    return x + y;
}
```

main.cpp

```c++
#include <iostream>
int add(int x, int y);

int main() {
  std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
  return 0;
}
```

But writing forward declarations for all the functions we want gets tedious. Header files can help! They only need to be written once and can include as many files as needed.

Header files consist of two parts:

1) **Header guard:** prevents a given header file from being #included more than once.

1) The actual content of the header file, which should be the declarations for all the functions we want other files to be able to see.

Ex: add.h

```c++
// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef ADD_H
#define ADD_H
 
// This is the content of the .h file, which is where the declarations go
int add(int x, int y); // function prototype for add.h -- don't forget the semicolon!
 
// This is the end of the header guard
#endif
```

We have to include the .h file in order to use it.


add.cpp stays the same. main.cpp:
```c++
#include <iostream>
#include "add.h"
 
int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
    return 0;
}
```

Angled brackets tell the compiler that we are including a header file that was included with the compiler. Double quotes tells the compiler that we are suppling the header file.

Rule: Each .cpp file should explicitly #include all of the header files it needs to compile.

**Header file best practices**
-Always include header guards.

-Do not define variables in header files unless they are constants. Header files should generally only be used for declarations.

-Do not define functions in header files.

-Each header file should have a specific job, and be as independent as possible. For example, you might put all your declarations related to functionality A in A.h and all your declarations related to functionality B in B.h. That way if you only care about A later, you can just include A.h and not get any of the stuff related to B.

-Give your header files the same name as the source files they’re associated with (e.g. grades.h goes with grades.cpp).

-Try to minimize the number of other header files you #include in your header files. Only #include what is necessary.

-Do not #include .cpp files.

### 1.10 - First look at the processor

Preprocessor: separate function that runs just before the compiler when you compile your program. Looks for directives: specific instructions that start with a # and end with a newline (no semi colon!). All text changes happen temporarily in-memory

`#include` is a directive.

`#define` can be used to create a **macro**: a rule that defines how an input sequence (ex: an identifier) is converted into a replacement output sequence. Two types: object-like macros and function-like macros (considered dangerous). Object-like macros look like 

```cpp
#define IDENTIFIER
#define IDENTIFIER substitution_text
```

When the preprocessor encounters this directive, any further occurance of `identifier` is replaced by `substitution_text`. The identifier is typically in all-caps with underscores for spaces. Frowned upon. The preprocessor turns this:

```cpp
#define MY_FAVORITE_NUMBER 9
 
std::cout << "My favorite number is: " << MY_FAVORITE_NUMBER << std::endl;
```

into

```cpp
std::cout << "My favorite number is: " << 9 << std::endl;
```

Object-like macros can also be defined without substitution text. Any further occurance is replaced with nothing!! Acceptable

**Conditional compilation**

These preprocessor directives allow you to specify under which conditions something will or wont compile: `#ifdef`, `#ifndef`, `#endif`

`#ifdef` allows the preprocessor to check whether a value has been previously #defined. If it has, the code between `#ifdef` and `#endif` is compiled. Otherwise, code is ignored. `#ifndef` is the opposite of `#ifdef`

```cpp 
#define PRINT_JOE

#ifdef PRINT_JOE
std::cout < "Joe" << std::endl;
#endif

#ifdef PRINT_BOB
std::cout << "Bob" << std::endl;
#endif
```


`PRINT_JOE` isn't replaced with nothing because macros only cause text substitution in normal code.


Directives found in one code file do not have an impact on other code files in the same project.


function.cpp 

```cpp 
#include <iostream>
 
void doSomething()
{
#ifdef PRINT
    std::cout << "Printing!";
#endif
#ifndef PRINT
    std::cout << "Not printing!";
#endif
}
```

main.cpp 

```cpp 
void doSomething(); // forward declaration for function doSomething()
 
int main()
{
#define PRINT
 
    doSomething();
 
    return 0;
}
```

Result is: `Not printing!`. Defining print in main.cpp has no effect on function.cpp. However, directives defined in a header file can be #included in multiple other files, so this is a way to define a set of directives for general use.










