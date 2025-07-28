#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        map<string, int> cloth;
        string name, cate;

        while(n--){
            cin >> name >> cate;
            cloth[cate]++;
        }

        int result = 1;
        for(auto& c : cloth){
            result *= (c.second + 1);  // (입는 경우 + 안 입는 경우)
        }

        result -= 1;  // 아무것도 안 입는 경우 제외
        cout << result << '\n';
    }
    return 0;
}
