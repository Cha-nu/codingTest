#include <iostream>

#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, c;
    cin >> a >> b >> c;

    long long result = 1;
    a %= c;

    while(b > 0){ // 모듈러 
        if(b % 2 == 1){ // 지수가 홀수일때
            result = (result * a) % c;
        }
        a = (a * a) % c;

        b /= 2;
    }

    cout << result;
    
    return 0;
}