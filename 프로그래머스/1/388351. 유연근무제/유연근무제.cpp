#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); i++)
    {
        int day = startday - 1;
        int chk = ((schedules[i]+10)%100 > 59) ? schedules[i]+50 : schedules[i]+10;
        for(int j = 0; j < 7; j++)
        {
            day = (day + 1) % 7;
            if(day == 6 || day == 0) // 주말처리
            {
                if(j == 6) answer++;
            }
            else
            {
                if(chk < timelogs[i][j]) break; // 지각!
                if(j == 6) answer++;  // 이벤트 해당자
            }
        }
    }
    return answer;
}