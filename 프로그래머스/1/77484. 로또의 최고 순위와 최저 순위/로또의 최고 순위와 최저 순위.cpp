#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> lt = {6, 6, 5, 4, 3, 2, 1};
    
    int idx1 = 0, idx2 = 0;

    
    for(int i = 0; i < static_cast<int>(lottos.size()); i++)
    {
        if(lottos[i] == 0) idx1++;
        if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
        {
            idx1++;
            idx2++;
        }
        
    }
    
    cout << idx1 << ' ' << idx2;
    
    answer.push_back(lt[idx1]);
    answer.push_back(lt[idx2]);
    
    return answer;
}