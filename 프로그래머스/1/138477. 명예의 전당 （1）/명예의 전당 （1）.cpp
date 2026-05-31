#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) 
{
    int n = static_cast<int>(score.size());
    vector<int> answer (n, 0);
    
    vector<int> a;
    
    for(int i = 0; i < n; i++)
    {
        if(i < k) // k번째전까지는 넣기
        {
            a.push_back(score[i]);
        }
        else // k번째부터는 비교 가장 작은 것이 탈락한다.
        {
            if(a.back() < score[i])
            {
                a.back() = score[i];
            }
        }
        sort(a.rbegin(), a.rend());
        answer[i] = a.back();
    }

    return answer;
}