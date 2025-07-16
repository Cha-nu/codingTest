#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, O;
    cin >> N;
    vector<int> dec(N);
    for(int i = 0; i < N; i++){
        cin >> dec[i];
    }
    sort(dec.begin(), dec.end());
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> O;
        int lower = lower_bound(dec.begin(), dec.end(), O) - dec.begin();
        int upper = upper_bound(dec.begin(), dec.end(), O) - dec.begin();
        cout << (upper - lower) << " ";
    }
    return 0;
}
