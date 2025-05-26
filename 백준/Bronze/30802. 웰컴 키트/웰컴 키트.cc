#include <iostream>

int main(){
    int N, a[6], b[2];
    int T = 0;
    std::cin >> N;
    std::cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    std::cin >> b[0] >> b[1];

    for(int i=0; i < 6; i++){
        T += a[i] / b[0];
        if (a[i] % b[0] != 0){
            T += 1;
        }
    }
    std::cout << T << "\n" << N / b[1] << " " << N % b[1];
    return 0;
}