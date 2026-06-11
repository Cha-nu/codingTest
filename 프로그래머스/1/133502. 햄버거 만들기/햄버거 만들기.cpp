#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0; 
    int idx = 0;
    vector<int> st;
    
    for(const int i : ingredient)
    {
        if(i == 1 && idx > 2 && !st.empty())
        {
            if(st[idx-3] == 1 && st[idx-2] == 2 && st[idx-1] == 3)
            {
                st.pop_back();
                st.pop_back();
                st.pop_back();
                answer++;
                idx -= 3;
                continue;
            }
        }
        st.push_back(i);
        idx++;
    }
    return answer;
}