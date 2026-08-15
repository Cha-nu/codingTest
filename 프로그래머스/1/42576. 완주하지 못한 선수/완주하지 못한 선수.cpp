#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> m;
    for(string c : completion) m[c] += 1;
    
    for(string p : participant)
    {
        if(m[p] < 1) return p;
        else m[p] -= 1;
    }
    
    
    
    return answer;
}