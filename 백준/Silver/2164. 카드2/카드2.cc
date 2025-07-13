#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    cin >> N;

    queue<int> card;

    for(int i = 0; i < N; i++) card.push(i+1);

    while(true){
        if(card.size() <= 1) break;
        card.pop();
        int a = card.front();
        card.pop();
        card.push(a);
    }

    cout << card.front();
    return 0;
}