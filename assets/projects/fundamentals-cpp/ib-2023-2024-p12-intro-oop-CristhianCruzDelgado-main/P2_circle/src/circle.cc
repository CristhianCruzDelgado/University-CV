/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File circle.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Implements the Circle class
 */

#include "circle.h"

// Constructor with parameters
Circle::Circle(Point2D point, double radio, Color color)
    : center_(point), radio_(radio), color_(color) {}

// Destructor
Circle::~Circle() {}

// Getters
const Point2D Circle::get_center() const { return center_; }
const double Circle::get_radio() const { return radio_; }
const Color Circle::get_color() const { return color_; }

// Setters
void Circle::set_center(const Point2D& point) { center_ = point; }
void Circle::set_radio(const double radio) { radio_ = radio; }
void Circle::set_color(const Color color) { color_ = color; }

// Area
double Circle::Area() const { return kPI * std::pow(get_radio(), 2); }

// Perimeter
double Circle::Perimeter() const { return 2 * kPI * get_radio(); }

// Print the details of the circle
void Circle::Print() const {
  std::cout << "Circle of colour ";
  switch (get_color()) {
    case Color::white:
      std::cout << " white ";
      break;
    case Color::red:
      std::cout << "red";
      break;
    case Color::blue:
      std::cout << "blue";
      break;
    case Color::yellow:
      std::cout << "yellow";
      break;
    case Color::green:
      std::cout << "green";
      break;
    case Color::black:
      std::cout << "black";
      break;
    default:
      std::cout << " unknown colour ";
      break;
  }
  std::cout << ", with radius " << get_radio() << " and centre at ";
  get_center().Show();
}

// Check whether a point lies inside the circle
bool Circle::IsIn(const Point2D& point) const {
  return get_center().Distance(point) < get_radio();
}
