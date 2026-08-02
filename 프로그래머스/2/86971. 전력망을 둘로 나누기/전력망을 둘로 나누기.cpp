#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 양방향 노드
    // 전선 == 간선 인접행렬 전선을 자르기 쉽게
    
    vector<vector<int>> v (n+1, vector<int>(n+1));
    
    // 인접행렬 생성
    for(auto& w : wires)
    {
        v[w[0]][w[1]] = 1;
        v[w[1]][w[0]] = 1;
    }
    
    for(auto& w : wires)
    {
        // 전선 끊기
        v[w[0]][w[1]] = 0;
        v[w[1]][w[0]] = 0;
        
        vector<int> visited (n+1); // 방문 재설정
        vector<int> cnt;
        queue<int> q;
        
        for(int i = 1; i <= n; ++i)
        {
            if(!visited[i])
            {
                q.push(i);
                cnt.push_back(1);
                visited[i] = 1;
                
                // 트리가 3개가 되면 안됨
                if(static_cast<int>(cnt.size()) >= 3)
                {
                    cnt[0] = 9;
                    cnt[1] = 0;
                    break;
                }
                
                while(!q.empty())
                {
                    int current = q.front();
                    q.pop();
                    for(int j = 1; j <= n; ++j)
                    {
                        if(v[current][j] && !visited[j])
                        {
                            q.push(j);
                            visited[j] = 1;
                            ++cnt.back();
                        }
                    }
                }
            }
        }
        
        if(cnt[0] > cnt[1]) answer = min(answer, cnt[0] - cnt[1]);
        else answer = min(answer, cnt[1] - cnt[0]);
        
        // 다시 연결
        v[w[0]][w[1]] = 1;
        v[w[1]][w[0]] = 1;
    }
    
    return answer;
}