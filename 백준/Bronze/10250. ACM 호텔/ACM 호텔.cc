#include <iostream>

int main() {
    int T, H, W, N;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> H >> W >> N;
        std::cout << ((N - 1) % H + 1) * 100 + ((N - 1) / H + 1)<< std::endl; // Output in the required format
    }
    return 0;
}