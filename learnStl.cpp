#include <bits/stdc++.h>
using namespace std;

// 1.functions
// while defining function we need to take care of 2 things return type and
// function name the return type must be mentioned if there infront of function
// name else keep it as void
void printMyName(string s) { cout << "The name is " << s << endl; }
int sumOf(int x, int y) { return x + y; }
void printLines(string s) {
  const std::string red("\033[1;31m");
  const std::string green("\033[1;32m");
  const std::string reset("\033[0m");
  cout << green << "---------------------- " << s << " ----------------------"
       << reset << endl;
}
int main() {
  printLines("1.Functions");
  printMyName("Likhith Reddy");
  cout << "The sum of 2 and 3 is " << sumOf(2, 3) << endl;
  printLines("1.Functions");
  return 0;
}
