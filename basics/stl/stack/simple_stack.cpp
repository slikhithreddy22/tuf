#include <iostream>
#include <stack>
using namespace std;

int main() {
  string action;
  stack<int> st;

  while (cin >> action && action != "exit") {
    if (action == "push") {
      int n;
      cin >> n;
      st.push(n);
      cout << "ok" << endl;
    } else if (action == "pop") {
      cout << st.top() << endl;
      st.pop();
    } else if (action == "back") {
      cout << st.top() << endl;
    } else if (action == "size") {
      cout << st.size() << endl;
    } else if (action == "clear") {
      while (!st.empty())
        st.pop();
      cout << "ok" << endl;
    }
  }

  return 0;
}
