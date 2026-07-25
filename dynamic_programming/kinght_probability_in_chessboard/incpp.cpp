#include <iostream>
#include <vector>
using namespace std;

double knightProbability_recursive(
    int n, int k, int row, int column,
    vector<vector<vector<double>>> &dp) { // this wont work for larger values
  if (k == 0)
    return 1;

  if (dp[k][row][column] != -1)
    return dp[k][row][column];
  vector<pair<int, int>> paths = {
      {-1 + row, 2 + column},  {-1 + row, -2 + column}, {1 + row, 2 + column},
      {1 + row, -2 + column},  {2 + row, 1 + column},   {2 + row, -1 + column},
      {-2 + row, -1 + column}, {-2 + row, 1 + column},
  };
  vector<pair<int, int>> remains;
  for (auto path : paths) {
    if ((path.first < n && path.second < n) &&
        (path.first >= 0 && path.second >= 0)) {
      remains.push_back(path);
    }
  }
  double sum = 0.0;
  for (auto path : remains) {
    cout << path.first << " " << path.second << endl;
    sum += (1.0 / 8.0) *
           (knightProbability_recursive(n, k - 1, path.first, path.second, dp));
  }
  dp[k][row][column] = sum;
  return sum;
}

double knightProbability(int n, int k, int row, int column) {
  vector<vector<vector<double>>> dp(
      k + 1, vector<vector<double>>(n, vector<double>(n, -1.0)));
  return knightProbability_recursive(n, k, row, column, dp);
}
int main() {
  cout << knightProbability(3, 3, 0, 0);
  return 0;
}
