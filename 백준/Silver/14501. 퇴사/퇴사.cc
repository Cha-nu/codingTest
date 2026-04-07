#include <iostream>
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


    for(int i = 0; i < n; i++)
    {
        if(sangdam[i][0]+i > n) continue; // 상담 기간이 퇴사 기간을 넘어가면 미선택
        else
        {
            dp[i] += sangdam[i][1];
            for(int j = i; j < n+1; j++)
            {
                if(sangdam[i][0]+j > n) break;
                dp[sangdam[i][0]+j] = max(dp[sangdam[i][0]+j], dp[i]); // 더 많이 받는 상담으로 교체
            }
        }
    }

    // for(int i = 0; i <= n; i++) cout << dp[i] << ' ';

    cout << dp[n];
    
    return 0;
}