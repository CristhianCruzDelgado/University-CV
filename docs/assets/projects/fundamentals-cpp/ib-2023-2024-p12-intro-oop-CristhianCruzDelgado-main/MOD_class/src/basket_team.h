/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 12: introduction to OOP
  * File xxx.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 12/12/2024
  * @brief Declares the BasketTeam class
  */

#ifndef BASKET_TEAM_H_
#define BASKET_TEAM_H_

#include <string>
#include <vector>

#include "player.h"
#include "trainer.h"
#include "support.h"

class BasketTeam {
  public:
    BasketTeam() : name_(""), city_(""), players_(), trainers_(), support_() {}
    BasketTeam(std::string name, std::string city, std::vector<Player> players,
    std::vector<Trainer> trainers, std::vector<Support> support)
        : name_(name), city_(city), players_(players), trainers_(trainers), support_(support) {}
    ~BasketTeam() {}
  private:
    std::string name_;
    std::string city_;
    std::vector<Player> players_;
    std::vector<Trainer> trainers_;
    std::vector<Support> support_;
};

#endif
