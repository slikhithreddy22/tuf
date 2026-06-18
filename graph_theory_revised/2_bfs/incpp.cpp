#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited) {
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    cout << current << " ";

    for (int neigh : graph[current]) {
      if (visited[neigh]) {
        continue;
      }
      visited[neigh] = true;
      q.push(neigh);
    }
  }
  // for (int x : current_level) {
  //   cout << x << " ";
  // }
}
int main() {
  vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5, 6}, {1},
                               {4},    {2},       {2}};
  int len = graph.size();
  vector<bool> visited(len, false);
  bfs(0, graph, visited);
}
