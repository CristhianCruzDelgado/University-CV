/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File tools.h: header file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Declares the functions that encrypt a file
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <expected>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

enum class Exit_options {
  no_options,
  show_help,
  less_args,
  more_args,
  unknown_option
};

struct Program_options {
  bool method_xor;
  bool method_cesar;
  std::string password;
  int kvalue;
};

std::expected<Program_options, Exit_options> CheckParameters(int, char* argv[]);

void ShowUsage();

void ShowHelp();

void MethodXor(std::ifstream&, std::ofstream&, const std::string&);

void MethodCesar(std::ifstream&, std::ofstream&, const int);

#endif
