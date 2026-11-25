/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Unsort_vector_main.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Generates a vector and shuffles it
  */

#include <vector>

#include "Generate_vector.h"
#include "Unsort_vector.h"

int main() {
  int size = ReadSize();
  double lower = ReadNumber();
  double upper = ReadNumber();
  std::vector<double> vector = GenerateVector(size, lower, upper);
  PrintVector(vector);
  UnsortVector(vector, size);
  PrintVector(vector);
  return 0;
}
