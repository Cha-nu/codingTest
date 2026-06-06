#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string b : babbling)
    {
        //string 검사 같은 발음 2개 X
        string s = "";
        bool aya = true;
        bool ye = true;
        bool woo = true;
        bool ma = true;
        for(char ch: b)
        {
            s += ch;
            if(aya && s == "aya")
            {
                s = "";
                aya = false;
                ye = true;
                woo = true;
                ma = true;
            }
            else if(ye && s == "ye")
            {
                s = "";
                aya = true;
                ye = false;
                woo = true;
                ma = true;
            }
            else if(woo && s == "woo")
            {
                s = "";
                aya = true;
                ye = true;
                woo = false;
                ma = true;
            }
            else if(ma && s == "ma")
            {
                s = "";
                aya = true;
                ye = true;
                woo = true;
                ma = false;
            }
        }
        if(s == "") answer++;
    }
    return answer;
}