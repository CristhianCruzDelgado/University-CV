/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File DFA.h: header file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief Declares the DFA class
 */

#ifndef DFA_H_
#define DFA_H_

#include <iostream>
#include <map>
#include <vector>

class DFA {
 public:
  DFA() : number_states_(), initial_state_(), final_states_(), transitions_() {}
  ~DFA() {}
  int get_number_states() const;
  int get_initial_state() const;
  const std::vector<bool>& get_final_states() const;
  const std::vector<std::map<char, int>>& get_transitions() const;
  void set_number_states(int);
  void set_initial_state(int);
  void set_final_states(const std::vector<bool>&);
  void set_transitions(const std::vector<std::map<char, int>>&);
  friend std::istream& operator>>(std::istream&, DFA&);
  friend std::ostream& operator<<(std::ostream&, const DFA&);

 private:
  int number_states_;
  int initial_state_;
  std::vector<bool> final_states_;
  std::vector<std::map<char, int>> transitions_;
};

#endif
