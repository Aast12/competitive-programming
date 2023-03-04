#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int perf_squares(int n) {
    float last_sqr = floor(sqrt(n));
    return (int) last_sqr;
    // return (int)pow(last_sqr, 2.0);
}

int perf_cubes(int n) {
    float last_cbr = floor(pow(n, 1.0 / 3.0));
    return (int) last_cbr;
    // return (int)pow(last_cbr, 3.0);
}

int search_x(int x) {
    int lo = 0, up = sqrt(INT32_MAX), mid;
    while (lo < up) {
        mid = pow(floor((lo + up) / 2), 2);
        int f = perf_squares(mid) - perf_cubes(mid);
        // cout << lo << " - " << mid << " - " << up << " -> " << f << endl;
        if (f >= x) {
            up = sqrt(mid);
        } else {
            lo = sqrt(mid) + 1;
        }
    }

    return up;
}

int main() {
    int t, x, ans;
    cin >> t;

    while (t--) {
        cin >> x;
        ans = search_x(x);
        cout << ans * ans << endl;
        // cout << perf_squares(ans * ans) << " " << perf_cubes(ans * ans) << endl;
    }
}