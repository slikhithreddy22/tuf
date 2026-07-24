#include <iostream>
#include <stack>
using namespace std;
void sortInsert(stack<int> &st, int ele) {
  if (st.empty() || st.top() <= ele) {
    st.push(ele);
  } else if (ele < st.top()) {
    int top = st.top();
    st.pop();
    sortInsert(st, ele);
    st.push(top);
  }
}
void sortStack(stack<int> &st) {
  // code here
  if (st.empty())
    return;
  int top = st.top();
  st.pop();
  sortStack(st);
  sortInsert(st, top);
};
int main() {
  stack<int> st;

  st.push(41);
  st.push(3);
  st.push(32);
  st.push(2);
  st.push(11);
  sortStack(st);
  while (st.size()) {
    cout << st.top() << " ";
    st.pop();
  }
  return 0;
}
