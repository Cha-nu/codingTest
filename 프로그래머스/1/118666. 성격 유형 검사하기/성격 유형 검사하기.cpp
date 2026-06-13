#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> score_map;
    
    for(size_t i = 0; i < survey.size(); i++)
    {
        int choice = choices[i];
        
        if(choice == 4) continue;
        
        if(choice < 4) score_map[survey[i][0]] += (4 - choice);
        else score_map[survey[i][1]] += (choice - 4);  
    }

    answer += (score_map['R'] >= score_map['T']) ? "R" : "T";
    answer += (score_map['C'] >= score_map['F']) ? "C" : "F";
    answer += (score_map['J'] >= score_map['M']) ? "J" : "M";
    answer += (score_map['A'] >= score_map['N']) ? "A" : "N";
    
    return answer;
}