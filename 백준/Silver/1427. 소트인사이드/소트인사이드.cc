#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    vector<int> result;
    int nl = static_cast<int>(n.length());
    result.resize(nl);

    for(int i = 0; i < nl; i++)
    {
        result[i] = (n[i]-'0');
    }
    sort(result.rbegin(), result.rend());

    for(int r : result) cout << r;
    return 0;
}