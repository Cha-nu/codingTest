#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> counts(number + 1, 0);
    
    // 에라토스테네스의 체
    for (int i = 1; i <= number; i++) 
    {
        for (int j = i; j <= number; j += i) 
        {
            counts[j]++;
        }
    }
    
    for(int i = 1; i <= number; i++)
    {
        if(counts[i] > limit) answer += power;
        else answer += counts[i];
    }
    
    return answer;
}