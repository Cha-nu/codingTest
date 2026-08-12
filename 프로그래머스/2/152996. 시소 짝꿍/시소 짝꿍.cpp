#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    int n = static_cast<int>(weights.size());
    
    sort(weights.begin(), weights.end());
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = i-1; j >= 0; --j)
        {
            if(weights[j] == weights[i]) ++answer;
            else if(weights[j] * 3 == weights[i] * 2) ++answer;
            else if(weights[j] * 2 == weights[i]) ++answer;
            else if(weights[j] * 4 == weights[i] * 3) ++answer;
        }
    }
    
    return answer;
}