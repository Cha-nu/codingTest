#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n);

    int a;
    for(short i = 0; i < n; i++){
        for(short j = 0; j < i+1; j++){
            cin >> a;
            tree[i].push_back(a);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) { // 왼쪽 끝
                tree[i][j] += tree[i - 1][j];
            } else if (j == i) { // 오른쪽 끝
                tree[i][j] += tree[i - 1][j - 1];
            } else { // 가운데
                tree[i][j] += max(tree[i - 1][j - 1], tree[i - 1][j]);
            }
        }
    }

    a = 0;
    for(short i = 0; i < n; i++) a = max(a, tree[n-1][i]);

    cout << a;

    return 0;
}