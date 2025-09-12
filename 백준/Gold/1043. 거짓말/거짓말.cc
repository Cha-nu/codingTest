#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m;
    cin >> k;
    
    if(k == 0){
        cout << m;
        return 0;
    }

    queue<int> q;
    vector<bool> know(n+1, false);
    vector<vector<int>> graph(n+1);
    vector<vector<int>> party(m);
    int result = 0;

    while(k--){
        short l;
        cin >> l;
        q.push(l);
        know[l] = true;
    }

    for(int w = 0; w < m; w++){
        short l;
        cin >> l;
        
        for(int i = 0; i < l; i++){
            short p;
            cin >> p;
            party[w].push_back(p);
        }
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++){
                if(i == j) continue;
                graph[party[w][i]].push_back(party[w][j]);
            }
        }
    }

    while(!q.empty()){ // dfs로 진실 아는 사람 생성
        int current = q.front(); q.pop();
        for(int i : graph[current]){
            if(!know[i]){
            know[i] = true;
            q.push(i);
            }
        }
    }

    // 과장할 수 있는 파티 찾기
    for(int i = 0; i < m; i++){
        if(!know[party[i][0]]){
            result+=1;
        }
    }
    cout << result;
    return 0;
}