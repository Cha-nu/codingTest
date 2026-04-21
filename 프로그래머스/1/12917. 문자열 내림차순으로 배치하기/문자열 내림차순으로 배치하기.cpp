#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    string upper_char = "";
    for(char a : s)
    {
        if(islower(a))
        {
            answer += a;
        }
        else
        {
            upper_char += a;
        }
    }
    sort(answer.begin(), answer.end(), greater<char>());
    sort(upper_char.begin(), upper_char.end(), greater<char>());
    return answer + upper_char;
}