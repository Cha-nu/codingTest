#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main(){
     ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    unordered_set<string> arr;
    vector<string> result;

     string name = "";

    for(int i = 0; i < N; i++){
        cin >> name;
        arr.insert(name);
    }
   
    while(M--){
        cin >> name;
        if(arr.count(name)) result.push_back(name);
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for(string s : result) cout << s << '\n';
    return 0;
}