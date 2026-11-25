/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 7: iterations
  *
  * Author: Cristhian Adoney Cruz Delgado
  * Email: alu0101648293@ull.edu.es
  * Date: 7/11/2024
  * File cero_one.cc: client program.
  * Description: reads a natural number and prints a pattern of zeros and ones
  */

#include <iostream>

void print_patron(int);

int main() {
  int number;
  std::cin >> number;
  print_patron(number);
  return 0;
}

void print_patron(int number) {
  for (int i = 0; i < number; i++) {
    std::cout << "1";
  }
}
