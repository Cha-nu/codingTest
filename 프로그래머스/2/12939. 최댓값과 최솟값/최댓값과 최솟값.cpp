#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    
    int ma = -9999;
    int mi = 9999;
    string temp;
    
    while(ss >> temp)
    {
        int t = stoi(temp);
        if(t > ma) ma = t;
        if(t < mi) mi = t;
    }
    
    answer += to_string(mi);
    answer += ' ';
    answer += to_string(ma);
    
    return answer;
}