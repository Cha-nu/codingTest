#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string binary(int n, int a)
{
    string b;
    
    for(int i = 0; i < n; ++i)
    {
        b.push_back(a % 2 + '0');
        a /= 2;
    }
    reverse(b.begin(), b.end());
    return b;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; ++i)
    {
        string a = binary(n, arr1[i]);
        string b = binary(n, arr2[i]);
        string c;
        for(int j = 0; j < n; ++j)
        {
            if(a[j] == '1' || b[j] == '1') c.push_back('#');
            else c.push_back(' ');
        }
        answer.push_back(c);
    }
    
    return answer;
}