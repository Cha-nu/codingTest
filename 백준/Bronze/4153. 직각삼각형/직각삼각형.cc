#include <iostream>
#include <cmath>

int main() {
    int Heru, Ausar, Auset;
    while(1){
        std::cin >> Ausar >> Auset >> Heru;
        if (Heru == 0 && Ausar == 0 && Auset == 0) {
            break;
        }

        if(Auset > Heru) {
            if (Auset > Ausar) std::swap(Auset, Heru);
            else std::swap(Ausar, Heru);
        }
        else if (Ausar > Heru) {
            if (Auset > Ausar) std::swap(Auset, Heru);
            else std::swap(Ausar, Heru);
        }

        if(pow(Auset, 2) + pow(Ausar, 2) == pow(Heru, 2)) {
        std::cout << "right" << std::endl;
        }else {
        std::cout << "wrong" << std::endl;
        }
    }
    return 0;
}