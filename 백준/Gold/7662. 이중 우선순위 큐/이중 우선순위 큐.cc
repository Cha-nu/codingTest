#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        multiset<long long> pq;
        while(k--){
            char cmd; long long n;
            cin >> cmd >> n;
            if(cmd == 'I'){
                pq.insert(n);
            }
            else if(cmd == 'D'){
                if(pq.empty()) continue;
                else if(n == 1){
                    pq.erase(prev(pq.end())); // 최댓값 삭제
                }
                else if(n == -1){
                    pq.erase(pq.begin()); // 최솟값 삭제
                }
            }
        }
        // 남아있는 최댓값 최솟값 구하기
        if(pq.empty()){
            cout << "EMPTY" << '\n';
        }
        else{
            long long minv =  *pq.begin() ;
            long long maxv = *prev(pq.end());
            cout << maxv << ' ' << minv << '\n'; // 남아있는 값중 최댓값 최솟값 출력
        }
    }
    return 0;
}
