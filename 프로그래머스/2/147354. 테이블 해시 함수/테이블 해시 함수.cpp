#include <algorithm>
#include <vector>

using namespace std;

int c;

bool cmp(vector<int> a, vector<int> b)
{
    if(a[c] == b[c]) return a[0] > b[0];
    return a[c] < b[c];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    c = col-1;
    
    sort(data.begin(), data.end(), cmp);
    
    int n = data.size();
    
    vector<int> s;
    
    for(int i = row_begin-1; i < row_end; ++i)
    {
        int a = 0;
        for(int d : data[i])
        {
            a += d % (i+1);
        }
        s.push_back(a);
    }
    
    int answer = s[0];
    
    for(int i = 1; i < s.size(); ++i)
    {
        answer ^= s[i];
    }
    
    
    
    return answer;
}