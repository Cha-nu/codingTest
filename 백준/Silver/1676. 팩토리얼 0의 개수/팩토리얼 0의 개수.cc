#include <iostream>
#include <string>
#include <vector>

using namespace std;

void multiply(vector<int>& result, int x){
    int carry = 0;
    for (int i = 0; i < result.size(); i++){
        int prod = result[i] * x + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while(carry){
        result.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n){
    int count = 0;
    vector<int> result = {1};

    for (int i = 2; i <= n; i++) multiply(result, i);

    for (int i = 0; i < result.size(); i++){
        if(result[i] != 0){
            cout << count;
            break;
        }
        count++;
    }
}


int main(){
    int n;
    cin >> n;
    factorial(n);
    return 0;
}