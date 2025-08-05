#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m >> s;

    int len = 2 * n + 1;
    int i = 0, result = 0;
    bool match = true;

    while(i <= m - len){
        if(s[i] == 'I'){
            match = true;
            for(int j = 0; j < len; j++){
                if((j % 2 ==0 && s[i+j] != 'I') || (j % 2 ==1 && s[i+j] != 'O')){match = false; break;}
            }
            if(match){ result++; i+=2;}
            else i++;
        }
        else i++;
    }

    cout << result;
    return 0;
}