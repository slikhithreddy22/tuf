#include <iostream>
using namespace std;

int numberOfSteps(int num) {
  int count = 0;
  while (num) {
    if (num % 2 == 0) {
      count++;
      num = num / 2;
    } else {
      num--;
      count++;
    }
  }
  return count;
}
int main() {
  cout << numberOfSteps(8);
  return 0;
}
