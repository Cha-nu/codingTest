#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer;
    int yn = (n-1)/w , ynum = (num-1)/w;
    int xn = (yn % 2 == 0) ? (n-1) % w : (w-1)-((n-1) % w);
    int xnum = (ynum % 2 == 0) ? (num-1) % w : (w-1)-((num-1) % w);
    bool has_box = false;
    if(yn % 2 == 0){if(xnum <= xn) has_box = true;}
    else{ if(xnum >= xn) has_box = true; }
    
    answer = has_box ? yn - ynum + 1 : yn - ynum;
    return answer;
}