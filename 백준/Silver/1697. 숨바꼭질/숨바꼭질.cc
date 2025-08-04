#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if(n == k){
        cout << 0;
        return 0;
    }

    vector<bool> visited(MAX * 2 + 1, false);
    queue<int> q;
    int time = 0, sz, x;
    q.push(n);
    
    while(!q.empty()){
        sz = q.size();
        while(sz--){
            x = q.front(); q.pop();
            if(x == k){
                cout << time;
                return 0;
            }
            if (x - 1 >= 0 && !visited[x - 1]) {
                q.push(x - 1);
                visited[x - 1] = true;
            }
            if (x + 1 <= MAX * 2 && !visited[x + 1]) {
                q.push(x + 1);
                visited[x + 1] = true;
            }
            if (x * 2 <= MAX * 2 && !visited[x * 2]) {
                q.push(x * 2);
                visited[x * 2] = true;
            }
        }
        time++;
    }
    cout << time;
    return 0;
}

