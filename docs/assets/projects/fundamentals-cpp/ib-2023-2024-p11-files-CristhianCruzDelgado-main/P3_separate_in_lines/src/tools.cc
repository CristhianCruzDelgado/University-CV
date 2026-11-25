/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File tools.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief: Implements splitting a file into
 * lines
 */

#include "tools.h"

void SeparateLines(std::ifstream& input_file) {
  std::string line;
  char character = 'A';
  while (std::getline(input_file, line)) {
    std::string name_file = character + ".txt";
    std::ofstream line_file(name_file);
    line_file << line;
    if (character == 'Z') {
      break;
    }
    character++;
  }
}
