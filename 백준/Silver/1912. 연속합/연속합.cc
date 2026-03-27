#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> memo (n, 0);

    int j;
    cin >> j;
    memo[0] = j;
    int max_val = j;

    // 음수가 아닌 연속된 수의 합
    for(int i = 1; i < n ; i++)
    {
        cin >> j;
        memo[i] = j;
        memo[i] = max(memo[i], memo[i]+memo[i-1]);
        if(max_val < memo[i]) max_val = memo[i];
    }

    // dp인 것 같은데
    cout << max_val;
    
    return 0;
}