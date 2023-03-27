#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, double> crash;  // i j t
typedef tuple<int, int, int> drone;     // i x v

struct CrashTime {
    list<drone>::iterator it;
    int i;
    double t;

    CrashTime() {}
    CrashTime(list<drone>::iterator it, int i, int t) : it(it), i(i), t(t) {}
};

bool operator<(const CrashTime& a, const CrashTime& b) { return a.t > b.t; }

int killcheck(list<drone>& drones, set<int>& alive, list<drone>::iterator it,
              int n, int min_t) {
    if (it == drones.end()) return -1;
    cout << "CHECK " << get<0>(*(it)) << endl;

    auto d0 = *it;
    // it++;

    priority_queue<CrashTime> kill_times;
    for (auto jit = next(it); jit != drones.end(); jit++) {
        auto d1 = *jit;
        // if (get<2>(d1) >= get<2>(d0)) break;
        int dv = get<2>(d0) - get<2>(d1);
        if (dv == 0) continue;
        double crash_t = (get<1>(d1) - get<1>(d0)) / double(dv);
        if (crash_t > 0) {
            cout << "ADD " << get<0>(*(it)) << " - " << get<0>(*(jit)) << endl;
            kill_times.push(CrashTime(jit, get<0>(*jit), crash_t));
        }
        // crashes.push_back(make_tuple(i, j, crash_t));
    }

    while (!kill_times.empty()) {
        auto top = kill_times.top();
        kill_times.pop();
        if (alive.find(top.i) == alive.end()) continue;
        if (top.t > min_t) {
            int next_t = killcheck(drones, alive, top.it, n, top.t);
            if (next_t == -1 || next_t >= top.t) {
                int x = get<0>(*(top.it));
                cout << "1DEL " << x << endl;
                alive.erase(x);
                drones.erase(top.it);
                return min_t;
            } else {
                int x = get<0>(*(top.it));
                cout << "2DEL " << x << endl;
                alive.erase(x);
                drones.erase(top.it);
            }

            // drones.erase(top.it);
            // return min_t;
        } else {
            int x = get<0>(*(top.it));
            cout << "3DEL " << x << endl;
            alive.erase(x);
            drones.erase(top.it);
        }
    }

    return -1;
}

int main() {
    int n, x, v;

    cin >> n;
    list<drone> drones;
    // vector<pii> drones(n);
    set<int> alive;
    for (int i = 0; i < n; i++) {
        cin >> x >> v;
        drones.push_back({i, x, v});
        // drones[i] = {x, v};
        alive.insert(i);
    }

    for (auto it = drones.begin(); it != drones.end(); it++) {
        auto kill = killcheck(drones, alive, it, n, -1);
        cout << "q " << get<0>(*it) << endl;
        if (kill != -1) {
            drones.erase(it);
        }
    }

    // sort(drones.begin(), drones.end(),
    //      [](const drone& a, const drone& b) { return get<1>(a) < get<1>(b);
    //      });

    // vector<crash> crashes;
    // for (int i = 0; i < n; i++) {
    //     // sort(drones.begin() + i + 1, drones.end(),
    //     //      [](const drone& a, const drone& b) {
    //     //          return get<2>(a) < get<2>(b);
    //     //      });

    //     auto d0 = drones[i];
    //     for (int j = i + 1; j < n; j++) {
    //         auto d1 = drones[j];
    //         // if (get<2>(d1) >= get<2>(d0)) break;

    //         int dv = get<2>(d0) - get<2>(d1);
    //         double crash_t = (get<1>(d1) - get<1>(d0)) / double(dv);
    //         crashes.push_back(make_tuple(i, j, crash_t));
    //     }
    // }

    // sort(crashes.begin(), crashes.end(),
    //      [](const crash& a, const crash& b) { return get<2>(a) < get<2>(b);
    //      });

    // for (auto& crash_i : crashes) {
    //     auto left = get<0>(crash_i);
    //     auto right = get<1>(crash_i);

    //     if (alive.find(left) != alive.end() &&
    //         alive.find(right) != alive.end()) {
    //         alive.erase(left);
    //         alive.erase(right);
    //     }
    // }

    cout << alive.size() << endl;
    for (auto& drone : alive) {
        cout << drone + 1 << " ";
    }
    cout << endl;
}

/*
6
0 3 2 2 3 1 4 3 5 2 6 3

10
-8 1 -4 1 -3 3 -2 -9 2 -3 4 1 5 1 6 4 8 4 10 3

*/