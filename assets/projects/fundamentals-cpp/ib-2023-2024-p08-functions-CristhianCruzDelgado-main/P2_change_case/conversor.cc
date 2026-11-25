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
  * File conversor.cc: implementation file.
  * Description: converts each character of the string
  * from lowercase to uppercase or vice versa
  */

#include "conversor.h"

std::string process_string(std::string string) {
  std::string new_string = "";
  for (char character : string) {
    if (character >= 'A' && character <= 'Z') {
      new_string += process_may(character);
    }
    else if (character >= 'a' && character <= 'z') {
      new_string += process_min(character);
    } else {
      new_string += character;
    }
  }
  return new_string;
}

char process_may(char character) {
  return static_cast<char>(character + CONVERSOR);
}

char process_min(char character) {
  return static_cast<char>(character - CONVERSOR);
}
