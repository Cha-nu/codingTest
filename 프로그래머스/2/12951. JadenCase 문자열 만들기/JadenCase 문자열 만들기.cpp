#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    bool key = true;
    
    for(char& a : s)
    {
       if(a == ' ') key = true;
       else
       {
           if(key)
           {
               a = toupper(static_cast<unsigned char>(a));
               key = false;
           }
           else a = tolower(static_cast<unsigned char>(a));
       }
    }
    
    return s;
}