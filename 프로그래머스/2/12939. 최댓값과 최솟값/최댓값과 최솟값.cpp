#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int a = -9999; // 최대 
    int b = 9999; // 최소
    
    string ss = "";
    
    for(char c : s)
    {
        if(c == ' ')
        {
            int d = stoi(ss);
            ss = "";
            if(a < d) a = d;
            if(b > d) b = d;
        }
        else
        {
            ss += c;
        }
    }
    
    if(ss != "")
    {
        int d = stoi(ss);
        ss = "";
        if(a < d) a = d;
        if(b > d) b = d;
    }
    
    answer += to_string(b);
    answer += ' ';
    answer += to_string(a);
    
    return answer;
}