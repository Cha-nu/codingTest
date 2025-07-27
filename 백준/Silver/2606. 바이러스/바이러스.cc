#include <iostream>
#include <vector>

using namespace std;

int dfs(int count, int current, vector<vector<int>> node, vector<int>& check){
    for(int i = 2; i < node[current].size(); i++){
        if(node[current][i] == 1){
            if(check[i] == 0){
                check[i] = 1;
                count = dfs(count, i, node, check) + 1;
            }
        }
    }
    return count;
}

int main(){
    int n, m, i, j;
    cin >> n >> m;

    // dfs 구현
    vector<vector<int>> node(n+1, vector<int>(n+1, 0));
    vector<int> check(n+1, 0);

    while(m--){
        cin >> i >> j;
        node[i][j] = 1;
        node[j][i] = 1;
    }

    check[1] = 1;
    cout << dfs(0, 1, node, check);
    
    return 0;
}