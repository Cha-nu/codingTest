#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int cal(const string& t)
{
    int Y = stoi(t.substr(0, 4));
    int M = stoi(t.substr(5, 2));
    int D = stoi(t.substr(8, 2));
    
    return (Y * 12 * 28) + (M * 28) + D;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> te;
    
    int a = cal(today);
    
    for(const string& s : terms)
    {
        stringstream ss(s);
        char b;
        int c;
        ss >> b >> c;
        te[b] = c;
    }
    
    for(size_t i = 0; i < privacies.size(); i++)
    {
        stringstream ss(privacies[i]);
        string b;
        char c;
        ss >> b >> c;
        
        int d = cal(b);
        
        if(a >= d + te[c] * 28) answer.push_back(i+1);
    }
    
    return answer;
}

