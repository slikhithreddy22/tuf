#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int data, Node *next = nullptr) {
    this->data = data;
    this->next = next;
  }
};

Node *reverse_linked(Node *head) {
  Node *prev = nullptr;
  Node *curr = head;
  while (curr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  };
  return prev;
}
void reorder_students(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast = fast->next;

  Node *secStart = slow->next;
  slow->next = nullptr;
  Node *last = reverse_linked(secStart);
  slow->next = last;
  Node *curr = head;
  while (curr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  Node *head = new Node(1);
  Node *curr = head;

  for (int i = 2; i < 11; i++) {
    curr->next = new Node(i);
    curr = curr->next;
  }
  reorder_students(head);
  // Node *node = reverse_linked(head);
  // cout << node->data;
  return 0;
}
