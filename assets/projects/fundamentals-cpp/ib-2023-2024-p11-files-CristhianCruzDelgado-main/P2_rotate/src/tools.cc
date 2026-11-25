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
 * @brief: Implements the rotation of vowels
 */

#include "tools.h"

bool IsVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
          c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

char Rotate(char c) {
  switch (c) {
    case 'a':
      return 'e';
    case 'e':
      return 'i';
    case 'i':
      return 'o';
    case 'o':
      return 'u';
    case 'u':
      return 'a';
    case 'A':
      return 'E';
    case 'E':
      return 'I';
    case 'I':
      return 'O';
    case 'O':
      return 'U';
    case 'U':
      return 'A';
    default:
      return c;
  }
}
