#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int n = static_cast<int>(queue1.size());
    
    unsigned long long sum1 = 0, sum2 = 0;
    for(int num : queue1) sum1 += num;
    for(int num : queue2) sum2 += num;
    
    unsigned long long total = sum1 + sum2;
    
    if(total % 2 != 0) return -1;
    unsigned long long target = total / 2;
    
    vector<int> q(queue1.begin(), queue1.end());
    q.insert(q.end(), queue2.begin(), queue2.end());
    
    // 투포인터
    int p1 = 0;
    int p2 = n;
    
    unsigned long long current_sum = sum1;
    
    int limit = n * 4;
    
    for(int i = 0; i <= limit; ++i)
    {
        if(current_sum == target) return i;
        if(current_sum > target)
        {
            current_sum -= q[p1 % (2 * n)];
            p1 = (p1 + 1) % (2 * n);
        }
        else
        {
            current_sum += q[p2 % (2 * n)];
            p2 = (p2 + 1) % (2 * n);
        }
    }
    
    return -1;
}