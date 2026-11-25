/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Reduce_sum.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Computes the sum of all the components of a vector
  */

#include "Reduce_sum.h"

double ReduceSum(const std::vector<double>& vector, const int size) {
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += vector[i];
  }
  return sum;
}
