#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count, N;
    cin >> N;
    vector<int> memo(N+1, 9999);

    memo[3] = 1, memo[5] = 1;

    for(int i = 6; i < N+1; i++){
        memo[i] = min(memo[i-3]+1, memo[i-5]+1);
    }

    if (memo[N] >= 9999) cout << -1;
    else cout << memo[N];
    return 0;
} 