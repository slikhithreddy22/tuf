#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector<vector<int>> &graph, vector<bool> &visited) {
  visited[n] = true;
  cout << n << " ";
  for (int neigh : graph[n]) {
    if (visited[neigh] == true) {
      continue;
    }
    dfs(neigh, graph, visited);
  }
}
int main() {
  vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5, 6}, {1},
                               {4},    {2},       {2}};
  int n = graph.size();
  vector<bool> visited(n, false);
  dfs(0, graph, visited);

  return 0;
}
