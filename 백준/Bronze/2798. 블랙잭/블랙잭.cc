#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    int answer = 0;
    int a[100];
    for(int i = 0; i < n; ++i){
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = a[i] + a[j] + a[k];
                if(sum <= m){
                    answer = std::max(answer, sum);
                }
            }
        }
    }
    std::cout << answer;
    return 0;
}