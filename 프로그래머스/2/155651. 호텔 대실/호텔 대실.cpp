#include <string>
#include <vector>
#include <algorithm>

using namespace std;
pair<int, int> cal(string a, string b)
{
    int c = stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
    int d = stoi(b.substr(0, 2)) * 60 + stoi(b.substr(3, 2));
    
    return {c, d};
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b) // 내림차순 정렬
{
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}


int solution(vector<vector<string>> book_time) {
    int n = static_cast<int>(book_time.size());
    
    vector<pair<int, int>> int_time;
    vector<pair<int, int>> room;
    int_time.reserve(n);
    
    for(int i = 0; i < n; ++i) int_time.push_back(cal(book_time[i][0], book_time[i][1]));
    
    sort(int_time.begin(), int_time.end(), cmp);

    // 10분 
    
    for(pair<int,int> t : int_time)
    {
        if(room.empty()) room.push_back(t);
        else
        {
            for(int i = 0; i < static_cast<int>(room.size()); ++i)
            {
                if(room[i].second + 10 <= t.first)
                {
                    room[i].second = t.second;
                    break;
                }
                else if(i >= static_cast<int>(room.size()) - 1)
                {
                    room.push_back(t);
                    break;
                }
            }
        }
    }
    
    return static_cast<int>(room.size());
}