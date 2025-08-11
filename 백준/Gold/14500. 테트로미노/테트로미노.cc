#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    // 모든 테트로미노 형태 (각 블록의 상대 좌표를 포함, 기준점은 (0,0))
    vector<vector<pair<int,int>>> shapes = {
        // I
        {{0,0},{0,1},{0,2},{0,3}},
        {{0,0},{1,0},{2,0},{3,0}},

        // O
        {{0,0},{0,1},{1,0},{1,1}},

        // T
        {{0,0},{0,1},{0,2},{1,1}},
        {{0,0},{1,0},{2,0},{1,1}},
        {{0,0},{0,1},{0,2},{-1,1}},
        {{0,0},{1,0},{2,0},{1,-1}},

        // L (8가지 형태)
        {{0,0},{1,0},{2,0},{2,1}},
        {{0,0},{0,1},{0,2},{1,2}},
        {{0,0},{1,0},{2,0},{0,1}},
        {{0,0},{0,1},{0,2},{-1,0}},
        {{0,0},{1,0},{2,0},{2,-1}},
        {{0,0},{0,1},{0,2},{-1,2}},
        {{0,0},{1,0},{2,0},{0,-1}},
        {{0,0},{0,1},{0,2},{1,0}},

        // Z (4가지 형태, S 포함)
        {{0,0},{1,0},{1,1},{2,1}},
        {{0,0},{0,1},{-1,1},{-1,2}},
        {{0,0},{1,0},{1,-1},{2,-1}},
        {{0,0},{0,1},{1,1},{1,2}}
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(auto &shape : shapes){
                int sum = 0;
                bool check = true;
                for(auto [dx, dy] : shape){
                    int nx = i + dx;
                    int ny = j + dy;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                        check = false;
                        break;
                    }
                    sum += arr[nx][ny];
                }
                if(check) result = max(result, sum);
            }
        }
    }
    cout << result;
    return 0;
}