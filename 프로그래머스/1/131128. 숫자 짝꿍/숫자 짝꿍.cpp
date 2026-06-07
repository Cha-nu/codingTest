#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> numX (10, 0);
    vector<int> numY (10, 0);
    
    for(char x : X) numX[x - '0']++;
    for(char y : Y) numY[y - '0']++;
    
    // 갯수 맞추기
    for(int i = 0; i < 10; i++) numX[i] = (numX[i] > numY[i] ? numY[i] : numX[i]);
    
    for(int i = 9; i >= 0; i--) for(int j = 0; j < numX[i]; j++) answer += i + '0';
    
    if(answer[0] == '0') answer = '0';
    if(answer == "") answer += "-1";
    
    return answer;
}