#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> matrix (rows, vector<int>(columns));
    
    // matrix 선언
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            matrix[i][j] = i * columns + j + 1;
        }
    }
    
    vector<int> answer;
    
    // 회전
    for(const vector<int>& q : queries)
    {
        int top = q[0] - 1;
        int left = q[1] - 1;
        int bottom = q[2] - 1;
        int right = q[3] - 1;
        
        int previous = matrix[top][left];
        int minimum = previous;
        
        // 왼쪽에서 오른쪽
        for(int column = left + 1; column <= right; ++column)
        {
            swap(previous, matrix[top][column]);
            minimum = min(minimum, previous);
        }
        
        // 위에서 아래
        for(int row = top + 1; row <= bottom; ++row)
        {
            swap(previous, matrix[row][right]);
            minimum = min(minimum, previous);
        }
        
        // 오른쪽에서 왼쪽
        for(int column = right - 1; column >= left; --column)
        {
            swap(previous, matrix[bottom][column]);
            minimum = min(minimum, previous);
        }
        
        // 아래에서 위쪽
        for (int row = bottom - 1; row >= top; --row) {
            swap(previous, matrix[row][left]);
            minimum = min(minimum, previous);
        }
        
        answer.push_back(minimum);
    }
    
    return answer;
}