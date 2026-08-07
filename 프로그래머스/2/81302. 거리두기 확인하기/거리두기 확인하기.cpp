#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5, 1);
    // 대기자 상하좌우대각선 확인 맨해튼 거리 2이하 앉기 금지 상하좌우에 파티션 있으면 해결  
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    
    // 안지켜지면 0, 지켜지면 
    // 대기실 크기 5x5, 대기실 갯수 5
    
    // BFS로 
    
    for(int i = 0; i < 5; ++i)
    {
        for(int r = 0; r < 5; ++r)
        {
            for(int c = 0; c < 5; ++c)
            {
                if(places[i][r][c] == 'P')
                {
                    queue<pair<int, int>> q; // dist, r, c; 
                    for(int d = 0; d < 4; ++d)
                    {
                        // 파티션 위치 확인
                        int nr = r + dr[d];
                        int nc = c + dc[d];
                        
                        if(0 <= nr && nr < 5 && 0 <= nc && nc < 5)
                        {
                            if(places[i][nr][nc] == 'P')
                            {
                                answer[i] = 0;
                                break;
                            }
                            else if(places[i][nr][nc] == 'O') q.push({nr, nc});
                        }
                    }
                    while(!q.empty())
                    {
                        int cr = q.front().first;
                        int cc = q.front().second;
                        q.pop();
                        int cnt = 0;
                        for(int d = 0; d < 4; ++d)
                        {
                            int nr = cr + dr[d];
                            int nc = cc + dc[d];
    
                            if(0 <= nr && nr < 5 && 0 <= nc && nc < 5 && places[i][nr][nc] == 'P') ++cnt;
                        }
                        if(cnt >= 2)
                        {
                            answer[i] = 0;
                            break;
                        }
                    }
                }
            }
        }
        
    }
    
    
    return answer;
}