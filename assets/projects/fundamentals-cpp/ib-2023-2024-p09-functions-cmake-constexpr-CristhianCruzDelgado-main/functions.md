# Lab Assignment 09. Functions. CMake. Constant expressions.

# Weighting factor: 8

### Objectives
The objectives of this assignment are that students:
* Are able to solve simple problems in C++ using everything learned so far,
  and in particular functions
* Design, develop and use functions in their programs, making their programs modular
* Know the CMake tool and are able to use it at a basic level to build their executable programs

### Assessment rubric for this assignment
The most relevant aspects that will be taken into account when assessing this assignment are listed below (the list is not exhaustive).
It will be checked that students:
* Know the concepts presented in the reference material of this assignment.
* Have completed all the exercises proposed in this statement
* Are able to write simple C++ programs that solve problems of similar complexity to those proposed in this document
* Are able to write a `CMakeLists.txt` file to automate the compilation of their programs with `cmake` and `make`
* Have automated the compilation of their programs with a `Makefile` for each of the programs they develop
* Structure their programs around different functions (modular programs)
* Organise all their programs in a separate folder for each "project", each one containing a `CMakeLists.txt` file with the build configuration of the project.
* Use appropriate comments in the format required by [Doxygen](https://www.doxygen.nl/index.html) in all their programs
* Can prove that all the assignments completed so far are hosted in private [GitHub](https://github.com/) repositories.
* Can prove that they are able to submit programs to the [Jutge](https://jutge.org/) platform for assessment
* Have included a prologue comment in every file (`*.cc`, `*.h`) of their exercises
* Make every program they develop print, before running, a message stating the purpose of the program and the information it will need from the user to run correctly.
* Make every program submitted for assessment comply with the standards defined in the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* Always use meaningful identifiers in their programs (for constants, variables, etc.) and never use single-letter identifiers, perhaps with the exception of loop variables.
* Can prove that they are able to edit remote files on their VM with vi
* Have completed all their exercises on the subject's Ubuntu virtual machine.
* Show that they are able to run Linux commands on their VM

### Programs with multiple source files
As programs grow, it is common to split them into several files (modules) for organisation or code
reuse.
In a real software development project, programs commonly consist of hundreds or thousands
of source files.
Study the following sections of the reference tutorial:
* [2.7 — Forward declarations and definitions](https://www.learncpp.com/cpp-tutorial/forward-declarations/)
* [A multi-file example](https://www.learncpp.com/cpp-tutorial/programs-with-multiple-code-files/) in section 2.8 of the tutorial (skip the introductory part about IDEs).
* [2.11 — Header files](https://www.learncpp.com/cpp-tutorial/header-files/)

Next, consider as an additional example the program in the folder [headerSourceSeparation](https://github.com/IB-2023-2024/IB-class-code-examples/tree/master/Tools/cmake/headerSourceSeparation) of the subject's code examples.

That program consists of three files: `main.cc`, `tools.cc` and `tools.h`.
The `Makefile` in that folder compiles the program.
Run `make` and observe the commands executed during compilation.
Then examine the code of all those files.
The main program simply calls the functions *MakeItRain()* and *MakeItSunny()*.
Those functions are defined in `tools.cc`, and their declarations (also called
prototypes) are in `tools.h`.
Any module (a `*.cc` file with code) that needs these functions must include (as
`main.cc` does) the file `tools.h`, where they are declared.

This is exactly what has been done so far with other header files:
any C++ program that needs mathematical functions such as *sin()*, *cos()*, *fabs()*, *exp()*,
etc. must include the header file `cmath` (`#include <cmath>`), which holds the
declarations of those functions.
Likewise, the header file `iostream` declares the classes and functions needed to
perform basic input/output operations.
For C++ library functions, the definitions are not in source files
(`*.cc`); instead, their binary code, stored in a library, is added to the final program by
the linker, as already studied.

The split into different source files shown in this academic example is very common in
real programming projects, which, as already mentioned, usually involve hundreds or thousands of
files.
Using tools such as `make` to compile this kind of project is essential to streamline
the development process.

### The `cmake` tool
[CMake](https://es.wikipedia.org/wiki/CMake)
is what is known as a *meta-build* system.
It is not used to build the executable program of an application; instead,
it produces native project files for the target platform.
For example, CMake on Linux generates a Makefile;
on Windows it generates a Visual Studio solution;
on macOS it generates an Xcode project, and so on.
That is what the word *meta* means: CMake builds build systems (*builders*).
The `make` tool already studied is a build system, possibly the most common one, so
in *Informática Básica* CMake will be used to generate a Makefile with which each
of the projects (programs) developed will be compiled.

A CMake-based project always contains a `CMakeLists.txt` file
that describes how the project is structured, the list of source
files to compile, what CMake must generate from it, and so on.
In short, it is a configuration file for the CMake tool.
CMake reads the instructions in that file and produces the desired result.

A useful feature of CMake is the so-called "*out-of-source build*".
Every file required for the final build, including the executables,
is stored in a separate build folder, usually called `build/`.
This keeps unwanted files out of the source folder and makes it easy to start
over: just delete the build folder (`build/`) and that is all.

CMake is a very powerful tool with many options.
These options can be studied in depth in [the documentation](https://cmake.org/cmake/help/latest/index.html)
of the tool, but for the use proposed
in *Informática Básica* it is enough to study carefully
[this short tutorial](https://www.internalpointers.com/post/modern-cmake-beginner-introduction).

In the root folder of this assignment's repository you will find a subfolder `fibonacci_sum` with the
following content:
```
  fibonacci_sum
  ├── CMakeLists.txt             // CMake configuration file
  ├── CMakeLists.txt.simpler     // Another, simpler configuration file
  ├── doc                        // Documentation
  ├── fibonacci.Doxyfile         // Doxygen configuration file
  ├── READ_ME.txt
  └── src                        // Source code of the application
      ├── fibonacci_main.cc
      ├── fibonacci_sum.cc
      ├── fibonacci_sum.h
      ├── tools.cc
      └── tools.h
```
This folder structure (to which the folders `build/` -and optionally `lib/`- are added)
is common in software development projects.
This example takes the `fibonacci_sum` application, which computes the sum of the even terms of the Fibonacci
sequence, and splits it into 5 source files (`*.cc` and `*.h`).
The configuration file `CMakeLists.txt` contains the configuration used to build the
application.
To illustrate this process, a library `libtools.a` is created and placed in the `lib` folder.
The binary program (`fibonacci_sum`) is built by linking this library with the rest of the object code
produced by the compilation.

> Note that the folder `fibonacci_sum/doc` is not in the repository; it must be created manually with `mkdir` before building the program.

To build the application, follow these (usual) steps:
```
$ cd fibonacci_sum
$ mkdir build
$ cd build
$ cmake ..
$ make
```

The fourth of these commands, `cmake`, uses the configuration file `CMakeLists.txt` to create in the
`build` folder the `Makefile` that the `make` command uses to build the application,
whose binary program `fibonacci_sum` is also created in the `build` folder.

Experiment with the provided configuration file, `CMakeLists.txt`, to adapt it to each
of your own projects (assignment exercises).
In principle, you do not need to build your own libraries for your programs.
Building a library has been included in this example only to illustrate the process.

The included file `CMakeLists.txt.simpler` is simpler than the previous one: it does not generate the
documentation (Doxygen) of the project, nor does it build any library linked with the final program.
You may use this file (renamed to `CMakeLists.txt`) as a "template", adapting it from now
on to each of your C++ programming projects.

### Constant expressions

When a constant is declared with the `const` keyword, the compiler implicitly checks whether it is a *compile-time* or a *run-time* constant. In most cases this only matters for code optimisation, but there are cases in which C++ requires a constant expression that only uses values defined at compile time. Since this kind of constant allows better optimisation, we will generally try to make constants evaluable at compile time.

Whether a constant can be evaluated at compile time or at run time depends on whether its initialisation can take place during compilation. In some cases this can be hard to determine. For example:

```
int variable{5};               // not constant
const int my_var1{x};          // run-time constant: its initialiser is not constant
const int my_var2{5};          // compile-time constant: its initialiser is a constant expression
const int result{getValue()};  // unclear: it depends on how getValue() is defined
```

Fortunately, the compiler can be told when a constant must be evaluable at compile time. To do so, use the `constexpr` keyword instead of `const`. A `constexpr` ("constant expression") can only be evaluated at compile time. If its initialiser is not a constant expression, the compiler reports an error.

```
#include <iostream>

int Five() {
  return 5;
}

int main() {
  constexpr double gravity{9.8};  // correct: 9.8 is a constant expression
  constexpr int sum{4 + 5};       // correct: 4 + 5 is a constant expression
  constexpr int something{sum};   // correct: sum is a constant expression

  int age;
  std::cin >> age;
  constexpr int myAge{age};      // error: age is not a constant expression
  constexpr int young{Five()};   // error: the return value of five() is not a constant expression
  return 0;
}
```

As good practice, every value that must not change after its initialisation should be declared:

- as `constexpr`, if its value is known at compile time
- as `const`, if its value is not known at compile time

Note that some data types that allocate memory dynamically, such as `std::string` and `std::vector`, are not compatible with `constexpr`; constants of these types must use `const`. Likewise, function parameters are always evaluated at run time and therefore cannot be declared `constexpr`.

In some contexts, the compiler may decide that an expression does not need to be evaluated at compile time.

```
constexpr int variable{3 + 4};  // 3 + 4 is always evaluated at compile time
const int my_var{3 + 4};        // 3 + 4 is always evaluated at compile time
int result{3 + 4};              // 3 + 4 may be evaluated at compile time or at run time
```

Consider the following example:

```
#include <iostream>

int main() {
  constexpr int x { 3 + 4 }; // 3 + 4 is a constant expression
  std::cout << x;            // Evaluated at run time
  return 0;
}
```

`3 + 4` is a constant expression, so the compiler evaluates it at compile time and replaces it with the value `7`. Since `x` is also a compile-time constant, the compiler will probably optimise the program by replacing `std::cout << x` with `std::cout << 7`, which runs at run time. However, since `x` is used only once, the compiler is more likely to optimise the program by removing `x` before evaluating `3 + 4`:

```
#include <iostream>

int main() {
  std::cout << 3 + 4;  // Evaluated at run time
  return 0;
}
```

The expression `std::cout << 3 + 4` is no longer constant, which raises the question of whether the subexpression `3 + 4` is evaluated at compile time. In general it will be optimised, since compilers can detect constant subexpressions even when they are part of run-time expressions. This optimisation is known as *"constant folding"*. Marking constant expressions as `constexpr` ensures that those values are recognised by constant folding whenever they are used in a run-time expression.

### Complementary study material
Study everything in the section
[Functions](https://google.github.io/styleguide/cppguide.html#Functions)
of the Google Style Guide and put into practice everything it proposes.
You may find content in that section that you have not studied yet: do not worry.
Focus on the aspects you already know, to consolidate them.

Study the following sections of the subject's
[reference tutorial](https://www.learncpp.com/):
* [Local variables](https://www.learncpp.com/cpp-tutorial/local-variables/)
* [Introduction to global variables](https://www.learncpp.com/cpp-tutorial/introduction-to-global-variables/)
* [Variable shadowing (name hiding)](https://www.learncpp.com/cpp-tutorial/variable-shadowing-name-hiding/)
* [Scope, duration, and linkage summary](https://www.learncpp.com/cpp-tutorial/scope-duration-and-linkage-summary/)
* [Command line arguments](https://www.learncpp.com/cpp-tutorial/command-line-arguments/)
* [Constant expressions](https://www.learncpp.com/cpp-tutorial/constexpr-variables/)

### Exercises
* When doing the exercises, create inside your repository for this assignment a separate folder
for each exercise.
Give each folder a meaningful name.
* Automate the compilation of each exercise's program with the cmake tool.
* Make every program take its input from the command line and, if it is run without
  the right number of parameters, print a message stating the correct way to
  run the program.
* The code of each program must be modular, that is, it must use functions
* Each function must perform a single task and do it correctly
* The identifier of a function must clearly reflect what the function does


1. Write a program `scalar_product.cc` that uses a function taking two vectors of real
numbers as parameters and returning their scalar product, computed as the sum of the products of the elements in the same position

$$[a1, a2, a3] \cdot [b1, b2, b3] = a1 * b1 + a2 * b2 + a3 * b3$$

  If the function detects that the vectors do not have the same length, it must print an error message and return 0.

2. Write a program `capitalize_vowels.cc` that includes a function taking as a parameter a string with no
spaces and modifying it so that consonants are lowercase and vowels are uppercase.
Characters that are neither uppercase nor lowercase letters must remain unchanged.

```
Public test cases
Input           Output
Abecedario      AbEcEdArIO
PyThon          pythOn
AlFa2022        AlfA2022
```

3. Write a program `polynomial.cc` that includes a C++ function receiving as parameters a vector of real
coefficients `coefficients` and a real value `value`, and computing the value of the corresponding polynomial at the given value, using
the following scheme:

$$(...(((coef_0 * value + coef_1) * value + coef_2) * value + coef_3) * value + coef_4) * value + ...) * value + coef_{N-1}$$

```
Public test cases
Coefficients    Value    Output
2 4 6 8         0        8
1 3 5           2        15
1 1 1 1 1       4        341
```

4. Write a program `approximate_root.cc` that includes a function taking as a parameter a real number greater than
zero, `number`, and returning its square root with an error of ±`EPSILON` (where `EPSILON` is a sufficiently small
real constant, for example `1e-4`). The function must internally use two real values, `root` and `delta`,
with any initial values (1.0 is recommended for both), and follow this procedure:

    - While the difference between `root`² and `number` is greater than `EPSILON`:
      - if `delta` is positive: while `root`² is __less__ than `number`, add `delta` to `root`.
      - otherwise: while `root`² is __greater__ than `number`, add `delta` to `root`.
      - multiply `delta` by -0.5.
    - Return the value of `root`.

5. Write a program `hypotenuse.cc` that includes a function taking as parameters the legs of a
right triangle, as real values, and returning its hypotenuse, using the function implemented in
exercise 4 to compute it.

$$hypotenuse = \sqrt{leg1^2 + leg2^2}$$

```
Public test cases
Input     Output
3 4       5
7 9       10.4018
10 12     15.6205
```
