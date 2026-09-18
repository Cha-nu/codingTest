#include <string>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> count(100001, 0);
    vector<int> values;
    int number = 0;

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            number = number * 10 + (c - '0');
        } else if (number > 0) {
            if (count[number] == 0) {
                values.push_back(number);
            }
            ++count[number];
            number = 0;
        }
    }

    int n = static_cast<int>(values.size());
    vector<int> answer(n);

    for (int value : values) {
        answer[n - count[value]] = value;
    }

    return answer;
}