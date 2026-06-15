#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> b;
    for(int i : ingredient)
    {
        int idx = static_cast<int>(b.size());
        if(i == 1 && idx > 2 && b[idx-3] == 1 && b[idx-2] == 2 && b[idx-1] == 3)
        {
            b.pop_back();
            b.pop_back();
            b.pop_back();
            answer++;
            continue;
        }
        b.push_back(i);
    }
    return answer;
}