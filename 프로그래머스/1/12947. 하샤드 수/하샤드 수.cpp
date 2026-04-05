#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int y = x;
    int xsum = 0;
    while(y > 0)
    {
        xsum += y % 10;
        y /= 10;
    }
    if(x % xsum == 0) answer = true;
    else answer = false;
    return answer;
}