#include <cmath>

using namespace std;

long long solution(int k, int d)
{
    long long answer = 0;
    long long distanceSquared = 1LL * d * d;

    for (long long x = 0; x <= d; x += k)
    {
        long long maxYSquared = distanceSquared - x * x;
        long long maxY = static_cast<long long>(sqrt(maxYSquared));

        // 부동소수점 오차 보정
        while ((maxY + 1) * (maxY + 1) <= maxYSquared)
            ++maxY;

        while (maxY * maxY > maxYSquared)
            --maxY;

        // y = 0, k, 2k, ... maxY
        answer += maxY / k + 1;
    }

    return answer;
}