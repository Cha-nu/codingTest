#include <string>
#include <vector>
#include <set>

using namespace std;

vector<bool> visited;

int isPrime(int n)
{
    if(n < 2) return 0; 
    for(int i = 2; i * i <= n; ++i) if(n % i == 0) return 0;
    return 1;
}

void dfs(const string& numbers, string number, set<int>& un)
{
    if(number != "") un.insert(stoi(number));
    
    for(int i = 0; i < static_cast<int>(numbers.size()); ++i)
    {
        if(!visited[i])
        {
            visited[i] = true;
            dfs(numbers, number+numbers[i], un);
            visited[i] = false;
        }
    }
}

int solution(string numbers)
{
    int cnt = 0;
    set<int> un;
    visited.assign(static_cast<int>(numbers.size()), false);
    dfs(numbers, "", un);
    
    for(int n : un) cnt += isPrime(n);
    
    return cnt;
}