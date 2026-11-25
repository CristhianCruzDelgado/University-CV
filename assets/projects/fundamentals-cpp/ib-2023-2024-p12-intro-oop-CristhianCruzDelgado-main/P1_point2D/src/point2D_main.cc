/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File point2D_main.cc: client program.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Creates a point, moves it, shows it, computes the
 * distance between two points and their midpoint
 */

#include <iostream>

#include "point2D.h"

int main() {
  Point2D point;
  point.Move(3, 3);
  point.Show();
  Point2D other{5, 5};
  std::cout << point.Distance(other) << "\n";
  Point2D middle_point = point.Middle(other);
  middle_point.Show();
  return 0;
}
