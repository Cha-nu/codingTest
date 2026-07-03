#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    int n = static_cast<int>(elements.size());
    
    unordered_set<int> s;
    vector<int> e = elements;
    e.insert(e.end(), elements.begin(), elements.end());
    
    for(int i = 0; i < n; ++i)
    {
        int sum = 0;
        for(int j = 0; j < n; ++j)
        {
            sum += e[i+j];
            s.insert(sum);
        }
    }
    
    return (static_cast<int>(s.size()));
}