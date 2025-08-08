#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;
    cin >> n >> m >> h;

    vector<vector<vector<short>>> box(h, vector(m, vector<short>(n, -1)));
    queue<tuple<int, int, int>> q;
    vector<short> dx = {1, -1, 0, 0, 0, 0};
    vector<short> dy = {0, 0 , 1, -1, 0, 0};
    vector<short> dz = {0, 0, 0, 0, 1, -1};
    
    int result = -1, count = 0;
    
    for(short i = 0; i < h; i++){ // z 
        for(short j = 0; j < m; j++){ // y
            for(short k = 0; k < n; k++){ // x
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) q.push({i, j, k});
                if(box[i][j][k] == 0) count++;
            }
        }
    }

    // bfs
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [z, y, x] = q.front(); q.pop();
            for(short i = 0; i < 6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if(nx >= 0 && ny >= 0 && nz >= 0 && nx < n && ny < m && nz < h && box[nz][ny][nx] == 0){
                    q.push({nz, ny, nx});
                    box[nz][ny][nx] = 1;
                    count--;
                }
            }
        }
        result++;
    }

    if(count) cout << -1; // 0이 남아있으면
    else cout << result;
    return 0;
}