#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> equip;
    
    for(auto& c : clothes) ++equip[c[1]];
    
    for(auto it = equip.begin(); it != equip.end(); ++it) answer *= (it->second + 1); // 안입는 경우 + 1
        
    return answer - 1; // 아예 안입을 경우 제거 
}