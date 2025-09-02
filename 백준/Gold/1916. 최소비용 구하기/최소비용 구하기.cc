#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> dist(n+1, 1e9);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; // 거리 비용
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int a, b;
    cin >> a >> b;
    dist[a] = 0;

    pq.push({0, a});

    while(!pq.empty()){
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if(current_dist > dist[current_node]) continue;
        
        for(auto& e : adj[current_node]){
            int next_node = e.first;
            int weg = e.second;
        
        if(dist[current_node] + weg < dist[next_node]){
            dist[next_node] = dist[current_node] + weg;
            pq.push({dist[next_node], next_node});
            }
        }
    }
    cout << dist[b];
    return 0;
}