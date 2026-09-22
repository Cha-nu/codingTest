#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    answer.reserve(s.size());
    
    for(int i = 0; i < s.size(); ++i)
    {
        bool key = false;
        int cnt = 1;
        for(int j = i-1; j >= 0; --j)
        {
            if(s[i] == s[j])
            {
                key = true;
                answer.push_back(cnt);
                break;
            }
            ++cnt;
        }
        if(key == false) answer.push_back(-1);
    }
    
    return answer;
}