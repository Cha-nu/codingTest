#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    
    for(int a : d)
    {
        if(a <= budget)
        {
            budget -= a;
            ++answer;
        }
        else break;
    }
    
    
    return answer;
}