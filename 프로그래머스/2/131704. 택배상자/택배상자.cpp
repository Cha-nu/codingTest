#include <stack>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> order)
{
    int answer = 0;
    
    int n = static_cast<int>(order.size());
    
    queue<int> con;
    for(int i = 1; i <= n; ++i) con.push(i);
    stack<int> st;
    
    // queue와 order 같은 지 확인
    for(int i = 0; i < n; ++i)
    {
        bool key = false;
        
        if(!st.empty() && st.top() == order[i])
        {
            st.pop();
            ++answer;
            key = true;
        }
        else
        {
            while(!con.empty())
            {
                int q = con.front();
                con.pop();
                if(q == order[i])
                {
                    ++answer;
                    key = true;
                    break;
                }
                else st.push(q);
            }
        }
        if(!key) return answer;
    }
    return answer;
}