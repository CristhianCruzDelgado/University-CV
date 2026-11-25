/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Person class Definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/header-guards/
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

/**
 * Persona class.
 *       Represents a person by their first name, surname and age
 */
class Persona {
 public:
  Persona();
  Persona(const std::string& nombre, const std::string& apellido, const int edad);
  std::string nombre() const { return nombre_; }
  std::string apellido() const { return apellido_; }
  int edad() const { return edad_; }
  void Print() const;
 private:
  std::string nombre_{""};     /** First name of the person */
  std::string apellido_{""};   /** Surname of the person */
  int edad_{0};                /** Age of the person */
};

#endif
