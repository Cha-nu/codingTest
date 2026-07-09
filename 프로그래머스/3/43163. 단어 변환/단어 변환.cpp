#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int n = static_cast<int>(words.size());
    int m = static_cast<int>(begin.size());
    queue<pair<string, int>> q;
    vector<bool> visited(n, true);
    q.push({begin, 0});
    
    
    while(!q.empty())
    {
        pair<string, int> a = q.front();
        q.pop();
        string word = a.first;
        int cnt = a.second; 
        if(word == target) return cnt;
        for(int j = 0; j < n; ++j)
        {
            if(visited[j])
            {
                int count = 0;
                for(int i = 0; i < m; ++i)
                {
                    if(words[j][i] != word[i]) ++count;
                }
                if(count == 1)
                {
                    q.push({words[j], cnt+1});
                    visited[j] = false;
                }
            }
        }
    }
    return 0;
}