#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;

    string cmd;
    int a;
    stack<int> stack;
    for(int i = 0; i < N; i++){
        cin >> cmd;
        if(cmd == "push"){
            cin >> a;
            stack.push(a);
        }
        else if(cmd == "top"){
            if(stack.empty()) cout << -1 << '\n';
            else{
                cout << stack.top() << '\n';
            } 
        } 
        else if(cmd == "size") cout << stack.size() << '\n';
        else if(cmd == "empty") cout << stack.empty() << '\n';
        else if(cmd == "pop"){
            if(stack.empty()) cout << -1 << '\n';
            else{
                cout << stack.top() << '\n';
                stack.pop();
            } 
        }
    }
    return 0;
}