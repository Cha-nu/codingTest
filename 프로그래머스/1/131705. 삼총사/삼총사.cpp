#include <vector>

using namespace std;

int answer = 0;

void backtrack(vector<int>& number, int start, int count, int currentSum) {
    if (count == 3) {
        if (currentSum == 0) {
            answer++;
        }
        return;
    }

    for (int i = start; i < number.size(); i++) {
        backtrack(number, i + 1, count + 1, currentSum + number[i]);
    }
}

int solution(vector<int> number) {
    answer = 0;
    backtrack(number, 0, 0, 0);
    return answer;
}