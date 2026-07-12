#include <string>
#include <vector>

using namespace std;

const char dic[5] = {'A', 'E', 'I', 'O', 'U'};

int total_count = 0;
int answer_idx = 0;
bool is_found = false;

void dfs(const string& target_word, string current_word)
{
    if(current_word == target_word)
    {
        answer_idx = total_count;
        is_found = true;
        return;
    }
    
    if(current_word.length() == 5)
    {
        return;
    }
    
    for(int i = 0; i < 5; ++i)
    {
        if(is_found) return;
        
        ++total_count;
        dfs(target_word, current_word+dic[i]);
    }
    
}

int solution(string word) {
    total_count = 0;
    answer_idx = 0;
    is_found = false;
 
    dfs(word, "");
    
    return answer_idx;
}