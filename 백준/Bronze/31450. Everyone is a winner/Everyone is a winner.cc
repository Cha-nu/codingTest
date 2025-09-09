#include <iostream>

using namespace std;

int main(){
    long long m, k;
    cin >> m >> k;
    if(m % k) cout << "No";
    else cout << "Yes";
    return 0;
}