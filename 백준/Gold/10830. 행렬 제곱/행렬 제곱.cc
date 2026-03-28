#include <iostream>
#include <vector>

using namespace std;

unsigned long long N, B;


vector<vector<unsigned long long>> multiply(const vector<vector<unsigned long long>>& A, const vector<vector<unsigned long long>>& B)
{
    vector<vector<unsigned long long>> tmp(N, vector<unsigned long long>(N, 0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                tmp[i][j] += (A[i][k] * B[k][j]);
            }
            tmp[i][j] %= 1000;
        }
    }
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B;

    vector<vector<unsigned long long>> mat(N, vector<unsigned long long>(N));
    vector<vector<unsigned long long>> ans(N, vector<unsigned long long>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> mat[i][j];
        }
        ans[i][i] = 1;
    }

    // 분할 정복
    while(B > 0)
    {
        if(B % 2 == 1)
        {
            ans = multiply(ans, mat);
        }
        mat = multiply(mat, mat);
        B /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}