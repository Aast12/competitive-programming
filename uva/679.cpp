#include <cmath>
#include <iostream>

using namespace std;

int search(int d, int i) {
    int d_pow = (1 << (d - 1));

    int lo = d_pow, hi = d_pow * 2 - 1;

    int depth = 1;
    for (int k = 0; k < d - 1; k++) {
        if (i % 2) {
            if (k == d - 2) return lo;
            hi = floor((lo + hi) / 2.0);
        } else {
            if (k == d - 2) return hi;
            lo = ceil((lo + hi) / 2.0);
        }

        i = ceil(i / 2.0);
    }
}

int main() {
    int t, d, i;

    cin >> t;

    while (t--) {
        cin >> d >> i;
        cout << search(d, i) << endl;
    }

    cin >> t;  // -1
}