#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> m;
    
    for(int n : nums) ++m[n];
    
    int answer = (nums.size()/2 > m.size()) ? m.size() : nums.size()/2;
    
    return answer;
}