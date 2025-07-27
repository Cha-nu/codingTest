#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> stair(n);
    vector<vector<int>> memo(n+1, vector<int>(2)); // n번째 계단까지 갈때 얻을 수 있는 가장 큰 점수

    for(int i = 0; i < n; i++) cin >> stair[i];

    memo[0][0] = 0;
    memo[0][1] = 0;
    memo[1][0] = stair[0];
    memo[1][1] = stair[0];

    for(int i = 2; i <= n; i++){
        memo[i][0] = max(memo[i-2][0], memo[i-2][1]) + stair[i-1];
        memo[i][1] = memo[i-1][0] + stair[i-1];
    }

    cout << max(memo[n][0], memo[n][1]);
    return 0;
}