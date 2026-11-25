/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File quijote_main.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Defines the functions used by quijote_main
 **/

#include "quijote.h"

void CountDulcinea(char* argv[]) {
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    return;
  }
  int count_dulcinea = 0;
  std::string word;
  while (file >> word) {
    if (word == "Dulcinea") {
      count_dulcinea++;
    }
  }
  std::cout << count_dulcinea << "\n";
  file.close();
}

void DulcineaToboso(char* argv[]) {
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    return;
  }
  std::ofstream output{"Dulcinea_del_Toboso.txt"};
  if (!output.is_open()) {
    return;
  }
  std::string word;
  while (file >> word) {
    std::string dulcinea_line;
    dulcinea_line += word + " ";
    if (dulcinea_line == "Dulcinea del Toboso") {
      dulcinea_line = "Mi señora Dulcinea del Toboso";
      output << dulcinea_line;
    } else {
      output << word;
    }
  }
  file.close();
  output.close();
}
