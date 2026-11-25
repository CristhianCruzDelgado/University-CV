/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File crypto.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Encrypts the contents of a file
 */

#include <cerrno>
#include <cstring>
#include <expected>
#include <fstream>

#include "tools.h"

int main(int argc, char* argv[]) {
  auto result = CheckParameters(argc, argv);
  if (!result.has_value()) {
    switch (result.error()) {
      case Exit_options::no_options:
        ShowUsage();
        return EXIT_SUCCESS;
      case Exit_options::show_help:
        ShowHelp();
        return EXIT_SUCCESS;
      case Exit_options::less_args:
        std::cerr << "Error: less_args\n";
        return EXIT_FAILURE;
      case Exit_options::more_args:
        std::cerr << "Error: more args\n";
        return EXIT_FAILURE;
      case Exit_options::unknown_option:
        std::cerr << "Error: unknown_option\n";
        return EXIT_FAILURE;
    }
  }
  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);
  if (!input.is_open() || !output.is_open()) {
    std::cerr << "Error: " << errno << " in OpenFile(). " << strerror(errno)
              << "\n";
    return EXIT_FAILURE;
  }
  if (result.value().method_xor) {
    MethodXor(input, output, result.value().password);
  } else if (result.value().method_cesar) {
    MethodCesar(input, output, result.value().kvalue);
  }
  input.close();
  output.close();
  return EXIT_SUCCESS;
}
