#include <iostream>
#include <vector>
using namespace std;

int minSteps(int n) {
  vector<int> mem = {0, 0};
  for (int i = 2; i <= n; i++) {
    int divisor = 1;
    int quotient;
    for (int j = i / 2; j >= 1 / 2; j--) {
      if (i % j == 0) {
        mem.push_back(mem[j] + i / j);
        break;
      }
    }
    if (divisor == 1) {
      mem.push_back(i);
    }
  }
  return mem[n];
}
int main() { return 0; }
