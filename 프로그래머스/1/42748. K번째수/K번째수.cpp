#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    answer.reserve(commands.size());
    for(const auto& command : commands)
    {
        int start = command[0] - 1;
        int end = command[1];
        int k = command[2] - 1;
        
        vector<int> temp(array.begin() + start, array.begin() + end);
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
        
    }
    return answer;
}