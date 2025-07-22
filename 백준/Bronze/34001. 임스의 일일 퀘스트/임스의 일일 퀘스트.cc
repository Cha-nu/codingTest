#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int getCount(int L, int start, int dec1, int dec2) {
    if (L < start) return 0;
    if (L < dec1) return 500;
    if (L < dec2) return 300;
    return 100;
}

int main() {
    int L;
    cin >> L;

    vector<tuple<int, int, int>> arcain = {
        {200, 210, 220},
        {210, 220, 225},
        {220, 225, 230},
        {225, 230, 235},
        {230, 235, 245},
        {235, 245, 250}
    };

    vector<tuple<int, int, int>> grandis = {
        {260, 265, 270},
        {265, 270, 275},
        {270, 275, 280},
        {275, 280, 285},
        {280, 285, 290},
        {285, 290, 295},
        {290, 295, 300}
    };

    // Arcain 출력
    for (auto [s, d1, d2] : arcain) {
        cout << getCount(L, s, d1, d2) << " ";
    }
    cout << '\n';

    // Grandis 출력
    for (auto [s, d1, d2] : grandis) {
        cout << getCount(L, s, d1, d2) << " ";
    }
    cout << '\n';
    return 0;
}
