#include <numeric>

using namespace std;

long long solution(int w,int h) {
    return 1LL*w*h - (w+h - gcd(w, h));
}