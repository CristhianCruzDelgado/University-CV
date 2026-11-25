/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 8: functions
  *
  * Author: Cristhian Adoney Cruz Delgado
  * Email: alu0101648293@ull.edu.es
  * Date: 14/11/2024
  * File random_number.cc: client program.
  * Description: reads two numbers and prints a random number in the interval they define
  */

#include <iostream>
#include <cstdlib>
#include <ctime>

int num1, num2;

void input();

void output();

int main() {
  input();
  output();
  return 0;
}

void input() {
  std::cout << "Enter two natural numbers\n";
  std::cin >> num1 >> num2;
  if (std::cin.fail() || num1 >= num2) {
    std::cout << "Error: unexpected input\nExpected format: \"m n\" "
                 "| m, n are natural numbers and m < n\n";
    std::exit(1);
  }
}

void output() {
  std::srand(std::time(nullptr));
  int random_number = num1 + std::rand() % (num2 - num1 + 1);
  std::cout << random_number << "\n";
}
