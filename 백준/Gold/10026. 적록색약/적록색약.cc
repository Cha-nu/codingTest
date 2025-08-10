#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> arr(n, vector<char>(n));
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    vector<vector<bool>> visited2(n, vector<bool> (n, false));
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) cin >> arr[i][j];
    vector<short> dx = {1, -1, 0, 0};
    vector<short> dy = {0, 0, 1, -1};

    int count = 0, count2 = 0;

    // 정상인 시야 (R, G, B 모두 구분)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                char see = arr[i][j];
                visited[i][j]= true;
                while(!q.empty()){
                    auto [currentx, currenty] = q.front(); q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = currentx + dx[k];
                        int ny = currenty + dy[k];
                        if(nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny] && arr[nx][ny] == see){
                             q.push({nx, ny});
                             visited[nx][ny] = true; // 방문 처리
                        }
                    }
                }
            }
        }
    }

    // 색약 시야 (R과 G를 구분 못함)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited2[i][j]){
                count2++;
                queue<pair<int, int>> q;
                q.push({i, j});
                char see = arr[i][j];
                visited2[i][j]= true;
                while(!q.empty()){
                    auto [currentx, currenty] = q.front(); q.pop();
                    for(int k = 0; k < 4; k++){
                        int nx = currentx + dx[k];
                        int ny = currenty + dy[k];
                        
                        // 인덱스 범위 초과 또는 이미 방문한 경우 건너뛰기
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited2[nx][ny]) continue;

                        bool same_color = false;
                        if(see == 'R' || see == 'G'){
                            if(arr[nx][ny] == 'R' || arr[nx][ny] == 'G'){
                                same_color = true;
                            }
                        } else { // see == 'B'
                            if(arr[nx][ny] == 'B'){
                                same_color = true;
                            }
                        }
                        
                        if(same_color){
                            q.push({nx, ny});
                            visited2[nx][ny] = true; // 방문 처리
                        }
                    }
                }
            }
        }
    }

    cout << count << ' ' << count2;

    return 0;
}