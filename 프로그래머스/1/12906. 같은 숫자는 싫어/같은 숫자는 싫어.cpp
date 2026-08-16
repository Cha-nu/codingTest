#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    queue<int> q;
    
    for(int a : arr)
    {
        if(q.empty()) q.push(a);
        else if(q.back() != a) q.push(a);

    }
    
    vector<int> answer;
    answer.reserve(q.size());
    
    while(!q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }

    return answer;
}