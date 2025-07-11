#include <iostream>
#include <set>

using namespace std;

int main(){
    int N, x, y;
    set<pair<int, int>> cod;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x >> y;
        cod.insert({x, y});
    }

    for(auto& c : cod){
        cout << c.first << " " << c.second << "\n";
    }
    return 0;
}