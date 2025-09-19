#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist (n+1, INF);
    vector<bool> visited(n+1, false);

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int current_node = pq.top().second;
        int val = pq.top().first;
        pq.pop();

        if(val > dist[current_node]) continue;

        for(const auto& edge : adj[current_node]){
            int neighbor = edge.first;
            int weight = edge.second;

            if((long long)dist[current_node] + weight < dist[neighbor]){
                dist[neighbor] = dist[current_node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    return dist;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short v;
    cin >> v;

    vector<vector<pair<int, int>>> adj(v+1);
    if (v == 1) { // 노드가 1개일 경우 지름은 0
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < v - 1; ++i) { // v-1개의 간선 입력
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int>dist1 = dijkstra(1, v, adj);

    int val = 0;
    int idx = 0;
    for (int i = 1; i <= v; i++) {
        if (val < dist1[i]) {
            val = dist1[i]; // You need to update the max value
            idx = i;
        }
    }

    vector<int> dist2 = dijkstra(idx, v, adj);

    auto result = max_element(dist2.begin() + 1, dist2.end());
    cout << *result;

    return 0;
}