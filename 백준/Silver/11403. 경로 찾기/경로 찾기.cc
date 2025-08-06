#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, a;
    cin >> n;

    vector<vector<int>> input(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            if(a == 0) input[i][j] = 1e9;
            else input[i][j] = 1;
        }
    }

    for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) input[i][j] = min(input[i][j], (input[i][k] + input[k][j]));

    for(int i = 0; i < n; i++){ for(int j = 0; j < n; j++) cout << (input[i][j] < 1e9) << ' ';  cout << '\n';}
    return 0;
}