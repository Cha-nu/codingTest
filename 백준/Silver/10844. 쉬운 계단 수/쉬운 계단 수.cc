#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // 인접한 모든 자리의 차이가 1인 계단수
     // 엥 dp라고?
    vector<vector<unsigned long long>> dp(n+1, vector<unsigned long long>(10, 0));
    for(int i = 1; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for(int i = 2; i < n+1; i++)
    {
       for(int j = 0; j < 10; j++)
       {
        if(j == 0) dp[i][j] += dp[i-1][j+1] % 1000000000;
        else if (j == 9) dp[i][j] += dp[i-1][j-1] % 1000000000;
        else dp[i][j] += (dp[i-1][j+1] + dp[i-1][j-1]) % 1000000000;
       }
    }

    // 12 23 34 45 56 67 78 89 
    // 10 21 32 43 54 65 76 87 98 
    
    // 121 232 343 454 565 676 787 898 
    // 123 234 345 456 567 678 789 
    // 101 212 323 434 545 656 767 878 989 
    // 210 321 432 543 654 765 876 987 

    unsigned long long result = 0;
    for(int i = 0; i < 10; i++)
    {
        result+=dp[n][i];
    }

    cout << result % 1000000000;
    return 0;
}