/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File circle_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Creates a circle, computes its area and perimeter, shows it
 * and determines whether a point belongs to the circle
 */

#include <iostream>

#include "circle.h"
#include "point2D.h"

int main() {
  Point2D center{0, 0}, other{0.5, 0.5};
  Circle circle{center, 1, Color::black};
  circle.Print();
  std::cout << circle.Area() << " " << circle.Perimeter() << "\n";
  std::cout << "Does the point belong to the circle?\n";
  circle.IsIn(other) ? std::cout << "Yes\n" : std::cout << "No\n";
  return 0;
}
