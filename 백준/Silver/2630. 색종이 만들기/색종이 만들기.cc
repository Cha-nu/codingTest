#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> sqr(n, vector<int> (n));
    vector<vector<int>> visited(n, vector<int> (n, 0));
    // 배열 입력
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) cin >> sqr[i][j];
    }

    int blue = 0, white = 0;
    for(int size = n; size >= 1; size /= 2){
        for(int i = 0; i < n; i += size){
            for(int j = 0; j < n; j += size){
                int color = sqr[i][j];
                bool isSame = true;

                if(visited[i][j]) continue;

                for(int x = i; x < i + size; x++){
                    for(int y = j; y < j + size; y++){
                        if(sqr[x][y] != color){
                            isSame = false;
                            break;
                        }
                    }
                    if(!isSame) break;
                }
                if(isSame){
                    for(int x = i; x < i + size; x++){
                        for(int y = j; y < j + size; y++){
                            visited[x][y] = 1;
                    }
                    if(!isSame) break;
                }
                    if(color == 1) blue++;
                    else white++;
                }
            }
        }
    }
    cout << white << '\n' << blue;
    return 0;
}