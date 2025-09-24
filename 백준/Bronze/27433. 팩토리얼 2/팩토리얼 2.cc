#include<iostream>
using namespace std;
int main() {
    int input;
    cin >> input;
    if (input == 0) { cout << 1; return 0; }
    long long tmp = 1;
    for (int i = 1; i <= input; ++i) tmp *= i;
    cout<< tmp;
}