#include <iostream>
#include <string>

int main() {
    int N;
    if (!(std::cin >> N)) return 0;
    
    std::string S;
    if (!(std::cin >> S)) return 0;

    // 인덱스 N-5부터 N-1까지 반복
    for (int i = N - 5; i < N; ++i) {
        // S[i]는 문자열의 i번째 문자를 나타냅니다.
        std::cout << S[i];
    }
    
    std::cout << "\n"; // 개행 문자 출력
    return 0;
}