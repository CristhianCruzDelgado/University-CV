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
#include "fibonacci_sum.h"

/** Returns the sum of all even-valued terms of the Fibonacci
 *  sequence that are less than kLimit
 *
 *  @param[in] kLimit. The even terms less than kLimit are added
 *  @return The sum of the even terms less than kLimit
 */
size_t FibonacciSum(const size_t kLimit) {
  size_t second_to_last{0},  // Second to last term
           last{1},          // Last term generated
           new_term{0};      // New term of the serie
  size_t sum{0};        // Accumulated sum of the terms

  while (new_term < kLimit) {
    new_term = last + second_to_last;
    if ((new_term % 2 == 0) && (new_term < kLimit)) {
      sum += new_term;
    }
    // Uncomment for debug: print each new term
    // std::cout << "Term: " << new_term << std::endl;
    second_to_last = last;
    last = new_term;
  }

  return sum;
}
