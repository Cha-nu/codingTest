#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, a;
    string cmd;
    int S = 0;

    cin >> M;
    while(M--){
        cin >> cmd;
        if(cmd == "add"){
            cin >> a;
            S |= (1 << a);
        }
        else if(cmd == "remove"){
            cin >> a;
            S &= ~(1 << a);
        }
        else if(cmd == "check"){
            cin >> a;
            cout << ((S & (1 << a)) ? 1 : 0) << '\n';
        }
        else if(cmd == "toggle"){
            cin >> a;
            S ^= (1 << a);
        }
        else if(cmd == "all"){
            S = (1 << 21) - 1;
        }
        else if(cmd == "empty"){
            S = 0;
        }
    }

    return 0;
}
