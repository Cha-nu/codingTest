#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100001;
vector<int> lst[MAX];
int parent[MAX];
bool visited[MAX];

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int c_node = q.front(); q.pop();
        for(int next : lst[c_node]){
            if(!visited[next]){
                visited[next] = true;
                parent[next] = c_node;
                q.push(next);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; // 정점의 수
    cin >> n;
    
    // 트리는 n-1개의 간선으로 이루어져 있음
    for (int i = 0; i < n-1; i++) {
        int u, v; // 간선 (u, v)를 입력받음
        cin >> u >> v;
        
        // 무방향이므로 양쪽에 모두 연결 정보 저장
        lst[u].push_back(v);
        lst[v].push_back(u);
    }

    bfs(1);
    for(int i = 2; i < n+1; i++) cout << parent[i] << '\n';

    return 0;
}