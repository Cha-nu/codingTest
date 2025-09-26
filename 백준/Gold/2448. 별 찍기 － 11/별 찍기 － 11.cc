#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> star(3072, vector<bool>(6144, false));

void solv(short r,short c,short n){
    if(n==3){
        star[r][c]=true;
        star[r+1][c-1] = true;
        star[r+1][c+1] = true;
        star[r+2][c-2] = true;
        star[r+2][c-1] = true;
        star[r+2][c] = true;
        star[r+2][c+1] = true;
        star[r+2][c+2] = true; 
    }
    else{
        solv(r, c, n/2);
        solv(r+n/2,c-n/2, n/2);
        solv(r+n/2,c+n/2, n/2);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short n;
    cin >> n;

    solv(0,n-1,n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2 * n; j++){
            if(star[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}