#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

int main() {
  cout << "Hello world!";
  Node firstNode;
  firstNode.data = 10;
  firstNode.next = nullptr;
  return 0;
}
