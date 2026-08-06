#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    // 최소한의 버튼으로 storey층에서 0층으로 이동
    // 배수 관계 그리디? DP?
    // 결과가 0보다 작으면 움직이지 않음
    
    // 최대한 10의 배수를 만든다.
    
    if(storey == 0) return answer;
    
                  // 0 1 2 3 4 5 6 7 8 9
    vector<int> a = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1};
    
    while(storey)
    {
        int l = storey % 10;
        answer += a[l];
        storey /= 10; 
        if(l > 5) ++storey; //  자릿 수 올리기 
        else if(l == 5) if(storey % 10 >= 5) ++storey; // 현재 5이상이면 자릿 수 올리는게 최소
    }
    return answer;
}