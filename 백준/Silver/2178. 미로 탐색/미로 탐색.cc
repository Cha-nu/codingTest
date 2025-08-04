#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<short>> miro(n, vector<short>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<short> dx = {1, -1, 0, 0}; // 상하좌우
    vector<short> dy = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            miro[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int count = 1;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x == n - 1 && y == m - 1) {
                cout << count << '\n';
                return 0;
            }

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(visited[nx][ny]) continue;
                if(miro[nx][ny] == 0) continue;

                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        count++;
    }

    cout << -1 << '\n'; // 도달 못한 경우
    return 0;
}
