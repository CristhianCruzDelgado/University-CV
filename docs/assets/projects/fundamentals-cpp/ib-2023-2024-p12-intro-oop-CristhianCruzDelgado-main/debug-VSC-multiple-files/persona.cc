/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Persona class Implementation
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 */

#include <iostream>
#include <string>

#include "persona.h"

/*
 * @brief default constructor
 */
Persona::Persona() : nombre_{"Alan"}, apellido_{"Turing"}, edad_{41} {
 std::cout << "DEBUG: DEFAULT Persona constructor executed" << std::endl;
}

/*
 * @brief constructor with parameters
 * @param[in] nombre: string with the first name of the person to create
 * @param[in] apellido: string with the surname of the person to create
 * @param[in] edad: age of the person to create
 */
Persona::Persona(const std::string& nombre, const std::string& apellido, const int edad) : nombre_{nombre}, apellido_{apellido}, edad_{edad} {
 std::cout << "DEBUG: Persona constructor executed" << std::endl;
}

/*
 * @brief Prints the attributes
 */
void Persona::Print() const {
 std::cout << "Name: " << apellido() << ", " << nombre() << ". Age: " << edad() << std::endl;
}
