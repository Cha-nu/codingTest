#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    // 인접리스트                  
    vector<vector<pair<int, int>>> adj(N+1);
    
    vector<int> dist(N+1, INF);
    
    for(vector<int>& r : road)
    {
        int u = r[0];
        int v = r[1];
        int w = r[2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    priority_queue<pair<int, int>> pq; // 코스트, 노드
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int cost = -pq.top().first; 
        int current = pq.top().second;
        pq.pop();
        
        if(cost > dist[current]) continue;
        
        for(auto& e : adj[current])
        {
            int next_cost = e.second;
            int next_node = e.first;
            
            if(dist[next_node] > cost + next_cost)
            {
                dist[next_node] = cost + next_cost;
                pq.push({-(cost + next_cost), next_node});
            }
        }
    
    }
    for(int d : dist) if(d <= K) ++answer;
    
    return answer;
}