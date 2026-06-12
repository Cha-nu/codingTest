#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string al = "abcdefghijklmnopqrstuvwxyz";
    
    for(char a : skip)
    {
        size_t pos = al.find(a);
        if(pos != string::npos) al.erase(pos, 1);
    }
    int n = static_cast<int>(al.length());
    for(char b : s) answer += al[(al.find(b) + index) % n];
    
    return answer;
}