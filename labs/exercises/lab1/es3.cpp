#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

#ifndef M
#define M 1000
#endif
#define WIDTH 10.0

class EventQueue {
    vector<list<double>> buckets;
    size_t cur = 0;
    double bucketTop = WIDTH;
    size_t n = 0;

    size_t idx(double t) const {
        return static_cast<size_t>(t / WIDTH) % M;
    }

public:
    EventQueue() : buckets(M) {}

    void insert(double t) {
        auto& b = buckets[idx(t)];
        b.insert(upper_bound(b.begin(), b.end(), t), t);
        n++;
    }

    double next() {
        if (n == 0)
            return -1;

        // scorro i bucket a partire da quello corrente
        for (size_t k = 0; k < M; k++) {
            auto& b = buckets[cur];
            if (!b.empty() && b.front() < bucketTop) {
                double x = b.front();
                b.pop_front();
                n--;
                return x;
            }
            cur = (cur + 1) % M;
            bucketTop += WIDTH;
        }

        // giro completo senza trovare nulla: cerco il minimo tra le teste
        size_t best = 0;
        double m = INFINITY;
        for (size_t i = 0; i < M; i++)
            if (!buckets[i].empty() && buckets[i].front() < m) {
                m = buckets[i].front();
                best = i;
            }
        cur = best;
        bucketTop = (floor(m / WIDTH) + 1) * WIDTH;
        double x = buckets[cur].front();
        buckets[cur].pop_front();
        n--;
        return x;
    }
};

int main() {
    EventQueue q;
    double x;
    while (cin >> x && x >= 0)
        q.insert(x);
    while (true) {
        double v = q.next();
        if (v == -1)
            break;
    }
    return 0;
}