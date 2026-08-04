#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> answer;
    
    for(const string& op :operations)
    {
        char c;
        int num;
        stringstream ss(op);
        
        ss >> c >> num;
        
        if(c == 'I') answer.insert(num);
        else if(c == 'D' && !answer.empty())
        {
            if(num == 1) answer.erase(*prev(answer.end()));
            else answer.erase(answer.begin());
        }
    }
    
    if(answer.empty()) return {0, 0};
    
    
    
    return {*answer.rbegin(), *answer.begin()};
}