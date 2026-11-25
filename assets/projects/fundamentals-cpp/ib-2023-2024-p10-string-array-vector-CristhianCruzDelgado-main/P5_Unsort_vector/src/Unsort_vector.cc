/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Unsort_vector.cc: implementation file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Shuffles a vector
  */

#include "Unsort_vector.h"

void UnsortVector(std::vector<double>& vector, const int size) {
  std::cout << "Shuffling vector...\n";
  std::srand(std::time(nullptr));
  for (int i = 0; i < size; i++) {
    int random_position = i + std::rand() % (size - i);
    std::swap(vector[i], vector[random_position]);
  }
}

void PrintVector(const std::vector<double>& vector) {
  for (const auto& value : vector) {
    std::cout << "Component: " << value << "\n";
  }
}
