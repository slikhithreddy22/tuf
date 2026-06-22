#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> khans_topological_sort(vector<vector<int>> graph) {
  int n = graph.size();
  vector<int> order(n, 0);
  vector<int> indegree(n, 0);
  for (int i = 0; i < n; i++) {
    for (int at : graph[i]) {
      indegree[at] = indegree[at] + 1;
    }
  }
  queue<int> q;
  int index = 0;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    order[index++] = node;
    for (int neigh : graph[node]) {
      indegree[neigh] = indegree[neigh] - 1;
      if (indegree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }
  return order;
}
int main() {
  vector<vector<int>> graph = {
      {1, 2}, // 0 -> 1, 2
      {3},    // 1 -> 3
      {3, 4}, // 2 -> 3, 4
      {5},    // 3 -> 5
      {5},    // 4 -> 5
      {}      // 5
  }; // graph given by chatgpt
  vector<int> order = khans_topological_sort(graph);
  for (int node : order) {
    cout << node << " ";
  }
  return 0;
}
