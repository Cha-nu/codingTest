#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int bfs(int start, const vector<vector<int>>& relation) {
    int n = relation.size();
    vector<int> visited(n, 0);
    queue<pair<int, int>> q; // {node, depth}
    q.push({start, 0});
    visited[start] = 1;

    int sum_depth = 0;

    while (!q.empty()) {
        int curr = q.front().first;
        int depth = q.front().second;
        q.pop();

        sum_depth += depth;

        for (int i = 0; i < n; i++) {
            if (relation[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push({i, depth + 1});
            }
        }
    }

    return sum_depth;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> relation(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int j, k;
        cin >> j >> k;
        relation[j - 1][k - 1] = 1;
        relation[k - 1][j - 1] = 1;
    }

    int min_sum = INT_MAX;
    int result_node = -1;

    for (int i = 0; i < n; i++) {
        int total = bfs(i, relation);
        if (total < min_sum) {
            min_sum = total;
            result_node = i;
        }
    }

    cout << result_node + 1 << '\n'; // 1-based 출력
    return 0;
}
