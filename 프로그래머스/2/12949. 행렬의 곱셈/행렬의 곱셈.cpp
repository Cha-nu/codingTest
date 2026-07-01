#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int a = static_cast<int>(arr1.size());
    int b = static_cast<int>(arr1[0].size());
    int c = static_cast<int>(arr2[0].size());
    
    vector<vector<int>> answer (a, vector<int> (c, 0));
    
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            for(int k = 0; k < b; ++k) answer[i][j] += arr1[i][k] * arr2[k][j];
        }
    }
    
    return answer;
}