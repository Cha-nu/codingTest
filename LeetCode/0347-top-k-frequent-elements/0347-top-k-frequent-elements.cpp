#include <map>
#include <algorithm>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> num_map;
        vector<int> result;
        vector<pair<int, int>> temp;

        for(int num : nums) num_map[num]++;

        for(auto i : num_map) temp.push_back({i.second, i.first});
    
        sort(temp.rbegin(), temp.rend());
        // k순위까지 result;
        for(int i = 0; i < k; i++) result.push_back(temp[i].second);

        return result;
    }
};