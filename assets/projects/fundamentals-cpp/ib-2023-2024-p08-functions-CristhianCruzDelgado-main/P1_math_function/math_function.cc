/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 8: functions
  *
  * Author: Cristhian Adoney Cruz Delgado
  * Email: alu0101648293@ull.edu.es
  * Date: 14/11/2024
  * File math_function.cc: client program.
  * Description: reads three real numbers and evaluates a mathematical function with them
  */

#include <iostream>
#include <iomanip>
#include <cmath>

double math_function(double, double, double);

int main() {
  double num1, num2, num3;
  std::cout << "Enter 3 numbers separated by spaces\n";
  std::cin >> num1 >> num2 >> num3;
  if (std::cin.fail()) {
    std::cout << "Error: unexpected input\nExpected format: \"x y z\" | x, y, z are real numbers\n";
    return 1;
  }
  std::cout << std::fixed << std::setprecision(6) << "f(x, y, z) = " << math_function(num1, num2, num3) << "\n";
  return 0;
}

double math_function(double var1, double var2, double var3) {
  double radicand, dividend, divisor, result;
  radicand = (2 * var3) - 4;
  if (radicand >= 0) {
    dividend = sqrt(radicand);
  } else {
    std::cout << "Error: square root of a negative number\n";
    return 0;
  }
  divisor = ((var1 * var1) - (var2 * var2));
  if (divisor != 0) {
    return result = dividend / divisor;
  } else {
    std::cout << "Error: division by zero\n";
    return 0;
  }
}
