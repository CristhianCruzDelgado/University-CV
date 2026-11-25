/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File min_max.cc: implementation file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Computes the minimum and the maximum
  * of a pair of numbers
  */

#include "min_max.h"

void Min_max(int a, int b, int& mn, int& mx) {
  if (a < b) {
    mn = a;
    mx = b;
  } else {
    mn = b;
    mx = a;
  }
}
