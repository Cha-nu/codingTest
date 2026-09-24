#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; ++i)
    {
        int map = arr1[i] | arr2[i]; // 비트 연산
        string row(n, ' ');
        
        for(int j = n-1; j >= 0; --j)
        {
            if(map & 1) row[j] = '#';
            
            map >>= 1;
        }
        answer.push_back(row);
        
    }
    
    return answer;
}