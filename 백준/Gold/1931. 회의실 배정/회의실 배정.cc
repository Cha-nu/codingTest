#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> com(n);
    vector<int> idx = {0};
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        com[i] = {a, b};
    }
    sort(com.begin(), com.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    int j = 0;
    for(int i = 1; i < n; i++){
        if (com[i].first >= com[j].second){
            idx.push_back(i);
            j = i;
        }
    }
    cout << idx.size();
    return 0;
}