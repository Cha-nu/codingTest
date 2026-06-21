#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = static_cast<int>(id_list.size());
    
    vector<vector<bool>> g (n, vector<bool> (n, true)); // 신고가능여부 행을 신고 한 사람
    vector<int> r (n, 0);
    vector<int> answer (n, 0);
    unordered_map<string, int> idx;
    
    for(int i = 0; i < n; i++) idx[id_list[i]] = i;
    
    for(const string& re: report) // 신고처리
    {
        stringstream ss(re);
        string x, y;
        ss >> x >> y;
        if(g[idx[y]][idx[x]])
        {
            g[idx[y]][idx[x]] = false;
            r[idx[y]]++; // 신고 당한 횟수
        }
        
        
    }
    // 정지 메일 받고 정지 보고 메일
    for(int i = 0; i < n; i++)
    {
        if(r[i] >= k)
        {
            for(int j = 0; j < n; j++) if(!g[i][j]) answer[j]++; // 신고 한 사람한테 메일
        }
    }

    return answer;
}