#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 절삭 평균
    int m = round(n * 0.15);    

    sort(arr.begin(), arr.end());

    vector<int> result(arr.begin() + m, arr.end() - m);

    double sum = accumulate(result.begin(), result.end(), 0.0);
    double avg = round(sum / result.size());

    if(n == 0) avg = 0;

    cout << static_cast<int>(avg);
    return 0;
}