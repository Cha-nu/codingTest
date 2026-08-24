#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
    int r = maps.size();
    int c = maps[0].size();
    
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    
    vector<vector<bool>> visited(r, vector<bool>(c, true));
    
    queue<pair<int,pair<int,int>>> q;
    q.push({1, {0, 0}});
    
    while(!q.empty())
    {
        auto& it = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            int nr = it.second.first + dr[i];
            int nc = it.second.second + dc[i];
            if(0 <= nr && nr < r && 0 <= nc && nc < c && visited[nr][nc] && maps[nr][nc])
            {
                if(nr == r-1 && nc == c-1) return it.first+1;
                else
                {
                    q.push({it.first+1, {nr, nc}});
                    visited[nr][nc] = false;
                }
            }
            
        }
        
    }
    
    return -1;
}