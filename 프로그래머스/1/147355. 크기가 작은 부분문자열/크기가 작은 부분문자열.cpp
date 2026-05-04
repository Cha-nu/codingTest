#include <vector>
#include <iostream>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int n = static_cast<int>(t.size());
    int m = static_cast<int>(p.size());
    unsigned long long num = stoll(p);
    for(int i = 0; i < n-m+1; i++)
    {
        string check = "";
        for(int j = i; j < i+m; j++) check += t[j];
        
        unsigned long long checked = stoll(check);
        if(num >= checked) answer++;
    }
    
    return answer;
}