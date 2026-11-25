/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File rotate_vowels_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Replaces each vowel of a file with the next vowel
 */

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "tools.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Correct usage: ./rotate_vowels PATH";
    return EXIT_FAILURE;
  }
  std::fstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error: " << errno << " in ReadFile(). "
              << std::strerror(errno);
    return EXIT_FAILURE;
  }
  std::string word;
  std::string tmp = "";
  while (file >> word) {
    for (char& c : word) {
      if (IsVowel(c)) {
        c = Rotate(c);
      }
    }
    tmp += word + " ";
  }
  file << tmp;
  file.close();
  return EXIT_SUCCESS;
}
