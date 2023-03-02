#include <iostream>
#include <queue>

using namespace std;

typedef unsigned long long ull;

int main() {
    int t, n;
    ull p, power;
    cin >> t;

    while (t--) {
        cin >> n;
        priority_queue<ull> pq;

        power = 0;
        for (int i = 0; i < n; i++) {
            cin >> p;
            if (p == 0) {
                if (!pq.empty()) {
                    power += pq.top();
                    pq.pop();
                }
            } else {
                pq.push(p);
            }
        }

        cout << power << endl;
    }
}