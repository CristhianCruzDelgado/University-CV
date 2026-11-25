/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File approximate_root.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Computes the square root of a number
  * entered by the user
  */

#include <iostream>
#include "tools.h"

int main() {
  double number = Read_num();
  if (number == -1.0) {
    return -1;
  }
  std::cout << "The square root of " << number << " is: "
            << Square_root(number) << "\n";
  return 0;
}
