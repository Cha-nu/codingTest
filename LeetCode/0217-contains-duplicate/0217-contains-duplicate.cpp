#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        m.reserve(nums.size());
        for(int num : nums)
        {
            if(!m.insert(num).second) return true;
        }
        return false;
    }
};