#include <stdio.h>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int left, right, zeroes, maxSum;
  left = 0;
  right = 0;
  zeroes = 0;
  maxSum = 0;
  while (right < nums.size()) {
    if (nums[right] == 0) {
      zeroes++;
    }
    if (zeroes > k) {
      if (nums[left] == 0) {
        zeroes--;
      }
      left++;
    }
    if (zeroes <= k) {
      maxSum = max(right - left + 1, maxSum);
    }
    right++;
  }
  return maxSum;
}

int main() {
  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  longestOnes(nums, 3);
  return 0;
}
