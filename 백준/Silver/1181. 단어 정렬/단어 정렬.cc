#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareStringsByLength(const std::string& a, const std::string& b) {
    if (a.length() < b.length()) return true;
    else if (a.length() > b.length()) return false;
    else return a < b;
}

int main(){
    int N;
    cin >> N;
    vector<string> v;
    string temp;

    while(cin >> temp){
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compareStringsByLength);
    v.erase(unique(v.begin(),v.end()),v.end());
    for(const auto& s : v) {
        cout << s << '\n';
    }

}