# Lab Assignment 12. Introduction to Object-Oriented Programming. Debugging.

# Weighting factor: 10

### Objectives
The objectives of this assignment are that students:
* Develop simple C++ programs using object-oriented programming, as well as all the language features studied previously

### Assessment rubric for this assignment
The most relevant aspects that will be taken into account when assessing this assignment are listed below (the list is not exhaustive).
It will be checked that students:
* Know the concepts presented in the reference material of this assignment.
* Have completed all the exercises proposed in this statement
* Are able to write simple C++ programs that solve problems of similar complexity to those proposed in this document
* Are able to use VSC to edit and compile programs remotely on their virtual machine
* Know the Exercism platform and are able to download and solve simple problems by interacting with it.
* Are able to write a `CMakeLists.txt` file to automate the compilation of their programs with `cmake` and `make`
* Have automated the compilation of their programs with a `Makefile` for each of the programs they develop
* Structure their programs around different functions (modular programs)
* Organise all their programs in a separate folder for each "project", each one
  containing a `CMakeLists.txt` file with the build configuration of the project.
* Use appropriate comments in the format required by
[Doxygen](https://www.doxygen.nl/index.html) in all their programs
* Can prove that all the assignments completed so far are hosted in private
[GitHub](https://github.com/) repositories.
* Can prove that they are able to submit programs to the
[Jutge](https://jutge.org/)
platform for assessment
* Have included a prologue comment in every file (`*.cc`, `*.h`) of their exercises
* Make every program they develop print, before running, a message stating the
  purpose of the program and the information it will need from the user to run correctly.
* Make every program submitted for assessment comply with the standards defined in the
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* Always use meaningful identifiers in their programs (for constants, variables, etc.) and
  never use single-letter identifiers, perhaps with the exception of loop variables.
* Can prove that they are able to edit remote files on their VM with vi
* Have completed all their exercises on the subject's Ubuntu virtual machine.
* Show that they are able to run Linux commands on their VM

### Introduction to debugging
Testing a program with a well-chosen set of input tests gives the programmer confidence
that the program is correct.
During testing, the programmer observes the input-output relations, that is, the output
the program produces for each input test case.
If the program produces the expected output and meets the specification for each test case,
the program has been tested successfully.

But if the output of one of the test cases is not the expected one, the program is incorrect:
it contains errors (also known as "*bugs*").
In such situations, testing only reveals the presence of errors; it does not show what they are or how
to fix the code.
In other words, testing reveals the effects (or symptoms) of errors, not their cause.
The programmer must then undertake a debugging process to identify the causes and fix the errors.

You may be surprised to learn that debugging usually takes more time than writing the code.
Most of the development time of an application is spent debugging and maintaining the code rather than writing it.

That is why the best approach is to avoid errors when writing the program.
It is important to sit down and think before coding: decide exactly what needs to be achieved, how you plan to achieve it,
design the high-level algorithm cleanly, convince yourself that it is correct, and decide which specific data structures
you plan to use.
All the effort spent designing and thinking about the code before writing it will pay off later.
The benefits are twofold.
First, a clean design reduces the likelihood of program defects.
Second, even if an error appears during testing, a clean design
makes it much easier to track down and fix.

It can be very tempting to write the program as fast as possible, leaving little or no time to think about it beforehand.
The programmer will be pleased to see the program running quickly.
But frustration is likely to follow soon: without careful thought, the program will be complex and unclear,
so maintenance and bug fixing will become an endless process.

Once the programmer starts coding, they should program defensively.
This is similar to defensive driving, which means driving so as to avoid adverse scenarios
(for example, other drivers breaking traffic laws, unexpected events or obstacles, etc.).
Likewise, defensive programming means writing code so that it works correctly in
the worst scenarios of its environment.
For example, when writing a function, assume worst-case inputs for that function, that is,
inputs that are too large, too small, or that violate some property, condition or invariant;
the code must handle these cases, even if the programmer does not expect them to occur under normal circumstances.

Remember that the goal is not to become an expert at fixing errors,
but to get better at writing robust and (mostly) error-free programs.
As a matter of attitude, programmers should not feel proud when they fix errors,
but rather embarrassed that their code contained them.
If there is a fault in a program, it is only because its author made mistakes.

There are several approaches to debugging simple programs.
You can review those options in the lecture slides
[Debugging your source code](https://docs.google.com/presentation/d/1-vU5UF1ruhHWMp-lJsoYsq8s8B9ZvJvBsdDUu4wVgDU/edit?usp=sharing),
but using a debugger is undoubtedly the best option as soon as the program to debug
is of a certain size.

Debugging is one of the most important tasks in programming.
Knowing how to use a debugger to set breakpoints, and how to step over and into the functions
being used, saves hours of development.
Debugging not only saves valuable development time; it also helps you better understand the logic of the code
and its flow of execution, which is not the main goal of debugging but is a great side effect.

The following tips, taken from the subject's
[reference tutorial](https://www.learncpp.com/cpp-tutorial/finding-issues-before-they-become-problems/),
aim to prevent programming errors.
The list is incomplete but can be very valuable:
* Always follow programming
[*Good Practices*](https://docs.google.com/presentation/d/1pj0YVWwOhWI0CGj2wjsHAebnFxfVtowRcFTOdBiloSc/edit?usp=sharing).
All of them are designed to minimise the number of potential errors.
* Do not let your functions grow too long (roughly the number of lines that fit on one screen, at most)
* Comment your code sensibly wherever relevant
* Simplify your programs
* Whenever possible, prefer the standard library (STL) to writing your own code.
In particular, in *Informática Básica*, use `std::vector`/`std::array` or `std::string` instead of "C-style"
arrays or strings
* Do not program when you are tired
* Understand where the common pitfalls of a language are (everything you are warned not to do)

In conclusion, **all the time you spend learning to use a debugger is time you
will gain in the future as a professional**.

### Debugging with Visual Studio Code
One of the great advantages of using an integrated development environment such as VSC is that it includes an
advanced debugger.
*Informática Básica* proposes using the
[gdb](https://www.sourceware.org/gdb/)
debugger through its Visual Studio Code interface.

If you have not done so, *Informática Básica* recommends keeping Visual Studio Code in its
English version when you install it (it can be customised for Spanish), because that way you can better follow
the various English tutorials about the program.

To learn how to use the debugger in VSC, start by following the instructions on the page
[Using C++ on Linux in VS Code](https://code.visualstudio.com/docs/cpp/config-linux)
of the official documentation.
That page explains how to edit, compile, run and debug the file `hello_world_debug.cc`, which is
available in the folder of this assignment.
Pay particular attention to the section
[Debug helloworld.cc](https://code.visualstudio.com/docs/cpp/config-linux#_debug-helloworldcpp),
which explains the basic debugging commands.

Next, watch and follow the instructions in the video
[Debugging with VSC and GDB](https://www.youtube.com/watch?v=MZK9U8GOaao),
available in the *Informática Básica* virtual classroom.
In the main folder of this assignment you will find the file `fibonacci_sum.tar.gz`, which contains the code
used in the video, already studied in a previous assignment.

Then also watch and follow the instructions of the video, also available in the virtual classroom,
[Debugging a C++ project](https://www.youtube.com/watch?v=O1GhRC3ECWo),
which shows how to compile, run and debug a program split into several files.
The files used in that video are available in the folder `debug-VSC-multiple-files/` of
this assignment.

As an exercise, then try to use the debugger to find the error in the program `debug.cc`
in the folder of this assignment.

From this point on, you are advised to *always* use the debugger to identify errors in every
program you develop.

### Complementary study material
Start by studying the material in the slides
[Debugging your source code](https://docs.google.com/presentation/d/1-vU5UF1ruhHWMp-lJsoYsq8s8B9ZvJvBsdDUu4wVgDU/edit?usp=sharing),
available in the subject's virtual classroom.

Study all the sections of chapter 3 of the subject's
[reference tutorial](https://www.learncpp.com/)
(taking into account the specifics of VSC).

The introduction to debugging in this statement is taken from the lecture
[Debugging Techniques](https://www.cs.cornell.edu/courses/cs312/2006fa/lectures/lec26.html)
of Cornell University.

### Exercises
* When doing the exercises, create inside your repository for this assignment a separate folder
for each exercise.
Give each folder a meaningful name.
* Automate the compilation of each exercise's program with a separate `Makefile`
for each program, and place it in the corresponding folder.
Alternatively, `cmake` with a `CMakeLists` file may be used, if preferred.
* Make every program take its input from the command line and, if it is run without
  the right number of parameters, print a message stating the correct way to
  run the program.
* The code of each program must be modular, that is, it must use functions
* Each function must perform a single task and do it correctly
* The identifier of a function must clearly reflect its purpose

1. Write a class `Point2D` to represent points in two-dimensional space by their
coordinates.
Include at least the following methods:
* *Show()* to print the coordinates of the point
* *Move* to change the coordinates of the point
* *Distance* to compute the
[distance](https://www.mathwarehouse.com/algebra/distance_formula/index.php)
between two points
* *Middle* to compute the
[midpoint](https://en.wikipedia.org/wiki/Midpoint)
of the segment joining two points

2. Design a class `Circulo` to represent circles, with the centre,
the radius and the colour of the circle as attributes.
Use an
[enumeration](https://www.learncpp.com/cpp-tutorial/unscoped-enumerations/)
(`enum`) to represent the colour of the circle.
Include methods *Area*, *Perimetro* and *Print* that respectively compute the area and the perimeter of the
circle and print the information about the circle.
Also include a method *EsInterior* that determines whether a point of the Cartesian plane `(x, y)` lies
inside the circle.

3. The `Complejo` class.

Every
[complex number](https://es.wikipedia.org/wiki/N%C3%BAmero_complejo)
can be written as the sum of a real number and an imaginary number, in the form `a + bi`, where the
term `a` is the real part, `b` the imaginary part and `i` the
[imaginary unit](https://es.wikipedia.org/wiki/Unidad_imaginaria).

This exercise proposes writing a class `Complejo` to represent and operate with complex numbers.

Split the design of your class `Complejo` into two files, `complejo.h` and `complejo.cc`, containing
the declaration and the definition of the class respectively.
Follow the tutorial
[Class code and header files](https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/)
to split your class into two files.
Likewise, follow the tutorial
[Header guards](https://www.learncpp.com/cpp-tutorial/header-guards/)
to include *header guards* in your
definition files (`*.h`), so that multiple inclusion of the same file is avoided.

Write a client program `complejos.cc` that operates with complex numbers using the class `Complejo` you design.
The class `Complejo` must contain at least methods that overload the addition and
subtraction operators for complex numbers, as well as the stream insertion and extraction operators.
Thus, the `main` function of the program `complejos.cc` could contain (among others) statements such as the following:

```
main() {
  Complejo complejo1{4, 5}, complejo2{7, -8};
  Complejo resultado;
  resultado = complejo1 + complejo2;
  std::cout << resultado;
  resultado = complejo1 - complejo2;
  std::cout << resultado;
}
```
Include (at your discretion) any other operations you consider appropriate as methods of the class `Complejo`.

4. Use your class `Complejo` from the previous exercise to solve the Exercism exercise
[Complex Numbers](https://exercism.org/tracks/cpp/exercises/complex-numbers).
On Exercism, the class must be named *Complex*.
You may need to make some other changes to your implementation of the
*Complejo* class.
Study the file `complex_numbers_test.cpp`, which contains the tests of that Exercism problem.

5. The Fecha class.

Write a class `Fecha` to represent and manage dates.
Add to the class the data members and methods you consider appropriate for the purpose
of this exercise.
Include a method that determines whether the year of a date is a leap
year.
Solve the Jutge problem
[Valid Dates](https://jutge.org/problems/P58459_en)
and submit it to the platform for assessment.
Based on the solution to that problem, make the constructor of the class `Fecha` accept a date only if
it is valid.

Write a client program `fechas.cc` that declares, reads and writes (screen, keyboard or files)
date objects.
