#include <iostream>

int main(){
    int A, B, V;
    std::cin >> A >> B >> V;
    int days = (V - B - 1) / (A - B) + 1 ;
    std::cout << days << "\n";
    return 0;
}