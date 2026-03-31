#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n); // 2 

    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    // 원리: 가장 작은 것과 가장 큰 것 곱하기
    sort(A.begin(), A.end()); // 오름차순
    sort(B.rbegin(), B.rend()); // 내림차순

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result += (A[i] * B[i]);
    }
    cout << result;
    return 0;
}