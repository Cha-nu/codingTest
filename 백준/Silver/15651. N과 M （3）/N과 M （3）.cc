#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<int> num;

void print(int depth)
{
    if(depth >= M){
        for(int j : num) cout << j << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        num.push_back(i);
        print(depth+1);
        num.pop_back();
    }
}

int main()
{
    cin >> N >> M;

    print(0);

}