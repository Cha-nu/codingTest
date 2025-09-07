#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> city;
vector<pair<int, int>> chicken;
vector<pair<int, int>> select_chicken;

int result = 1e9;

void com(int idx, int m){
    if(m == 0){ // 다 뽑으면 치킨 거리 계산
        int sum = 0; // 도시의 치킨 거리
        for(const pair<int,int> i : city){
            int c1 = i.first;
            int r1 = i.second;
            int dist = 1e9;
            for(const pair<int, int> j : select_chicken){
                int c2 = j.first;
                int r2 = j.second;
                int d = abs(c1-c2)+abs(r1-r2);
                dist = min(dist, d);
            }      
            sum += dist;
        }
        result = min(result, sum);
        return;
    }
    if (chicken.size() == idx) return; //종료조건
    select_chicken.push_back(chicken[idx]);
    com(idx+1, m-1); // 뽑았을때
    select_chicken.pop_back();
    com(idx+1, m); // 뽑지않았을때
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short n, m;

    cin >> n >> m;

    int chicken_cnt = 0;

    for(int i = 1; i <= n; i++){ // 입력
        for(int j = 1; j <= n; j++){
            int val;
            cin >> val;
            if(val == 1){
                city.push_back({i, j});
            }
            else if(val == 2){
                chicken.push_back({i, j});
                chicken_cnt++;
            }
        }
    }

    com(0, m);
    cout << result;
    return 0;
}