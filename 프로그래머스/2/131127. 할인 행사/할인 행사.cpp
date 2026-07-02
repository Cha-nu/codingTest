#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check(unordered_map<string, int>& target, unordered_map<string, int>& window)
{
    for (auto const& [item, count] : target)
    {
        if (window[item] != count) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int result = 0;
    
    unordered_map<string, int> lst;
    
    for(int i = 0; i < static_cast<int>(want.size()); ++i) lst[want[i]] = number[i];
    
    unordered_map<string, int> window;
    
    for(int i = 0; i < 10; ++i) ++window[discount[i]];
    
    if (check(lst, window)) result++;
    
    for (int i = 10; i < discount.size(); ++i) {
        string old_item = discount[i - 10];
        window[old_item]--;
        
        window[discount[i]]++;
        
        if (check(lst, window)) result++;
    }
    
    return result;
}