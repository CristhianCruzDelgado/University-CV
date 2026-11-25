/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File complex.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Implements the Complex class
 */

#include "complex.h"

// Constructors
Complex::Complex() : real_(0), imag_(0) {}

Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

// Destructor
Complex::~Complex() {}

// Getters
double Complex::get_real() const { return real_; }

double Complex::get_imag() const { return imag_; }

// Setters
void Complex::set_real(double real) { real_ = real; }

void Complex::set_imag(double imag) { imag_ = imag; }

// Addition operator
Complex Complex::operator+(const Complex& number) const {
  Complex result;
  result.set_real(get_real() + number.get_real());
  result.set_imag(get_imag() + number.get_imag());
  return result;
}

// Subtraction operator
Complex Complex::operator-(const Complex& number) const {
  Complex result;
  result.set_real(get_real() - number.get_real());
  result.set_imag(get_imag() - number.get_imag());
  return result;
}

// Input operator
std::istream& operator>>(std::istream& is, Complex& number) {
  double real, imag;
  is >> real >> imag;
  number.set_real(real);
  number.set_imag(imag);
  return is;
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Complex& number) {
  os << "Real part: " << number.get_real()
     << ". Imaginary part: " << number.get_imag() << ".\n";
  return os;
}
