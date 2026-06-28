#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> m;
    for(size_t i = 0; i < players.size(); ++i) m[players[i]] = i;
    
    for(string c : callings)
    {
        int idx = m[c];
        int prev = idx - 1;
        
        string a = players[prev];
        
        players[prev] = c;
        players[idx] = a;
        
        m[c] = prev;
        m[a] = idx;
    }
    return players;
}