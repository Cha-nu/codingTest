#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int n)
{
    vector<int> memo (n+1);
    int result = 0;
    
    while(n > 0)
    {
        if(n % 2 == 0) n/=2;
        else
        {
            n-=1;
            ++result;
        }
    }

    return result;
}