#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    short n, m;
    cin >> n >> m;

    vector<vector<short>> graph(n, vector<short>(m));
    vector<vector<short>> dist(n, vector<short>(m, -1));
    vector<short> dx = {1, -1, 0, 0};
    vector<short> dy = {0, 0, 1, -1};
    queue<pair<short, short>> q;

    for(short i = 0; i < n; i++){
        for(short j = 0; j < m; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 2){
                q.push({i, j});
                dist[i][j] = 0;
            }
            else if(graph[i][j] == 0){
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto [currentx, currenty] = q.front(); q.pop();
        for(short k = 0; k < 4; k++){
            short nx = currentx + dx[k];
            short ny = currenty + dy[k];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[currentx][currenty] + 1;
            q.push({nx, ny});
        }
    }

    for(short i = 0; i < n; i++){
        for(short j = 0; j < m; j++)cout << dist[i][j] << ' '; cout << '\n';
    }

    return 0;
}