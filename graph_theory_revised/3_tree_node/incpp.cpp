#include "../4_tree_centre/incpp.cpp"
#include <algorithm>
#include <string>
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

  // void add_children(vector<TreeNode *> &nodes) {
  //   for (TreeNode *node : nodes) {
  //     this->children.push_back(node);
  //   }
  // }
  void add_children(TreeNode *node) { this->children.push_back(node); }

  TreeNode *get_parent() { return this->parent; }
  vector<TreeNode *> get_children() { return this->children; }
};

TreeNode *rootTree(int rootId) { return new TreeNode(rootId); }

void buildTree(vector<vector<int>> &graph, TreeNode *node) {
  for (int neighbour : graph[node->node]) {
    if (node->parent && node->parent->node == neighbour) {
      continue;
    }
    TreeNode *child = new TreeNode(neighbour, node);
    node->add_children(child);
    buildTree(graph, child);
  }
}

string encode(TreeNode *node) {
  if (node->children.size() == 0) {
    return "()";
  }
  vector<string> encodings;
  string brackets;
  for (TreeNode *child : node->children) {
    encodings.push_back(encode(child));
  }
  sort(encodings.begin(), encodings.end());
  string combined = "";
  for (string s : encodings) {
    combined += s;
  }
  brackets += "(" + combined + ")";
  return brackets;
}

bool isomorphism(vector<vector<int>> graph1, vector<vector<int>> graph2) {
  vector<int> treeCenters1 = tree_center(graph1);
  vector<int> treeCenters2 = tree_center(graph2);

  TreeNode *root1 = rootTree(treeCenters1[0]);
  buildTree(graph1, root1);
  string encoded1 = encode(root1);
  for (int root : treeCenters2) {
    TreeNode *root2 = rootTree(root);
    buildTree(graph2, root2);
    string encode2 = encode(root2);
    if (encoded1 == encode2) {
      return true;
    }
  }
  return false;
}
int main() {}
