/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Calculate_max_min_avg.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Computes the maximum, minimum and average values
  * of a vector
  */

#include "Calculate_max_min_avg.h"

void CalculateMaximumMinimumAverage(const std::vector<double>& vector,
                                    const int size, double& maximum,
                                    double& minimum, double& average) {
  maximum = vector[0];
  minimum = vector[0];
  average = 0.0;
  double sum = 0.0;
  for (int i = 0; i < size; i++) {
    if (vector[i] > maximum) {
      maximum = vector[i];
    }
    if (vector[i] < minimum) {
      minimum = vector[i];
    }
    sum += vector[i];
  }
  average = sum / size;
}

void PrintValues(double& maximum, double& minimum, double& average) {
  std::cout << "Values computed for the vector: maximum = " << maximum
            << ", minimum = " << minimum << " and average = " << average
            << "\n";
}
