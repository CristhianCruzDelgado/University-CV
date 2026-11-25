/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Persona class
 *        this is a client program that uses the Persona class
 *
 * @see https://github.com/ULL-ESIT-IB-2021-2022/P11-Classes-CMake/blob/main/Classes-CMake.md
 */

#include <iostream>

#include "persona.h"

int main() {
  Persona otra;
  Persona albert{"Albert", "Einstein", 18};
  otra.Print();
  albert.Print();
  return 0;
}
