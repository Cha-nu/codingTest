#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 테스트 케이스의 개수 N을 입력받습니다.
    int N;
    if (!(cin >> N)) return 0; // 입력 오류 방지 (선택적)

    // 총합을 저장할 변수를 초기화합니다.
    // 문제의 제약($N \le 100, X \le 100$) 상 최대 합은 $100 \times 100 = 10000$이므로 int형으로 충분합니다.
    long long sum = 0; 
    
    // 2. N번 반복합니다.
    for (int i = 0; i < N; ++i) {
        int X;
        // 3. 각 정수 X를 입력받고, 총합(sum)에 누적합니다.
        if (cin >> X) {
            sum += X;
        } else {
            // 입력 오류가 발생하면 반복을 중단합니다. (선택적)
            break;
        }
    }

    // 4. 최종 총합을 출력합니다.
    cout << sum << "\n";

    return 0;
}