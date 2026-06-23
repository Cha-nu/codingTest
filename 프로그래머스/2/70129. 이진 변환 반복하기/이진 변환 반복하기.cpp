#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer (2, 0);
    
    while(s != "1")
    {
        int cnt = 0;
        ++answer[0];
        for(char c: s)
        {
            if(c == '1') ++cnt;
            else if(c == '0') ++answer[1];
        }
        s = "";
        
        while(cnt != 0)
        {
            s += (cnt % 2) +'0';
            cnt /= 2;
        }
    }
    
    
    return answer;
}