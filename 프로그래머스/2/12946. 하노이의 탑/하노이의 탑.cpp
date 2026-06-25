#include <vector>

using namespace std;

void hanoi(int n, int start, int to, int aux, vector<vector<int>>& answer){
    if (n == 1)
    {
        answer.push_back({start, to});
        return;
    }
    
    hanoi(n - 1, start, aux, to, answer);
    answer.push_back({start, to});
    hanoi(n - 1, aux, to, start, answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, 2, answer);
    return answer;
}