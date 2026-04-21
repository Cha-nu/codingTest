class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result (2, 0);
        // 합하여 target이 되는 두 수 찾기
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(nums[i]+nums[j] == target)
                {
                    if(i > j)
                    {
                        result[0] = j;
                        result[1] = i;
                    }
                    else
                    {
                        result[0] = i;
                        result[1] = j;
                    }
                    return result;
                }
            }
        }
        return result;
    }
};