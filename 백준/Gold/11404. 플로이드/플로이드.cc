#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000 

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> memo(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) memo[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 같은 경로에 여러 간선이 있을 수 있으므로 최솟값만 유지
        if (memo[a][b] > c) memo[a][b] = c;
    }

    // 플로이드-워셜: k(거쳐가는 노드), i(출발), j(도착)
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // i에서 k를 거쳐 j로 가는 거리가 더 짧으면 갱신
                if (memo[i][k] != INF && memo[k][j] != INF) 
                {
                    memo[i][j] = min(memo[i][j], memo[i][k] + memo[k][j]);
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 도달할 수 없는 경우 0 출력
            if (memo[i][j] == INF) cout << 0 << " ";
            else cout << memo[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}