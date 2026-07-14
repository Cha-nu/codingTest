#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    // 슬라이싱 윈도우
    int n = static_cast<int>(topping.size());
    
    int max_topping = 0;
    for(int t : topping) if(t > max_topping) max_topping = t;
    
    vector<int> right_count(max_topping + 1, 0);
    int right_types = 0;
    
    for(int t : topping)
    {
        if(right_count[t] == 0) ++right_types;
        ++right_count[t];
    }
    
    vector<bool> left_visited(max_topping + 1, false);
    int left_types = 0;
    
    for(int i = 0; i < n-1; ++i)
    {
        int current_topping = topping[i];
        
        if(!left_visited[current_topping])
        {
            left_visited[current_topping] = true;
            ++left_types;
        }
        
        --right_count[current_topping];
        if(right_count[current_topping] == 0) --right_types;
        
        if(left_types == right_types) ++answer;
    }
    
    return answer;
}