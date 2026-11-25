/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date Nov 7, 2022
 * @brief Shows floating point arithmetics
 *
 * https://www.geeksforgeeks.org/problem-in-comparing-floating-point-numbers-and-how-to-compare-them-correctly/
 * @see https://stackoverflow.com/a/17341/12791643
 */

#include <iostream>
#include <cmath>

bool AreEqual(const double, const double, const double epsilon = 1e-7);

int main() {
  const double kOneThird{0.3333333333};
  std::cout << kOneThird << std::endl;
  const double kDivision{1.0 / 3};
  std::cout << kDivision << std::endl;
  AreEqual(kOneThird, kDivision) ? std::cout << "Equals\n" : std::cout << "Differents\n";
  return 0;
}

bool AreEqual(const double num1, const double num2, const double epsilon) {
  if (fabs(num1 - num2) < epsilon) {
    return true;
  }
  return false;
}
