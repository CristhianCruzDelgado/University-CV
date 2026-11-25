/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File quijote_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Shows the index of Don Quixote
 */

#include <fstream>
#include <iostream>

#include "quijote.h"

int main(int argc, char* argv[]) {
  if (argc == 2) {
    return -1;
  }
  CountDulcinea(argv[1]);
  DulcineaToboso(argv[1]);
  file.close();
  return 0;
}
