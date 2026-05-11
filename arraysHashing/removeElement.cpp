#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val) {
  int left = 0;
  int right;
  for (right = 0; right < nums.size(); right++) {
    if (nums[left] == val) {
      if (nums[right] != val) {
        swap(nums[left], nums[right]);
        left++;
      }
    } else {
      left++;
    }
  }
  cout << "right --" << right << " left -- " << left << endl;
  return right - left;
}
int main() {
  vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  removeElement(nums, val);
  for (int n : nums) {
    cout << n << " ";
  }
  return 0;
}
