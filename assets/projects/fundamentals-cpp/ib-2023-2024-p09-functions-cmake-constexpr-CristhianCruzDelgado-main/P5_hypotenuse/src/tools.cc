#include "tools.h"

double Read_num() {
  double num;
  std::cout << "Enter a real number\n";
  std::cin >> num;
  if (std::cin.fail()) {
    std::cerr << "Error: invalid input\nExpected format: x.x"
                 " | it must be a real number\n";
    exit(EXIT_FAILURE);
  }
  return num;
}

double Sum_squares(double leg1, double leg2) {
  double sum;
  sum = (leg1 * leg1) + (leg2 * leg2);
  return sum;
}

double Square_root(double num, const double EPSILON) {
  double root = 1.0;
  double delta = 1.0;
  while (fabs((root * root) - num) > EPSILON) {
    if (delta > 0) {
      while ((root * root) < num) {
        root += delta;
      }
    } else {
      while ((root * root) > num) {
        root += delta;
      }
    }
    delta *= -0.5;
  }
  return root;
}
