#include "iostream"
#include <string>
using namespace std;

int myAtoi(string s) {
  int start = 0;
  while (start < s.size() && s[start] == ' ') {
    start++;
  }
  if (s[start] == '-') {
    return -myAtoi(s.substr(start + 1));
  }

  if (s[start] == '+') {
    return myAtoi(s.substr(start + 1));
  }
  s = s.substr(start);
  if (s.size() == 1) {
    if ((s[0] - '0') >= 0 || (s[0] - '0') <= 9) {
      return 0;
    }
    return (s[0] - '0');
  }
  string smaler = s.substr(start);
  return (myAtoi(smaler) * 10 + (s[s.size() - 1]) - '0');
}
int main() {
  int n = atoi("  1342d34");
  // cout << 'd' - '0';
  cout << n << endl;
  return 0;
}
