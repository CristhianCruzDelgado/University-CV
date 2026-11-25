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
 * @brief Declares the functions that
 * count the lowercase and uppercase letters of a file
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <fstream>
#include <iostream>
#include <string>

bool IsVocal(char c);

std::string FindMoreVowels(std::ifstream& file);

bool IsConsonant(char c);

std::string FindMoreConsonants(std::ifstream& file);

#endif
