#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> a = {{'R', 0}, {'T', 0}, {'C', 0}, {'F', 0}, {'J', 0}, {'M', 0}, {'A', 0}, {'N', 0}};
    
    for(int i = 0; i < static_cast<int>(choices.size()); i++)
    {
        if(choices[i] > 4) a[survey[i][1]] += (choices[i] - 4);
        else if (choices[i] < 4) a[survey[i][0]] += (4 - choices[i]);
    }
    
    a['R'] >= a['T'] ? answer+='R' : answer+='T';
    a['C'] >= a['F'] ? answer+='C' : answer+='F';
    a['J'] >= a['M'] ? answer+='J' : answer+='M';
    a['A'] >= a['N'] ? answer+='A' : answer+='N';
    
    return answer;
}