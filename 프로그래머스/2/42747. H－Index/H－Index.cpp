#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int n = static_cast<int>(citations.size());
    sort(citations.begin(), citations.end());
    int answer = citations[0];
    for(int h = 0; h <= n; ++h)
    {
        int cnt = 0;
        
        for(int c : citations) if(c >= h) ++cnt;
        
        if(cnt >= h && n - cnt <= h) answer = h;
    }
    return answer;
}