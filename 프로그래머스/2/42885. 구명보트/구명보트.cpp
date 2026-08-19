#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
    sort(people.begin(), people.end(), greater());
    
    while(idx < people.size())
    {
        int l = limit;
        l -= people[idx++];
        ++answer;
        if(l >= people.back()) people.pop_back();
    }
    
    
    return answer;
}