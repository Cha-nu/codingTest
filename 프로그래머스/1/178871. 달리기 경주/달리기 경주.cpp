#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> m;
    
    for(int i = 0; i < static_cast<int>(players.size()); i++)
    {
        m[players[i]] = i;
    }
    
    for(string s : callings)
    {
        int idx = m[s];
        int pidx = idx-1;
        
        string a = players[pidx];
        
        players[idx] = a;
        players[pidx] = s;
        
        m[s] = pidx;
        m[a] = idx;
    }
    return players;
}