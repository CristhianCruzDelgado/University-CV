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
 * @brief Implements reading a file and counting
 * vowels and consonants
 */

#include "tools.h"

bool IsVocal(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
             ? true
             : false;
}

std::string FindMoreVowels(std::ifstream& file) {
  std::string word;
  std::string more_vowels = "";
  int max_vowels = 0;
  while (file >> word) {
    int count_vowels = 0;
    for (char c : word) {
      if (IsVocal(c)) {
        count_vowels++;
      }
    }
    if (max_vowels < count_vowels) {
      max_vowels = count_vowels;
      more_vowels = word;
    }
  }
  return more_vowels;
}

bool IsConsonant(char c) {
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
    if (!IsVocal(c)) {
      return true;
    }
  }
  return false;
}

std::string FindMoreConsonants(std::ifstream& file) {
  std::string word;
  std::string more_consonants = "";
  int max_consonants = 0;
  while (file >> word) {
    int count_consonants = 0;
    for (char c : word) {
      if (IsConsonant(c)) {
        count_consonants++;
      }
    }
    if (max_consonants < count_consonants) {
      max_consonants = count_consonants;
      more_consonants = word;
    }
  }
  return more_consonants;
}
