#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (obstacleGrid[i][j] == 1) {
        obstacleGrid[i][j] = -1;
      } else if (i == 0 || j == 0) {
        obstacleGrid[i][j] = 1;
      } else {
        obstacleGrid[i][j] =
            max(max(obstacleGrid[i][j - 1], obstacleGrid[i - 1][j]),
                obstacleGrid[i][j - 1] + obstacleGrid[i - 1][j]);
      }
    }
  }
  for (auto num : obstacleGrid) {
    for (int nu : num) {
      cout << nu << " ";
    }
    cout << endl;
  }
  return obstacleGrid[m - 1][n - 1];
}

int main() {
  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  cout << uniquePathsWithObstacles(obstacleGrid);
  return 0;
}
