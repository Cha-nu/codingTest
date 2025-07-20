#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        priority_queue<int> pq_max_priority;

        for (int i = 0; i < N; ++i) {
            int priority;
            cin >> priority;
            q.push({priority, i}); 
            pq_max_priority.push(priority); 
        }

        int print_order = 0; 

        while (!q.empty()) {
            int current_priority = q.front().first;
            int current_index = q.front().second;
            q.pop();

            if (current_priority == pq_max_priority.top()) {
                pq_max_priority.pop(); 
                print_order++; 

                if (current_index == M) {
                    cout << print_order << '\n';
                    break;
                }
            } else {
            
                q.push({current_priority, current_index});
            }
        }
    }

    return 0;
}