#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && a == c && a == 60) cout << "Equilateral";
    else if(a+b+c == 180)
    {
        if(a == b || a == c || b == c) cout << "Isosceles";
        else cout << "Scalene";
    }
    else cout << "Error";

    return 0;
}