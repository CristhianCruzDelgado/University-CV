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
  * File change_case.cc: client program.
  * Description: reads a string and converts uppercase letters to lowercase and vice versa
  */

#include <iostream>
#include <string>

#include "conversor.h"

int main() {
  std::string string;
  std::cin >> string;
  if (std::cin.fail()) {
    std::cout << "Error: unexpected input\nExpected format: \"abcd...\""
                 "| a string with no blank spaces\n";
    return 1;
  }
  std::cout << process_string(string) << "\n";
  return 0;
}
