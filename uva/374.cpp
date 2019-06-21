#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull m_bin_exp(ull a, ull n, ull m) {
    ull result = 1;
    a %= m;
    while (n > 0) {
        if (n & 1) result *= a % m;
        a *= a % m;
        a %= m;
        result %= m;
        n >>= 1;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull x, y, n;

    while (cin >> x >> y >> n) {
        cout << m_bin_exp(x, y, n) << endl;
    }
}