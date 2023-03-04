#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

const double EPS = 0.00000001;
const int MAX_IT = 10000000;

double search(double C) {
    double lo = 0, up = C, mid, value;
    for (int it = 0; it < MAX_IT; it++) {
        mid = (lo + up) / 2.0;
        value = pow(mid, 4) + mid;
        if (abs(C - value) < EPS) return mid * mid;

        if (value > C) {
            up = mid;
        } else {
            lo = mid;
        }
    }

    return mid * mid;
}

int main() {
    double C;
    cin >> C;

    cout << fixed << setprecision(6) << search(C) << endl;
}