#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<bool> visited;
vector<int> arr;

void P(int depth)
{
    if(depth >= m) // 종료조건
    {
        // 출력
        for(int i : arr) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(visited[i-1]) continue;
        else
        {
            arr.push_back(i);
            visited[i-1] = true;
            P(depth+1);
            visited[i-1] = false;
            arr.pop_back();
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    visited.resize(n);

    P(0);

    return 0;
}