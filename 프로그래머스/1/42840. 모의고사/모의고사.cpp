#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> patterns = { // 수포자들의 찍는 패턴
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
    
    vector<int> scores(3, 0); // 각 수포자 점수
    
    // 채점
    for(int i = 0; i < answers.size(); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (answers[i] == patterns[j][i % patterns[j].size()]) scores[j]++;
        }
    }
    
    // 최댓값 찾기
    int max_score = *max_element(scores.begin(), scores.end());
    
    // 최댓값과 일치하는 수포자 추출
    vector<int> answer;
    for (int i = 0; i < 3; i++) if(scores[i] == max_score) answer.push_back(i+1);
    
    return answer;
}