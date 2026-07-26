#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check(unordered_map<string, int>& target, unordered_map<string, int>& window)
{
    for(auto const&[item, count] : target) if(window[item] != count) return false;
    return true;
}



int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> target;
    unordered_map<string, int> window;
    
    for(int i = 0; i < static_cast<int>(want.size()); ++i) target[want[i]] = number[i];
    for(int i = 0; i < 10; ++i) ++window[discount[i]];
    
    if(check(target, window)) ++answer;
    
    for(int i = 10; i < static_cast<int>(discount.size()); ++i)
    {
        string olditem = discount[i - 10];
        --window[olditem];
        ++window[discount[i]];
        
        if(check(target, window)) ++answer;
    }
    
    return answer;
}