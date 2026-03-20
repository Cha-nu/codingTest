#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<int> numbers;
    for(int i = 1; i <= n; i++) numbers.push(i);

    for(int i = 1; i < m; i++)
    {
        numbers.push(numbers.front());
        numbers.pop();
    }
    cout << '<' << numbers.front();
    numbers.pop();

    while(!numbers.empty())
    {
        for(int i = 1; i < m; i++)
        {
            numbers.push(numbers.front());
            numbers.pop();
        }
        cout << ", " << numbers.front();
        numbers.pop();
    }
    cout << '>';
    return 0;
}