#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    short w, h;
    cin >> w >> h;
    double s = (double) w * h / 2;
    printf("%.1f\n", s);
    return 0;
}