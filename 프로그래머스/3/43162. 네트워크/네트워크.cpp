#include <queue>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited (n, true);
    queue<int> q;
    
    //BFS
    for(int i = 0; i < n; i++)
    {
        if(visited[i])
        {
            q.push(i);
            visited[i] = false;
            while(!q.empty())
            {
                int val = q.front(); q.pop();
                for(int j = 0; j < n; j++)
                {
                    if(computers[val][j] && visited[j])
                    {
                        q.push(j);
                        visited[j] = false;
                    }
                }
            }
            answer++;
        }
    }
    return answer;
}