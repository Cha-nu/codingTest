#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N;
    vector<int> A(N);

    for(int i = 0; i < N; i++) cin >> A[i];
    
    sort(A.begin(), A.end());

    cin >> M;
    vector<int> arr(M);
    for(int i = 0; i < M; i++) cin >> arr[i];
    
    for(int i = 0; i < M; i++){
        cout << binary_search(A.begin(), A.end(), arr[i]) << '\n';
    }

    return 0;
}