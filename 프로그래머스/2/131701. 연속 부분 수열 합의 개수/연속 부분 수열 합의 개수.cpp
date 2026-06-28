#include <unordered_set>
#include <vector>

using namespace std;


int solution(vector<int> elements) {
    size_t n = elements.size();
    unordered_set<int> s;
    
    vector<int> e = elements;
    e.insert(e.end(), elements.begin(), elements.end());
    
    
    for(size_t i = 0; i < n; ++i)
    {
        int sum = 0;
        for(size_t j = 0; j < n; ++j)
        {
            sum += e[i+j];
            s.insert(sum);
        }
    }
    
    return s.size();
}