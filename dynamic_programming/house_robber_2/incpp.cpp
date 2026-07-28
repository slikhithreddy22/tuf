#include "iostream"
using namespace std;
#include <vector>

int rob(vector<int> &nums) {
  vector<int> mem(nums.size() + 1, 0);
  mem[0] = 0;
  mem[1] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    mem[i + 1] = max(mem[i - 1] + nums[i], mem[i]);
  }
  return mem[nums.size()];
}
int main() {
  vector<int> nums = {1, 3, 2, 1};
  vector<int> first(nums.begin(), nums.end() - 1);
  vector<int> second(nums.begin() + 1, nums.end());
  cout << max(rob(first), rob(second));
  return 0;
}
