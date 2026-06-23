#include <iostream>
#include <queue>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    queue<int> q;
    
    for(int i = 1; i <= n; i++) q.push(i);
    
    while(true)
    {
        answer++;
        int n = static_cast<int>(q.size());
        for(int i = 0; i < n/2; i++)
        {
            int r = q.front();
            q.pop();
            int c = q.front();
            q.pop();
            
            if( (r == a || r == b )&& (c == a || c == b)) return answer;
            else if((c == a || c == b)) q.push(c);
            else q.push(r);
        }
    }
 

    return answer;
}