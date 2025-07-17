#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int N, a;
    string cmd;
    queue<int> q;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> a;
            q.push(a);
        }
        else if(cmd == "pop"){
            if(q.empty()) cout << -1 << '\n';
            else {
                a = q.front();
                cout << a << '\n';
                q.pop();
            }
        }
        else if(cmd == "size") cout << q.size() << '\n';
        else if(cmd == "empty") cout << q.empty() << '\n';
        else if(cmd == "front"){
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
            }
        } 
        else{
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}