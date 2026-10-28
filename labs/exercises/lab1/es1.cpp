#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class EventQueue {
    vector<float> queue;
public:
    void insert(float n) {
        queue.push_back(n);
    }

    float next() {
        if (queue.empty())
            return -1;
        auto it = min_element(queue.begin(), queue.end());
        float x = *it;
        queue.erase(it);
        return x;
    }
};

int main() {
    EventQueue q;
    float x;
    while (cin >> x && x >= 0) {
        q.insert(x);
    }
    while(1){
        float x = q.next();
        if (x == -1)
            break;
    }  
    return 0;
}