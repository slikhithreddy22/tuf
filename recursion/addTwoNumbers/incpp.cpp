#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *first = l1;
  ListNode *second = l2;
  int sum = first->val + second->val; // 18
  bool remaining = false;
  if (sum > 9) {
    remaining = true;
    sum = sum - 10; // 8
  }
  ListNode *ans = new ListNode(sum);
  ListNode *tail = ans;
  first = first->next;
  second = second->next;
  while (first != nullptr && second != nullptr) {
    // cout << first->val << " " << second->val << endl;
    sum = first->val + second->val;
    if (remaining) {
      sum++;
    }
    remaining = false;
    if (sum > 9) {
      remaining = true;
      sum = sum - 10;
    }
    tail->next = new ListNode(sum);
    tail = tail->next;
    first = first->next;
    second = second->next;
  }
  while (first != nullptr) {
    sum = first->val;
    if (remaining) {
      sum++;
    }
    remaining = false;
    if (sum > 9) {
      remaining = true;
      sum = sum - 10;
    }
    tail->next = new ListNode(sum);
    tail = tail->next;
    first = first->next;
  }
  while (second != nullptr) {
    sum = second->val;
    if (remaining) {
      sum++;
    }
    remaining = false;
    if (sum > 9) {
      remaining = true;
      sum = sum - 10;
    }
    tail->next = new ListNode(sum);
    tail = tail->next;
    second = second->next;
  }
  if (remaining) {
    tail->next = new ListNode(1);
  }
  return ans;
}

int main() {
  ListNode *l1 = new ListNode(9);
  l1->next = new ListNode(9);
  l1->next->next = new ListNode(9);
  l1->next->next->next = new ListNode(9);
  l1->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next = new ListNode(9);
  l1->next->next->next->next->next->next = new ListNode(9);

  ListNode *l2 = new ListNode(9);
  l2->next = new ListNode(9);
  l2->next->next = new ListNode(9);
  l2->next->next->next = new ListNode(9);
  ListNode *ans = addTwoNumbers(l1, l2);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  return 0;
}
