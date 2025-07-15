#include<iostream>
#include<vector>

using namespace std;

int main(){
    int K, a;
    cin >> K;
    vector<int> arr;
    int key = 0; // 0이면 제로불가 1이면 제로 가능

    for(int i = 0; i < K; i++){
        cin >> a;
        if(a != 0){
            arr.push_back(a);
            key = 1;
        } 
        else{
            arr.pop_back();
            key = 0;
        }
    }

    int result = 0;
    for(int i = 0; i < arr.size(); i++) result += arr[i];

    cout << result;
    return 0;
}