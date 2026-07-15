#include <vector>
#include <queue>

#define m 10000001

using namespace std;

int solution(int x, int y, int n) {
    //bfs
    queue<pair<int, int>> q;
    
    vector<bool> visited(m, false);
    
    q.push({x, 0});
    visited[x] = true;
    
    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        if(a.first == y) return a.second;
        
        if(a.first + n <= 1000000 && !visited[a.first + n])
        {
            visited[a.first + n] = true;
            q.push({a.first + n, a.second + 1});
        }
        if(a.first*2 <= 1000000 && !visited[a.first*2])
        {
            visited[a.first*2] = true;
            q.push({a.first*2, a.second + 1});
        }
        if(a.first*3 <= 1000000 && !visited[a.first*3])
        {
            visited[a.first*3] = true;
            q.push({a.first*3, a.second + 1});
        }
    }
    
    
    
    return -1;
}