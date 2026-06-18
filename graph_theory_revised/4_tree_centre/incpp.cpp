#include <iostream>
#include <vector>
using namespace std;

vector<int> tree_center(vector<vector<int>> graph) {
  int n = graph.size();
  vector<int> degrees(n, 0);
  vector<int> leaves;
  for (int i = 0; i < n; i++) {
    degrees[i] = graph[i].size();
    if ((degrees[i] == 1) || (degrees[i] == 0)) {
      leaves.push_back(i);
    }
  }
  int count = leaves.size();
  while (count < n) {
    vector<int> new_leaves;
    for (int leaf : leaves) {
      for (int neigh : graph[leaf]) {
        degrees[neigh]--;
        if (degrees[neigh] == 1) {
          new_leaves.push_back(neigh);
        }
      }
    }
    count += new_leaves.size();
    leaves = new_leaves;
  }
  return leaves;
}
int main() {
  vector<vector<int>> graph = {{1, 2, 3}, {0, 4, 5}, {0, 6, 7}, {0},
                               {1, 8},    {1},       {2},       {2, 9},
                               {4, 10},   {7, 11},   {8, 12},   {9, 13},
                               {10, 14},  {11, 15},  {12},      {13}};
  vector<int> centers = tree_center(graph);
  for (int center : centers) {
    cout << center << " ";
  }
  return 0;
}
