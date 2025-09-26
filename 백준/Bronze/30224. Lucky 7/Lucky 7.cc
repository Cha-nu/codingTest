#include <iostream>

/**
 * @brief 주어진 정수 num에 숫자 7이 포함되어 있는지 확인합니다.
 */
bool containsSeven(int num) {
    while (num > 0) {
        if (num % 10 == 7) {
            return true;
        }
        num /= 10;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // 조건 변수 설정
    bool isDivisibleBy7 = (N % 7 == 0);
    bool contains7 = containsSeven(N);

    int result = (contains7 ? 2 : 0) + (isDivisibleBy7 ? 1 : 0);

    std::cout << result << "\n";

    return 0;
}