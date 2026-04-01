#include <algorithm>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> num;
    while(n > 0)
    {
        num.push_back(n%10);
        n /= 10;
    }
    sort(num.rbegin(), num.rend());
    for(int i : num)
    {
        answer = (answer*10) + i;
    }
    return answer;
}