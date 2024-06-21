#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    vector<int> v = {1, 10, -1, 3, 15, 25, 12};
    for(const auto& i: v) {
        pq.push(i);
    }
    
    return 0;
}