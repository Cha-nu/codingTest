#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr) {
    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    return sum / arr.size();
}