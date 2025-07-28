#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int T, n, result, cat, key;
    string name, cate;
    cin >> T;

    while(T--){
        cin >> n;
        map<string, int> cloth;
        result = 1;
        while(n--){
            cin >> name >> cate;
            cloth[cate]++;
        }
        if(key >= 2) cat = 1;
        // 전체 합, 곱 계산
        for(auto a = cloth.begin(); a != cloth.end(); a++){
            result *= (a->second+1);
        }
        cout << --result << '\n';
    }
    return 0;
}