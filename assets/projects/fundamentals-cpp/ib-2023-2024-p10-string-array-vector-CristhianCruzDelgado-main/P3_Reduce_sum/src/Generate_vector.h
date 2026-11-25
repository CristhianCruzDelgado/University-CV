/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Generate_vector.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Declares the functions that generate a vector
  * of a given size with random values from a given interval
  */

#ifndef GENERATE_VECTOR_H_
#define GENERATE_VECTOR_H_

#include <iostream>
#include <random>
#include <vector>

int ReadSize();

double ReadNumber();

double GenerateRandom(const double, const double);

std::vector<double> GenerateVector(const int, const double, const double);

#endif
