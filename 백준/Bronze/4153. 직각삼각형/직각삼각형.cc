#include <iostream>
#include <algorithm>

int main() {
    int a[3];
    while(1){
        std::cin >>a[0] >> a[1] >> a[2];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0) break;
        std::sort(a, a + 3);

        if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) {
        std::cout << "right\n";
        }else {
        std::cout << "wrong\n";
        }
    }
    return 0;
}