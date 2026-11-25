/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 12: introduction to OOP
 * File date.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 12/12/2024
 * @brief Implements the Date class
 */

#include "date.h"

// Default constructor
Date::Date() : day_(0), month_(0), year_(0) {}

// Constructor with parameters
Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {
  if (!is_valid_date()) {
    std::cout
        << "Invalid date. The object was not built correctly.\n";
    set_day(0);
    set_month(0);
    set_year(0);
  }
}

// Destructor
Date::~Date() {}

int Date::get_day() const { return day_; }

int Date::get_month() const { return month_; }

int Date::get_year() const { return year_; }

void Date::set_day(int day) { day_ = day; }

void Date::set_month(int month) { month_ = month; }

void Date::set_year(int year) { year_ = year; }

bool Date::is_leap_year() const {
  return (year_ % 4 == 0 && year_ % 100 != 0) || (year_ % 400 == 0);
}

bool Date::is_valid_date() const {
  if (day_ < 1 || day_ > 31 || month_ < 1 || month_ > 12 || year_ < 1800 ||
      year_ > 9999) {
    return false;
  }
  if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
    if (day_ > 30) {
      return false;
    }
  }
  if (month_ == 2) {
    if (is_leap_year() && day_ > 29) {
      return false;
    } else if (!is_leap_year() && day_ > 28) {
      return false;
    }
  }
  return true;
}

std::istream& operator>>(std::istream& is, Date& date) {
  int day, month, year;
  is >> day >> month >> year;
  date.set_day(day);
  date.set_month(month);
  date.set_year(year);
  if (!date.is_valid_date()) {
    std::cout << "Invalid date. It was not read correctly.\n";
    date.set_day(0);
    date.set_month(0);
    date.set_year(0);
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.get_day() << "/" << date.get_month() << "/" << date.get_year()
     << "\n";
  return os;
}
