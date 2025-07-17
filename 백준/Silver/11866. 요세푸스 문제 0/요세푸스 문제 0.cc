#include <iostream>
#include <vector>

using namespace std;

int check(int size, int i){
    if(i > size) return i % size;
    else return i;
}

int main(){
    int N, K;
    cin >> N >> K;

    int idx = 0;
    vector<int> arr(N+1);
    for (int i = 0; i < N+1; i++) arr[i] = i;

    cout << "<";
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < K; j++){
            idx+=1;
            idx = check(N, idx);
            if(arr[idx] == 0){
                while(arr[idx] == 0){
                    idx+=1;
                    idx = check(N, idx);
                }
            }
        }
        cout << arr[idx] << ", ";
        arr[idx] = 0;
    }
    for (int i = 0; i < N+1; i++){
        if(arr[i] != 0) cout << arr[i] << ">";
    }
    return 0;
}