class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            anagramGroups[key].push_back(s);

        }
        vector<vector<string>> result;
        result.reserve(anagramGroups.size());
        for(auto& pair : anagramGroups) result.push_back(std::move(pair.second));
        
        return result;
    }
};