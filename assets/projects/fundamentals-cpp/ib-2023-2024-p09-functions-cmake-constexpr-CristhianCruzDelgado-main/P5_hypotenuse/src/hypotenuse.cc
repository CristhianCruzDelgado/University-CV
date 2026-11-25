/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File hypotenuse.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Computes the hypotenuse from the two legs
  * using the Square_root() function
  */

#include <iostream>
#include "tools.h"

int main() {
  double leg1 = Read_num();
  double leg2 = Read_num();
  double before_root = Sum_squares(leg1, leg2);
  std::cout << "The hypotenuse with legs " << leg1 << " " << leg2
            << " is: " << Square_root(before_root) << "\n";
  return 0;
}
