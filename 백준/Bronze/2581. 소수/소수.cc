#include <iostream>
#include <vector>
#include <cmath> // sqrt 함수를 사용하기 위해 필요

using namespace std;

// 소수 판별 함수
bool isPrime(int num) {
    if (num <= 1) { // 1 이하는 소수가 아님
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false; // 나누어떨어지면 소수가 아님
        }
    }
    return true; // 반복문을 모두 통과하면 소수
}

int main() {
    int m, n;
    cin >> m >> n;

    int sum = 0;
    int min_prime = -1; // 최솟값을 저장할 변수, 초기값은 소수가 없는 경우를 대비해 -1로 설정

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            sum += i; // 소수이면 합에 더함
            if (min_prime == -1) {
                min_prime = i; // 첫 소수가 최솟값
            }
        }
    }

    if (sum == 0) {
        cout << -1 << endl;
    } else {
        cout << sum << endl;
        cout << min_prime << endl;
    }

    return 0;
}