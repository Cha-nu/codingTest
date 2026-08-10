#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = arrayA[0];
    int gcdB = arrayB[0];
    
    for(int i = 0; i < arrayA.size(); ++i)
    {
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    int answer = 0;
    
    bool pa = true;
    
    for(int ab : arrayB)
    {
        if(ab % gcdA == 0)
        {
            pa = false;
            break;
        }
    }
    
    if(pa) answer = max(answer, gcdA);
    
    
    pa = true;
    
    for(int ab : arrayA)
    {
        if(ab % gcdB == 0)
        {
            pa = false;
            break;
        }
    }
    
    if(pa) answer = max(answer, gcdB);
    
    return answer;
}