#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N, a;
    cin >> N;
    vector<int> vc(N);
    int offset = 4000;
    vector<int> arr(8001, 0);

    double sum = 0;

    for(int i = 0; i < N; i++){
        cin >> a;
        vc[i] = a;
        sum += a;
        arr[a + offset] += 1;
    }

    sort(vc.begin(), vc.end());

    int max_count = *max_element(arr.begin(), arr.end());

    vector<int> modes;

    for (int i = 0; i < 8001; ++i) {
        if (arr[i] == max_count)
            modes.push_back(i - offset); // 보정된 인덱스 → 원래 값
    }

        sort(modes.begin(), modes.end());


    // 산술평균 소수점 첫째자리에서 반올림
    cout << static_cast<int>(round(sum / N)) << '\n';
    // 중앙값
    cout << vc[N/2] << '\n';
    // 최빈값
    if (modes.size() == 1)
        cout << modes[0] << '\n';
    else
        cout << modes[1] << '\n';
    // 범위
    cout << vc[N-1] - vc[0] << '\n';

    return 0;
}