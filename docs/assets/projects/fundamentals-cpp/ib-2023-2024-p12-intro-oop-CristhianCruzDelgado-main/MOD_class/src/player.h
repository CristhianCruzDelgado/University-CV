/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 12: introduction to OOP
  * File player.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 12/12/2024
  * @brief Declares the Player class
  */

#include <string>

#include "person.h"

enum class Position {
  base,
  alero,
  escolta,
  pivote
};

class Player : public Person {
  public:
    Player(double height, double weight, Position position, std::string name, int age, std::string id)
        : Person(name, age, id), height_(height), weight_(weight), position_(position) {}
  private:
    double height_;
    double weight_;
    Position position_;
};
