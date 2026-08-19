#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 투포인트 
    int left = 0;
    int right = people.size()-1;
    
    sort(people.begin(), people.end());
    
    for(int p : people) cout << p << '\n';
    
    while(left <= right)
    {
        if(people[left] + people[right] <= limit) ++left;
        
        ++answer;
        --right;
    }
    
    return answer;
}