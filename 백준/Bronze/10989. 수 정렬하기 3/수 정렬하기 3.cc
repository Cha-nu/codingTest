#include <iostream>
using namespace std;

const int MAX = 10001;
int countArr[MAX] = {0};

int main() {
    int N, num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        countArr[num]++;
    }
    for (int i = 0; i < MAX; i++) {
        while (countArr[i]--) {
            cout << i << "\n";
        }
    }
    return 0;
}
