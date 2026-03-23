#include <iostream>

using namespace std;

int main()
{
    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // x 결정 셋 중 다른 것 출력
    if(x1 == x2)
    {
        cout << x3;
    }
    else //x1 != x2
    {
        if(x1 == x3) cout << x2;
        else  cout << x1; //  x1 != x3 
    }
    // y 결정 셋 중 다른 것 출력
    if(y1 == y2)
    {
        cout << ' ' << y3;
    }
    else //y1 != y2
    {
        if(y1 == y3) cout << ' ' << y2;
        else cout << ' ' << y1;
    }
    return 0;
}