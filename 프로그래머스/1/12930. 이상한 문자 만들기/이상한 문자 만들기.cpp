#include <string>

using namespace std;

string solution(string s) {
    int idx = 0;
    for(int i = 0; i < static_cast<int>(s.length()); i++)
    {
        if(s[i] == ' ')
        {
            idx = 0; // 단어별로 공백확인
            continue;
        }
        if(idx % 2 == 0)
        {
            if(s[i] >= 97) s[i] -= 32;
        }
        else
        {
            if(s[i] < 97) s[i] += 32;
        }
        idx++;
    }
    return s;
}