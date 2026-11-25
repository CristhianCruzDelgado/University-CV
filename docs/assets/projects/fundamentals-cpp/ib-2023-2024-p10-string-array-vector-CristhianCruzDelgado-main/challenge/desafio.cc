#include <iostream>
#include <vector>

void SumaPolinomios(const std::vector<int>&, const std::vector<int>&);

int main() {
  std::vector<int> vector1 = { 3, 2, 1 };
  std::vector<int> vector2 = { 0, 5, 4 };
  SumaPolinomios(vector1, vector2);
  return 0;
}

void SumaPolinomios(const std::vector<int>& v1, const std::vector<int>& v2) {
  int suma = 0;
  int max_size = 0;
  int suma_final = 0;
  bool v1mayorv2 = false;
  if (v1.size() < v2.size()) {
   max_size = v1.size();
   suma_final = v2.size();
  } else {
   max_size = v2.size();
   suma_final = v2.size();
   v1mayorv2 = true;
  }
  std::vector<int> pol;
  for (int i = 0; i < max_size; i++) {
    pol[i] = v1[i] + v2[i];
  }
  if (v1mayorv2) {
    for (int j = max_size; j < suma_final; j++) {
      pol[j] = v2[j];
    }
  } else {
    for (int j = max_size; j < suma_final; j++) {
      pol[j] = v1[j];
    }
  }
  for (int z = 0; z < pol.size(); z++) {
    std::cout << pol[z] << " ";
  }
  std::cout << "\n";
}
