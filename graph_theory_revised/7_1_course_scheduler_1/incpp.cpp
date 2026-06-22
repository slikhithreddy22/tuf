#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> buildAdjacencyList(int numCourses,
                                       vector<vector<int>> &prerequisites) {
  vector<vector<int>> adjacency_list(numCourses, vector<int>{});
  for (int i = 0; i < prerequisites.size(); i++) {
    vector<int> set = prerequisites[i];
    adjacency_list[set[1]].push_back(set[0]);
  }
  return adjacency_list;
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
  vector<int> inDegrees(numCourses, 0);
  vector<vector<int>> adjacency_list =
      buildAdjacencyList(numCourses, prerequisites);
  for (int i = 0; i < numCourses; i++) {
    for (int at : adjacency_list[i]) {
      inDegrees[at] = inDegrees[at] + 1;
    }
  }

  queue<int> q;
  for (int i = 0; i < numCourses; i++) {
    if (inDegrees[i] == 0) {
      q.push(i);
    }
  }
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (int neigh : adjacency_list[node]) {
      inDegrees[neigh] = inDegrees[neigh] - 1;
      if (inDegrees[neigh] == 0) {
        q.push(neigh);
      }
    }
  }
  for (int degree : inDegrees) {
    if (degree != 0) {
      return false;
    }
  }
  return true;
}
int main() { return 0; }
