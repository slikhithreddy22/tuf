#include "iostream"
using namespace std;
#include <vector>

int rob(vector<int> &nums) {
  vector<int> mem(nums.size() + 1, 0);
  mem[0] = 0;
  mem[1] = nums[0];
  for (int i = 0; i < nums.size(); i++) {
    mem[i + 1] = max(mem[i - 1] + nums[i], mem[i]);
  }
  return mem[nums.size()];
}
int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << rob(nums);
  return 0;
}
