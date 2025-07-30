#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main(){
    string a;
    cin >> a;
    vector<int> numbers;
    vector<char> operators;

    string num;
    for(char b : a){
        if(isdigit(b)) num+=b;
        else{
            numbers.push_back(stoi(num));
            num.clear();
            operators.push_back(b);
        }
    }
    if(!num.empty()) numbers.push_back(stoi(num));

    for(int i = 0; i <operators.size();){
        if(operators[i] == '+'){
            numbers[i] += numbers[i+1];
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
        } else i++;
    }

    int result = numbers[0];
    for (int i = 0; i < operators.size(); ++i) {
        result -= numbers[i + 1];
    }

    cout << result;

    return 0;
}