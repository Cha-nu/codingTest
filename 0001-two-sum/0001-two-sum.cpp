class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map <int, int> num_table;
        // 합하여 target이 되는 두 수 찾기
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int remain = target - nums[i];
            if(num_table.count(remain))
            {
                return {num_table[remain], i};
            }
            num_table[nums[i]] = i;
        }
        return {};
    }
};