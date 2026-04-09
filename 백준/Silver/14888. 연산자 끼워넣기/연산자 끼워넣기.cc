#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> nums;
vector<int> ari(4); // 덧셈, 뺄셈, 곱셈, 나눗셈
vector<long long> result;
long long maxresult = -1000000001, minresult = 1000000001;


void calc(int idx)
{
    if(idx >= n)
    {
        if(maxresult < result.back()) maxresult = result.back();
        if(minresult > result.back()) minresult = result.back();
        return; // 종료조건
    }
    if(ari[0] >= 1) // 덧셈
    {
        result.push_back(result.back() + nums[idx]);
        ari[0]--;
        calc(idx+1);
        result.pop_back();
        ari[0]++;
    }
    if(ari[1] >= 1) // 뺄셈
    {
        result.push_back(result.back() - nums[idx]);
        ari[1]--;
        calc(idx+1);
        result.pop_back();
        ari[1]++;
    }
    if(ari[2] >= 1) // 곱셈
    {
        result.push_back(result.back() * nums[idx]);
        ari[2]--;
        calc(idx+1);
        result.pop_back();
        ari[2]++;
    }
    if(ari[3] >= 1) // 나눗셈
    {
        result.push_back(result.back() / nums[idx]);
        ari[3]--;
        calc(idx+1);
        result.pop_back();
        ari[3]++;
    }
}

int main()
{
    cin >> n;
    nums.resize(n);

    for(int& num : nums) cin >> num;
    for(int& a : ari) cin >> a;

    result.push_back(nums[0]);
    calc(1);

    cout << maxresult << '\n' << minresult;
    return 0;
}