#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> cls;
    
    for(int t : tangerine) ++cls[t];
    
    vector<pair<int, int>> box (cls.begin(), cls.end());
    sort(box.begin(), box.end(), cmp);
    
    for(auto const&[i, j] : box)
    {
        k -= j;
        ++answer;
        if(k <= 0) return answer;
    }
    
    return answer;
}