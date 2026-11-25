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
  * File sum_digits.cc: client program.
  * Description: reads natural numbers and prints the sum of their digits
  */

#include <iostream>

int sum(int);

int main() {
  int number;
  while (std::cin >> number) {
    std::cout << "The sum of the digits of " << number << " is " << sum(number) << ".\n";
  }
  return 0;
}

int sum(int number) {
  int sum = 0;
  while (number > 0) {
    if (number < 10) {
      sum += number;
      return sum;
    }
    sum += number % 10;
    number /= 10;
  }
  return sum;
}
