#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    vector<pair<int, int>> val;

    for(int i = 1; i <= n; i++){
        int w, v;
        cin >> w >> v;
        val.push_back({w, v});
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int weight = val[i-1].first;
            if (weight > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                int value = val[i-1].second;
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weight] + value);
            }
            
        }
    }

    cout << dp[n][k];
    return 0;
}