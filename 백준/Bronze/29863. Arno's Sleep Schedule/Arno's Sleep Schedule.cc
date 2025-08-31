#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    int c = 0;
    if(a >= 20){
        c = 24 - a;
        a = 0;
    }
    cout << b - a + c;
    return 0;
}