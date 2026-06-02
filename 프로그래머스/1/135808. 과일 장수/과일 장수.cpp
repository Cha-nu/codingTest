#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end());
    while(true)
    {
        if(static_cast<int>(score.size()) < m) break;
        
        for(int i = 0; i < m; i++)
        {
            if(i == m-1)
            {
                answer += score.back()*m;
            }
            score.pop_back();
        }
    }
    return answer;
}