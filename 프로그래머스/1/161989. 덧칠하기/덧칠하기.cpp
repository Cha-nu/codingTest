#include <string>
#include <vector>

using namespace std;


int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int current = n;
    
    while(!section.empty())
    {
        int idx = section.back();
        section.pop_back();
        if(idx > current) continue;
        current = idx - m;
        answer++;
    }
    return answer;
}