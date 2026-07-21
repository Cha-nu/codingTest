#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> str_numbers;
    
    str_numbers.reserve(numbers.size());
    for(int num : numbers) str_numbers.push_back(to_string(num));
    
    sort(str_numbers.begin(), str_numbers.end(), [](const string& a, const string& b) {return a + b > b + a;});
    
    if(str_numbers.front() == "0") return "0";
    
    string answer = "";
    
    for (const string& str : str_numbers) answer += str;
    
    return answer;
}