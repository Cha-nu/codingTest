#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int n;
int m;

bool cal(int r, int c, vector<string>& park)
{
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    else if (park[r][c] == 'X') return false;
    return true;
}


vector<int> solution(vector<string> park, vector<string> routes) {
    n = park.size();
    m = park[0].size();
    int r = -1;
    int c = -1;
    
    
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            if(park[i][j] == 'S')
            {
                r = i;
                c = j;
                break;
            }
        }
        if(r != -1 && c != -1) break;
    }
    
    for(const string& op :  routes)
    {
        stringstream ss(op);
        char a; int val;
        ss >> a >> val;
        int nr = r, nc = c;
        bool key = true;
        if(a == 'N') // 시뮬레이트
        {
            for(int i = 1; i <= val; i++)
            {
                nr = r - i;
                if(!cal(nr, c, park))
                {
                    key = false;
                    break;
                }
            }
            if(key) r = nr;
        }
        else if(a == 'E')
        {
            for(int i = 1; i <= val; i++)
            {
                nc = c + i;
                if(!cal(r, nc, park))
                {
                    key = false;
                    break;
                }
            }
            if(key) c = nc;
        }
        else if(a == 'W')
        {
            for(int i = 1; i <= val; i++)
            {
                nc = c - i;
                if(!cal(r, nc, park))
                {
                    key = false;
                    break;
                }
            }
            if(key) c = nc;
        }
        else if (a == 'S')
        {
            for(int i = 1; i <= val; i++)
            {
                nr = r + i;
                if(!cal(nr, c, park))
                {
                    key = false;
                    break;
                }
            }
            if(key) r = nr;
        }
        cout << r << ' ' << c << '\n';
    }
    return {r, c};
}