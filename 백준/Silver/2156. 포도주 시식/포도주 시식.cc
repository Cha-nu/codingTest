#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> podo(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        podo[i] = m; 
    }

    if (n == 1) {
        cout << podo[0] << endl;
        return 0;
    }
    if (n == 2) {
        cout << podo[0] + podo[1] << endl;
        return 0;
    }

    // dp 점화식 생각하기 dp[i] = max()
    // 첫잔 선택
    // 연속으로 놓인 3잔은 마실 수 없다.  6 10 13 9 8 1 => 6 10 9 8 = 33
    /*
    6
    6 10
    6 10 13
    6을 버릴 경우
    count = 2;
    10 13 = 23 2개 뽑았을때 최대
    10 13 9에서 9 버려짐 count = 0;
    10 13 8 = 31 3개 뽑았을시 최대
    10 13 8 1 = 32
    10을 버릴경우
    count = 1;
    6 13 = 19
    6 13 9 count = 2; 28 
    6 13 9 8버려짐 count = 0;
    6 13 9 1 = 29
    13를 버릴경우
    count = 0;
    6 10 = 16
    6 10 9 count = 1; 25
    6 10 9 8 count = 2; 답 33
    1 버려짐
    */
   dp[0] = podo[0];
   dp[1] = dp[0] + podo[1];
   dp[2] = max({dp[1], podo[0] + podo[2], podo[1] + podo[2]});

   for(int i = 3; i < n; i++)
   {
    // 2번째 잔까지 고려했을 때 얻을 수 있는 최댓값
    // dp[i-1] i번째 잔을 마시지 않는다.
    // dp[i-2]+podo[i] i번째 잔을 마시고 이게 첫번째
    // dp[i-3] + dp[i-2] + podo[i] i번째 잔을 마시고 이게 두번째
    dp[i] = max({dp[i-1], dp[i-2] + podo[i], dp[i-3] + podo[i-1] + podo[i]});
   }
   cout << dp[n-1];
   return 0;
}