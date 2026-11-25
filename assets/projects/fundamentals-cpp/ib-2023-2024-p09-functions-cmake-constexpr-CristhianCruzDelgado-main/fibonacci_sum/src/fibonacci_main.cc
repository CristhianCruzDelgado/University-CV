/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief Each new term of the Fibonacci sequence is the sum of the previous two.
 *        Starting with 0 and 1, the first 10 terms are: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
 *        Write a C++ program that computes the sum of all even-valued terms
 *        of the sequence that are less than 1000.
 * @see https://docs.google.com/document/d/1-3hTIVf8tPrbn9u0vs0Cm2IGyX1XBgv8hReVU0KOSUQ/edit?usp=sharing
 * @see stoi http://www.cplusplus.com/reference/string/stoi/
 * An Object Oriented Version of the program:
 * @see https://stackoverflow.com/questions/21360694/sum-of-even-fibonacci-numbers-under-1000
 *
 */

#include <iostream>

#include "tools.h"
#include "fibonacci_sum.h"

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string limit = argv[1];
  const size_t kLimit = stoi(limit);
  std::cout << "Sum: " << FibonacciSum(kLimit) << std::endl;
  return 0;
}
