#include <iostream>

int main() {
    char ch;
    std::cin >> ch;

    if (ch == 'M') {
        std::cout << "MatKor" << std::endl;
    } else if (ch == 'W') {
        std::cout << "WiCys" << std::endl;
    } else if (ch == 'C') {
        std::cout << "CyKor" << std::endl;
    } else if (ch == 'A') {
        std::cout << "AlKor" << std::endl;
    } else if (ch == '$') {
        std::cout << "$clear" << std::endl;
    }

    return 0;
}