#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int count = 0;

    deque<int> dq;
    for(int i = 1; i <= N; i++) dq.push_back(i);

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        int idx = 0;
        int sz = dq.size();
        for(int j = 0; j < sz; j++)
        {
            if(dq[j] == num)
            {
                idx = j;
                break;
            }
        }

        if(idx <= sz/2)
        {
            while(dq.front() != num) // 왼쪽 시프트
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
        }
        else
        {
            while(dq.front() != num) // 오른쪽 시프트
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }
        dq.pop_front();
    }

    cout << count;
    return 0;
}