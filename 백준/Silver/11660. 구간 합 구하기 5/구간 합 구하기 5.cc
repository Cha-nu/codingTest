#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n+1, vector<int>(n+1, 0));
    vector<vector<int>> sum_table(n+1, vector<int>(n+1, 0));

    for(short i = 1; i <= n; i++) for(short j = 1; j <= n; j++){
        cin >> table[i][j];
        sum_table[i][j] = table[i][j] + sum_table[i-1][j] + sum_table[i][j-1] - sum_table[i-1][j-1];
    }

    while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = sum_table[x2][y2] - sum_table[x1-1][y2] - sum_table[x2][y1-1] + sum_table[x1-1][y1-1];
        cout << sum << '\n';
    }

    return 0;
}