using namespace std;

int solution(int n) {
     if(n == 1) return 1;
    int answer = 0;
    int left = 1;
    int right = 2;
    int sum = left + right;
    
    while(left <= right && right <= n)
    {
        if(sum < n)
        {
            ++right;
            sum += right;
            continue;
        }
        else if(sum == n)  ++answer;
            
        sum -= left;
        ++left;
    }
    
    return answer;
}