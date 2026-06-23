#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int t = brown + yellow;
    
    for(int h = 3; h * h <= t; h++)
    {
        if(t % h == 0)
        {
            int w = t / h;
            if((w-2)*(h-2) == yellow) return {w, h};
        }
    }
    
    return {0, 0};
}