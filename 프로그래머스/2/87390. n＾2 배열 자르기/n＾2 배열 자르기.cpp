#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    answer.reserve(right - left + 1);
    
    for(unsigned long long i = left; i < right+1;++i)
    {
        unsigned long long row = i / n;
        unsigned long long col = i % n;
        answer.push_back(max(row, col)+1);
    }
    
    return answer;
}