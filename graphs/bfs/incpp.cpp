#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<vector<pair<int, int>>> graph) {
  vector<bool> discovered(graph.size(), false);
  vector<vector<int>> bfs_vec;
  queue<int> q;
  char start = 0;
  discovered[start] = true;
  q.push(start);
  while (!q.empty()) {
    char top = q.front();
    q.pop();
    vector<int> level;
    for (auto neighbor : graph[top]) {
      if (!discovered[neighbor.first]) {
        discovered[neighbor.first] = true;
        level.push_back(neighbor.first);
        q.push(neighbor.first);
      }
    }
    bfs_vec.push_back(level);
  }
}
int main() {
  const int V = 12;

  // 0=A, 1=B, 2=C, 3=D, 4=E, 5=F,
  // 6=G, 7=H, 8=I, 9=J, 10=K, 11=L

  vector<vector<pair<int, int>>> graph(V);

  auto addEdge = [&](int u, int v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  };

  addEdge(0, 1, 4); // A-B
  addEdge(0, 2, 2); // A-C
  addEdge(0, 3, 7); // A-D

  addEdge(1, 4, 5); // B-E
  addEdge(1, 5, 3); // B-F

  addEdge(2, 6, 6); // C-G
  addEdge(2, 7, 4); // C-H

  addEdge(3, 8, 2); // D-I

  addEdge(4, 9, 8); // E-J

  addEdge(5, 6, 1);  // F-G
  addEdge(5, 10, 7); // F-K

  addEdge(6, 11, 5); // G-L

  addEdge(7, 8, 3); // H-I

  addEdge(8, 9, 4); // I-J

  addEdge(9, 10, 2); // J-K

  addEdge(10, 11, 3); // K-L

  // Print the graph
  for (int i = 0; i < V; i++) {
    cout << char('A' + i) << " : ";
    for (auto [neighbor, weight] : graph[i]) {
      cout << "(" << char('A' + neighbor) << ", " << weight << ") ";
    }
    cout << '\n';
  }

  return 0;
}
