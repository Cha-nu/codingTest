#include <iostream>
#include <cmath>

int main(){
    const int r = 31;
    const int M = 1234567891;
    int L;
    char s[101];
    long long hash = 0;
    long long pow_r = 1;

    std::cin >> L >> s;
    
    for(int i = 0; i < L; i++){
        hash = (hash + (s[i] - 'a' + 1) * pow_r) % M;
        pow_r = (pow_r * r) % M;
    }

    std::cout << hash;
}