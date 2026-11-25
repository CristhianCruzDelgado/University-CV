# Lab Assignment 11. Files. Visual Studio Code.

# Weighting factor: 9

### Objectives
The objectives of this assignment are that students:
* Are able to solve simple problems in C++ using everything learned so far,
  and in particular functions and text files
* Design, develop and use functions in their programs, making their programs modular
* Set up and practise the use of Visual Studio Code (VSC) to edit files remotely on their VM

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

#### Visual Studio Code
An
[IDE](https://en.wikipedia.org/wiki/Integrated_development_environment)
(*integrated development environment*) is a program that provides
a programmer with various services to make program development easier.
The most common services an IDE provides are a source code editor (vi has been used so far),
a compiler (g++ will still be used), automated build tools (`make` has been used
so far) and a debugger.
Most IDEs offer intelligent code completion (IntelliSense).
IDEs provide a single program in which all development takes place.
This program (the IDE) usually offers many features for creating, modifying, compiling, deploying and debugging programs.
Some IDEs target a specific programming language, while others can
be used with several languages.

[Visual Studio Code](https://en.wikipedia.org/wiki/Visual_Studio_Code)
(VSC) is an IDE developed by Microsoft
for Windows, Linux, macOS and the web.
It includes support for debugging, built-in Git control, syntax highlighting, intelligent code completion,
snippets and
[refactoring](https://es.wikipedia.org/wiki/Refactorizaci%C3%B3n)
(changing the source code without changing its behaviour).
The IDE is customisable, so its users can change the editor theme, keyboard shortcuts and preferences.
It is free and open source and is
[one of the most widely used IDEs](https://www.geeksforgeeks.org/10-best-ide-for-web-developers-in-2022/)
today.
*Informática Básica* adopts VSC as its IDE, and it will be used in the assessment of the remaining
assignments of the subject.

To install VSC on your own Linux installation (not on your virtual machine, but on the Linux installation
you usually work from), follow
[these instructions](https://code.visualstudio.com/docs/setup/linux)
and download the `.deb` package.
Once you have downloaded the package, install it on your machine by running:
```
sudo apt install code_1.73.1-1667967334_amd64.deb
```
The command above refers to the package for version 1.73.
Make sure you use the name of the `.deb` package you downloaded.

Once the package is installed, check that you can start VSC on your machine by running in a terminal:
```
code .
```
In the command above, the dot means that you want to edit files in the current folder (`.`).
Once the program starts, exit it from the menu (*File* -> *Exit*).

Then follow the instructions on the page
[Remote Development using SSH](https://code.visualstudio.com/docs/remote/ssh)
to set up remote editing with VSC.

Of the three steps listed on that page:
1. Install an OpenSSH client
2. Install Visual Studio Code
3. Install the *Remote Development extension pack*

you only need to do the third, since (1) `ssh` is already available on both the virtual machine and your working
machine, and VSC (2) has already been installed with `apt install`.

The link
[Remote Development extension pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)
takes you to a page that shows the command to type in VSC (`Ctrl+P`) to install the
extension.

Go back to the page
[Remote Development using SSH](https://code.visualstudio.com/docs/remote/ssh)
and, in the *SSH host setup* section, follow the instructions of step 3 (optional).
To do so, go to the page
[Tips and Tricks](https://code.visualstudio.com/docs/remote/troubleshooting#_improving-security-on-multi-user-servers)
and follow the instructions for *Quick start: Using SSH keys*.

To do so, run (replacing the IP address with that of your VM):
```
$ ssh-keygen -t rsa -b 4096
$ export USER_AT_HOST=usuario@10.6.131.106
$ export PUBKEYPATH="$HOME/.ssh/id_rsa.pub"
$ ssh-copy-id -i "$PUBKEYPATH" "$USER_AT_HOST"
```
[This image](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-connect-to-host.png)
shows step 2 of the section "Connect to a remote host" of those instructions, while
[this other one](https://raw.githubusercontent.com/fsande/IB-P01-EntornoIaaS/master/img/VSC-password.png)
shows the VSC authentication window that grants it access to the virtual machine.
[This video](https://youtu.be/pAUfwae-eWg) shows how to set up remote editing of files hosted on IaaS-ULL machines with VSC.

Once it is installed on your local machine, run Microsoft Visual Studio Code (VSC) and follow
[these instructions](https://code.visualstudio.com/docs/remote/ssh)
to set up remote editing of files hosted on your virtual machine.

Then follow the instructions on the page
[C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)
to install the C/C++ extension in VSC.

You can check that the GNU `g++` compiler, which has been used so far in
*Informática Básica*, is already available.

Follow the instructions to create a subfolder named `HelloWorld` in the folder of assignment 11
and, inside that folder on the remote machine, edit the file `helloworld.cc` referred to on the previous
page.

At this point, *Informática Básica* recommends installing the
[vscodevim](https://marketplace.visualstudio.com/items?itemName=vscodevim.vim)
extension, which emulates Vim in VSC.
If you install that extension (`ext install vscodevim.vim`) in VSC, you will be able to use in VSC all the commands you already
know from `vim`, which will let you keep practising with that editor.

Visual Studio Code is installed on the computers of the ESIT Computing Centre rooms.
Before the assessment session of this assignment, students should check from one of those
computers the connection to their virtual machine for the subject, to make sure that everything works
correctly before the assessment session.

### Complementary study material
In addition to the content reviewed in the
[lecture slides](https://docs.google.com/presentation/d/1MvBmwui2ZJJXt-fWItcm_7AwJ0Vc8XyGvC7OIxAbZ7E/edit?usp=drive_link)
on Input/Output and the
[code examples](https://github.com/IB-2024-2025/IB-class-code-examples/tree/main/Functions)
for that material,
study the following sections of the subject's
[reference tutorial](https://www.learncpp.com/):
* [28.1 Input and output (I/O) streams](https://www.learncpp.com/cpp-tutorial/input-and-output-io-streams/)
* [28.2 Input with istream](https://www.learncpp.com/cpp-tutorial/input-with-istream/)
* [28.3 Output with ostream and ios](https://www.learncpp.com/cpp-tutorial/output-with-ostream-and-ios/)
* [28.6 Basic file I/O](https://www.learncpp.com/cpp-tutorial/basic-file-io/)

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

1. Write a program `vowels-and-consonants.cc` that prints the word with the most vowels and the word with the
most consonants (regardless of whether they are uppercase or lowercase) found
in a text file passed as a command-line parameter.
In case of a tie (several words with the same number of vowels/consonants), the program prints the
word that appears first in the text file.

2. Write a program `rotate.cc` that *rotates* the lowercase vowels found in the file passed
as a command-line parameter, where *rotating* means replacing
* 'a' with 'e'
* 'e' with 'i'
* 'i' with 'o'
* 'o' with 'u'
* 'u' with 'a'

So that an input file containing this text:
```
In an age when acronyms were popular, the Manchester Mark I was
sometimes referred to as MADM (Manchester Automatic Digital Machine)
or MUC (Manchester University Computer).
```
would produce this output:
```
In en egi whin ecrunyms wiri pupaler, thi Menchistir Merk I wes
sumitomis rifirrid tu es MADM (Menchistir Aatumetoc Dogotel Mechoni)
ur MUC (Menchistir Unovirsoty Cumpatir).
```

3. Write a program that reads a text file passed as a parameter and produces as output
files named `A.txt`, `B.txt`, ..., `Z.txt`.
Each of those files must contain, on separate lines, all the words of the file passed as a
parameter that start with the corresponding letter.

4. A deterministic finite automaton ([DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton))
is an abstract machine that accepts or rejects a given sequence of symbols.
Read the
[Wikipedia](https://en.wikipedia.org/wiki/Deterministic_finite_automaton)
article if you want to learn some details about this model of computation, although it is not strictly necessary
for this exercise.
Write a program `read_DFA.cc` that reads a text file `input.dfa` containing the specification of a
DFA and prints its characteristics.
DFA specification files have the following structure:
* Line 1: Total number of states of the DFA.
* Line 2: Start state of the DFA.
* Then there is one line for each state.
  Each line contains the following numbers, separated by blank spaces:
  * Identifier of the state.
  The states of the automaton are represented by unsigned integers.
  The states are numbered with the first natural numbers, starting from 0.
  * A 1 if it is an accepting state and a 0 if it is a non-accepting state.
  * Number of transitions of the state.
  * Then, for each transition, separated by blank spaces, the following information:
    * Input symbol that triggers the transition.
    * Target state of the transition.

As an example, the following would be the content of the specification file of the DFA in
[this figure](https://raw.githubusercontent.com/IB-2022-2023/P10-files/main/dfa.png)
```
4
0
0 0 2 a 1 b 3
1 1 2 a 1 b 2
2 1 2 a 1 b 3
3 0 2 a 3 b 3
```
and for this input file the program should print the following information:
```
|Q| = 4
q0 = 0
F = {1, 2}
delta(0, a) = 1
delta(0, b) = 3
delta(1, a) = 1
delta(1, b) = 2
delta(2, a) = 1
delta(2, b) = 3
delta(3, a) = 3
delta(3, b) = 3
```
That is, the first 3 lines show the cardinality of the set of states,
the start state (q0) and the set of accepting states (F).
The following lines show the value of the transition function (*delta*) for each state and symbol.

5. Read this
[introduction to cryptography](Cryptography.md)
and then write a C++ program `cripto.cc` whose purpose is to encrypt and/or decrypt text files.
If the program is run without command-line parameters, it should print the following message:
```
./cripto -- File encryption
Usage: ./cripto input_file output_file method password operation
Try ./cripto --help for more information
```

If the program is run with the `--help` option, it must print:

```
./cripto -- File encryption
Usage: ./cripto input_file output_file method password operation

input_file:      File to encode
output_file:     Encoded file
method:          Encryption method
                   1: XOR cipher
                   2: Caesar cipher
password:        Secret word for method 1, value of K for method 2
operation:       Operation to perform on the file
                   +: encrypt the file
                   -: decrypt the file
```

The program only runs when the required parameters have been passed on the command line.
If any inconsistency is detected in the parameters, the program must abort its execution.
An error message must also be shown if the program cannot open the input file.
