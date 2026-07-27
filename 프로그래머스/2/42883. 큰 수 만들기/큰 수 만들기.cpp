#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    // 첫번째 아이디어 작은 수를 제거하면 되지않을까?
    // 계속 탐색은 n^k 이기때문에 불가
    // 1회 정렬 후 최소 k개를 남기고 여기에 없으면 answer에 더하기
    /*
     vector<int> m (10, 0); // 0 부터 9
    
    for(char c: number) m[c - '0']++;
    
    
    for(int i = 1; i < 10; ++i)
    {
        while(m[i] > 0 && k > 0)
        {
            --k;
            --m[i];
        }
        if(k <= 0) break;
    }
    
    for(int a : m) cout << a << '\n';
    
    
    for(char c : number)
    {
        if(m[c - '0']-- > 0) answer.push_back(c);
    }
    최대를 보장해주지 않음
    */
   
    // 두번째 아이디어 스택방식 최상단의 숫자는 항상 커야된다.
    // answer가 비어있지않고 k 가 0 초과, 최상단 숫자와 들어올 숫자 비교
    for(char c : number)
    {
        while(!answer.empty() && k > 0 && answer.back() < c)
        {
            answer.pop_back();
            --k;
        }
        
        answer.push_back(c);
    }
    
    // k가 0 초과로 끝나면
    if( k > 0) answer.erase(answer.length() - k, k); // k만큼 슬라이싱
    
    return answer;
}