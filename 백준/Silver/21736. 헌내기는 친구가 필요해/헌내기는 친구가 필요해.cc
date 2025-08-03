#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<char>> campus(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<int> dx = {1, -1, 0, 0}; // 상하좌우
    vector<int> dy = {0, 0, 1, -1};
    queue<int> q;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> campus[i][j];
            if (campus[i][j] == 'I'){ 
                q.push(i); 
                q.push(j);
            }
        }
    }

    while(!q.empty()){
        int currentx = q.front(); q.pop();
        int currenty = q.front(); q.pop();

        if(visited[currentx][currenty]) continue;
        visited[currentx][currenty] = 1;

        if(campus[currentx][currenty] == 'P') count++;

        for(int i = 0; i < 4; i++){
            int nx = currentx + dx[i];
            int ny = currenty + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny] || campus[nx][ny] == 'X') continue;

            q.push(nx);
            q.push(ny);
        }
    }

    if (count == 0) cout << "TT\n";
    else cout << count << '\n';

    return 0;
}
