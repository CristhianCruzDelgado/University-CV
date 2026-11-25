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
  * File sum_square.cc: client program.
  * Description: reads an integer n and prints the sum of the first n squares
  */

#include <iostream>

int sum_square(int);

int main() {
  int number;
  std::cin >> number;
  std::cout << sum_square(number) << std::endl;
  return 0;
}

int sum_square(int number) {
  int sum = 0;
  for (int i = 1; i <= number; i++) {
    sum += i * i;
  }
  return sum;
}
