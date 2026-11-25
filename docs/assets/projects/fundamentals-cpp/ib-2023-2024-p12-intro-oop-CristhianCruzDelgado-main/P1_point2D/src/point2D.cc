/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File point2D.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Implements the Point2D class
 */

#include "point2D.h"

// Default constructor
Point2D::Point2D() : x_(0), y_(0) {}

// Constructor with parameters
Point2D::Point2D(double x, double y) : x_(x), y_(y) {}

// Destructor
Point2D::~Point2D() {}

// Getters
const double Point2D::get_x() const { return x_; }

const double Point2D::get_y() const { return y_; }

// Setters
void Point2D::set_x(double x) { this->x_ = x; }

void Point2D::set_y(double y) { this->y_ = y; }

// Show the coordinates
void Point2D::Show() const {
  std::cout << "(" << get_x() << ", " << get_y() << ")\n";
}

// Move the point to new coordinates
void Point2D::Move(double x, double y) {
  set_x(x);
  set_y(y);
}

// Compute the distance between two points
double Point2D::Distance(const Point2D& point) const {
  return std::sqrt(std::pow(get_x() - point.get_x(), 2) +
                   std::pow(get_y() - point.get_y(), 2));
}

// Compute the midpoint between two points
Point2D Point2D::Middle(const Point2D& point) const {
  return Point2D((get_x() + point.get_x()) / 2, (get_y() + point.get_y()) / 2);
}
