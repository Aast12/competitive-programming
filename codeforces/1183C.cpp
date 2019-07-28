#include <iostream>

using namespace std;

typedef long long ull;

int main() {
    ull q, k, n, a, b, ans;
    cin >> q;

    while (q--) {
        ans = -1;
        cin >> k >> n >> a >> b;
        for (int i = n; i <= (k + b * n) / (a - b); i--) {
            if (k - a * i - b * (n - i) > 0) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
    }
}