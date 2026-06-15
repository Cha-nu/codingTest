#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int cal(const std::string& s) // int day로 관리
{
    int Y = stoi(s.substr(0, 4));
    int M = stoi(s.substr(5, 2));
    int D = stoi(s.substr(8, 2));
    
    return (Y * 12 * 28) + (M * 28) + D;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> T;
    
    int r = cal(today);
    
    
    for(const string a : terms)
    {
        stringstream ss(a);
        string key;
        int val;
        ss >> key >> val;
        T[key] = val*28;
    }
    
    for(int i = 0; i < static_cast<int>(privacies.size()); ++i)
    {
        stringstream ss(privacies[i]);
        string d;
        string key;
        ss >> d >> key;
        int a = cal(d);
        if(r >= a + T[key]) answer.push_back(i+1);
    }
    return answer;
}