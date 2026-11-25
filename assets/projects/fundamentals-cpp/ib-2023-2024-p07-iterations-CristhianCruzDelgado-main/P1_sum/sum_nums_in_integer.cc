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
  * File sum_nums_in_integer.cc: client program.
  * Description: reads a natural number and prints the sum of its digits
  */

#include <iostream>

int size(int);

int sum(int, int);

int main() {
  int number;
  std::cout << "Enter an integer\n";
  std::cin >> number;
  int numbers_in_number = size(number);
  std::cout << "The sum of its digits is: " << sum(number, numbers_in_number) << "\n";
  return 0;
}

int size(int number) {
  int numbers_in_number = 1;
  while (number > 9) {
    number /= 10;
    numbers_in_number++;
  }
  return numbers_in_number;
}

int sum(int number, int size) {
  if (size == 1) {
    return number;
  }
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (number < 10) {
      sum += number;
      return sum;
    }
    sum += number % 10;
    number /= 10;
  }
  return sum;
}
