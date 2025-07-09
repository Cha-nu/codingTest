#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
    map<int, vector<string>> arr;
    int N, num;
    string s;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num >> s;
        arr[num].push_back(s);
    }


    for (auto& [num, names] : arr) {
        for (auto& name : names) {
            cout << num << " " << name << "\n";
        }
    }

    return 0;

}