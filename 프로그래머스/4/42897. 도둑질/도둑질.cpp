#include <vector>
#include <algorithm>

using namespace std;

int robLinear(const vector<int>& money, int start, int end)
{
    int prev2 = 0; // dp[i - 2]
    int prev1 = 0; // dp[i - 1]

    for (int i = start; i <= end; ++i)
    {
        int cur = max(
            prev1,             // 현재 집을 털지 않음
            prev2 + money[i]   // 현재 집을 털음
        );

        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int solution(vector<int> money)
{
    int n = money.size();

    // 첫 번째 집 포함 가능 -> 마지막 집 제외
    int case1 = robLinear(money, 0, n - 2);

    // 첫 번째 집 제외 -> 마지막 집 포함 가능
    int case2 = robLinear(money, 1, n - 1);

    return max(case1, case2);
}