#include <iostream>
#include <vector>

using namespace std;

// nCm
void com(short i, short n, short m, vector<short>& arr){
    if (m == 0){ // 다 뽑을 시 출력
        for(short j = 0; j < arr.size(); j++){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    else if(i > n) return; // i가 n을 넘어가면 끝
    else{ // 자기 자신 뽑기 가능
        arr.push_back(i);
        com(i, n, m-1, arr);
        arr.pop_back();
        // 자기 자신 다음 뽑기
        // arr.push_back(i);
        // com(i+1, n, m-1, arr);
        // arr.pop_back();
        // i를 뽑지 않은 경우
        com(i+1, n,  m, arr);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short n, m;
    cin >> n >> m;

    vector<short> arr;

    com(1, n, m, arr);
        
    return 0;
}