/** Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Bachelor's Degree in Computer Engineering
 * Subject: Informática Básica 2023-2024
 * Year: 1st
 * Lab assignment 11: files
 * File DFA.cc: implementation file.
 *
 * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
 * @date 5/12/2024
 * @brief: Implements the DFA class
 */

#include "DFA.h"

// getter
int DFA::get_number_states() const { return number_states_; }
int DFA::get_initial_state() const { return initial_state_; }
const std::vector<bool>& DFA::get_final_states() const { return final_states_; }
const std::vector<std::map<char, int>>& DFA::get_transitions() const {
  return transitions_;
}

// setter
void DFA::set_number_states(int number_states) {
  number_states_ = number_states;
}
void DFA::set_initial_state(int initial_state) {
  initial_state_ = initial_state;
}
void DFA::set_final_states(const std::vector<bool>& final_states) {
  final_states_ = final_states;
}
void DFA::set_transitions(const std::vector<std::map<char, int>>& transitions) {
  transitions_ = transitions;
}

// read
std::istream& operator>>(std::istream& is, DFA& automata) {
  // Read lines 1 and 2
  int number_states, initial_state;
  is >> number_states >> initial_state;
  automata.set_number_states(number_states);
  automata.set_initial_state(initial_state);

  std::vector<bool> final_states(number_states, false);
  std::vector<std::map<char, int>> transitions(number_states);

  // Read the remaining lines one by one
  for (int i = 0; i < number_states; ++i) {
    int state_id, number_transitions;
    bool is_final;
    is >> state_id >> is_final >> number_transitions;
    final_states[state_id] = is_final;

    for (int j = 0; j < number_transitions; ++j) {
      char symbol;
      int next_state;
      is >> symbol >> next_state;
      transitions[state_id][symbol] = next_state;
    }
  }
  automata.set_final_states(final_states);
  automata.set_transitions(transitions);
  return is;
}

// write
std::ostream& operator<<(std::ostream& os, const DFA& automata) {
  os << "|Q| = " << automata.get_number_states() << "\n";
  os << "q0 = " << automata.get_initial_state() << "\n";
  os << "F = {";
  bool first = true;
  for (size_t i = 0; i < automata.get_final_states().size(); ++i) {
    if (automata.get_final_states()[i]) {
      if (!first) os << ", ";
      os << i;
      first = false;
    }
  }
  os << "}\n";
  for (size_t i = 0; i < automata.get_transitions().size(); i++) {
    for (const auto& [symbol, next_state] : automata.get_transitions()[i])
      os << "delta(" << i << ", " << symbol << ") = " << next_state << "\n";
  }

  return os;
}
