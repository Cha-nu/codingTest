#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    for(int i = 3; i <= yellow+2; i++)
    {
        for(int j = 3; j <= i; j++)
        {
            if(i*j == (brown + yellow) && (i - 2) * (j - 2) == yellow) return {i, j};
        }
    }
    
    return {0, 0};
}