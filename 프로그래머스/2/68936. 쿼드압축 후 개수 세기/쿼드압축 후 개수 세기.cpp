#include <vector>

using namespace std;

int cnt_zero = 0;
int cnt_one = 0;

void ComQuadTree(const vector<vector<int>>& arr, int r, int c, int sz)
{
    int init_val = arr[r][c];
    bool bIsUniform = true;
    
    for(int i = r; i < r + sz; ++i)
    {
        for(int j = c; j < c + sz; ++j)
        {
            if(arr[i][j] != init_val)
            {
                bIsUniform = false;
                break;
            }
        }
        if(!bIsUniform) break;
    }
    
    if(bIsUniform)
    {
        if(init_val == 0) ++cnt_zero;
        else ++cnt_one;
    }
    else
    {
        int half_size = sz / 2;
        
        ComQuadTree(arr, r, c, half_size);
        ComQuadTree(arr, r, c + half_size, half_size);
        ComQuadTree(arr, r + half_size, c, half_size);
        ComQuadTree(arr, r + half_size , c + half_size, half_size);
    }
    
}


vector<int> solution(vector<vector<int>> arr) { 
    cnt_zero = 0;
    cnt_one = 0;
    
    int init_sz = static_cast<int>(arr.size());
    
    ComQuadTree(arr, 0, 0, init_sz);
    
    return {cnt_zero, cnt_one};
}