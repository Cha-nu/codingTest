#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, result = 0; // k에 최단시간으로 도착한 방법의 수
    cin >> n >> k;
    
    vector<vector<int>> visited (100001, vector<int> (2, 0)); // (방문여부, 시간)

    queue<pair<int, int>> q; // BFS (위치, 시간)

    // 방문 시작
    visited[n][0] = 1;
    visited[n][1] = 0;
    visited[k][1] = 100001;
    q.push({n, 0});

    while(!q.empty())
    {
        n = q.front().first;
        int time = q.front().second;
        q.pop();

        if(n == k)
        {
            // cout << n << ' ' <<  time << '\n';
            if(visited[n][0] = 1 && visited[n][1] == time) result++;
            else if(visited[n][1] > time) // 더 빠른 시간에 도착하면 초기화
            {
                visited[n][1] = time;
                result = 1;
            }
            continue; // k에 도달한 경우 더 이상 진행X
        }

        vector<int> next_ns = {n+1, n-1, n*2};
        for(int next_n : next_ns)
        {
            if(next_n >= 0 && next_n <= 100000)
            {
                if(visited[next_n][0] == 0 || (visited[next_n][0] == 1 && visited[next_n][1] >= time+1))
                {
                    visited[next_n][0] = 1;
                    visited[next_n][1] = time+1;
                    q.push({next_n, time+1});
                }
            }
        }
    }
    cout << visited[k][1] << '\n' << result;

    return 0;
}