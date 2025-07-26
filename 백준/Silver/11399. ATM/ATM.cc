#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> memo(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int result = 0;
    for(int i = 0; i < N; i++) {
        memo[i] = arr[i] + (i > 0 ? memo[i-1] : 0);
        result += memo[i];
    }
    cout << result << '\n';
    return 0;
}