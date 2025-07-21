#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    stack<int> st;
    vector<char> result;
    int num = 1; // 다음 push할 수
    bool possible = true;

    for (int i = 0; i < n; i++) {
        int target = seq[i];

        // target보다 작거나 같을 때까지 push
        while (num <= target) {
            st.push(num++);
            result.push_back('+');
        }

        // top이 target이면 pop
        if (!st.empty() && st.top() == target) {
            st.pop();
            result.push_back('-');
        } else {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO\n";
    } else {
        for (char c : result)
            cout << c << '\n';
    }

    return 0;
}
