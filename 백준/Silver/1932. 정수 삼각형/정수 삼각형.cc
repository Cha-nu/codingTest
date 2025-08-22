#include <iostream>
#include <vector>
#include <algorithm> // max 함수를 위해 필요

using namespace std;

int main() {
    int n;
    cin >> n;

    // 2차원 벡터를 미리 n x n 크기로 초기화 (메모리 낭비는 좀 있지만, 구현이 간단)
    vector<vector<int>> tree(n, vector<int>(n));

    // 삼각형 숫자 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tree[i][j];
        }
    }

    // 동적 프로그래밍: 맨 아래에서부터 위로 올라가며 경로 합 계산
    // i는 맨 아래 행(n-2)부터 0까지 감소
    for (int i = n - 2; i >= 0; i--) {
        // j는 현재 행의 첫 번째 열(0)부터 i까지 증가
        for (int j = 0; j <= i; j++) {
            // 현재 위치의 값에, 아래 두 경로 중 더 큰 값을 더함
            tree[i][j] += max(tree[i + 1][j], tree[i + 1][j + 1]);
        }
    }

    // 최종 결과는 맨 위(0,0)에 저장된 값
    cout << tree[0][0] << endl;

    return 0;
}