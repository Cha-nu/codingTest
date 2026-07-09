#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = static_cast<int>(numbers.size());
    
    queue<int> q;
    q.push(0);
    
    for(int i = 0; i <= n; ++i)
    {
        int m = static_cast<int>(q.size());
        while(m--)
        {
            int a = q.front();
            q.pop();
            if(i == n)
            {
                if(a == target) ++answer;
            }
            else
            {
                q.push(a+numbers[i]);
                q.push(a-numbers[i]);
            } 
        }
    }
    
    return answer;
}