#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, bomb;
    cin >> s;
    cin >> bomb;

    vector<char> result;

    for(char c : s)
    {
        // 폭탄의 끝 글자와 같으면
        if(c == bomb.back())
        {
            result.push_back(c);
            vector<char> temp;
            // 폭탄 글자수 만큼 스택에서 pop()
            for(int i = static_cast<int>(bomb.length()) - 1; i >= 0; --i)
            {
                if(!result.empty() && bomb[i] == result.back()) // 스택 예외처리
                {
                        temp.push_back(result.back());
                        result.pop_back();
                }
                else
                {
                    while(!temp.empty()) // 비어있으면 폭탄과 안맞으니 다시 넣기
                    {
                        result.push_back(temp.back());
                        temp.pop_back();
                    }
                }
            }
        }
        // 다르면 스택에 집어넣기
        else
        {
            result.push_back(c);
        }
    }

    if(result.empty()) cout << "FRULA";
    else
    {
        for(char c : result) cout << c;
    }
    
    return 0;
}