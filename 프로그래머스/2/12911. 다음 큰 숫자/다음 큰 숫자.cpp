#include <string>
#include <vector>

using namespace std;

int cnt(int n)
{
    int c = 0;
    while(n > 0)
    {
        c += n % 2;
        n /= 2;
    }
    return c;
}


int solution(int n) {
    int answer = 0;
    
    int m = cnt(n);
    int i = n+1;
    
    while(true)
    {
        int k = cnt(i);
        if(m == k) return i;
        ++i;
    }
}