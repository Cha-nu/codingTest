#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int cal(const string& day)
{
    int Y = stoi(day.substr(0, 4));
    int M = stoi(day.substr(5, 2));
    int D = stoi(day.substr(8, 2));
    
    return Y * 12 * 28 + M * 28 + D;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int t = cal(today);
    map<char, int> te;
    
    for(const string& term: terms)
    {
        stringstream ss(term);
        char c;
        int m;
        ss >> c >> m;
        te[c] = m*28;
    }
    
    for(size_t i = 0; i < privacies.size(); ++i)
    {
        stringstream ss(privacies[i]);
        string d;
        char c;
        ss >> d >> c;
        int day = cal(d) + te[c];
        if(t >= day) answer.push_back(i+1);
    }
    
    
    
    return answer;
}