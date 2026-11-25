/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File point2D.h: header file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Defines the Point2D class
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#include <cmath>
#include <iostream>

class Point2D {
 public:
  // Constructors and destructor
  Point2D();
  Point2D(double x, double y);
  ~Point2D();

  // Getters
  const double get_x() const;
  const double get_y() const;

  // Setters
  void set_x(double x);
  void set_y(double y);

  // Methods
  void Show() const;
  void Move(double x, double y);
  double Distance(const Point2D& point) const;
  Point2D Middle(const Point2D& point) const;

 private:
  double x_;
  double y_;
};

#endif
