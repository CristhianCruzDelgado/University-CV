#include "complex_numbers.h"

namespace complex_numbers {

// Constructors
Complex::Complex() : real_(0.0), imag_(0.0) {}

Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}

// Destructor
Complex::~Complex() {}

// Getters
double Complex::real() const { return real_; }

double Complex::imag() const { return imag_; }

// Setters
void Complex::set_real(double value) { real_ = value; }

void Complex::set_imag(double value) { imag_ = value; }

// Absoluto
double Complex::abs() const { return sqrt(pow(real(), 2) + pow(imag(), 2)); }

// Conjugado
Complex Complex::conj() const { return Complex(real(), -imag()); }

// Sobrecarga operadores miembro
Complex Complex::operator+(const Complex& number) const {
  Complex result;
  result.set_real(real() + number.real());
  result.set_imag(imag() + number.imag());
  return result;
}

Complex Complex::operator-(const Complex& number) const {
  Complex result;
  result.set_real(real() - number.real());
  result.set_imag(imag() - number.imag());
  return result;
}

Complex Complex::operator*(const Complex& number) const {
  Complex result;
  result.set_real(real() * number.real() - imag() * number.imag());
  result.set_imag(real() * number.imag() + imag() * number.real());
  return result;
}

Complex Complex::operator/(const Complex& number) const {
  Complex result;
  double num_real, num_imag, den;
  num_real = (real() * number.real() + imag() * number.imag());
  num_imag = (imag() * number.real() - real() * number.imag());
  den = pow(number.real(), 2) + pow(number.imag(), 2);
  result.set_real(num_real / den);
  result.set_imag(num_imag / den);
  return result;
}

Complex Complex::operator+(double number) const {
  Complex result;
  result.set_real(real() + number);
  result.set_imag(imag());
  return result;
}
Complex Complex::operator-(double number) const {
  Complex result;
  result.set_real(real() - number);
  result.set_imag(imag());
  return result;
}
Complex Complex::operator*(double number) const {
  Complex result;
  result.set_real(real() * number);
  result.set_imag(imag() * number);
  return result;
}
Complex Complex::operator/(double number) const {
  Complex result;
  result.set_real(real() / number);
  result.set_imag(imag() / number);
  return result;
}

// Sobrecarga operadores globales
Complex operator+(double number, const Complex& complex) {
  Complex result;
  result.set_real(number + complex.real());
  result.set_imag(complex.imag());
  return result;
}
Complex operator-(double number, const Complex& complex) {
  Complex result;
  result.set_real(number - complex.real());
  result.set_imag(-complex.imag());
  return result;
}
Complex operator*(double number, const Complex& complex) {
  Complex result;
  result.set_real(number * complex.real());
  result.set_imag(number * complex.imag());
  return result;
}
Complex operator/(double number, const Complex& complex) {
  Complex result;
  double num_real, num_imag, den;
  num_real = (number * complex.real());
  num_imag = (-number * complex.imag());
  den = pow(complex.real(), 2) + pow(complex.imag(), 2);
  result.set_real(num_real / den);
  result.set_imag(num_imag / den);
  return result;
}

// Exponencial
Complex Complex::exp() const {
  Complex result;
  result.set_real(std::exp(real()) * std::cos(imag()));
  result.set_imag(std::exp(real()) * std::sin(imag()));
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
  os << "Parte real: " << number.real()
     << ". Parte imaginaria: " << number.imag() << ".\n";
  return os;
}

}  // namespace complex_numbers
