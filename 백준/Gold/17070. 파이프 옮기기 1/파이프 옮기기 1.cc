#include <iostream>
#include <vector>

using namespace std;

long cnt = 0;
short n;

// 밀기만 하기 & 회전하면서 밀기

void solution(int r, int c, vector<vector<int>>& home, int state){ // 가로 : 0, 가로대각선 : 1, 세로 : 2
    if(r == n-1 && c == n-1){ // 끝부분 n,n 도착
        cnt++;
        return;
    }
    if(state == 0){ // 가로
        if(c+1 < n && !home[r][c+1]) solution(r, c+1, home, state); // 밀기
        state = 1; // 회전시키고 민다.
        if(r+1 < n && c+1 < n && !home[r+1][c] && !home[r][c+1] && !home[r+1][c+1]) solution(r+1, c+1, home, state);
    }
    else if(state == 1){ // 대각선
        if(r+1 < n && c+1 < n && !home[r+1][c] && !home[r][c+1] && !home[r+1][c+1]) solution(r+1, c+1, home, state);
        state = 0; // 가로 회전
        if(c+1 < n && !home[r][c+1]) solution(r, c+1, home, state);
        state = 2; // 세로 회전
        if(r+1 < n && !home[r+1][c]) solution(r+1, c, home, state);
    }
    else if(state == 2){ // 세로
        if(r+1 < n && !home[r+1][c]) solution(r+1, c, home, state);
        state = 1;// 회전시키고 민다.
        if(r+1 < n && c+1 < n && !home[r+1][c] && !home[r][c+1] && !home[r+1][c+1]) solution(r+1, c+1, home, state);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<vector<int>> home(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> home[i][j];
    solution(0, 1, home, 0);
    cout << cnt;
    return 0;
}