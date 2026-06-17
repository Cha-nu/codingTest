#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> o;
    
    for(size_t i = 0; i < players.size(); i++)
    {
        o[players[i]] = i;
    }
    
    for(string c: callings)
    {
        int a = o[c];
        string pa = players[a - 1];
        
        o[c] = a-1;
        o[pa] = a;
        
        players[a-1] = c;
        players[a] = pa;
    }
    
    
    return players;
}