#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int a = 0;
    int b = 0;
    int score = 0;

    while (a < A.size() && b < B.size())
    {
        if (B[b] > A[a])
        {
            ++score;
            ++a;
            ++b;
        }
        else
        {
            // B[b]로는 현재 가장 약한 A[a]조차 못 이김
            // 따라서 이 B는 누구도 이길 수 없음
            ++b;
        }
    }

    return score;
}