/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File polynomial.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Reads a vector, interpreted as a polynomial,
  * and evaluates it at a value read from the input
  */

#include <iostream>

// declarations...
int Read_size();

std::vector<int> Read_vector(int);

int Read_value();

int Resolve_polynomial(const std::vector<int>&, const int);

int main() {
  std::cout << "Enter the degree of your polynomial\n"
  int degree = Read_size();
  std::cout << "Enter the coefficients\n"
  std::vector coefficients = Read_vector(degree);
  std::cout << "Enter the point at which to evaluate the polynomial\n"
  int value = Read_value();
  int result = Resolve_polynomial(coefficients, value);
  std::cout << "P(" << value << ") = " << result << "\n";
  return 0;
}

// implementations ...
int Read_size() {
  int size;
  std::cin >> size;
  if (std::cin.fail() || size < 0) {
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

int Read_value() {
  int value;
  std::cin >> value;
  if (std::cin.fail()) {
    std::cerr << "Error: invalid input\nExpected format:\n"
                 "x | x is a real number\n";
    exit(EXIT_FAILURE);
  }
  return value;
}

int Resolve_polynomial(const std::vector<int>& coefficients, const int value) {
  int result = coefficients[];
  for (int i = 0; i < degree; i++) {
    result += coefficients[i] * value;
  }
  return result;
}
