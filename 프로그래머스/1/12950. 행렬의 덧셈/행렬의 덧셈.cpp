#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    size_t n = arr1.size();
    size_t m = arr1[0].size();
    vector<vector<int>> answer (n, vector<int>(m, 0));
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            answer[i][j] = arr1[i][j]+ arr2[i][j] ;
        }
    }
    
    return answer;
}