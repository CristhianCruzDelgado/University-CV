/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File vowels_consonants_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Counts the vowels and consonants of each word
 * and prints the words that have the most
 */

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#include "tools.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Correct usage: ./vowels_consonants PATH";
    return EXIT_FAILURE;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error: " << errno << " in ReadFile(). "
              << std::strerror(errno);
    return EXIT_FAILURE;
  }
  std::string more_vowels = FindMoreVowels(file);
  file.clear();
  file.seekg(0);
  std::string more_consonants = FindMoreConsonants(file);
  file.close();
  std::cout << "Most vowels: " << more_vowels
            << "\nMost consonants: " << more_consonants << "\n";
  return EXIT_SUCCESS;
}
