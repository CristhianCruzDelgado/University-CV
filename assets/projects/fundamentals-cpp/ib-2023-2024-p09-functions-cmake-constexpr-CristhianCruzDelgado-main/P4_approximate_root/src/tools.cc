#include "tools.h"

double Read_num() {
  double num;
  std::cout << "Enter a real number\n";
  std::cin >> num;
  if (std::cin.fail() || num < 0) {
    std::cerr << "Error: invalid input\nExpected format: x.x"
                 " | it must be a positive real number\n";
    return -1.0;
  }
  return num;
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
