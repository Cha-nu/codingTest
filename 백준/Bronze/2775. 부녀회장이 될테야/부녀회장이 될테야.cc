#include <iostream>

int main() {
    int T = 0;
    std::cin >> T;
    int dp[15][15] = {0};
    for(int i = 0; i < 15; i++){
        dp[0][i] = i;
        dp[i][1] = 1;
    }
    for(int i = 0; i < T; i++){
        int k = 0, n = 0;
        std::cin >> k >> n;
        for(int j = 0; j < k; j++){
            for(int l = 0; l < n; l++){
                if (dp[j + 1][l + 1] != 0) continue;
                dp[j + 1][l + 1] = dp[j][l + 1] + dp[j + 1][l];
            }
        }
        std::cout << dp[k][n] << "\n"; 
    }
}