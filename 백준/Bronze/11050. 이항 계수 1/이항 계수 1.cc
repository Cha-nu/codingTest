#include <iostream>

int fac(int n){
    int result = 1;
    for(int i = 1; i <= n; i++){
        result *= i;
    }
    return result;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cout << (fac(N) / (fac(N-K) * fac(K))); 
    return 0;
}

