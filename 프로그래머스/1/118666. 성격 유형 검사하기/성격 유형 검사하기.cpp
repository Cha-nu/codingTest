#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "abcd";
    unordered_map<char, int> k = {{'R', 0},{'T', 0},{'C', 0},{'F', 0},{'J', 0},{'M', 0},{'A', 0},{'N', 0}};
    
    for(size_t i = 0; i < choices.size(); ++i)
    {
        if(choices[i] >= 4) k[survey[i][1]] += choices[i]-4;
        else k[survey[i][0]] += 4-choices[i];
    }
    
    k['R'] >= k['T'] ? answer[0] = 'R' : answer[0] = 'T';
    k['C'] >= k['F'] ? answer[1] = 'C' : answer[1] = 'F';
    k['J'] >= k['M'] ? answer[2] = 'J' : answer[2] = 'M';
    k['A'] >= k['N'] ? answer[3] = 'A' : answer[3] = 'N';
    return answer;
}