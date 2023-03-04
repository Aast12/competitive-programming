#include <iostream>

using namespace std;

typedef long long lli;

int main() {
    int t, n, c, b, r;
    cin >> t;

    while (t--) {
        int boxes[4];
        cin >> n >> c;
        for (int i = 0; i < 4; i++) cin >> boxes[i];

        b = boxes[0];
        r = boxes[2];

        lli rem = b * c - n;
        if (rem >= 0) {
            cout << n << endl;
            continue;
        }
        rem *= -1;
        if (rem > r) {
            cout << "Don't even try!" << endl;
            continue;
        }
        cout << b * c + rem * c << endl;
    }
}