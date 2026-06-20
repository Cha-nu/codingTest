#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<vector<int>> drdc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

unordered_map<char, int> c = {{'S', 0}, {'N', 1}, {'E', 2}, {'W', 3}};


vector<int> solution(vector<string> park, vector<string> routes) {
    int sr = 0, sc = 0;
    
    int cr = static_cast<int>(park.size());
    int cc = static_cast<int>(park[0].size());
    
    for(size_t i = 0; i < cr; i++)
    {
        for(size_t j = 0; j < cc; j++)
        {
            if(park[i][j] == 'S')
            {
                sr = i, sc = j;
                break;
            }
        }
    }
    
    for(const string& r : routes)
    {
        stringstream ss(r);
        char cmd;
        int val;
        ss >> cmd >> val;
        
        int nr = sr;
        int nc = sc;
        bool key = true;
        
        for(int i = 0; i < val; i++)
        {
            nr += drdc[c[cmd]][0];
            nc += drdc[c[cmd]][1];
            if(nr < 0 || nr >= cr || nc < 0 || nc >= cc || park[nr][nc] == 'X')
            {
                key = false;
                break;
            }
        }
        if(key)
        {
            sr = nr;
            sc = nc;
        }
        
    }
    
    return {sr, sc};
}