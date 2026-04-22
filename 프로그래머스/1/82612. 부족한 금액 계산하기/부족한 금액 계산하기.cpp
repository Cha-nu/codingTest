#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    unsigned long long Nprice = 0;
    
    for(int i = 1; i <= count; i++)
    {
        Nprice += price*i;
    }
    answer = Nprice - money; 
    if(answer > 0) return answer;
    else return 0;
}