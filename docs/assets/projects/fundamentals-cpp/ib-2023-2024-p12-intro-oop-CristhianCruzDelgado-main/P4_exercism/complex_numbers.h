#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

#include <cmath>
#include <iostream>

namespace complex_numbers {

class Complex {
 public:
  // Constructors and destructor
  Complex();
  Complex(double real, double imag);
  ~Complex();

  // Getters
  double real() const;
  double imag() const;

  // Setters
  void set_real(double value);
  void set_imag(double value);

  // Absoluto
  double abs() const;

  // Conjugado
  Complex conj() const;

  // Operadores sobrecargados miembro
  Complex operator+(const Complex& number) const;
  Complex operator-(const Complex& number) const;
  Complex operator*(const Complex& number) const;
  Complex operator/(const Complex& number) const;

  Complex operator+(double number) const;
  Complex operator-(double number) const;
  Complex operator*(double number) const;
  Complex operator/(double number) const;

  // Operadores sobrecargados globales
  friend Complex operator+(double number, const Complex& complex);
  friend Complex operator-(double number, const Complex& complex);
  friend Complex operator*(double number, const Complex& complex);
  friend Complex operator/(double number, const Complex& complex);

  // Exponencial
  Complex exp() const;

  // Input and output stream operators
  friend std::istream& operator>>(std::istream& is, Complex& number);
  friend std::ostream& operator<<(std::ostream& os, const Complex& number);

 private:
  double real_;
  double imag_;
};

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
