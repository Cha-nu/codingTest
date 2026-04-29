#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> nums;
    long long answer = 0;
    while(n)
    {
        nums.push_back(n%3);
        n /= 3;
    }
    long long power = 1;
    for(int i = (int)nums.size() - 1; i >= 0; i--)
    {
        answer += (long long)nums[i] * power;
        power *= 3;
    }
    
    return (int)answer;
}