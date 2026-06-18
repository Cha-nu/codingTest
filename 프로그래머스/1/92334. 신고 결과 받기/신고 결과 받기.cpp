#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int j = id_list.size();
    vector<int> answer(j, 0);
    vector<int> ans(j, 0);
    vector<vector<bool>> ad (j, vector<bool>(j, true));
    map<string, int> a;
    
    for(size_t i = 0; i < j; i++) a[id_list[i]] = i;
    
    for(const string& s : report)
    {
        stringstream ss(s);
        string n, m;
        ss >> n >> m;
        
        if(ad[a[n]][a[m]])
        {
            ad[a[n]][a[m]] = false; //false 신고
            ans[a[m]]++;
        }  
    }
    
    for(int i = 0; i < j ; i++)
    {
        if(ans[i] >= k)
        {
            for(int t = 0; t < j; t++)
            {
                if(!ad[t][i]) answer[t]++;
            }
        }
    }
    
    
    return answer;
}