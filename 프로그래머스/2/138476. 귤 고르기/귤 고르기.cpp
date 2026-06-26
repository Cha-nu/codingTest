#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a,const pair<int, int>& b)
{
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    for(int t : tangerine) m[t]++;
    
    vector<pair<int, int>> v (m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        k -= i->second;
        ++answer;
        if(k <= 0) return answer;
    }
    
    return answer;
}