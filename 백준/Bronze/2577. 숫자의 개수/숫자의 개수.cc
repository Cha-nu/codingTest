#include <iostream>
#include <string>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    int D = A * B * C;
    int count[10] = {0};
    std::string result = std::to_string(D);

    for(int i = 0; i < result.length(); i++) {
        count[result[i] - '0']++;
    }
    for(int i = 0; i < 10; i++) {
        std::cout << count[i] << std::endl;
    }
}