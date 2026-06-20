#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> um;
    
    for(size_t i = 0; i < players.size(); i++) um[players[i]] = i;
    
    for(string c : callings)
    {
        int i = um[c];
        int j = i - 1;
        string p = players[j];
        
        um[c] = j;
        um[p] = i;
        
        players[j] = c;
        players[i] = p;
    }
    
    
    return players;
}