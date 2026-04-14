#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r; // n : 지역수, m : 수색범위, r : 길의 개수
    cin >> n >> m >> r;
    vector<vector<int>> memo (n, vector<int> (n, INF));
    vector<int> item (n, 0);
    
    for(int i = 0; i < n; i++)
    {
        cin >> item[i];
        memo[i][i] = 0;
    }

    for(int i = 0; i < r; i++)
    {
        int r, c, val;
        cin >> r >> c >> val;
        memo[r-1][c-1] = val;
        memo[c-1][r-1] = val;
    }


    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
            }
        }
    }

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int value = 0;
        for(int j = 0; j < n; j++)
        {
            if(memo[i][j] <= m) value += item[j];
        }
        result = max(result, value);
    }
    cout << result;
    return 0;
}
