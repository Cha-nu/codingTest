#include <string>
#include <unordered_map>

using namespace std;

int solution(string s) {
   unordered_map<string, string> nums = {{"zero","0"}, {"one","1"}, {"two","2"}, {"three","3"}, {"four","4"}, {"five","5"}, {"six","6"}, {"seven", "7"}, {"eight","8"}, {"nine","9"}};
    
    string key = "";
    string answer = "";
    for(char a : s)
    {
        if(isdigit(a)) // 숫자인 경우 answer에 넣기
        {
            answer += a;
        }
        else // 문자
        {
            key += a;
            if(nums.find(key) != nums.end())
            {
                answer += nums[key];
                key = "";
            }
        }
        
    }
    
    
    return stoi(answer);
}