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
  * File binary_decimal: client program.
  * Description: converts binary numbers to decimal
  */

#include <iostream>

bool is_binary(int);

int conversor(int);

int main() {
  int binary;
  std::cout << "Enter a binary number \n";
  std::cin >> binary;
  // Check that the input is binary
  if (!is_binary(binary)) {
    std::cout << "Error: the input is not a binary number\n"
                 "Only '0' and '1' are valid\n";
    return 1;
  }
  // Show the conversion
  std::cout << "The corresponding decimal number is: " << conversor(binary) << "\n";
  return 0;
}

bool is_binary(int binary) {
  while (binary > 0) {
    int test = binary;
    test %= 10;
    if (test != 0 && test != 1) {
      return false;
    }
    binary /= 10;
  }
  return true;
}

int conversor(int binary) {
  int decimal = 0;
  int position = 1;
  while (binary > 0) {
    decimal += (binary % 10) * position;
    position *= 2;
    binary /= 10;
  }
  return decimal;
}
