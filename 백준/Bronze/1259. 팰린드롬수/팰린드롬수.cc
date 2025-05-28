#include <iostream>
#include <cstring>

int main(){
    char c[100];
    std::string s;
    while(true){
        std::cin >> c;
        if(c[0] == '0') break;
        s = "yes";
        int len = 0;
        for(int i = 0; c[i] != '\0'; i++){
            len++;
        }
        for(int i = 0; i < len / 2; i++){
            if(c[i] != c[len - 1 - i]){
                s = "no";
                break;
            }
        }
        std::cout << s << '\n';
    }
    return 0;
}