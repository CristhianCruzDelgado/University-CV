/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 10: string, array and vector
  * File Calculate_max_min_avg: header file.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 28/11/2024
  * @brief: Declares the functions that compute the maximum,
  * minimum and average of a vector
  */

#ifndef CALCULATE_MAX_MIN_AVG_H_
#define CALCULATE_MAX_MIN_AVG_H_

#include <iostream>
#include <vector>

void CalculateMaximumMinimumAverage(const std::vector<double>&, const int,
                                    double&, double&, double&);

void PrintValues(double&, double&, double&);

#endif
