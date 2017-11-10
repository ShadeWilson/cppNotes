# Learn C++

## Chapter 1: C++ Basics

Notes by Shade Wilson from LearnCpp.com

*Oct 18, 2016*

### 1.1
Statements in C++ are terminated with a ; (dont forget!!)
All variables must be declared before they can be used

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
`/* This is a multi-line /* comment */ this is not inside the comment */`

`// The above comment ends at the first */, not the second */`

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

`int x = 5; // initialize variable x with the value 5`

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
But it is best practice to return a value from main().

You should also define main function at the bottom of your code file.

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







