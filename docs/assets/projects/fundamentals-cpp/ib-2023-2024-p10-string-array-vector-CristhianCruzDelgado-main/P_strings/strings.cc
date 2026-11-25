#include "strings.h"

void EliminateSpaces(const std::string& cadena) {
  std::string nueva_cadena = "";
  for (auto caracter : cadena) {
    if (caracter != ' ') {
      nueva_cadena += caracter;
    }
  }
  std::cout << nueva_cadena << "\n";
}
