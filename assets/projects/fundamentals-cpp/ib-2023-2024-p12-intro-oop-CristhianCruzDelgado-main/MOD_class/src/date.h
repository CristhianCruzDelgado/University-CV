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
 * @brief Defines the Date class
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

class Date {
 public:
  // Constructors and destructor
  Date();
  Date(int day, int month, int year);
  ~Date();

  // Getters
  int get_day() const;
  int get_month() const;
  int get_year() const;

  // Setters
  void set_day(int day);
  void set_month(int month);
  void set_year(int year);

  // Checks
  bool is_leap_year() const;
  bool is_valid_date() const;

  // Input and output overloads
  friend std::istream& operator>>(std::istream& is, Date& date);
  friend std::ostream& operator<<(std::ostream& os, const Date& date);

 private:
  int day_;
  int month_;
  int year_;
};

#endif
