#include <string>
#include <vector>

using namespace std;


int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    vector<bool> wall (n+1, true);
    
    for(int s : section) // 초기화
    {
        wall[s] = false;
    }
    
    while(!section.empty())
    {
        int idx = section.back();
        section.pop_back();
        if(wall[idx] == true) continue;
        
        for(int i = idx; (i > idx-m && i > 0); i--)
        {
            wall[i] = true;
        }
        answer++;
    }
    
    return answer;
}