#include <vector>
using namespace std;

struct TreeNode {
  int node;
  TreeNode *parent;
  vector<TreeNode *> children;
  TreeNode(int n, TreeNode *parent = nullptr) {
    this->node = n;
    this->parent = parent;
  }
};
int main() {}
