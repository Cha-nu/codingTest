#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> dq;
    
    for(const string& op : operations)
    {
        stringstream ss(op);
        char cmd;
        int val;
        ss >> cmd >> val;
        
        if(cmd == 'I') dq.insert(val);
        else if(cmd == 'D')
        {
            if(dq.empty()) continue;
            if(val == 1)
            {
                auto it = prev(dq.end());
                dq.erase(it);
            }
            else if(val == -1) dq.erase(dq.begin());
        }
    }
    
    if(dq.empty()) return {0, 0};
    
    
    int m = *dq.rbegin();
    int n = *dq.begin();
    
    return {m, n};
}