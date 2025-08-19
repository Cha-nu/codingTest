#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// short result = 1e9;

// void solv(short depth, short sum, short n, vector<vector<short>> &rgb, vector<vector<bool>>& visited){
//     if(depth == n){
//         result = min(result, sum);
//         return;
//     }
//     for(short i = 0; i < 3; i++){ // r g b back tracking 이용
//         if(visited[depth][i]) continue;
//         sum += rgb[depth][i];
//         visited[depth][i] = true;
//         if(depth+1 < n) visited[depth+1][i] = true;
//         solv(depth+1, sum, n, rgb, visited);
//         sum -= rgb[depth][i];
//         visited[depth][i] = false;
//         if(depth+1 < n) visited[depth+1][i] = false;
//     }

// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int n;
//     cin >> n;
//     vector<vector<short>> rgb(n, vector<short>(3));
//     vector<vector<bool>> visited(n, vector<bool>(3, false));

//     for(int i = 0; i < n; i++) for(int j = 0; j < 3; j++) cin >> rgb[i][j];

//     // n개의 집을 최소의 비용으로 색칠해야함
//     // 최솟값을 찾아 색칠하는 경우 N번 집과 N-1, N+1은 색칠하면 안된다.

//     solv(0, 0, n, rgb, visited);
//     cout << result;
//     return 0;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short n;
    cin >> n;
    vector<vector<int>> rgb(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3, 0));

    for(short i = 0; i < n; i++) cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];

    for(int i = 1; i < n; i++){
        dp[i][0] = rgb[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = rgb[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = rgb[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    int result = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    cout << result;
    return 0;
}