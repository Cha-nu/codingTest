#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> memo(n+1, 0);
    memo[1] = 1;
    memo[2] = 1;
    
    for(int i = 2; i <= n; i++) memo[i] = (memo[i-1] + memo[i-2]) % 1234567;
    
    
    return (memo[n] % 1234567);
}