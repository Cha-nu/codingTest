#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.empty()) return {-1};
    
    int minidx = 0;
    int minval = arr[0];
    for(int i= 0; i < static_cast<int>(arr.size()); i++)
    {
        if(arr[i] < minval)
        {
            minval = arr[i];
            minidx = i;
        }
        
    }
    arr.erase(arr.begin()+minidx);
    if(arr.empty()) return {-1};
    
    return arr;
}