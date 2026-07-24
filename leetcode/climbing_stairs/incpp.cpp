#include <iostream>
#include <vector>
using namespace std;

int climbingStairs(int n) {
  vector<int> mem = {0, 1, 2};
  for (int i = 3; i < n; i++) {
    mem.emplace_back(mem[i - 1] + mem[i - 2]);
    cout << "i = " << i << "mem[i] = " << mem[i] << endl;
  }
  return mem[n - 1] + mem[n - 2];
}
int main() {
  cout << climbingStairs(4) << endl;
  return 0;
}
