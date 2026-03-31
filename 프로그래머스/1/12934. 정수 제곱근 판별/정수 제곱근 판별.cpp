using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long start = 1, end = n;
    while(end >= start)
    {
        long long i = start + (end - start) / 2;
        if(i != 0 && i == n / i && n % i == 0)
        {
            return((i+1)*(i+1));
        }
        else if(i <= n / i)
        {
            start = i+1;
        }
        else
        {
            end = i-1;
        }
    }
    return -1;
}