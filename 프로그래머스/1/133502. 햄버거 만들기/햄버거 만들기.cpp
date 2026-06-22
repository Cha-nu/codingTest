#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> st;
    
    
    for(int i : ingredient)
    {
        int n = static_cast<int>(st.size());
        if(i == 1 && n >= 3 && st[n-3] == 1 && st[n-2] == 2 && st[n-1] == 3)
        {
            st.pop_back();
            st.pop_back();
            st.pop_back();
            answer++;
        }
        else st.push_back(i);
    }
    
    return answer;
}