#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int lli;

int msb(lli n) {
    int bit = 0;
    while (n > 0) {
        n >>= 1;
        bit++;
    }

    return bit;
}

vector<lli> solve(int n) {
    lli a, b, c, d;
    if (n == 0) {
        return {6, 5, 0, 4};
        // cout << 6 << " " << 5 << " " << 0 << " " << 4 << endl;
        // cout << (((6 & 5) | 0) ^ 4) << endl;

        // continue;
    }

    int k = msb(n);
    cout << "k " << k << endl;

    a = 1 << (k + 3);
    b = 1 << (k + 2);
    c = 1 << (k + 1);
    d = n + c;

    return {a, b, c, d};

    cout << a << " " << b << " " << c << " " << d << endl;
}

int main() {
    int t;
    lli a, b, c, d, n;
    // cin >> t;

    for (lli i = 1; i < ((lli)1 << 32); i *= 2) {
        for (n = i - 2; n < i + 2; n++) {
            if (n < 0) continue;
            vector<lli> s = solve(n);

            a = s[0], b = s[1], c = s[2], d = s[3];
            if (a == b || a == c || a == d || b == c || b == d || c == d) {
                cout << n << " NOTDIST " << a << " " << b << " " << c << " "
                     << d << endl;
            }
            lli res = ((a & b) | c) ^ d;
            if (res != n) {
                cout << std::bitset<64>(n) << " NOTEq " << std::bitset<64>(a) << " "
                     << std::bitset<64>(b) << " " << std::bitset<64>(c) << " "
                     << std::bitset<64>(d) << " = " << std::bitset<64>(res) << endl;
            }
        }
    }

    // while (t--) {
    //     cin >> n;

    //     if (n == 0) {
    //         cout << 6 << " " << 5 << " " << 0 << " " << 4 << endl;
    //         // cout << (((6 & 5) | 0) ^ 4) << endl;

    //         continue;
    //     }

    //     int k = msb(n);
    //     // cout << "k " << k << endl;

    //     if (k < 29) {
    //         a = 1 << (k + 3);
    //         b = 1 << (k + 2);
    //         c = 1 << (k + 1);
    //         d = n + c;
    //     } else {
    //         a = 1 << (k);
    //         b = 1 << (k - 1);
    //         c = n & (-n);
    //         d = n - c;
    //     }

    //     cout << a << " " << b << " " << c << " " << d << endl;

    //     // cout << (((a & b) | c) ^ d) << endl;
    // }
}