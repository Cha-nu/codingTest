#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    int total = 0;
    for(int w : works) total+= w;
    if(total <= n) return 0;
    
    priority_queue<int> pq (works.begin(), works.end());
    // 최댓값을 줄이는 방식
    while(n-- && !pq.empty())
    {
        int val = pq.top() - 1;
        pq.pop();
        if(val > 0) pq.push(val);
    }
    
    while(!pq.empty())
    {
        int i = pq.top();
        pq.pop();
        answer += i*i;
    }
    
    return answer;
}