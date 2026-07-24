#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount) {
  vector<int> mem(amount + 1, amount + 1);
  mem[0] = 0;
  for (int j = 1; j <= amount; j++) {
    for (int i = 0; i < coins.size(); i++) {
      if (coins[i] <= j) {
        mem[j] = min(mem[j], mem[j - coins[i]] + 1);
      }
    }
  }
  if (mem[amount] == amount + 1) {
    return -1;
  }
  return mem[amount];
}
int main() {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << coinChange(coins, amount);
  return 0;
}
