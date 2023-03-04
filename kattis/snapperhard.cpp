#include <iostream>

using namespace std;

int main() {
    int T, n, k;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n >> k;

        int base = 1 << n;

        cout << "Case #" << t << ": ";
        if (k % base == base - 1) {
            cout << "ON\n";
        } else {
            cout << "OFF\n";
        }
    }
}