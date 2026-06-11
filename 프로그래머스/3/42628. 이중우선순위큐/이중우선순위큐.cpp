#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> s;
    for(const string& op: operations)
    {
        stringstream ss(op);
        char cmd;
        int n;
        ss >> cmd >> n;
        if(cmd == 'I') s.insert(n);
        else if(cmd == 'D')
        {
            if(s.empty()) continue;
            if(n == 1) s.erase(prev(s.end()));
            else if (n == -1) s.erase(s.begin());
        }
    }
    if(s.empty()) return {0, 0};
    
    return {*s.rbegin(), *s.begin()};
}