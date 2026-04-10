#include <iostream>

#define X 1000000007

using namespace std;

unsigned long long dnq(unsigned long long b)
{
    unsigned long long result = 1, e = X-2;
    b %= X;
    while(e > 0)
    {
        if(e % 2 == 1) result = (result * b) % X;
        b = (b * b) % X;
        e /= 2;
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    unsigned long long result = 0;
    for(int i = 0; i < m; i++)
    {
        unsigned long long n, s, a;
        cin >> n >> s;
        /*
            n*a = 1(mod X)
            n^(X-2) = n^(-1) (mod X)
            result = s * a % X
        */
        a = dnq(n); // 분할정복
        result = (result + ((s * a) % X)) % X;
    }

    cout << result;
    return 0;
}