#include <string>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int n = static_cast<int>(phone_number.length());
    for(int i = 0; i < n-4; i++) answer += "*";
    for(int i = n-4; i < n; i++) answer += phone_number[i];
    
    return answer;
}