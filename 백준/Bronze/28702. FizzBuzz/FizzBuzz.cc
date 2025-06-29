#include <iostream>

using namespace std;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    int a2, b2, c2;
    int result = 0;
    a2 = atoi(a.c_str());
    b2 = atoi(b.c_str());
    c2 = atoi(c.c_str());

    // result는 이중 0이 아닌 값 찾기 a가 0이 아니면 +3, b가 0이 아니면 +2 c가 0이 아니면 +1
    if(a2 != 0){
        result = a2 + 3;
    }
    else if(b2 != 0){
        result = b2 + 2;
    }
    else{
        result = c2 + 1;
    }

    if (result % 3 == 0){
        if(result % 5 == 0){
            cout << "FizzBuzz";
        }
        else cout <<"Fizz";
    } 
    else if (result % 5 == 0)
    {
        cout << "Buzz";
    }
    else{
        cout << result;
    }
    return 0;
}