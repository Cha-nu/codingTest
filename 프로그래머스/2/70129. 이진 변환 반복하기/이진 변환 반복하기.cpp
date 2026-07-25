#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {0, 0}; // {이진 변환 횟수, 제거된 0의 갯수}
    
    while(s != "1")
    {
        int cnt = 0;
        // 문자열 x의 길이 세기
        for(char c : s)
        {
            if(c == '1') ++cnt;
            else ++answer[1];
        }
        s = "";
        while(cnt > 0) // 2진수 변환;
        {
            s += cnt % 2 + '0';
            cnt /= 2;
        }
        ++answer[0];
    }
    
    return answer;
}