#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void per(short startidx, short m, vector<short>& arr, vector<short>& lst){
    if (m == arr.size()){
        for(short result : arr) cout << result << ' ';
        cout << '\n';
        return;
    }
    for(short i = startidx; i < lst.size(); i++){ // 고른 순열은 비내림차순이다.
        if(i > 0 && lst[i] <= lst[i - 1]) continue;
        arr.push_back(lst[i]);
        per(i, m, arr, lst);
        arr.pop_back();
    }
}

int main(){
    short n, m;
    cin >> n >> m;
    vector<short> lst;
    for(int i = 0; i < n; i++){
        short a;
        cin >> a;
        lst.push_back(a);
    }

    sort(lst.begin(), lst.end());

    vector<short> arr;
    vector<bool> visited(n, false);
    per(0, m, arr, lst);

    return 0;
}