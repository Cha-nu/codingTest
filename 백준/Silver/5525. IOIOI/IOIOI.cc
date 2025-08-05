#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    int result = 0;
    int count = 0;

    for (int i = 1; i < m - 1;) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            count++;
            if (count == n) {
                result++;
                count--; // 겹치는 IOI 고려
            }
            i += 2; // IOI니까 O 다음 I로 점프
        } else {
            count = 0;
            i++; // 불일치니까 한 칸만 이동
        }
    }

    cout << result;
    return 0;
}
