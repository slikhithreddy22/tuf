#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int titleToNumber(string columnTitle) {
  cout << columnTitle.length() << endl;
  int n = columnTitle.length() - 1;
  int sum = 0;
  for (int ch : columnTitle) {
    sum += ((ch - 64) * pow(26, n--));
  }
  return sum;
}
int main() {
  cout << titleToNumber("AB");
  return 0;
}
