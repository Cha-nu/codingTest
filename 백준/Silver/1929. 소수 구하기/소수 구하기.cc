#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 에라토스테네스의 체 사용
void is_prime(int m,int n){
    int count = 0;
    bool *arr = new bool[n+1];
    fill(arr, arr+n+1, true);

    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i <= static_cast<int>(sqrt(n)); i++){
        if(arr[i] == true){
            int j = 2;
            while(i * j <= n){
                arr[i * j] = false;
                j+=1;
            }
        }
    }
    for(int i = m; i <= n; i++) if(arr[i] == true) cout << i << '\n';

    delete[] arr;
    return;
}


int main(){
    int M, N;
    cin >> M >> N;
    is_prime(M, N);
    return 0;
}