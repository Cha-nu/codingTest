#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int row = 0, col = 0;
    for(int i = 0; i < static_cast<int>(sizes.size()); i++)
    {
        int currentRow = 0;
        int currentCol = 0;
        // 큰 것을 row로
        if(sizes[i][0] > sizes[i][1])
        {
            currentRow = sizes[i][0];
            currentCol = sizes[i][1];
        }
        else
        {
            currentRow = sizes[i][1];
            currentCol = sizes[i][0];
        }
        row = max(row, currentRow);
        col = max(col, currentCol);
    }
    return row*col;
}