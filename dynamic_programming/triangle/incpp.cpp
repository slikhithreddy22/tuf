#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
  int n = triangle.size();
  // cout << n;
  for (int i = 1; i < n; i++) {
    triangle[i][0] += triangle[i - 1][0];
    int j;
    for (j = 1; j < i; j++) {
      triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
    }
    triangle[i][j] += triangle[i - 1][j - 1];
  }
  for (auto vec : triangle) {
    for (int num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  int mini = triangle[n - 1][0];
  for (int num : triangle[n - 1]) {
    if (num < mini) {
      mini = num;
    }
  }
  return mini;
}

int main() {
  vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  minimumTotal(triangle);
  return 0;
}
