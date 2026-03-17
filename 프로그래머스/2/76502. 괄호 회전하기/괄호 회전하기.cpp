#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, char> bracketPair = {{')', '('},{']', '['}, {'}','{'}};

bool isVaild(string &s, int start)
{
    stack<char> stk;
    unsigned int sz = s.size();
    
    for(int i = 0; i < sz; i++)
    {
        char ch = s[(start + i) % sz];
        if(bracketPair.count(ch))
        {
            if(stk.empty() || stk.top() != bracketPair[ch]) return false;
            stk.pop();
        }
        else
        {
            stk.push(ch);    
        }
    }
    return stk.empty();
}


int solution(string s) {
    int answer = 0;
    
    for(int start = 0; start < s.size(); start++)
    {
        answer += isVaild(s, start);
    }
    return answer;
}