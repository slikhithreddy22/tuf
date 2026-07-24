#include "iostream"
#include <vector>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  for (int i = 1; i < n; i++) {
    matrix[i][0] = min(matrix[i - 1][0], matrix[i - 1][1]) + matrix[i][0];
    for (int j = 1; j < n - 1; j++) {
      matrix[i][j] =
          matrix[i][j] + min(min(matrix[i - 1][j - 1], matrix[i - 1][j]),
                             matrix[i - 1][j + 1]);
    }

    matrix[i][n - 1] =
        min(matrix[i - 1][n - 1], matrix[i - 1][n - 2]) + matrix[i][n - 1];
  }
  int min = matrix[n - 1][0];
  for (int var : matrix[n - 1]) {
    if (min > var) {
      min = var;
    }
  }
  return min;
}
int main() {
  vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  cout << minFallingPathSum(matrix);
  return 0;
}
