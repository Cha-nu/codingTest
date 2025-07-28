#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, o;
    cin >> n >> m;
    vector<int> arr(n+1);
    arr[0] = 0;
    int sum = 0;
    for(int i = 1; i < n+1; i++){
        cin >> o;
        sum += o;
        arr[i] = sum;
    } 
    int i, j;
    while(m--){
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }
    return 0;
}