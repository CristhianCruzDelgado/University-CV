/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File complex_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Reads complex numbers, adds them, subtracts them and
 * shows them
 */

#include <iostream>

#include "complex.h"

int main() {
  Complex number{1, 1}, other{2, 2};
  Complex result;
  result = number + other;
  std::cout << result;
  result = number - other;
  std::cout << result;
  return 0;
}
