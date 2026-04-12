# C++ - by TheCherno

[Course link](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)

## How C++ Works

Statements start with `#` are preprocessor statements.  `#include <iostream>` copy and paste header file `iostream` at the beginning of our source code.

`<<` is an **overload operator** (operator is function).  `std::out << "Hello World!" << std::endl;` is equivalent to `std::out.print("Hello World").print(std::endl);`.  

Compilation: ![compilation steps](static/compilation-steps.png)

More information at [Cornell](static/compilation.pdf).

Notes: read Output page (rather than Error in VS or Problems in VS Code) to fix errors.

For example, we defined a `log()` function in file `log.cpp`. Declaration (e.g. in file `log.h` or just add it before caller) tells the compiler that a function really exists.  Definition (e.g. in file `log.cpp`) tells the compiler how this function behave.  During compilation, linker will find the definition of function `log()` in `log.cpp` and link it to its caller. (If it cannot find the definition, linker error will occur).

## How the C++ Compiler Works

Compiler converts our code into either constant data or instructions.

C++ doesn't care about files.

### Preprocess

Preprocessor statements are usually `#include`, `define`, `if`, and `if def`.  

`#include file` just read the `file` and paste its contents at that position. And `#define A b` just replace A with b.

for example: we have `EndBrace.h`, then we can write `Math.cpp` in the following way.

```cpp
// EndBrace.h
}
```

```cpp
// Math.cpp

# define INTEGER int

INTEGER Multiply (INTEGER a, INTEGER b) {
    INTEGER result = a * b;
    return result;
#include "EndBrace.h"

/* it is equivalent to 
 * 
 * int Multiply(int a, int b) {
 *     int result = a * b;
 *     return result;
 * }
 * 
 */
```

`#if` an `#endif` makes it possible to include or exclude code based on certain condition.

### Compile

Turn preprocessed code into assembly code (`.s` files).

Compiler can optimize your code.

Sometimes, when people talk about compiler, they may mean "compiler + assembler" (`.cpp` -> `.obj`) or "compiler + assembler + linker" (`.cpp` -> `.exe`).

## How the C++ Linker Works

It combines separate object files (`.o` or `.obj`) into a executable file (`.exe`).  Please note that codes in object files and those in executable files are machine-level.

Error code starts with C is compiling error.  Error code starts with LNK is linking error.

> Entry can be assigned to other functions. But people usually don't do it.

To avoid symbol-not-found (symbol means function's name) error while compiling, we need to add declaration of that function before it's called. So that compiler knows that this function really exists. And after compilation, linker will link them together.

### Unresolved-external-symbol error

If we delete the definition of a function, although compiler can compile successfully (because its declaration wasn't deleted, and the compiler trusts us), linker will raise this unresolved-external-symbol error because it cannot find the definition of this function.

Special cases ([6:59](https://youtu.be/H4s55GgAg0I?t=419)) and `static` (8:06).

### Duplicate symbols

> Symbol: function's name.

If functions with same name in

- the same file: we will get a compilation error
- different files: we will get a linking error

Because compiler or linker don't know which function we want to call.

This error is actually pretty common ([11:15](https://youtu.be/H4s55GgAg0I?t=675)).

#### How to solve it? 

Watch video [13:00](https://youtu.be/H4s55GgAg0I?t=780).

- `static`: make the duplicate function only visible to its object file (translation unit).
- `inline`: replace the function directly with its definition.
- bring them in the same translation unit—Header files only contain declaration.

## Variables in C++

A variable allows us to name a piece of data and get access to it.

There are a bunch of primitive data types in C++, but C++ don't limit how we use them. So, the only difference between different data types are their size.

The actual size of a primitive data type **depends on compiler**. For example, if you tell `g++` to compile a 32-bit program (`g++ -m32`), then `long` occupies 4 Bytes; if you tell it to compile a 64-bit program (`g++ -m64`), then `long` occupies 8 Bytes. Moreover, although typically, `int` occupies 4 Bytes in both 32- and 64-bit system. The C++ standard only requires it to be at least 2 Bytes (CSAPP 2.2.1), so some compilers may interpret `int` as a 2-Byte number.

When we assign 5.5 to a float `float variable = 5.5`. `5.5` is a double, to assign a float, use `5.5f` or `5.5F`.

bool: 0 is false, anything else is true (including negative numbers).  Although 1 bit is enough to represent a bool, it occupies a Byte (8 bits). Because CPU access addresses in Bytes.  If you want to save spaces, you can store 8 bools in 1 Byte.

function `sizeof()` returns how many Bytes a variable occupies.

pointers: `bool* variable`  <!-- TODO: Add reference (pass by pointer (copy)) later -->
references: `bool& variable`  <!-- TODO: Add reference (pass by reference) later -->

## C++ Header Files

Traditionally, header files are used to declare certain **types or functions**.  ONLY declarations!

Because we need declaration to tell the compiler that this function really exists (but in other files). By including header files, we can introduce multiple declarations with one line. (Remember that the preprocessor just copy and paste the file's content when it meets `#include`).  
> subtopic: declaration and signature
> declaration: `int add(int, int);`
> signature: `add(int, int)`  

Header files usually start with `#pragma once` (header guard), which tells the preprocessor to only include this file once in a translation unit.

There is another way to achieve this (header guard)—`#ifndef`.  Although `#pragma once` is more modern because it's cleaner.

```cpp
#ifndef _LOG_H
#define _LOG_H

// Declarations

#endif
```

It's equivalent to:

```cpp
#pragma once

// Declarations
```

### Difference between `#include <>` and `#include ""`

`#include <>` search files in environment paths.  While `#include ""` search files relative to current path (or in environment paths, but it's better to use it only for user-defined files).

C standard libraries ends with `.h`, for example `#include <math.h>`, C++ standard libraries usually have not suffix `#include <iostream>`.

## How to DEBUG C++ in VISUAL STUDIO

- Set break point
- Step over, step into, step out, continue
- Memory viewer ([10:10](https://youtu.be/0ebzPwixrJA?t=610)). A whole bunch of `cc`s means that this variable is not initialized yet.

## BEST Visual Studio Setup for C++ Projects

Video: [![BEST Visual Studio Setup for C++ Projects!][yt
]](https://youtu.be/qeH9Xv_90KM)

## Loops in C++ (for loops, while loops)

Video: [![Loops in C++][yt]](https://youtu.be/_1AwR-un4Hk)

## Control Flow in C++ (continue, break, return)

Video: [![Control Flow][yt]](https://youtu.be/a3IZ8WaIFAA)

## POINTERS in C++

This video is talking about raw pointers but smart pointers.  Smart pointers will be talked about in the future.

A pointer is an integer storing an memory address.

Types are meaningless, they just tell the compiler how many bytes to read from write to memory each time. The executable binary program itself knows nothing about types.

If you need a pure pointer and don't want to specify what type it points to, you can use `void*`. For example, we can define a pure pointer as `void* ptr = NULL`, `void* ptr = nullptr`, or `void* ptr = &10` (store 10 in memory and create point to its address).

To create a integer pointer: `int *pi = &8`.

`char *buff = new char[8];` allocate 8 bytes in **heap** and let `buff` point to that location in heap.  `memset(ptr, val, size)` (e.g. `memset(buff, 0, 8)`) can initialize (set values for a block of memory).  `delete[] buff` can release the buffer.

Pointers are variables stored in memory. So we can have pointers to pointers. e.g. `char** ptr = &buff`.

## REFERENCES in C++

Pointers and references are relevant.

Reference is a reference to an existing variable. They don't occupy new spaces.

For example

```c++
int a = 5;
int* b = &a; // b is a pointer to a
int& c = a; // c is a reference to a 
// Like `int*`, `int&` can also be regarded as a type.
```

A references can be regarded as an alias of that variable. So compilers will combine reference and the original variable to a single variable. Which means that the compiled binary program won't know the existence of references.

Reference is not a real variable, but a syntax sugar to make our life easier.

```c++
// If you want to change the value passed into an function
// You can pass its address
void increment_1(int* value) {
  (*value)++;
}
increment_1(&a);

// But there is a much easier way -- **pass by reference**
void increment_2(int& value) {
  value++;
}
increment_2(a);
```

Please note:

```c++
int a = 5;
int b = 8;

int& ref = a;
ref = b;
// It doesn't mean ref is now representing b.
// Actually, it means that assign a to b's value, 
// which is 8 -> equivalent to `a = 8;`

// But pointers can make it
int* pi = &a;
pi = &b;

// And you cannot create a dangling reference like `int& ref2;`
// You must assign a variable to a reference immediately after
// it's created. 
int& ref2 = b;
```



<!-- References -->
[yt]: https://img.shields.io/badge/YouTube-%23FF0000.svg?style=flat-square&logo=YouTube&logoColor=white
