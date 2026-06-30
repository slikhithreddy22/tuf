#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int source;
    cin >> source;

    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool updated = false;

        for (auto &e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }

        if (!updated) break;
    }

    bool hasNegativeCycle = false;

    for (auto &e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Negative weight cycle exists\n";
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
