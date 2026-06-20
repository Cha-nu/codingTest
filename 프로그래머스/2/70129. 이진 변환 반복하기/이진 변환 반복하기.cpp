#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer (2, 0);
    
    while(s != "1")
    {
        int cnt = 0;
        for(char a : s)
        {
            if(a == '1') cnt++;
            if(a == '0') answer[1]++;
        }
        answer[0]++;
        s = "";
        while(cnt != 0)
        {
            if (cnt % 2 == 1) s += "1";
            else s+= "0";
  
            cnt /= 2; 
        }
    }
    
    
    return answer;
}