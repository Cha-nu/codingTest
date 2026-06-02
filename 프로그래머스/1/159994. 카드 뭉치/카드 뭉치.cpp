#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0;
    int idx2 = 0;
    
    for(string const& s : goal)
    {
        if(idx1 < cards1.size() && s == cards1[idx1]) idx1++;
        else if (idx2 < cards2.size() && s == cards2[idx2]) idx2++;
        else return "No";
    }
    return "Yes";
}