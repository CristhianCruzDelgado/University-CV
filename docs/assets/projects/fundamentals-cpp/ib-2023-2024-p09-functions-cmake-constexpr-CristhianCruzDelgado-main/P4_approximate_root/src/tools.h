/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 9: functions 2
  * File tools.h: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 21/11/2024
  * @brief: Declares the functions that read a number
  * from the user and compute its square root
  */

#ifndef SQUARE_ROOT_H_
#define SQUARE_ROOT_H_

#include <iostream>
#include <cmath>

double Read_num();

double Square_root(double number, const double EPSILON = 1e-4);

#endif // SQUARE_ROOT_H_
