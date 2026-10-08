#include "iostream"
using namespace std;
#include <vector>

int rob(vector<int> &nums) {
    int n = nums.size();
           if (n == 1){
               return nums[0];
           }
           int first = nums[0];
           int second = max(nums[0],nums[1]);
           int ans;
           for(int i = 2;i<n;i++){
               ans = max(first+nums[i],second);
               first = second;
               second = ans;
           }
           return max(first,second);
}
int main() {
  vector<int> nums = {1, 2, 3, 4};
  cout << rob(nums);
  return 0;
}
