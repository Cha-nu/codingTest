#include <iostream>
#include <string>

using namespace std;

int main(){
    short n;
    cin >> n;
    while(n--){
        string a;
        cin >> a;
        for (char b : a){
            if('A' <= b && b <= 'Z') b+=32;
            cout << b;
        }
        cout << '\n';
    }
    return 0;
}