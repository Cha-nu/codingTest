#include <string>
#include <vector>
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int counts[26] = {0};
        for(char letter : magazine)
        {
            counts[letter - 'a']++;
        }
        for(char letter : ransomNote)
        {

            if(--counts[letter - 'a'] < 0) return false;
        }
        return true;


        // for(char letter : ransomNote)
        // {
        //     if(magazine.find(letter) != string::npos)
        //     {
        //         // cout << letter << '\n';
        //         int idx = magazine.find(letter);
        //         // cout << idx << '\n';
        //         magazine.erase(idx, 1);
                
        //     }
        //     else return false;
        // }
        // return true;
    }
};