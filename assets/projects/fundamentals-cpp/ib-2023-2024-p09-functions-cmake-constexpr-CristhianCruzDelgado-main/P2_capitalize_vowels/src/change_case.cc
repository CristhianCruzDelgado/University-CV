/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File change_case.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Reads a string and converts consonants to lowercase and vowels to uppercase
  */

#include <iostream>
#include <string>

#include "conversor.h"

int main() {
  std::string string;
  std::cin >> string;
  if (std::cin.fail()) {
    std::cout << "Error: unexpected input\nExpected format: \"abcd...\" | a"
                 " string with no blank spaces\n";
    return 1;
  }
  std::cout << process_string(string) << "\n";
  return 0;
}
