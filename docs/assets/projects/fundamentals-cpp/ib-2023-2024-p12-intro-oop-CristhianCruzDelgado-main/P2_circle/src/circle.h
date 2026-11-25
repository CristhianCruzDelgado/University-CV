/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File cricle.h: header file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Defines the Circle class
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <cmath>
#include <iostream>

#include "point2D.h"

const double kPI = 3.14159265358979323846;

enum class Color { white, red, blue, yellow, green, black };

class Circle {
 public:
  // Constructor and destructor
  Circle(Point2D point, double radio, Color color);
  ~Circle();

  // Getters
  const Point2D get_center() const;
  const double get_radio() const;
  const Color get_color() const;

  // Setters
  void set_center(const Point2D& point);
  void set_radio(const double radio);
  void set_color(const Color color);

  // Methods
  double Area() const;
  double Perimeter() const;
  void Print() const;
  bool IsIn(const Point2D& point) const;

 private:
  Point2D center_;
  double radio_;
  Color color_;
};

#endif
