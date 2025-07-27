#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    string web, pass;
    unordered_map<string, string> save; 
    while(N--){
        cin >> web >> pass;
        save[web] = pass;
    }
    while(M--){
        cin >> web;
        cout << save[web] << '\n';
    }
    return 0;
}