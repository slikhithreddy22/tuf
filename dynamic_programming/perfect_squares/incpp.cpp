#include <algorithm>
#include <climits>
#include <endian.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> perfect_Squares(int n) {
  vector<int> ps;
  ps.push_back(1);
  for (int i = 2; i * i <= n; i++) {
    ps.push_back(i * i);
  }
  return ps;
}
int numSquares_recur(int n, vector<int> &ps) {
  if (n == 1) {
    return 1;
  }
  int out = INT_MAX;
  vector<int> ans_store;
  for (int sq : ps) {
    cout << "sq is : " << sq << " ";
    if (sq <= n) {
      int ans = 1 + numSquares_recur(n - sq, ps);
      ans_store.push_back(ans);
    }
  }
  cout << endl;
  for (int ans : ans_store) {
    cout << ans << " ";
    if (ans < out) {
      out = ans;
    }
  }
  cout << endl;
  return out;
}

int numSquares(int n) {
  vector<int> dp;
  vector<int> ps = perfect_Squares(n);
  auto it = find(ps.begin(), ps.end(), n);
  if (it != ps.end()) {
    return 1;
  }
  dp.push_back(0);
  dp.push_back(1);
  for (int k = 2; k <= n; k++) {
    vector<int> ans;
    for (int sq : ps) {
      if (k >= sq) {
        ans.push_back(1 + dp[max(0, k - sq)]);
      }
    }
    dp.push_back(INT_MAX);
    for (int a : ans) {
      if (a < dp[k]) {
        dp[k] = a;
      }
    }
  }
  return dp[n];
}
int main() {
  vector<int> ps = {1, 4, 9};
  cout << numSquares(12);
  return 0;
}
