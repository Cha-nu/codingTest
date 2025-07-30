#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(int start, const vector<vector<int>> &arr, vector<int> &check){
    check[start] = 1;
    cout << start << " ";
    for(int i = 0; i < arr[start].size(); i++){
        if(check[i] != 1 && arr[start][i] == 1) dfs(i, arr, check);
    }
}

void bfs(int start, const vector<vector<int>> &arr,vector<int> &check){
    int current;
    queue<int> q;
    q.push(start);
    check[start] = 1;
    while(!q.empty()){
        current = q.front();
        q.pop();
        cout << current << ' ';
        for(int i = 0; i < arr[current].size(); i++) if(check[i] != 1 && arr[current][i] == 1){
            q.push(i);
            check[i] = 1;
        }
    }
}

int main(){
    int n, m, v, i, j;
    cin >> n >> m >> v;
    vector<vector<int>> arr(n+1,vector<int>(n+1, 0));
    vector<int> dfscheck(n+1,0);
    vector<int> bfscheck(n+1,0);
    while(m--){
        cin >> i >> j;
        arr[i][j] = 1;
        arr[j][i] = 1;
    }
    dfs(v, arr, dfscheck);
    cout <<'\n';
    bfs(v, arr, bfscheck);
}