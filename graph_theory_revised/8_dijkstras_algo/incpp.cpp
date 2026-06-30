// some notes about priority queue
// implementation : priority_queue<T,container,comp>pq;
// for max heap the default one like priority_queue<int> pq;
// for min heap priority_queue<int,vector<int>,greater<int>> pq;

#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> dijstra(vector<vector<int>> graph, int n, int s) {
  vector<bool> visited(n, false);
  vector<int> dist(n, INT_MAX);
  dist[s] = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.emplace(s, 0);
  return dist;
}
int main() {
  cout << "Hello world!";
  return 0;
}
