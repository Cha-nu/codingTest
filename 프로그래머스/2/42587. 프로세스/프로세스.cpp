#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    

    for (int i = 0; i < priorities.size(); ++i) q.push({priorities[i], i});

    sort(priorities.rbegin(), priorities.rend());
    
    int count = 0;
    int idx = 0;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        if (current.first == priorities[idx]) {
            count++;
            idx++;
            if (current.second == location) {
                return count;
            }
        } else {
            q.push(current);
        }
    }

    return count;
}