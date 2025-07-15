#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int N;
    stack<char> stack;
    string P, result;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> P;
        result = "YES";
        for(char p : P){
            if(p == '(') stack.push(p);
            else if(p == ')'){
                if (stack.empty() || stack.top() != '('){
                    result = "NO";
                    break;
                }
                stack.pop();
            }
        }
        // (로만 끝날경우 yes뜸
        if(!stack.empty()){
            result = "NO";
            while(!stack.empty()) stack.pop();
        }
        cout << result << '\n';
    }
    return 0;
}