#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0; 

    if (n <= 1) {
        int a, b;
        for(int i = 0; i < n; i++) cin >> a >> b;
        cout << 0 << "\n";
        return 0;
    }

    vector<int> x_coords;
    vector<int> y_coords;
    x_coords.reserve(n);
    y_coords.reserve(n);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x_coords.push_back(a);
        y_coords.push_back(b);
    }

    // 각 좌표축의 최솟값과 최댓값 찾기
    auto min_x = *min_element(x_coords.begin(), x_coords.end());
    auto max_x = *max_element(x_coords.begin(), x_coords.end());
    auto min_y = *min_element(y_coords.begin(), y_coords.end());
    auto max_y = *max_element(y_coords.begin(), y_coords.end());

    // 결과 계산 (오버플로우 방지를 위해 long long 캐스팅)
    long long width = (long long)max_x - min_x;
    long long height = (long long)max_y - min_y;

    cout << width * height << "\n";

    return 0;
}