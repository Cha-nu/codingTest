#include <string>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i < static_cast<int>(s.size()); i++)
    {
        if(s[i] < 'A' || s[i] > 'z') continue;
        for(int j = 0; j < n; j++)
        {
            if(s[i] == 'Z' || s[i] == 'z')
            {
                s[i]-=26;
            }
            s[i]++;
        }
    }
    return s;
}