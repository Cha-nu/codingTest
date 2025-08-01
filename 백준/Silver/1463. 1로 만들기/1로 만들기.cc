#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int count = 0;
    
    vector<int> memo(N+1);
    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;

    for(int i = 3; i <= N; i++){
        if((i % 3 == 0) && (i % 2 == 0)) memo[i] = min(min(memo[i/3]+1, memo[i/2]+1), memo[i-1]+1);
        else if (i % 3 == 0) memo[i] = min(memo[i/3]+1, memo[i-1]+1);
        else if (i % 2 == 0) memo[i] = min(memo[i/2]+1, memo[i-1]+1);
        else memo[i] = memo[i-1] + 1;
    }

    cout << memo[N] << '\n';
    return 0;
}