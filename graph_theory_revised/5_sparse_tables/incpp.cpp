#include "iostream"
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> sparseTable(vector<int> &arr) {
  int n = arr.size();
  int k = log2(n) + 1;
  vector<vector<int>> st(k, vector<int>(n));
  for (int i = 0; i < n; i++) {
    st[0][i] = arr[i];
  }
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < (n - (pow(2, i) - 1)); j++) {
      st[i][j] = min(st[i - 1][j], st[i - 1][j + pow(2, i - 1)]);
    }
  }

  return st;
}

int main() {
  vector<int> v = {4, 2, 3, 7, 1, 5, 3, 3, 9, 6, 7, -1, 4};
  vector<vector<int>> st = sparseTable(v);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < v.size() - pow(2, i) + 1; j++) {
      cout << st[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
