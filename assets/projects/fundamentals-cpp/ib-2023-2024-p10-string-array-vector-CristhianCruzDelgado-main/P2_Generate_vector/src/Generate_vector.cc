/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Generate_vector.cc: implementation file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Generates a vector of a given size with
  * random values from a given interval
  */

#include "Generate_vector.h"

int ReadSize() {
  std::cout << "Enter the size of your vector\n";
  int size;
  std::cin >> size;
  if (std::cin.fail() || size < 0) {
    std::cerr << "Error: invalid input\nExpected format: x"
                 " | x is a positive integer\n";
    exit(EXIT_FAILURE);
  }
  return size;
}

double ReadNumber() {
  std::cout << "Enter a bound of your interval\n";
  double number;
  std::cin >> number;
  if (std::cin.fail()) {
    std::cerr << "Error: invalid input\nExpected format: x.x\n";
    exit(EXIT_FAILURE);
  }
  return number;
}

double GenerateRandom(const double num1, const double num2) {
  std::random_device xxx;
  std::mt19937 generate(xxx());
  std::uniform_real_distribution<double> distribution(num1, num2);
  double random_number = distribution(generate);
  return random_number;
}

std::vector<double> GenerateVector(const int size, const double lower,
                                   const double upper) {
  if (lower > upper) {
    exit(EXIT_FAILURE);
  }
  std::cout << "Generating vector...\n";
  std::vector<double> v(size);
  for (int i = 0; i < size; i++) {
    v[i] = GenerateRandom(lower, upper);
  }
  return v;
}
