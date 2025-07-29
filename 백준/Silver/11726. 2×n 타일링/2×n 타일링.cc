#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<unsigned long long> memo(n+1);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for(int i = 3; i <= n; i++){
        memo[i] = (memo[i-2] + memo[i-1]) % 10007 ;
    }

    cout << memo[n] << '\n';
    return 0;
}