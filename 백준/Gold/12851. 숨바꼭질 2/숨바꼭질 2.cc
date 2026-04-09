#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, result = 0;
    queue<pair<int, int>> q; // (위치 시간)
    vector<vector<int>> visited(100001, vector<int> (2, 0)); // (방문여부, 시간)

    cin >> n >> k;

        q.push({n, 0});
        visited[n][0] = 1;
        visited[n][1] = 0;

        while(!q.empty())
        {
            n = q.front().first;
            int time = q.front().second;
            q.pop();

            if(n == k) 
            {
                if(result == 0) // 처음 도착
                {
                    visited[k][1] = time;
                    result = 1;
                }
                else if (time == visited[k][1]) result++;
                continue; // 도착하면 종료
            } 

            if(n+1 <= 100000)
            {
                if(visited[n+1][0] == 0 || visited[n+1][1] == time+1) // 미방문
                {
                    visited[n+1][0] = 1; // 방문처리
                    visited[n+1][1] = time+1;
                    q.push({n+1, time+1});  
                }
            } 
            if(n-1 >= 0)
            {
                if(visited[n-1][0] == 0 || visited[n-1][1] == time+1) // 미방문
                {
                    visited[n-1][0] = 1; 
                    visited[n-1][1] = time+1;
                    q.push({n-1, time+1});
                }
            }
            if(2*n <= 100000)
            {
                if(visited[2*n][0] == 0 || visited[2*n][1] == time+1) // 미방문
                {
                    visited[2*n][0] = 1;
                    visited[2*n][1] = time+1;
                    q.push({2*n, time+1});
                }
            }
        }

    cout << visited[k][1] << '\n' << result;

    return 0;
}