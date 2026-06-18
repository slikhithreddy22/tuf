#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> adj = {
      {},          // 0 unused
      {2},         // 1
      {1, 3},      // 2
      {2, 4, 9},   // 3
      {3, 5},      // 4
      {4, 6, 13},  // 5
      {5, 7, 16},  // 6
      {6, 8},      // 7
      {7, 20, 22}, // 8
      {3, 10},     // 9
      {9, 11},     // 10
      {10, 12},    // 11
      {11},        // 12
      {5, 14},     // 13
      {13, 15},    // 14
      {14},        // 15
      {6, 17},     // 16
      {16, 18},    // 17
      {17, 19},    // 18
      {18},        // 19
      {8, 21},     // 20
      {20},        // 21
      {8, 23},     // 22
      {22, 24},    // 23
      {23, 25},    // 24
      {24}         // 25
  };
  int n = adj.size() - 1;
  vector<int> degrees(26, 0);
  vector<int> leaf_nodes;
  for (int i = 1; i <= n; i++) {
    degrees[i] = adj[i].size();
    if ((degrees[i] == 0) || (degrees[i] == 1)) {
      leaf_nodes.push_back(i);
    }
  }
  cout << "leaf Nodes are : ";
  for (int node : leaf_nodes) {
    cout << node << " ";
  }
  cout << "\n";
  int count = leaf_nodes.size();
  while (count < n) {
    vector<int> leaves;
    for (int node : leaf_nodes) {
      degrees[node] = 0;
      for (int parent : adj[node]) {
        if (degrees[parent] > 0) {
          degrees[parent]--;
          if (degrees[parent] == 1) {
            leaves.push_back(parent);
          }
        }
      }
    }
    count += leaves.size();
    leaf_nodes = leaves;
    for (int node : leaf_nodes) {
      cout << node << " ";
    }
    cout << "\n";
  }
  // for (int final_leaf : leaf_nodes) {
  //   cout << final_leaf << " ";
  // }
  return 0;
}
