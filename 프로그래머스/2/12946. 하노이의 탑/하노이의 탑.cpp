#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void h(int n, int start, int to, int aux, vector<vector<int>>& answer)
{
    if(n == 1)
    {
        answer.push_back({start, to});
        return;
    }
    
    h(n-1, start, aux, to, answer);
    answer.push_back({start, to});
    h(n-1, aux, to, start, answer);
    
    
    return;
}


vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    h(n, 1, 3, 2, answer);
    
    return answer;
}