#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> stack;
    string N;
    string result;
    char m;
    while(true){
        // 100글자보다 작은 문자열이 들어옴
        getline(cin, N);
        
        // if .만 들어오면 break;
        if (N == ".")break;

        result = "yes";

        // 문자열 반복문
        for(char n : N){
            if(n == '.') break;
            if(n == '(' || n == '[') stack.push(n);
            else if(n == ')'){
                if (stack.empty() || stack.top() != '('){
                    result = "no";
                    break;
                }
                stack.pop();
            }
            else if(n == ']'){
                if (stack.empty() || stack.top() != '['){
                    result = "no";
                    break;
                }
                stack.pop();  
            }
        }
        // (, [ 로만 끝날경우 yes뜸
        if(!stack.empty()){
            result = "no";
            while(!stack.empty()) stack.pop();
        }
        cout << result << '\n';
    }
    return 0;
}