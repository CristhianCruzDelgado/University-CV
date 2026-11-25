/** Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Bachelor's Degree in Computer Engineering
  * Subject: Informática Básica 2023-2024
  * Year: 1st
  * Lab assignment 8: functions
  * File perfect_num.cc: client program.
  *
  * @author Cristhian Adoney Cruz Delgado alu0101648293@ull.edu.es
  * @date 14/11/2024
  * @brief: Checks whether a number is perfect
  */

bool is_perfect(int n) {
  int sum = 1;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      sum += i;
    }
  }
  if (n == sum && n != 1) {
    return true;
  }
  return false;
}
