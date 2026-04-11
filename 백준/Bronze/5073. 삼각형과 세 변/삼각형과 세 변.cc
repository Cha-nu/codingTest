#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;

        int max_val = max({a, b, c});
        int total_sum = a + b + c;

        if (max_val >= total_sum - max_val) {
            cout << "Invalid" << "\n";
        }
        else if(a == b && b == c) {
            cout << "Equilateral" << "\n";
        }
        else if(a == b || b == c || a == c) {
            cout << "Isosceles" << "\n";
        }
        else {
            cout << "Scalene" << "\n";
        }
    }
    return 0;
}