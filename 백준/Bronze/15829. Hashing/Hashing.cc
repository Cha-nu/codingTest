#include <iostream>
#include <cmath>

int main(){
    int r = 31;
    int M = 1234567891;
    int L;
    char s[101];
    long long hash = 0;

    std::cin >> L >> s;
    
    for(int i = 0; i < L; i++){
        hash += ((s[i] - 'a' + 1) * (long long)pow(r, i));
    }

    std::cout << hash % M;
}