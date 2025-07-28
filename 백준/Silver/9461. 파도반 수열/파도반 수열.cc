#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, n;
    cin >> T;
    int current_idx = 6;
    vector<unsigned long long> memo(101, 1);
    memo[0] = 0;
    memo[4] = 2;
    memo[5] = 2;
    while(T--){
        cin >> n;
        if(n < current_idx) cout << memo[n] << '\n';
        else{
        for(; current_idx <= n; current_idx++){
            memo[current_idx] = memo[current_idx-1] + memo[current_idx-5];
        }
        cout << memo[n] << '\n';
    }
    }

    return 0;
}