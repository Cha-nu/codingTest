#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, count;
    cin >> N;

    vector<int> w(N), h(N);

    for(int i = 0; i < N; i++){
        cin >> w[i] >> h[i];
    }

    for(int i = 0; i < N; i++){
        count = 1;
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(w[i] < w[j] && h[i] < h[j]) count++;
        }
        cout << count << " ";
    }

}