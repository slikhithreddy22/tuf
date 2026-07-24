#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs) {
  vector<int> dp(366, 0);
  for (int i = 1; i < 366; i++) {
    auto it = find(days.begin(), days.end(), i);
    if (it != days.end()) {
      dp[i] =
          min(costs[0] + dp[max(i - 1, 0)],
              min(costs[1] + dp[max(i - 7, 0)], costs[2] + dp[max(i - 30, 0)]));
    } else {
      dp[i] = dp[i - 1];
    }
    return dp[365];
  };
}

int main() { return 0; }
