#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> al (26, 101);
    for(string s : keymap)
    {
        for(int i = 0; i < static_cast<int>(s.length()); i++)
        {
            if(al[s[i]-'A'] > i) al[s[i]-'A'] = i+1;
        }
    }
    
    for(string s : targets)
    {
        int n = 0;
        for(int i = 0; i < static_cast<int>(s.length()); i++)
        {
            if(al[s[i]-'A'] >= 101)
            {
                n = -1;
                break;
            }
            else n += al[s[i]-'A'];
        }
        answer.push_back(n);
    }
    return answer;
}