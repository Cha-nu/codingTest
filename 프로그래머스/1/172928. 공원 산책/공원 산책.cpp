#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

unordered_map<char, int> r = {{'S', 0}, {'N', 1}, {'E', 2}, {'W', 3}};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int sr, sc;
    bool key = false;
    
    int cr = static_cast<int>(park.size());
    int cc = static_cast<int>(park[0].size());
    
    // 출발지 선택
    for(int r = 0; r < cr; ++r)
    {
        for(int c = 0; c < cc; ++c)
        {
            if(park[r][c] == 'S')
            {
                sr = r;
                sc = c;
                break;
            }
        }
        if(key) break;
    }
    
    for(string ro : routes)
    {
        stringstream ss(ro);
        char cmd;
        int val;
        ss >> cmd >> val;
        
        int nr = sr;
        int nc = sc;
        key = true;
        
        while(val--)
        {
            nr+= dr[r[cmd]];
            nc+= dc[r[cmd]];    
               
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