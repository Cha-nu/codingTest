#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> equip;
    
    for(auto& c: clothes) ++equip[c[1]];
    
    for (auto it = equip.begin(); it != equip.end(); ++it) answer *= (it->second + 1);
  
    return answer-1;
}