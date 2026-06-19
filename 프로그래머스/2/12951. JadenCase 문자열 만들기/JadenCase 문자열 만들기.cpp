#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool key = true;
    
    for(char a : s)
    {
        if(key && a >= 'a' && a <= 'z')
        {
            key = false;
            answer += (a - 32);
        }
        else if(a == ' ')
        {
            key = true;
            answer += a;
        }
        else if(!key && a >= 'A' && a <= 'Z')
        {
            key = false;
            answer += (a + 32);
        }
        else
        {
            key = false;
            answer += a;
        }
    }
    
    return answer;
}