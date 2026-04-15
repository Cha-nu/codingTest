#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> drdc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int r, c, t;
    cin >> r >> c >> t;
    vector<vector<int>> graph {r, vector<int> (c, 0)};
    vector<pair<int,int>> aircondition;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            int val;
            cin >> val;
            graph[i][j] = val;
            if (val == -1) aircondition.push_back({i, j});
        }
    }

    for(; t > 0 ; t--)
    {
        // 확산
        vector<vector<int>> temp(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (graph[i][j] <= 0) continue; // 미세먼지가 없거나 공기청정기면 패스

                int spread_amount = graph[i][j] / 5;
                int spread_count = 0;

                for (int d = 0; d < 4; d++)
                {
                    int nr = i + drdc[d].first;
                    int nc = j + drdc[d].second;

                    if (nr >= 0 && nr < r && nc >= 0 && nc < c && graph[nr][nc] != -1)
                    {
                        temp[nr][nc] += spread_amount;
                        spread_count++;
                    }
                }
            temp[i][j] += graph[i][j] - (spread_amount * spread_count);
            }
        }
        // 공기청정기 위치 복구 후 graph에 복사
        temp[aircondition[0].first][aircondition[0].second] = -1;
        temp[aircondition[1].first][aircondition[1].second] = -1;
        graph = temp;
        // 공기 순환 위로 반시계 아래로는 시계
        //위쪽
        int up = aircondition[0].first;
        // 아래로 당기기 (왼쪽 벽)
        for (int i = up - 1; i > 0; i--) graph[i][0] = graph[i - 1][0];
        // 왼쪽으로 당기기 (천장)
        for (int i = 0; i < c - 1; i++) graph[0][i] = graph[0][i + 1];
        // 위로 당기기 (오른쪽 벽)
        for (int i = 0; i < up; i++) graph[i][c - 1] = graph[i + 1][c - 1];
        // 오른쪽으로 당기기 (공기청정기 라인)
        for (int i = c - 1; i > 1; i--) graph[up][i] = graph[up][i - 1];
        graph[up][1] = 0; // 공기청정기에서 나가는 바람은 먼지 0

        // 아래쪽
        int down = aircondition[1].first;
        // 위로 당기기 (왼쪽 벽)
        for (int i = down + 1; i < r - 1; i++) graph[i][0] = graph[i + 1][0];
        // 왼쪽으로 당기기 (바닥)
        for (int i = 0; i < c - 1; i++) graph[r - 1][i] = graph[r - 1][i + 1];
        // 아래로 당기기 (오른쪽 벽)
        for (int i = r - 1; i > down; i--) graph[i][c - 1] = graph[i - 1][c - 1];
        // 오른쪽으로 당기기 (공기청정기 라인)
        for (int i = c - 1; i > 1; i--) graph[down][i] = graph[down][i - 1];
        graph[down][1] = 0;

    }
    int result = 0;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(graph[i][j] > 0) result += graph[i][j];
        }
    }
    cout << result;
    return 0;
}