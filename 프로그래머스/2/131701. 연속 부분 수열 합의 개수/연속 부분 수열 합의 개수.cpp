#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int sz = static_cast<int>(elements.size());
    
    unordered_set<int> s; // 연속 부분 수열의 합
    
    // 원형 수열
    vector<int> c = elements;
    c.insert(c.end(), elements.begin(), elements.end());
    
    for(int i = 0; i < sz; ++i)
    {
        int sum = 0; // 연속 부분 수열 합 계산
        for(int j = 0; j < sz; ++j)
        {
            sum += c[i+j]; // {0, 0}, {0, 1}, {0, 2} 점점 더해짐
            s.insert(sum); // 합 중복 제거
        }
    }
    
    return static_cast<int>(s.size());
}