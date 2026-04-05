using namespace std;

int solution(int num) {
    int answer = -1;
    unsigned long long a = num;
    for(int i = 0; i < 500; i++)
    {
        if(a == 1)
        {
            answer = i;
            break;
        }
        if(a % 2 == 0) a /= 2;
        else a = a * 3 + 1;
    }
    return answer;
}