#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short v, k;
    int e;
    cin >> v >> e >> k;

    vector<vector<pair<int, int>>> adj(v+1);
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> dist (v+1, INF);
    dist[k] = 0;
    pq.push({0, k});
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
    for(int i = 1; i <= v; i++){
        if(dist[i] < INF) cout << dist[i] << '\n';
        else cout << "INF\n";
    }
    
}