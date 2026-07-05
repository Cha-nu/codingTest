#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int idx = 0;
    
    while(idx < static_cast<int>(progresses.size()))
    {
        for(int i = 0; i < static_cast<int>(progresses.size()); ++i) progresses[i] += speeds[i];
        
        int cnt = 0;
        while(progresses[idx] >= 100 && idx < static_cast<int>(progresses.size()))
        {
            cout << progresses[idx] << '\n';
            ++cnt;
            ++idx;
        }
        if(cnt > 0) answer.push_back(cnt);
    }
    
    return answer;
}