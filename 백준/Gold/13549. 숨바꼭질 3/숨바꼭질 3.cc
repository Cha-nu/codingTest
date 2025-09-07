#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> visited(200001, -1);
    deque<pair<int,int>> q;
    
    q.push_front({n, 0}); // position, time
    visited[n] = 0;

    while(!q.empty()){
        int val = q.front().first; 
        int time = q.front().second;
        q.pop_front();
        if(val == k){
            cout << time;
            return 0;
        }
        int next_pos = val * 2;
        if(next_pos <= 200000 && (visited[next_pos] == -1 || visited[next_pos] > time)){
            q.push_front({next_pos, time}); // 순간이동
            visited[next_pos] = time;
        } 
        next_pos = val+1;
        if(next_pos <= 200000 && (visited[next_pos] == -1 || visited[next_pos] > time+1)){
            q.push_back({next_pos, time+1}); // 한 칸 앞으로 이동
            visited[next_pos] = time+1;
        }
        next_pos = val-1;
        if(next_pos >= 0 && (visited[next_pos] == -1 || visited[next_pos] > time+1)){
            q.push_back({next_pos, time+1}); // 한 칸 뒤로 이동
            visited[next_pos] = time+1;
        }
    }
    return 0;
}