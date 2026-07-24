#include <iostream>
using namespace std;

int minMoves(int target, int maxDoubles) {
  int count = 0;
  while (target > 1) {
    if (maxDoubles) {
      if (target % 2 == 0) {
        target = target / 2;
        maxDoubles--;
        count++;
        // cout << count << " " << maxDoubles << " " << target << endl;
      } else {
        target--;
        count++;
        // cout << count << " " << maxDoubles << " " << target << endl;
      }
    } else {
      count += target - 1;
      // target = 0;
      break;
      // cout << count << " " << maxDoubles << " " << target << endl;
    }
  }
  return count;
}
int main() {
  cout << minMoves(5, 0) << endl;
  cout << minMoves(19, 2) << endl;
  cout << minMoves(10, 4) << endl;
  return 0;
}
