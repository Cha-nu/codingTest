#include <iostream>
#include <vector>

using namespace std;

// short answer = 0;

// nCm
// void com(short i, short n, short clen, short l_v, vector<short> &lst){
//     if (i >= n){ // 다 뽑을 시 출력
//         answer = max(clen, answer);
//     }
//     else{
//         if(lst[i] > l_v){ // 전에 뽑은 것 보다 크면 뽑기
//             com(i+1, n, clen+1, lst[i], lst);
//         }
//         com(i+1, n, clen, l_v, lst); // 다음으로 넘어감
//     }
// }

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     short n;
//     cin >> n;

//     vector<short> lst(n);
//     for(int i = 0; i < n; i++) cin >> lst[i];

//     com(0, n, 0, -1, lst);

//     cout << answer;
        
//     return 0;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    short n;
    cin >> n;

    vector<short> lst(n);
    for(int i = 0; i < n; i++) cin >> lst[i];

    vector<int> memo(n, 1);
    for(short i = 1; i < n; i++) for(short j = 0; j < i; j++) if(lst[i] > lst[j]) memo[i] = max(memo[i], memo[j]+1);

    int result = 0;
    for(int val : memo) result = max(result, val);
    
    cout << result;

    return 0;
}