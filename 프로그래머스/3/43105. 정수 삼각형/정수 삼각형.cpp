#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = static_cast<int>(triangle.size());
    int m = static_cast<int>(triangle[n-1].size());
    vector<vector<int>> memo (n, vector<int> (m)); // 바텀업
    
    for(int j = 0; j < m; j++) memo[n-1][j] = triangle[n-1][j]; // 초기 상태 
    
    for(int i = n-2; i >= 0; i--)
    {
        for(int j = 0; j < static_cast<int>(triangle[i].size()); j++)
        memo[i][j] = triangle[i][j] + max(memo[i+1][j], memo[i+1][j+1]);
    }
    answer = memo[0][0];
    return answer;
}
