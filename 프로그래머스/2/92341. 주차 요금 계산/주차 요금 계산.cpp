#include <string>
#include <vector>
#include <map>
#include <sstream> 
#include <iostream>

using namespace std;

int caltime(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3, 2));
    
    return h * 60 + m;
}



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, int> time;
    map<int, int> stack_time;
    map<int, string> state;
    
    for(string r : records)
    {
        stringstream ss(r);
        string t;
        int num;
        string cmd;
        
        ss >> t >> num >> cmd;
        
        int current_time = caltime(t);
        
        if(cmd == "IN")
        {
            time[num] = current_time; // 차량 방문
            state[num] = "IN";
        }
        else if(cmd == "OUT")
        {
            stack_time[num] += current_time - time[num];
            state[num] = "OUT";
        }
    }
    
    for(auto& s : state) if(s.second == "IN") stack_time[s.first] += 1439 - time[s.first];
    
    answer.reserve(static_cast<int>(stack_time.size()));
    for(auto& t : stack_time)
    {
        t.second -= fees[0];
        int r = fees[1];
        
        if(t.second > 0)
        {
            r += (t.second / fees[2]) * fees[3];
            if(t.second%fees[2] > 0) r += fees[3];
        }
        answer.push_back(r);
    }

    
    return answer;
}