/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief This file declares the "Help Text" constant and two functions
 *
 */

#include <iostream>

const std::string kHelpText =
"The first terms of the Fibonacci sequence are: \
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... \
\n\nThis program computes the sum of all even terms of the \
Fibonacci sequence that are less than a value, \nwhich the user \
must enter on the command line when running the program";

void Usage(int argc, char *argv[]);
