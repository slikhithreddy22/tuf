#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int knapsack(vector<int> &weights, vector<int> profit, int n, int m) {
  vector<int> items;
  vector<vector<int>> k(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= m; w++) {
      if ((i == 0) || (w == 0)) {
        k[i][w] = 0;
      } else if (weights[i] <= w) {
        k[i][w] = max(k[i - 1][w], k[i - 1][w - weights[i]] + profit[i]);
      } else {
        k[i][w] = k[i - 1][w];
      }
    }
  }
  return k[n][m];
}

int main() {
  vector<int> weights = {0, 2, 3, 4, 5};
  vector<int> profits = {0, 1, 2, 5, 6};
  int m = 8, n = 4;
  cout << knapsack(weights, profits, n, m);
  return 0;
}
