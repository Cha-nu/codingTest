#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> prev_max(3);
    vector<int> prev_min(3);

    vector<int> cur_max(3);
    vector<int> cur_min(3);

    cin >> prev_max[0] >> prev_max[1] >> prev_max[2];

    prev_min = prev_max;

    for(int i = 1; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        cur_max[0] = max(prev_max[0], prev_max[1]) + a;
        cur_max[1] = max(prev_max[0], max(prev_max[1], prev_max[2])) + b;
        cur_max[2] = max(prev_max[1], prev_max[2]) + c;
        cur_min[0] = min(prev_min[0], prev_min[1]) + a;
        cur_min[1] = min(prev_min[0], min(prev_min[1], prev_min[2])) + b;
        cur_min[2] = min(prev_min[1], prev_min[2]) + c;
        prev_min = cur_min;
        prev_max = cur_max;
    }
    
    int max_result = max(prev_max[0], max(prev_max[1], prev_max[2]));
    int min_result = min(prev_min[0], min(prev_min[1], prev_min[2]));
    
    cout << max_result << ' ' << min_result;

    return 0;
}