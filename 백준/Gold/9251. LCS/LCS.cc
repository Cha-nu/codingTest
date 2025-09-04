#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string n, m;
    cin >> n >> m;
    int a = n.length();
    int b = m.length();

    vector<vector<int>> dp (++a, vector<int> (++b, 0));

    for(int i = 1; i < a; i++){
        for(int j = 1; j < b; j++){
            if(n[i-1] == m[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a-1][b-1];
    return 0;
}