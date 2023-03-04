#include <iomanip>
#include <iostream>

using namespace std;

double epsilon = 0.0000001;

double findRate(int q, int T) {
    double lo = 0, up = T, t = (lo + up) / 2, q_p, rate, delta;
    while (lo < up) {
        rate = (double)80 / t;
        q_p = rate * t + (rate / 2) * (T - t);
        delta = abs(q_p - q);
        if (delta < epsilon) {
            return rate;
        }
        if (q_p < q) {
            up = t;
            t = (lo + t) / 2.0;
        } else {
            lo = t;
            t = (t + up) / 2.0;
        }
    }

    t = (lo + up) / 2.0;
    return rate = (double)80 / t;
}

int main() {
    int t, p, q;
    double rate, t0, t1, T;
    cin >> t >> p;
    q = 100 - p;

    if (q < 80) {
        rate = q / t;
    } else {
        rate = findRate(q, t);
    }

    t0 = 80.0 / rate;
    t1 = 40.0 / rate;

    cout << fixed << setprecision(5) << t0 + t1 - t << endl;
}