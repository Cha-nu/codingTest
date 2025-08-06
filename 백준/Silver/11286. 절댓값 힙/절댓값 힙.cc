#include <iostream>
#include <queue>
#include <functional>
#include <cstdlib>

using namespace std;

struct compare{
    bool operator() (long long a, long long b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    priority_queue<long long, vector<long long>, compare> pq;

    int n;
    cin >> n;
    long long num, num2;
    while(n--){
        cin >> num;
        if(num == 0){
            if(pq.empty()) cout << 0 << '\n';
            else{
                num = pq.top();
                cout << num << '\n';
                pq.pop();
                }
            }
        else pq.push(num);
    }
    return 0;
}