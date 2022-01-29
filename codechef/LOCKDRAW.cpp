#include <iostream>

using namespace std;

int main() {
    int t, a, b, c, sum, max_v;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        max_v = max(a, max(b, c));
        sum = a + b + c - max_v;

        cout << (sum == max_v ? "YES\n" : "NO\n");
    }
}