#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

int solution(vector<int> arr) {
    int a = (arr[0]*arr[1])/gcd(arr[0], arr[1]);
    
    for(size_t b = 2; b < arr.size(); ++b)
    {
        a = (a*arr[b])/gcd(a, arr[b]);
    }
    
    
    return a;
}