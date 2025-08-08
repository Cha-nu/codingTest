#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

using namespace std;

deque<int> string_to_int_vector(const std::string& s) {
    deque<int> result;
    string temp_s = s;

    // 불필요한 문자 제거
    temp_s.erase(remove(temp_s.begin(), temp_s.end(), '['), temp_s.end());
    temp_s.erase(remove(temp_s.begin(), temp_s.end(), ']'), temp_s.end());
    temp_s.erase(remove(temp_s.begin(), temp_s.end(), ' '), temp_s.end());

    stringstream ss(temp_s);
    string segment;

    // 문자열 분리 및 정수 변환, 벡터에 저장
    while(getline(ss, segment, ',')) {
        if (!segment.empty()) {
            result.push_back(std::stoi(segment));
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string p;
        cin >> p;
        int n;
        cin >> n;
        string s;
        cin >> s;
        deque<int> arr = string_to_int_vector(s);
        bool rev = false;
        bool err = false;

        for(char q: p){
            if(q == 'R'){
                rev = !rev;
            }
            else if (q == 'D'){
                if(arr.empty()){ // 비어있으면 에러 저장
                    err = true;
                    break;
                }
                else{
                    if (rev) {
                        arr.pop_back(); // 뒤집힌 상태면 맨 뒤 삭제
                    } else {
                        arr.pop_front(); // 아니면 맨 앞 삭제
                    }
                }
            }
            
        }
        if (err) {
            cout << "error" << '\n';
        } else {
            cout << '[';
            if (rev) {
                for (int i = arr.size() - 1; i >= 0; i--) {
                    cout << arr[i] << (i == 0 ? "" : ",");
                }
            } else {
                for (size_t i = 0; i < arr.size(); i++) {
                    cout << arr[i] << (i == arr.size() - 1 ? "" : ",");
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}