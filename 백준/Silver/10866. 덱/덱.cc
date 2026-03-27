#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string commend;
    deque<int> dq;
    for(int i = 0; i < n; i++)
    {
        cin >> commend;
        if(commend == "push_back")
        {
            int val;
            cin >> val;
            dq.push_back(val);
        }
        else if(commend == "push_front")
        {
            int val;
            cin >> val;
            dq.push_front(val);
        }
        else if(commend == "pop_front")
        {
            if(dq.empty()) cout << -1 <<'\n';
            else
            {
                cout << dq.front() <<'\n';
                dq.pop_front();
            }
        }
        else if(commend == "pop_back")
        {
            if(dq.empty()) cout << -1 <<'\n';
            else
            {
                cout << dq.back() <<'\n';
                dq.pop_back();
            }
        }
        else if(commend == "front")
        {
            if(dq.empty()) cout << -1 <<'\n';
            else cout << dq.front() <<'\n';
        }
        else if(commend == "back")
        {
            if(dq.empty()) cout << -1 <<'\n';
            else cout << dq.back() <<'\n';
        }
        else if(commend == "size")
        {
            cout << dq.size() << '\n';
        }
        else if(commend == "empty")
        {
            cout << dq.empty() <<'\n';
        }
    }

}