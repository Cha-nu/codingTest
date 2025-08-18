#include <iostream>
#include <queue>

using namespace std;

int main(){
    long a, b;
    cin >> a >> b;
    queue<long> q;
    q.push(a);

    int cnt = 0;
    while(!q.empty()){
        long sz = q.size();
        while(sz--){
            a = q.front(); q.pop();
            if(a == b){
                cout << ++cnt;
                return 0;
            }
            else if(a > b){
                continue;
            }
            q.push(a*2);
            q.push(a*10+1);
        }
        cnt++;
    }
    cout << -1;
    return 0;
}