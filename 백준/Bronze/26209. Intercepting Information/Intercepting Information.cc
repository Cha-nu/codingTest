#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    for(int i = 0; i < 8; i++){
        cin >> a;
        if(a == 9){
            cout << "F";
            return 0;
        }
    }
    cout << "S";
    return 0;
}