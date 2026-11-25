/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions, CMake and constexpr
  * File scalar_product.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Reads two vectors and computes their scalar product
  */

#include <cstdlib>
#include <iostream>
#include <vector>

// declarations...

int Read_size();

std::vector<int> Read_vector(int);

int Scalar_product(const std::vector<int>&, const std::vector<int>&, const int);

int main() {
  std::cout << "Enter the length of both vectors\n";
  int size = Read_size();
  std::cout << "Enter two vectors of the same length "
               "to compute their scalar product\n";
  std::vector<int> vector1 = Read_vector(size);
  std::vector<int> vector2 = Read_vector(size);
  int result = Scalar_product(vector1, vector2, size);
  std::cout << "The scalar product of the given"
               " vectors is: " << result << "\n";
  return 0;
}

// implementations ...

int Read_size() {
  int size;
  std::cin >> size;
  if (std::cin.fail() || size < 1) {
    std::cerr << "Error: invalid input\nExpected format:\n"
                 "x | x is a natural number greater than zero\n";
    exit(EXIT_FAILURE);
  }
  return size;
}

std::vector<int> Read_vector(int size) {
  std::cout << "Enter " << size << " numbers\n";
  std::vector<int> vector(size);
  for (int i = 0; i < size; i++) {
    int num;
    std::cin >> num;
    if (std::cin.fail()) {
      std::cerr << "Error: invalid input\nExpected format:\nx\ny\nz\n...\n"
                << size << "times\n";
      exit(EXIT_FAILURE);
    }
    vector[i] = num;
  }
  return vector;
}

int Scalar_product(const std::vector<int>& vector1,
                   const std::vector<int>& vector2,
                   const int size) {
  int product = 0;
  for (int i = 0; i < size; i++) {
    product += vector1[i] * vector2[i];
  }
  return product;
}
