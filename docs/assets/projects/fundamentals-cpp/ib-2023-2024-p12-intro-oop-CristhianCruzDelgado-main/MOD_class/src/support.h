/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 12: introduction to OOP
  * File support.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 12/12/2024
  * @brief Declares the Support class
  */

#include "date.h"
#include "person.h"

class Support : public Person {
  public:
    Support(Date initial_date, Date final_date, std::string name, int age, std::string id)
        : Person(name, age, id), initial_date_(initial_date), final_date_(final_date) {}
  private:
    Date initial_date_;
    Date final_date_;
};
