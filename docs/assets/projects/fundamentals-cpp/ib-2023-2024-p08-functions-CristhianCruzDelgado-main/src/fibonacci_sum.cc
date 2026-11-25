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
#include <cstdlib>    // exit

#include "fibonacci_sum.h"

/** Shows the correct usage of the program.
 *  If the usage is incorrect, prints the message and ends
 *  the execution of the program.
 *  The program requires a single natural number to run.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << argv[0] << ": A natural number is required as a parameter" << std::endl;
    std::cout << "Try " << argv[0] << " --help for more information" << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parameter{argv[1]};
  if (parameter == "--help") {
    const std::string kHelpText = "This program computes the sum of all even terms of the \
Fibonacci sequence that are less than a value, which the user \
must enter on the command line when running the program";
    std::cout << kHelpText << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/** Returns the sum of all even-valued terms of the Fibonacci
 *  sequence that are less than kLimit
 *
 *  @param[in] kLimit. The even terms less than kLimit are added
 *  @return The sum of the even terms less than kLimit
 */
size_t FibonacciSum(const size_t kLimit) {
  size_t second_to_last{0},  // Second to last term
           last{1},          // Last term generated
           new_term;         // New term of the serie
  size_t long sum{0};        // Accumulated sum of the terms

  do {
    new_term = last + second_to_last;
    if (new_term % 2 == 0) {
      sum += new_term;
    }
    // Uncomment for debug: print each new term
    // std::cout << "Term: " << new_term << std::endl;
    second_to_last = last;
    last = new_term;
  } while (new_term < kLimit);
  return sum;
}
