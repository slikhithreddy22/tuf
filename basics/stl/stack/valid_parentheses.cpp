#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if (c == '(' || c == '[' || c == '{') {
      st.push(c);
    } else {
      if (st.empty()) {
        cout << "Parenthesis not matched" << endl;
        return 0;
      }
      char top = st.top();
      if ((c == ')' && top == '(') || (c == ']' && top == '[') ||
          (c == '}' && top == '{')) {
        st.pop();
      } else {
        cout << "Parenthesis not matched" << endl;
        return 0;
      }
    }
  }
  if (st.empty()) {
    cout << "Parenthesis matched" << endl;
  } else {
    cout << "Parenthesis not matched" << endl;
  }

  return 0;
}
