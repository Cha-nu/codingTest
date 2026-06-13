#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> val (4, 0); // RT, FC, MJ, AN
    
    for(int i = 0; i < static_cast<int>(choices.size()); i++)
    {
        string s = survey[i];
        int c = choices[i];
        int idx = 0;
        int a = 1;
        if(s == "RT") 
        {
            idx = 0;
            a = 1;
        }
        else if(s == "TR")
        {
            idx = 0;
            a = -1;
        }
        else if(s == "FC")
        {
            idx = 1;
            a = 1;
        }
        else if(s == "CF")
        {
            idx = 1;
            a = -1;
        }
        else if(s == "MJ")
        {
            idx = 2;
            a = 1;
        }
        else if(s == "JM")
        {
            idx = 2;
            a = -1;
        }
        else if(s == "AN")
        {
            idx = 3;
            a = 1;
        }
        else if(s == "NA")
        {
            idx = 3;
            a = -1;
        }
        
        if(c == 1) val[idx] -= a*3;
        else if(c == 2) val[idx] -= a*2;
        else if(c == 3) val[idx] -= a*1;
        else if(c == 5) val[idx] += a*1;
        else if(c == 6) val[idx] += a*2;
        else if(c == 7) val[idx] += a*3;
    }
    
    val[0] <= 0 ? answer+= "R" : answer += "T";
    val[1] >= 0 ? answer+= "C" : answer += "F";
    val[2] >= 0 ? answer+= "J" : answer += "M";
    val[3] <= 0 ? answer+= "A" : answer += "N";
    
    return answer;
}