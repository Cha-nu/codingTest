#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// --- 큰 수 덧셈 함수 (Big Integer Addition) ---
// a와 b는 음수 부호가 없는 문자열 형태의 큰 정수여야 함
string add(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i--] - '0';
        }
        if (j >= 0) {
            sum += b[j--] - '0';
        }
        carry = sum / 10;
        result += to_string(sum % 10);
    }
    reverse(result.begin(), result.end());
    return result;
}

// --- 큰 수 비교 함수 (두 수가 같으면 0, a가 크면 1, b가 크면 -1 반환) ---
int compare(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() > b.length() ? 1 : -1;
    }
    if (a == b) return 0;
    return a > b ? 1 : -1;
}

// --- 큰 수 뺄셈 함수 (Big Integer Subtraction) ---
// a와 b는 음수 부호가 없는 문자열 형태의 큰 정수여야 하며, a >= b 임이 보장되어야 함
string subtract(string a, string b) {
    string result = "";
    int borrow = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0) {
        int diff = (a[i--] - '0') - borrow;
        if (j >= 0) {
            diff -= (b[j--] - '0');
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += to_string(diff);
    }

    reverse(result.begin(), result.end());
    // 불필요한 0 제거
    size_t first_digit = result.find_first_not_of('0');
    if (string::npos == first_digit) {
        return "0";
    }
    return result.substr(first_digit);
}

// --- 큰 수 덧셈/뺄셈 통합 처리 함수 (부호 처리) ---
string calculate_sum(string a, string b) {
    // A와 B의 부호를 저장
    bool a_neg = (a[0] == '-');
    bool b_neg = (b[0] == '-');
    
    // 부호 제거 (절댓값)
    string abs_a = a_neg ? a.substr(1) : a;
    string abs_b = b_neg ? b.substr(1) : b;
    
    // Case 1: 두 수의 부호가 같을 때 (A + B, (-A) + (-B)) -> 절댓값의 합 + 공통 부호
    if (a_neg == b_neg) {
        string res = add(abs_a, abs_b);
        return a_neg ? "-" + res : res;
    } 
    // Case 2: 두 수의 부호가 다를 때 (A + (-B), (-A) + B) -> 절댓값의 차
    else {
        int comp_res = compare(abs_a, abs_b);
        string res;
        bool result_neg = false;

        if (comp_res == 0) {
            return "0"; // 절댓값이 같으면 0
        } else if (comp_res > 0) { // |A| > |B| -> 부호는 A의 부호를 따름
            res = subtract(abs_a, abs_b);
            result_neg = a_neg;
        } else { // |A| < |B| -> 부호는 B의 부호를 따름
            res = subtract(abs_b, abs_a);
            result_neg = b_neg;
        }

        return result_neg ? "-" + res : res;
    }
}

// --- 큰 수 뺄셈 통합 처리 함수 (부호 처리) ---
// A - B = A + (-B) 로 변환하여 calculate_sum 재활용
string calculate_diff(string a, string b) {
    // B의 부호를 반전
    string neg_b;
    if (b == "0") {
        neg_b = "0"; // 0은 부호 없음
    } else if (b[0] == '-') {
        neg_b = b.substr(1); // -B -> B
    } else {
        neg_b = "-" + b; // B -> -B
    }
    // A + (-B) 계산
    return calculate_sum(a, neg_b);
}

// --- 큰 수 곱셈 함수 (Big Integer Multiplication) ---
// a와 b는 음수 부호가 없는 문자열 형태의 큰 정수여야 함
string multiply(string a, string b) {
    if (a == "0" || b == "0") return "0";

    // 결과 배열의 최대 크기는 a.length() + b.length()
    vector<int> result(a.length() + b.length(), 0); 
    
    // a와 b를 뒤집어 처리하면 인덱스 관리가 편리함
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < a.length(); ++i) {
        for (int j = 0; j < b.length(); ++j) {
            int digit_a = a[i] - '0';
            int digit_b = b[j] - '0';
            
            int prod = digit_a * digit_b;
            int sum = prod + result[i + j];
            
            result[i + j] = sum % 10; // 현재 자릿수
            result[i + j + 1] += sum / 10; // 다음 자릿수로 올림
        }
    }

    // 결과 문자열로 변환
    string final_result = "";
    // 최상위 자리(result의 마지막 원소)부터 시작하여 0이 아닌 첫 자리 찾기
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }
    
    // 결과가 0인 경우 처리 (위에서 "0"인 경우는 이미 처리함)
    if (i < 0) return "0"; 

    while (i >= 0) {
        final_result += to_string(result[i--]);
    }

    return final_result;
}

// --- 큰 수 곱셈 통합 처리 함수 (부호 처리) ---
string calculate_prod(string a, string b) {
    if (a == "0" || b == "0") return "0";

    bool a_neg = (a[0] == '-');
    bool b_neg = (b[0] == '-');

    string abs_a = a_neg ? a.substr(1) : a;
    string abs_b = b_neg ? b.substr(1) : b;

    string res = multiply(abs_a, abs_b);

    // 부호가 같으면 양수, 다르면 음수
    if (a_neg == b_neg) {
        return res;
    } else {
        return "-" + res;
    }
}


int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    // 입력
    if (!(cin >> A >> B)) return 0;

    // A + B
    cout << calculate_sum(A, B) << "\n";

    // A - B
    cout << calculate_diff(A, B) << "\n";

    // A * B
    cout << calculate_prod(A, B) << "\n";

    return 0;
}