#include <iostream>
using namespace std;

int main(){
    char str[14];
    cin >> str;
    int sum = 0;
    int mul = 1;
    int starmul = 1;

    for(int i =0; i < 13; i++){
        if(str[i] != '*'){
            sum += mul*(int(str[i])-48);
        }
        else starmul = mul;
        if(mul == 1) mul = 3;
        else mul = 1;
    }
    for(int i = 0; i < 10; i++){
        if((sum + starmul*i) % 10 == 0){
            cout << i;
            break;
        }
    }
}