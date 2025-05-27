#include <iostream>

int main(){
    int X;
    std::cin >> X;
    int n = 1;
    while (X > n) { // 몇번째 대각선인지 확인인
        X -= n;
        n++;
    }
    int a, b;
    if (n % 2 == 0) { // 대각선의 위치 확인인
        a = X;
        b = n - X + 1;
    } else {
        a = n - X + 1;
        b = X;
    }

    std::cout << a  << '/' << b;
    return 0;
}