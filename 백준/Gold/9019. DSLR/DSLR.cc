#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short t;
    cin >> t;
    while(t--){
        short x, y;
        cin >> x >> y;
        queue<pair<int, string>> q;
        vector<bool> visited(10000, false);
        q.push({x, ""});
        visited[x] = true;
        while(!q.empty()){ // bfs
            auto [n, m] = q.front(); q.pop();
            if(n == y){
                cout << m << '\n';
                break;
            }
            // D
            int a = (n*2) % 10000;
            if (!visited[a]) {
                q.push({a, m + "D"});
                visited[a] = true;
            }
            // S
            a = (n == 0) ? 9999 : n-1;
            if (!visited[a]) {
                q.push({a, m + "S"});
                visited[a] = true;
            }
            // L shift
            a = (n % 1000) * 10 + (n / 1000);
            if (!visited[a]) {
                q.push({a, m + "L"});
                visited[a] = true;
            }
            // R shift
            a = (n % 10) * 1000 + (n / 10);
            if (!visited[a]) {
                q.push({a, m + "R"});
                visited[a] = true;
            }
        }
    }
    return 0;
}