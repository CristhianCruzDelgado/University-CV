/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 12: introduction to OOP
  * File trainer.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 12/12/2024
  * @brief Declares the Trainer class
  */

#include <string>

#include "date.h"
#include "person.h"

class Trainer : public Person {
  public:
    Trainer(std::string license, Date inital_date, Date final_date, std::string name, int age, std::string id)
        : Person(name, age, id), license_(license), inital_date_(inital_date), final_date_(final_date) {}
  private:
    std::string license_;
    Date inital_date_;
    Date final_date_;
};
