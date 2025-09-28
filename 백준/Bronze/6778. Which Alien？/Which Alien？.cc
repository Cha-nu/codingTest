#include <iostream>

using namespace std;

int main() {
    // 입출력 속도 향상 (선택 사항이지만 경쟁 프로그래밍에서 유용합니다.)
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(NULL);

    int antenna; // 안테나 개수
    int eye;     // 눈 개수

    // 1. 안테나 개수와 눈 개수 입력 받기
    if (!(cin >> antenna >> eye)) {
        // 입력 실패 처리 (문제 조건상 필수는 아닐 수 있으나 견고한 코드에선 고려)
        return 0;
    }

    // 2. 각 외계인 종족의 조건을 독립적으로 검사 및 출력

    // (1) TroyMartian 검사
    // 안테나 >= 3 이고 눈 <= 4
    if (antenna >= 3 && eye <= 4) {
        cout << "TroyMartian\n";
    }

    // (2) VladSaturnian 검사
    // 안테나 <= 6 이고 눈 >= 2
    if (antenna <= 6 && eye >= 2) {
        cout << "VladSaturnian\n";
    }

    // (3) GraemeMercurian 검사
    // 안테나 <= 2 이고 눈 <= 3
    if (antenna <= 2 && eye <= 3) {
        cout << "GraemeMercurian\n";
    }

    return 0;
}