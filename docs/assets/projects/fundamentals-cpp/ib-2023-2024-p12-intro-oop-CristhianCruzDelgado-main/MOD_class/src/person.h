/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 12: introduction to OOP
  * File person.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 12/12/2024
  * @brief Declares the Person class
  */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person {
  public:
    Person(std::string name, int age, std::string id)
        : name_(name), age_(age), id_(id) {}
    ~Person() {}
  private:
    std::string name_;
    int age_;
    std::string id_;
};

#endif
