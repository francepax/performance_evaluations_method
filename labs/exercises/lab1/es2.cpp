#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;


struct Comp {
    bool operator()(int a, int b) const {
        return a > b;
    }
}; 

class EventQueue {
    priority_queue<float, vector<float>, Comp> queue;
public:
    void insert(float n) {
        queue.push(n);
    }

    float next() {
        if (queue.empty())
            return -1;
        float x = queue.top();
        queue.pop();
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