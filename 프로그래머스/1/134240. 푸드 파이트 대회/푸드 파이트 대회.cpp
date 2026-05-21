#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

string solution(vector<int> food) {
    string left_half = "";
    
    // [최적화] 불필요한 메모리 재할당을 방지하기 위해 필요한 문자열 길이를 미리 계산하고 Reserve 합니다.
    int expected_length = 0;
    for (int i = 1; i < food.size(); ++i) {
        expected_length += food[i] / 2;
    }
    left_half.reserve(expected_length);

    // 왼쪽 절반 문자열 구성
    for (int i = 1; i < food.size(); ++i) {
        int count = food[i] / 2;
        if (count > 0) {
            // 정수 i를 char로 변환하기 위해 '0'의 아스키 값을 더합니다. (조건: food 길이 <= 9)
            left_half.append(count, i + '0'); 
        }
    }

    // 오른쪽 절반 구성 및 결합
    string right_half = left_half;
    reverse(right_half.begin(), right_half.end());

    return left_half + "0" + right_half;
}