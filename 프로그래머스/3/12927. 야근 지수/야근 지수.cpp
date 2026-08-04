#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int t = 0;
    
    for(int w : works) t += w;
    if(t <= n) return 0;
    
    priority_queue<long long> pq = {works.begin(), works.end()};
    
    while(n--) // 야근
    {
        int w = pq.top();
        pq.pop();
        --w;
        if(w > 0) pq.push(w);
    }
    
    while(!pq.empty())
    {
        int w = pq.top();
        pq.pop();
        answer += w*w;
    }
    
    return answer;
}