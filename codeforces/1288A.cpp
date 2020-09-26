#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

bool bin_search(ull lb, ull ub, ull n, ull d) {
    while (lb < ub) {
        ull mid = (lb + ub) / 2;
        if (mid + ceil(double(d) / (mid + 1)) <= n) {
            return true;
        }
        else {
            lb = mid + 1;
        }
    }
    return false;
}


int main() {
    ull t, n, d;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        if (bin_search(0, n, n, d)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}