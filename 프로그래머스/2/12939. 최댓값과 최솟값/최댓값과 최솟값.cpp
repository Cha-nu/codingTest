#include <string>
#include <sstream>

using namespace std;

string solution(string s) {
    string temp;
    stringstream ss(s);
    
    int a = 9999;
    int b = -9999;
    int c;
    
    while(ss >> temp)
    {
        c = stoi(temp);
        if(a > c) a = c;
        if(b < c) b = c;
    }
    
    temp = "";
    temp += to_string(a);
    temp += " ";
    temp += to_string(b);
    
    return temp;
}

