#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t, n, a;

    cin >> t;
    while (t--) {
        cin >> n;

        int twos[n];

        for (int i = 0; i < n; i++) {
            cin >> a;
            twos[i] = a == 1 ? 0 : 1;
            if (i > 0) twos[i] += twos[i - 1];
        }

        int total = twos[n - 1];

        if (total & 1) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < n; i++) {
                if (twos[i] == total / 2) {
                    cout << i + 1 << endl;
                    break;
                }
            }
        }
    }
}