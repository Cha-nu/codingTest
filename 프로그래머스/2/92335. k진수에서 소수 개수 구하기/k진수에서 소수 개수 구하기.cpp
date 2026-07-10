#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPrime(long long number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    long long sqrtNum = static_cast<long long>(sqrt(number));
    for (long long i = 3; i <= sqrtNum; i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string kBaseStr = "";
    while (n > 0) {
        kBaseStr += to_string(n % k);
        n /= k;
    }
    reverse(kBaseStr.begin(), kBaseStr.end());
    
    string currentToken = "";
    for (char ch : kBaseStr) {
        if (ch == '0') {
            if (!currentToken.empty()) {
                long long candidate = stoll(currentToken);
                if (isPrime(candidate)) {
                    answer++;
                }
                currentToken = "";
            }
        } else {
            currentToken += ch;
        }
    }
    
    if (!currentToken.empty()) {
        long long candidate = stoll(currentToken);
        if (isPrime(candidate)) {
            answer++;
        }
    }
    
    return answer;
}