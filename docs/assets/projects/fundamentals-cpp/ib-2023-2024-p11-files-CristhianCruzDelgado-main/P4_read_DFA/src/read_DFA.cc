/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File read_DFA.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Reads a DFA and prints it
 */

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>

#include "DFA.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Correct usage: ./read_DFA PATH\n";
    return EXIT_FAILURE;
  }
  std::ifstream input_file(argv[1]);
  if (!input_file.is_open()) {
    std::cerr << "Error: " << errno << " in OpenFile(). "
              << std::strerror(errno) << "\n";
    return EXIT_FAILURE;
  }
  DFA automata;
  input_file >> automata;
  std::cout << automata;
  input_file.close();
}
