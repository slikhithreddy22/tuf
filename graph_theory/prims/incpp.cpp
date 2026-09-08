#include "bits/stdc++.h"
using namespace std;

int prim(vector<vector<pair<int,int>>> &graph, int start){
    vector<bool> visited(v,false);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>
        pq;
    vector<pair<int,int>> mst;
    total_cost = 0;
    pq.push({0,0});
    while (!pq.empty()){
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;
        total_cost+=weight;
        for (auto [v,edgeWeight : graph[u]){
            if (!visited[v])
                pq.push({edgeWeight,v});
        }
    }
    return total_cost;
}
int main(){
    return 0;
}
