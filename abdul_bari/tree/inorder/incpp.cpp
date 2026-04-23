#include <cstddef>
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  Node(int value) {
    data = value;
    left = right = nullptr;
  }
};

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(Node *root) {
  if (root != NULL) {
    postorder(root->right);
    postorder(root->left);
    cout << root->data << " ";
  }
}
int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(5);
  root->left->left = new Node(4);
  inorder(root);
  cout << endl;
  preorder(root);
  cout << endl;
  postorder(root);
  cout << endl;
  return 0;
}
