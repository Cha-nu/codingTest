#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// nPm
void per(short m, vector<short>& arr, vector<short>& lst, vector<bool>& visited) {
    if (m == arr.size()) { // m개를 모두 뽑았을 때 출력
        for (short val : arr) {
            cout << val << ' ';
        }
        cout << '\n';
        return;
    }
    for (short i = 0; i < lst.size(); i++) {
        // 이미 방문한 원소이거나, 이전 원소와 같은데 아직 방문하지 않은 경우 건너뛰기
        if (visited[i] || (i > 0 && lst[i] == lst[i - 1] && !visited[i - 1])) {
            continue;
        }

        arr.push_back(lst[i]);
        visited[i] = true;
        
        per(m, arr, lst, visited);
        
        visited[i] = false;
        arr.pop_back();
    }
}

int main() {
    short n, m;
    cin >> n >> m;
    vector<short> lst;
    for (int i = 0; i < n; i++) {
        short a;
        cin >> a;
        lst.push_back(a);
    }

    sort(lst.begin(), lst.end());

    vector<short> arr;
    vector<bool> visited(n, false);
    per(m, arr, lst, visited);

    return 0;
}