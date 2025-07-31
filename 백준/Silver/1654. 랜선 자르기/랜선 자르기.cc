#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<int> lan(k, 0);
    int maxint = 0; // 가장 긴 랜선으로 최소 1개 생성
    for(int i = 0; i < k; i++){
        cin >> lan[i];
        if(lan[i] > maxint) maxint = lan[i];
    }

    int result = 0;
    long long start = 1, end = maxint;
    while(start <= end){
        long long mid = (start+end) / 2;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += (lan[i] / mid);
        }
        if(sum >= n){
            result = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }

    cout << result;
    return 0;
}