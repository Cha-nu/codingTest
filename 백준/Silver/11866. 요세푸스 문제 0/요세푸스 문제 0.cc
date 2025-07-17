#include <iostream>
#include <list>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    list<int> people;
    for (int i = 1; i <= N; i++) people.push_back(i);

    auto it = people.begin();
    cout << "<";

    while (!people.empty()) {
        // K-1칸 이동 (K번째를 제거할거니까)
        for (int i = 0; i < K - 1; i++) {
            it++;
            if (it == people.end()) it = people.begin();
        }

        cout << *it;
        it = people.erase(it);  // 현재 위치 삭제하고 다음 원소 가리킴
        if (!people.empty()) cout << ", ";
        if (it == people.end()) it = people.begin();
    }

    cout << ">";
    return 0;
}
