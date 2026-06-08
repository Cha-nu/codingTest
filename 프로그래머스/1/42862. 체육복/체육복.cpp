#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> p (n+2, 0); // -1: lost, 0: normal, 1: reserve
    
    for(int i : reserve) p[i] = 1;
    for(int i : lost)
    {
        if(p[i] == 0) p[i] = -1;
        else p[i] = 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(p[i] == -1)
        {
            if(p[i-1] == 1)
            {
                answer++;
                p[i-1] = 0;
            }
            else if(p[i+1] == 1)
            {
                {
                answer++;
                p[i+1] = 0;
                }
            }
        }
        else answer++;
    }
        
    return answer;
}