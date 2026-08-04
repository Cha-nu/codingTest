#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> dp (n+1, vector<long long>(m+1));
    
    for(auto& p : puddles) dp[p[1]][p[0]] = -1;
    
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(i == 1 && j == 1)
            {
                dp[i][j] = 1;
                continue;
            }
            else if(dp[i][j] == -1) continue;
            if(dp[i-1][j] == -1) dp[i][j] = dp[i][j-1] % 1000000007;
            else if(dp[i][j-1] == -1) dp[i][j] = dp[i-1][j] % 1000000007;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
        }
    }
    
    return dp[n][m] % 1000000007;
}
// bfs X DP O
// #include <string>
// #include <vector>
// #include <queue>

// using namespace std;

// int solution(int m, int n, vector<vector<int>> puddles) {
//     int answer = 0;
    
//     vector<short> dr {1, 0};
//     vector<short> dc {0, 1};
    
//     vector<vector<int>> g(n, vector<int>(m, 1));
    
//     for(auto& p : puddles)
//     {
//         g[p[0] - 1][p[1] - 1] = 0;
//     }
    
//     queue<pair<int,int>> q;
//     q.push({0,0});
    
//     while(!q.empty())
//     {
//         int current_r = q.front().first;
//         int current_c = q.front().second;
//         q.pop();
//         for(int i = 0; i < 2; ++i)
//         {
//             int next_r = current_r + dr[i];
//             int next_c = current_c + dc[i];
            
//             if(next_r == n-1 && next_c == m-1)
//             {
//                 answer = (answer + 1) % 1000000007;
//                 continue;
//             }
//             else if(0 <= next_r && next_r < n && 0 <= next_c && next_c < m && g[next_r][next_c]) q.push({next_r, next_c});
//         }
//     }
    
//     return answer % 1000000007;
// }