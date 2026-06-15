#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> a;
    
    for(const string& op : operations)
    {
        stringstream ss(op);
        char c; int val;
        ss >>  c >> val;
        if(c == 'I') a.insert(val);
        else if(c == 'D')
        {
            if(a.empty()) continue;
            else if(val == -1) a.erase(a.begin());
            else if(val == 1) a.erase(prev(a.end()));
        }   
    }
    
    if(a.empty()) return {0, 0};
    
    return {*(a.rbegin()), *(a.begin())};
}