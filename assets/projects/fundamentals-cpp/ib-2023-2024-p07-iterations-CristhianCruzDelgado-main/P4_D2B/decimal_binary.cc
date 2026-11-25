/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 7: iterations
  *
  * Author: Cristhian Adoney Cruz Delgado
  * Email: alu0101648293@ull.edu.es
  * Date: 7/11/2024
  * File decimal_binary: client program.
  * Description: converts decimal numbers to binary
  */

#include <iostream>

int conversor(int);

int main() {
  int decimal;
  std::cout << "Enter a decimal number\n";
  std::cin >> decimal;
  if (decimal < 0) {
    std::cout << "Error: invalid decimal number\n";
                 "Try a natural number\n";
    return 1;
  }
  // Show the conversion
  std::cout << "The number in binary is: " << conversor(decimal) << "\n";
  return 0;
}

int conversor(int decimal) {
  if (decimal == 0 || decimal == 1) {
    return decimal;
  }
  int binary = 0;
  int position = 1;
  while (decimal > 0) {
    binary += (decimal % 2) * position;
    decimal /= 2;
    position *= 10;
  }
  return binary;
}
