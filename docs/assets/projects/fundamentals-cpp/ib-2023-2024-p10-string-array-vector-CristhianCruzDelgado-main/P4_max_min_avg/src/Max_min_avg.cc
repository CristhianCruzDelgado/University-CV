/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File xxx.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Calls the functions needed to
  * generate a vector within an interval and computes its maximum, minimum
  * and average
  */

#include <iostream>
#include <vector>

#include "Generate_vector.h"
#include "Calculate_max_min_avg.h"

int main() {
  int size = ReadSize();
  double lower = ReadNumber();
  double upper = ReadNumber();
  std::vector<double> vector = GenerateVector(size, lower, upper);
  for (const auto& value : vector) {
    std::cout << "Component: " << value << "\n";
  }
  double maximum, minimum, average;
  CalculateMaximumMinimumAverage(vector, size, maximum, minimum, average);
  PrintValues(maximum, minimum, average);
  return 0;
}
