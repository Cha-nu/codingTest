#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    
    int r = static_cast<int>(maps.size());
    int c = static_cast<int>(maps[0].size());
    
    vector<vector<bool>> visited(r, vector<bool> (c, true));
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            int sum = 0;
            if(visited[i][j] && maps[i][j] != 'X')
            {
                q.push({i, j});
                sum += maps[i][j] - '0';
                visited[i][j] = false;
                while(!q.empty())
                {
                    int cr = q.front().first;
                    int cc = q.front().second;
                     
                    q.pop();
                    for(int k = 0; k < 4; ++k)
                    {
                        int nr = cr+dr[k];
                        int nc = cc+dc[k];
                        // cout << nr << ' ' << nc << '\n';
                        if(0 <= nr && nr < r && 0 <= nc && nc < c && visited[nr][nc] && maps[nr][nc] != 'X')
                        { 
                            
                            sum += maps[nr][nc] - '0';
                            visited[nr][nc] = false;
                            q.push({nr, nc});
                        }
                    }
                }
                // cout << '\n';
            }
            if(sum > 0) answer.push_back(sum);
        }
    }
    
    if(answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    
    return answer;
}