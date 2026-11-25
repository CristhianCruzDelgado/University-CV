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
 * @brief: Implements the encryption of a file
 */

#include "tools.h"

Program_options operation = {false, false, "", 0};

std::expected<Program_options, Exit_options> CheckParameters(int argc,
                                                             char* argv[]) {
  if (argc == 1) {
    return std::unexpected(Exit_options::no_options);
  }
  if (std::string(argv[1]) == "--help") {
    return std::unexpected(Exit_options::show_help);
  }
  if (argc < 6) {
    return std::unexpected(Exit_options::less_args);
  }
  if (argc > 6) {
    return std::unexpected(Exit_options::more_args);
  }
  if (std::string(argv[3]) == "xor") {
    operation.password = std::string(argv[4]);
    operation.method_xor = true;
  } else if (std::string(argv[3]) == "cesar") {
    operation.kvalue = std::stoi(std::string(argv[4]));
    operation.method_cesar = true;
  } else {
    return std::unexpected(Exit_options::unknown_option);
  }
  if (std::string(argv[5]) == "encrypt") {
  } else if (std::string(argv[5]) == "decrypt") {
    operation.kvalue = -operation.kvalue;
  } else {
    return std::unexpected(Exit_options::unknown_option);
  }
  return operation;
}

void ShowUsage() {
  std::cout << "File encryption.\n"
               "Usage: ./cripto INPUT OUTPUT [ xor | cesar ] "
               "[ PASSWORD | VALUE ] [ encrypt | decrypt ]\n"
               "Try ./cripto --help for more information.\n ";
}

void ShowHelp() {
  std::cout << "File encryption.\n"
               "Usage: ./cripto INPUT OUTPUT [ xor | cesar ] "
               "[ PASSWORD | VALUE ] [ encrypt | decrypt ]\n\n"
               "input_file:      File to encode.\n"
               "output_file:     Encoded file.\n"
               "method:          Encryption method.\n"
               "                 1: XOR cipher.\n"
               "                 2: Caesar cipher.\n"
               "password:\n"
               "                 Secret word for method 1.\n"
               "                 Value of K for method 2.\n"
               "operation:       Operation to perform on the file.\n"
               "                 +: Encrypt the file.\n"
               "                 -: Decrypt the file.\n ";
}

void MethodXor(std::ifstream& input_file, std::ofstream& output_file,
               const std::string& password) {
  std::string line;
  size_t position = 0;
  size_t size = password.size();
  while (std::getline(input_file, line)) {
    for (char& c : line) {
      c ^= static_cast<char>(password[position] ^ 128);
      position = (position + 1) % size;
    }
    output_file << line << "\n";
  }
}

void MethodCesar(std::ifstream& input_file, std::ofstream& output_file,
                 const int kvalue) {
  std::string line;
  while (std::getline(input_file, line)) {
    for (char& c : line) {
      c += static_cast<char>(kvalue);
    }
    output_file << line << "\n";
  }
}
