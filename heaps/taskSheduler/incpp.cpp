#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  unordered_map<char, int> mp;
  for (char t : tasks) {
    mp[t]++;
  }
  priority_queue<pair<int, char>> pq;
  for (auto [ch, cnt] : mp) {
    pq.push({cnt, ch});
  }
  int n = 3;

  int times = 0;
  while (!pq.empty()) {
    vector<pair<int, char>> temp;

    for (int i = 0; i < n + 1; i++) {
      if (!pq.empty()) {
        auto [in, cha] = pq.top();
        cout << cha << "-->";
        pq.pop();
        if (in > 1) {
          temp.push_back({in - 1, cha});
        }
        times++;
      } else if (!temp.empty()) {
        times++;
        cout << "Idle--> ";
      }
    }
    for (auto t : temp) {
      pq.push({t.first, t.second});
    }
  }
  cout << times;
  return 0;
}
