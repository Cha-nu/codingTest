#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    vector<int> al (26, -1);
    
    for(string k : keymap) for(int i = 0; i < static_cast<int>(k.size()); i++) if(al[k[i] - 'A'] == -1 || al[k[i] - 'A'] > i) al[k[i] - 'A'] = i+1;
    
    for(string k : targets)
    {
        int sum = 0;
        for(int i = 0; i < static_cast<int>(k.size()); i++)
        {
            if(al[k[i] - 'A'] == -1)
            {
                sum = -1;
                break;
            }
            else
            {
                sum += al[k[i] - 'A'];
            }
        }
        answer.push_back(sum);
    }
    
    
    return answer;
}