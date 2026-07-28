#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> triangle(n, vector<int>(n, 0));
    
    int row = -1;
    int col = 0;
    int num = 1;
    
    // i는 방향 상태 (0: 아래, 1: 오른쪽, 2: 대각선 위)
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if(i % 3 == 0) ++row; // 짝수행 3의 배수이면 행 넘어감
            else if(i % 3 == 1) ++col;
            else if(i % 3 == 2) // 홀수행 
            {
                --row;
                --col;
            }
            
            triangle[row][col] = num++;
        }
    }
    
    for(int i = 0; i < n; ++i) for(int j = 0; j <= i; ++j) answer.push_back(triangle[i][j]);
    
    
    return answer;
}