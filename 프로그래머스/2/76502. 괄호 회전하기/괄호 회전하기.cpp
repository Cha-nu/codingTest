#include <string>
#include <stack>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();
    
    for(int start = 0; start < n; start++)
    {
        bool key = true;
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            char c = s[(start + i) % n];
            
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(c == ')')
            {
                if(st.empty())
                {
                    key = false;
                    break;
                }
                else
                {
                    char d = st.top();
                    st.pop();
                    if(d != '(')
                    {
                        key = false;
                        break;
                    }
                }
            }
            else if(c == '}')
            {  
                if(st.empty())
                {
                    key = false;
                    break;
                }
                else
                {
                    char d = st.top();
                    st.pop();
                    if(d != '{')
                    {
                        key = false;
                        break;
                    }
                }
            }
            else if(c == ']')
            {
                if(st.empty())
                {
                    key = false;
                    break;
                }
                else
                {
                    char d = st.top();
                    st.pop();
                    if(d != '[')
                    {
                        key = false;
                        break;
                    }
                }
            }
        }
        if(key && st.empty()) answer++;     
    }
    return answer;
}