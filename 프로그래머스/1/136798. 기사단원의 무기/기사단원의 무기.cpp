#include <string>
#include <vector>

using namespace std;

// 약수 개수 구하는 함수
int factorNum(int num)
{
    int result = 0;
    for(int i = 1;i <= num; i++)
    {
        if(num % i == 0) result++;
    }
    
    return result;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++)
    {
        int val = factorNum(i);
        if(val > limit) answer += power;
        else answer += val;
    }
    
    return answer;
}