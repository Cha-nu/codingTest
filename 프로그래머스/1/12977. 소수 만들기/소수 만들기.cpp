#include <vector>
#include <cmath>
using namespace std;

int N;
int answer = 0;
// 3개를 뽑으면 합 소수 판별
bool IsPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i * i <= num; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}


void backtracking(vector<int>& nums,int idx, int sum, int depth)
{
    if(depth >= 3) // 소수 판별
    {
        if(IsPrime(sum)) answer++;
        return;
    }
    
    if(idx >= N) return; // 인덱스 초과방지
    
    backtracking(nums,idx+1, sum+nums[idx], depth+1); // 선택
    backtracking(nums,idx+1, sum, depth); // 미선택
}



int solution(vector<int> nums) {
    answer = 0;
    N = static_cast<int>(nums.size());
    backtracking(nums, 0 ,0, 0);
    return answer;
}