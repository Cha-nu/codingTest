#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = (long long) * min_element(times.begin(), times.end()) * n;
    
    while(left < right)
    {
        long long mid = (left + (right - left) / 2);
        
        long long m = 0;
        
        for(int time : times) m += mid / time;
        
        if(n > m) left = mid + 1;
        else right = mid;
    }
    
    return left;
}