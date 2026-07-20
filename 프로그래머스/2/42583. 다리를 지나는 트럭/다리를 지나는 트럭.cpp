#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int current_weight = 0;
    int time = 0;           
    int truck_idx = 0;     


    for (int i = 0; i < bridge_length; ++i) {
        bridge.push(0);
    }

    while (!bridge.empty()) {
        time++;
        
        current_weight -= bridge.front();
        bridge.pop();

        if (truck_idx < truck_weights.size()) {
            if (current_weight + truck_weights[truck_idx] <= weight) {
                bridge.push(truck_weights[truck_idx]);
                current_weight += truck_weights[truck_idx];
                truck_idx++; 
            } else {
                bridge.push(0);
            }
        }
    }

    return time;
}