#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int> &cost) {
  int prev1 = cost[0];
  int prev2 = cost[1];
  for (int i = 2; i < cost.size(); i++) {
    int current = min(prev1, prev2) + cost[i];
    prev1 = prev2;
    prev2 = current;
  }
  return min(prev1, prev2);
}
int main() {
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << minCostClimbingStairs(cost);
  return 0;
}
