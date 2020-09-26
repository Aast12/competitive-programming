#include <iostream>

using namespace std;
typedef long long lli;

int main() {
    lli t, a, b, c, n;

    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> n;
        lli sum = a + b + c + n;
        if (sum % 3) {
            cout << "NO" << endl;
        } else {
            lli target = sum / 3;
            bool fl = 1;
            if (a > target || b > target || c > target) fl = 0;
            if ((target - a) + (target - b) + (target - c) != n) fl = 0;
            cout << ((fl) ? "YES" : "NO") << endl;
        }
    }
}