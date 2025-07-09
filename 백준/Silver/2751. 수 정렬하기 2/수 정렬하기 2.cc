#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> countArr(n);

    for(int i = 0; i < n; i++){
        cin >> countArr[i];
    }

    sort(countArr.begin(), countArr.end());

    for (int i = 0; i < countArr.size(); i++) cout << countArr[i] << "\n";
    return 0;
}