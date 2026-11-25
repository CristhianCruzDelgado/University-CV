/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File complex.h: header file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Defines the Complex class
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex {
 public:
  // Constructors and destructor
  Complex();
  Complex(double real, double imag);
  ~Complex();

  // Getters
  double get_real() const;
  double get_imag() const;

  // Setters
  void set_real(double real);
  void set_imag(double imag);

  // Overloaded operators
  Complex operator+(const Complex& number) const;
  Complex operator-(const Complex& number) const;

  // Overloaded stream operators
  friend std::istream& operator>>(std::istream& is, Complex& number);
  friend std::ostream& operator<<(std::ostream& os, const Complex& number);

 private:
  double real_;
  double imag_;
};

#endif
