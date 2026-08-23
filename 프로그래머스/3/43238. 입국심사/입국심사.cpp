#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = (long long)*min_element(times.begin(), times.end()) * n;
    
    while(left < right)
    {
        long long mid = (left + right) / 2; //Time
        long long m = 0;
        for(int time: times) m += mid / time;
        if(m >= n) right = mid;
        else left = mid + 1;
    }
    return left;
}