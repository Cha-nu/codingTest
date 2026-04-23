#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int n = static_cast<int>(s.length());
    if(n == 4 || n == 6)
    {
       for(char c : s)
        {
            if(c < '0' || c > '9') return false;
        } 
    }
    else return false;
    return answer;
}