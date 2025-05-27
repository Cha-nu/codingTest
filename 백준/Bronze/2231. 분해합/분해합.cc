#include <iostream>

int main(){
    int answer = 0;
    int n;
    std::cin >> n;
    // 256 = 245 + 2 + 4 + 5, 216 = 198 + 1 + 9 + 8
    for(int i = n; i >= 0; --i){
        int sum = i;
        int calc = i;
        while(calc > 0){
            sum += calc % 10;
            calc /= 10;
        }
        if(sum == n){
            answer = i;
        }
    }
    std::cout << answer;
    return 0;
}