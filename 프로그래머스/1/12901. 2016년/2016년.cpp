#include <vector>
#include <string>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int currentMonth = 1;
    int currentDate = 1;
    int currentDay = 5; // "FRI"
    
    vector<string> day = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    while((currentMonth < a) || ( currentMonth == a && currentDate < b))
    {
        while(currentDate <= month[currentMonth-1])
        {
            if(currentMonth == a && currentDate == b) break;
            currentDate++;
            currentDay = (currentDay + 1) % 7;
        }
        
        if(currentDate > month[currentMonth-1])
        {
            currentMonth++;
            currentDate = 1;
        }
        
    }
    
    answer = day[currentDay];
    return answer;
}