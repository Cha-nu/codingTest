#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    string poke ="";
    vector<string> Enc(N+1);
    unordered_map<string, int> nameToIndex;

    for(int i = 1; i <= N; i++){
        cin >> Enc[i];
        nameToIndex[Enc[i]] = i;
    }

    while(M--){ // O(MNlogN)
        cin >> poke;
        if(isdigit(poke[0])) cout << Enc[stoi(poke)] << '\n';
        else cout << nameToIndex[poke] << '\n';
    }

    return 0;
}