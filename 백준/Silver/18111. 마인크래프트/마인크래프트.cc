#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long b;
    cin >> n >> m >> b;

    vector<vector<int>> ground(n,vector<int>(m));

    int maxh = 0, minh =1e9;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ground[i][j];
            if(maxh < ground[i][j]) maxh = ground[i][j];
            if(minh > ground[i][j]) minh = ground[i][j];
        }
    }

    long long remove, add;
    int resulttime = 1e9, resultheight;
    for(int h = minh; h <= maxh; h++){
        remove = 0, add = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    if(ground[i][j] > h) remove += ground[i][j] - h;
                    else if (ground[i][j] < h) add += h - ground[i][j];
                }
            }
            if(remove + b >= add){
            int ctime = remove * 2 + add;
            if(ctime < resulttime || (ctime == resulttime && h > resultheight)){
                resulttime = ctime;
                resultheight = h;
            }
        }
    }
    cout << resulttime << ' ' << resultheight << '\n';
    return 0;
}