#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = static_cast<int>(s.length());
    int i = 0;
    
    while(i < n)
    {
        char first = s[i];
        int firstcount = 0;
        int othercount = 0;
        
        for(; i < n; i++)
        {
            if(s[i] == first) firstcount++;
            else othercount++;
            
            if(firstcount == othercount)
            {
                answer++;
                i++;
                break;
            }
        }
        
        if (firstcount != othercount) {
            answer++;
            break; 
        }
    }
    
    return answer;
}