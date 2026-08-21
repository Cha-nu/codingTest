#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> m (n);
    unordered_map<string, int> um;
    
    ++um[words[0]];
    ++m[0];
    
    for(int i = 1; i < words.size(); ++i)
    {
        ++m[i%n];
        ++um[words[i]];
        if(um[words[i]] > 1 || (words[i-1].back() != words[i][0])) return {(i%n+1), m[i%n]};
    }
    return {0, 0};
}