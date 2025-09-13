#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// 무한대 값 정의
const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>>& adj){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> dist (n+1, INF);
    
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

    short n;
    int e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> adj(n+1);
    while(e--){
        short a, b, c;
        cin >> a >> b >> c;
        // Correctly store the adjacency list and add bidirectional edges
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int v1, v2;
    cin >> v1 >> v2;

    vector<int> dist1 = dijkstra(1, n, adj);
    vector<int> dist_v1 = dijkstra(v1, n, adj);
    vector<int> dist_v2 = dijkstra(v2, n, adj);

    long long path1 = -1, path2 = -1;

    // Calculate path 1: 1 -> v1 -> v2 -> N
    if (dist1[v1] != INF && dist_v1[v2] != INF && dist_v2[n] != INF) {
        path1 = (long long)dist1[v1] + dist_v1[v2] + dist_v2[n];
    }
    
    // Calculate path 2: 1 -> v2 -> v1 -> N
    if (dist1[v2] != INF && dist_v2[v1] != INF && dist_v1[n] != INF) {
        path2 = (long long)dist1[v2] + dist_v2[v1] + dist_v1[n];
    }

    long long result;
    if (path1 == -1 && path2 == -1) {
        result = -1;
    } else if (path1 == -1) {
        result = path2;
    } else if (path2 == -1) {
        result = path1;
    } else {
        result = min(path1, path2);
    }
    
    cout << result;

    return 0;
}