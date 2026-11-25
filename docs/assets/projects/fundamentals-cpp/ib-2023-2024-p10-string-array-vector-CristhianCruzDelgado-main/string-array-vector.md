# Lab Assignment 10. `std::string`, `std::array`, `std::vector`. Test-Driven Development. Exercism.

# Weighting factor: 8

### Objectives
The objectives of this assignment are that students:
* Are able to solve simple problems in C++ using everything learned so far, in particular functions and objects of the classes `std::string`, `std::array` and `std::vector`
* Design, develop and use functions in their programs, making their programs modular
* Know the fundamentals of test-driven development and unit testing
* Know the Exercism platform and are able to interact with it to solve problems

### Assessment rubric for this assignment
The most relevant aspects that will be taken into account when assessing this assignment are listed below (the list is not exhaustive).
It will be checked that students:
* Know the concepts presented in the reference material of this assignment
* Have completed all the exercises proposed in this statement
* Are able to write simple C++ programs that solve problems of similar complexity to those proposed in this document
* Know the Exercism platform and are able to download and solve simple problems by interacting with it
* Are able to write a `CMakeLists.txt` file to automate the compilation of their programs with `cmake` and `make`
* Have automated the compilation of their programs with a `Makefile` for each of the programs they develop
* Structure their programs around different functions (modular programs)
* Organise all their programs in a separate folder for each "project", each one containing a `CMakeLists.txt` file with the build configuration of the project
* Use appropriate comments in the format required by [Doxygen](https://www.doxygen.nl/index.html) in all their programs
* Can prove that all the assignments completed so far are hosted in private [GitHub](https://github.com/) repositories.
* Can prove that they are able to submit programs to the [Jutge](https://jutge.org/) platform for assessment
* Have included a prologue comment in every file (`*.cc`, `*.h`) of their exercises
* Make every program they develop print, before running, a message stating the purpose of the program and the information it will need from the user to run correctly
* Make every program submitted for assessment comply with the standards defined in the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* Always use meaningful identifiers in their programs (for constants, variables, etc.) and never use single-letter identifiers, except perhaps for loop variables
* Can prove that they are able to edit remote files on their VM with Vi
* Have completed all their exercises on the subject's Ubuntu virtual machine.
* Show that they are able to run Linux commands on their VM

### Test-driven development
As described in [Wikipedia](https://es.wikipedia.org/wiki/Desarrollo_guiado_por_pruebas), test-driven development (TDD) is a software engineering practice that involves two techniques:
- Writing the tests first (Test First Development), usually with unit tests.
- [Refactoring](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n),
or restructuring the code.

TDD is based on repeating a very short development cycle of three steps:
1. First, a test case is written that defines a desired improvement (usually a new function or method); since this improvement does not exist yet, the test is expected to fail
2. Next, the code (of the function) is written so that the test passes
3. Finally, the new code is refactored (rewritten, improved), always checking that the test still passes

The purpose of test-driven development is to achieve clean code that works correctly. The idea is that the requirements are translated into tests, so that when the tests pass, the software is guaranteed to meet the established requirements.

The code "units" that are usually tested are classes, functions or groups of them. Suppose, for example, that a function (code unit) is being implemented that computes the sum of two integers. A test (unit test) is code that validates the correctness of that function. It could check:
- that the function actually receives two parameters
- that those two parameters are numbers
- that the function returns another number
- that this number actually equals the sum

All of these could be unit tests run on the function. Unit tests are usually run with specialised testing frameworks.

There are several frameworks for writing unit tests in C++.
Some of the most widely used are [Boost.Test](https://www.boost.org/doc/libs/1_49_0/libs/test/doc/html/index.html), [CppUnit](https://sourceforge.net/projects/cppunit/), [Cute](https://cute-test.com/) and [Catch2](https://github.com/catchorg/Catch2), although there are [many others](https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C++)

The tests available in Jutge for each problem are just a primitive version of the tests a program or function must pass to be considered correct. With one of these frameworks, the tests become part of the development of the program as a set of checks that each program or function must pass.

Plenty of documentation on TDD can be found on the web. As an example and introduction, the article "[Improving code quality with unit testing](https://www.mql5.com/es/articles/1579)" is recommended.

### Exercism
[Exercism](https://exercism.io/) is a platform for learning to program or for improving the skills of any programmer. Its goal is to serve as a means of learning a given language by solving exercises posed by other users. The aim is for both the person solving the problem and the person who posed it to learn at the same time. In addition, interaction with the rest of the community can lead to discussions about the best solution to a given problem.

The platform is based on a command-line application available for several operating systems (Linux, Mac, Windows). With that application, users can download programming exercises available on Exercism and write the corresponding programs until they pass the tests supplied with each exercise.

The platform can be used in "practice mode", in which there is no mentoring option (asking an expert to help you with your exercises), but it is still worth practising the many exercises available on the platform.

#### Getting started with Exercism
Start by [signing up for Exercism](https://exercism.io/users/sign_up). If you wish, you can use your existing GitHub account. Once you have an account, set up its basic settings and choose a "track" (a language) to practise. Obviously, you are advised to choose the C++ track.

When you do so, the platform will ask whether you want to work in the online editor or on your local machine. If you choose the second option, it will explain how to work with the platform on your local machine. To install Exercism on your virtual machine, run the following command:
```
$ sudo snap install exercism
```
[`snap`](https://blogubuntu.com/que-es-ubuntu-snap) is an alternative to the familiar `apt-get install` for installing applications on Ubuntu Linux. To learn more about `snap`, see [this reference](https://snapcraft.io/docs/getting-started), although it is not needed for this assignment. To check that the installation is correct, use the command
```
$ exercism version
```
Once the `exercism` application is installed, the next step is to configure its command-line interface (CLI). To do so, copy your personal *token*, which you will find in the [API/CLI](https://exercism.org/settings/api_cli) section of your account settings page. For example, if your token were `xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx`, you would run
```
$ exercism configure --token=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
```
Once run, this command prints
```
You have configured the Exercism command-line client:

Config dir:                       /home/usuario/snap/exercism/5/.config/exercism
Token:         (-t, --token)      xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
Workspace:     (-w, --workspace)  /home/usuario/snap/exercism/5/exercism
API Base URL:  (-a, --api)        https://api.exercism.io/v1
```
You can now choose a problem to solve. The ["Hello World"](https://exercism.org/tracks/cpp/exercises/hello-world) problem is suggested. Each problem page includes a precise description and a link,
"[Learn more about solving exercises locally](https://exercism.org/docs/using/solving-exercises/working-locally)", with instructions to:
* Download the problem with the command
```exercism download --track=cpp --exercise=xxxx```
This command is always shown next to the statement of the problem to solve
* Solve the problem with the editor of your choice (Vim is recommended).
* Submit your proposed solution with the command `exercism submit`

When the command to download the problem is run, the system responds:
```
$ exercism download --track=cpp --exercise=hello-world

Downloaded to
/home/usuario/snap/exercism/5/exercism/cpp/hello-world
```
indicating the folder where it has placed the code needed to work on that problem. If you look at the downloaded files, you will see that Exercism uses `.cpp` as the extension for C++ source files, instead of the `.cc` extension used in *Informática Básica*. The `.cpp` extension is very common for C++ source files.

#### Running the tests for a problem
The next step is to edit the program (for the *"Hello World"* problem, the file to edit is `hello_world.cpp`). Edit that file until you consider it has a working version. Once your program is finished, the next step is to pass the code's tests. Every Exercism exercise comes with a set of tests that the program must pass to be considered valid.

As explained on the page [Running the Tests](https://exercism.io/tracks/cpp/tests), each problem comes with its unit tests and a `CMakeLists.txt` file used to automate the compilation of the tests and the program itself. Note that you must **not** modify the `CMakeLists.txt` file.

As stated on that page, and assuming your exercise is called `bob`, the files `bob.cpp` and `bob.h` must exist before running the tests. Those files may be empty, but they must exist. For the `hello-world` exercise, the files are `hello_world.cpp` and `hello_world.h`

The next step is to compile the program and the unit tests. To do so, go to the exercise folder (`/home/usuario/snap/exercism/5/exercism/cpp/hello-world`) and run:
```sh
$ touch hello_world.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make
```
The [touch](https://ss64.com/bash/touch.html) command updates the timestamp of the file or files passed as arguments. The `build` folder created will hold, among other files, an executable program that runs the tests on your code. Exercism uses `cmake`, so you must install that application on your VM if it is not installed (`sudo apt install cmake`).

Running `cmake -G "Unix Makefiles" ..` makes CMake create a `Makefile` that you will use to compile your exercise. Running `make` in the `build` folder compiles the tests your program must pass. If there are compilation errors, you must fix them in your exercise folder (the parent folder of `build`). Once the errors are fixed, `make` builds and runs the tests available for the exercise.

Each problem usually comes with a set of tests whose code is in a file whose name ends in `_test` (`hello_world_test.cpp` for the "Hello World" exercise). The strategy for improving your exercise step by step is to make your code pass the tests in that file one after another. To do so, simply "move" the line
```
#if defined(EXERCISM_RUN_ALL_TESTS)
```
(if it exists) so that it sits after the next test you want to run. The testing framework used by Exercism is [Catch2](https://github.com/catchorg/Catch2), and tests in Catch2 format are easy to understand.

When your solution passes all the tests, you can submit it to the
platform. To do so, use the `exercism submit` command found in the `HELP.md` file included with the problem files. Once you have submitted your solution to Exercism, you will receive a message similar to this one:
```
Your solution has been submitted successfully.
You can complete the exercise and unlock the next core exercise at:

https://exercism.io/my/solutions/xxxx
```
From this point on, you can see the solutions other users have given to the same problem, or move on to other problems in the same "track". Start with the problems labelled as easy (*Easy*).

#### The leap year problem
We will now solve the Exercism problem [Leap](https://exercism.org/tracks/cpp/exercises/leap).

First, if you have not done so yet, solve the Jutge problem [P61634 Leap Years](https://jutge.org/problems/P61634_en). Base it on a boolean function `IsLeapYear(const int year)` that determines whether the year passed as a parameter is a leap year. Confirm that your program passes all the public tests before submitting it to [Jutge](https://jutge.org/) and obtaining an AC verdict.

Next, download the Exercism problem [Leap](https://exercism.org/tracks/cpp/exercises/leap):
```
exercism download --track=cpp --exercise=leap
```
The program is downloaded to the folder `~/snap/exercism/5/exercism/cpp/leap`. Remember that you must copy every Exercism exercise you solve to the working folder of this assignment:
```sh
cd ~/practicas/practica09-string-array-vector
mkdir Exercism-Leap
cd Exercism-Leap
cp -R ~/snap/exercism/5/exercism/cpp/leap/* .
```
If you inspect the file `leap_test.cpp`, you will see that it contains several tests (unit tests) such as the following:
```cpp
 8 TEST_CASE("not_divisible_by_4")
 9 {
10     REQUIRE(!leap::is_leap_year(2015));
11 }
```
Your program must pass all these tests. Line 8 simply gives the test an (arbitrary) name. Line 10 states that the function `is_leap_year()` of the namespace `leap` is required to return `false`. Note that the function is called through the namespace in which it is defined:
```cpp
leap::is_leap_year(2015);
```
The `REQUIRE` clause is specific to the [Catch2](https://github.com/catchorg/Catch2) testing framework used by Exercism, and its meaning is obvious: its argument `!leap::is_leap_year(2015)` is **required** to be true or, in other words, the function must return `false` when passed the year 2015 as a parameter.

This inspection shows that the tests use a function named `is_leap_year()`, which takes an integer parameter for the year to evaluate. The tests check that the function returns `true` for the years 1996 and 2000 and `false` for the years 2015, 1970, 2100 and 1800. Therefore, a function with the following prototype must be designed:
```cpp
bool is_leap_year(const int year);
```
Include the prototype (declaration) of the function in the file `leap.h`, whose content would be:
```cpp
#if !defined(LEAP_H)
#define LEAP_H

namespace leap {
  bool is_leap_year(const int year);
}  // namespace leap

#endif // LEAP_H
```
Note that the prototype is included in the namespace `leap`. Note also that Exercism does not follow the Google Style Guide rule for function identifiers either.

Then include the definition of your function `is_leap_year` in the namespace `leap` of the file `leap.cpp`. For this function you can use the code of the function `IsLeapYear()` you already wrote for Jutge.

Once your code is complete, correctly written and documented (remember to include Doxygen comments with JSDoc tags in every function you write, as well as header comments in all your files), compile the program. To do so, use `cmake` with the `CMakeLists.txt` file supplied by Exercism:
```sh
$ cd ~/practicas/practica09-string-array-vector/Exercism-Leap/
$ mkdir build
$ cd build
$ cmake ..
$ make
```
Running `make` runs the first test, and the system prints:
```
~/practicas/practica09-string-array-vector/Exercism-Leap/build$ make
Scanning dependencies of target leap
[ 25%] Building CXX object CMakeFiles/leap.dir/leap_test.cpp.o
[ 50%] Building CXX object CMakeFiles/leap.dir/leap.cpp.o
[ 75%] Building CXX object CMakeFiles/leap.dir/test/tests-main.cpp.o
[100%] Linking CXX executable leap
[100%] Built target leap
Scanning dependencies of target test_leap
===============================================================================
All tests passed (1 assertion in 1 test case)

[100%] Built target test_leap
```
which shows that your code has passed the first test.

Since the function has already been tested on Jutge, we can try to pass all the tests available for this problem. To do so, edit the file `leap_test.cpp` and move the line with the directive `#if defined(EXERCISM_RUN_ALL_TESTS)` to the line immediately before the `#endif` directive. The system will then run all the tests required by Exercism (6 in this case) for this problem. Go back to the `build` folder and run `make` again.

Once your solution passes all the tests, you can delete the `build` folder and submit your solution to Exercism. The command to do so is in the `HELP.md` file:
```sh
$ rm -rf build
$ exercism submit leap.cpp leap.h
```
You can then view your solution in a browser.

### Complementary study material
Review in the [lecture slides](https://docs.google.com/presentation/d/1uZd_yEuvZzTnjyhCWFQjI_llZfuJ3QJQJslt3qU7lfo/edit?usp=drive_link) and their example programs all the content related to objects of type `std::string`, `std::array` and `std::vector`

Also review in the [lecture slides](https://docs.google.com/presentation/d/11kYDk2awyZNBv2TkevEeOZHsITP5ah1F4sF9QtMkf-M/edit?usp=drive_link) all the content related to passing parameters to functions.

Study in [cppreference](https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution) how to use a uniform distribution of real (floating-point) numbers.

Study the following sections of the subject's [reference tutorial](https://www.learncpp.com/):
* [7.18 — Introduction to random number generation](https://www.learncpp.com/cpp-tutorial/introduction-to-random-number-generation/)
* [4.17 — Introduction to std::string](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/)
* [4.18 — Introduction to std::string_view](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring_view/)
* [11.16 — An introduction to std::array](https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdarray/)
* [11.17 — An introduction to std::vector](https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdvector/)
* [11.13 — For-each loops](https://www.learncpp.com/cpp-tutorial/for-each-loops/)

### Exercises
* When doing the exercises, create inside your repository for this assignment a separate folder for each exercise. Give each folder a meaningful name
* Automate the compilation of each exercise's program with a separate `Makefile` for each program, and place it in the corresponding folder
* Make every program take its input from the command line and, if it is run without the right number of parameters, print a message stating the correct way to run the program
* The code of each program must be modular, that is, it must use functions
* Each function must perform a single task and do it correctly
* The identifier of a function must clearly reflect what the function does

1. Solve as many problems as you can on the Exercism platform. This will help you improve your programming skills. For the assessment of this assignment, apart from the "Hello World!" problem and others mentioned in this document, you will be asked to present the solution to one additional Exercism problem labelled as easy (*Easy*).

2. Write a program that includes a function whose prototype is:
```cpp
std::vector<double> GenerateVector(const int size, const double lower, const double upper);
```
This function must generate and return a vector of `size` components (vector elements), initialised with values generated randomly in the interval `(lower, upper)`. The lower and upper bounds of that interval are passed as parameters to `GenerateVector()`. Once you have written that function, you could call it as follows (for example):
```cpp
std::vector<double> my_vector = GenerateVector(30, 5.0, 10.0);
for (const auto& value: my_vector) {
  std::cout << "Component: " << value << std::endl;
}
```
The call above initialises the vector `my_vector` with 30 components of type `double`, whose values are generated randomly in the range `(5.0, 10.0)`. The loop then prints the values (components) stored in that vector.

3. Write a program that includes a function `ReduceSum` that takes as a parameter a vector of floating-point numbers and returns the sum of all the values stored in the vector.

Use the function `GenerateVector()` to generate vectors and test `ReduceSum`.
```
Public test cases
Input           Output
1.0 1.0 1.0      3.0
1 2 3 4 5 6     21.0
0 0 0 0 1 0 1    2.0
```

4. Write a program that includes a function that takes a vector as a parameter and computes the maximum, minimum and average of all the values stored in the vector.

Since a function can only return a single value, you will need to find a mechanism that allows the function to return those three values (maximum, minimum and average). One possible solution would be to write three different functions, one for each calculation, but that would be inefficient because it would require traversing the vector three times, when the problem can be solved by traversing it only once.

Find out how to solve the problem by passing parameters by reference, so that the function can *"export"* the three values it computes. Use the function `GenerateVector()` to generate vectors and test your function.

5. A simple way to generate a random integer in any range is the function [`std::rand`](https://en.cppreference.com/w/cpp/numeric/random/rand) of the `cstdlib` library, which returns a pseudo-random integer in the range [0, `RAND_MAX`]. `RAND_MAX` is a constant whose value depends on the compiler version, but it is guaranteed to be at least 32767.

To fit the value returned by `std::rand` to the desired interval, the *modulo* operation (`%`) can be used. For example, to obtain a random value in the interval `a,b` (`a` included, `b` excluded), you could compute
```
a + std::rand() % (b - a)
```
Write a program that includes a function (returning nothing) that takes a vector as a parameter and shuffles it. To do so, traverse the vector and swap each of its elements with a random position within it.

If you notice that your program always shows the same permutation of the vector, study the function [`std::srand`](https://en.cppreference.com/w/cpp/numeric/random/srand), which changes the *seed* of the C++ random number generator.
