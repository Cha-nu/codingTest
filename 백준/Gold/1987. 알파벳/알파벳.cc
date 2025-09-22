#include <iostream>
#include <vector>

using namespace std;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<bool> visited(26, false);

int result = 1;

int sol(int r, int c, int current_row, int current_col, int cnt, vector<vector<char>>& graph){ // 백트래킹
    result = max(result, cnt);
    for(int i = 0; i < 4; i++){
        int next_row = current_row + dx[i];
        int next_col = current_col + dy[i];

        if(next_row < 0 || next_col < 0 || next_row >= r || next_col >= c) continue; // 경계조건

        if(!visited[(int)graph[next_row][next_col]-65]){
            visited[(int)graph[next_row][next_col]-65] = true;
            sol(r, c, next_row, next_col, cnt+1, graph);
            visited[(int)graph[next_row][next_col]-65] = false;
        }
    }
    return cnt;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    vector<vector<char>> graph(r, vector<char> (c, ' '));
    

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char a;
            cin >> a;
            graph[i][j] = a;
        }
    }

    visited[(int)graph[0][0]-65] = true;
    sol(r, c, 0, 0, 1, graph);
    cout << result;
    return 0;
}

