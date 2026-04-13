#include <iostream>
#include <vector>
#include <queue>

using namespace std;


vector<vector<int>> lab; // 전부 벽으로 채우기
vector<pair<int, int>> drdc = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> fvirus;

int result = 0;
short n, m;

void spread() /*모든 0을 돌아가면서 막아본다. O(nm^3)*/
{ 
    vector<vector<int>> simul = lab;
    int cnt = 0;
    queue<pair<int, int>> q;  //(row, col)
    // 초기 바이러스 위치
    for(int i = 0; i < fvirus.size(); i++)
    {
        int raw = fvirus[i].first;
        int col = fvirus[i].second;
        q.push({raw, col});
    }

    while(!q.empty()) 
    {
        int raw = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++)
        {
            int dr = raw+drdc[k].first;
            int dc = col+drdc[k].second;
            if(simul[dr][dc] == 0) // 넣을때 처리
            {
                simul[dr][dc] = 2;
                q.push({dr, dc});
            }
        }  
    }

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            if(simul[i][j] == 0) cnt++;
        }
    }
    result = max(result, cnt);
}

void backtracking(int start, int depth)
{
    if(depth == 3)
    {
        spread();
        return;
    }

    // 1부터 n*m;
    for(;start < n*m; start++)
    {   
        int r = (start / m) + 1;
        int c = (start % m) + 1;
        if (lab[r][c] == 0)
        {
            lab[r][c] = 1;
            backtracking(start + 1, depth + 1);
            lab[r][c] = 0;
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    lab.resize(n+2, vector<int>(m+2, 1));

    for(int i = 1; i < n+1; i++)
    {
        for(int j = 1; j < m+1; j++)
        {
            int val;
            cin >> val;
            lab[i][j] = val;
            if(val == 2) fvirus.push_back({i, j});
        }
    }

    backtracking(0, 0);

    
    cout << result;
    return 0;

}