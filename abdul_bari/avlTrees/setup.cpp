#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

class Node {
public:
  int val;
  int height;
  Node *left;
  Node *right;

  Node(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }

  int h(Node *root) {
    if (!root)
      return 0;
    return root->height;
  }

  int getBalance(Node *root) {
    if (!root)
      return 0;
    return h(root->left) - h(root->right);
  }

  void update(Node *root) {
    root->height = 1 + max(h(root->left), h(root->right));
  }

  Node *RightRotate(Node *y) {
    Node *x = new y->left;
    Node *T1 = new x->left;

    x->right = y;
  }
};
