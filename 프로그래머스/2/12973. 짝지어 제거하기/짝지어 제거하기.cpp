#include <stack>
#include<string>
using namespace std;


int solution(string s)
{
    stack<int> stk;

    for(char c : s)
    {
        if(stk.empty() || c != stk.top()) stk.push(c);
        else if(stk.top() == c) stk.pop();
    }
    return stk.empty();
}