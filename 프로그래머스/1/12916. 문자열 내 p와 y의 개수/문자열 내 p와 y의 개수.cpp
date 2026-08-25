#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{ 
    vector<int> a(2, 0);

    for(char c: s)
    {
        if(c == 'p' || c == 'P') ++a[0];
        else if(c == 'y' || c == 'Y') ++a[1];
    }

    return a[0] == a[1];
}