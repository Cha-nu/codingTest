#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    
    // 포인터 및 현재 합계 초기화
    int left = 0;
    int right = 0;
    long long current_sum = sequence[0];
    
    // 정답을 기록할 변수
    int best_left = 0;
    int best_right = n; 
    
    while (right < n) {
        // 현재 부분 수열의 합이 k와 같을 때
        if (current_sum == k) {
            // 더 짧은 길이를 찾았을 경우에만 정답 갱신 
            if (right - left < best_right - best_left) {
                best_left = left;
                best_right = right;
            }
            // 다른 가능한 해를 찾기 위해 왼쪽 포인터를 이동
            current_sum -= sequence[left];
            left++;
        } 
        // 조건 2: 현재 합이 k보다 작을 때 
        else if (current_sum < k) {
            right++;
            if (right < n) {
                current_sum += sequence[right];
            }
        } 
        // 현재 합이 k보다 클 때 
        else {
            current_sum -= sequence[left];
            left++;
        }
    }
    
    return {best_left, best_right};
}