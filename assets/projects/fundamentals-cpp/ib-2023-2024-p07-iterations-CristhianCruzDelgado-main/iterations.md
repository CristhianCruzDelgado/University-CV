# Lab Assignment 07. Iterations. Git and GitHub.

# Weighting factor: 7

### Objectives
The objectives of this assignment are that students:
* Are able to solve simple problems in C++ using everything learned so far,
and in particular iterative statements
* Begin to use functions and to modularise their programs into different functions
* Study and learn the fundamentals of working with Git and GitHub

### Assessment rubric for this assignment
The most relevant aspects that will be taken into account when assessing this assignment are listed below (the list is not exhaustive).
It will be checked that students:
* Are able to write simple C++ programs that solve problems of
  similar complexity to those proposed in this assignment
* Structure their programs around different functions (modular programs)
* Have automated the compilation of their programs with a `Makefile`
  for each of the programs they develop
* Can prove that they are able to submit programs to the
[Jutge](https://jutge.org/)
platform for assessment
* Have included a prologue comment in every file (`*.cc`, `*.h`) of their exercises
* Make every program of their assignments comply with the
[Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
* Can prove that they are able to edit remote files on their VM with vi
* Show that they are able to run Linux commands on their VM

### GitHub Classroom
From now on, GitHub Classroom (a platform related to GitHub) will be used to manage the
assignments of *Informática Básica*.
On that platform, you will receive an invitation to a task for each assignment, which you must
accept.
Once you accept the invitation, you must clone with `git` a repository associated with the task.
That private repository will be the starting point, and you must add to it folders with the programs
you write.

The invitation link to the task will look similar to
`https://classroom.github.com/a/uNbth9vD`
If you open it in a browser, you will be asked to sign in to your GitHub account,
and once signed in you will be taken to a screen
[like this one](https://raw.githubusercontent.com/IB-2024-2025/P07-iterations/refs/heads/main/join.png)
where you will be asked to join the "*classroom*" IB-2024-2025.
To do so, select your email address from the list of identifiers (*Identifiers*) shown on that page.
You will then be asked to "Accept the assignment Practica-Name".
There will be one task for each assignment of the subject.

Once you have done so, a screen
[like this one](https://raw.githubusercontent.com/IB-2024-2025/P07-iterations/refs/heads/main/accepted.png)
will confirm that you have accepted the assigned task, and
when you refresh the page it will show
[another screen](https://raw.githubusercontent.com/IB-2024-2025/P07-iterations/refs/heads/main/ready.png)
with the link to the repository created
for your work on the assignment.

Through that link you will reach, on GitHub, the private repository created for you to develop
the programs of the assignment.
[The link shown in that repository](https://raw.githubusercontent.com/IB-2024-2025/P07-iterations/refs/heads/main/link.png)
(choose the SSH option for the link) is the one you must submit in the virtual classroom task for the assignment.

Remember that you must submit two items for each assignment:
* This link to your repository. You may enter it in the corresponding virtual classroom task now:
there is no need to wait for the assessment session to upload it.
* A `.tar.gz` file containing every program you develop, both before and during the assessment session.
You must wait for the assessment session to upload the .tar.gz file containing your programs.

Use that same link to make a local copy (clone) of the repository on your virtual
machine and start working on the exercises of the assignment:

```
git clone https://github.com/IB-2024-2025/P07-iterations <LocalDirectory>
```

### Complementary study material
Study everything in the section
[Comments](https://google.github.io/styleguide/cppguide.html#Comments)
of the Google Style Guide and put into practice everything it proposes.

Study the following sections of the subject's
[reference tutorial](https://www.learncpp.com/):
* [Comments](https://www.learncpp.com/cpp-tutorial/comments/)
* Chapter 2,
[Basics: Functions and Files](https://www.learncpp.com/cpp-tutorial/introduction-to-functions/)
(in full)
* [Command line arguments](https://www.learncpp.com/cpp-tutorial/command-line-arguments/)

### Program design
Remember the *Good Practices* studied for designing your functions:
* The code must be organised into different functions
* Each function must perform a single task and do it correctly
* The identifier of a function must clearly reflect what the function does

As stated in
[How to design your first programs](https://www.learncpp.com/cpp-tutorial/how-to-design-your-first-programs/),
your code should be organised around functions that are called from the *main()* function.
The usual shape of the main function of any program should therefore be similar to:
``` .cpp
int main(int argc, char* argv[]) {
  PrintProgramPurpose();
  if (!CheckCorrectParameters(argc, argv, 3)) {
    return 1;
  }
  GetUserInput();
  GetMathematicalOperation();
  GetUserInput();
  CalculateResult();
  PrintResult();

  return 0;
}
```
in the sense that *main()* merely *orchestrates* the functions that make up the program.
*main()* passes those functions the parameters they need, and the functions
return to *main()* the value they compute (where applicable).

Include in all your programs two functions declared as:
```
void PrintProgramPurpose();
bool CheckCorrectParameters(const int argc, char *argv[], const int kCorrectNumber);
```
The first one is called at the start of execution to print a message explaining
the purpose of the program.
*CheckCorrectParameters()* returns `true` if the program received the right number of
command-line parameters (3 in the previous example) and `false` otherwise.
Study the program
[check-correct-parameters.cc](https://github.com/IB-2023-2024/IB-class-code-examples/blob/master/Functions/check-correct-parameters.cc)
from the lecture code examples, which illustrates the use of these two functions.

### Exercises
* When doing the exercises, create inside your repository for this assignment a separate folder
for each exercise.
Give each folder a meaningful name.
* Automate the compilation of each exercise's program with a separate `Makefile`
for each program, and place it in the corresponding folder.

1. Write a program that reads a natural number and prints the sum of its digits.
```
Public test cases
Input           Output
2022              6
1492             16
0                 0
```

2. Write a program that prints the first N terms of the
[Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_number).
The first terms of the sequence are: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, ...
```
Public test cases
Input           Output
5                 0 1 1 2 3
9                 0 1 1 2 3 5 8 13 21
1                 0
```

3. Study in the Learn C++ tutorial the sections
[Numeral systems (decimal, binary, hexadecimal, and
octal)](https://www.learncpp.com/cpp-tutorial/numeral-systems-decimal-binary-hexadecimal-and-octal/)
and
[Converting between binary and
decimal](https://www.learncpp.com/cpp-tutorial/converting-between-binary-and-decimal/).

Write a program `binary-to-decimal.cc` that converts binary numbers to decimal.
Do not use the types `std::string`, `std::vector` or `std::array`.
If the input is not a binary number, the program must print an error message and
end its execution.
```
Public test cases
Input           Output
1111              15
1011110           94
1018110        Wrong Input
10010111         151
```

4. Write a program `decimal-to-binary.cc` that converts decimal numbers to binary.
Do not use the types `std::string`, `std::vector` or `std::array`.
```
Public test cases
Input           Output
15              1111
94              1011110
151             10010111
```

5. Write a program `leap-year.cc` that states whether a year is a
[leap year](https://en.wikipedia.org/wiki/Leap_year).
A leap year has 366 days.
After the Gregorian reform, leap years are the multiples of four that do not end in two zeros,
and also the years ending in two zeros that, after removing those two zeros, are divisible by four.
Thus 1800 and 1900, although multiples of four, were not leap years; 2000, on the other hand, was.

```
Public test cases
Input        Output
1999           NO
1968          YES
2000          YES
1800           NO
```

Bear in mind that Jutge exercises will be used in the assessment of the *Informática Básica* assignments,
so solving problems on that platform will improve your programming skills.
Complete as many exercises of the Informática Básica course on Jutge as you can.

Always remember that Jutge only assesses whether your program works correctly.
Your code must also meet the modularity, formatting and style requirements.
