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
 * @brief Declares the function that splits a file into lines
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <fstream>
#include <string>

void SeparateLines(std::ifstream& input_file);

#endif
