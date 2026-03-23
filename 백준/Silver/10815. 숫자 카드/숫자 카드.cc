#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> cards(n);
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        cards[i] = val;
    }
    sort(cards.begin(), cards.end());

    int m;
    cin >> m;

    for(int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        int b = 0;
        int e = n-1;
        bool found = false;

        // 이진 탐색
        while(b <= e)
        {
            int j = (b+e)/2;
            int a = cards[j];
            if(a > num) e = j-1;
            else if (a < num) b = j+1;
            else
            {
                found = true;
                break;
            }
        }
        if(found) cout << 1 << ' ';
        else cout << 0 << ' ';
    }

    return 0;
}