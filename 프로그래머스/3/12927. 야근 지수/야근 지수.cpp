#include <queue>
#include <vector>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int t = 0;
    for(int w : works) t+=w; 
    if(n >= t) return 0;
    
    priority_queue<int> pq(works.begin(), works.end());
    
    while(n--)
    {
        t = pq.top();
        pq.pop();
        --t;
        
        if(t > 0) pq.push(t);
    }
    
    while(!pq.empty())
    {
        t = pq.top();
        pq.pop();
        answer += t*t;
    }
    
    return answer;
}