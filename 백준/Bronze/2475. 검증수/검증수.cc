#include <iostream>
#include <cmath>

int main(){
    int answer = 0;
    int number;
    for (int i = 0; i < 5; ++i) {
        std::cin >> number;
        answer += pow(number,2);
    }

    std::cout << answer % 10 << std::endl;
    return 0;
}