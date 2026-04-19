#include <algorithm>
#include <iostream>
using namespace std;

int longest_substring(string s) {
  int cur_max = 0;
  string max_str = "";

  for (int i = 0; i < s.length(); i++) {
    if (max_str.find(s.at(i)) != string::npos) {
      size_t index = max_str.find(s.at(i));
      max_str = max_str.substr(index + 1);
      max_str += s.at(i);
      cur_max = max(cur_max, (int)max_str.length());
    } else {
      max_str += s.at(i);
      cur_max = max(cur_max, (int)max_str.length());
    }
  }

  return cur_max;
}
int main() {
  cout << longest_substring("abcabcbb") << endl;
  return 0;
}
