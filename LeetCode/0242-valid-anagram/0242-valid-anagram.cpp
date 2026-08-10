#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>  a;
        if (s.size() != t.size()) {
      return false;
    }

    std::vector<int> s_counts(26, 0);
    std::vector<int> t_counts(26, 0);      

    for (int i = 0; i < s.size(); ++i) {
      s_counts[s[i] - 'a']++;
      t_counts[t[i] - 'a']++;
    }

    return s_counts == t_counts;
  }
};