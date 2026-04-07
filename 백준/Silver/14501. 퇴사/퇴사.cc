#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> sangdam (n, vector<int>(2));
    vector<int> dp(n+1);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        sangdam[i][0] = a;
        sangdam[i][1] = b;
    }


    for (int i = 0; i < n; i++) {
        // 1. 현재까지의 최댓값을 다음 날로 전파 (오늘 상담을 안 하는 경우)
        if (i + 1 <= n) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
        }

        // 2. 오늘 상담을 하는 경우 (퇴사 전까지 끝날 때만)
        int finish_day = i + sangdam[i][0];
        if (finish_day <= n) {
            dp[finish_day] = max(dp[finish_day], dp[i] + sangdam[i][1]);
        }
    }

    // for(int i = 0; i <= n; i++) cout << dp[i] << ' ';

    cout << dp[n];
    
    return 0;
}