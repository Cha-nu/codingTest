#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long m, maxh = 0;
    cin >> n >> m;

    vector<long long> tree(n);

    for(int i = 0; i < n; i++){
        cin >> tree[i];
        if(tree[i] > maxh) maxh = tree[i];
    }
    
    long long start = 1, end = maxh, result = 0;
    long long mid, sum;

    while(start <= end){
        mid = (start + end) / 2;
        sum = 0;
        for(int i = 0; i < n; i++) sum += ((tree[i] - mid) > 0 ? tree[i] - mid : 0);
        
        if(sum >= m){
            result = max(mid, result);
            start = mid + 1;
        }
        else end = mid - 1;
    }

    cout << result;


    return 0;
}