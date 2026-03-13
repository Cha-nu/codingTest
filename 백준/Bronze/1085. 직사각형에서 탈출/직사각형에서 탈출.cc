#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int result = min({abs((0-x)), abs(0-y), abs(w-x), abs(h-y)});
    cout << result;
    return 0;
}