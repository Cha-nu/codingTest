#include <map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int>  a;
        if(s.length() < t.length())
        {
            for(char st : s)
            {
                if(a.find(st) != a.end()) a[st]++;
                else a[st] = 1;
            }
            for(char st : t)
            {
                if(a.find(st) != a.end() && a[st] > 0)a[st]--;
                else return false;
            }
        }
        else
        {
            for(char st : t)
            {
                if(a.find(st) != a.end()) a[st]++;
                else a[st] = 1;
            }
            for(char st : s)
            {
                if(a.find(st) != a.end() && a[st] > 0)a[st]--;
                else return false;
            }
        }
    return true;
    }
};