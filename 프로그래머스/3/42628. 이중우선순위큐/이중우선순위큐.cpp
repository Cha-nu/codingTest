#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> dq;
    
    for(const string& op: operations)
    {
        stringstream ss(op);
        char c;
        int val;
        
        ss >> c >> val;
        
        if(c == 'I') dq.insert(val);
        else if(c == 'D')
        {
            if(!dq.empty())
            {
                if(val == 1) dq.erase(*prev(dq.end()));
                else if(val == -1) dq.erase(dq.begin());
            }
        }
        
    }
    if(dq.empty()) return {0, 0};
    
    return {*dq.rbegin(), *dq.begin()};
}
