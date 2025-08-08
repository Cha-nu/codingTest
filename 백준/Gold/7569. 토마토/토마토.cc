#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, h;
    cin >> n >> m >> h;

    // H x M x N 순서로 배열 선언
    vector<vector<vector<short>>> box(h, vector<vector<short>>(m, vector<short>(n, -1)));
    queue<tuple<int, int, int>> q;
    
    vector<short> dx = {1, -1, 0, 0, 0, 0}; // x축
    vector<short> dy = {0, 0, 1, -1, 0, 0}; // y축
    vector<short> dz = {0, 0, 0, 0, 1, -1}; // z축
    
    int result = -1, count = 0;
    
    // H > M > N 순서로 입력값 읽기
    for (short k = 0; k < h; k++) {
        for (short i = 0; i < m; i++) {
            for (short j = 0; j < n; j++) {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1) {
                    q.push({k, i, j});
                }
                if (box[k][i][j] == 0) {
                    count++;
                }
            }
        }
    }

    // BFS 탐색
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [z, y, x] = q.front(); q.pop();
            for (short i = 0; i < 6; i++) {
                int nz = z + dz[i];
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (nz >= 0 && nz < h && ny >= 0 && ny < m && nx >= 0 && nx < n && box[nz][ny][nx] == 0) {
                    q.push({nz, ny, nx});
                    box[nz][ny][nx] = 1;
                    count--;
                }
            }
        }
        result++;
    }

    if (count > 0) {
        cout << -1;
    } else {
        cout << result;
    }
    
    return 0;
}