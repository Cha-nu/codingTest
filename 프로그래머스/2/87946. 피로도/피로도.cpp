#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int max_dungeons = 0;
    int n = dungeons.size();
    vector<bool> visited(n, false);

    auto dfs = [&](auto& self, int current_k, int count) -> void {
        max_dungeons = max(max_dungeons, count);

        for (int i = 0; i < n; ++i) {
            if (!visited[i] && current_k >= dungeons[i][0]) {
                visited[i] = true; 
                self(self, current_k - dungeons[i][1], count + 1); 
                visited[i] = false;
            }
        }
    };

    dfs(dfs, k, 0);

    return max_dungeons;
}