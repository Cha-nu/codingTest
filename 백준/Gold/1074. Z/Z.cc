#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int r, int c){
    if(n == 0) return 0;

    int half = 1 << (n - 1);

    if(r < half && c < half) return solve(n-1, r, c); // 1사분면
    if(r < half && c >= half) return half * half + solve(n-1, r, c-half); // 2사분면
    if(r >= half && c < half) return 2 * half * half + solve(n-1,r-half,c); // 3사분면
    if(r >= half && c >= half) return 3 * half * half + solve(n-1,r-half, c-half); // 4사분면
}

int main(){
    int n, r, c;
    cin >> n >> r >> c;
    int result = 0;

    result = solve(n, r, c);
    cout << result;
}