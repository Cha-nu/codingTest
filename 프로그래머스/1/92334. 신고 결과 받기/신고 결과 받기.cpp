#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>


using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    
    int n = static_cast<int>(id_list.size());
    
    vector<int> answer(n, 0); // 결과
    
    unordered_map<string, int> um;
    
    for(int i = 0; i < n; ++i) um[id_list[i]] = i;
    
    vector<vector<bool>> m (n, vector<bool>(n, false)); // 신고를 한 사람;
    vector<int> re (n, 0); // 신고 당한 횟수
        
    for(string r : report)
    {
        stringstream ss(r);
        string a, b;
        ss >> a >> b;
        int i = um[b];
        int j = um[a];
        if(!m[i][j])
        {
            m[i][j] = true;
            ++re[i];
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        if(re[i] >= k)
        {
            for(int j = 0; j < n; ++j) if(m[i][j]) ++answer[j];
        }
    }
    
    
    return answer;
}