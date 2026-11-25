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
  * File leap_year.cc: client program.
  * Description: states whether the given year is a leap year
  */

#include <iostream>

bool is_leap_year(int);

int main() {
  std::cout << "Enter a natural number\n";
  int year;
  std::cin >> year;
  if (year < 0) {
    std::cerr << "Error: the input is not a natural number\n";
                 "Try numbers greater than zero\n";
    return 2;
  }
  if (is_leap_year(year)) {
    std::cout << "The year IS a leap year\n";
  } else {
    std::cout << "The year is NOT a leap year\n";
  }
  return 0;
}

bool is_leap_year(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
