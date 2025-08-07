#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<short>> box(m, vector<short>(n, -1));
    queue<pair<int, int>> q;
    vector<short> dx = {1, -1, 0, 0};
    vector<short> dy = {0, 0 , 1, -1};
    
    int result = -1, count = 0;
    
    for(short i = 0; i < m; i++){
        for(short j = 0; j < n; j++){
            cin >> box[i][j];
            if(box[i][j] == 1) q.push({i, j});
            if(box[i][j] == 0) count++;
        }
    }

    // bfs
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [x, y] = q.front(); q.pop();
            for(short i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || box[nx][ny] == 1 || box[nx][ny] == -1) continue;
                q.push({nx, ny});
                box[nx][ny] = 1;
                count--;
            }
        }
        result++;
    }

    if(count) cout << -1; // 0이 남아있으면
    else cout << result;
    return 0;
}