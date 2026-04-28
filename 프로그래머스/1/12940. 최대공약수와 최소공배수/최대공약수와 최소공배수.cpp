#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer (2, 0);
    
    int a = n;
    int b = m;
    
    while (b)
    { 
        int r = a % b;
        a = b;
        b = r; 
    }
    answer[0] = a;
    answer[1] = (n*m)/answer[0];
    
    return answer;
}