#include <queue>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    
    int tw = 0;
    for(int w : works)tw += w;
    if(tw <= n) return 0;
    
    priority_queue<int> pq(works.begin(), works.end());
    
    while(n-- && !pq.empty())
    {
        int a = pq.top() - 1;
        pq.pop();
        
        if(a > 0) pq.push(a);
    }
    
    while(!pq.empty())
    {
        int a = pq.top();
        pq.pop();
        answer += a * a;
    }
    
    return answer;
}