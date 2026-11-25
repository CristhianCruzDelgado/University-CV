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
  * File triangle_area.cc: client program.
  * Description: reads the three sides of a triangle
  * and computes its area with Heron's formula
  */

#include <iostream>
#include <iomanip>
#include <cmath>

bool IsValidTriangle(double, double, double);

double Area(double, double, double);

int main() {
  double side1, side2, side3;
  std::cout << "Enter three numbers\n";
  std::cin >> side1 >> side2 >> side3;
  if (std::cin.fail()) {
    std::cout << "Error: invalid input\nExpected format: \"a b c\" "
                 "| they are natural numbers\n";
    return 1;
  }
  IsValidTriangle(side1, side2, side3)
  ? std::cout << std::fixed << std::setprecision(2)
              << std::trunc(Area(side1, side2, side3) * 100) / 100 << "\n"
  : std::cout << "Not a valid Triangle\n";
  return 0;
}

bool IsValidTriangle(double side1, double side2, double side3) {
  if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
    return true;
  }
  return false;
}

double Area(double side1, double side2, double side3) {
  double semiperim, radical, area;
  semiperim = (side1 + side2 + side3) / 2;
  radical = semiperim * (semiperim - side1) * (semiperim - side2) * (semiperim - side3);
  area = sqrt(radical);
  return area;
}
