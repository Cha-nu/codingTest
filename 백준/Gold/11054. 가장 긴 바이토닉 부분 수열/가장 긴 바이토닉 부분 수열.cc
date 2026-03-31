#include <iostream>
#include <vector>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, result = 1;
    cin >> n;

    vector<int> arr(n);
    vector<int> front_memo(n, 1);
    vector<int> back_memo(n, 1);
    
    for(int i = 0; i < n; i++) cin >> arr[i];


    // DP 증가부순열로 바이토닉 수열 구하기
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) if(arr[j] < arr[i])  front_memo[i] = max(front_memo[i] , front_memo[j] + 1);

    for(int i = n-1; i >= 0; i--) for(int j = n-1; j > i; j--) if(arr[j] < arr[i]) back_memo[i] = max(back_memo[i], back_memo[j] + 1);

    for(int i = 0; i < n; i++)
    {
        int a = front_memo[i] + back_memo[i] - 1;
        if(result < a) result = a;
    }
    cout << result;
    return 0;
} 