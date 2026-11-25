/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File conversor.cc: implementation file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Converts each character of the string
  */

#include "conversor.h"

std::string Process_string(std::string string) {
  std::string new_string = "";
  for (char c : string) {
    if (c >= 'A' && c <= 'Z') {
      if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
        new_string += process_may(c);
      }	else {
        new_string += c;
      }
    } else if (c >= 'a' && c <= 'z') {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        new_string += process_min(c);
      } else {
        new_string += c;
      }
    } else {
      new_string += c;
    }
  }
  return new_string;
}

char Process_may(char character) {
  return static_cast<char>(character + CONVERSOR);
}

char Process_min(char character) {
  return static_cast<char>(character - CONVERSOR);
}
