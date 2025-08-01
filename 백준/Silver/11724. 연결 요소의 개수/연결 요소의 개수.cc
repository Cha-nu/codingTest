#include <iostream>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int>>& ma, vector<int>& visited){
    visited[start] = 1;
    for(int i = 0; i < visited.size(); i++){
        if(visited[i]) continue;
        if(ma[start][i]) dfs(i, ma, visited);
    }
    return;
}

int main(){
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> ma(n, vector<int>(n, 0));
    vector<int> visited(n, 0);

    int i, j;
    for(int k = 0; k < m; k++){
        cin >> i >> j;
        --i, --j;
        ma[i][j] = 1;
        ma[j][i] = 1;
    }

    for(int k = 0; k < n; k++){
        if(visited[k]) continue;
        dfs(k, ma, visited);
        cnt += 1;
    }

    cout << cnt;
    return 0;
}