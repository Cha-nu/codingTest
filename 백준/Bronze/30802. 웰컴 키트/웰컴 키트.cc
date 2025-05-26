#include <iostream>

int main() {
    int N, a[6], b[2], T = 0;
    std::cin >> N;
    for(int &x : a) std::cin >> x;
    std::cin >> b[0] >> b[1];

    for(int i = 0; i < 6; ++i)
        T += (a[i] + b[0] - 1) / b[0];

    std::cout << T << '\n' << N / b[1] << ' ' << N % b[1];
    return 0;
}