#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long> arr(n);
    vector<long> a(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        a[i] = arr[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for(int i = 0; i < n; i++){
        int idx= lower_bound(a.begin(), a.end(), arr[i])-a.begin();
        cout << idx << " ";
    }

    return 0;
}