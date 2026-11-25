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
  * File serie_fibonacci.cc: client program.
  * Description: prints the first n terms of the Fibonacci sequence
  */

#include <iostream>

void fibonacci(int number) {
  int last_value = 0;
  std::cout << last_value;
  int actual_value = 1;
  for (int i = 1; i < number; i++) {
    int next_value = actual_value + last_value;
    std::cout << " " << actual_value;;
    last_value = actual_value;
    actual_value = next_value;
  }
}

int main() {
  int number;
  std::cout << "Enter a natural number\n";
  std::cin >> number;
  std::cout << "The Fibonacci sequence for that number is: \n";
  fibonacci(number);
  std::cout << "\n";
  return 0;
}
