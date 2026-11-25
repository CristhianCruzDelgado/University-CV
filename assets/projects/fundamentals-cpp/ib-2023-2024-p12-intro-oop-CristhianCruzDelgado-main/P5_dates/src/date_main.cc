/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File date_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Works with dates, determines whether a year is a leap year and
 * checks that the dates are valid
 */

#include <fstream>
#include <iostream>
#include <string>

#include "date.h"

int HelpInfo();

int NoOption();

int Input(char* agrv[]);

int Output(char* argv[]);

int main(int argc, char* argv[]) {
  if (argc > 3) {
    std::cout << "Learn how to use the program: ./date --help\n";
    return 0;
  }
  if (argc == 1) {
    return NoOption();
  }
  if (argc == 2) {
    if (std::string(argv[1]) == "--help") {
      return HelpInfo();
    }
    return Input(argv);
  }
  if (argc == 3) {
    return Output(argv);
  }
}

int HelpInfo() {
  std::cout << "Run the program without options to build any "
               "date\nand to read a date and determine whether it "
               "is a leap year.\nIn either case, the input format "
               "is: xx xx xxxx\nTo read from a "
               "file, run: ./date INPUT\nThis option "
               "reads dates from a file, in that format, and "
               "shows them one by one.\nFinally, if an "
               "output file is given, the dates are copied to it.\nTo "
               "do so, run: ./date INPUT OUTPUT\n";
  return 0;
}

int NoOption() {
  int d, m, y;
  std::cin >> d >> m >> y;
  std::cout << Date(d, m, y);
  std::cout << "Try to find a leap year.\n";
  Date bisiesto;
  std::cin >> bisiesto;
  if (bisiesto.is_valid_date()) {
    if (bisiesto.is_leap_year()) {
      std::cout << "You have found a leap year.\n";
    } else {
      std::cout << "No luck this time.\n";
    }
    return 0;
  }
  std::cerr << "Error.\n";
  return -1;
}

int Input(char* argv[]) {
  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cerr << "The file could not be opened.\nError.\n";
    return -1;
  }
  Date fecha;
  while (input >> fecha) {
    std::cout << fecha;
  }
  input.close();
  return 0;
}

int Output(char* argv[]) {
  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);
  if (!input.is_open() || output.is_open()) {
    std::cerr << "The files could not be opened.\nError.\n";
    return -1;
  }
  Date fecha;
  while (input >> fecha) {
    output << fecha;
  }
  input.close();
  output.close();
  return 0;
}
