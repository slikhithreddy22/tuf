#include <iostream>
#include <vector>
using namespace std;

int uniquePaths_recursive(int m, int n) { // not the best solution and won't
                                          // even run because of time exceeded
  if (m == 1 || n == 1) {
    return 1;
  }
  cout << m << " " << n << " " << endl;
  // cout << 1 + uniquePaths(max(m - 1, 0), n) + uniquePaths(m, max(n - 1, 0));
  return uniquePaths_recursive(max(m - 1, 1), n) +
         uniquePaths_recursive(m, max(n - 1, 1));
}

int uniquePaths_2d(int m, int n) {
  vector<vector<int>> matrix(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // cout << i << " " << j << endl;
      if (i == 0 || j == 0) {
        matrix[i][j] = 1;
      } else {
        matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
      }
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return matrix[m - 1][n - 1];
}

int uniquePaths(int m, int n) { // using only 1d and optimized
  vector<int> vec_1(n, 1);
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      vec_1[j] = vec_1[j] + vec_1[j - 1];
    }
  }
  return vec_1[n - 1];
}

int main() {
  cout << uniquePaths(3, 7);
  return 0;
}
