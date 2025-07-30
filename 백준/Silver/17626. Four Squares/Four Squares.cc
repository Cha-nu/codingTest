#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> memo(n+1, 1e9);
    memo[0] = 0;

    for(int i = 1; i <= n; i++) for(int j = 1; j * j <= i; j++) memo[i] = min(memo[i], memo[i - j*j] + 1);
    
    cout << memo[n];

    return 0;
}