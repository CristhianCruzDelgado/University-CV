/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 8: functions
  * File print_line.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 14/11/2024
  * @brief: Prints a line with s spaces followed by n repetitions
  * of the character c
  */

#include <iostream>

void print(int spaces, char symbol, int reps) {
  for (int i = 0; i < spaces; i++) {
    std::cout << " ";
  }
  for (int i = 0; i < reps; i++) {
    std::cout << symbol;
  }
  std::cout << "\n";
}
