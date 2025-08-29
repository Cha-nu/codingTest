#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> sticker[i][j];
            }
        }

        // Base case for n = 1
        if (n == 1) {
            cout << max(sticker[0][0], sticker[1][0]) << "\n";
            continue;
        }

        vector<vector<long long>> dp(n, vector<long long>(3, 0));

        // Initialize DP table for the first column
        dp[0][0] = 0;
        dp[0][1] = sticker[0][0];
        dp[0][2] = sticker[1][0];

        // Fill the DP table from the second column
        for (int i = 1; i < n; i++) {
            dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + sticker[0][i];
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + sticker[1][i];
        }

        cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << "\n";
    }

    return 0;
}