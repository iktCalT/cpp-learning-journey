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

`char *buff = new char[8];` allocate 8 bytes in **heap** and let `buff` point to that location on heap.  `memset(ptr, val, size)` (e.g. `memset(buff, 0, 8)`) can initialize (set values for a block of memory).  `delete[] buff` can release the buffer.

Pointers are variables stored in memory. So we can have pointers to pointers. e.g. `char** ptr = &buff`.

Meaning of `*(ptr + num)`: read Section [Arrays in C++](#arrays-in-c).

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

## CLASSES in C++

For example

```c++
class Player {
  int x, y;
  int speed;
public:
  void SetX(int x) {
    this->x = x;
  }
  void SetY(int y) {
    this->y = y;
  }
  void Move(int xa, int ya) {
    x += xa * speed;
    y += ya * speed;
  }
};  // Don't forget this semicolon

int main() {
  // Create instances of Player
  Player player1;
  Player player2;

  // `player1.x = 5;` is not allowed
  // because members are **private by default**
  player1.SetX(5);
}
```

Please note that classes have NO new functionality and CANNOT do new things. Anything you can do with classes can also be done without classes (that's why C still exists).  But classes can really make our code cleaner and make our life easier.

## CLASSES vs STRUCTS in C++

There is basically no difference between class and struct, except for visibility.

Members and methods of **class** are **private** by default. But in **struct**, they are **public** by default.

Although technically, there are almost no difference between class and struct. People have specific convention / style on choosing class or struct.

Use struct to represent a bunch of variables (e.g. vector in math, node of linked list). So, if I need to define a simple and elementary data type (which may be used in many other places) and I don't want to add too much functionality to it, I'd choose struct. Of course, I can add methods to a struct, but they should only realize basic functions.

And I will use class to represent a complicated structure. And I will add a lot of functionality to it.

Moreover, we should never use inheritance with structs. If we need inheritance, use class.

## How to Write a C++ Class

Let's create a simple Log class as an example. Please note that, in practice, people don't write Log class like this, they are terrible codes.

```c++
class Log {
public:
  const int LogLevelError = 0;
  const int LogLevelWarning = 1;
  const int LogLevelInfo = 2;

private:
  int m_LogLevel = LogLevelInfo; // m_ means it's a private class member variable

public:
  void SetLevel(int level) {
    m_LogLevel = level;
  }

  void Error(const char* message) {
    if (m_LogLevel >= LogLevelError) 
      std::cout << "[ERROR]: " << message << std::endl;
  }

  void Warn(const char* message) {
    if (m_LogLevel >= LogLevelWarning) 
      std::cout << "[WARNING]: " << message << std::endl;
  }

  void Info(const char* message) {
    if (m_LogLevel >= LogLevelInfo) 
      std::cout << "[INFO]: " << message << std::endl;
  }
};

int main() {
  Log log;
  log.SetLevel(log.LogLevelWarning);
  log.Warn("Hello");
  log.Info("Hello"); // This won't be printed
  log.Error("Hello");
}
```

## Static in C++

### Static's meaning in different cases

Read [this](https://www.geeksforgeeks.org/cpp/static-keyword-cpp/).

Local: static inside a function means that symbol (**symbol: function / variable / object's name**) is going to be declared only once for the entire lifetime of the program.

Local: static inside class or struct means that symbol is going to shared by all instances of the class / struct (for a variable, its memory address is shared; for a method, *it should be called using the class name with the scope resolution operator (::). It can access only static data members or member functions*).

Global: static outside a scope (class, struct, ...) means that the linage of that symbol is going to be internal (only visible to its translation unit, *meaning it is accessible only within the file where it is defined*).

### Global static symbols

This section will focus on the last meaning—static outside a scope. They are accessible only within its translation unit.

For example

```c++
// file1.cpp
static int s_Variable = 5;
```

```c++
// main.cpp
#include <iostream>

int s_Variable = 10;

int main() {
  std::cout << s_Variable << std::endl;
}
```

If we compile and run it, terminal will print `10` successfully.

But if we delete `static` in `file1.cpp` (now: `int s_Variable = 5;`), even if `main.cpp` didn't include `file1.cpp`, there will be linking error—`"int s_Variable (?s_Variable@@3HA) already defined in Main.obj"`.

#### External linkage

To fix this, except for making both of them static, we can also let one refer to the other.

```c++
// file1.cpp
int s_Variable = 5
```

```c++
// main.cpp
// include
extern int s_Variable;  // external linkage
// main function
```

In this case, you cannot make `s_Variable` in `file1.cpp` static (`static int s_Variable = 5;`). Because, if we do so, `main.cpp` cannot see it.

All rules above (about static variables) also holds for static functions.

#### Summary

If you don't need a variable or a function to be global, use static as much as you can.

## Static for Classes and Structs in C++

Static in a class (or struct) means it's shared by all instances of that class. So, you cannot access that variable or function through a **instance**, you should access it with **class name** with the **scope resolution operator (::)**.

And also, in a static method, you cannot refer to a instance, because static methods can be called even without creating any class instance. But you can a static variable or function can be used in a non-static method.

For example: [![static for class or struct][yt]](https://youtu.be/V-BFlMrBtqQt=89)

```c++
struct Entity {
  static int x;
  static int y;

  static void Print() {
    std::cout << x << ", " << y << std::endl;
  }
};

// We have to define static variable before using them
int Entity::x;
int Entity::y;

int main() {
  Entity::x = 5;
  Entity::y = 6;
  Entity::Print();
}
```

## ENUMS in C++

Enum is short for enumeration. It's a way to give a name to a value. It's useful if you want to use integers to represent  certain states and to make your code more readable.

```c++
// If we don't use Enum
int A = 0;
int B = 1;
int C = 2;

int main() {
  int value = B;
  if (value == A) {
    // Do something about A
  } else if (value == B) {
    // Do something about B
  } else if (value == C) {
    // Do something about C
  } else {
    // We cannot limit the allowed values
  }
}
```

With the help of enum, we can limit allowed values.

```c++
// By default, enums are int starting from 0
enum Example {
  A, B, C=100
}; // int A=0; int B=1; int C=100

/* If we set:
  enum Example : unsigned char {
    A=5, B, C
  }
  Then, unsigned char A=5; unsigned char B=6; unsigned char C=7
  we cannot assign enum to float, it must be integer (char, int, long, ...)
 */

int main() {
  Example value = A;
  // This is NOT allowed: `Example value = 0`;
  // You CANNOT assign `int` to `Example`
  // But you can compare them
  if (value == 0) { 
    // Do something about A
  } else if (value == B) { // Unlike Java, we don't write `value == Example.B` (watch enum class)
    // Do something about B
  } else {
    // Do something about C, because only 0, 1, 100 are allowed values
  }
}
```

Let's improve our Log class in section [How to Write a C++ Class](#how-to-write-a-c-class).

```c++
class Log {
public:
  enum Level {
    LevelError = 0, LevelWarning, LevelInfo
  }

private:
  Level m_LogLevel = LevelInfo;

public:
void SetLevel (Level level)
// following things......
};

int main() {
  Log log;
  log.SetLevel(Log::LevelError);  // Note how we access it
}
```

## Constructors in C++

It's a method runs every time we instantiate (create a instance) a object.

```c++
class Entity {
public:
  float X, Y;

  // Constructor
  Entity() {
    X = 0.0f;
    Y = 0.0f;
  }
  Entity(float x, float y) {
    X = x;
    Y = y;
  }
  // Although C++ have default constructor, it does nothing (unlike Java, it helps us initialize int and float to 0)
};

int main() {
  Entity e1; // e1.X = 0, e1.Y = 0
  Entity e2(10.0f, 5.0f); // e2.X = 10, e2.Y = 5
}
```

If we don't want anybody to create any instance for a class (all members and methods are static).  We can either **make the constructor private** or **delete the constructor** (e.g. `Entity() = delete;`)

## Destructors in C++

Destructor runs when you an object.

For heap allocated objects (created with `new`): when you delete it with `delete`, destructors will be called

For stack allocated objects: when the scope ends, destructors will be called.

For example:

```c++
// Example of destructor called when reaches the end of scope
class Entity {
private:
  float X;
  float Y;

public:
  Entity() {
    X = 0.0f;
    Y = 0.0f;
    std::cout << "Created Entity!" << std::endl;
  }

  // Destructor
  ~Entity() {
    std::cout << "Destroyed Entity!" << std::endl;
  }

  Print() {
    std::cout << X << ", " << Y << std::endl;
  }
};

void Function() {
  Entity e; // stack allocated objects
  e.Print();
} // Destructor is executed when Function() returns

int main() {
  Function(); 
}
```

\[Note\]: You can call destructors manually (e.g. `e.~Entity();`). But usually, people don't do so.

## Inheritance in C++

It helps is avoid code duplication.

```c++
class Entity {
public:
  float X, Y;

  Entity() {
    X = 0.0f;
    Y = 0.0f;
  }

  void Move(float xa, float ya) {
    X += xa;
    Y += ya;
  }
};

// You can inherit multiple classes
// class A : public B, public C
class Player : public Entity {
public:
  const char* Name;

  void Print() {
    std::cout << Name << std::endl;
  }
};

int main() {
  Player player;
  player.Move(1, 2);
  std::cout << player.X << std::endl;
}
```

Polymorphism: read [this](https://www.w3schools.com/cpp/cpp_polymorphism.asp).

## Virtual Functions in C++

It allows us to overwrite functions in subclasses.

```c++
class Entity {
public:
  std::string GetName() { return "Entity"; }
};

class Player : public Entity {
private:
  std::string m_Name;
public:
  Player(const std::string &name) : m_Name(name) {}

  // Overrides GetName() 
  // unlike Java, it don't need to write @Override 
  // But it's recommended to add this keyword
  // read section "### Virtual function + override keyword"
  std::string GetName() { return m_Name; }
};

int main() {
  Entity* e = new Entity();
  std::cout << e->GetName() << std::endl; // Entity

  Player* p = new Player("Cherno");
  std::cout << p->GetName() << std::endl; // Cherno

  Entity* entity = p;
  std::cout << entity->GetName() << std::endl; // Entity
}
```

It can be inferred from the last that case that:  
In memory, different objects (instances) are just a block of data (storing its member variables). And the behavior of a function is defined by its type (class), and compilers will read the type and find the definition of methods, than translate them into binary files.

```c++
// define class Entity and class Player

void PrintName(Entity* entity) {
  std::cout << entity->GetName() << std::endl;
}

int main() {
  Entity* e = new Entity();
  PrintName(e); // Entity

  Player* p = new Player("Cherno");
  PrintName(p); // Entity
}
```

Because `PrintName(Entity* entity)` function regard its argument as `Entity`, it will call `Entity`'s version of `GetName()`.

But sometimes, we want to call methods based on its 'real' class.  

### Virtual function

To solve this problem, we can declare the function in base class as **virtual function**.

```c++
class Entity {
public:
  virtual std::string GetName() { return "Entity"; }
};
// following codes
```

It's achieved by creating a v-table for the `Entity` class.

V-table is a table containing all virtual functions within base class (will be introduced later).

### Virtual function + override keyword

Only virtual functions can be overridden. So base class: `virtual std::string GetName() {}`. Subclass: `std::string GetName() override {}`

```c++
class Entity {
public:
  virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity {
private:
  std::string m_Name;
public:
  Player(const std::string &name) : m_Name(name) {}

  // Overrides GetName() with keyword override
  std::string GetName() override { return m_Name; }
};
```

Moreover, it's recommended to add this keyword. Because if we made some mistakes (for example, mis-typed function name or the overridden function is not virtual), the compiler will warn us.

## Interfaces in C++ (Pure Virtual Functions)

Interfaces consist of **pure virtual functions** (in other languages, we say "interfaces", but in C++ we often say "pure virtual functions").  They're classes (acting as templates) with only unimplemented methods, so the **subclasses are required to implement them**.  

Because they don't implement methods, **we cannot create instances of interfaces**. Moreover, if a subclass implement only a part of pure virtual functions, we cannot instantiate that subclass either.

```c++
class Entity {
public:
  // pure virtual function
  virtual std::string GetName() = 0;

  // virtual function
  // virtual std::string GetName() { return "Entity"; }
};
```

Here is another example:

```c++
class Printable {
public:
  virtual std::string GetClassName() = 0;
};

class Entity : public Printable {
public:
  virtual std::string GetName() { return "Entity"; }
  std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity {
private:
  std::string m_Name;
public: 
  Player(const std::string& name) : m_Name(name) {}

  std::string GetName() override { return m_Name; }
  std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj) {
  std::cout << obj->GetClassName() << std::endl;
}

int main() {
  Entity* e = new Entity();
  Player* p = new Player("Cherno");

  Print(e);
  Print(p);
}
```

## Visibility in C++

It has nothing to do with program performance, it's used to help you organize your code.

Three visibilities: `private`, `protected`, and `public`.  The default visibility for class members is `private`. The default visibility for struct is `public`.

- `private`: "only" the methods of this class can read and write to it.  Actually, methods of `friend` classes can also access it (Will be covered later).
- `protected`: this class and it's child classes can access it.
- `public`: accessible to all.

Mark members as `public` when you this member can be used by others. Otherwise, mark them `private` or `protected`.  It helps both others and yourself.

## Arrays in C++

Arrays store a bunch of data with same type continuously.  With the help of array, we can access multiple variables with only one name.

For example,

```c++
int main() {
  int example[5] = {0,1,2,3,4};

  std::cout << example[0] << std::endl; // 0
  std::cout << example << std::endl; // print the address of array

  example[2] = 5;
  // is equivalent to 
  int* ptr = example.
  *(ptr + 2) = 5;
      // ptr + 2 -> ptr moves 2*sizeof(int) Bytes. 
      // Because ptr's type is int*
  // is equivalent to
  *((char*) ptr + 8) = 5;
      // (char*) says treat ptr as char*. 
      // So ptr moves 8*sizeof(char) = 8 Bytes
  // is equivalent to
  *(int*)((char*) ptr + 8) = 5;

  // initialization
  int example2[5] = {1}; 
      // {1,0,0,0,0} 
      // set the first element to 1 and reset others to 0
  std::fill_n(example2, sizeof(example2)/sizeof(example2[0]), 1); 
      // fill example2 with 1
  // In newer version of C++:
  example2.fill(1); 
  // or 
  std::fill(begin(example2), end(example2), 1)
}
```

We can also create an array with `new` keyword. `int* arr = new int[5]` is equivalent to `int* arr[5]`, except for their lifetime.  

- `int* arr = new int[5]`is created on heap, it will be alive until we destroy it manually with `delete[] arr` (or until the program ends).
- `int* arr[5]` is created on stack, it will be destroyed when we reach the end of the scope (the end curly bracket).

Why create on heap rather than stack?—it's about lifetime, if you have a function creating and returning a new array. You should use `new`. Otherwise, it will be destroyed when the function ends.

\[Note\]: If we create a pointer to an array `int* pa = new int[5]`. When we access the array with the pointer, we need to jump from one memory address to another, which will case cache miss, and slow down the program.  So, to avoid cache miss, create arrays on **stack** whenever possible.

### Arrays in C++11

In C++, "standard array" `std::array<type, num>` is introduced (the arrays above are called "raw array"). Standard arrays have **boundary checking** and keep track of the **length of array**.  

Standard arrays are safer, but raw arrays are faster.

To get the length of a raw array on **stack**, we have to use `sizeof(arr) / sizeof(arr[0])`.  If you apply this method on raw arrays on heap, thing might get wrong. If you write

```c++
int* pa = new int[5]; 
int length = sizeof(pa) / sizeof(int);  
// Wrong! You'll get 1 or 2
```

Because `pa` is a pointer, `sizeof(pa)` will return 8 (on 64-bit program) or 4 (on 32-bit program). So, the length we get will be 8/4 = 2 or 4/4 = 1.

Moreover, you cannot do

```c++
const int size = 5;
int arr[size];
```

In `int arr[size];`, `size` must be known at compile time, but `const int size = 5;` is not known at compile time (because it's C++).  To solve this problem, use `constexpr int size = 5;` or `static const int size = 5;`.  `constexpr` will be covered in other sector.

However, with standard arrays, we can get its length simply.

```c++
sdt::array<int, 5> another_arr;
std::cout << another_arr.size() << std::endl; // 5
```

## How Strings Work in C++ (and how to use them)

String is a sting of text.

### Characters

Characters: in C++ type `char` can represent one Byte of memory. It can also represent one ASCII character.

> Charset (character set) and Character Encoding:
>
> | Charset | Encoding    |
> | :---    | :---        |
> | ASCII   | ASCII       |
> | Unicode | UTF-8/16/32 |
>
> UTF: Unicode Transformation Format
> UTF-16 and UTF-32 are fixed length, they use 16 and 32 bits respectively. UTF-8 is variable length.

8 bits is not enough to represent all letters and symbols in English, Japanese, Korean, Chinese, etc... However, in C++ primitive types, `char` can only represent up to 256 characters (although ASCII only uses non-negative 128 numbers of `char`).

As for how to support non-English characters, it won't be covered here. 

### How string works

A string is an **array** of characters.

So, `'A'` is a `char`. `"A"` is a char pointer (string).

### C-style

Assigning a string: `const char* name = "Cherno";`.  

If you don't want to use it anymore, just don't use it. You should NOT delete it—`delete name;` is illegal.  **Remember: if you didn't use `new` keyword, don't use `delete` keyword.**

`const` make sure that the values stored at those addresses CANNOT be changed. `name[2] = 'a'` is illegal if `name` is declared as `const char*`.  And it's not recommended to delete `const`. If you declared a string as `char* name = "Cherno";`, then change it `name[2] = 'a'`, it's an **undefined behavior** (watch next [video](https://youtu.be/FeHZHF0f2dw?t=203)).  Thus, strings are immutable, if you want to change a character, just create a new string. So, strings are always `const char*` (some compilers don't let you compile a `char*` without `const`).

All strings are end with a `'\0'` (ASCII 0, NUL) character. It's used to indicate where the string ends. So, `sizeof("Cherno")` is 7 (not 6).

These three are equivalent  
`char* name = "Cherno";`  
`char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', '\0' };`  
` char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', 0 };`

### C++-style

C++ standard library has a class called `std::string`. It's essentially a array of `char` (more specifically, `const char*`, same as above).  But there are a bunch of methods related to it.

```c++
#include <string>

int main() {
  std::string name = "Cherno".
  // size() is a method of std::string class
  name.size(); // 6

  // in a char array, we have to use functions (not defined in class)
  char* s1[] = "Cherno";
  char* s2[20];
  strlen(s1); // 6
  strcpy(s2, s1); // copy s1 into s2
}
```

Since you cannot add two pointers together, you cannot add two `const char*` together.  BUT, `+` is overloaded in `std::string` class.

So, `std::string name = "Hello" + ", World!";` is illegal.  But `std::string name = "Hello";  name += ", World!"` and `std::string name = std::string("Hello") + ", World!";` are legal. Or, [use `std::string_literals` library](#stdstring_literals-library).

You can find substrings in a string.

```c++
int main() {
  std::string name = std::string("Hello") + ", World!";
  // name.find("no") returns the address of 'n' in "Cherno"
  if (name.find("no") != std::string::npos) {  // npos: not legal position
    std::cout << "Contains!\n";
  }
}
```

If you want to create a function that **only reads** a string, don't use `PrintString(std::string string)`, use `PrintString(const std::string &string)` (`const` + pass by reference) instead. It can save time and space.

[Document](https://cplusplus.com/reference/string/string/).

## String Literals in C++

### Don't create a string with `\0`

If your string has NUL `'\0'`, you may meet some problem.

```c++
#include <stdlib.h>

int main() {
  const char* name = "Che\0rno";
  std::cout << strlen(name) << std::endl;  // 3, only counts "Che"
}
```

### String Immutability

Changing a character in a string that is not protected by `const` (for example `char* name = "Cherno";`) is undefined behavior.  Because string literals are stored in a read-only segment called "const segment" of memory.  And if you check the generated binary file, you'll find `"Cherno"` is embedded in the binary file. So, they should not be edited.

If you really want to change it, define it as an **array** `char name[] = "Cherno";  name[2] = 'a';`.

### Wide character

We can declare a wide character with `const wchar_t* name2 = L"Cherno";`. `L` means the following string is made of wide character (16 bits on windows, 32 bits on Unix/Linux).

There are other types of character.

- `const char* name = u8"Cherno";`—normal string with 8-bit characters. `u8` can be omitted.
- `const wchar_t* name = L"Cherno";`—16 or 32 bits.
- `const char16_t* name = u"Cherno";`—16 bits, used for UTF-16.
- `const char32_t* name = U"Cherno";`—32 bits, used for UTF-32.

### `std::string_literals` library

From C++14, you can use `std::string_literals` to concatenate strings. For example, `std::string name = "Cherno"s + " hello.";`. The `s` convert `"Cherno"` into a `std::string`. You can also do `std::string name = u8"Cherno"s;`, `std::wstring name = L"Cherno"s;`, `std::u16string name = u"Cherno"s;`, `std::u32string name = U"Cherno"s;` to specify how many bytes are used for one character.

### Multiline string

```c++
const char* example = R"(Line1
Line2
Line3)"; // don't forget ()
// is equivalent to
const char* example2 = "Line1\n"
"Line2\n"
"Line3"
```

### String literals are always on read-only segment

String literals are always on read-only segment. Even if we created an array of characters and change it. 

```c++
char name[] = "Cherno";
name[2] = 'a';
```

`name` will point to a location not in read-only segment. Then it reads the string ("Cherno") from read-only segment and copy it into where `name` is pointing at, then modifies it.  If we don't modify it, `name` will point to the read-only segment directly.

[![string literals][yt]](https://youtu.be/FeHZHF0f2dw?t=683)

<!-- References -->
[yt]: https://img.shields.io/badge/YouTube-%23FF0000.svg?style=flat-square&logo=YouTube&logoColor=white
