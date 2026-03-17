#include <stack>
#include <string>

using namespace std;

bool isValid(const string &s, int start, int n) {
    stack<char> stk;
    for(int i = 0; i < n; i++) {
        char ch = s[(start + i) % n];
        // Map 대신 switch를 사용하면 컴파일러가 Jump Table로 최적화하여 매우 빠름
        switch(ch) {
            case '(': case '{': case '[':
                stk.push(ch);
                break;
            case ')':
                if(stk.empty() || stk.top() != '(') return false;
                stk.pop();
                break;
            case '}':
                if(stk.empty() || stk.top() != '{') return false;
                stk.pop();
                break;
            case ']':
                if(stk.empty() || stk.top() != '[') return false;
                stk.pop();
                break;
        }
    }
    return stk.empty();
}



int solution(string s) {
    int answer = 0;
    int n = s.size();
    for(int start = 0; start < n; start++)
    {
        answer += isValid(s, start, n);
    }
    return answer;
}