#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(100, 0); // 0부터 99까지 실제 1부터 100까지 방향 그래프 
    vector<int> visited(100, 0);
    queue<int> q;
    int x, y;
    for(int i = 0; i < n; i++){ // 사다리 x에서 y로 이동 증가
        cin >> x >> y;
        arr[x-1] = y-1;
    }
    for(int i = 0; i < m; i++){ // 뱀 x에서 y로 이동 감소
        cin >> x >> y;
        arr[x-1] = y-1;
    }

    q.push(0); // 시작은 0
    visited[0] = 1; // 0으로 시작이지만 방문 확인을 위해 1로 설정 나중에 1제거

    while(!q.empty()){ // BFS
        int i = q.front(); q.pop();
        if(i == 99){
            cout << visited[i]-1;
            return 0;
        }
        for(int j = 1; j <= 6; j++){ // 주사위 6만큼 이동
            int k = i + j;
            if(k >= 100) continue;

            // 주사위 이동 후 사다리/뱀이 있다면 최종 도착 칸으로 변경
            if(arr[k] != 0){
                k = arr[k];
            }
            
            // 최종 도착 칸이 아직 방문하지 않은 곳일 때만 큐에 추가
            if(visited[k] == 0){ 
                visited[k] = visited[i] + 1;
                q.push(k);
            }
        }
    }
    return 0;
}