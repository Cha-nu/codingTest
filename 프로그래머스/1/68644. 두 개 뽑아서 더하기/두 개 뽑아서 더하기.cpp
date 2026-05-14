#include <set>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum;
    
    int loop  = numbers.size();
    
    for(int i = 0; i < loop; i++)
    {
        for(int j = i + 1; j  < loop; j++) sum.insert(numbers[i] + numbers[j]);
    }
    vector<int> answer(sum.begin(), sum.end());
    return answer;
}