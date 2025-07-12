#include <iostream>

using namespace std;

int main(){
    int N, M, result = 64;
    cin >> N >> M;

    char** array = new char*[N];
    for(int i = 0; i < N; i++){
        array[i] = new char[M];
        fill_n(array[i], M, 0);
        for (int j = 0; j < M; j++){
            cin >> array[i][j];
        }
    }

    for(int i = 0; i < N - 7; i++){ // N 판
        for (int j = 0; j < M - 7; j++){ // M판
            int countB = 0, countW = 0; // 시작이 B, W
            for(int k = 0; k < 8; k++){ // 검증
                for(int l = 0; l < 8; l++){
                    if (l % 2 == k % 2) (array[l+i][k+j] == 'B') ? countW++ : countB++;
                    else (array[l+i][k+j] == 'B') ? countB++ : countW++;
                }
            }
            result = min(result, min(countB, countW));
        }
    }

    cout << result;
    return 0;
}