#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> a (n+1, 0);
    
    a[1] = 1; // 1
    a[2] = 2; // (1, 1), (2)
    
    
    for(int i = 3; i < n+1; ++i) a[i] = (a[i-2] + a[i-1]) % 1234567;

    return a[n] % 1234567;
}