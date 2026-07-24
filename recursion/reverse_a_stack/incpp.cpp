#include <iostream>
#include <stack>
using namespace std;

void insert_stack(stack<int> &st, int ele) {
  if (st.empty()) {
    st.push(ele);
    return;
  }
  int top = st.top();
  st.pop();
  insert_stack(st, ele);
  st.push(top);
}
void reverseStack(stack<int> &st) {
  // code here
  if (st.empty())
    return;
  int top = st.top();
  st.pop();
  reverseStack(st);
  insert_stack(st, top);
}

int main() {}
