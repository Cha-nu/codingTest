#include <iostream>
#include <cmath> // std::llabs()를 사용하기 위해 포함합니다.
// 또는 <cstdlib>을 포함하여 std::llabs()를 사용할 수도 있습니다.

void solve() {
    // 1. 입력 범위가 20억까지이므로, N과 M 그리고 그 차이의 절댓값을 저장하기 위해
    // int 범위를 넘을 수 있는 'long long' 자료형을 사용합니다.
    long long N, M;

    // 2. 두 정수를 입력받습니다.
    if (!(std::cin >> N >> M)) {
        return; // 입력 오류 발생 시 종료
    }

    // 3. 두 수의 차이를 계산합니다.
    long long difference = N - M;

    // 4. 차이의 절댓값을 구하고 출력합니다.
    // std::llabs()는 long long 타입의 절댓값을 반환합니다.
    long long result = std::llabs(difference);

    std::cout << result << "\n";
}

int main() {
    // 백준 환경에서 권장되는 최적화(이 문제에서는 필수 아님)
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    solve();

    return 0;
}